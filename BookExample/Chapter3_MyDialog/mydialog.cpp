#include <QtGui>
#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent)
	:QDialog(parent)
{
	labelID = new QLabel("学号: ");
	lineEditID = new QLineEdit;
	labelName = new QLabel("姓名: ");
	lineEditName = new QLineEdit;
	labelAge = new QLabel("性别: ");
	lineEditAge = new QLineEdit;

	/* 设置网格布局管理器 */
	QGridLayout *grid = new QGridLayout();
	grid->addWidget(labelID, 0, 0, 1, 1);
	grid->addWidget(lineEditID, 0, 1, 1, 3);
	grid->addWidget(labelName, 1, 0, 1, 1);
	grid->addWidget(lineEditName, 1, 1, 1, 3);
	grid->addWidget(labelAge, 2, 0, 1, 1);
	grid->addWidget(lineEditAge, 2, 1, 1, 3);

	/* 设置Button */
	QPushButton *okButton = new QPushButton("确定");
	QPushButton *resetButton = new QPushButton("重置");
	QPushButton *cancelButton = new QPushButton("取消");
	//水平布局管理器
	QHBoxLayout *btnLayout = new QHBoxLayout;
	btnLayout->addWidget(okButton);
	btnLayout->addWidget(resetButton);
	btnLayout->addWidget(cancelButton);

	/* 垂直布局管理器 */
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addLayout(grid);
	layout->addLayout(btnLayout);
	//设置页边空白
	layout->setMargin(40);
	//设置间距
	layout->setSpacing(20);

	/* 设置信号和槽 */
	connect(okButton, SIGNAL(clicked()), this, SLOT(slotEnsure()));
	connect(resetButton, SIGNAL(clicked()), this, SLOT(slotReset()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void MyDialog::slotReset()
{
	lineEditID->clear();
	lineEditName->clear();
	lineEditAge->clear();
}

void MyDialog::slotEnsure()
{
}

