//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_informationModifierWidget.h" resolved

#include "informationmodifierwidget.h"
#include "ui_informationModifierWidget.h"

namespace airLifeWidget {
    informationModifierWidget::informationModifierWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::informationModifierWidget) {
        ui->setupUi(this);
    }

    informationModifierWidget::~informationModifierWidget() {
        delete ui;
    }

    void informationModifierWidget::on_airLifeBackPushButton_clicked() {
        this->close();
    }
} // airLifeWidget
