/********************************************************************************
** Form generated from reading UI file 'hmodifylot.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HMODIFYLOT_H
#define UI_HMODIFYLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HModifyLot
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *leLot;
    QLabel *label_3;
    QLineEdit *leProd;
    QLabel *label_5;
    QLineEdit *leGiac;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *cbUm;
    QGridLayout *gridLayout;
    QDateEdit *deScad;
    QLabel *label_4;
    QCheckBox *cbScad;
    QCheckBox *cbAttivo;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QComboBox *cbAnag;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *leLotFornitore;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *leEan;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QComboBox *cbtipo;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *leBolla;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QPlainTextEdit *ptNote;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pbComposizione;
    QPushButton *pbLotOperations;
    QPushButton *pbClose;

    void setupUi(QWidget *HModifyLot)
    {
        if (HModifyLot->objectName().isEmpty())
            HModifyLot->setObjectName(QStringLiteral("HModifyLot"));
        HModifyLot->setWindowModality(Qt::ApplicationModal);
        HModifyLot->resize(914, 574);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HModifyLot->sizePolicy().hasHeightForWidth());
        HModifyLot->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Wood-4-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        HModifyLot->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(HModifyLot);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(HModifyLot);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(label);

        leLot = new QLineEdit(HModifyLot);
        leLot->setObjectName(QStringLiteral("leLot"));
        leLot->setMaximumSize(QSize(100, 16777215));
        leLot->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leLot->setReadOnly(true);

        horizontalLayout_3->addWidget(leLot);

        label_3 = new QLabel(HModifyLot);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_3);

        leProd = new QLineEdit(HModifyLot);
        leProd->setObjectName(QStringLiteral("leProd"));
        leProd->setMaximumSize(QSize(16777215, 16777215));
        leProd->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leProd->setReadOnly(true);

        horizontalLayout_3->addWidget(leProd);

        label_5 = new QLabel(HModifyLot);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_5);

        leGiac = new QLineEdit(HModifyLot);
        leGiac->setObjectName(QStringLiteral("leGiac"));
        leGiac->setMaximumSize(QSize(80, 16777215));
        leGiac->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leGiac->setReadOnly(true);

        horizontalLayout_3->addWidget(leGiac);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(HModifyLot);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        cbUm = new QComboBox(HModifyLot);
        cbUm->setObjectName(QStringLiteral("cbUm"));
        cbUm->setEditable(true);
        cbUm->setInsertPolicy(QComboBox::InsertAtBottom);

        formLayout->setWidget(0, QFormLayout::FieldRole, cbUm);


        verticalLayout->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        deScad = new QDateEdit(HModifyLot);
        deScad->setObjectName(QStringLiteral("deScad"));

        gridLayout->addWidget(deScad, 1, 2, 1, 1);

        label_4 = new QLabel(HModifyLot);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        cbScad = new QCheckBox(HModifyLot);
        cbScad->setObjectName(QStringLiteral("cbScad"));

        gridLayout->addWidget(cbScad, 1, 1, 1, 1);

        cbAttivo = new QCheckBox(HModifyLot);
        cbAttivo->setObjectName(QStringLiteral("cbAttivo"));

        gridLayout->addWidget(cbAttivo, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(HModifyLot);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        cbAnag = new QComboBox(HModifyLot);
        cbAnag->setObjectName(QStringLiteral("cbAnag"));
        cbAnag->setEditable(true);
        cbAnag->setInsertPolicy(QComboBox::NoInsert);
        cbAnag->setMinimumContentsLength(30);

        horizontalLayout->addWidget(cbAnag);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(HModifyLot);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        leLotFornitore = new QLineEdit(HModifyLot);
        leLotFornitore->setObjectName(QStringLiteral("leLotFornitore"));

        horizontalLayout_4->addWidget(leLotFornitore);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(HModifyLot);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        leEan = new QLineEdit(HModifyLot);
        leEan->setObjectName(QStringLiteral("leEan"));

        horizontalLayout_5->addWidget(leEan);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(HModifyLot);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        cbtipo = new QComboBox(HModifyLot);
        cbtipo->setObjectName(QStringLiteral("cbtipo"));
        cbtipo->setEditable(true);
        cbtipo->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_6->addWidget(cbtipo);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_10 = new QLabel(HModifyLot);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        leBolla = new QLineEdit(HModifyLot);
        leBolla->setObjectName(QStringLiteral("leBolla"));

        horizontalLayout_7->addWidget(leBolla);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_11 = new QLabel(HModifyLot);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_8->addWidget(label_11);

        ptNote = new QPlainTextEdit(HModifyLot);
        ptNote->setObjectName(QStringLiteral("ptNote"));

        horizontalLayout_8->addWidget(ptNote);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(HModifyLot);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pushButton);

        pbComposizione = new QPushButton(HModifyLot);
        pbComposizione->setObjectName(QStringLiteral("pbComposizione"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Bar-chart64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbComposizione->setIcon(icon2);
        pbComposizione->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbComposizione);

        pbLotOperations = new QPushButton(HModifyLot);
        pbLotOperations->setObjectName(QStringLiteral("pbLotOperations"));
        pbLotOperations->setIcon(icon);
        pbLotOperations->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbLotOperations);

        pbClose = new QPushButton(HModifyLot);
        pbClose->setObjectName(QStringLiteral("pbClose"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon3);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(HModifyLot);

        QMetaObject::connectSlotsByName(HModifyLot);
    } // setupUi

    void retranslateUi(QWidget *HModifyLot)
    {
        HModifyLot->setWindowTitle(QApplication::translate("HModifyLot", "Informazioni su lotto", 0));
        label->setText(QApplication::translate("HModifyLot", "Lotto:", 0));
        label_3->setText(QApplication::translate("HModifyLot", "Prodotto:", 0));
        label_5->setText(QApplication::translate("HModifyLot", "Giacenza:", 0));
        label_2->setText(QApplication::translate("HModifyLot", "Unit\303\240 di misura:", 0));
        label_4->setText(QApplication::translate("HModifyLot", "Scadenza:", 0));
        cbScad->setText(QApplication::translate("HModifyLot", "No scadenza", 0));
        cbAttivo->setText(QApplication::translate("HModifyLot", "Attivo", 0));
        label_6->setText(QApplication::translate("HModifyLot", "Cliente/fornitore:", 0));
        label_7->setText(QApplication::translate("HModifyLot", "lotto Fornitore:", 0));
        label_8->setText(QApplication::translate("HModifyLot", "lotto  di uscita:", 0));
        label_9->setText(QApplication::translate("HModifyLot", "Tipo:", 0));
        label_10->setText(QApplication::translate("HModifyLot", "Bolla:", 0));
        label_11->setText(QApplication::translate("HModifyLot", "Note:", 0));
        pushButton->setText(QApplication::translate("HModifyLot", "Salva", 0));
        pbComposizione->setText(QApplication::translate("HModifyLot", "Dettagli", 0));
        pbLotOperations->setText(QApplication::translate("HModifyLot", "Movimenti Lotto", 0));
        pbClose->setText(QApplication::translate("HModifyLot", "Chiudi", 0));
    } // retranslateUi

};

namespace Ui {
    class HModifyLot: public Ui_HModifyLot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HMODIFYLOT_H
