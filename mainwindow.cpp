#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "deletedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ISBN");
    bookclass = new ISBNBook;
    QObject::connect(ui->clear, &QAction::triggered, this, MainWindow::earase);
    bookclass->fillWithRandom();
    on_refresh_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bookclass;
}

void MainWindow::on_AddNew_clicked()
{
    NewDialog addnewdialog(bookclass);
    QObject::connect(&addnewdialog, QDialog::accepted, this, MainWindow::on_refresh_clicked);
    addnewdialog.exec();
}

void MainWindow::on_refresh_clicked()
{
    ui->table->setModel(bookclass->getTable());
}


void MainWindow::on_delete_2_clicked()
{
    Deletedialog deldialog(bookclass);
    QObject::connect(&deldialog, QDialog::accepted, this, MainWindow::on_refresh_clicked);
    deldialog.exec();
}

void MainWindow::earase()
{
    delete bookclass;
    bookclass = new ISBNBook;
}
