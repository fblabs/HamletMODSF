#include "hlotti.h"
#include "ui_hlotti.h"
 #include <QDebug>
#include <QDate>
#include <QSqlError>
#include <QSqlquery>
#include <QSqlRelationalDelegate>
#include <QMessageBox>
#include <QPainter>
#include <QsqlTableModel>
#include "hnewop.h"
#include "hmodifylot.h"
#include "hreadonlymodellots.h"
#include "hnuovaoperazione.h"
#include <QMenu>
#include <QClipboard>
#include "hprint.h"
#include <QThread>
#include "huser.h"
#include "hpackagesunload.h"
#include "hcomposizionelotto.h"
#include <QCompleter>
#include "hexpirations.h"
#include "hlotmod.h"


HLotti::HLotti(QSqlDatabase pdb, HUser *puser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HLotti)
{

    ui->setupUi(this);
    ui->pbUnload->setVisible(false);

    user=puser;
    db=pdb;
    dateset=false;

    ui->chBio->setVisible(false);




    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

   tbm = new HReadOnlyModelLots(0,db);

   tbm->setTable("lotti_view");


   tbm->setHeaderData(4,Qt::Horizontal,QObject::tr("Data"));
   tbm->setHeaderData(5,Qt::Horizontal,QObject::tr("Lotto Interno"));
   tbm->setHeaderData(6,Qt::Horizontal,QObject::tr("LOTTO"));
   tbm->setHeaderData(7,Qt::Horizontal,QObject::tr("Codice Prod."));
   tbm->setHeaderData(8,Qt::Horizontal,QObject::tr("Prodotto"));
   tbm->setHeaderData(9,Qt::Horizontal,QObject::tr("Giacenza"));
   tbm->setHeaderData(10,Qt::Horizontal,QObject::tr("Unità di misura"));
   tbm->setHeaderData(11,Qt::Horizontal,QObject::tr("Scadenza"));
   tbm->setHeaderData(12,Qt::Horizontal,QObject::tr("Provenienza"));
   tbm->setHeaderData(13,Qt::Horizontal,QObject::tr("Lotto Fornitore"));
   tbm->setHeaderData(14,Qt::Horizontal,QObject::tr("Bolla"));
   tbm->setHeaderData(16,Qt::Horizontal,QObject::tr("Note"));



   /*tbm->setRelation(3,QSqlRelation("prodotti","ID","codice"));
   tbm->setRelation(4,QSqlRelation("prodotti","ID","descrizione"));
   tbm->setRelation(5,QSqlRelation("unita_di_misura","ID","descrizione"));
   tbm->setRelation(8,QSqlRelation("anagrafica","ID","ragione_sociale"));
   tbm->setRelation(11,QSqlRelation("tipi_lot","ID","descrizione"));
   tbm->setSort(3,Qt::DescendingOrder);*/
   tbm->select();
   tbm->lastError().text();
  // tbm->setFilter("lotdef.attivo>0");*

   ui->twLots->setModel(tbm);
   //ui->twLots->setItemDelegate(new QSqlRelationalDelegate(tbm));
  // ui->twLots->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
   ui->twLots->horizontalHeader()->setStretchLastSection(true);
   ui->twLots->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

  // ui->twLots->setColumnWidth(11,10);
   ui->twLots->setColumnHidden(0,true);
   ui->twLots->setColumnHidden(1,true);
   ui->twLots->setColumnHidden(2,true);
   ui->twLots->setColumnHidden(3,true);

   ui->pushButton_7->setEnabled(false);


   ui->datadal->setDate(QDate::currentDate().addYears(-1));
   ui->dataal->setDate(QDate::currentDate());
   dal=ui->datadal->date();
   al=ui->dataal->date();







    det=new QShortcut(QKeySequence("F5"),this);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContextMenu(QPoint)));
    connect(det,SIGNAL(activated()),this,SLOT(getDetails()));


    getDataLots();
    dateset=true;

    setFilter();
    ui->twLots->selectRow(0);
    QApplication::setOverrideCursor(Qt::ArrowCursor);

}



HLotti::~HLotti()
{

    delete ui;

}

void HLotti::getDataLots()
{
    mTipi=new QSqlTableModel(0,db);
    mTipi->setTable("tipi_lot");
    mTipi->select();
    mTipi->setSort(1,Qt::AscendingOrder);

    mTipiProdotto=new QSqlTableModel(0,db);
    mTipiProdotto->setTable("tipi_prodotto");
    mTipiProdotto->select();
    mTipiProdotto->setSort(1,Qt::AscendingOrder);

    mProdotti=new QSqlTableModel(0,db);
    mProdotti->setTable("prodotti");
    mProdotti->setSort(2,Qt::AscendingOrder);
    mProdotti->select();



    ui->cbTipiLot->setModel(mTipi);
    ui->cbTipiLot->setModelColumn(1);
    ui->cbTipiLot->setCurrentIndex(0);


    ui->cbTipoProd->setModel(mTipiProdotto);
    ui->cbTipoProd->setModelColumn(1);
    ui->cbTipoProd->setCurrentIndex(0);



    ui->cbProdotti->setModel(mProdotti);
    ui->cbProdotti->setModelColumn(2);
    ui->cbProdotti->completer()->setCompletionMode(QCompleter::PopupCompletion);
    ui->cbProdotti->setCurrentIndex(0);

}

void HLotti::editLot()
{
    int idlotto=ui->twLots->model()->index(ui->twLots->selectionModel()->currentIndex().row(),0).data(0).toInt();
    HModifyLot *f=new HModifyLot(idlotto,user,db);
    connect(f,SIGNAL(updateLot()),this,SLOT(updateTableView()));
    f->show();

}

void HLotti::getDetails()
{
    int lot=ui->twLots->model()->index(ui->twLots->selectionModel()->currentIndex().row(),0).data(0).toInt();
    QString desc=ui->twLots->model()->index(ui->twLots->selectionModel()->currentIndex().row(),1).data(0).toString();
    desc+= " - ";
    desc+=ui->twLots->model()->index(ui->twLots->selectionModel()->currentIndex().row(),2).data(0).toString();


    HComposizioneLotto *f=new HComposizioneLotto(0,db,lot,desc);
    f->show();
}

void HLotti::showContextMenu(const QPoint &pos)
{
    QPoint globalPos =mapToGlobal(pos);
    QMenu *menu=new QMenu(0);

    QAction *detailsAction=menu->addAction("Composizione/uso lotto");
    menu->addSeparator();
    QAction *copyAction=menu->addAction("Copia il testo sotto il cursore");
    QAction *editAction=menu->addAction("Modifica/Copia dati ...");
   //. detailsAction->setShortcut(QKeySequence("Ctrl+F5"));

    connect(detailsAction,SIGNAL(triggered(bool)),this,SLOT(getDetails()));
    connect(copyAction,SIGNAL(triggered(bool)),this,SLOT(copyField()));
    connect(editAction,SIGNAL(triggered(bool)),this,SLOT(editLot()));



    menu->popup(globalPos);
}

void HLotti::copyField()
{
    QString field=ui->twLots->currentIndex().data(0).toString();
    QClipboard *clipboard= QApplication::clipboard();
    clipboard->setText(field);
}

void HLotti::on_pbUnload_clicked()
{

   HPackagesUnload *f=new HPackagesUnload(user,db);
   f->show();
   connect(f,SIGNAL(update()),this,SLOT(updateTableView()));


}

void HLotti::on_pushButton_3_clicked()
{
    if( QMessageBox::Ok == QMessageBox::question(this, QApplication::applicationName(), "Chiudere la finestra?", QMessageBox::Ok |QMessageBox::Cancel))
      {

        this->close();
       // this->deleteLater();
      }
}




void HLotti::resetData()
{
    tbm->select();
}




void HLotti::on_pushButton_4_clicked()
{

   HnuovaOperazione *f = new HnuovaOperazione(user,db);

   f->show();
   connect(f,SIGNAL(trigger()),this,SLOT(updateTableView()));

}



void HLotti::setFilter()
{
    QString tipo,prodotto,filter;


       dal=ui->datadal->date();
       al=ui->dataal->date();


       filter="";


       QString datafilter="lotti_view.data between cast('" + dal.toString("yyyy-MM-dd") + "' as date) and cast('" + al.addDays(1).toString("yyyy-MM-dd")+"' as date)";

       filter=datafilter;

       if (ui->chbT->isChecked())
       {
           //filtra solo per tipo
          tipo=mTipi->index(ui->cbTipiLot->currentIndex(),0).data(0).toString();
          filter="lotti_view.tipolot="+tipo+ " and "+datafilter;

       }
       else if (ui->chbP->isChecked())
       {
           //filtra per prodotto
           prodotto=mProdotti->index(ui->cbProdotti->currentIndex(),0).data(0).toString();
           filter="lotti_view.idprodotto="+prodotto+" and "+datafilter;
           qDebug()<<filter;
       }
       else if(ui->chTipoProdotti->isChecked())
       {
           //filtra  per entrambi
           tipo=mTipiProdotto->index(ui->cbTipoProd->currentIndex(),0).data(0).toString();
           filter="lotti_view.idprodotto in (SELECT ID from prodotti where tipo=" + tipo + ") and "+datafilter;
       }

       tbm->setFilter(filter);

   qDebug()<<tbm->filter()<<tbm->lastError().text()<<tbm->query().lastQuery();


}



void HLotti::on_pushButton_6_clicked()
{
  print();
}



void HLotti::print()
{


    HPrint *f =new HPrint();

    int rows=ui->twLots->model()->rowCount();
    int cols=ui->twLots->model()->columnCount();



    f->append("PRODUZIONE DAL "+ ui->datadal->text().toUpper() + " AL " + ui->dataal->text().toUpper(),false);
    f->toggleImageUI(false);
    f->showMaximized();
    QTextTable *tb=f->addTable(rows,cols);
    QString txt;

   int r,c;


    f->showMaximized();

    for (r=0;r<rows;r++)
    {


        for (c=0; c<cols; c++)
        {
            txt=ui->twLots->model()->index(r,c).data(0).toString();
            f->writeTableContent(tb,r,c,txt);
            QApplication::processEvents();


        }
        QApplication::processEvents();

    }
  //  QApplication::processEvents();



}

void HLotti::updateTableView()
{
    if(tbm) tbm->select();
    qDebug()<<"update";
}

void HLotti::modifySelected(int pidlotto)
{

   HModifyLot *f=new HModifyLot(pidlotto,user,db);
   connect(f,SIGNAL(updatedLot()),this,SLOT(updateTableView()));
   f->show();

}

void HLotti::on_pushButton_7_clicked()
{
    int idlotto=ui->twLots->model()->index(ui->twLots->currentIndex().row(),0).data(0).toInt();

    modifySelected(idlotto);

}

void HLotti::on_leLottoRaw_textChanged(const QString &arg1)
{
    QString filter="lotti_view.lotto like '" +arg1+"%'";
    tbm->setFilter(filter);
   // // qDebug()<<tbm->query().lastError().text();
}



void HLotti::on_chTipoProdotti_toggled(bool checked)
{
    if(checked)
    {

      //  ui->chTipoProdotti->setEnabled(true); //check tipo prodotti
      //  ui->chTipoProdotti->setChecked(true);

        ui->chbT->setEnabled(false);//check tipo lotti
        ui->chbT->setChecked(false);
        ui->cbTipiLot->setEnabled(false);

        ui->chbP->setEnabled(false);
        ui->chbP->setChecked(false);
        ui->cbProdotti->setEnabled(false);


    }
    else
    {

          ui->cbTipoProd->setEnabled(checked); //combo tipo prodotti

          ui->chbT->setEnabled(true);//check tipo lotti
          ui->cbTipiLot->setEnabled(false);

          ui->chbP->setEnabled(true);
          ui->chbP->setChecked(false);
          ui->cbProdotti->setEnabled(false);
    }

    ui->cbTipoProd->setEnabled(checked); //combo tipo prodotti



    setFilter();

}

void HLotti::on_cbTipoProd_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    if(ui->cbTipoProd->isEnabled())
    {
    setFilter();
    }
}



void HLotti::on_chbT_toggled(bool checked)
{


    if(checked)
    {

        ui->chTipoProdotti->setEnabled(false); //check tipo prodotti
        ui->chTipoProdotti->setChecked(false);
        ui->cbTipoProd->setEnabled(false); //combo tipo prodotti
        ui->cbTipiLot->setEnabled(true);
        ui->chbP->setEnabled(true);
        ui->chbP->setChecked(false);



    }
    else
    {
          ui->chTipoProdotti->setEnabled(true); //check tipo prodotti
          ui->chTipoProdotti->setChecked(false);
          ui->chbP->setEnabled(true);

    }

    setFilter();
}

void HLotti::on_cbTipiLot_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    if(ui->cbTipiLot->isEnabled())
    {
        setFilter();
    }
}



void HLotti::on_chbP_toggled(bool checked)
{
    if(checked)
    {

        ui->chTipoProdotti->setEnabled(false); //check tipo prodotti
        ui->chTipoProdotti->setChecked(false);
        ui->cbProdotti->setEnabled(true);



    }
    else
    {
          ui->chTipoProdotti->setEnabled(true);
          ui->chbP->setEnabled(true);
          ui->chbP->setChecked(false);
          ui->cbProdotti->setEnabled(false);
    }
    setFilter();
}



void HLotti::on_cbProdotti_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    qDebug()<<"cbprodotti";
    setFilter();
}

void HLotti::on_twLots_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);

    int row=ui->twLots->selectionModel()->currentIndex().row();

    int idlotto=ui->twLots->model()->index(row,0).data(0).toInt();


    modifySelected(idlotto);
    tbm->select();

}


void HLotti::on_pbScadenze_clicked()
{
    HExpirations *f = new HExpirations(db,user);
    f->show();
}

void HLotti::on_datadal_dateChanged(const QDate &date)
{
    if(!dateset)return;
    dal=date;
    setFilter();


}

void HLotti::on_dataal_dateChanged(const QDate &date)
{
    if(!dateset)return;
     al=date;
     setFilter();


}




void HLotti::on_twLots_clicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    ui->pushButton_7->setEnabled(true);
}


void HLotti::on_chBio_toggled(bool checked)
{
    setFilter();
}


void HLotti::on_pbLotMod_clicked()
{
    int idlotto=ui->twLots->model()->index(ui->twLots->currentIndex().row(),0).data(0).toInt();
    QString lotto=ui->twLots->model()->index(ui->twLots->currentIndex().row(),5).data(0).toString();
    QString prodotto=ui->twLots->model()->index(ui->twLots->currentIndex().row(),8).data(0).toString();
    QString desc=lotto + " - " + prodotto;

    HComposizioneLotto *f=new HComposizioneLotto(user,db,idlotto,desc);

    f->show();
}







void HLotti::on_leLotInterno_textChanged(const QString &arg1)
{
    QString filter="lotti_view.LotInt like '" +arg1+"%'";
    tbm->setFilter(filter);
}
