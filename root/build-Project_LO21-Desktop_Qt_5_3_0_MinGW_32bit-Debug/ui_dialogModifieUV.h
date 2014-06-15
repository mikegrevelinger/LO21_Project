/********************************************************************************
** Form generated from reading UI file 'dialogModifieUV.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMODIFIEUV_H
#define UI_DIALOGMODIFIEUV_H

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

class Ui_dialogModifieUV
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLineEdit *nomUV;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QTextEdit *descriUV;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QSpinBox *nbCreditsUV;
    QLabel *label_14;
    QComboBox *catUV;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QComboBox *semestreUV;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogModifieUV)
    {
        if (dialogModifieUV->objectName().isEmpty())
            dialogModifieUV->setObjectName(QStringLiteral("dialogModifieUV"));
        dialogModifieUV->resize(450, 250);
        verticalLayoutWidget = new QWidget(dialogModifieUV);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 391, 159));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(100, 16777215));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_11);

        nomUV = new QLineEdit(verticalLayoutWidget);
        nomUV->setObjectName(QStringLiteral("nomUV"));
        nomUV->setMaximumSize(QSize(300, 100));
        nomUV->setReadOnly(true);

        horizontalLayout_9->addWidget(nomUV);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(100, 16777215));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_12);

        descriUV = new QTextEdit(verticalLayoutWidget);
        descriUV->setObjectName(QStringLiteral("descriUV"));
        descriUV->setMaximumSize(QSize(300, 100));
        descriUV->setAcceptRichText(false);

        horizontalLayout_10->addWidget(descriUV);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(100, 16777215));
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(true);

        horizontalLayout_11->addWidget(label_13);

        nbCreditsUV = new QSpinBox(verticalLayoutWidget);
        nbCreditsUV->setObjectName(QStringLiteral("nbCreditsUV"));
        nbCreditsUV->setMaximumSize(QSize(100, 30));
        nbCreditsUV->setAlignment(Qt::AlignCenter);
        nbCreditsUV->setMinimum(1);
        nbCreditsUV->setMaximum(30);

        horizontalLayout_11->addWidget(nbCreditsUV);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(100, 16777215));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_14);

        catUV = new QComboBox(verticalLayoutWidget);
        catUV->setObjectName(QStringLiteral("catUV"));
        catUV->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_11->addWidget(catUV);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(true);

        horizontalLayout_12->addWidget(label_15);

        semestreUV = new QComboBox(verticalLayoutWidget);
        semestreUV->setObjectName(QStringLiteral("semestreUV"));

        horizontalLayout_12->addWidget(semestreUV);


        verticalLayout_3->addLayout(horizontalLayout_12);

        buttonBox = new QDialogButtonBox(dialogModifieUV);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 190, 250, 40));
        buttonBox->setMaximumSize(QSize(250, 50));
        QFont font;
        font.setPointSize(10);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);

        retranslateUi(dialogModifieUV);

        QMetaObject::connectSlotsByName(dialogModifieUV);
    } // setupUi

    void retranslateUi(QDialog *dialogModifieUV)
    {
        dialogModifieUV->setWindowTitle(QApplication::translate("dialogModifieUV", "Dialog", 0));
        label_11->setText(QApplication::translate("dialogModifieUV", "Nom de l'UV", 0));
        label_12->setText(QApplication::translate("dialogModifieUV", "Description", 0));
        label_13->setText(QApplication::translate("dialogModifieUV", "Nombre de Credits", 0));
        label_14->setText(QApplication::translate("dialogModifieUV", "Categorie", 0));
        label_15->setText(QApplication::translate("dialogModifieUV", "Semestre d'enseignement", 0));
    } // retranslateUi

};

namespace Ui {
    class dialogModifieUV: public Ui_dialogModifieUV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMODIFIEUV_H
