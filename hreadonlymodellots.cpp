#include "hreadonlymodellots.h"
#include <QSqlRelationalTableModel>
#include <QColor>
#include <QDebug>
#include <QIcon>



HReadOnlyModelLots::HReadOnlyModelLots(QObject *parent,QSqlDatabase db ): QSqlRelationalTableModel(parent,db)
{

}

Qt::ItemFlags HReadOnlyModelLots::flags(const QModelIndex & item ) const
{
//// qDebug()<<item.column();

Qt::ItemFlags flags=QSqlRelationalTableModel::flags(item);

 /*  if (item.column()==15)
   {

      // flags &= Qt::ItemIsUserCheckable;
       flags |= Qt::ItemIsEditable;
       flags &= Qt::ItemIsEnabled;

       return flags;
   }
   else
   {
      return QSqlRelationalTableModel::flags(item)  ;
   }*/


 return QSqlRelationalTableModel::flags(item) ;

}

QVariant HReadOnlyModelLots::data( const QModelIndex & item, int role /*= Qt::DisplayRole*/ ) const
{
    int row=item.row();

    int tipo=QSqlRelationalTableModel::data(this->index(row,3)).toInt();


   if (item.column()==3 && tipo==1 && role==Qt::DecorationRole)
   {
     return QIcon(":/Resources/fork-1-icon.png");
   }
   if (item.column()==3 && tipo==2 && role==Qt::DecorationRole)
   {
     return QIcon(":/Resources/Actions-configure-icon.png");
   }
   if (item.column()==3 && tipo==3 && role==Qt::DecorationRole)
   {
      return QIcon(":/Resources/Gears.PNG");
   }
  if (item.column()==3 && tipo==4 && role==Qt::DecorationRole)
   {
    return QIcon(":/Resources/Box.PNG");
   }
   if (item.column()==15)
   {


  //     QVariant value=QSqlRelationalTableModel::data(item);
       if (role==Qt::CheckStateRole)
           return (QSqlRelationalTableModel::data(item).toInt() != 0) ? Qt::Checked :Qt::Unchecked;
       else
           return QVariant();


   }

  return QSqlRelationalTableModel::data(item,role);
}

bool HReadOnlyModelLots::setData(const QModelIndex &index, const QVariant &value, int role)
{
     QSqlRelationalTableModel::setData(index,value,role);
     return true;
}
