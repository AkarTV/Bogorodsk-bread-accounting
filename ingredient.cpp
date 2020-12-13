#include "ingredient.h"
double ingredient::Total_expense_value = 0;

ingredient::ingredient(int row_)
{
    row = row_;
    Document price_table("prices.xlsx");
    price_table.selectSheet("ингредиент");
    name = price_table.read(row, 1).toString();
    price = price_table.read(row, 2).toDouble();
}

void ingredient::change_price(double price_)
{
    price = price_;
    Document price_table("prices.xlsx");
    price_table.selectSheet("ингредиент");
    price_table.load();
    price_table.write(row, 2, price);
    price_table.save();
}
