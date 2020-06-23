#include "hmodifylot.h"
#include "ui_hmodifylot.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlTableModel>
 #include <QDebug>
#include "hcomposizionelotto.h"
#include <QSqlError>
#include "hlotmovements.h"
#include <QCompleter>
#include "huser.h"


HModifyLot::HModifyLot(int pidlotto, HUser *p_user, QSqlDatabase pdb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HModifyLot)
{
    ui->setupUi(this);

    db=pdb;
    lot=pidlotto;
    user=p_user;
    QSqlTableModel *mum=new QSqlTableModel(0,db);
    QSqlTableModel *mang=new QSqlTableModel(0,db);
    QSqlTableModel *mtipi=new QSqlTableModel(0,db);


    mum->setTable("unita_di_misura");
    mum->setSort(1,Qt::AscendingOrder);
    mum->select();

    mang->setTable("anagrafica");
    mang->setSort(1,Qt::AscendingOrder);
    mang->select();

    mtipi->setTable("tipi_lot");
    mtipi->setSort(1,Qt::AscendingOrder);
    mtipi->select();


    QCompleter *cum=new QCompleter(mum);
    cum->setCompletionColumn(1);
    cum->setCompletionMode(QCompleter::PopupCompletion);
    cum->setCaseSensitivity(Qt::CaseInsensitive);


    QCompleter *cana=new QCompleter(mang);
    cana->setCompletionColumn(1);
    cana->setCompletionMode(QCompleter::PopupCompletion);
    cana->setCaseSensitivity(Qt::CaseInsensitive);


    QCompleter *ctp=new QCompleter(mtipi);
    ctp->setCompletionColumn(1);
    ctp->setCompletionMode(QCompleter::PopupCompletion);
    ctp->setCaseSensitivity(Qt::CaseInsensitive);

    ui->cbAnag->setModelColumn(1);
    ui->cbAnag->setModel(mang);
    ui->cbAnag->setCurrentIndex(0);
    ui->cbAnag->setCompleter(cana);


    ui->cbUm->setModelColumn(1);
    ui->cbUm->setModel(mum);
    ui->cbUm->setCurrentIndex(0);
    ui->cbUm->setCompleter(cum);

    ui->cbtipo->setModelColumn(1);
    ui->cbtipo->setModel(mtipi);
    ui->cbtipo->setCurrentIndex(0);
    ui->cbtipo->setCompleter(ctp);



    QSqlQuery q(db);
    QString sql="SELECT * from lotti_view WHERE ID=:id";
    q.prepare(sql);
    q.bindValue(":id",QVariant(lot));
    q.exec();
    q.first();


    //setto la form ai valori correnti

    QVariant cod=q.value(6);
    QVariant prod=q.value(7);
    QVariant anag=q.value(11);
    QVariant ixtipo=q.value(13);
    QVariant ixum=q.value(9);
    QVariant scadz= q.value(10);
    QVariant attv=q.value(14);
    QVariant lotint=q.value(4);

    if (scadz.isNull())
    {
        ui->cbScad->setChecked(true);
        ui->deScad->setVisible(false);

    }
    else
    {
        ui->cbScad->setChecked(false);
        ui->deScad->setVisible(true);
    }

    ui->leLot->setText(lotint.toString());
    qDebug()<<q.value(5).toString();

    ui->leGiac->setText(QString::number(q.value(8).toDouble(),'n',3));
    ui->deScad->setDate(q.value(10).toDate());
    ui->leLotFornitore->setText(q.value(12).toString());
    ui->leEan->setText(q.value(5).toString());
    ui->ptNote->setPlainText(q.value(15).toString());
    ui->leCodice->setText(cod.toString());
    ui->leProd->setText(prod.toString());

    sql= "select ragione_sociale from anagrafica where ID=:id";
    q.prepare(sql);
    q.bindValue(":id",anag);
    q.exec();
    q.first();

    int idx=ui->cbAnag->findText(anag.toString());
    ui->cbAnag->setCurrentIndex(idx);

    sql= "select descrizione from tipi_lot where ID=:id";
    q.prepare(sql);
    q.bindValue(":id",ixtipo);
    q.exec();
    q.first();

    bool at=attv.toBool();
    ui->cbAttivo->setChecked(at);

    int ixt=ui->cbtipo->findText(q.value(0).toString());
    ui->cbtipo->setCurrentIndex(ixt);

    sql="select descrizione from unita_di_misura where ID=:id";
    q.prepare(sql);
    q.bindValue(":id",ixum);
    q.exec();
    q.first();

    int ium=ui->cbUm->findText(ixum.toString());
    ui->cbUm->setCurrentIndex(ium);
}

HModifyLot::~HModifyLot()
{
    delete ui;
}



void HModifyLot::on_cbScad_toggled(bool checked)
{
    if(checked)
    {
        ui->deScad->setVisible(false);
    }
    else
    {
        ui->deScad->setVisible(true);
    }
}

void HModifyLot::updateLot()
{
    QSqlQuery q(db);
    QString sql;
    bool b=false;

    sql="UPDATE lotdef set um=:um, scadenza=:scad, anagrafica=:anag, lot_fornitore=:lotf, ean=:ean,tipo=:tipo,attivo=:att,note=:note WHERE id=:lotid";
    q.prepare(sql);

    q.bindValue(":um",ui->cbUm->model()->index(ui->cbUm->currentIndex(),0).data(0));

    if(ui->cbScad->isChecked())
    {
        q.bindValue(":scad",QVariant(QVariant::Date));
    }
    else
    {

       q.bindValue(":scad",QVariant(ui->deScad->date()));
    }



    if(ui->cbAttivo->isChecked())
    {
        q.bindValue(":att",true);
    }
    else
    {

       q.bindValue(":att",false);
    }


    q.bindValue(":anag",ui->cbAnag->model()->index(ui->cbAnag->currentIndex(),0).data(0));
    q.bindValue(":lotf",QVariant(ui->leLotFornitore->text()));
    q.bindValue(":ean",QVariant(ui->leEan->text()));
    q.bindValue(":tipo",ui->cbtipo->model()->index(ui->cbtipo->currentIndex(),0).data(0));
    q.bindValue(":note",QVariant(ui->ptNote->toPlainText()));
    q.bindValue(":lotid",QVariant(lot));

    db.transaction();
    b=q.exec();
    qDebug()<<q.lastQuery()<<q.lastError().text();
    if(b)
    {
        db.commit();
        emit updatedLot();
        QMessageBox::information(this,QApplication::applicationName(),"modifiche salvate",QMessageBox::Ok);


    }
    else
    {

        QMessageBox::warning(this,QApplication::applicationName(),"modifiche salvate",QMessageBox::Ok);
        db.rollback();
        QMessageBox::information(this,QApplication::applicationName(),"Errore salvando le modifiche",QMessageBox::Ok);


    }

}

void HModifyLot::on_pushButton_clicked()
{
    if (QMessageBox::Ok==QMessageBox::question(this,QApplication::applicationName(),"Salvare le modifiche?",QMessageBox::Ok|QMessageBox::Cancel))
    {
         updateLot();
    }
}

void HModifyLot::on_pbComposizione_clicked()
{


    HComposizioneLotto *f=new HComposizioneLotto(user,db,lot,ui->leLot->text() + " - " + ui->leProd->text());

    f->show();


}


void HModifyLot::on_pbClose_clicked()
{
   if(QMessageBox::question(this,QApplication::applicationName(),"Chiudere? ATTENZIONE LE MODIFICHE NON SALVATE verranno perse",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {

        close();
    }
}

void HModifyLot::on_pbLotOperations_clicked()
{
    HLotMovements *f =new HLotMovements(lot,db);
    f->show();
}


