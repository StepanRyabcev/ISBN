#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    setWindowTitle("Добавить книгу");
}

NewDialog::~NewDialog()
{
    delete ui;
}
