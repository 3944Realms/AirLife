//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_informationModifierWidget.h" resolved

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
        emit destroyed();
    }

    void informationModifierWidget::on_airLifeModifyAreasPushButton_clicked() {
        //修改地点按钮
    }

    void informationModifierWidget::on_airLifeModifyAirplanePushButton_clicked() {
        //修改飞机按钮
    }

    void informationModifierWidget::on_airLifeModifyFlightPushButton_clicked() {
        //修改航班按钮
    }

    void informationModifierWidget::on_airLifeDeleteAreaPushButton_clicked() {
        //删除地点按钮
    }

    void informationModifierWidget::on_airLifeDeleteAirplanePushButton_clicked() {
        //删除飞机按钮
    }

    void informationModifierWidget::on_airLifeDeleteFlightPushButton_clicked() {
        //删除航班按钮
    }
} // airLifeWidget
