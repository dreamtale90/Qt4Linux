#include <QtGui>
#include <unistd.h>
#include "BuiltInDialog.h"

BuiltInDialog::BuiltInDialog(QWidget *parent)
	:QDialog(parent)
{
	num = 0;
	textEditDisplay = new QTextEdit();
	filePushButton = new QPushButton("打开");
	colorPushButton = new QPushButton("颜色");
	fontPushButton = new QPushButton("字体");
	inputPushButton = new QPushButton("保存");
	closePushButton = new QPushButton("关闭");

	QVBoxLayout *rightLayout = new QVBoxLayout();
	rightLayout->addWidget(filePushButton);
	rightLayout->addWidget(colorPushButton);
	rightLayout->addWidget(fontPushButton);
	rightLayout->addWidget(inputPushButton);
	rightLayout->addWidget(closePushButton);

	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addWidget(textEditDisplay);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	connect(filePushButton, SIGNAL(clicked()), this, SLOT(slotFile()));
	connect(colorPushButton, SIGNAL(clicked()), this, SLOT(slotColor()));
	connect(fontPushButton, SIGNAL(clicked()), this, SLOT(slotFont()));
	connect(inputPushButton, SIGNAL(clicked()), this, SLOT(slotInput()));
	connect(closePushButton, SIGNAL(clicked()), this, SLOT(close()));

	setWindowTitle("内建对话框");
}

void BuiltInDialog::slotFile()
{
	QString str = QFileDialog::getOpenFileName(this, "open file dialog", "/root", "Text files(*.txt)");
	QFile file(str);

	if(!file.open(QIODevice::ReadWrite))
	{
		return;
	}

	QTextStream in(&file);
	while(!in.atEnd())
	{
		QString line = in.readLine();
		num++;
		textEditDisplay->append(line);
	}
}

void BuiltInDialog::slotColor()
{
	QPalette palette = textEditDisplay->palette();
	QColor color = QColorDialog::getColor(palette.color(QPalette::Text), this);
	if(color.isValid())
	{
		palette.setColor(QPalette::Text, color);
		textEditDisplay->setPalette(palette);
	}
}

void BuiltInDialog::slotFont()
{
	bool ok;
	QFont font = QFontDialog::getFont(&ok);

	if(ok)
	{
		textEditDisplay->setFont(font);
	}
}

void BuiltInDialog::slotInput()
{
	bool ok;
	QString filePath = QInputDialog::getText(this, tr("Input Dialog"), tr(" InputSavePath:"), QLineEdit::Normal, QDir::home().dirName(), &ok);

	if(!ok)
	{
		return;
	}

	QFile file(filePath);
	if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
	{
		return;
	}

	slotProgress();
	QTextStream out(&file);
	QString a = textEditDisplay->toPlainText();
	out << a << endl;
	if(ok && !a.isEmpty())
	{
		//why?
		textEditDisplay->setText(a);
	}
}

void BuiltInDialog::slotProgress()
{
	QProgressDialog *progressDialog = new QProgressDialog(this);
	QFont font("ZYSong18030", 12);
	progressDialog->setFont(font);
	progressDialog->setWindowModality(Qt::WindowModal);
	progressDialog->setMinimumDuration(10);
	progressDialog->setLabelText(tr("Copying......"));
	progressDialog->setCancelButtonText(tr("Cancel"));
	progressDialog->setRange(0, num);

	for(int i = 1; i < num; i++)
	{
		progressDialog->setValue(i);
		qApp->processEvents();
		sleep(1);
		if(progressDialog->wasCanceled())
			return;
	}

	delete progressDialog;
}

