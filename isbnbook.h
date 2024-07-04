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
    void deleteBook(QString);
    void fillWithRandom();

private:
    struct BookInfo
    {
        QString ISBN, name, creator;
    };
    QVector<BookInfo> bookvector;
    QStandardItemModel *tablemodel = nullptr;
    void GenerateISBN(BookInfo&);
};

#endif // ISBNBOOK_H
