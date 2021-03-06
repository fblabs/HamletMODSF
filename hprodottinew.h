#ifndef HPRODOTTINEW_H
#define HPRODOTTINEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include "huser.h"
#include "hproductsmodel.h"

namespace Ui {
class HProdottiNew;
}

class HProdottiNew : public QWidget
{
    Q_OBJECT

public:
    explicit HProdottiNew(QSqlDatabase pdb=QSqlDatabase(),HUser *puser=0,QWidget *parent=0);
    ~HProdottiNew();
private slots:
    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_radioButton_5_toggled(bool checked);

    void on_radioButton_6_toggled(bool checked);

    void save();

    void reloadProduct();



    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_lineEdit_textChanged(const QString &arg1);




    void on_rbBio_toggled(bool checked);

    void on_tvProdotti_doubleClicked(const QModelIndex &index);

    void on_pbMod_clicked();

private:
    Ui::HProdottiNew *ui;
    QString sConn;
    QSqlDatabase db;
    HProductsModel *tmProdotti;
    QSqlRelationalTableModel *tmTipi;
    HUser *user;


};

#endif // HPRODOTTINEW_H
