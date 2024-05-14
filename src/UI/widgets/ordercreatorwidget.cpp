//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_orderCreatorWidget.h" resolved

#include "ordercreatorwidget.h"
#include "ui_orderCreatorWidget.h"

namespace airLifeWidget {
    orderCreatorWidget::orderCreatorWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::orderCreatorWidget) {
        ui->setupUi(this);
    }

    orderCreatorWidget::~orderCreatorWidget() {
        delete ui;
    }

    void orderCreatorWidget::on_airLifeBackPushButton_clicked() {
        this->close();
    }
} // airLifeWidget
