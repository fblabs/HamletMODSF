/********************************************************************************
** Form generated from reading UI file 'hpackview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPACKVIEW_H
#define UI_HPACKVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HPackView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *deDal;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateEdit *deAl;
    QSpacerItem *horizontalSpacer;
    QTableView *tvPacks;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbInfo;
    QPushButton *pbMod;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbClose;

    void setupUi(QWidget *HPackView)
    {
        if (HPackView->objectName().isEmpty())
            HPackView->setObjectName(QStringLiteral("HPackView"));
        HPackView->setWindowModality(Qt::ApplicationModal);
        HPackView->resize(1293, 601);
        verticalLayout = new QVBoxLayout(HPackView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(HPackView);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        deDal = new QDateEdit(HPackView);
        deDal->setObjectName(QStringLiteral("deDal"));
        deDal->setCalendarPopup(true);

        horizontalLayout->addWidget(deDal);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(HPackView);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        deAl = new QDateEdit(HPackView);
        deAl->setObjectName(QStringLiteral("deAl"));
        deAl->setCalendarPopup(true);

        horizontalLayout_2->addWidget(deAl);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);


        horizontalLayout_3->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(45, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        tvPacks = new QTableView(HPackView);
        tvPacks->setObjectName(QStringLiteral("tvPacks"));
        tvPacks->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tvPacks->setAlternatingRowColors(true);
        tvPacks->setSelectionMode(QAbstractItemView::SingleSelection);
        tvPacks->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvPacks->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tvPacks);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pbInfo = new QPushButton(HPackView);
        pbInfo->setObjectName(QStringLiteral("pbInfo"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Wood-4-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbInfo->setIcon(icon);
        pbInfo->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbInfo);

        pbMod = new QPushButton(HPackView);
        pbMod->setObjectName(QStringLiteral("pbMod"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Pencil.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pbMod->setIcon(icon1);
        pbMod->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbMod);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pbClose = new QPushButton(HPackView);
        pbClose->setObjectName(QStringLiteral("pbClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbClose->setIcon(icon2);
        pbClose->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(pbClose);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(HPackView);

        QMetaObject::connectSlotsByName(HPackView);
    } // setupUi

    void retranslateUi(QWidget *HPackView)
    {
        HPackView->setWindowTitle(QApplication::translate("HPackView", "Storico Package", 0));
        label->setText(QApplication::translate("HPackView", "Dal:", 0));
        label_3->setText(QApplication::translate("HPackView", "Al:", 0));
        pbInfo->setText(QApplication::translate("HPackView", "Informazioni su lotto", 0));
        pbMod->setText(QApplication::translate("HPackView", "Modifica Composizione Lotto", 0));
        pbClose->setText(QApplication::translate("HPackView", "Chiudi", 0));
    } // retranslateUi

};

namespace Ui {
    class HPackView: public Ui_HPackView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPACKVIEW_H
