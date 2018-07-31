#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

class QLabel;
class QComboBox;
class QTextEdit;

class MessageBox : public QDialog
{
	Q_OBJECT
public:
	MessageBox(QWidget *parent = 0);
	void Question();
	void Information();
	void Warning();
	void Critical();
	void AboutQt();
	void About();
	void Custom();

public slots:
	void slotMessageBox(int index);

private:
	QTextEdit *label;
	QComboBox *comboBoxMessage;
};
#endif 	//MESSAGEBOX_H
