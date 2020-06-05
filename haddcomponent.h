#ifndef HADDCOMPONENT_H
#define HADDCOMPONENT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include "huser.h"


namespace Ui {
class HAddComponent;
}

class HAddComponent : public QWidget
{
    Q_OBJECT

public:
    explicit HAddComponent(int p_idlotto=-1,HUser *p_user=0,QSqlDatabase p_db=QSqlDatabase(), QWidget *parent = 0);
    ~HAddComponent();

private:
    Ui::HAddComponent *ui;
    QSqlDatabase db;
    QSqlTableModel *prodmod;
    QSqlQueryModel *mod;
    HUser *user;
    int idlotto;
    void addComponent();

signals:
    void done();
private slots:
    void on_rbTutti_toggled(bool checked);

    void on_rbMateriali_toggled(bool checked);
    void on_rbProdotti_toggled(bool checked);

    void on_rbRipieni_toggled(bool checked);
    void on_rbConfezioni_toggled(bool checked);
    void on_rbImpasti_toggled(bool checked);
    void on_cbProdotto_currentIndexChanged(int index);
    void addComponentOperation();
    void updateComposizioneLot(int idoperazione=-1);
    void refreshModel();

    void on_pbConfirm_clicked();
    void on_pbClose_clicked();

};

#endif // HADDCOMPONENT_H
