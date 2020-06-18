#include "hpackages.h"
#include "ui_hpackages.h"
#include <QHeaderView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QCompleter>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QSqlRelation>
#include "huser.h"

HPackages::HPackages(HUser *puser,QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HPackages)
{
    ui->setupUi(this);
    user=puser;
    db=pdb;

    basefilter="year(lotti_view.scadenza) > '" +QDate::currentDate().addYears(1).toString("yyyy-MM-dd")+"' or lotti_view.scadenza is null";
   // // qDebug()<<basefilter;


    tmProdotti = new QSqlTableModel(0,db);
    tmUnitaMisura = new QSqlTableModel(0,db);



    tmLots=new QSqlTableModel(0,db);
    tmLots->setTable("lotti_view");
    tmLots->setFilter(basefilter);
    tmLots->select();


    tmProdotti->setTable("prodotti");
    tmProdotti->setFilter("tipo=2");
    tmProdotti->setSort(2,Qt::AscendingOrder);
    tmProdotti->select();

    qDebug()<<tmProdotti->query().lastQuery()<<tmProdotti->query().lastError().text();

    tmUnitaMisura->setTable("unita_di_misura");
    tmUnitaMisura->setSort(1,Qt::AscendingOrder);
    tmUnitaMisura->select();
    ui->cbProdotti->setModel(tmProdotti);
    ui->cbProdotti->setModelColumn(2);
    ui->cbQua->setModel(tmUnitaMisura);
    ui->cbQua->setModelColumn(1);
    ui->cbQua->setCurrentIndex(1);


    compProdotti=new QCompleter();


    compProdotti->setModel(tmProdotti);
    compProdotti->setCaseSensitivity(Qt::CaseInsensitive);
    compProdotti->setCompletionColumn(2);
    compProdotti->setCompletionMode(QCompleter::PopupCompletion);

    ui->cbProdotti->setCompleter(compProdotti);

    ui->dateEdit->setDate(QDate::currentDate().addMonths(2));




    ui->tvLots->setModel(tmLots);
   // // qDebug()<<tmLots->lastError().text();

    ui->tvLots->setSortingEnabled(true);



    ui->tvLots->setColumnHidden(0,true);
    ui->tvLots->setColumnHidden(1,true);
    ui->tvLots->setColumnHidden(2,true);
    ui->tvLots->setColumnHidden(5,true);
    ui->tvLots->setColumnHidden(9,true);
    ui->tvLots->setColumnHidden(11,true);
    ui->tvLots->setColumnHidden(12,true);
    ui->tvLots->setColumnHidden(13,true);
    ui->tvLots->setColumnHidden(14,true);
    ui->tvLots->setEditTriggers(QTableView::NoEditTriggers);
    ui->tvLots->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);



    //connect(ui->cbProdotti,SIGNAL(currentIndexChanged(int)),this,SLOT(createNewLot()));
    connect(ui->cbProdotti,SIGNAL(currentIndexChanged(int)),this,SLOT(getEanList()));
    connect(ui->tvLots->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(setLotText()));

    ui->pbAnnulla->setEnabled(false);
    ui->pbCrea->setEnabled(true);//
    ui->leComponente->setEnabled(false);
    ui->leQuantita->setEnabled(false);
    ui->pbAddRow->setEnabled(false);
    ui->pbRemoveRow->setEnabled(false);
    ui->cbProdotti->setCurrentIndex(0);
 //   ui->checkBox_2->setVisible(false);
    ui->tvLots->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    getEanList();

}

HPackages::~HPackages()
{
    delete ui;
}

void HPackages::enableUI(bool e)
{
    ui->cbProdotti->setEnabled(e);
    ui->pbAnnulla->setEnabled(!e);
    ui->pushButton_3->setEnabled(!e);
}

void HPackages::setLotText()
{
    QString lot=ui->tvLots->model()->index(ui->tvLots->selectionModel()->currentIndex().row(),4).data(0).toString();
    ui->leComponente->setText(lot);
}

void HPackages::resetForm()
{
    ui->tvPack->setModel(0);
    ui->pbAnnulla->setEnabled(false);
    ui->pbCrea->setEnabled(true);
    ui->leComponente->setEnabled(false);
    ui->leQuantita->setEnabled(false);
    ui->pbAddRow->setEnabled(false);
    ui->pbRemoveRow->setEnabled(false);
    ui->leNewLot->setText("");
    ui->tvLots->setEnabled(false);
}

void HPackages::getEanList()
{
    int idcliente;
    int idprodotto;



     idprodotto=ui->cbProdotti->model()->index(ui->cbProdotti->currentIndex(),0).data(0).toInt();

     QSqlQuery q(db);
     QString sql;
     QSqlQueryModel *mod = new QSqlQueryModel();
     sql="SELECT EAN FROM lotdef where prodotto=:idp and year(data)=year(now()) order by data desc";
     q.prepare(sql);

     q.bindValue(":idp",QVariant(idprodotto));
     if (q.exec())
     {
         mod->setQuery(q);
         ui->lvEan->setModel(mod);
         ui->lvEan->setModelColumn(0);
     }

}

void HPackages::filterProducts()
{




    QString filtro="";
    tmProdotti->setFilter(filtro);
    ui->cbProdotti->setCurrentIndex(0);



}




void HPackages::on_pushButton_4_clicked()
{
    if(QMessageBox::Ok==QMessageBox::question(this,QApplication::applicationName(),"Chiudere?",QMessageBox::Ok|QMessageBox::Cancel))
    {
       close();
    }
}

void HPackages::createNewLotInterno()
{
    QSqlQuery q(db);
    int idprodotto= ui->cbProdotti->model()->index(ui->cbProdotti->currentIndex(),0).data(0).toInt();

    QString sql;
    QString nlot;
    QDateTime data=QDateTime::currentDateTime();

   sql="select createid_sf(:p,:d)";
   q.prepare(sql);
   q.bindValue(":p",QVariant(idprodotto));
   q.bindValue(":d",QVariant(data.toString("yyyy-MM-dd hh:mm:ss")));

   q.exec();
   q.first();

   nlot=q.value(0).toString();

   ui->leNewLot->setText(nlot);
}

void HPackages::createNewLot()
{

    QSqlQuery q(db);
    int idprodotto= ui->cbProdotti->model()->index(ui->cbProdotti->currentIndex(),0).data(0).toInt();
    int anagrafica=-1;
    QString sql;
    QString ean;
    QString n;



   sql="select count(*)+1 from lotdef where prodotto=:p and year(data)=year(now()) and tipo=4";//tipo=package
   q.prepare(sql);
   q.bindValue(":p",QVariant(idprodotto));
   //q.bindValue (":a",QVariant(anagrafica));

   q.exec();
   q.first();

   n=q.value(0).toString();

   if (n.length()<2)
   {
       ean="L0";
   }
   else
   {
       ean="L";
   }

   ean.append(n);

    ui->leLest->setText(ean);




}

void HPackages::on_pbCrea_clicked()
{
    bool ok;

    enableUI(false);

    ok=ui->leQuantLot->text().toDouble(&ok);
    if(!ok)
    {
        QMessageBox::warning(this,QApplication::applicationName(),"Quantità non valida",QMessageBox::Ok);
        return;
    }

    createNewLot();
    createNewLotInterno();
    mod=new QStandardItemModel();
    ui->tvPack->setModel(mod);
    ui->tvPack->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pbCrea->setEnabled(false);
    ui->pbAnnulla->setEnabled(true);

    ui->leComponente->setEnabled(true);
    ui->leQuantita->setEnabled(true);
    ui->pbAddRow->setEnabled(true);
    ui->pbRemoveRow->setEnabled(true);
    ui->tvLots->setEnabled(true);
}

int HPackages::getIdProdotto(QString lotto)
{
  //  QString lotto = ui->leComponente->text();
    QStringList list;
    list=lotto.split('-');
    if (list.size()<3) return -1;
    QString idprod= list.at(1);

    int idp=idprod.toInt();

    return idp;
}

QString HPackages::getDescProdotto(QString lotto)
{
    QSqlQuery *q=new QSqlQuery(db);

    QString sql;

    int id=getIdProdotto(lotto);



    sql="SELECT descrizione FROM prodotti WHERE id=:id";

    q->prepare(sql);
    q->bindValue(":id",QVariant(id));

    q->exec();
    q->first();
    return q->value(0).toString();

}

int HPackages::getIdLotto(QString lotto)
{
    QSqlQuery q(db);
    QString sql;

    sql="SELECT ID from lotdef WHERE lot=:lotto";
    q.prepare(sql);
    q.bindValue(":lotto",lotto);
    q.exec();
    q.first();

    return q.value(0).toInt();

}

QList<QStandardItem*> HPackages::addRow( QString idprod,QString sDescProdotto,QString idlotto,QString sLotto,QString sQuantita,QString sum)
{



        QList<QStandardItem*> fields;



        QStandardItem *idprodotto=new QStandardItem(idprod);
        QStandardItem *descr=new QStandardItem(sDescProdotto);
        QStandardItem *idltt=new QStandardItem(idlotto);
        QStandardItem *lotto=new QStandardItem(sLotto);
        QStandardItem *quantita= new QStandardItem(sQuantita);
        QStandardItem *um = new QStandardItem(sum);


        fields <<idprodotto<<descr<<idltt<<lotto<<quantita<<um;


        return fields;


}


void HPackages::on_pbAddRow_clicked()
{
    QString lotto =ui->leComponente->text();
    int idlotto=getIdLotto(lotto);
    QString desc=getDescProdotto(lotto);
    int idprod=getIdProdotto(lotto);
    bool ok;

    ok=ui->leQuantita->text().toDouble(&ok);
    if(!ok)
    {
        QMessageBox::warning(this,QApplication::applicationName(),"Quantità non valida",QMessageBox::Ok);
        return;
    }

   if(checkLot(lotto))
   {
        if(ui->leComponente->text().size()>4 && ui->leQuantita->text().toDouble() >0)
       {
         mod->appendRow(addRow(QString::number(idprod),getDescProdotto(lotto),QString::number(getIdLotto(lotto)),lotto,ui->leQuantita->text().trimmed(),getumdesc(getumid(idlotto))));
         ui->leComponente->setText("");
         ui->leQuantita->setText(getDescProdotto(ui->leQuantita->text().trimmed()));
       }
   }
   else
   {
       QMessageBox::warning(this,QApplication::applicationName(),"Il lotto non esiste. Può essere un errore di inserimento",QMessageBox::Ok);

   }

}

bool HPackages::checkLot(QString lot)
{
    QSqlQuery q(db);
    QString sql;

    sql="SELECT count(ID) FROM lotdef where lot=:lot";


    q.prepare(sql);
    q.bindValue(":lot",QVariant(lot));
    q.exec();
    q.first();

    int count=q.value(0).toInt();

    if (count >0)
        return true;
    else
        return false;

}

void HPackages::on_pbRemoveRow_clicked()
{
    mod->removeRow(ui->tvPack->selectionModel()->currentIndex().row());
}



int HPackages::getLastId()
{

    QSqlQuery q(db);
    QString sql="SELECT last_insert_id();";
    q.prepare(sql);
    q.exec();

    q.first();

    return q.value(0).toInt();
}

bool HPackages::saveLot(QString lotto)
{
     bool b;

    //1. creazione lotto in lotdef

    b=saveNewLotInLotdef(lotto);

   if(!b)
   {
       db.rollback();
       return false;

   }
   int nlotid=getLastId();


    //2.salvo l'operazione di carico del lotto (operazione)

   b=chargeNewLot(nlotid);

   if(!b)
   {
       db.rollback();
      // // qDebug()<<"errore in chargeNewLot";
       return false;
   }

//3.se il lotto è caricato, scarico i componenti

   b=unloadNewLotComponents(nlotid);

    if(!b)
    {
        db.rollback();
       // // qDebug()<<"errore in unloadNewLotComponents";
        return false;
    }




        db.commit();
        // // qDebug()<<"saveLot ok";
     return true;

}

bool HPackages::saveNewLotInLotdef(QString lotto)
{
    QSqlQuery q(db);
    QString sql;
    bool b;
    int anagrafica=78;



    QString idp=ui->cbProdotti->model()->index(ui->cbProdotti->currentIndex(),0).data(0).toString();



    sql="INSERT INTO `lotdef`(`lot`,`prodotto`,`data`,`giacenza`,`um`,`scadenza`,`anagrafica`,`EAN`,`tipo`,`attivo`,`note`) values (:lot,:prodotto,:data,:giacenza,:um,:scadenza,:anagrafica,:ean,4,2,:note)";
    q.prepare(sql);
    q.bindValue(":lot",QVariant(lotto));
    q.bindValue(":prodotto",QVariant(idp));
    q.bindValue(":data",QVariant(QDateTime::currentDateTime()));
    q.bindValue(":giacenza",QVariant(ui->leQuantLot->text()));
    q.bindValue(":um",2);
    q.bindValue(":scadenza",QVariant(ui->dateEdit->date()));
    q.bindValue(":anagrafica",QVariant(anagrafica));
    q.bindValue(":ean",QVariant(ui->leLest->text()));
    q.bindValue(":note",ui->teNote->toPlainText());

    b = q.exec();

    qDebug()<<"saveNewLot"<<q.lastError().text();


    return b;
}

bool HPackages::chargeNewLot(int id)
{
    QSqlQuery q(db);
    QString sql;
    QString quant=ui->leQuantLot->text();
    QString note=ui->teNote->toPlainText();
    QString lotto=ui->leNewLot->text();

    int idp =getIdProdotto(lotto);



    bool b;


         sql="INSERT INTO `operazioni` (`IDlotto`,`data`,`utente`, `IDprodotto`,`azione`,`quantita`,`um`,`note`) VALUES (:lot,:data,:utente,:idprodotto,:azione,:quantita,:um,:note)";
         q.prepare(sql);

         q.bindValue(":lot",id);
         q.bindValue(":data",QVariant(QDateTime::currentDateTime()));
         q.bindValue(":utente",QVariant(user->getID()));
         q.bindValue(":idprodotto",QVariant(idp));
         q.bindValue(":azione",QVariant(1));
         q.bindValue(":quantita",QVariant(quant));
         q.bindValue(":um",QVariant(2));
         q.bindValue(":note",QVariant(note));

         b=q.exec();

        // // qDebug()<<"CARICO NUOVO LOTTO:"<<q.lastInsertId().toString()<<QString::number(idp)<<q.lastError().text();



      return b;


}

bool HPackages::unloadNewLotComponents(int nlot)
{
    bool b;
    QSqlQuery q(db);
    QString sql;
  //  QString lot;

    int lotdascaricare;
    int prodottodascaricare;
    int azione=2;
    int operazione;
    int um;

    for (int row=0;row<ui->tvPack->model()->rowCount();row++)
    {
         lotdascaricare=ui->tvPack->model()->index(row,2).data(0).toInt();
         prodottodascaricare=ui->tvPack->model()->index(row,0).data(0).toInt();
         um=getumidfromdesc(ui->tvPack->model()->index(row,5).data(0).toString());
        // // qDebug()<<"unload newlot components gtumidfromdesc"<<um;


        sql="INSERT INTO `operazioni` (`IDlotto`,`data`,`utente`, `IDprodotto`,`azione`,`quantita`,`um`) VALUES (:idlot,:data,:utente,:idprodotto,:azione,:quantita,:um)";



        q.prepare(sql);

        q.bindValue(":idlot",ui->tvPack->model()->index(row,2).data(0));
        q.bindValue(":data",QDateTime::currentDateTime());
        q.bindValue(":utente",QVariant(user->getID()));
        q.bindValue(":idprodotto",QVariant(prodottodascaricare));
        q.bindValue(":azione",QVariant(azione));
        q.bindValue(":quantita",ui->tvPack->model()->index(row,4).data(0));
        q.bindValue(":um",QVariant(um));

        b=q.exec();
        operazione=q.lastInsertId().toInt();
 // // qDebug()<<"unloadLOT b:"+b<<q.lastError().text()<<q.boundValue(3).toString()<<QString::number(prodottodascaricare);


   sql="insert into composizione_lot (id_lotto,operazione) values (:nlot,:operazione)";
   q.prepare(sql);
   q.bindValue(":nlot",QVariant(nlot));
   q.bindValue(":operazione",QVariant(operazione));
   b=q.exec();

  // // qDebug()<<"COMPOSIZIONE SCARICO COMPONENHTE:"<<"nlot"<<nlot<<"operazione"<<operazione;
        if (!b)return false;

    }



    return b;


}

QString HPackages::getumdesc(int umid)
{
    QSqlQuery *q=new QSqlQuery(db);

    QString sql;


    sql="SELECT descrizione FROM unita_di_misura WHERE ID=:id";

    q->prepare(sql);
    q->bindValue(":id",QVariant(umid));

    q->exec();
    q->first();
    return q->value(0).toString();
}


int HPackages::getumid(int idlotto)
{
    QSqlQuery *q=new QSqlQuery(db);

    QString sql;


    sql="SELECT um FROM lotdef WHERE ID=:id";

    q->prepare(sql);
    q->bindValue(":id",QVariant(idlotto));

    q->exec();
    q->first();
    return q->value(0).toInt();


}

int HPackages::getumidfromdesc(QString pdesc)
{
    QSqlQuery *q=new QSqlQuery(db);

    QString sql;


    sql="SELECT ID FROM unita_di_misura WHERE descrizione=:desc";

    q->prepare(sql);
    q->bindValue(":desc",QVariant(pdesc));

    q->exec();
    q->first();

    int res=q->value(0).toInt();

   // // qDebug()<<res<<pdesc;

    return res;

}




void HPackages::on_pushButton_3_clicked()
{


bool b;


    if(QMessageBox::question(this,QApplication::applicationName(),"Salvare il nuovo lotto?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {

       db.transaction();
       b=saveLot(ui->leNewLot->text());


        if(b)
        {
            db.commit();
            QMessageBox::information(this,QApplication::applicationName(),"Lotto salvato",QMessageBox::Ok);

        }
        else
        {
            db.rollback();
            QMessageBox::warning(this,QApplication::applicationName(),"Errore salvando il nuovo lotto",QMessageBox::Ok);
            enableUI(true);

        }

       resetForm();

    }



}

void HPackages::on_pbAnnulla_clicked()
{
    enableUI(true);
    resetForm();
}




void HPackages::on_rbTutti_toggled(bool checked)
{
 // // qDebug()<<basefilter +"- FILTER "<<tmLots->filter();
  if (checked)
  {
      tmLots->setFilter(basefilter);


  }

}




void HPackages::on_rbProdottiFiniti_toggled(bool checked)
{

    if (checked)
    {
        QString flt="("+basefilter + ") and lotti_view.tipolot=3 and lotti_view.`Tipo prodotto`=2";
        tmLots->setFilter(flt);
        ui->leSearch->setText("");

    }

    qDebug()<<tmLots->filter()<<tmLots->lastError();

}






void HPackages::on_rbConfezionamenti_toggled(bool checked)
{

    if (checked)
    {   QString flt="("+basefilter + ") and lotti_view.tipolot=1 and lotti_view.`Tipo prodotto`=5";
        tmLots->setFilter(flt);
        ui->leSearch->setText("");

    }

    qDebug()<<"confezionamenti"<<tmLots->filter()<<tmLots->lastError();
}


void HPackages::on_leSearchCode_returnPressed()
{
    QString arg1=ui->leSearchCode->text();
    QString flt=" and lotti_view.codprodotto like '"+arg1+"%'";
    QString filter="";
    QString tipo;


    if(arg1.length()>0)
    {
        filter="("+basefilter + ")"+flt;

        if (ui->rbProdottiFiniti->isChecked())
        {
            tipo=" and lotti_view.tipolot=3 ";
            filter.append(tipo);
        }
        else if(ui->rbConfezionamenti->isChecked())
        {
            tipo=" and lotti_view.tipolot= 4 ";
            filter.append(tipo);
        }

    }
    else
    {
         filter=basefilter;
    }


    tmLots->setFilter(filter);

    ui->leSearchCode->setText(QString());

    qDebug()<<tmLots->lastError().text();


}

void HPackages::on_leSearch_returnPressed()
{
       QString arg1=ui->leSearch->text();
       QString tipo;
       QString filter="("+basefilter + ")";



        if(arg1.length()>0)
        {

            filter=filter.append(" and lotti_view.prodotto  like '"+ arg1 +"%'");





            if (ui->rbProdottiFiniti->isChecked())
            {
                tipo=" and lotti_view.tipolot=3 ";
                filter.append(tipo);
            }
            else if(ui->rbConfezionamenti->isChecked())
            {
                tipo=" and lotti_view.tipolot= 4 ";
                filter.append(tipo);
            }
        }
        else
        {
            filter=basefilter;
        }


        tmLots->setFilter(filter);

        ui->leSearch->setText(QString());

        qDebug()<<tmLots->lastError().text();

}



void HPackages::on_leSearch_cursorPositionChanged(int arg1, int arg2)
{
    ui->leSearchCode->setText(QString());
}

void HPackages::on_leSearchCode_cursorPositionChanged(int arg1, int arg2)
{
    ui->leSearch->setText(QString());
}
