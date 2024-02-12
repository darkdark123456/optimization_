#pragma once

#include <QMainWindow>
#include <qmessagebox.h>
#include <forward_list>
#include <iostream>
#include <algorithm>
#include <qformlayout.h>
#include <qplaintextedit.h>
#include <math.h>
#include <vector>
#include "ui_AlgorithmDialog.h"

typedef struct funcNode {
	float coefficient;
	int exponent;
} funcNode;



QT_BEGIN_NAMESPACE
namespace Ui { class AlgorithmDialogClass; };
QT_END_NAMESPACE

class AlgorithmDialog : public QMainWindow
{
	Q_OBJECT

public:
	AlgorithmDialog(QWidget *parent = nullptr);
	~AlgorithmDialog();
private:
	QString getDerivativesString(const float& coeffieient, const int& exponent);
	double getDerivativeValue(const double& value);
	double getSecondDerivativeValue(const double& value);
	double getFunctionValue(const double& value);
	double calculateFirstCoefficient(const double& x1, const double& x3);/*三点二次插值搜索*/
	double calculateSecondCoefficient(const double& x1, const double& x2,const  double& x3);/*三点二次插值搜索*/
	void   calculateCoefficient(const double& x1,const double& x2,std::vector<double>& coefficientVector);
public:
	void setWidgetName(QString widgetName = nullptr);
	bool BinarySearch();/*二分搜索*/
	bool goldenSectionSearch();/*黄金分割法搜索*/
	bool newtonSearch();/*牛顿搜索*/
	bool ordernarySearch();/*进退法搜索*/
	bool firstInterpolationSearch();/*三点两次插值 仅考虑间隔为1的情况*/
	bool secondInterpolationSearch();

private slots:
	void buttonCalculateClicked();
	void buttonClearClicked();
private:
	Ui::AlgorithmDialogClass *ui;
	std::forward_list<funcNode> functionList;/*用一个前向list存放函数的系数和指数*/
	std::forward_list<funcNode> firstOrderDerivativesList;
	std::forward_list<funcNode> secondOrderDerivativesList;
	QString widgetName;
	QDialog* inputEndPonitWidget;
};
