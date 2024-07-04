#include "newdialog.h"
#include "ui_newdialog.h"

#include <QMessageBox>

NewDialog::NewDialog(ISBNBook* pointer, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    bookclass = pointer;
    setWindowTitle("Добавить книгу");
}

NewDialog::~NewDialog()
{
    delete ui;
}

void NewDialog::on_cancel_clicked()
{
    reject();
}


void NewDialog::on_add_clicked()
{
    QString ISBN, Name, Creator;
    ISBN = ui->ISBN->toPlainText();
    Name = ui->BookName->toPlainText();
    Creator = ui->Creator->toPlainText();
    if (Name.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Название книги не может быть пустым");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
    else
    {
        if (Creator.isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Внимание");
            msgBox.setText("Автор книги должен быть указан");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
        else
        {
            if (ISBN.isEmpty())
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Внимание");
                msgBox.setText("ISBN книги не был указан");
                msgBox.setInformativeText("Вы хотите указать ключ для его генерации или он будет сгенеирирован на основе названия книги");
                msgBox.setIcon(QMessageBox::Question);
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);
                QPushButton *buttonY = qobject_cast<QPushButton *>(msgBox.button(QMessageBox::Yes));
                buttonY->setText("Да");
                QPushButton *buttonN = qobject_cast<QPushButton *>(msgBox.button(QMessageBox::No));
                buttonN->setText("Нет");
                msgBox.setIcon(QMessageBox::Question);
                if (msgBox.exec() == QMessageBox::No)
                {
                    bookclass->addNew(ISBN, Name, Creator);
                    accept();
                }
            }
            else
            {
                bookclass->addNew(ISBN, Name, Creator);
                accept();
            }
        }
    }
}

