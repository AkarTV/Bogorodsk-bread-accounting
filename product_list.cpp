#include "product_list.h"

QList<Product*> product_list = {
    new Product(1, QMap<ingredient*, double>{{&flour_vs, 0.198}, {&sault, 0.004}, {&droji, 0.0052}}),
    new Product(2, QMap<ingredient*, double>{{&flour_1s, 0.26}, {&flour_rj, 0.065}, {&flour_vs, 0.042}, {&sault, 0.009}, {&solod, 0.0022}, {&droji, 0.0065}}),
    new Product(3, QMap<ingredient*, double>{{&flour_vs, 0.25}, {&sault, 0.005}, {&sugar, 0.0055}, {&oil, 0.0055}, {&droji, 0.00486}}),
};
