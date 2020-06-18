#include "haddcomponent.h"
#include "ui_haddcomponent.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include"huser.h"
#include <QCompleter>


HAddComponent::HAddComponent(int p_idlotto, HUser *p_user, QSqlDatabase p_db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HAddComponent)
{
    ui->setupUi(this);
    db=p_db;
    user=p_user;
    idlotto=p_idlotto;
    prodmod=new QSqlTableModel(0,db);
    prodmod->setTable("prodotti");
    prodmod->select();
    prodmod->setSort(2,Qt::AscendingOrder);

    QSqlTableModel *umod=new QSqlTableModel(0,db);
    umod->setTable("unita_di_misura");
    umod->select();
    ui->cbUm->setModel(umod);
    ui->cbUm->setModelColumn(1);



    ui->cbProdotto->setModel(prodmod);
    ui->cbProdotto->setModelColumn(2);
    ui->cbProdotto->setCurrentIndex(0);
    QCompleter *comp=new QCompleter(prodmod);
    comp->setCompletionColumn(2);
    comp->setCompletionMode(QCompleter::PopupCompletion);
    comp->setCaseSensitivity(Qt::CaseInsensitive);
    ui->cbProdotto->setCompleter(comp);



    refreshModel();



    ui->tvProdLots->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );
    ui->tvProdLots->setColumnHidden(0,true);
    ui->tvProdLots->setColumnHidden(5,true);
    ui->tvProdLots->setCurrentIndex(ui->tvProdLots->model()->index(0,0));

}

HAddComponent::~HAddComponent()
{
    delete ui;
}

void HAddComponent::on_rbTutti_toggled(bool checked)
{
    if(checked)
    {
        prodmod->setFilter("");
        ui->cbProdotto->setCurrentIndex(0);
    }
}



void HAddComponent::on_rbMateriali_toggled(bool checked)
{
    if(checked)
    {
        prodmod->setFilter("tipo=1");
        ui->cbProdotto->setCurrentIndex(0);
    }
}

void HAddComponent::on_rbProdotti_toggled(bool checked)
{
    if(checked)
    {
       prodmod->setFilter("tipo=2");
       ui->cbProdotto->setCurrentIndex(0);
    }
}



void HAddComponent::on_rbImpasti_toggled(bool checked)
{
    if(checked)
    {
       prodmod->setFilter("tipo=3");
       ui->cbProdotto->setCurrentIndex(0);
    }
}



void HAddComponent::on_rbRipieni_toggled(bool checked)
{
    if(checked)
    {
       prodmod->setFilter("tipo=4");
       ui->cbProdotto->setCurrentIndex(0);
    }
}

void HAddComponent::on_rbConfezioni_toggled(bool checked)
{
    if(checked)
    {
       prodmod->setFilter("tipo=5");
    }
}

void HAddComponent::on_cbProdotto_currentIndexChanged(int index)
{
   refreshModel();
}

void HAddComponent::refreshModel()
{
    mod=0;
    mod=new QSqlQueryModel();

    QSqlQuery q(db);

    QString data=QDate::currentDate().toString("yyyy-MM-dd");

    //QString sql="select lotdef.ID,lotdef.lot,prodotti.descrizione,lotdef.data ,lotdef.scadenza,lotdef.um from  lotdef,prodotti where prodotti.ID=lotdef.prodotto and prodotti.id=:prodid and lotdef.scadenza < :data ORDER BY prodotti.descrizione asc,lotdef.scadenza desc";
    QString sql="select lotdef.ID,lotdef.lot,prodotti.descrizione,lotdef.data ,lotdef.scadenza,lotdef.um from  lotdef,prodotti where prodotti.ID=lotdef.prodotto and prodotti.id=:prodid and (lotdef.scadenza < :data or lotdef.scadenza is not null) ORDER BY prodotti.descrizione asc,lotdef.scadenza desc";
    q.prepare(sql);
    q.bindValue(":prodid",static_cast<QSqlTableModel*>(ui->cbProdotto->model())->index(ui->cbProdotto->currentIndex(),0).data(0).toInt());
    q.bindValue(":data",QVariant(data));
    q.exec();

    mod->setQuery(q);
    ui->tvProdLots->setModel(mod);
    ui->tvProdLots->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );
    ui->tvProdLots->setColumnHidden(0,true);
    ui->tvProdLots->setColumnHidden(5,true);
    ui->tvProdLots->setCurrentIndex(ui->tvProdLots->model()->index(0,0));
}

void HAddComponent::addComponentOperation()
{
    //creare operazione di scarico
    //aggiunger a composzione lot l'id operazione
    QSqlQuery q(db);
    QString sql="insert into operazioni(IDlotto,data,utente, IDprodotto,azione,quantita,um, note)VALUES(:idlotto,:data,:utente,:prodotto,:azione,:quantita,:um,:note)";
    q.prepare(sql);
    q.bindValue(":idlotto",mod->index(ui->tvProdLots->currentIndex().row(),0).data(0).toInt());
    q.bindValue(":data",mod->index(ui->tvProdLots->currentIndex().row(),3).data(0).toDate().toString("yyyy-MM-dd"));
    q.bindValue(":utente",user->getID());
    q.bindValue(":prodotto",prodmod->index(ui->cbProdotto->currentIndex(),0).data(0).toInt());
    q.bindValue(":azione",2);
    bool ok;
    q.bindValue(":quantita",ui->lequantita->text().toDouble(&ok));
    if(!ok)
    {
        QMessageBox::warning(this,QApplication::applicationName(),"Errore nel formato della quantità",QMessageBox::Ok);
        return;
    }
    q.bindValue(":um",mod->index(ui->tvProdLots->currentIndex().row(),5).data(0).toInt());
    q.bindValue(":note","");

    if (q.exec())
    {
    int idop=q.lastInsertId().toInt();
    updateComposizioneLot(idop);
    }else{
        QMessageBox::warning(this,QApplication::applicationName(),"Errore aggiornando i dati\n "+q.lastError().text(),QMessageBox::Ok);
        return;
    }


}

void HAddComponent::updateComposizioneLot(int idoperazione)
{
    QSqlQuery q(db);
    QString sql="insert into composizione_lot(ID_lotto,operazione) values (:idlotto,:idop)";
    q.prepare(sql);
    qDebug()<<idlotto;
    q.bindValue(":idlotto",idlotto);
    q.bindValue(":idop",idoperazione);
    bool b=false;
    b=q.exec();
    if (b)
    {
        db.commit();
        emit done();
        QMessageBox::information(this,QApplication::applicationName(),"Dati aggiornati correttamente",QMessageBox::Ok);

        close();
    }
    else
    {
        db.rollback();
        QMessageBox::warning(this,QApplication::applicationName(),"Errore aggiornando i dati\n"+q.lastError().text(),QMessageBox::Ok);

        return;

    }

}

void HAddComponent::on_pbConfirm_clicked()
{
    db.transaction();
    addComponentOperation();

    prodmod->setFilter(QString());

}

void HAddComponent::on_pbClose_clicked()
{
    close();
}



void HAddComponent::on_leCode_returnPressed()
{
    QString filter=ui->leCode->text();

    if(filter.length()>0)
    {
        prodmod->setFilter("codice="+filter);
    }else
    {
        prodmod->setFilter(QString());

    }
    ui->leCode->setText(QString());
    ui->cbProdotto->setCurrentIndex(0);


}
