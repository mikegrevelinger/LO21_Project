/********************************************************************************
** Form generated from reading UI file 'dialogAjouterDossier.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERDOSSIER_H
#define UI_DIALOGAJOUTERDOSSIER_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogAjouterDossier
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpinBox *spinBox;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QComboBox *comboBox_4;
    QLabel *label_10;
    QSpinBox *spinBox_2;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QSpinBox *spinBox_3;
    QLabel *label_12;
    QSpinBox *spinBox_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QSpinBox *spinBox_6;
    QLabel *label_14;
    QSpinBox *spinBox_4;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QSpinBox *spinBox_7;
    QLabel *label_16;
    QSpinBox *spinBox_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QSpinBox *spinBox_9;
    QLabel *label_18;
    QSpinBox *spinBox_10;

    void setupUi(QDialog *dialogAjouterDossier)
    {
        if (dialogAjouterDossier->objectName().isEmpty())
            dialogAjouterDossier->setObjectName(QStringLiteral("dialogAjouterDossier"));
        dialogAjouterDossier->resize(500, 500);
        buttonBox = new QDialogButtonBox(dialogAjouterDossier);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 450, 200, 30));
        buttonBox->setMaximumSize(QSize(250, 30));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);
        verticalLayoutWidget = new QWidget(dialogAjouterDossier);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 461, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(lineEdit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(90, 20));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(comboBox);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(90, 20));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_3->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_6);

        dateEdit = new QDateEdit(verticalLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(1993, 6, 30));

        horizontalLayout_4->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 110));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 441, 81));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);

        horizontalLayout_5->addWidget(label_7);

        spinBox = new QSpinBox(verticalLayoutWidget_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(2014);
        spinBox->setMaximum(2025);

        horizontalLayout_5->addWidget(spinBox);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_8);

        comboBox_3 = new QComboBox(verticalLayoutWidget_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        horizontalLayout_5->addWidget(comboBox_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_9);

        comboBox_4 = new QComboBox(verticalLayoutWidget_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        horizontalLayout_6->addWidget(comboBox_4);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(true);

        horizontalLayout_6->addWidget(label_10);

        spinBox_2 = new QSpinBox(verticalLayoutWidget_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setMaximum(10);

        horizontalLayout_6->addWidget(spinBox_2);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(verticalLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 110));
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 441, 81));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(true);

        horizontalLayout_7->addWidget(label_11);

        spinBox_3 = new QSpinBox(verticalLayoutWidget_3);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setMinimum(0);
        spinBox_3->setMaximum(100);
        spinBox_3->setValue(0);

        horizontalLayout_7->addWidget(spinBox_3);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_12);

        spinBox_5 = new QSpinBox(verticalLayoutWidget_3);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setMinimum(0);
        spinBox_5->setMaximum(100);

        horizontalLayout_7->addWidget(spinBox_5);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_13);

        spinBox_6 = new QSpinBox(verticalLayoutWidget_3);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setMinimum(0);
        spinBox_6->setMaximum(100);

        horizontalLayout_8->addWidget(spinBox_6);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(true);

        horizontalLayout_8->addWidget(label_14);

        spinBox_4 = new QSpinBox(verticalLayoutWidget_3);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setMaximum(10);

        horizontalLayout_8->addWidget(spinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(verticalLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 110));
        verticalLayoutWidget_4 = new QWidget(groupBox_3);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 441, 81));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_15 = new QLabel(verticalLayoutWidget_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(true);

        horizontalLayout_9->addWidget(label_15);

        spinBox_7 = new QSpinBox(verticalLayoutWidget_4);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setAlignment(Qt::AlignCenter);
        spinBox_7->setMinimum(0);
        spinBox_7->setMaximum(100);
        spinBox_7->setValue(0);

        horizontalLayout_9->addWidget(spinBox_7);

        label_16 = new QLabel(verticalLayoutWidget_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_16);

        spinBox_8 = new QSpinBox(verticalLayoutWidget_4);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setAlignment(Qt::AlignCenter);
        spinBox_8->setMinimum(0);
        spinBox_8->setMaximum(100);

        horizontalLayout_9->addWidget(spinBox_8);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_17 = new QLabel(verticalLayoutWidget_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_17);

        spinBox_9 = new QSpinBox(verticalLayoutWidget_4);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));
        spinBox_9->setAlignment(Qt::AlignCenter);
        spinBox_9->setMinimum(0);
        spinBox_9->setMaximum(100);

        horizontalLayout_10->addWidget(spinBox_9);

        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(true);

        horizontalLayout_10->addWidget(label_18);

        spinBox_10 = new QSpinBox(verticalLayoutWidget_4);
        spinBox_10->setObjectName(QStringLiteral("spinBox_10"));
        spinBox_10->setAlignment(Qt::AlignCenter);
        spinBox_10->setMaximum(10);

        horizontalLayout_10->addWidget(spinBox_10);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(dialogAjouterDossier);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogAjouterDossier, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogAjouterDossier, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogAjouterDossier);
    } // setupUi

    void retranslateUi(QDialog *dialogAjouterDossier)
    {
        dialogAjouterDossier->setWindowTitle(QApplication::translate("dialogAjouterDossier", "Dialog", 0));
        label_2->setText(QApplication::translate("dialogAjouterDossier", "Nom", 0));
        label_4->setText(QApplication::translate("dialogAjouterDossier", "Prenom", 0));
        label->setText(QApplication::translate("dialogAjouterDossier", "Civilit\303\251", 0));
        label_5->setText(QApplication::translate("dialogAjouterDossier", "Nationalite", 0));
        label_6->setText(QApplication::translate("dialogAjouterDossier", "Date de Naissance", 0));
        groupBox->setTitle(QApplication::translate("dialogAjouterDossier", "Actuellement", 0));
        label_7->setText(QApplication::translate("dialogAjouterDossier", "Annee courante", 0));
        label_8->setText(QApplication::translate("dialogAjouterDossier", "Semestre Courant", 0));
        label_9->setText(QApplication::translate("dialogAjouterDossier", "Cursus suivi", 0));
        label_10->setText(QApplication::translate("dialogAjouterDossier", "Semestre dans le cursus", 0));
        groupBox_2->setTitle(QApplication::translate("dialogAjouterDossier", "Equivalence (dont d\303\251part \303\240 l'\303\251tranger d\303\251j\303\240 effectu\303\251)", 0));
        label_11->setText(QApplication::translate("dialogAjouterDossier", "Credit total valid\303\251 (dont libre)", 0));
        label_12->setText(QApplication::translate("dialogAjouterDossier", "Credit CS valid\303\251", 0));
        label_13->setText(QApplication::translate("dialogAjouterDossier", "Credit TM valid\303\251", 0));
        label_14->setText(QApplication::translate("dialogAjouterDossier", "Credit TSH valid\303\251", 0));
        groupBox_3->setTitle(QApplication::translate("dialogAjouterDossier", "Futur d\303\251part \303\240 l'\303\251tranger (pr\303\251vision)", 0));
        label_15->setText(QApplication::translate("dialogAjouterDossier", "Credit total valid\303\251 (dont libre)", 0));
        label_16->setText(QApplication::translate("dialogAjouterDossier", "Credit CS valid\303\251", 0));
        label_17->setText(QApplication::translate("dialogAjouterDossier", "Credit TM valid\303\251", 0));
        label_18->setText(QApplication::translate("dialogAjouterDossier", "Credit TSH valid\303\251", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogAjouterDossier: public Ui_dialogAjouterDossier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERDOSSIER_H
