#include "OptimizationAlgorithm.h"

OptimizationAlgorithm::OptimizationAlgorithm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OptimizationAlgorithmClass()){
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/icon3.ico"));
    setFixedSize(QSize(1024, 800));
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(currentIndexClicked()));
}


OptimizationAlgorithm::~OptimizationAlgorithm(){
    delete ui;
}


void OptimizationAlgorithm::currentIndexClicked() {
    QString currenText = ui->comboBox->currentText();
    algorithmDialog = new AlgorithmDialog();
    algorithmDialog->setWindowTitle(currenText);
    algorithmDialog->setWidgetName(currenText);
    algorithmDialog->show();
}