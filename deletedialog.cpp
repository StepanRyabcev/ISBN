#include "deletedialog.h"
#include "ui_deletedialog.h"
#include <QMessageBox>

Deletedialog::Deletedialog(ISBNBook* pointer, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Deletedialog)
{
    bookclass = pointer;
    ui->setupUi(this);
    setWindowTitle("Удаление");
}

Deletedialog::~Deletedialog()
{
    delete ui;
}

void Deletedialog::on_cancel_clicked()
{
    reject();
}


void Deletedialog::on_delete_2_clicked()
{
    QString ISBN = ui->ISBN->toPlainText();
    if (ISBN.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("ISBN не был указан");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
    else
    {
        bookclass->deleteBook(ISBN);
        accept();
    }
}

