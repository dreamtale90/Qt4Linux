#include <QtGui>
#include "Messagebox.h"

MessageBox::MessageBox(QWidget *parent)
	: QDialog(parent)
{
	label = new QTextEdit;
	comboBoxMessage = new QComboBox();
	comboBoxMessage->insertItem(0, "询问消息框");
	comboBoxMessage->insertItem(1, "提示消息框");
	comboBoxMessage->insertItem(2, "警告消息框");
	comboBoxMessage->insertItem(3, "致命错误消息框");
	comboBoxMessage->insertItem(4, "关于消息框");
	comboBoxMessage->insertItem(5, "关于Qt消息框");
	comboBoxMessage->insertItem(6, "自定义消息框");

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setMargin(10);
	mainLayout->setSpacing(20);
	mainLayout->addWidget(label);
	mainLayout->addWidget(comboBoxMessage);
	setLayout(mainLayout);

	connect(comboBoxMessage, SIGNAL(activated(int)), this, SLOT(slotMessageBox(int)));

	setWindowTitle("消息框实例");
}

void MessageBox::slotMessageBox(int index)
{
	switch(index)
	{
		case 0:
			Question();
			break;
		case 1:
			Information();
			break;
		case 2:
			Warning();
			break;
		case 3:
			Critical();
			break;
		case 4:
			About();
			break;
		case 5:
			AboutQt();
			break;
		case 6:
			Custom();
			break;
		default:
			break;
	}
}

void MessageBox::Question()
{
	switch(QMessageBox::question(this, "询问消息框", "搜索到文档的末尾，要重新搜索吗？", QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
	{
		case QMessageBox::Ok:
			label->setText(" Question button / Ok ");
			break;
		case QMessageBox::Cancel:
			label->setText(" Question button / Cancel ");
			break;
		default:
			break;
	}
	return;
}

void MessageBox::Information()
{
	QMessageBox::information(this, "提示消息框", "这是一个提示消息框。");
	return;
}

void MessageBox::Warning()
{
	switch(QMessageBox::warning(this, "警告消息框", "保存文件吗？", QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel, QMessageBox::Save))
	{
		case QMessageBox::Save:
			label->setText(" Warning button / Save ");
			break;
		case QMessageBox::Discard:
			label->setText(" Warning button / Discard ");
			break;
		case QMessageBox::Cancel:
			label->setText(" Warning button / Cancel ");
			break;
		default:
			break;
	}
	return;
}

void MessageBox::Critical()
{
	QMessageBox::critical(this, "严重错误消息框", "告诉用户出现了错误。");
	label->setText(" Critical MessageBox ");
	return;
}

void MessageBox::About()
{
	QMessageBox::about(this, "关于消息框", "关于消息框实例。");
	label->setText(" 关于消息框 ");
	return;
}

void MessageBox::AboutQt()
{
	QMessageBox::aboutQt(this, "关于Qt消息框");
	label->setText(" 关于消息框 ");
	return;
}


void MessageBox::Custom()
{
	QMessageBox customMsgBox;
	customMsgBox.setWindowTitle("自定义消息框");
	QPushButton *lockButton = customMsgBox.addButton(tr("Lock"), QMessageBox::ActionRole);
	QPushButton *unlockButton = customMsgBox.addButton(tr("Unlock"), QMessageBox::ActionRole);
	QPushButton *cancelButton = customMsgBox.addButton(QMessageBox::Cancel);
	customMsgBox.setIconPixmap(QPixmap("./images/linuxredhat.png"));
	customMsgBox.setText("这是一个自定义消息框。");
	customMsgBox.exec();

	if(customMsgBox.clickedButton() == lockButton)
		label->setText(" Custom MessageBox / Lock ");
	if(customMsgBox.clickedButton() == unlockButton)
		label->setText(" Custom MessageBox / Unlock ");
	if(customMsgBox.clickedButton() == cancelButton)
		label->setText(" Custom MessageBox / Cancel ");

	return;
}
