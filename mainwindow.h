#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "isbnbook.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_AddNew_clicked();

    void on_refresh_clicked();

    void on_delete_2_clicked();

    void earase();

    void on_search_clicked();

    void save();

    void load();

private:
    Ui::MainWindow *ui;
    ISBNBook* bookclass;
};
#endif // MAINWINDOW_H
