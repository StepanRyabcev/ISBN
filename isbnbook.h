#ifndef ISBNBOOK_H
#define ISBNBOOK_H

#include <QString>
#include <QVector>

class ISBNBook
{
public:
    ISBNBook();
    void addNew(QString, QString, QString);

private:
    struct BookInfo
    {
        QString ISBN, name, creator;
    };
    QVector<BookInfo> bookvector;
};

#endif // ISBNBOOK_H
