#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName(QTextCodec::codecForLocale()->name()));

	QApplication app(argc, argv);
	MainWindow window;
	window.show();

	return app.exec();
}
