/********************************************************************************
** Form generated from reading UI file 'OptimizationAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIMIZATIONALGORITHM_H
#define UI_OPTIMIZATIONALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptimizationAlgorithmClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QComboBox *comboBox;
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OptimizationAlgorithmClass)
    {
        if (OptimizationAlgorithmClass->objectName().isEmpty())
            OptimizationAlgorithmClass->setObjectName(QString::fromUtf8("OptimizationAlgorithmClass"));
        OptimizationAlgorithmClass->resize(479, 400);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        OptimizationAlgorithmClass->setFont(font);
        OptimizationAlgorithmClass->setStyleSheet(QString::fromUtf8("background-image: url(:/image/r1.jpg);\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(OptimizationAlgorithmClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Serif"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border:1px groove gray;\n"
""));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);

        OptimizationAlgorithmClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OptimizationAlgorithmClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OptimizationAlgorithmClass->setStatusBar(statusBar);

        retranslateUi(OptimizationAlgorithmClass);

        QMetaObject::connectSlotsByName(OptimizationAlgorithmClass);
    } // setupUi

    void retranslateUi(QMainWindow *OptimizationAlgorithmClass)
    {
        OptimizationAlgorithmClass->setWindowTitle(QApplication::translate("OptimizationAlgorithmClass", "OptimizationAlgorithm", nullptr));
        comboBox->setItemText(0, QApplication::translate("OptimizationAlgorithmClass", "\344\270\200\347\273\264\346\234\264\347\264\240\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(1, QApplication::translate("OptimizationAlgorithmClass", "\344\272\214\345\210\206\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(2, QApplication::translate("OptimizationAlgorithmClass", "\351\273\204\351\207\221\345\210\206\345\211\262\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(3, QApplication::translate("OptimizationAlgorithmClass", "\347\211\233\351\241\277\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(4, QApplication::translate("OptimizationAlgorithmClass", "\344\270\211\347\202\271\344\272\214\346\254\241\346\217\222\345\200\274\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(5, QApplication::translate("OptimizationAlgorithmClass", "\344\270\244\347\202\271\344\270\211\346\254\241\346\217\222\345\200\274\346\220\234\347\264\242", nullptr));

        label->setText(QApplication::translate("OptimizationAlgorithmClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Serif'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sitka Small'; font-size:11pt;\">\346\220\234\347\264\242\347\256\227\346\263\225</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptimizationAlgorithmClass: public Ui_OptimizationAlgorithmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIMIZATIONALGORITHM_H
