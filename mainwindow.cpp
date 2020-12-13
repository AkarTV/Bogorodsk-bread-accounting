#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFileDialog"
#include "QDate"
#include "QFont"
#include "QFile"

#include "product_list.h"
#include "report_for_day.h"
#include "price_dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->date_label->setText(QDate::currentDate().toString(Qt::SystemLocaleLongDate));
    for(int i = 0; i < ingredient_list.size(); ++i)
    {
        ui->list_of_ingredients->addItem(ingredient_list[i]->get_name() + ": " + QString::number(ingredient_list[i]->get_price()) + " руб");
    }
    for(int i = 0; i < product_list.size(); ++i)
    {
        ui->list_of_products->addItem(product_list[i]->get_name() + ": " + QString::number(product_list[i]->get_price()) + " руб");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file;
    QFileDialog open_file;
    file = open_file.getOpenFileName(0, "Выберите файл", "C:/Users/Tolga/Desktop", "*.xlsx *.xlsm");
    if(file.isNull())
        return;
    else
    {
        report_for_day *report = new report_for_day(this);
        report->setAttribute(Qt::WA_DeleteOnClose);
        connect(this, SIGNAL(make_report(QString)), report, SLOT(make_report(QString)));
        emit make_report(file);
        report->setWindowFlags(Qt::Window);
        //report->showMaximized();
        report->show();
    }
}

void MainWindow::on_change_ignredient_price_but_clicked()
{
    Price_dialog* ingredient_dialog = new Price_dialog(this, false, ui->list_of_ingredients->currentRow());
    ingredient_dialog->setAttribute(Qt::WA_DeleteOnClose);
    ingredient_dialog->show();
}

void MainWindow::on_change_product_price_but_clicked()
{
    Price_dialog* ingredient_dialog = new Price_dialog(this, true, ui->list_of_products->currentRow());
    ingredient_dialog->setAttribute(Qt::WA_DeleteOnClose);
    ingredient_dialog->show();
}

void MainWindow::from_price_dialog(bool ingredient_or_product)
{
    if(ingredient_or_product)
        ui->list_of_products->currentItem()->setText(product_list[ui->list_of_products->currentRow()]->get_name() + ": " + QString::number(product_list[ui->list_of_products->currentRow()]->get_price())  + " руб");
    else
        ui->list_of_ingredients->currentItem()->setText(ingredient_list[ui->list_of_ingredients->currentRow()]->get_name() + ": " + QString::number(ingredient_list[ui->list_of_ingredients->currentRow()]->get_price()) + " руб");
}
