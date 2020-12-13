#ifndef PRICE_DIALOG_H
#define PRICE_DIALOG_H

#include <QDialog>
#include "product_list.h"

namespace Ui {
class Price_dialog;
}

class Price_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Price_dialog(QWidget *parent = nullptr, bool ignredient_or_product = false, unsigned row_num_ = 0); //если false - открывает список ингредиентов, true - продуктов
    ~Price_dialog();

private slots:
    void on_ok_but_clicked();

    void on_cancel_but_clicked();

signals:
    void to_mainwindow(bool ingredient_or_product); //false - ingredient, true - product
private:
    QWidget* parent;
    Ui::Price_dialog *ui;
    int row_num;
    bool ingredient_or_product;
};

#endif // PRICE_DIALOG_H
