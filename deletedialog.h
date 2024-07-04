#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include "isbnbook.h"

namespace Ui {
class Deletedialog;
}

class Deletedialog : public QDialog
{
    Q_OBJECT

public:
    explicit Deletedialog(ISBNBook* = nullptr, QWidget *parent = nullptr);
    ~Deletedialog();

private slots:

    void on_cancel_clicked();

    void on_delete_2_clicked();

private:
    Ui::Deletedialog *ui;
    ISBNBook* bookclass;
};

#endif // DELETEDIALOG_H
