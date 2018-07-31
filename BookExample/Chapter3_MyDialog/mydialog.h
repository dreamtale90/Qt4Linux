#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class MyDialog : public QDialog
{
	Q_OBJECT
public:
	MyDialog(QWidget *parent = 0);

public slots:
	void slotReset();
	void slotEnsure();

private:
	QLabel *labelID;
	QLabel *labelName;
	QLabel *labelAge;
	QLineEdit *lineEditID;
	QLineEdit *lineEditName;
	QLineEdit *lineEditAge;
};

#endif 	//MYDIALOG_H
