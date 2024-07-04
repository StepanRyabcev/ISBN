#ifndef ISBNBOOK_H
#define ISBNBOOK_H

#include <QString>
#include <QVector>
#include <QStandardItemModel>
#include <QStack>

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
    void savetofile(QString);
    void loadfromfile(QString);

private:
    struct BookInfo
    {
        QString ISBN, name, creator;
    };
    QVector<BookInfo> bookvector;
    QStandardItemModel *tablemodel = nullptr;
    QStandardItemModel *searchresult = nullptr;
    QStack<QStandardItem*> items;
    void GenerateISBN(BookInfo&);
};

#endif // ISBNBOOK_H
