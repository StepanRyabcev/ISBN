#include "searchresults.h"
#include "ui_searchresults.h"
#include <QStandardItemModel>

SearchResults::SearchResults(QStandardItemModel *pointer, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchResults)
{
    ui->setupUi(this);
    ui->table->setModel(pointer);
    setWindowTitle("Результаты поиска");
}

SearchResults::~SearchResults()
{
    delete ui;
}

void SearchResults::on_pushButton_clicked()
{
    accept();
}

