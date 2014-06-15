/********************************************************************************
** Form generated from reading UI file 'dialogAjouterCursusTC.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERCURSUSTC_H
#define UI_DIALOGAJOUTERCURSUSTC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_dialogAjouterCursusTC
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *choixCredit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *spinBox_4;
    QLabel *label_4;

    void setupUi(QDialog *dialogAjouterCursusTC)
    {
        if (dialogAjouterCursusTC->objectName().isEmpty())
            dialogAjouterCursusTC->setObjectName(QStringLiteral("dialogAjouterCursusTC"));
        dialogAjouterCursusTC->resize(450, 400);
        buttonBox = new QDialogButtonBox(dialogAjouterCursusTC);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(125, 350, 200, 30));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);
        verticalLayoutWidget = new QWidget(dialogAjouterCursusTC);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 60, 391, 251));
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

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(300, 100));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(300, 100));
        textEdit->setAcceptRichText(false);

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(190, 30));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        choixCredit = new QSpinBox(verticalLayoutWidget);
        choixCredit->setObjectName(QStringLiteral("choixCredit"));
        choixCredit->setMaximumSize(QSize(190, 30));
        choixCredit->setAlignment(Qt::AlignCenter);
        choixCredit->setMinimum(1);
        choixCredit->setMaximum(10);

        horizontalLayout->addWidget(choixCredit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        horizontalLayout_5->addWidget(label_5);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(50);

        horizontalLayout_5->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);

        horizontalLayout_6->addWidget(label_6);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximumSize(QSize(200, 30));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(50);

        horizontalLayout_6->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);

        horizontalLayout_7->addWidget(label_7);

        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(50);

        horizontalLayout_7->addWidget(spinBox_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);

        horizontalLayout_8->addWidget(label_8);

        spinBox_4 = new QSpinBox(verticalLayoutWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setMinimum(1);
        spinBox_4->setMaximum(10);

        horizontalLayout_8->addWidget(spinBox_4);


        verticalLayout->addLayout(horizontalLayout_8);

        label_4 = new QLabel(dialogAjouterCursusTC);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(125, 20, 200, 16));
        label_4->setWordWrap(true);

        retranslateUi(dialogAjouterCursusTC);

        QMetaObject::connectSlotsByName(dialogAjouterCursusTC);
    } // setupUi

    void retranslateUi(QDialog *dialogAjouterCursusTC)
    {
        dialogAjouterCursusTC->setWindowTitle(QApplication::translate("dialogAjouterCursusTC", "Dialog", 0));
        label->setText(QApplication::translate("dialogAjouterCursusTC", "Nom du Cursus", 0));
        label_3->setText(QApplication::translate("dialogAjouterCursusTC", "Description", 0));
        label_2->setText(QApplication::translate("dialogAjouterCursusTC", "Dur\303\251e (en semestre)", 0));
        label_5->setText(QApplication::translate("dialogAjouterCursusTC", "Nombre de credit CS \303\240 valider", 0));
        label_6->setText(QApplication::translate("dialogAjouterCursusTC", "Nombre de credit TM \303\240 valider", 0));
        label_7->setText(QApplication::translate("dialogAjouterCursusTC", "Nombre de credit TSH \303\240 valider", 0));
        label_8->setText(QApplication::translate("dialogAjouterCursusTC", "Credits Libre", 0));
        label_4->setText(QApplication::translate("dialogAjouterCursusTC", "Ajout d'un cursus de type TC / HUTECH", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogAjouterCursusTC: public Ui_dialogAjouterCursusTC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERCURSUSTC_H
