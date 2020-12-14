#include "product.h"

double Product::all_total_price = 0;

Product::Product(int row_, QMap<ingredient*, double> ingredients_and_counts)
{
    row = row_;
    Document price_table("prices.xlsx");
    price_table.selectSheet("продукт");
    price_table.load();
    name = price_table.read(row, 1).toString();
    price = price_table.read(row, 2).toDouble();
    ingredients_with_counts = ingredients_and_counts;
}

QString Product::get_name() const {return name;}
double Product::get_price() const {return price;}
double Product::get_total_price() const {return total_price;}

void Product::change_price(double price_)
{
    price = price_;
    Document price_table("prices.xlsx");
    price_table.selectSheet("продукт");
    price_table.load();
    price_table.write(row, 2, price);
    price_table.save();
}

void Product::calculate(int number)
{
    total_price = price*number;
    all_total_price += total_price;
    QMap<ingredient*, double>::const_iterator i = ingredients_with_counts.constBegin();
    while(i != ingredients_with_counts.constEnd())
    {
        ingredients_with_counts[i.key()] = i.value()*number;
        i.key()->take_total_count_for_product(i.value());
        ++i;
    }
    for(int i = 0; i<ingredients_with_counts.size(); ++i)
    {
        total_local_expenses.append(ingredients_with_counts.values().at(i)*ingredients_with_counts.keys().at(i)->get_price());
    }
}



