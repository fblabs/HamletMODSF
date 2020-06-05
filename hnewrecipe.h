#ifndef HNEWRECIPE_H
#define HNEWRECIPE_H

#include <QWidget>

namespace Ui {
class HNewRecipe;
}

class HNewRecipe : public QWidget
{
    Q_OBJECT

public:
    explicit HNewRecipe(QWidget *parent = 0);
    ~HNewRecipe();

private:
    Ui::HNewRecipe *ui;
    int tipo;
signals:
    void OK(QString nome,int tipo);
private slots:
    void on_rbImpasti_toggled(bool checked);
    void on_rbRipieni_toggled(bool checked);
    void on_rbProdotti_toggled(bool checked);
    void on_pbAbort_clicked();
    void on_pbOK_clicked();
};

#endif // HNEWRECIPE_H
