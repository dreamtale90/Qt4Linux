#include <QApplication>
#include <QTextCodec>
#include "BuiltInDialog.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QApplication app(argc, argv);
    BuiltInDialog dialog;
    dialog.show();

    return app.exec();
}
