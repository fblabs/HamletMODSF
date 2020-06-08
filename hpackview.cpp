#include "hpackview.h"
#include "ui_hpackview.h"
#include <QSqlDatabase>
#include "huser.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>
#include "hcomposizionelotto.h"
#include "hmodifylot.h"

HPackView::HPackView(QSqlDatabase pdb=QSqlDatabase(),HUser *puser=0,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HPackView)
{
    ui->setupUi(this);
    db=pdb;

    user=puser;
    mod=new QSqlTableModel(0,db);
    mod->setTable("lotdef_view");
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("DATA"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("LOTTO"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("CODICE PRODOTTO"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("DESCRIZIONE PRODOTTO"));
    mod->setHeaderData(5,Qt::Horizontal,QObject::tr("GIACENZA"));
    mod->setHeaderData(6,Qt::Horizontal,QObject::tr("UNITA' DI MISURA"));
    mod->setHeaderData(7,Qt::Horizontal,QObject::tr("SCADENZA"));
    ui->deDal ->setDate(QDate::currentDate().addMonths(-1));
    ui->deAl->setDate(QDate::currentDate());
    setFilter();
    mod->select();

    ui->tvPacks->setModel(mod);
    ui->tvPacks->setColumnHidden(0,true);
    ui->tvPacks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

HPackView::~HPackView()
{
    delete ui;
}

void HPackView::setFilter()
{
    mod->setFilter("lotdef_view.data between cast('" + ui->deDal->date().toString("yyyy-MM-dd") + "' as date) and cast('" + ui->deAl->date().toString("yyyy-MM-dd")+"' as date)");

}

void HPackView::on_deDal_dateChanged( const QDate &date)
{
    Q_UNUSED(date);
    setFilter();
}

void HPackView::on_deAl_dateChanged(const QDate &date)
{
    Q_UNUSED(date);
    setFilter();
}

void HPackView::on_pbClose_clicked()
{
    close();
}

void HPackView::modifySelected(int pidlotto)
{

   HModifyLot *f=new HModifyLot(pidlotto,user,db);
   connect(f,SIGNAL(updatedLot()),this,SLOT(updateTableView()));
   f->show();

}


void HPackView::on_pbMod_clicked()
{
    int idlotto=ui->tvPacks->model()->index(ui->tvPacks->currentIndex().row(),0).data(0).toInt();

    HComposizioneLotto *f=new HComposizioneLotto(user,db,idlotto,ui->tvPacks->model()->index(ui->tvPacks->selectionModel()->currentIndex().row(),1).data(0).toString() + " - " + ui->tvPacks->model()->index(ui->tvPacks->selectionModel()->currentIndex().row(),2).data(0).toString());

    f->show();
}


void HPackView::on_tvPacks_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);

    int row=ui->tvPacks->selectionModel()->currentIndex().row();

    int idlotto=ui->tvPacks->model()->index(row,0).data(0).toInt();


    modifySelected(idlotto);
    mod->select();
}
