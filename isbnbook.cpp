#include "isbnbook.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QTime>

ISBNBook::ISBNBook() {}

ISBNBook::~ISBNBook()
{
    if (tablemodel != nullptr)
       delete tablemodel;
}

void ISBNBook::addNew(QString ISBN_in, QString Name_in, QString Creator_in)
{
    BookInfo temp;
    temp.ISBN = ISBN_in; //временно!!! Надо будет сделать функцию
    temp.name = Name_in;
    temp.creator = Creator_in;
    GenerateISBN(temp);
    bool canadd = true;
    for (int i = 0; i < bookvector.size(); i++)
    {
        if (bookvector[i].ISBN == temp.ISBN)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Внимание");
            msgBox.setText("Книга с ISNB " + temp.ISBN + " уже существует");
            msgBox.setInformativeText("Книга не была добавлена");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
            canadd = false;
        }
    }
    if (canadd)
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
    tablemodel->setHeaderData(2, Qt::Horizontal, "Автор");
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

void ISBNBook::deleteBook(QString ISBN)
{
    int index = -1;
    for (int i = 0; i < bookvector.size(); i++)
        if (bookvector[i].ISBN == ISBN)
        {
            index = i;
            break;
        }
    if (index == -1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Книга с ISBN " + ISBN + " не найдена");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Подтверждение действия");
        msgBox.setText("Вы действительно хотите удалить книгу с ISBN " + ISBN);
        msgBox.setInformativeText("Данное действие отменить нельзя");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        QPushButton *buttonY = qobject_cast<QPushButton *>(msgBox.button(QMessageBox::Yes));
        buttonY->setText("Да");
        QPushButton *buttonN = qobject_cast<QPushButton *>(msgBox.button(QMessageBox::No));
        buttonN->setText("Нет");
        msgBox.setIcon(QMessageBox::Question);
        if (msgBox.exec() == QMessageBox::Yes)
        {
            bookvector.remove(index);
        }
    }
}

void ISBNBook::fillWithRandom()
{
    QRandomGenerator random(QTime::currentTime().msec());
    int numberOfBooks = random.bounded(1, 50);
    BookInfo temp;
    for (int i = 1; i <= numberOfBooks; i++)
    {
        temp.name = "Книга " + QString::number(i);
        temp.creator = "Автор " + QString::number(i);
        GenerateISBN(temp);
        bookvector.push_back(temp);
    }
}
