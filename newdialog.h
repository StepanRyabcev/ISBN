#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include "isbnbook.h"

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(ISBNBook* = nullptr, QWidget *parent = nullptr);
    ~NewDialog();

private slots:
    void on_cancel_clicked();

    void on_add_clicked();

private:
    Ui::NewDialog *ui;
    ISBNBook* bookclass;
};

#endif // NEWDIALOG_H
