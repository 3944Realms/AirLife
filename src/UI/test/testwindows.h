//
// Created by f2561 on 24-5-9.
//

#ifndef AIRLIFE_TESTWINDOWS_H
#define AIRLIFE_TESTWINDOWS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class testWindows; }
QT_END_NAMESPACE

class testWindows : public QWidget {
Q_OBJECT

public:
    explicit testWindows(QWidget *parent = nullptr);

    ~testWindows() override;
private slots://声明槽函数
    void on_pushButton_clicked();
private:
    Ui::testWindows *ui;
    QString account_name;
};


#endif //AIRLIFE_TESTWINDOWS_H
