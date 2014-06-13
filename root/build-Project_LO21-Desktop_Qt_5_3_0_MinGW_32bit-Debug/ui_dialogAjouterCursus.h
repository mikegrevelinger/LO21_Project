/********************************************************************************
** Form generated from reading UI file 'dialogAjouterCursus.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERCURSUS_H
#define UI_DIALOGAJOUTERCURSUS_H

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

class Ui_dialogAjouterCursus
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
    QLabel *label_4;
    QComboBox *comboBox;

    void setupUi(QDialog *dialogAjouterCursus)
    {
        if (dialogAjouterCursus->objectName().isEmpty())
            dialogAjouterCursus->setObjectName(QStringLiteral("dialogAjouterCursus"));
        dialogAjouterCursus->resize(450, 400);
        buttonBox = new QDialogButtonBox(dialogAjouterCursus);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 350, 250, 30));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);
        verticalLayoutWidget = new QWidget(dialogAjouterCursus);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 391, 311));
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
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        choixCredit = new QSpinBox(verticalLayoutWidget);
        choixCredit->setObjectName(QStringLiteral("choixCredit"));
        choixCredit->setMaximumSize(QSize(100, 30));
        choixCredit->setAlignment(Qt::AlignCenter);
        choixCredit->setMinimum(1);
        choixCredit->setMaximum(10);

        horizontalLayout->addWidget(choixCredit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dialogAjouterCursus);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogAjouterCursus, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogAjouterCursus, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialogAjouterCursus);
    } // setupUi

    void retranslateUi(QDialog *dialogAjouterCursus)
    {
        dialogAjouterCursus->setWindowTitle(QApplication::translate("dialogAjouterCursus", "Dialog", 0));
        label->setText(QApplication::translate("dialogAjouterCursus", "Nom du Cursus", 0));
        label_3->setText(QApplication::translate("dialogAjouterCursus", "Description", 0));
        label_2->setText(QApplication::translate("dialogAjouterCursus", "Dur\303\251e (en semestre)", 0));
        label_4->setText(QApplication::translate("dialogAjouterCursus", "Type du cursus", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogAjouterCursus: public Ui_dialogAjouterCursus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERCURSUS_H
