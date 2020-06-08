#ifndef HPACKVIEW_H
#define HPACKVIEW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "huser.h"

namespace Ui {
class HPackView;
}

class HPackView : public QWidget
{
    Q_OBJECT

public:
    explicit HPackView(QSqlDatabase pdb,HUser *puser,QWidget *parent = 0);
    ~HPackView();

private:
    Ui::HPackView *ui;
    QSqlDatabase db;
    QSqlTableModel *mod;
    HUser *user;
private slots:
    void setFilter();
    void on_deDal_dateChanged(const QDate &date);
    void on_deAl_dateChanged(const QDate &date);
    void on_pbClose_clicked();
    void modifySelected(int pidlotto=-1 );
    void on_pbMod_clicked();
    void on_tvPacks_doubleClicked(const QModelIndex &index);
};

#endif // HPACKVIEW_H
