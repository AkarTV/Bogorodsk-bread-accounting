#ifndef PRODUCT_H
#define PRODUCT_H

#include "ingredient_list.h"
#include "QMap"

class Product
{
public:
    Product(int row_, QMap<ingredient*, double> ingredients_and_counts);
    void calculate(int number);
    QString get_name() const;
    double get_price() const;
    double get_total_price() const;
    void change_price(double);
    static double all_total_price;

private:
    QString name;
    double price;
    double total_price;
    int row;
    QMap<ingredient*, double>ingredients_with_counts;
    QList<double>total_local_expenses;
};

#endif // PRODUCT_H
