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
    } // retranslateUi

};

namespace Ui {
    class dialogAjouterUV: public Ui_dialogAjouterUV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERUV_H
