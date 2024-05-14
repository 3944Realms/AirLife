//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_informationFinderWidget.h" resolved

#include "informationfinderwidget.h"
#include "ui_informationFinderWidget.h"

namespace airLifeWidget {
    informationFinderWidget::informationFinderWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::informationFinderWidget) {
        ui->setupUi(this);
    }

    informationFinderWidget::~informationFinderWidget() {
        delete ui;
    }
} // airLifeWidget
