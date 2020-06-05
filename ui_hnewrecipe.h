/********************************************************************************
** Form generated from reading UI file 'hnewrecipe.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HNEWRECIPE_H
#define UI_HNEWRECIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HNewRecipe
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbProdotti;
    QRadioButton *rbImpasti;
    QRadioButton *rbRipieni;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *leNomeRicetta;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbOK;
    QPushButton *pbAbort;

    void setupUi(QWidget *HNewRecipe)
    {
        if (HNewRecipe->objectName().isEmpty())
            HNewRecipe->setObjectName(QStringLiteral("HNewRecipe"));
        HNewRecipe->resize(591, 226);
        verticalLayout = new QVBoxLayout(HNewRecipe);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rbProdotti = new QRadioButton(HNewRecipe);
        rbProdotti->setObjectName(QStringLiteral("rbProdotti"));
        rbProdotti->setChecked(true);

        horizontalLayout->addWidget(rbProdotti);

        rbImpasti = new QRadioButton(HNewRecipe);
        rbImpasti->setObjectName(QStringLiteral("rbImpasti"));

        horizontalLayout->addWidget(rbImpasti);

        rbRipieni = new QRadioButton(HNewRecipe);
        rbRipieni->setObjectName(QStringLiteral("rbRipieni"));

        horizontalLayout->addWidget(rbRipieni);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        leNomeRicetta = new QLineEdit(HNewRecipe);
        leNomeRicetta->setObjectName(QStringLiteral("leNomeRicetta"));

        verticalLayout->addWidget(leNomeRicetta);

        verticalSpacer = new QSpacerItem(20, 57, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbOK = new QPushButton(HNewRecipe);
        pbOK->setObjectName(QStringLiteral("pbOK"));

        horizontalLayout_2->addWidget(pbOK);

        pbAbort = new QPushButton(HNewRecipe);
        pbAbort->setObjectName(QStringLiteral("pbAbort"));

        horizontalLayout_2->addWidget(pbAbort);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(HNewRecipe);

        QMetaObject::connectSlotsByName(HNewRecipe);
    } // setupUi

    void retranslateUi(QWidget *HNewRecipe)
    {
        HNewRecipe->setWindowTitle(QApplication::translate("HNewRecipe", "Form", 0));
        rbProdotti->setText(QApplication::translate("HNewRecipe", "Prodotto", 0));
        rbImpasti->setText(QApplication::translate("HNewRecipe", "Impasto", 0));
        rbRipieni->setText(QApplication::translate("HNewRecipe", "Ripieno", 0));
        pbOK->setText(QApplication::translate("HNewRecipe", "Ok", 0));
        pbAbort->setText(QApplication::translate("HNewRecipe", "Annulla", 0));
    } // retranslateUi

};

namespace Ui {
    class HNewRecipe: public Ui_HNewRecipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HNEWRECIPE_H
