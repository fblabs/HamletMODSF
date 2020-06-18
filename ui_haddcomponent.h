/********************************************************************************
** Form generated from reading UI file 'haddcomponent.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HADDCOMPONENT_H
#define UI_HADDCOMPONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HAddComponent
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QRadioButton *rbTutti;
    QRadioButton *rbMateriali;
    QRadioButton *rbProdotti;
    QRadioButton *rbImpasti;
    QRadioButton *rbRipieni;
    QRadioButton *rbConfezioni;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *leCode;
    QLabel *label_3;
    QComboBox *cbProdotto;
    QTableView *tvProdLots;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lequantita;
    QComboBox *cbUm;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbConfirm;
    QPushButton *pbClose;

    void setupUi(QWidget *HAddComponent)
    {
        if (HAddComponent->objectName().isEmpty())
            HAddComponent->setObjectName(QStringLiteral("HAddComponent"));
        HAddComponent->setWindowModality(Qt::ApplicationModal);
        HAddComponent->resize(521, 409);
        verticalLayout = new QVBoxLayout(HAddComponent);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rbTutti = new QRadioButton(HAddComponent);
        rbTutti->setObjectName(QStringLiteral("rbTutti"));
        rbTutti->setChecked(true);

        gridLayout->addWidget(rbTutti, 0, 0, 1, 1);

        rbMateriali = new QRadioButton(HAddComponent);
        rbMateriali->setObjectName(QStringLiteral("rbMateriali"));

        gridLayout->addWidget(rbMateriali, 0, 1, 1, 1);

        rbProdotti = new QRadioButton(HAddComponent);
        rbProdotti->setObjectName(QStringLiteral("rbProdotti"));

        gridLayout->addWidget(rbProdotti, 0, 2, 1, 1);

        rbImpasti = new QRadioButton(HAddComponent);
        rbImpasti->setObjectName(QStringLiteral("rbImpasti"));

        gridLayout->addWidget(rbImpasti, 0, 3, 1, 1);

        rbRipieni = new QRadioButton(HAddComponent);
        rbRipieni->setObjectName(QStringLiteral("rbRipieni"));

        gridLayout->addWidget(rbRipieni, 0, 4, 1, 1);

        rbConfezioni = new QRadioButton(HAddComponent);
        rbConfezioni->setObjectName(QStringLiteral("rbConfezioni"));

        gridLayout->addWidget(rbConfezioni, 0, 5, 1, 1);


        verticalLayout->addLayout(gridLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(HAddComponent);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        leCode = new QLineEdit(HAddComponent);
        leCode->setObjectName(QStringLiteral("leCode"));
        leCode->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, leCode);

        label_3 = new QLabel(HAddComponent);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        cbProdotto = new QComboBox(HAddComponent);
        cbProdotto->setObjectName(QStringLiteral("cbProdotto"));
        cbProdotto->setEditable(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, cbProdotto);


        verticalLayout->addLayout(formLayout);

        tvProdLots = new QTableView(HAddComponent);
        tvProdLots->setObjectName(QStringLiteral("tvProdLots"));
        tvProdLots->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvProdLots->setAlternatingRowColors(true);
        tvProdLots->setSelectionMode(QAbstractItemView::SingleSelection);
        tvProdLots->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvProdLots->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvProdLots);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(HAddComponent);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lequantita = new QLineEdit(HAddComponent);
        lequantita->setObjectName(QStringLiteral("lequantita"));

        horizontalLayout_2->addWidget(lequantita);

        cbUm = new QComboBox(HAddComponent);
        cbUm->setObjectName(QStringLiteral("cbUm"));

        horizontalLayout_2->addWidget(cbUm);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbConfirm = new QPushButton(HAddComponent);
        pbConfirm->setObjectName(QStringLiteral("pbConfirm"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Accept64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbConfirm->setIcon(icon);

        horizontalLayout->addWidget(pbConfirm);

        pbClose = new QPushButton(HAddComponent);
        pbClose->setObjectName(QStringLiteral("pbClose"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon1);

        horizontalLayout->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(HAddComponent);

        QMetaObject::connectSlotsByName(HAddComponent);
    } // setupUi

    void retranslateUi(QWidget *HAddComponent)
    {
        HAddComponent->setWindowTitle(QApplication::translate("HAddComponent", "Aggiungi componente", 0));
        rbTutti->setText(QApplication::translate("HAddComponent", "Tutti", 0));
        rbMateriali->setText(QApplication::translate("HAddComponent", "Materie prime", 0));
        rbProdotti->setText(QApplication::translate("HAddComponent", "Prodotti", 0));
        rbImpasti->setText(QApplication::translate("HAddComponent", "Impasti", 0));
        rbRipieni->setText(QApplication::translate("HAddComponent", "Ripieni", 0));
        rbConfezioni->setText(QApplication::translate("HAddComponent", "Confezionamenti", 0));
        label_2->setText(QApplication::translate("HAddComponent", "Codice:", 0));
        label_3->setText(QApplication::translate("HAddComponent", "Prodotto:", 0));
        label->setText(QApplication::translate("HAddComponent", "Quantit\303\240:", 0));
        pbConfirm->setText(QApplication::translate("HAddComponent", "Conferma", 0));
        pbClose->setText(QApplication::translate("HAddComponent", "Chiudi", 0));
    } // retranslateUi

};

namespace Ui {
    class HAddComponent: public Ui_HAddComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HADDCOMPONENT_H
