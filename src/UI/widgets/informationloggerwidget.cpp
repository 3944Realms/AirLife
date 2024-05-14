//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_informationLoggerWidget.h" resolved

#include "informationloggerwidget.h"
#include "ui_informationLoggerWidget.h"

namespace airLifeWidget {
    informationLoggerWidget::informationLoggerWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::informationLoggerWidget) {
        ui->setupUi(this);
    }

    informationLoggerWidget::~informationLoggerWidget() {
        delete ui;
    }
} // airLifeWidget
