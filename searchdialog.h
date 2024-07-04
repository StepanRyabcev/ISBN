#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include "isbnbook.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(ISBNBook *pointer = nullptr, QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_cancel_clicked();

    void on_search_clicked();

private:
    Ui::SearchDialog *ui;
    ISBNBook *bookclass;
};

#endif // SEARCHDIALOG_H
