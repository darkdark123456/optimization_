#include "AlgorithmDialog.h"

AlgorithmDialog::AlgorithmDialog(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::AlgorithmDialogClass()) {
	ui->setupUi(this);
	QObject::connect(ui->btnCalculate, SIGNAL(clicked()), this, SLOT(buttonCalculateClicked()));
	QObject::connect(ui->buttonClear, SIGNAL(clicked()), this, SLOT(buttonClearClicked()));
}


AlgorithmDialog::~AlgorithmDialog() {
	delete ui;
}

void AlgorithmDialog::buttonClearClicked() {
	ui->lineEdit->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineTextLeft->clear();
	ui->lineTextRight->clear();
	std::cout << std::endl;
}




void AlgorithmDialog::setWidgetName(QString widgetName) {
	(*this).widgetName = widgetName;
}



void AlgorithmDialog::buttonCalculateClicked() {
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	functionList.clear();
	firstOrderDerivativesList.clear();
	secondOrderDerivativesList.clear();
	QString currentText = ui->lineEdit->text();

	/*先从右至左扫描常数项*/
	size_t index = currentText.toStdString().length() - 1;
	size_t		endElementIndex = index;
	if (index == 0 && (currentText.toStdString()[index] < 46 ||  currentText.toStdString()[index] > 59 && currentText.toStdString()[index]!='x')) {
		QMessageBox::warning(this, "Warnning Widget", "非法字符？");
		return;
	}
	if (currentText.toStdString()[index] > 47 && currentText.toStdString()[index] < 58) {
		size_t		indexCopy = index;
		funcNode	funcNodeElement;
		QString		numberString;
		if (index == 0) {
			funcNodeElement.exponent = 0;
			funcNodeElement.coefficient = currentText.toStdString()[index] - 48;
			functionList.push_front(funcNodeElement);
			for (auto iterator = functionList.begin();iterator != functionList.end();iterator++) {
				std::cout << "系数  " << (*iterator).coefficient << "  " << " 指数  " << (*iterator).exponent << std::endl;
			}
			return;
		}
		else if (index - 1 > 0 && currentText.toStdString()[index - 1] == '/' && (index - 2) >= 0) {
			funcNodeElement.exponent = 0;
			funcNodeElement.coefficient = QString(currentText.toStdString()[index - 2]).toDouble() / QString(currentText.toStdString()[index]).toDouble();
			endElementIndex = index - 2;
			/*此时只输入了一个分数*/
			if (endElementIndex == 0) {  functionList.push_front(funcNodeElement);  return;  }
			/*此时输入了一个带有符号的分数*/
			if (endElementIndex - 1 == 0 && (currentText.toStdString()[endElementIndex-1]=='+' || currentText.toStdString()[endElementIndex]=='-') ){
				int flag = currentText.toStdString()[endElementIndex] == '-' ? -1 : 1;
				funcNodeElement.coefficient *= flag;
				functionList.push_front(funcNodeElement);
				return;
			}
			if (endElementIndex - 1 >0 && (currentText.toStdString()[endElementIndex - 1] == '+' || currentText.toStdString()[endElementIndex - 1] == '-')){
				--endElementIndex;
			}

		}
		else if (index-1 > 0 && currentText.toStdString()[index - 1] == '^') {
			endElementIndex = index;
		}
		else if (index - 1 >= 0 && currentText.toStdString()[index - 1] != '^') {
			size_t indexCopy = index;
			while (indexCopy > 0 && currentText.toStdString()[indexCopy] != '+' && currentText.toStdString()[indexCopy] != '-') {
				--indexCopy;
			}
			/*判断是否扫描到负号*/
			int flag = currentText.toStdString()[indexCopy] == '-' ? -1 : 1;
			
			endElementIndex = indexCopy;
			if (currentText.toStdString()[indexCopy] == '+' || currentText.toStdString()[indexCopy] == '-') {
				++indexCopy;
			}
			while (indexCopy <= index) {
				numberString += QString(currentText.toStdString()[indexCopy++]);
			}
			funcNodeElement.coefficient = numberString.toDouble()*flag;
			funcNodeElement.exponent = 0;
			functionList.push_front(funcNodeElement);
		}

		else{
			QMessageBox::critical(this, "Error Widget", "未知错误");
		}
	}
		

	//std::cout <<"最后一个元素的索引  " << endElementIndex << std::endl;



	for (size_t index = 0; index <= endElementIndex; index++) {
		/*处理系数为小数的情况  从左至右扫描系数为小数的变量的x*/
		if (currentText.toStdString()[index] == '.') {
			//std::cout << "小数点的起始位置" << index << std::endl;
			QString numberString = NULL;
			size_t indexCopy = index - 1;
			int flag = 1;
			while (indexCopy > 0 && currentText.toStdString()[indexCopy] != '+' && currentText.toStdString()[indexCopy] != '-') {
				char beforeChar = currentText.toStdString()[indexCopy];
				numberString += QString(beforeChar);
				--indexCopy;
			}
			/*无符号整型不能小于0，会发生溢出，这里判断==0*/
			if (indexCopy == 0 && currentText.toStdString()[indexCopy]!='+' && currentText.toStdString()[indexCopy]!='-') { 
				numberString += currentText.toStdString()[indexCopy]; 
			}
			if (indexCopy>=0 && currentText.toStdString()[indexCopy] == '+' || currentText.toStdString()[indexCopy] == '-') {
				flag = currentText.toStdString()[indexCopy] == '-' ? -1 : 1;
			}


			/*得到的函数表达式是反序的，通过快速排序的思想将函数表达式正序*/
			std::string numberStringCopy = numberString.toStdString();
			size_t low = 0;
			size_t  high = numberStringCopy.length() - 1;
			while (low < high) {
				std::swap(numberStringCopy[low++], numberStringCopy[high--]);
			}
			numberString = QString::fromStdString(numberStringCopy);
			numberString += QString('.');

			while (currentText.toStdString()[++index] != 'x' && index <= endElementIndex) {
				char postChar = currentText.toStdString()[index];
				numberString += QString(postChar);
			
			}

			if ((index+1) <=endElementIndex && currentText.toStdString()[index + 1] == '^' && (index + 2) <= endElementIndex) {
				funcNode funcNodeElement;
				funcNodeElement.coefficient = numberString.toDouble()*flag;
				funcNodeElement.exponent = QString(currentText.toStdString()[index + 2]).toInt();
				functionList.push_front(funcNodeElement);
			}
			else {
				funcNode funcNodeElement;
				funcNodeElement.coefficient = numberString.toDouble()*flag;
				funcNodeElement.exponent = 1;
				functionList.push_front(funcNodeElement);
			}
		}
		
		///*从左至右扫描系数为分数的变量x，处理系数为分数的情况，转换为小数来处理*/
		else if (currentText.toStdString()[index] == '/') {
			char beforeNumberChar;
			char postNumberChar;
			int flag = 1;
			double coefficient = 0;
			size_t indexCopy = index - 1;
			if (index + 1 > endElementIndex) { QMessageBox::critical(this, "Error", "range out of memory");  return; }


			while (indexCopy>0 && currentText.toStdString()[indexCopy] != '+' && currentText.toStdString()[indexCopy] != '-') {
				--indexCopy;
			}

			if (indexCopy == 0 && currentText.toStdString()[indexCopy] == '+' || currentText.toStdString()[indexCopy] == '-') {
				flag = currentText.toStdString()[indexCopy] == '-' ? -1 : 1;
				++indexCopy;
			}

			beforeNumberChar = currentText.toStdString()[indexCopy];
			postNumberChar = currentText.toStdString()[indexCopy+2];
			if (QString(postNumberChar).toDouble() == 0) { QMessageBox::critical(this, "错误", "分母不能为0");  return; }
			coefficient = QString(beforeNumberChar).toDouble() / QString(postNumberChar).toDouble();
			while (currentText.toStdString()[++index] != 'x') {}
			if ((index+1) <= endElementIndex && currentText.toStdString()[index+1] == '^' && index + 2 <= endElementIndex) {
				funcNode funcNodeElement;
				funcNodeElement.coefficient = coefficient*flag;
				funcNodeElement.exponent = QString(currentText.toStdString()[index + 2]).toInt();
				functionList.push_front(funcNodeElement);
			}
			else {
				funcNode funcNodeElement;
				funcNodeElement.coefficient = coefficient*flag;
				funcNodeElement.exponent = 1;
				functionList.push_front(funcNodeElement);
			}
		}

			/*从左至右扫描含有系数为整数的变量x*/
		else if (currentText.toStdString()[index] == 'x') {
			funcNode funcNodeElement;
			QString numberString;
			
			if (index == 0) {
				funcNodeElement.coefficient = 1;
			}
			else if (index - 1 == 0) {
				funcNodeElement.coefficient = QString(currentText.toStdString()[index - 1]).toDouble();
			}

			else if ((index - 1) >0 && currentText.toStdString()[index - 1] != '+') {
				size_t indexCopy = index - 1;

				while (indexCopy > 0 && currentText.toStdString()[indexCopy] != '+' && currentText.toStdString()[indexCopy] != '-') {
					--indexCopy;
				}
				if (currentText.toStdString()[indexCopy] == '+') { ++indexCopy; }
				while (indexCopy < index) {
					numberString += QString(currentText.toStdString()[indexCopy]);
					++indexCopy;
				}
				funcNodeElement.coefficient = numberString.toDouble();
			}
			else{
				/*QMessageBox::warning(this, " ", "非法字符");*/
			}
			
			if ((index+1 <= endElementIndex) && (index + 2) <= endElementIndex && currentText.toStdString()[index + 1] == '^') {
				funcNodeElement.exponent = QString(currentText.toStdString()[index + 2]).toInt();
				functionList.push_front(funcNodeElement);
			}
			else {
				funcNodeElement.exponent = 1;
				functionList.push_front(funcNodeElement);
			}
		}
		else{

		}
	}


	for (auto iterator = functionList.begin();iterator != functionList.end();iterator++) {
		//std::cout <<"系数 " << iterator->coefficient <<"指数 " << iterator->exponent << std::endl;
	}

	for (auto iterator = functionList.begin();iterator != functionList.end();iterator++) {
		if (iterator->coefficient == 0 || iterator->exponent < 0) {
			QMessageBox::critical(this, "Error Widget", "数据格式错误");
		}
	}

	/*遍历forward_list 通过指数对其求导,在计算前严格检查每个元素的类型 指数为整型 将每个元素分配到一个新的forward_list中*/
	
	for (auto  iterator = functionList.begin(); iterator!= functionList.end();iterator++){
		if (iterator->coefficient == 0) { continue; }
		funcNode derivativesNode;
		derivativesNode.exponent = iterator->exponent - 1;
		derivativesNode.coefficient = iterator->exponent * iterator->coefficient;
		if (derivativesNode.exponent < 0 || derivativesNode.coefficient == 0) { continue; }
		firstOrderDerivativesList.push_front(derivativesNode);
	}

	QString derivativesString ;
	for (auto iterator =firstOrderDerivativesList.begin();iterator!=firstOrderDerivativesList.end(); iterator++){
		if (iterator->coefficient > 0) {
			derivativesString += QString("+")+getDerivativesString(iterator->coefficient, iterator->exponent);
		}
		else{
			derivativesString += getDerivativesString(iterator->coefficient, iterator->exponent);
		}
	}
	std::string derivativesStringCopy = derivativesString.toStdString();
	derivativesStringCopy.erase(derivativesStringCopy.begin());
	ui->lineEdit_2->setText(QString::fromStdString(derivativesStringCopy));

	firstOrderDerivativesList.reverse();
	for (auto iterator = firstOrderDerivativesList.begin();iterator != firstOrderDerivativesList.end();iterator++) {
		if (iterator->coefficient == 0) { continue; }
		funcNode derivativeNode;
		derivativeNode.exponent = iterator->exponent - 1;
		derivativeNode.coefficient = iterator->exponent * iterator->coefficient;
		if (derivativeNode.exponent < 0 || derivativeNode.coefficient == 0) { continue; }
		secondOrderDerivativesList.push_front(derivativeNode);
	}
	

	QString secondOrderDerivativesString ;
	for (auto iterator=secondOrderDerivativesList.begin(); iterator !=secondOrderDerivativesList.end(); iterator++){
		if (iterator->coefficient > 0) {
			secondOrderDerivativesString +=QString("+")+getDerivativesString(iterator->coefficient, iterator->exponent);
		}
		else{
			secondOrderDerivativesString += getDerivativesString(iterator->coefficient, iterator->exponent);
		}
		
	}
	std::string secondOrderDerivativesStringCopy = secondOrderDerivativesString.toStdString();
	secondOrderDerivativesStringCopy.erase(secondOrderDerivativesStringCopy.begin());
	ui->lineEdit_3->setText(QString::fromStdString(secondOrderDerivativesStringCopy));
	

	if (widgetName == "二分搜索") {
		BinarySearch();
	}
	else if(widgetName=="黄金分割搜索"){
		goldenSectionSearch();
	}
	else if (widgetName=="牛顿搜索") {
		newtonSearch();
	}
	else if (widgetName == "一维朴素搜索") {
		ordernarySearch();
	}

	else if(widgetName=="三点二次插值搜索"){
		firstInterpolationSearch();
	}
	else if (widgetName == "两点三次插值搜索") {
		secondInterpolationSearch();
	}
	/*预留的其他搜索的接口*/
	else{

	}

	functionList.clear();
	firstOrderDerivativesList.clear();
	secondOrderDerivativesList.clear();

	return;
	
}


QString AlgorithmDialog::getDerivativesString(const float& coefficient, const int&exponent) {
	if (coefficient == 1 && exponent == 1) {
		return QString('x');
	}
	else if (exponent == 0) {
		return QString::number(coefficient);
	}
	else if (coefficient == 1 && exponent != 1) {
		return QString("x^") + QString::number(exponent);

	}
	else if (coefficient != 1 && exponent == 1) {
		return QString::number(coefficient) + QString('x');
	}
	else {
		return QString::number(coefficient) + QString("x^") + QString::number(exponent);
	}
}


double AlgorithmDialog::getSecondDerivativeValue(const double& value) {
	double sum = 0;
	for each (auto & listNode in secondOrderDerivativesList) {
		if (listNode.exponent != 0) {
			sum += listNode.coefficient * std::pow(value, listNode.exponent);
		}
		else {
			sum += listNode.coefficient;
		}
	}
	return sum;
}



double AlgorithmDialog::getDerivativeValue(const double& value) {
	double sum = 0;
	for each (auto&  listNode in firstOrderDerivativesList){
		if (listNode.exponent != 0) {
			sum += listNode.coefficient*std::pow(value, listNode.exponent);
		}
		else{
			sum += listNode.coefficient;
		}
	}
	return sum;
}


double AlgorithmDialog::getFunctionValue(const double& value) {
	double sum = 0;
	for each  (auto& listNode in functionList){
		if (listNode.exponent != 0) {
			sum += listNode.coefficient * std::pow(value, listNode.exponent);
		}
		else{
			sum += listNode.coefficient;
		}
	}
	return sum;
}




bool AlgorithmDialog::BinarySearch() {
	double accuracy ;
	double a, b, xStar;
	size_t step = 0;
	bool flag = 1;

	//QDialog* binarySearchWidget = new QDialog();
	//binarySearchWidget->setFixedSize(QSize(800, 1080));
	//binarySearchWidget->setStyleSheet(QString("background-image: url(:/image/r1.jpg);border-radius:5px;border:1px groove gray;"));
	//QFormLayout* formLayout = new QFormLayout(binarySearchWidget);
	//formLayout->setAlignment(Qt::AlignRight);
	//binarySearchWidget->setWindowTitle(QString("binarySearch"));
	//QLabel* leftEndPointLabel = new QLabel(tr("左端点"),binarySearchWidget);
	//QLabel* rightEndPointLabel = new QLabel(tr("右端点"), binarySearchWidget);
	//QLineEdit* leftEndPointLineEdit = new QLineEdit(binarySearchWidget);
	//QLineEdit* rightEndPointLineEdit = new QLineEdit(binarySearchWidget);
	//QPlainTextEdit* searchResultTextEdit = new QPlainTextEdit(binarySearchWidget);
	//QFont font("MS Serif",11,75,false);
	//leftEndPointLabel->setFont(font);
	//rightEndPointLabel->setFont(font);
	//leftEndPointLineEdit->setFont(font);
	//rightEndPointLineEdit->setFont(font);
	//searchResultTextEdit->setFont(font);

	//leftEndPointLabel->setGeometry(QRect(100,100,100,50));
	//rightEndPointLabel->setGeometry(QRect(100, 170, 100, 50));
	//leftEndPointLineEdit->setGeometry(QRect(400, 100, 100, 50));
	//rightEndPointLineEdit->setGeometry(QRect(400, 170, 100, 50));
	//searchResultTextEdit->setGeometry(QRect(100,300,600,700));
	//leftEndPointLineEdit->setReadOnly(true);
	//rightEndPointLineEdit->setReadOnly(true);
	//searchResultTextEdit->setReadOnly(true);

	//formLayout->addRow(leftEndPointLabel, leftEndPointLineEdit);
	//formLayout->addRow(rightEndPointLabel, rightEndPointLineEdit);
	//formLayout->addWidget(searchResultTextEdit);
	a = ui->lineTextLeft->text().toDouble();
	b = ui->lineTextRight->text().toDouble();
	accuracy = ui->lineTextAccuracy->text().toDouble();
	//leftEndPointLineEdit->setText(QString::number(a));
   //rightEndPointLineEdit->setText(QString::number(b));
   //searchResultTextEdit->appendPlainText(QString("初始区间  [") + QString::number(a) +QString(",")+QString::number(b)+QString("]"));
	while (true){
		++step;
		if (step >= 1000) { break; }
		std::cout <<step << "  区间  (" << a << "," << b << ")        ";
		if (getDerivativeValue(a) * getDerivativeValue(b) >= 0) {
			QMessageBox::critical(this, "Error Widget", "两端导数同号，二分法无法判断区间上是否存在最小值点!");
			flag = 0;
			break;
		}
		std::cout << "    |b-a|    " << b - a << "         accuracy    " << accuracy << "        ";
		if (fabs(b - a) < accuracy) { xStar = (a + b) / 2; std::cout << "x* " << xStar << std::endl; break; }
		double x0 = (a + b) / 2;
		std::cout << "    mid    " << x0 << std::endl;
		if (getDerivativeValue(x0) == 0) { xStar = x0; break;  }
		if (getDerivativeValue(x0) > 0)  { b = x0;  }
		else							  { a = x0;  }
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "函数的最小值的近似值的横坐标  " <<xStar<< "   近似的极小值   " << getFunctionValue(xStar) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return flag;
}



bool AlgorithmDialog::goldenSectionSearch() {
	double accuracy ;
	double a, b, xStar;
	size_t step = 0;
	bool flag = 1;
	a = ui->lineTextLeft->text().toDouble();
	b = ui->lineTextRight->text().toDouble();
	accuracy = ui->lineTextAccuracy->text().toDouble();
	double x1 = a + 0.382 * (b - a);
	double x2 = a + 0.618 * (b - a);
	xStar = 0;
	std::cout << "初始区间 (" << a << "," << b << ")" << std::endl;
	while (true) {
		++step;
		if (step >= 1000) { break;}
		std::cout << step << "    " << "区间    " << "    (" << a << "," << b << ")    " << "    |b-a|    " << fabs(b - a) << "    accuracy    " << accuracy << std::endl;
		if (fabs(b - a) < accuracy) {
			xStar = (b + a) / 2;
			std::cout << "    x*    " << xStar << std::endl;
			break;
		}
		if (getFunctionValue(x1) > getFunctionValue(x2)) {
			a  = x1;
			x1 = x2;
			x2 = a + 0.618 * (b - a);
		}
		else{
			b  = x2;
			x2 = x1;
			x1 = a+0.382 * (b - a);
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "函数的最小值的近似值的横坐标  " << xStar << "   近似的极小值   " << getFunctionValue(xStar) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return true;
}


bool AlgorithmDialog::newtonSearch() {
	double randomInitPoint = ui->lineEditInitPoint->text().toDouble();
	double accuracy = ui->lineTextAccuracy->text().toDouble();
	double derivativeValue;
	double secondDerivativeValue;
	double xStar;
	size_t step = 0;
	while (true){
		++step;
		if (step >= 1000) {
			break;
		}
		std::cout << step<<"    random point    " << randomInitPoint;
		derivativeValue = getDerivativeValue(randomInitPoint);
		secondDerivativeValue = getSecondDerivativeValue(randomInitPoint);
		if (secondDerivativeValue == 0) {
			break;
			QMessageBox::critical(this, "ErrorWidget", "分母不能为0");
			return false;
		}
		std::cout << "        |f'(x0)|        " << fabs(derivativeValue) << "      accuracy      " << accuracy << std::endl;
		if (fabs(derivativeValue) < accuracy) {
			xStar = randomInitPoint;
			break;
		}
		randomInitPoint = randomInitPoint - (derivativeValue / secondDerivativeValue);
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "函数的最小值的近似值的横坐标  " <<randomInitPoint <<"   近似的极小值   " << getFunctionValue(xStar) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return true;
}


bool AlgorithmDialog::ordernarySearch() {
	std::cout << "正在使用进退法搜索" << std::endl;
	double xStar = 0;
	double x0 = ui->lineEditInitPoint->text().toDouble();/*默认为当前点为最高点*/
	std::cout << "random point " << x0 << std::endl;
	double x1 =0;/*x0,x1,x2 高低高*/
	double x2 = 0;
	size_t step = 0;
	double h = 0.5;
	double beforeFuncValue =getFunctionValue(x0);
	double postFuncValue = 0;
	while (true){
		std::cout << step;
		++step;
		if (step >= 1000) { break; }
		xStar = x0 + h;
		postFuncValue = getFunctionValue(xStar);
		std::cout << "    旧的函数值   " << beforeFuncValue <<"    新的函数值    " <<postFuncValue;
		if (postFuncValue<beforeFuncValue) {
			x1 = x0;/*将舍弃的高点记录*/
			x0 = xStar;/*更新x0*/
			h = 2 * h;/*更新步长*/
			beforeFuncValue = postFuncValue;
		}
		else{
			/*第一步反向*/
			if (step== 1) {
				x1 = xStar;
				h = -h;
			}
			if (step >= 2) {
				x2 = xStar;

				break;
			}
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	if (x1 < x2) { std::cout << "最小值所在的区间为   (" << x1 <<"," << x2 << ")" << std::endl; }
	if (x1 > x2) { std::cout << "最小值所在的区间为   (" << x1 << "," << x2 << ")" << std::endl; }
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return true;
}


double AlgorithmDialog::calculateFirstCoefficient(const double& x1,const  double& x3) {
	if (x1 - x3!=0) {
		return (getFunctionValue(x1) - getFunctionValue(x3)) / (x1 - x3);
	}
	return 0;
}


double AlgorithmDialog::calculateSecondCoefficient(const double& x1, const double& x2, const double& x3) {
	if (x1 - x2 != 0 && x2 - x3 != 0) {
		double numerator = ((getFunctionValue(x1) - getFunctionValue(x2)) / (x1 - x2)) - calculateFirstCoefficient(x1,x3);
		return numerator / (x2 - x3);
	}
	return 0;
}


bool AlgorithmDialog::firstInterpolationSearch() {
	double x1 = ui->lineEditInitPoint->text().toDouble();/*随机点*/
	double accuracy = ui->lineTextAccuracy->text().toDouble();
	double xStar = 0;
	int space = 1;
	size_t step = 0;
	double x2 = x1 + 1;/*随机点+1*/
	double x3 = x1 + 2;/*随机点+2*/
	while (true){
		++step;
		if (step >= 1000) { break; }
		std::cout << step << "  区间    (" << x1 << "," << x3 << ")    "<<"    x2    "<<x2;
		double c1 = calculateFirstCoefficient(x1, x3);
		double c2 = calculateSecondCoefficient(x1, x2, x3);
		xStar = 0.5 * (x1 + x3 - (c1 / c2));
		std::cout << "    |x2-x*|    " << fabs(x2 - xStar) << "    accuracy    " << accuracy << std::endl;
		if (fabs(x2 - xStar) < accuracy) {
			break;
		}
		if (xStar < x2) { x3 = x2;	x2 = xStar;  }
		else            { x1 = x2;	x2 = xStar;  }
	}
	std::cout << "最小值的近似横坐标为   " << xStar <<"    近似的最小值    " <<getFunctionValue(xStar)<<std::endl;
	return true;
}


void AlgorithmDialog::calculateCoefficient(const double& x1,const double& x2,std::vector<double>& coefficientVector) {
	double firstDenominator = pow(x2 - x1, 3);
	double secondDenominator = pow(x2 - x1, 2);
	double firstNumerato = (x2 - x1) * ((getDerivativeValue(x1) + getDerivativeValue(x2))) + 2 * (getFunctionValue(x1) + getFunctionValue(x2));
	double A = firstNumerato / firstDenominator;
	coefficientVector.push_back(A);
	double secondNumerato = 3 * (getFunctionValue(x2) - getFunctionValue(x1)) - (x2 - x1) * (getFunctionValue(x2) + 2 * getFunctionValue(x1));
	double B = secondNumerato / secondDenominator;
	coefficientVector.push_back(B);
	double C = getDerivativeValue(x1);
	double D = getFunctionValue(x1);
	coefficientVector.push_back(C);
	coefficientVector.push_back(D);
}


bool AlgorithmDialog::secondInterpolationSearch() {
	double x1 = ui->lineTextLeft->text().toDouble();
	double x2 = ui->lineTextRight->text().toDouble();
	double xStar = 0;
	double accuracy = ui->lineTextAccuracy->text().toDouble();
	std::vector<double> coefficientVector;
	double firstFuncValue = 0;
	double secondFuncValue = 0;
	double firstDerValue = 0;
	double secondDerValue = 0;
	double xstarDerValue = 0;
	size_t step = 0;
	while (true){
		++step;
		std::cout << step << "    区间    (" << x1 << "," << x2 << ")        " << std::endl;
		if (step >= 1000) { break; }
		firstDerValue = getDerivativeValue(x1);
		secondDerValue = getDerivativeValue(x2);
		if (firstDerValue >= 0 || secondDerValue <= 0) {
			std::cout << "********程序异常结束********" << std::endl;
			break;
		}
		calculateCoefficient(x1, x2, coefficientVector);
		double parmA = coefficientVector[0];
		double parmB = coefficientVector[1];
		double parmC = coefficientVector[2];
		xStar = x1 - (parmC / (parmB + pow(pow(parmB, 2) - 3 * parmA * parmC, 0.5)));
		xstarDerValue = getDerivativeValue(xStar);
		if (fabs(xstarDerValue) <= accuracy) {
			break;
		}
		if (xstarDerValue < 0)  {  x1 = xStar;	 }
		else                    {	x2 = xStar;	 }
		coefficientVector.clear();
	}
	std::cout << "最小值的横坐标的近似值  " << xStar <<"函数值的最小值的近似值 " <<getFunctionValue(xStar)<<std::endl;
	return true;
}