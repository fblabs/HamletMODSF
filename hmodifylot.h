#ifndef HMODIFYLOT_H
#define HMODIFYLOT_H

#include <QWidget>
#include <QSqlDatabase>
#include "hcomposizionelotto.h"
#include "huser.h"


namespace Ui {
class HModifyLot;
}

class HModifyLot : public QWidget
{
    Q_OBJECT

public:
    explicit HModifyLot( int pidlotto=-1,HUser *p_user=0, QSqlDatabase pdb=QSqlDatabase(),QWidget *parent = 0);
    ~HModifyLot();


private slots:

    void updateLot();

    void on_cbScad_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pbComposizione_clicked();

    void on_pbClose_clicked();

    void on_pbLotOperations_clicked();

private:
    Ui::HModifyLot *ui;
    QSqlDatabase db;
    HUser *user;
    int lot;
    int tipo;


signals:
    void updatedLot();
};

#endif // HMODIFYLOT_H
