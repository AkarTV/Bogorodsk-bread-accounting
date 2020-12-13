#include "report_for_day.h"
#include "ui_report_for_day.h"

#include <QPrinter>
#include <QPrintDialog>
#include "QTextDocument"
#include "QFileDialog"
#include "QDate"
#include "QMessageBox"

#include "product_list.h"

report_for_day::report_for_day(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::report_for_day)
{
    ui->setupUi(this);
    QDate date;
    if(QDate::currentDate().day()<QDate::currentDate().daysInMonth())
        date.setDate(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day()+1);
    else
        date.setDate(QDate::currentDate().year(), QDate::currentDate().month()+1, 1);
    ui->date_label->setText("Расход за " + date.toString(Qt::SystemLocaleLongDate));
    ui->verticalLayout->setAlignment(ui->table_report, Qt::AlignHCenter);
    ui->verticalLayout->setAlignment(ui->general_sum, Qt::AlignHCenter);
    ui->table_report->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->general_sum->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->general_sum->horizontalHeader()->setVisible(true);
    ui->table_report->setColumnCount(3);
    ui->table_report->setHorizontalHeaderLabels(QStringList() <<"Ингредиент" << "Количество" << "Сумма");
    ui->table_report->setRowCount(ingredient_list.size());
}

report_for_day::~report_for_day()
{
    delete ui;
        for(int i = 0; i< product_list.size(); ++i)
        {
            product_list[i]->calculate(0);
        }
        Product::all_total_price = 0;
        ingredient::Total_expense_value = 0;
}

void report_for_day::make_report(QString filename)
{
    Document table(filename);
    if(!table.load())
        QMessageBox::critical(this, "Ошибка!", "Не удалось загрузить таблицу!");
    table.selectSheet("parcing");
    for(int i = 0; i< product_list.size(); ++i)
    {
        product_list[i]->calculate(table.read(i+1,2).toInt());
    }
    for(int i = 0; i < ingredient_list.size(); ++i)
        for(int j = 0; j < 3; ++j)
        {
            if(j==0)
                ui->table_report->setItem(i,j, new QTableWidgetItem(ingredient_list[i]->get_name()));
            if(j==1)
                ui->table_report->setItem(i,j, new QTableWidgetItem(tr("%1 ").arg(ingredient_list[i]->get_total_count(), 0, 'f', 2)));
            if(j==2)
                ui->table_report->setItem(i,j, new QTableWidgetItem(tr("%1 %2").arg(ingredient_list[i]->get_local_expense(), 0, 'f', 2).arg("руб")));
        }
    ui->general_sum->setItem(0,0, new QTableWidgetItem(tr("%1 %2").arg(ingredient::Total_expense_value, 0, 'f', 2).arg(" руб")));
    ui->general_sum->setItem(0,1, new QTableWidgetItem(tr("%1 %2").arg(Product::all_total_price, 0, 'f', 2).arg(" руб")));
    ui->general_sum->setItem(0,2, new QTableWidgetItem(tr("%1 %2").arg(Product::all_total_price - ingredient::Total_expense_value, 0, 'f', 2).arg(" руб")));
}

void report_for_day::on_print_but_clicked()
{
    QPrinter printer;
    QTextDocument doc;

    QString text("<font size=\"8\"><h1 align=\"center\">");
    text.append(ui->date_label->text()).append("</h1></font>");
    text.append("<font size=\"5\"><p><table border =\"1\" cellspacing=\"1\" cellpadding=\"3\"><thead>");
    text.append("<tr>");
    for (int i = 0; i < ui->table_report->columnCount(); ++i) {
        text.append("<th>").append(ui->table_report->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < ui->table_report->rowCount(); ++i) {
        text.append("<tr>");
        for (int j = 0; j < ui->table_report->columnCount(); ++j) {
            QTableWidgetItem *item = ui->table_report->item(i, j);
            if (!item || item->text().isEmpty()) {
                ui->table_report->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(ui->table_report->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table></p></font>");

    text.append("<font size=\"5\"><p><table border =\"1\" cellspacing=\"1\" cellpadding=\"3\"><thead>");
    text.append("<tr>");
    for(int i = 0; i < ui->general_sum->columnCount(); ++i){
        text.append("<th>").append(ui->general_sum->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < ui->general_sum->rowCount(); ++i) {
        text.append("<tr>");
        for (int j = 0; j < ui->general_sum->columnCount(); ++j) {
            QTableWidgetItem *item = ui->general_sum->item(i, j);
            if (!item || item->text().isEmpty()) {
                ui->table_report->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(ui->general_sum->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table></p></font>");
    doc.setHtml(text);

    QPrintDialog print_dialog(&printer, this);
    if(print_dialog.exec() == QDialog::Rejected) return;
    else doc.print(&printer);

}

void report_for_day::on_save_but_clicked()
{
    QString text("<font size=\"8\"><h1 align=\"center\">");
    text.append(ui->date_label->text()).append("</h1></font>");
    text.append("<font size=\"5\"><p><table border =\"1\" cellspacing=\"1\" cellpadding=\"3\"><thead>");
    text.append("<tr>");
    for (int i = 0; i < ui->table_report->columnCount(); ++i) {
        text.append("<th>").append(ui->table_report->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < ui->table_report->rowCount(); ++i) {
        text.append("<tr>");
        for (int j = 0; j < ui->table_report->columnCount(); ++j) {
            QTableWidgetItem *item = ui->table_report->item(i, j);
            if (!item || item->text().isEmpty()) {
                ui->table_report->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(ui->table_report->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table></p></font>");

    text.append("<font size=\"5\"><p><table border =\"1\" cellspacing=\"1\" cellpadding=\"3\"><thead>");
    text.append("<tr>");
    for(int i = 0; i < ui->general_sum->columnCount(); ++i){
        text.append("<th>").append(ui->general_sum->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < ui->general_sum->rowCount(); ++i) {
        text.append("<tr>");
        for (int j = 0; j < ui->general_sum->columnCount(); ++j) {
            QTableWidgetItem *item = ui->general_sum->item(i, j);
            if (!item || item->text().isEmpty()) {
                ui->table_report->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(ui->general_sum->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table></p></font>");
    QPrinter printer;
    QString path = QFileDialog::getSaveFileName(NULL, "Сохранить отчет", ui->date_label->text(), "PDF (*.pdf)");
    if(path.isEmpty()) return;
    printer.setOutputFileName(path);
    QTextDocument doc;
    doc.setHtml(text);
    doc.print(&printer);
}
