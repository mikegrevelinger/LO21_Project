/********************************************************************************
** Form generated from reading UI file 'dialogAjouterUV.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERUV_H
#define UI_DIALOGAJOUTERUV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogAjouterUV
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *textEditDescription;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *choixCredit;
    QLabel *label_4;
    QComboBox *comboBoxCat;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *comboBoxSemestre;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEditNom_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QTextEdit *textEditDescription_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSpinBox *choixCredit_2;
    QLabel *label_9;
    QComboBox *comboBoxCat_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QComboBox *comboBoxSemestre_2;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *dialogAjouterUV)
    {
        if (dialogAjouterUV->objectName().isEmpty())
            dialogAjouterUV->setObjectName(QStringLiteral("dialogAjouterUV"));
        dialogAjouterUV->resize(450, 250);
        dialogAjouterUV->setMaximumSize(QSize(500, 500));
        buttonBox = new QDialogButtonBox(dialogAjouterUV);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 200, 250, 40));
        buttonBox->setMaximumSize(QSize(250, 50));
        QFont font;
        font.setPointSize(10);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);
        verticalLayoutWidget = new QWidget(dialogAjouterUV);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 391, 159));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(100, 16777215));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        lineEditNom = new QLineEdit(verticalLayoutWidget);
        lineEditNom->setObjectName(QStringLiteral("lineEditNom"));
        lineEditNom->setMaximumSize(QSize(300, 100));

        horizontalLayout_3->addWidget(lineEditNom);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        textEditDescription = new QTextEdit(verticalLayoutWidget);
        textEditDescription->setObjectName(QStringLiteral("textEditDescription"));
        textEditDescription->setMaximumSize(QSize(300, 100));
        textEditDescription->setAcceptRichText(false);

        horizontalLayout_2->addWidget(textEditDescription);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        choixCredit = new QSpinBox(verticalLayoutWidget);
        choixCredit->setObjectName(QStringLiteral("choixCredit"));
        choixCredit->setMaximumSize(QSize(100, 30));
        choixCredit->setAlignment(Qt::AlignCenter);
        choixCredit->setMinimum(1);
        choixCredit->setMaximum(30);

        horizontalLayout->addWidget(choixCredit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        comboBoxCat = new QComboBox(verticalLayoutWidget);
        comboBoxCat->setObjectName(QStringLiteral("comboBoxCat"));
        comboBoxCat->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(comboBoxCat);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        horizontalLayout_4->addWidget(label_5);

        comboBoxSemestre = new QComboBox(verticalLayoutWidget);
        comboBoxSemestre->setObjectName(QStringLiteral("comboBoxSemestre"));

        horizontalLayout_4->addWidget(comboBoxSemestre);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayoutWidget_2 = new QWidget(dialogAjouterUV);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(260, 220, 391, 159));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);

        lineEditNom_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEditNom_2->setObjectName(QStringLiteral("lineEditNom_2"));
        lineEditNom_2->setMaximumSize(QSize(300, 100));

        horizontalLayout_5->addWidget(lineEditNom_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(100, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_7);

        textEditDescription_2 = new QTextEdit(verticalLayoutWidget_2);
        textEditDescription_2->setObjectName(QStringLiteral("textEditDescription_2"));
        textEditDescription_2->setMaximumSize(QSize(300, 100));
        textEditDescription_2->setAcceptRichText(false);

        horizontalLayout_6->addWidget(textEditDescription_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);

        horizontalLayout_7->addWidget(label_8);

        choixCredit_2 = new QSpinBox(verticalLayoutWidget_2);
        choixCredit_2->setObjectName(QStringLiteral("choixCredit_2"));
        choixCredit_2->setMaximumSize(QSize(100, 30));
        choixCredit_2->setAlignment(Qt::AlignCenter);
        choixCredit_2->setMinimum(1);
        choixCredit_2->setMaximum(30);

        horizontalLayout_7->addWidget(choixCredit_2);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_9);

        comboBoxCat_2 = new QComboBox(verticalLayoutWidget_2);
        comboBoxCat_2->setObjectName(QStringLiteral("comboBoxCat_2"));
        comboBoxCat_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(comboBoxCat_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(true);

        horizontalLayout_8->addWidget(label_10);

        comboBoxSemestre_2 = new QComboBox(verticalLayoutWidget_2);
        comboBoxSemestre_2->setObjectName(QStringLiteral("comboBoxSemestre_2"));

        horizontalLayout_8->addWidget(comboBoxSemestre_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        buttonBox_2 = new QDialogButtonBox(dialogAjouterUV);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(330, 400, 250, 40));
        buttonBox_2->setMaximumSize(QSize(250, 50));
        buttonBox_2->setFont(font);
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox_2->setCenterButtons(true);

        retranslateUi(dialogAjouterUV);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogAjouterUV, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogAjouterUV, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogAjouterUV);
    } // setupUi

    void retranslateUi(QDialog *dialogAjouterUV)
    {
        dialogAjouterUV->setWindowTitle(QApplication::translate("dialogAjouterUV", "Dialog", 0));
        label->setText(QApplication::translate("dialogAjouterUV", "Nom de l'UV", 0));
        label_3->setText(QApplication::translate("dialogAjouterUV", "Description", 0));
        label_2->setText(QApplication::translate("dialogAjouterUV", "Nombre de Credits", 0));
        label_4->setText(QApplication::translate("dialogAjouterUV", "Categorie", 0));
        label_5->setText(QApplication::translate("dialogAjouterUV", "Semestre d'enseignement", 0));
        label_6->setText(QApplication::translate("dialogAjouterUV", "Nom de l'UV", 0));
        label_7->setText(QApplication::translate("dialogAjouterUV", "Description", 0));
        label_8->setText(QApplication::translate("dialogAjouterUV", "Nombre de Credits", 0));
        label_9->setText(QApplication::translate("dialogAjouterUV", "Categorie", 0));
        label_10->setText(QApplication::translate("dialogAjouterUV", "Semestre d'enseignement", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogAjouterUV: public Ui_dialogAjouterUV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERUV_H
