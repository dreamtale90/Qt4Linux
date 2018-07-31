#include <QApplication>
#include <QTextCodec>
#include "mydialog.h"


int main(int argc, char *argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	QApplication app(argc, argv);
	MyDialog mydialog;
	mydialog.show();
	return app.exec();
}
