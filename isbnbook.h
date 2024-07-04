#ifndef ISBNBOOK_H
#define ISBNBOOK_H

#include <QString>
#include <QVector>
#include <QStandardItemModel>

class ISBNBook
{
public:
    ISBNBook();
    ~ISBNBook();
    void addNew(QString, QString, QString);
    QStandardItemModel* getTable();

private:
    struct BookInfo
    {
        QString ISBN, name, creator;
    };
    QVector<BookInfo> bookvector;
    QStandardItemModel *tablemodel;
};

#endif // ISBNBOOK_H
