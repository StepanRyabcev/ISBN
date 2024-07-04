#include "isbnbook.h"
#include <QDebug>

ISBNBook::ISBNBook() {}

void ISBNBook::addNew(QString ISBN_in, QString Name_in, QString Creator_in)
{
    BookInfo temp;
    temp.ISBN = ISBN_in; //временно!!! Надо будет сделать функцию
    temp.name = Name_in;
    temp.creator = Creator_in;
    bookvector.push_back(temp);
    qDebug() << "executed";
}
