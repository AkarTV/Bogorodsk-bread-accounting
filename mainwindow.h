#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void from_price_dialog(bool ingredient_or_product); //false - ingredient, true - product; element in container

private slots:
    void on_pushButton_clicked();
    void on_change_ignredient_price_but_clicked();

    void on_change_product_price_but_clicked();

signals:
    void make_report(QString filename);
    //void change_item_price(bool ingredient_or_product);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
