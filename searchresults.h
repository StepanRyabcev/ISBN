#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class SearchResults;
}

class SearchResults : public QDialog
{
    Q_OBJECT

public:
    explicit SearchResults(QStandardItemModel *pointer = nullptr, QWidget *parent = nullptr);
    ~SearchResults();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchResults *ui;
};

#endif // SEARCHRESULTS_H
