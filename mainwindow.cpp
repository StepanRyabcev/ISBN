#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ISBN");
    bookclass = new ISBNBook;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddNew_clicked()
{
    NewDialog addnewdialog(bookclass);
    addnewdialog.exec();
}

