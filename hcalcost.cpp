#include "hcalcost.h"
#include "ui_hcalcost.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include "huser.h"
#include <QCompleter>
#include "hprodottinew.h"

#include <QSqlQueryModel>
HCalcost::HCalcost(QSqlDatabase pdb, HUser* puser,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HCalcost)
{
    ui->setupUi(this);
    user=puser;
    db=pdb;

    ui->label_2->setVisible(false);
    ui->leCostoProdotto->setVisible(false);

    getClients();

    getProducts();
    getConfezionamenti(3);
    getConfezionamenti(4);
    getConfezionamenti(5);




}

HCalcost::~HCalcost()
{
    delete ui;
}

void HCalcost::getClients()
{
    QSqlTableModel *clientsmod=new QSqlTableModel(0,db);
    clientsmod->setTable("anagrafica");
    clientsmod->setSort(1,Qt::AscendingOrder);
    clientsmod->setFilter("cliente=1");
    clientsmod->select();
    ui->cbClients->setModel(clientsmod);
    ui->cbClients->setModelColumn(1);

    QCompleter *completer=new QCompleter();
    completer->setModel(clientsmod);
    completer->setCompletionColumn(1);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    ui->cbClients->setCompleter(completer);

}



void HCalcost::getProducts()
{
   int idcliente=ui->cbClients->model()->index(ui->cbClients->currentIndex(),0).data(0).toInt();
   QSqlQuery q(db);
   QString sql="select prodotti.ID,prodotti.descrizione from prodotti,ricette WHERE prodotti.ID=ricette.ID_prodotto AND ricette.ID IN (SELECT associazioni.ID_ricetta FROM associazioni WHERE associazioni.ID_cliente=:idc)";
   q.prepare(sql);
   q.bindValue(":idc",idcliente);
   q.exec();

   cmod= new QSqlQueryModel();
   cmod->setQuery(q);
   ui->lvProdotti->setModel(cmod);
   ui->lvProdotti->setModelColumn(1);

}


void HCalcost::getRecipe()
{
    resetUI();
    int idp=cmod->index(ui->lvProdotti->selectionModel()->currentIndex().row(),0).data(0).toInt();
    QSqlQuery q(db);
    QString sql="SELECT prodotti.descrizione as 'PRODOTTO',righe_ricette.quantita as 'QUANTITA',prodotti.prezzo as 'Costo unitario ingrediente',righe_ricette.quantita*prodotti.prezzo as 'COSTO' FROM righe_ricette,prodotti,ricette WHERE righe_ricette.ID_ricetta=ricette.ID and prodotti.ID=righe_ricette.ID_prodotto and ricette.ID=(SELECT ID from ricette where ricette.ID_prodotto=:idp) group by prodotti.ID,ricette.ID,righe_ricette.ID";
    q.prepare(sql);
    q.bindValue(":idp",idp);
    q.exec();
    qDebug()<<idp<<q.lastError().text();
    ricmod=new QSqlQueryModel();
    ricmod->setQuery(q);
    ui->tvComponenti->setModel(ricmod);
    ui->tvComponenti->horizontalHeader()->resizeSections(QHeaderView::Stretch);

    int r=ricmod->rowCount();
    double cost=0.0;
    double quant=0.0;
    double costoperunita=0.0;

    for (int x=0; x<r; x++)
    {
        cost +=ricmod->index(x,3).data(0).toDouble();
        quant +=ricmod->index(x,1).data(0).toDouble();
    }

    costoperunita=cost/quant;

    ui->leQuantitaProdotto->setText(QString::number(quant,'f',3));
    ui->leCostounitaricetta->setText(QString::number(costoperunita,'f',4));

    ui->leCostoProdotto->setText(QString::number(cost,'f',4));


}

void HCalcost::on_leQuantitaProdotto_returnPressed()
{

}

void HCalcost::getConfezionamenti(int tipo)
{
    QSqlQueryModel *modtappi=new QSqlQueryModel();
    QSqlQueryModel *modvasi=new QSqlQueryModel();
    QCompleter *tappicomp=new QCompleter();
    QCompleter *vasicomp=new QCompleter();

    QSqlQuery q(db);
    QString sql = "SELECT id, descrizione,prezzo from prodotti WHERE tipo=:tipo order by descrizione asc";

    q.prepare(sql);
    q.bindValue(":tipo",tipo);

    q.exec();


    switch (tipo)
    {
        case 4:

        modtappi->setQuery(q);
        ui->cbTappi->setModel(modtappi);
        ui->cbTappi->setModelColumn(1);

        tappicomp->setModel(modtappi);
        tappicomp->setCompletionColumn(1);
        tappicomp->setCompletionMode(QCompleter::PopupCompletion);
        tappicomp->setCaseSensitivity(Qt::CaseInsensitive);
        ui->cbTappi->setCompleter(tappicomp);
        break;

        case 5:

        modvasi->setQuery(q);
        ui->cbVasi->setModel(modvasi);
        ui->cbVasi->setModelColumn(1);

        vasicomp->setModel(modvasi);
        vasicomp->setCompletionColumn(1);
        vasicomp->setCompletionMode(QCompleter::PopupCompletion);
        vasicomp->setCaseSensitivity(Qt::CaseInsensitive);

        ui->cbVasi->setCompleter(vasicomp);

    default:
        return;

    }



}



void HCalcost::on_pbClose_clicked()
{
    if (QMessageBox::question(this,QApplication::applicationName(),"Chiudere?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        close();
    }
}

void HCalcost::on_lvProdotti_clicked(const QModelIndex &index)
{


        getRecipe();

}

void HCalcost::resetUI()
{
    ui->leDaprodurre->setText("");
    ui->leCostoFisso->setText("");
    ui->leCostoProduzione->setText("");
    ui->leCostoProdotto->setText("");
    ui->leCostoCartoni->setText("");
    ui->leCostoEtichette->setText("");
    ui->leCostoTappi->setText("");
    ui->leCostoEtichette->setText("");
    ui->leCostounitaricetta->setText("");
    ui->leCostoVasi->setText("");
}


void HCalcost::on_cbClients_currentIndexChanged(int index)
{
    getProducts();
}

void HCalcost::on_cbVasi_currentIndexChanged(int index)
{
    double prezzo = ui->cbVasi->model()->index(ui->cbVasi->currentIndex(),2).data(0).toDouble();
    int n=ui->leQtVasi->text().toInt();
    QString price=QString::number(prezzo*n,'f',4);
    ui->leCostoVasi->setText(price);
}

void HCalcost::on_cbTappi_currentIndexChanged(int index)
{
    double prezzo = ui->cbTappi->model()->index(ui->cbTappi->currentIndex(),2).data(0).toDouble();
    int n=ui->leQtTappi->text().toInt();
    QString price=QString::number(prezzo*n,'f',4);
    ui->leCostoTappi->setText(price);
}


void HCalcost::on_leQtVasi_returnPressed()
{
    double prezzo = ui->cbVasi->model()->index(ui->cbVasi->currentIndex(),2).data(0).toDouble();
    int n=ui->leQtVasi->text().toInt();
    QString price=QString::number(prezzo*n,'f',4);
    ui->leCostoVasi->setText(price);
}

void HCalcost::on_leQtTappi_returnPressed()
{
    double prezzo = ui->cbTappi->model()->index(ui->cbTappi->currentIndex(),2).data(0).toDouble();
    int n=ui->leQtTappi->text().toInt();
    QString price=QString::number(prezzo*n,'f',4);
    ui->leCostoTappi->setText(price);
}

void HCalcost::on_leDaprodurre_returnPressed()
{
    double costokg=ui->leCostounitaricetta->text().toDouble();
    double quantita = ui->leDaprodurre->text().toDouble();

    double prezzo= costokg*quantita;
    ui->leCostoProduzione->setText(QString::number(prezzo,'f',4));
}

void HCalcost::on_leCostoTotale_returnPressed()
{

}

void HCalcost::on_pbCalcola_clicked()
{

    performCalculation();


}

void HCalcost::on_pbPrint_clicked()
{
    HPrint *f=new HPrint();
    f->toggleImageUI(false);
    f->show();

    f->append("COSTO PRODOTTO "+ui->lvProdotti->currentIndex().data(0).toString());
    f->append("\nda produrre: \tKg "+ ui->leDaprodurre->text());
    f->append("Costo fisso: \t€ "+ ui->leCostoFisso->text());
    f->append("Costo vasi: \t€ "+ui->leCostoVasi->text());
    f->append("Costo tappi: \t€ "+ui->leCostoTappi->text());
    f->append("Costo cartoni: \t€ "+ui->leCostoCartoni->text());
    f->append("Costo etichette: \t€ "+ui->leCostoEtichette->text());
    f->append("====================================================");
    f->append("Costo prodotto: \t€ "+ui->leCostoTotale->text());
    f->append("====================================================");



}

void HCalcost::on_pushButton_clicked()
{
    HProdottiNew* f = new HProdottiNew(db,user);
    f->show();
}

void HCalcost::performCalculation()
{
    double costototale=0.0;
    double costoprodotto=0.0;
    double costovasi=0.0;
    double costotappi=0.0;
    double costocartoni=0.0;
    double costoetichette=0.0;
    double costofisso=0.0;

    costoprodotto=ui->leCostoProduzione->text().toDouble();
    costovasi=ui->leCostoVasi->text().toDouble();
    costotappi=ui->leCostoTappi->text().toDouble();
    costocartoni=ui->leCostoCartoni->text().toDouble();
    costoetichette=ui->leCostoEtichette->text().toDouble();
    costofisso=ui->leCostoFisso->text().toDouble();

    costototale=costoprodotto + costovasi + costotappi + costocartoni +costoetichette +costofisso;

    ui->leCostoTotale->setText(QString::number(costototale,'f',4));
}
