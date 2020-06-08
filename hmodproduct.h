#ifndef HMODPRODUCT_H
#define HMODPRODUCT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include "huser.h"


enum FIELDS{
    ID=0,
    CODICE=1,
    DESCRIZIONE=2,
    TIPO=3,
    ALLERGENE=4,
    ATTIVO=5,
    BIO=6,
    PRICE=7
};

namespace Ui {
class HModProduct;
}

class HModProduct : public QWidget
{
    Q_OBJECT

public:
    explicit HModProduct(int pID=-1, QSqlDatabase pdb=QSqlDatabase(), QWidget *parent = 0);
    ~HModProduct();

private:
    Ui::HModProduct *ui;
    QSqlDatabase db;
    QSqlRelationalTableModel *productsmodel;
    QSqlTableModel *typemod;
    QDataWidgetMapper *map;
    int ID;
    private slots:
   bool getProductData();

   void on_pbClose_clicked();
   void on_pbSave_clicked();
   void setModifyEnabled(bool enable=false);
   void save();

signals:
   void done();
};

#endif // HMODPRODUCT_H
