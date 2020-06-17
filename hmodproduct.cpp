#include "hmodproduct.h"
#include "ui_hmodproduct.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>
#include <QDebug>
#include <QSqlError>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include "huser.h"
#include "hmodricette.h"

HModProduct::HModProduct(int pID, QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HModProduct)
{
    ui->setupUi(this);
    //setModifyEnabled(user->getCanUpdateAnag());
    db=pdb;
    ID=pID;
    getProductData();



}

HModProduct::~HModProduct()
{
    delete ui;
}

void HModProduct::setModifyEnabled(bool enable)
{

        ui->pbSave->setEnabled(enable);


}

bool HModProduct::getProductData()
{
    QSqlTableModel *tipimodel=new QSqlTableModel(0,db);
    tipimodel->setTable("tipi_prodotto");
    ui->cbType->setModel(tipimodel);
    ui->cbType->setModelColumn(1);
    tipimodel->select();




    productsmodel=new QSqlRelationalTableModel(0,db);
    productsmodel->setTable("prodotti");
    productsmodel->setRelation(TIPO,QSqlRelation("tipi_prodotto","ID","descrizione"));
    productsmodel->setFilter("prodotti.ID="+QString::number(ID));
    productsmodel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    productsmodel->setSort(DESCRIZIONE,Qt::AscendingOrder);
    productsmodel->select();




    map=new QDataWidgetMapper(productsmodel);
    map->setModel(productsmodel);
    map->setItemDelegate(new QSqlRelationalDelegate(this));

    map->addMapping(ui->leCod,CODICE);
    map->addMapping(ui->leDescription,DESCRIZIONE);
    map->addMapping(ui->cbType,TIPO);
    map->addMapping(ui->cbActive,ATTIVO);
    map->addMapping(ui->cbAllergene,ALLERGENE);
    map->addMapping(ui->cbBio,BIO);

    map->toFirst();
    map->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);



    qDebug()<<productsmodel->rowCount()<<productsmodel->lastError().text();




    return true;

}

void HModProduct::save()
{
    qDebug()<<"save";
    db.transaction();
    bool b= map->submit();
    productsmodel->submitAll();
    qDebug()<<productsmodel->lastError().text();
    if(b){

     qDebug()<<"save OK";
     db.commit();

     emit done();
     close();
    }else{
        qDebug()<<productsmodel->lastError().text();
        db.rollback();
        QMessageBox::information(this,QApplication::applicationName(),"Errore durante il salvataggio\n"+db.lastError().text(),QMessageBox::Ok);
    }

    productsmodel->select();


}


void HModProduct::on_pbClose_clicked()
{


      close();

}

void HModProduct::on_pbSave_clicked()
{
    if(QMessageBox::question(this,QApplication::applicationName(),"Salvare?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {

        save();
    }

}








