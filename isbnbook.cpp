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
    while (!items.isEmpty())
        delete items.pop();
    if (tablemodel != nullptr)
       delete tablemodel;
    if (searchresult != nullptr)
        delete searchresult;
}

void ISBNBook::addNew(QString ISBN_in, QString Name_in, QString Creator_in)
{
    BookInfo temp;
    temp.ISBN = ISBN_in;
    temp.name = Name_in;
    temp.creator = Creator_in;
    GenerateISBN(temp);
    bool canadd = true;
    for (int i = 0; i < bookvector.size(); i++)
    {
        if (bookvector[i].ISBN == temp.ISBN)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Возникла коллизия");
            msgBox.setText("Книга с ISNB " + temp.ISBN + " уже существует");
            msgBox.setInformativeText("Вы хотите сгенерировать другое чисто ISNB?");
            msgBox.setIcon(QMessageBox::Question);
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            QPushButton *buttonY = qobject_cast<QPushButton *>(msgBox.button(QMessageBox::Yes));
            buttonY->setText("Да");
            QPushButton *buttonN = qobject_cast<QPushButton *>(msgBox.button(QMessageBox::No));
            buttonN->setText("Нет");
            msgBox.setIcon(QMessageBox::Question);
            if (msgBox.exec() == QMessageBox::Yes)
            {
                do
                {
                    temp.ISBN += QString::number(QTime::currentTime().msec());
                    GenerateISBN(temp);
                }while (bookvector[i].ISBN == temp.ISBN);
            }
            else
                canadd = false;
        }
    }
    if (canadd)
        bookvector.push_back(temp);
}

QStandardItemModel* ISBNBook::getTable()
{
    while (!items.isEmpty())
    {
        delete items.pop();
    }
    if (tablemodel != nullptr)
        delete tablemodel;
    tablemodel = new QStandardItemModel(bookvector.size(), 3);
    for (int i = 0; i < bookvector.size(); i++)
    {
        QStandardItem *pntr = new QStandardItem(bookvector[i].ISBN);
        tablemodel->setItem(i, 0, pntr);
        items.push(pntr);
        pntr = new QStandardItem(bookvector[i].name);
        tablemodel->setItem(i, 1, pntr);
        items.push(pntr);
        pntr = new QStandardItem(bookvector[i].creator);
        items.push(pntr);
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
        temp.ISBN = QString::number(random.generate());
        GenerateISBN(temp);
        bookvector.push_back(temp);
    }
}

QStandardItemModel* ISBNBook::search(QString ISBN)
{
    for (int i = 0; i < bookvector.size(); i++)
        if (ISBN == bookvector[i].ISBN)
        {
            if (searchresult != nullptr)
                delete searchresult;
            searchresult = new QStandardItemModel(1, 3);
            QStandardItem *pntr = new QStandardItem(bookvector[i].ISBN);
            items.push(pntr);
            searchresult->setItem(0, 0, pntr);
            pntr = new QStandardItem(bookvector[i].name);
            items.push(pntr);
            searchresult->setItem(0, 1, pntr);
            pntr = new QStandardItem(bookvector[i].creator);
            items.push(pntr);
            searchresult->setItem(0, 2, pntr);
            tablemodel->setHeaderData(0, Qt::Horizontal, "ISBN");
            tablemodel->setHeaderData(1, Qt::Horizontal, "Название");
            tablemodel->setHeaderData(2, Qt::Horizontal, "Автор");
            return searchresult;
        }
    return nullptr;
}
