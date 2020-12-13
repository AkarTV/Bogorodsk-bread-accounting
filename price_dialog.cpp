#include "price_dialog.h"
#include "ui_price_dialog.h"

Price_dialog::Price_dialog(QWidget *parent, bool one_of_sheets, unsigned row_num_) :
    QDialog(parent), parent(parent),
    ui(new Ui::Price_dialog)
{
    ui->setupUi(this);
    ingredient_or_product = one_of_sheets;
    row_num = row_num_;
    if(one_of_sheets)
        ui->doubleSpinBox->setValue(product_list[row_num]->get_price());
    else
        ui->doubleSpinBox->setValue(ingredient_list[row_num]->get_price());
}

Price_dialog::~Price_dialog()
{
    delete ui;
}

void Price_dialog::on_ok_but_clicked()
{
    double new_value = ui->doubleSpinBox->value();
    if(ingredient_or_product)
    {
        product_list[row_num]->change_price(new_value);
    }
    else
        ingredient_list[row_num]->change_price(new_value);
    connect(this, SIGNAL(to_mainwindow(bool)), parent, SLOT(from_price_dialog(bool)));
    emit(to_mainwindow(ingredient_or_product));
    this->close();
}

void Price_dialog::on_cancel_but_clicked()
{
    this->close();
}
