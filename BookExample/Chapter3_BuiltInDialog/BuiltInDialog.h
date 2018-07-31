#ifndef BUILDINDIALOG_H
#define BUILDINDIALOG_H

#include <QDialog>

class QTextEdit;
class QPushButton;

class BuiltInDialog : public QDialog
{
	Q_OBJECT
public:
	BuiltInDialog(QWidget *parent = 0);

private:
	QTextEdit *textEditDisplay;
	QPushButton *filePushButton;
	QPushButton *colorPushButton;
	QPushButton *fontPushButton;
	QPushButton *inputPushButton;
	QPushButton *closePushButton;
	int num;

private slots:
	void slotFile();
	void slotColor();
	void slotFont();
	void slotInput();
	void slotProgress();
};

#endif 	//BUILDINDIALOG_H
