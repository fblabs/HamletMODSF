/********************************************************************************
** Form generated from reading UI file 'hwarehousedetails.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HWAREHOUSEDETAILS_H
#define UI_HWAREHOUSEDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HWarehouseDetails
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leID;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDateTimeEdit *deData;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *leOperatore;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leProdotto;
    QLabel *label_6;
    QLineEdit *leLotto;
    QLabel *label_10;
    QLineEdit *leGiacenza;
    QLabel *label_11;
    QDateEdit *deScadenza;
    QSplitter *splitter_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *leLotFornitore;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *leEAN;
    QSplitter *splitter_2;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *cbAzione;
    QLineEdit *leQuantita;
    QComboBox *cbUM;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QPlainTextEdit *ptNote;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbSave;
    QPushButton *pbClose;

    void setupUi(QWidget *HWarehouseDetails)
    {
        if (HWarehouseDetails->objectName().isEmpty())
            HWarehouseDetails->setObjectName(QStringLiteral("HWarehouseDetails"));
        HWarehouseDetails->setWindowModality(Qt::ApplicationModal);
        HWarehouseDetails->resize(894, 316);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Monitoring64.png"), QSize(), QIcon::Normal, QIcon::Off);
        HWarehouseDetails->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(HWarehouseDetails);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(HWarehouseDetails);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        leID = new QLineEdit(layoutWidget);
        leID->setObjectName(QStringLiteral("leID"));
        leID->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leID->setReadOnly(true);

        horizontalLayout->addWidget(leID);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        deData = new QDateTimeEdit(layoutWidget1);
        deData->setObjectName(QStringLiteral("deData"));
        deData->setReadOnly(true);
        deData->setCurrentSection(QDateTimeEdit::DaySection);
        deData->setCalendarPopup(true);

        horizontalLayout_4->addWidget(deData);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        leOperatore = new QLineEdit(layoutWidget2);
        leOperatore->setObjectName(QStringLiteral("leOperatore"));
        leOperatore->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leOperatore->setReadOnly(true);

        horizontalLayout_3->addWidget(leOperatore);

        splitter->addWidget(layoutWidget2);

        verticalLayout_2->addWidget(splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(HWarehouseDetails);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leProdotto = new QLineEdit(HWarehouseDetails);
        leProdotto->setObjectName(QStringLiteral("leProdotto"));
        leProdotto->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));

        horizontalLayout_2->addWidget(leProdotto);

        label_6 = new QLabel(HWarehouseDetails);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        leLotto = new QLineEdit(HWarehouseDetails);
        leLotto->setObjectName(QStringLiteral("leLotto"));
        leLotto->setAcceptDrops(false);
        leLotto->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));

        horizontalLayout_2->addWidget(leLotto);

        label_10 = new QLabel(HWarehouseDetails);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        leGiacenza = new QLineEdit(HWarehouseDetails);
        leGiacenza->setObjectName(QStringLiteral("leGiacenza"));
        leGiacenza->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        leGiacenza->setReadOnly(true);

        horizontalLayout_2->addWidget(leGiacenza);

        label_11 = new QLabel(HWarehouseDetails);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        deScadenza = new QDateEdit(HWarehouseDetails);
        deScadenza->setObjectName(QStringLiteral("deScadenza"));
        deScadenza->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        deScadenza->setReadOnly(true);
        deScadenza->setCurrentSection(QDateTimeEdit::MonthSection);

        horizontalLayout_2->addWidget(deScadenza);


        verticalLayout_2->addLayout(horizontalLayout_2);

        splitter_3 = new QSplitter(HWarehouseDetails);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget3 = new QWidget(splitter_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        leLotFornitore = new QLineEdit(layoutWidget3);
        leLotFornitore->setObjectName(QStringLiteral("leLotFornitore"));
        leLotFornitore->setReadOnly(false);

        horizontalLayout_9->addWidget(leLotFornitore);

        splitter_3->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(splitter_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        leEAN = new QLineEdit(layoutWidget4);
        leEAN->setObjectName(QStringLiteral("leEAN"));
        leEAN->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));

        horizontalLayout_10->addWidget(leEAN);

        splitter_3->addWidget(layoutWidget4);

        verticalLayout_2->addWidget(splitter_3);

        splitter_2 = new QSplitter(HWarehouseDetails);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget5 = new QWidget(splitter_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget5);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        cbAzione = new QComboBox(layoutWidget5);
        cbAzione->setObjectName(QStringLiteral("cbAzione"));

        horizontalLayout_6->addWidget(cbAzione);

        leQuantita = new QLineEdit(layoutWidget5);
        leQuantita->setObjectName(QStringLiteral("leQuantita"));

        horizontalLayout_6->addWidget(leQuantita);

        cbUM = new QComboBox(layoutWidget5);
        cbUM->setObjectName(QStringLiteral("cbUM"));

        horizontalLayout_6->addWidget(cbUM);

        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        splitter_2->addWidget(layoutWidget5);

        verticalLayout_2->addWidget(splitter_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(HWarehouseDetails);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        ptNote = new QPlainTextEdit(HWarehouseDetails);
        ptNote->setObjectName(QStringLiteral("ptNote"));
        ptNote->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(ptNote);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pbSave = new QPushButton(HWarehouseDetails);
        pbSave->setObjectName(QStringLiteral("pbSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSave->setIcon(icon1);
        pbSave->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbSave);

        pbClose = new QPushButton(HWarehouseDetails);
        pbClose->setObjectName(QStringLiteral("pbClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(pbClose);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(HWarehouseDetails);

        QMetaObject::connectSlotsByName(HWarehouseDetails);
    } // setupUi

    void retranslateUi(QWidget *HWarehouseDetails)
    {
        HWarehouseDetails->setWindowTitle(QApplication::translate("HWarehouseDetails", "Modifica Operazione", 0));
        label->setText(QApplication::translate("HWarehouseDetails", "ID Operazione:", 0));
        label_3->setText(QApplication::translate("HWarehouseDetails", "Data:", 0));
        deData->setDisplayFormat(QApplication::translate("HWarehouseDetails", "dd/MM/yyyy hh:mm:ss", 0));
        label_4->setText(QApplication::translate("HWarehouseDetails", "Operatore:", 0));
        label_2->setText(QApplication::translate("HWarehouseDetails", "Prodotto:", 0));
        label_6->setText(QApplication::translate("HWarehouseDetails", "Lotto:", 0));
        label_10->setText(QApplication::translate("HWarehouseDetails", "Giacenza:", 0));
        label_11->setText(QApplication::translate("HWarehouseDetails", "Scadenza:", 0));
        label_9->setText(QApplication::translate("HWarehouseDetails", "Lotto Fornitore", 0));
        label_8->setText(QApplication::translate("HWarehouseDetails", "Lotto Esterno", 0));
        label_5->setText(QApplication::translate("HWarehouseDetails", "Azione:", 0));
        label_7->setText(QApplication::translate("HWarehouseDetails", "Note:", 0));
        pbSave->setText(QApplication::translate("HWarehouseDetails", "Salva", 0));
        pbClose->setText(QApplication::translate("HWarehouseDetails", "Chiudi", 0));
    } // retranslateUi

};

namespace Ui {
    class HWarehouseDetails: public Ui_HWarehouseDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HWAREHOUSEDETAILS_H
