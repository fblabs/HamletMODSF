/********************************************************************************
** Form generated from reading UI file 'hpackages.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPACKAGES_H
#define UI_HPACKAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HPackages
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *cbProdotti;
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QListView *lvEan;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *leLest;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *leQuantLot;
    QLabel *label_6;
    QComboBox *cbQua;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QTextEdit *teNote;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbCrea;
    QPushButton *pbAnnulla;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *rbTutti;
    QRadioButton *rbProdottiFiniti;
    QRadioButton *rbConfezionamenti;
    QTableView *tvLots;
    QFormLayout *formLayout_4;
    QLabel *label_12;
    QLineEdit *leSearchCode;
    QLabel *label_10;
    QLineEdit *leSearch;
    QVBoxLayout *verticalLayout_6;
    QFrame *line;
    QLabel *label_8;
    QLineEdit *leComponente;
    QLabel *label_4;
    QLineEdit *leQuantita;
    QLabel *label_2;
    QLineEdit *leNewLot;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbAddRow;
    QPushButton *pbRemoveRow;
    QTableView *tvPack;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *HPackages)
    {
        if (HPackages->objectName().isEmpty())
            HPackages->setObjectName(QStringLiteral("HPackages"));
        HPackages->setWindowModality(Qt::NonModal);
        HPackages->resize(1257, 832);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Box.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        HPackages->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(HPackages);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(HPackages);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(label);

        cbProdotti = new QComboBox(HPackages);
        cbProdotti->setObjectName(QStringLiteral("cbProdotti"));
        cbProdotti->setEditable(true);
        cbProdotti->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_6->addWidget(cbProdotti);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_11 = new QLabel(HPackages);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(label_11);

        lvEan = new QListView(HPackages);
        lvEan->setObjectName(QStringLiteral("lvEan"));
        lvEan->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(lvEan);


        verticalLayout_4->addLayout(verticalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(HPackages);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_7->addWidget(label_7);

        leLest = new QLineEdit(HPackages);
        leLest->setObjectName(QStringLiteral("leLest"));

        horizontalLayout_7->addWidget(leLest);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, horizontalLayout_7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_9 = new QLabel(HPackages);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        dateEdit = new QDateEdit(HPackages);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout_3->addWidget(dateEdit, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, gridLayout_3);


        verticalLayout_4->addLayout(formLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        leQuantLot = new QLineEdit(HPackages);
        leQuantLot->setObjectName(QStringLiteral("leQuantLot"));
        leQuantLot->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leQuantLot, 0, 1, 1, 1);

        label_6 = new QLabel(HPackages);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        cbQua = new QComboBox(HPackages);
        cbQua->setObjectName(QStringLiteral("cbQua"));
        cbQua->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(cbQua, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_5 = new QLabel(HPackages);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        teNote = new QTextEdit(HPackages);
        teNote->setObjectName(QStringLiteral("teNote"));
        teNote->setMaximumSize(QSize(16777215, 60));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, teNote);


        verticalLayout_4->addLayout(formLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pbCrea = new QPushButton(HPackages);
        pbCrea->setObjectName(QStringLiteral("pbCrea"));
        pbCrea->setIcon(icon);

        horizontalLayout_4->addWidget(pbCrea);

        pbAnnulla = new QPushButton(HPackages);
        pbAnnulla->setObjectName(QStringLiteral("pbAnnulla"));
        pbAnnulla->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Banned-Sign.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbAnnulla->setIcon(icon1);

        horizontalLayout_4->addWidget(pbAnnulla);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(HPackages);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        rbTutti = new QRadioButton(HPackages);
        rbTutti->setObjectName(QStringLiteral("rbTutti"));
        rbTutti->setChecked(true);

        horizontalLayout_3->addWidget(rbTutti);

        rbProdottiFiniti = new QRadioButton(HPackages);
        rbProdottiFiniti->setObjectName(QStringLiteral("rbProdottiFiniti"));
        rbProdottiFiniti->setChecked(false);

        horizontalLayout_3->addWidget(rbProdottiFiniti);

        rbConfezionamenti = new QRadioButton(HPackages);
        rbConfezionamenti->setObjectName(QStringLiteral("rbConfezionamenti"));

        horizontalLayout_3->addWidget(rbConfezionamenti);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tvLots = new QTableView(HPackages);
        tvLots->setObjectName(QStringLiteral("tvLots"));
        tvLots->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tvLots->setAlternatingRowColors(true);
        tvLots->setSelectionMode(QAbstractItemView::SingleSelection);
        tvLots->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvLots->setSortingEnabled(true);
        tvLots->horizontalHeader()->setStretchLastSection(true);
        tvLots->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tvLots);


        verticalLayout_3->addLayout(verticalLayout_2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_12 = new QLabel(HPackages);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_12);

        leSearchCode = new QLineEdit(HPackages);
        leSearchCode->setObjectName(QStringLiteral("leSearchCode"));
        leSearchCode->setMaximumSize(QSize(100, 16777215));
        leSearchCode->setClearButtonEnabled(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, leSearchCode);

        label_10 = new QLabel(HPackages);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_10);

        leSearch = new QLineEdit(HPackages);
        leSearch->setObjectName(QStringLiteral("leSearch"));
        leSearch->setMaximumSize(QSize(1677215, 16777215));
        leSearch->setClearButtonEnabled(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, leSearch);


        verticalLayout_3->addLayout(formLayout_4);


        verticalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        line = new QFrame(HPackages);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        label_8 = new QLabel(HPackages);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);

        leComponente = new QLineEdit(HPackages);
        leComponente->setObjectName(QStringLiteral("leComponente"));
        leComponente->setEnabled(false);

        verticalLayout_6->addWidget(leComponente);

        label_4 = new QLabel(HPackages);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_6->addWidget(label_4);

        leQuantita = new QLineEdit(HPackages);
        leQuantita->setObjectName(QStringLiteral("leQuantita"));
        leQuantita->setEnabled(false);

        verticalLayout_6->addWidget(leQuantita);

        label_2 = new QLabel(HPackages);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        leNewLot = new QLineEdit(HPackages);
        leNewLot->setObjectName(QStringLiteral("leNewLot"));
        QPalette palette;
        QBrush brush(QColor(234, 234, 234, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(236, 233, 216, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        leNewLot->setPalette(palette);
        leNewLot->setReadOnly(false);

        verticalLayout_6->addWidget(leNewLot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbAddRow = new QPushButton(HPackages);
        pbAddRow->setObjectName(QStringLiteral("pbAddRow"));
        pbAddRow->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Plus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbAddRow->setIcon(icon2);

        horizontalLayout_2->addWidget(pbAddRow);

        pbRemoveRow = new QPushButton(HPackages);
        pbRemoveRow->setObjectName(QStringLiteral("pbRemoveRow"));
        pbRemoveRow->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/Minus.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbRemoveRow->setIcon(icon3);

        horizontalLayout_2->addWidget(pbRemoveRow);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_5->addLayout(verticalLayout_7);

        tvPack = new QTableView(HPackages);
        tvPack->setObjectName(QStringLiteral("tvPack"));
        tvPack->setAlternatingRowColors(true);
        tvPack->setSelectionMode(QAbstractItemView::SingleSelection);
        tvPack->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvPack->horizontalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tvPack);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_3 = new QPushButton(HPackages);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Resources/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(HPackages);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Resources/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon5);
        pushButton_4->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_4);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        dateEdit->raise();
        label_9->raise();
        leSearch->raise();
        label_10->raise();
        label_12->raise();
        QWidget::setTabOrder(cbProdotti, lvEan);
        QWidget::setTabOrder(lvEan, leLest);
        QWidget::setTabOrder(leLest, dateEdit);
        QWidget::setTabOrder(dateEdit, leQuantLot);
        QWidget::setTabOrder(leQuantLot, teNote);
        QWidget::setTabOrder(teNote, pbCrea);
        QWidget::setTabOrder(pbCrea, pbAnnulla);
        QWidget::setTabOrder(pbAnnulla, rbTutti);
        QWidget::setTabOrder(rbTutti, rbProdottiFiniti);
        QWidget::setTabOrder(rbProdottiFiniti, rbConfezionamenti);
        QWidget::setTabOrder(rbConfezionamenti, tvLots);
        QWidget::setTabOrder(tvLots, leSearchCode);
        QWidget::setTabOrder(leSearchCode, leSearch);
        QWidget::setTabOrder(leSearch, pbRemoveRow);
        QWidget::setTabOrder(pbRemoveRow, leComponente);
        QWidget::setTabOrder(leComponente, leQuantita);
        QWidget::setTabOrder(leQuantita, leNewLot);
        QWidget::setTabOrder(leNewLot, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, tvPack);

        retranslateUi(HPackages);

        QMetaObject::connectSlotsByName(HPackages);
    } // setupUi

    void retranslateUi(QWidget *HPackages)
    {
        HPackages->setWindowTitle(QApplication::translate("HPackages", "Packages", 0));
        label->setText(QApplication::translate("HPackages", "Prodotto:", 0));
        label_11->setText(QApplication::translate("HPackages", "Lotti nell'anno", 0));
        label_7->setText(QApplication::translate("HPackages", "lotto", 0));
        label_9->setText(QApplication::translate("HPackages", "Scadenza:", 0));
        label_6->setText(QApplication::translate("HPackages", "Quantit\303\240:", 0));
        label_5->setText(QApplication::translate("HPackages", "Note:", 0));
        pbCrea->setText(QApplication::translate("HPackages", "Inizia", 0));
        pbAnnulla->setText(QApplication::translate("HPackages", "Annulla", 0));
        label_3->setText(QApplication::translate("HPackages", "Componenti:", 0));
        rbTutti->setText(QApplication::translate("HPackages", "Tutti", 0));
        rbProdottiFiniti->setText(QApplication::translate("HPackages", "Prodotti finiti", 0));
        rbConfezionamenti->setText(QApplication::translate("HPackages", "Confezionamenti", 0));
        label_12->setText(QApplication::translate("HPackages", "Cerca codice:", 0));
        label_10->setText(QApplication::translate("HPackages", "Cerca prodotto:", 0));
        label_8->setText(QApplication::translate("HPackages", "Lotto:", 0));
        label_4->setText(QApplication::translate("HPackages", "Quantit\303\240:", 0));
        label_2->setText(QApplication::translate("HPackages", "Lotto interno creato:", 0));
        pbAddRow->setText(QApplication::translate("HPackages", "Aggiungi", 0));
        pbRemoveRow->setText(QApplication::translate("HPackages", "Rimuovi", 0));
        pushButton_3->setText(QApplication::translate("HPackages", "Salva", 0));
        pushButton_4->setText(QApplication::translate("HPackages", "Chiudi", 0));
    } // retranslateUi

};

namespace Ui {
    class HPackages: public Ui_HPackages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPACKAGES_H
