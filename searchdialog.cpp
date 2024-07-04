#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include "searchresults.h"

SearchDialog::SearchDialog(ISBNBook *pointer, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    bookclass = pointer;
    ui->setupUi(this);
    setWindowTitle("Поиск");
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_cancel_clicked()
{
    reject();
}


void SearchDialog::on_search_clicked()
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
        QStandardItemModel *pointer = bookclass->search(ISBN);
        if (pointer != nullptr)
        {
            SearchResults results(pointer);
            results.exec();
            accept();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Внимание");
            msgBox.setText("Книга с указанным ISBN не была найдена");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
    }
}

