#ifndef REPORT_FOR_DAY_H
#define REPORT_FOR_DAY_H

#include <QDialog>

namespace Ui {
class report_for_day;
}

class report_for_day : public QDialog
{
    Q_OBJECT

public:
    explicit report_for_day(QWidget *parent = nullptr);
    ~report_for_day();

public slots:
    void make_report(QString filename);

private slots:
    void on_print_but_clicked();

    void on_save_but_clicked();

private:
    Ui::report_for_day *ui;
};

#endif // REPORT_FOR_DAY_H
