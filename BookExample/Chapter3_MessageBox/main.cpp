#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include "Messagebox.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	MessageBox msg;
	msg.show();
	return app.exec();
}
