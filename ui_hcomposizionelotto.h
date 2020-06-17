/********************************************************************************
** Form generated from reading UI file 'hcomposizionelotto.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HCOMPOSIZIONELOTTO_H
#define UI_HCOMPOSIZIONELOTTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HComposizioneLotto
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leDesc;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbAdd;
    QPushButton *pbRemove;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbPrint;
    QPushButton *pushButton_3;

    void setupUi(QWidget *HComposizioneLotto)
    {
        if (HComposizioneLotto->objectName().isEmpty())
            HComposizioneLotto->setObjectName(QStringLiteral("HComposizioneLotto"));
        HComposizioneLotto->setWindowModality(Qt::WindowModal);
        HComposizioneLotto->resize(1213, 770);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Bar-chart64.png"), QSize(), QIcon::Normal, QIcon::Off);
        HComposizioneLotto->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(HComposizioneLotto);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(HComposizioneLotto);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        leDesc = new QLineEdit(HComposizioneLotto);
        leDesc->setObjectName(QStringLiteral("leDesc"));
        leDesc->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leDesc->setReadOnly(true);

        horizontalLayout_2->addWidget(leDesc);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(HComposizioneLotto);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbAdd = new QPushButton(HComposizioneLotto);
        pbAdd->setObjectName(QStringLiteral("pbAdd"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Download.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbAdd->setIcon(icon1);
        pbAdd->setIconSize(QSize(32, 32));
        pbAdd->setCheckable(false);

        horizontalLayout->addWidget(pbAdd);

        pbRemove = new QPushButton(HComposizioneLotto);
        pbRemove->setObjectName(QStringLiteral("pbRemove"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Upload.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbRemove->setIcon(icon2);
        pbRemove->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbRemove);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbPrint = new QPushButton(HComposizioneLotto);
        pbPrint->setObjectName(QStringLiteral("pbPrint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/Printer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPrint->setIcon(icon3);
        pbPrint->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pbPrint);

        pushButton_3 = new QPushButton(HComposizioneLotto);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Resources/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(HComposizioneLotto);

        QMetaObject::connectSlotsByName(HComposizioneLotto);
    } // setupUi

    void retranslateUi(QWidget *HComposizioneLotto)
    {
        HComposizioneLotto->setWindowTitle(QApplication::translate("HComposizioneLotto", "Dettagli Lotto", 0));
        label->setText(QApplication::translate("HComposizioneLotto", "Lotto:", 0));
        pbAdd->setText(QApplication::translate("HComposizioneLotto", "Aggiungi componente", 0));
        pbRemove->setText(QApplication::translate("HComposizioneLotto", "Rimuovi componente", 0));
        pbPrint->setText(QApplication::translate("HComposizioneLotto", "Stampa", 0));
        pushButton_3->setText(QApplication::translate("HComposizioneLotto", "Chiudi", 0));
    } // retranslateUi

};

namespace Ui {
    class HComposizioneLotto: public Ui_HComposizioneLotto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HCOMPOSIZIONELOTTO_H
