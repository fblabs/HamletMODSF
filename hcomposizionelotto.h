#ifndef HCOMPOSIZIONELOTTO_H
#define HCOMPOSIZIONELOTTO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QShortcut>
#include <QList>
#include "huser.h"

namespace Ui {
class HComposizioneLotto;
}

class HComposizioneLotto : public QWidget
{
    Q_OBJECT

public:
    explicit HComposizioneLotto(HUser *p_user=0, QSqlDatabase pdb=QSqlDatabase(), int idLotto=-1, QString descrizione="",HComposizioneLotto *parentf=0,QWidget *parent = 0);
    ~HComposizioneLotto();

private:
    Ui::HComposizioneLotto *ui;
    QSqlDatabase db;
    int id;
    int tipo;

    QString desc;
    QSqlQueryModel *mod;
    HComposizioneLotto *parf;
    QShortcut *det;
    HUser *user;

private slots:
    void getLotComposition();
    void getLotUse();

    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_pushButton_3_clicked();
    void print();
    void printUse();
    void printComposition();
    int getTipo(int idl);
    void getDetails();
    void removeComponent();

    void on_pbRemove_clicked();
    void on_pbAdd_clicked();
    void refresh();
    void on_pbPrint_clicked();
signals:
    wclose();

};

#endif // HCOMPOSIZIONELOTTO_H
