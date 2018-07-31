#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::slotEnsure()
{
}

void Dialog::slotReset()
{
    ui->lineEditID->clear();
    ui->lineEditName->clear();
    ui->lineEditAge->clear();
}
