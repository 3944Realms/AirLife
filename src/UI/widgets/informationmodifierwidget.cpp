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

        errorDialog = new airLifeDialog::AirLifeErrorDialog(this);
        runningDialog = new airLifeDialog::AirLifeRunningDialog(this);
        dataType = airLifeHandler::UNKNOWN_DATA_TYPE;
        windowTitle = this->window()->windowTitle();
        timerId = 0;
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
//        initWork(airLifeHandler::AREA);
        std::string AreaUUID = this->ui->airLifeThisAreaUUIDComboBox->currentText().toStdString();
        std::string AreaCurrentName = this->ui->airLifeThisAreaNameComboBox->currentText().toStdString();
        std::string AreaNewName = this->ui->airLifeThisAreaNewNameLineEdit->text().toStdString();
    }

    void informationModifierWidget::on_airLifeModifyAirplanePushButton_clicked() {
        //修改飞机按钮
        std::string AirplaneUUID = this->ui->airLifeThisAirplaneUUIDComboBox->currentText().toStdString();
        std::string AirplaneCapacityStr = this->ui->airLifeUpdateAirplaneCapLineEdit->text().toStdString();
    }

    void informationModifierWidget::on_airLifeModifyFlightPushButton_clicked() {
        //修改航班按钮
        std::string FlightUUID;
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

    void informationModifierWidget::enableWindowsSlot() {
        switch (dataType) {
            case airLifeHandler::AREA: {
                clearAreaText();
                break;
            }
            case airLifeHandler::AIRPLANE: {
                clearAirplaneText();
                break;
            }
            case airLifeHandler::FLIGHT: {
                clearFlightText();
                break;
            }
            default:
                break;
        }
        this->setEnabled(true);
        this->windowTitleChanged(windowTitle);
    }

    void informationModifierWidget::initWork(airLifeHandler::DataType type) {
        this->windowTitleChanged(windowTitle + " (RUNNING...)");
        this->setEnabled(false);
        this->errorDialog->setEnabled(true);
        this->runningDialog->setEnabled(true);
        dataType = type;
    }

    void informationModifierWidget::clearAreaText() { //target：互改目的（UUID->Name,Name->UUID）
        this->ui->airLifeThisAreaUUIDComboBox->clearEditText();
        this->ui->airLifeThisAreaNameComboBox->clearEditText();
        this->ui->airLifeThisAreaNewNameLineEdit->clear();
    }

    void informationModifierWidget::clearAirplaneText() {
        this->ui->airLifeThisAirplaneUUIDComboBox->clearEditText();
        this->ui->airLifeUpdateAirplaneCapLineEdit->clear();
    }

    void informationModifierWidget::clearFlightText() { //由航班UUID -》改飞机编号（起点/终点，时刻）
        this->ui->airLifeFlightUUIDComboBox->clearEditText();
        this->ui->airLifeThisAirplaneUUIDComboBox->clearEditText();
        this->ui->airLifeFlightEComboBox->clearEditText();
        this->ui->airLifeFlightSComboBox->clearEditText();
        this->ui->airLifeFlightTakeTimeLineEdit->clear();
    }


} // airLifeWidget
