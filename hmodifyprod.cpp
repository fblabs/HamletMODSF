#include "hmodifyprod.h"
#include "ui_hmodifyprod.h"

#include <QSqlDatabase>
//#include <QSqlRelationalTableModel>
#include "hreadonlymodellots.h"
#include <QSqlRelationalDelegate>
#include <QSqlRelation>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include <QDate>
#include <QDebug>
// #include <QDebug>
#include <huser.h>


#include <QMessageBox>



HModifyProd::HModifyProd(HUser *puser,QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HModifyProd)
{
    ui->setupUi(this);
    db=pdb;
    user=puser;
    action=0;

    ui->deDal->setDate(QDate::currentDate().addYears(-2));
    ui->deAl->setDate(QDate::currentDate());
    dfrom=ui->deDal->date();
    dto=ui->deAl->date().addDays(1);
    tipo="lotdef.tipo=3";




    tmLots=new HReadOnlyModelLots(0,db);
    tmLots->setTable("lotdef");
    tmLots->setSort(3,Qt::DescendingOrder);


    tmLots->setRelation(2,QSqlRelation("prodotti","ID","descrizione"));
    tmLots->setRelation(5,QSqlRelation("unita_di_misura","ID","descrizione"));
    tmLots->setRelation(8,QSqlRelation("anagrafica","ID","ragione_sociale"));
    tmLots->setRelation(11,QSqlRelation("tipi_lot","ID","descrizione"));

    QSqlRelationalDelegate *del=new QSqlRelationalDelegate(0);

    tmLots->select();

    //temp
    QDate to = dto.addDays(1);
    tmLots->setFilter(tipo +" and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + to.toString("yyyy-MM-dd")+"'");



    ui->tvLots->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tmLots->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    tmLots->select();

    ui->tvLots->setItemDelegate(del);
    ui->tvLots->setModel(tmLots);

    QSqlTableModel *umm=new QSqlTableModel(0,db);
    umm->setTable("unita_di_misura");
    umm->setSort(1,Qt::AscendingOrder);
    umm->select();
    ui->cbUm->setModel(umm);
    ui->cbUm->setModelColumn(1);

    QSqlQueryModel *compmod=new QSqlQueryModel();
    QSqlQuery qcomp(db);
    QString sqlcomp="SELECT ID,lot,data,scadenza FROM lotdef where scadenza < CURRENT_DATE() order by data desc";
    qcomp.exec(sqlcomp);
    compmod->setQuery(qcomp);

    comp=new QCompleter();
    comp->setCaseSensitivity(Qt::CaseInsensitive);
    comp->setCompletionColumn(1);
    comp->setCompletionMode(QCompleter::PopupCompletion);
    comp->setModel(compmod);

    ui->leLotto->setCompleter(comp);


   ui->tvLots->setColumnHidden(0,true);

   ui->tvLots->setColumnHidden(5,true);
   ui->tvLots->setColumnHidden(6,true);
   ui->tvLots->setColumnHidden(7,true);
   ui->tvLots->setColumnHidden(8,true);

   tmLots->setHeaderData(1,Qt::Horizontal,QObject::tr("Lotto"));
   tmLots->setHeaderData(2,Qt::Horizontal,QObject::tr("Prodotto"));
   tmLots->setHeaderData(3,Qt::Horizontal,QObject::tr("Data"));
   tmLots->setHeaderData(4,Qt::Horizontal,QObject::tr("Giacenza"));
   tmLots->setHeaderData(10,Qt::Horizontal,QObject::tr("Lot. Uscita"));
   tmLots->setHeaderData(11,Qt::Horizontal,QObject::tr("Tipo"));

   ui->tvLots->setColumnHidden(11,true);
   ui->tvLots->setColumnHidden(12,true);

   ui->tvDetails->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    connect(ui->tvLots->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(getIDLot()));
}

HModifyProd::~HModifyProd()
{
    delete ui;
}

void HModifyProd::getComponetsLot()
{
    QSqlQuery q(db);
  //  idlot=ui->tvLots->model()->index(ui->tvLots->currentIndex().row(),0).data(0).toInt();
    QString sql="select operazioni.ID,operazioni.IDlotto,lotdef.lot,prodotti.ID,prodotti.descrizione,operazioni.quantita,unita_di_misura.ID,unita_di_misura.descrizione from operazioni,lotdef,prodotti,unita_di_misura where prodotti.ID=operazioni.IDprodotto and lotdef.ID=operazioni.IDlotto and unita_di_misura.ID=operazioni.um and  operazioni.ID in (SELECT operazione from composizione_lot where ID_lotto=:lotid )order by operazioni.quantita desc";
    QSqlQueryModel *qmod = new QSqlQueryModel();
    q.prepare(sql);
    q.bindValue(":lotid",QVariant(idlot));
    q.exec();
    qmod->setQuery(q);
   // // qDebug()<<q.lastQuery();

    ui->tvDetails->setModel(qmod);
    connect(ui->tvDetails->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(getLotRowData()));
    //// qDebug()<<q.lastError().text();
    qmod->setHeaderData(4,Qt::Horizontal,QObject::tr("Ingrediente"));
    qmod->setHeaderData(5,Qt::Horizontal,QObject::tr("Quantità"));
    ui->tvDetails->setColumnHidden(0,true);
    ui->tvDetails->setColumnHidden(1,true);
    ui->tvDetails->setColumnHidden(3,true);
    ui->tvDetails->setColumnHidden(6,true);


    QString lbtxt;
    lbtxt=ui->tvLots->model()->index(ui->tvLots->currentIndex().row(),1).data(0).toString();
    lbtxt.append(" - ");
    lbtxt.append(ui->tvLots->model()->index(ui->tvLots->currentIndex().row(),2).data(0).toString());
    ui->lbProd->setText(lbtxt);



 qDebug()<<qmod->lastError().text();


}

void HModifyProd::getLotRowData()
{
   ui->leLotto->setText(ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),2).data(0).toString());
   int opid=ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),0).data(0).toInt();

   QString toSearchUm=ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),7).data(0).toString();

   int k=ui->cbUm->findText(toSearchUm);
// qDebug()<<toSearchUm<<QString::number(k);
   ui->cbUm->setCurrentIndex(k);

   ui->leQuantita->setText(ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),5).data(0).toString());




 /*  QString toSearch=ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),4).data(0).toString();

   int x=ui->cbProdotto->findText(toSearch);

   ui->cbProdotto->setCurrentIndex(x);

   ui->leQuantita->setText(ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),5).data(0).toString());*/

}

bool HModifyProd::updateRow()
{
    QSqlQuery q(db);
    QString sql="UPDATE operazioni set operazioni.quantita=:quantita,um=:um where operazioni.ID=:idr";
    bool ok;
   // int lot=ui->cbProdotto->model()->index(ui->cbProdotto->currentIndex(),1).data(0).toInt();
    int um = ui->cbUm->model()->index(ui->cbUm->currentIndex(),0).data(0).toInt();
   // um++;
// // qDebug()<<"umupdate"<<QString::number(um)<<q.lastError()<<q.lastQuery();
    int idr=ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),0).data(0).toInt();
      double quantita=ui->leQuantita->text().toDouble(&ok);
    if (!ok)
    {

        return false;
    }


    q.prepare(sql);
    q.bindValue(":idr",QVariant(idr));
    q.bindValue(":um",QVariant(um));
    q.bindValue(":quantita",QVariant(quantita));


    bool b= q.exec();
   // // qDebug()<<q.lastError().text();
    return b;
    return false;
    getComponetsLot();
}

bool HModifyProd::deleteRow()
{
    QSqlQuery q(db);
    QString sql="delete from operazioni where ID=:id";
    QString comp="delete from composizione_lot where operazione=:id";
    QString id=ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),0).data(0).toString();
    bool b=q.exec();

    q.prepare(comp);
    q.bindValue(":id",QVariant(id));
    b=q.exec();
    if(!b)
    {
        QMessageBox::question(this,QApplication::applicationName(),"ERRORE\n"+q.lastError().text()+"\n"+q.lastQuery(),QMessageBox::Ok | QMessageBox::Cancel);
        return false;
    }

    q.clear();



    q.prepare(sql);
    id=ui->tvDetails->model()->index(ui->tvDetails->currentIndex().row(),0).data(0).toString();
    q.bindValue(":id",id);
    b=q.exec();
    if(!b)
    {
        QMessageBox::question(this,QApplication::applicationName(),"ERRORE\n"+q.lastError().text()+"\n"+q.lastQuery(),QMessageBox::Ok | QMessageBox::Cancel);
    }



    getComponetsLot();
    return b;
}



bool HModifyProd::addRow(){


    QDateTime data=QDateTime::currentDateTime();
    int idl;
    int utente=user->getID();
    int idprod;
    QStringList list=ui->leLotto->text().split('-');
    idprod=list.at(1).toInt();
    int azione=2;
    double quantita=ui->leQuantita->text().toDouble();
    int um=ui->cbUm->model()->index(ui->cbUm->currentIndex(),0).data(0).toInt();
    QString sql;

    QSqlQuery q(db);
    sql="SELECT ID from lotdef where lot=:lot";
    q.prepare(sql);
    q.bindValue(":lot",QVariant(ui->leLotto->text()));
    q.exec();
    q.first();
    idl=q.value(0).toInt();




    sql="INSERT INTO `operazioni`(`IDlotto`,`data`,`utente`,`IDprodotto`,`azione`,`quantita`,`um`)VALUES(:idlotto,:data,:utente,:idprodotto,:azione,:quantita,:um)";
db.transaction();
    q.prepare(sql);
    q.bindValue(":idlotto",QVariant(idl));
    q.bindValue(":data",QVariant(data));
    q.bindValue(":utente",QVariant(utente));
    q.bindValue(":idprodotto",QVariant(idprod));
    q.bindValue(":azione",QVariant(azione));
    q.bindValue(":quantita",QVariant(quantita));
    q.bindValue(":um",QVariant(um));
   bool   b =q.exec();
  // // qDebug()<<"insert:"<<q.lastError().text();
   if(!b) return false;
   int idop=q.lastInsertId().toInt();

  // // qDebug()<<QString::number(idl)<<QString::number(idop);

   sql="INSERT into composizione_lot(`ID_lotto`,`operazione`) VALUES(:lot,:operazione)";
   q.prepare(sql);
   q.bindValue(":lot",QVariant(idlot));
   q.bindValue(":operazione",QVariant(idop));

   b=q.exec();
  // // qDebug()<<"compB"<<q.lastError().text()<<q.lastQuery()<<QString::number(idlot)<<QString::number(idop);



    if(b)
    {
        db.commit();
        tmLots->select();
       // // qDebug()<<"compA"<<q.lastError().text()<<q.lastQuery()<<QString::number(idlot)<<QString::number(idop);
    }
    else
    {

        db.rollback();
    }

    return b;

}

void HModifyProd::on_pushButton_2_clicked()
{



    if (QMessageBox::Ok==QMessageBox::question(this,QApplication::applicationName(),"Chiudere la finestra?",QMessageBox::Ok | QMessageBox::Cancel))
    {
        close();

    }
}

void HModifyProd::getIDLot()
{
    idlot=ui->tvLots->model()->index(ui->tvLots->currentIndex().row(),0).data(0).toInt();
    ui->pushButton_4->setEnabled(true);
    getComponetsLot();
}


void HModifyProd::on_pushButton_clicked()
{
    if (action==0)
    {

    if(updateRow())
        {
          getComponetsLot();
          QMessageBox::information(this,QApplication::applicationName(),"Riga modificata",QMessageBox::Ok);

        }
        else
        {
            QMessageBox::warning(this,QApplication::applicationName(),"MODERRORACCIO!!!\n" + db.lastError().text()  ,QMessageBox::Ok);
        }
    }
    else if (action==1)
    {
        if(addRow())
            {
              getComponetsLot();

            QMessageBox::information(this,QApplication::applicationName(),"Riga aggiunta",QMessageBox::Ok);

            }
            else
            {
                QMessageBox::warning(this,QApplication::applicationName(),"MODERRORINO!!!\n" + db.lastError().text()  ,QMessageBox::Ok);
            }
         action=0;
    }
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(false);

}

void HModifyProd::on_pushButton_3_clicked()
{
  if (QMessageBox::Ok==QMessageBox::question(this,QApplication::applicationName(),"Rimuovere la riga?\n Attenzione!! La cancellazione è definitiva",QMessageBox::Ok|QMessageBox::Cancel))
  {
  bool b= deleteRow();
   if(b)
   {
       QMessageBox::information(this,QApplication::applicationName(),"Riga rimossa",QMessageBox::Ok);
   }
   else
   {
       QMessageBox::warning(this,QApplication::applicationName(),"ERRORACCIO!!!\n" + db.lastError().text()  ,QMessageBox::Ok);
   }
  }


}


void HModifyProd::on_pushButton_4_clicked()
{

    ui->leLotto->setText("");
    ui->leQuantita->setText("");
    QSqlTableModel *lotm=new QSqlTableModel(0,db);
    lotm->setTable("lotdef");
    lotm->setFilter("tipo<4");
    lotm->setSort(3,Qt::DescendingOrder);
    lotm->select();
    QCompleter *lcmp=new QCompleter(lotm);
    lcmp->setCaseSensitivity(Qt::CaseInsensitive);
    lcmp->setCompletionMode(QCompleter::PopupCompletion);
    lcmp->setCompletionColumn(1);



    action=1;



    ui->leLotto->setCompleter(lcmp);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(true);
}



void HModifyProd::on_cbUm_currentIndexChanged(int index)
{
   // // qDebug()<<QString::number(index);
}

void HModifyProd::on_pushButton_5_clicked()
{
    action=0;
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(false);
}

void HModifyProd::on_deDal_dateChanged(const QDate &date)
{
    dfrom=ui->deDal->date();
}

void HModifyProd::on_deAl_dateChanged(const QDate &date)
{
    dto=ui->deAl->date();
}

void HModifyProd::on_pushButton_6_clicked()
{
    filter=tipo +" and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + dto.toString("yyyy-MM-dd")+"'";
    tmLots->setFilter(filter);
   // // qDebug()<<tmLots->filter()<<tmLots->query().lastError().text();
}



void HModifyProd::findIt(QString arg)
{  QString filter;
   QDate to=ui->deAl->date().addDays(1);


    if (ui->rblots->isChecked())
    {
        if(ui->leSearch->text().length()==0)
        {
           filter=tipo +" and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + to.toString("yyyy-MM-dd")+"'";

        }
        else
        {
           filter=tipo +" and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + to.toString("yyyy-MM-dd")+"' and lotdef.lot like '%" +arg+"%'";

        }

    }
    else
    {
        if(ui->leSearch->text().length()==0)
        {
           filter=tipo +" and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + dto.toString("yyyy-MM-dd")+"'";

        }
        else
        {
           filter=tipo +" and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + dto.toString("yyyy-MM-dd")+"' and relTblAl_2.descrizione like '%" +arg+"%'";

        }
    }


    tmLots->setFilter(filter);
    ui->tvDetails->setModel(0);

   //// // qDebug()<<tmLots->query().lastError().text();
    // // qDebug()<<tmLots->query().lastQuery()<<tmLots->lastError();
}

void HModifyProd::on_leSearch_textChanged(const QString &arg1)
{

    findIt(arg1);


}

void HModifyProd::on_pushButton_7_clicked()
{
    ui->leSearch->setText("");
}



void HModifyProd::on_rbprod_toggled(bool checked)
{
    ui->leSearch->setText("");

}



void HModifyProd::on_rbProdottiFiniti_toggled(bool checked)
{ if (checked)
    {
    tipo="lotdef.tipo=3";
    tmLots->setFilter(tipo + " and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + dto.toString("yyyy-MM-dd")+"'");
    }
}

void HModifyProd::on_rbPackeges_toggled(bool checked)
{
    if (checked)
        {
        tipo="lotdef.tipo=4";
        tmLots->setFilter(tipo + " and lotdef.data between '" + dfrom.toString("yyyy-MM-dd") + "' and '" + dto.toString("yyyy-MM-dd")+"'");
        }
}
