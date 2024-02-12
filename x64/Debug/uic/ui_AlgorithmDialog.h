/********************************************************************************
** Form generated from reading UI file 'AlgorithmDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALGORITHMDIALOG_H
#define UI_ALGORITHMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlgorithmDialogClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QToolButton *btnCalculate;
    QToolButton *buttonClear;
    QLineEdit *lineEdit_3;
    QLabel *labelLeft;
    QLineEdit *lineTextLeft;
    QLabel *labelRight;
    QLineEdit *lineTextRight;
    QLabel *labelAcc;
    QLineEdit *lineTextAccuracy;
    QLabel *labelInitPoint;
    QLineEdit *lineEditInitPoint;

    void setupUi(QMainWindow *AlgorithmDialogClass)
    {
        if (AlgorithmDialogClass->objectName().isEmpty())
            AlgorithmDialogClass->setObjectName(QString::fromUtf8("AlgorithmDialogClass"));
        AlgorithmDialogClass->resize(487, 400);
        AlgorithmDialogClass->setStyleSheet(QString::fromUtf8("#AlgorithmDialogClass{\n"
"background-image: url(:/image/r1.jpg);\n"
"border-radius:5px;\n"
"border:1px groove gray;\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(AlgorithmDialogClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray"));
        lineEdit->setMaxLength(65536);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset;"));
        lineEdit_2->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        btnCalculate = new QToolButton(centralWidget);
        btnCalculate->setObjectName(QString::fromUtf8("btnCalculate"));
        btnCalculate->setFont(font);
        btnCalculate->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color:blue;\n"
"border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset\n"
"}"));

        formLayout->setWidget(7, QFormLayout::LabelRole, btnCalculate);

        buttonClear = new QToolButton(centralWidget);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setFont(font);
        buttonClear->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"color:blue;\n"
"border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style:outset\n"
"\n"
"}"));

        formLayout->setWidget(7, QFormLayout::FieldRole, buttonClear);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset;"));
        lineEdit_3->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        labelLeft = new QLabel(centralWidget);
        labelLeft->setObjectName(QString::fromUtf8("labelLeft"));
        labelLeft->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelLeft);

        lineTextLeft = new QLineEdit(centralWidget);
        lineTextLeft->setObjectName(QString::fromUtf8("lineTextLeft"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Serif"));
        font1.setPointSize(11);
        lineTextLeft->setFont(font1);
        lineTextLeft->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset;"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineTextLeft);

        labelRight = new QLabel(centralWidget);
        labelRight->setObjectName(QString::fromUtf8("labelRight"));
        labelRight->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelRight);

        lineTextRight = new QLineEdit(centralWidget);
        lineTextRight->setObjectName(QString::fromUtf8("lineTextRight"));
        lineTextRight->setFont(font1);
        lineTextRight->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset;"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineTextRight);

        labelAcc = new QLabel(centralWidget);
        labelAcc->setObjectName(QString::fromUtf8("labelAcc"));
        labelAcc->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, labelAcc);

        lineTextAccuracy = new QLineEdit(centralWidget);
        lineTextAccuracy->setObjectName(QString::fromUtf8("lineTextAccuracy"));
        lineTextAccuracy->setFont(font);
        lineTextAccuracy->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset;"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineTextAccuracy);

        labelInitPoint = new QLabel(centralWidget);
        labelInitPoint->setObjectName(QString::fromUtf8("labelInitPoint"));
        labelInitPoint->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelInitPoint);

        lineEditInitPoint = new QLineEdit(centralWidget);
        lineEditInitPoint->setObjectName(QString::fromUtf8("lineEditInitPoint"));
        lineEditInitPoint->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
"border-style: outset;"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditInitPoint);


        verticalLayout->addLayout(formLayout);

        AlgorithmDialogClass->setCentralWidget(centralWidget);

        retranslateUi(AlgorithmDialogClass);

        QMetaObject::connectSlotsByName(AlgorithmDialogClass);
    } // setupUi

    void retranslateUi(QMainWindow *AlgorithmDialogClass)
    {
        AlgorithmDialogClass->setWindowTitle(QApplication::translate("AlgorithmDialogClass", "AlgorithmDialog", nullptr));
        label->setText(QApplication::translate("AlgorithmDialogClass", "\350\276\223\345\205\245\345\207\275\346\225\260", nullptr));
        label_2->setText(QApplication::translate("AlgorithmDialogClass", "\344\270\200\351\230\266\345\257\274\346\225\260", nullptr));
        label_3->setText(QApplication::translate("AlgorithmDialogClass", "\344\272\214\351\230\266\345\257\274\346\225\260", nullptr));
        btnCalculate->setText(QApplication::translate("AlgorithmDialogClass", "\350\256\241\347\256\227", nullptr));
        buttonClear->setText(QApplication::translate("AlgorithmDialogClass", "\346\270\205\347\251\272", nullptr));
        labelLeft->setText(QApplication::translate("AlgorithmDialogClass", "\350\276\223\345\205\245\345\267\246\347\253\257\347\202\271", nullptr));
        labelRight->setText(QApplication::translate("AlgorithmDialogClass", "\350\276\223\345\205\245\345\217\263\347\253\257\347\202\271", nullptr));
        labelAcc->setText(QApplication::translate("AlgorithmDialogClass", "\347\262\276\345\272\246", nullptr));
        labelInitPoint->setText(QApplication::translate("AlgorithmDialogClass", "\351\232\217\346\234\272\345\210\235\345\247\213\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlgorithmDialogClass: public Ui_AlgorithmDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGORITHMDIALOG_H
