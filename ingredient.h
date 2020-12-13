#ifndef INGREDIENT_H
#define INGREDIENT_H
#include "QString"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "xlsxcellformula.h"
using namespace QXlsx;

class ingredient{
public:
    void change_price(double price_);
    void take_total_count_for_product(double count_){count += count_;}
    double get_price() {return price;}
    QString get_name() {return name;}
    double get_total_count() {return count;}
    double get_local_expense() {
        double local_expense = price*count;
        Total_expense_value += local_expense;
        return local_expense;}
    double get_total_expense() {return Total_expense_value;}
    static double Total_expense_value;

protected:
    ingredient(int row_);
    ingredient(const ingredient&);
    ingredient& operator=(const ingredient&);
    QString name;
    double price;
    double count = 0;
    int row;
};


#endif // INGREDIENT_H
