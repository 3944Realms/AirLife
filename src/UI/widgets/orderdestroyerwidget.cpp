//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_orderDestroyerWidget.h" resolved

#include "orderdestroyerwidget.h"
#include "ui_orderDestroyerWidget.h"

namespace airLifeWidget {
    orderDestroyerWidget::orderDestroyerWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::orderDestroyerWidget) {
        ui->setupUi(this);
    }

    orderDestroyerWidget::~orderDestroyerWidget() {
        delete ui;
    }

    void orderDestroyerWidget::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }
} // airLifeWidget
