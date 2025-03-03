#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "deletedialog.h"
#include "searchdialog.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ISBN");
    bookclass = new ISBNBook;
    QObject::connect(ui->clear, &QAction::triggered, this, MainWindow::earase);
    QObject::connect(ui->save, &QAction::triggered, this, MainWindow::save);
    QObject::connect(ui->load, &QAction::triggered, this, MainWindow::load);
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

void MainWindow::on_search_clicked()
{
    SearchDialog searchdialog(bookclass);
    searchdialog.exec();
}

void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this, ("Open File"), "/home", ("Binary File(*.bin)"));
    bookclass->savetofile(filename);
}

void MainWindow::load()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Open File"), "/home", ("Binary File(*.bin)"));
    earase();
    bookclass->loadfromfile(fileName);
    on_refresh_clicked();
}

