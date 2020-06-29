#include "hnewrecipe.h"
#include "ui_hnewrecipe.h"
#include <QMessageBox>
#include <QDebug>

HNewRecipe::HNewRecipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HNewRecipe)
{
    ui->setupUi(this);
    tipo=2;
}

HNewRecipe::~HNewRecipe()
{
    delete ui;
}

void HNewRecipe::on_rbImpasti_toggled(bool checked)
{
    if(checked)
    {
       tipo=3;
    }
}

void HNewRecipe::on_rbRipieni_toggled(bool checked)
{
    if(checked)
    {
       tipo=4;
    }
}

void HNewRecipe::on_rbProdotti_toggled(bool checked)
{
    if(checked)
    {
        tipo=2;
    }
}

void HNewRecipe::on_pbAbort_clicked()
{
    if (QMessageBox::question(0, QApplication::applicationName(),"Annullare?",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        close();
    }
}

void HNewRecipe::on_pbOK_clicked()
{
    if (QMessageBox::question(0, QApplication::applicationName(),"Verificare i dati. Se Corretti confermere (Ok) se non sicuri annullare (Cancel)",QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
    {
        emit OK(ui->leNomeRicetta->text(),tipo);
        qDebug()<<tipo;
        close();
    }
}

void HNewRecipe::on_rbConfezionamenti_toggled(bool checked)
{
    if(checked)
    {
        tipo=5;
    }
}
