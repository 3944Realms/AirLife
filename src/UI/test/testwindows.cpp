//
// Created by f2561 on 24-5-9.
//
/*
 * 槽函数的声明
 * 网格布局
 * 按钮属性 - 背景颜色（有点类似与CSS） 加载图片
 */
// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_testWindows.h" resolved

#include <QMessageBox>
#include "testwindows.h"
#include "ui_testWindows.h"


testWindows::testWindows(QWidget *parent) :
        QWidget(parent), ui(new Ui::testWindows) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [this]{
        QMessageBox::information(this,"Information","This is a message form testWindow.");
    });
}

testWindows::~testWindows() {
    delete ui;
}

void testWindows::on_pushButton_clicked() {
    account_name += "Clicked PushButton ! ";
    ui->AccountInput->setText(account_name);
}
