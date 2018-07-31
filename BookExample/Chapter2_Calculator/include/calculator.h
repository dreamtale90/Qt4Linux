#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class Button;

class Calculator : public QDialog
{
	Q_OBJECT
public:
	Calculator(QWidget *parent=0);

private slots:
	void digitClicked();					//数字按键0~9
	void unaryOperatorClicked();			//单目运算，平方、求根号、倒数
	void additiveOperatorClicked();			//"+", "-"
	void multiplicativeOperatorClicked();	//"x", "/"
	void equalClicked();					//"="
	void pointClicked();					//"."
	void changeSignClicked();				//"+/-"
	void backspaceClicked();				//"Backspace"
	void clear();							//"Clear"
	void clearAll();						//"Clear All"
	void clearMemory();						//"MC"
	void readMemory();						//"MR"
	void setMemory();						//"MS"
	void addToMemory();						//"M+"

private:
	//生成按键函数
	Button *createButton(const QString &text, const char *member);
	//运算错误
	void abortOperation();
	//运算函数（加减乘除）
	bool calculate(double rightOperand, const QString &pendingOperator);
	//MC,MR,MS,M+ 值保存
	double sumInMemory;
	//加法和减法运算值保存
	double sumSoFar;
	//乘法和除法运算值保存
	double factorSoFar;
	//加法和减法运算符合保存
	QString pendingAdditiveOperator;
	//乘法和除法运算符合保存
	QString pendingMultiplicativeOperator;
	//表示状态
	bool waitingForOperand;
	//数字显示框
	QLineEdit *display;

	enum {NumDigitButtons = 10};
	//数字按键0~9
	Button *digitButtons[NumDigitButtons];
};

#endif //CALCULATOR_H
