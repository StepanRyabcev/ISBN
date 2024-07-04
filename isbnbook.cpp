#include "isbnbook.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QRandomGenerator>

ISBNBook::ISBNBook() {}

ISBNBook::~ISBNBook()
{
    if (!tablemodel)
        delete tablemodel;
}

void ISBNBook::addNew(QString ISBN_in, QString Name_in, QString Creator_in)
{
    BookInfo temp;
    temp.ISBN = ISBN_in; //временно!!! Надо будет сделать функцию
    temp.name = Name_in;
    temp.creator = Creator_in;
    GenerateISBN(temp);
    bookvector.push_back(temp);
}

QStandardItemModel* ISBNBook::getTable()
{
    if (!tablemodel)
        delete tablemodel;
    tablemodel = new QStandardItemModel(bookvector.size(), 3);
    for (int i = 0; i < bookvector.size(); i++)
    {
        tablemodel->setItem(i, 0, new QStandardItem(bookvector[i].ISBN));
        tablemodel->setItem(i, 1, new QStandardItem(bookvector[i].name));
        tablemodel->setItem(i, 2, new QStandardItem(bookvector[i].creator));
    }
    tablemodel->setHeaderData(0, Qt::Horizontal, "ISBN");
    tablemodel->setHeaderData(1, Qt::Horizontal, "Название");
    tablemodel->setHeaderData(2, Qt::Horizontal, "Жанр");
    return tablemodel;
}

void ISBNBook::GenerateISBN(BookInfo &bookInf)
{
    qint32 seed = 1;
    if (!bookInf.ISBN.isEmpty())
    {
        for (int i = 0; i < bookInf.ISBN.size(); i++)
        {
            seed = bookInf.ISBN[i].unicode() * seed;
            seed = bookInf.ISBN[i].unicode() + seed;
        }
    }
    else
    {
        QString seedstr = bookInf.name + bookInf.creator;
        for (int i = 0; i < seedstr.size(); i++)
        {
            seed = seedstr[i].unicode() * seed;
            seed = seedstr[i].unicode() + seed;
        }
    }
    QRandomGenerator random(seed);
    bookInf.ISBN = QString::number(random.generate() % 1000) + "-" + QString::number(random.generate() % 1000);

}
