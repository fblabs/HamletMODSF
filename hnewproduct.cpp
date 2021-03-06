#include "hnewproduct.h"
#include "ui_hnewproduct.h"
#include "hnuovaricetta.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include "huser.h"

HNewProduct::HNewProduct(HUser *pusr, QSqlDatabase pdb,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HNewProduct)
{

    ui->setupUi(this);
    Q_UNUSED(pusr);


    db=pdb;

    tmTipo=new QSqlTableModel(0,db);
    tmTipo->setTable("tipi_prodotto");
    tmTipo->setSort(1,Qt::AscendingOrder);
    tmTipo->select();

    ui->comboBox->setModel(tmTipo);
    ui->comboBox->setModelColumn(1);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(tipoSelected()));


}

HNewProduct::~HNewProduct()
{
    delete ui;
}




void HNewProduct::addNewProduct()
{
    QSqlQuery q(db);
    QString query;
    QVariant codice,descrizione,tipo,allergenico,attivo,bio;
    codice=ui->leCodice->text();
    descrizione=ui->leDescrizione->text().toUpper();
    tipo=ui->comboBox->model()->index(ui->comboBox->currentIndex(),0).data(0).toString();
    if (ui->cbAllergenico->isChecked())
    {
       allergenico="1";
    }
    else
    {
        allergenico="0";
    }
    if (ui->cbBio->isChecked())
    {
       bio="1";
    }
    else
    {
        bio="0";
    }


    attivo="1";


    query="INSERT INTO prodotti (codice,descrizione,tipo,allergenico,attivo,bio) VALUES(:codice,:desc,:tipo,:allerg,:attivo,:bio)";
    q.prepare(query);
    q.bindValue(":codice",QVariant(codice));
    q.bindValue(":desc",QVariant(descrizione));
    q.bindValue(":tipo",QVariant(tipo));
    q.bindValue(":allerg",QVariant(allergenico));
    q.bindValue(":attivo",QVariant(attivo));
    q.bindValue(":bio",QVariant(bio));

    bool s=q.exec();
    if(s)
    {
        QMessageBox::warning(this, QApplication::applicationName(),"Prodotto salvato",QMessageBox::Ok);
        emit done();
        close();

    }
    else
    {
        QMessageBox::warning(this, QApplication::applicationName(),"Errore salvando il prodotto\n"+q.lastError().text(),QMessageBox::Ok);
    }
}



void HNewProduct::on_pbSave_clicked()
{
    addNewProduct();
}


void HNewProduct::on_pbCancel_clicked()
{
    close();
}
