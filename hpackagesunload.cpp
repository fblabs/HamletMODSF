#include "hpackagesunload.h"
#include "ui_hpackagesunload.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <huser.h>
#include <QSqlTableModel>
#include <QCompleter>

#include <QSqlError>
// #include <QDebug>
#include <QDateTime>
#include <QMessageBox>


HPackagesUnload::HPackagesUnload(HUser *puser, QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HPackagesUnload)
{
    ui->setupUi(this);
    user=puser;
    db=pdb;
    baseFilter="attivo > 0 and year(data)>year(data)-1 and tipo=2";
    getProducts();


}

HPackagesUnload::~HPackagesUnload()
{
    delete ui;
}

void HPackagesUnload::getProducts()
{
    modProdotti=new QSqlQueryModel();
   QSqlQuery q(db);

    QString sql="SELECT ID,descrizione FROM prodotti where tipo=2 order by descrizione asc";
    q.prepare(sql);
    q.exec();
    modProdotti->setQuery(q);

    ui->cbProdotti->setModelColumn(1);
    ui->cbProdotti->setModel(modProdotti);

    connect(ui->cbProdotti,SIGNAL(currentIndexChanged(int)),this,SLOT(loadPackages()));


}

void HPackagesUnload::loadPackages()
{

    QString prodotto;
    QString prfilt;
    QString flt;

    prodotto=ui->cbProdotti->model()->index(ui->cbProdotti->currentIndex(),0).data(0).toString();

    prfilt=" and prodotto=" + prodotto;


    flt=baseFilter+prfilt + " order by data desc";

    mlots=new QSqlTableModel(0,db);
    mlots->setTable("lotdef");
    mlots->setFilter(flt);
    mlots->select();
    mlots->setSort(3,Qt::DescendingOrder);
  //  ui->tvLots->setModelColumn(1);
    ui->tvLots->setModel(mlots);

    ui->tvLots->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tvLots->setColumnHidden(0,true);
    ui->tvLots->setColumnHidden(2,true);
    ui->tvLots->setColumnHidden(5,true);
    ui->tvLots->setColumnHidden(6,true);
    ui->tvLots->setColumnHidden(7,true);
    ui->tvLots->setColumnHidden(8,true);
    ui->tvLots->setColumnHidden(9,true);
    ui->tvLots->setColumnHidden(10,true);
    ui->tvLots->setColumnHidden(11,true);
    ui->tvLots->setColumnHidden(12,true);

    connect(ui->tvLots->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(setQuantitaText()));





}

void HPackagesUnload::setQuantitaText()
{
    QString q=ui->tvLots->model()->index(ui->tvLots->selectionModel()->currentIndex().row(),4).data(0).toString();
    ui->leQuantita->setText(q);
}

bool HPackagesUnload::scarica()
{
    QSqlQuery q(db);
    bool b;

    QString lot=ui->tvLots->model()->index(ui->tvLots->selectionModel()->currentIndex().row(),1).data(0).toString();
    int idlot=ui->tvLots->model()->index(ui->tvLots->selectionModel()->currentIndex().row(),0).data(0).toInt();
    int prodotto=ui->tvLots->model()->index(ui->tvLots->selectionModel()->currentIndex().row(),2).data(0).toInt();
    int lum;

    QSqlQuery l(db);
    QString sql="SELECT um from lotdef where ID=:idlot";
    l.prepare(sql);
    l.bindValue(":idlot",QVariant(idlot));
    l.exec();
    l.first();

    lum=l.value(0).toInt();

    QString data=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

   // QStringList prodottolist =lot.split("-");

  //  int prodotto=prodottolist.at(1).toInt();
    int azione=2;
    bool ok;
    double quantita=ui->leQuantita->text().toDouble(&ok);
    if(!ok)
    {
        QMessageBox::warning(this,QApplication::applicationName(),"Quantità errata",QMessageBox::Ok);
        return false;
    }
    if (quantita<0)
        quantita*= -1;

    QString note=ui->leNote->text();

    QString query="INSERT INTO operazioni(IDlotto,data,utente,IDprodotto,azione,quantita,um,note) VALUES (:lot,:data,:utente,:prodotto,:azione,:quantita,:um,:note)";

    q.prepare(query);
    q.bindValue(":lot",QVariant(idlot));
    q.bindValue(":data",QVariant(data));
    q.bindValue(":utente",QVariant(user->getID()));
    q.bindValue(":prodotto",QVariant(prodotto));
    q.bindValue(":azione",QVariant(azione));
    q.bindValue(":quantita",QVariant(quantita));
    q.bindValue(":um",QVariant(lum));
    q.bindValue(":note",QVariant(note));


    b=q.exec();
    if (b)
    {

      loadPackages();
     // QMessageBox::information(this,QApplication::applicationName(),"Operazione salvata",QMessageBox::Ok);


    }
  /*  else
    {
       // QMessageBox::warning(this,QApplication::applicationName(),"Errore salvando l'operazione",QMessageBox::Ok);
       //// // qDebug()<<"scarica: " +q.lastError().text()+q.lastQuery();
    }*/

    return b;


}

void HPackagesUnload::on_pushButton_2_clicked()
{
    close();
}

void HPackagesUnload::on_cbClienti_currentIndexChanged(int index)
{
    getProducts();
}

void HPackagesUnload::on_pushButton_clicked()
{
  if (QMessageBox::question(this,QApplication::applicationName(),"Confermi lo scarico?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
  {
      if ( scarica())
      {
          QMessageBox::information(this,QApplication::applicationName(),"Scarico effettuato",QMessageBox::Ok);
          ui->leQuantita->setText("");
          ui->leNote->setText("");
          emit update();
          loadPackages();
      }
      else
      {
          QMessageBox::warning(this,QApplication::applicationName(),"Errore salvando lo scarico",QMessageBox::Ok);
      }
  }
}
