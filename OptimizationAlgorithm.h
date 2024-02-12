#pragma once

#include <QtWidgets/QMainWindow>
#include <qobject.h>
#include <qmessagebox.h>
#include <qicon.h>
#include "ui_OptimizationAlgorithm.h"
#include "AlgorithmDialog.h"






QT_BEGIN_NAMESPACE
namespace Ui { class OptimizationAlgorithmClass; };
QT_END_NAMESPACE

class OptimizationAlgorithm : public QMainWindow
{
    Q_OBJECT

public:
    OptimizationAlgorithm(QWidget *parent = nullptr);
    ~OptimizationAlgorithm();


private slots:
    void currentIndexClicked();
private:
    Ui::OptimizationAlgorithmClass *ui;
    AlgorithmDialog *algorithmDialog;
};
