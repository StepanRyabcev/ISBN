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
    QStandardItemModel* search(QString);

private:
    struct BookInfo
    {
        QString ISBN, name, creator;
    };
    QVector<BookInfo> bookvector;
    QStandardItemModel *tablemodel = nullptr;
    QStandardItemModel *searchresult = nullptr;
    void GenerateISBN(BookInfo&);
};

#endif // ISBNBOOK_H
