#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_informationLoggerWidget.h" resolved

#include "informationloggerwidget.h"
#include "ui_informationLoggerWidget.h"
#include <QTime>

namespace airLifeWidget {
    static int waitTime = 1000;
    //然后在List中添加编号（Name（UUID））
    informationLoggerWidget::informationLoggerWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::informationLoggerWidget) {
        ui->setupUi(this);
        errorDialog = new airLifeDialog::AirLifeErrorDialog(this);
        runningDialog = new airLifeDialog::AirLifeRunningDialog(this);
        dataType = airLifeHandler::UNKNOWN_DATA_TYPE;
        windowTitle = this->window()->windowTitle();
        timerId = 0;
        connect(errorDialog, &airLifeDialog::AirLifeErrorDialog::destroyed, this, &informationLoggerWidget::enableWindowsSlot);
        connect(runningDialog, &airLifeDialog::AirLifeRunningDialog::destroyed, this, &informationLoggerWidget::enableWindowsSlot);
    }

    informationLoggerWidget::~informationLoggerWidget() {
        delete ui;
        disconnect(errorDialog, &airLifeDialog::AirLifeErrorDialog::destroyed, this, &informationLoggerWidget::enableWindowsSlot);
        disconnect(runningDialog, &airLifeDialog::AirLifeRunningDialog::destroyed, this, &informationLoggerWidget::enableWindowsSlot);
        delete errorDialog;
        delete runningDialog;
    }

    void informationLoggerWidget::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }
    void informationLoggerWidget::initWork(airLifeHandler::DataType type){
        this->setWindowTitle(windowTitle + " (RUNNING...)");
        this->setEnabled(false);
        this->errorDialog->setEnabled(true);
        this->runningDialog->setEnabled(true);
        dataType = type;
    }
    void informationLoggerWidget::on_airLifeAddNewAreasPushButton_clicked() {
        //添加新地点
        initWork(airLifeHandler::AREA);
        std::string AreaUUID = ui->airLifeAddNewAreaUUIDLineEdit->text().toStdString();
        std::string AreaName = ui->airLifeAddNewAreaNameLineEdit->text().toStdString();
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        COMPONENT::Area* interruptArea = nullptr;
        if(AreaUUID.empty() || AreaName.empty()) {
            isValid = false;
            failedResult = airLifeHandler::LOST;
            goto JUMP$isValid$Area;
        }
        for(auto l: COMPONENT::AreaList){
            if(l->getUUID() == AreaUUID || l->getName() == AreaName) {
                isValid = false;
                interruptArea = l;
                failedResult = airLifeHandler::REPEATED;
                break;
            }
        }
JUMP$isValid$Area:
        if(!isValid) {
            QString message ("Default Message");
            switch (failedResult) {
                case airLifeHandler::LOST: {
                    message = "Empty Input.";
                    break;
                }
                case airLifeHandler::REPEATED: {
                    message = "Repeated Input.";
                    message += "\n Repeated Area:\n  " + QString(interruptArea->toString().c_str());
                    break;
                }
                default:{
                    message = "Unknown failed reason";
                }
            }
            errorDialog->setMessage(message);
            errorDialog->show();
        }else{
            runningDialog->setMessage("Preparing...");
            runningDialog->setProcessBarCurrentValue(0);
            runningDialog->show();
            timerId = startTimer(waitTime);

        }

        //添加新地点
    }

    void informationLoggerWidget::on_airLifeAddNewAirplanePushButton_clicked() {
        //添加飞机
        initWork(airLifeHandler::AIRPLANE);
        std::string AirplaneUUID = ui->airLifeAddNewAirplaneUUIDLineEdit->text().toStdString();
        std::string AirplaneCapacityStr = ui->airLifeAddNewAirplaneCapLineEdit->text().toStdString();
        int AirplaneCapacity = -1;
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        COMPONENT::Airplane* interruptAirplane = nullptr;
        if(AirplaneCapacityStr.empty() || AirplaneUUID.empty()) {
            isValid = false;
            failedResult = airLifeHandler::LOST;
            goto JUMP$isValid$Airplane;//不然会被覆盖
        } else
            try{
                AirplaneCapacity = stoi(AirplaneCapacityStr);
            } catch(std::invalid_argument &a) {
                isValid = false;
                failedResult = airLifeHandler::INCORRECT_FORMAT;
                goto JUMP$isValid$Airplane;
            } catch (std::out_of_range &e) {
                isValid = false;
                failedResult = airLifeHandler::OUT_OF_RANGE;
                goto JUMP$isValid$Airplane;
            }

        if(AirplaneCapacity <= 0 || AirplaneCapacity > USHRT_MAX) {
            isValid = false;
            failedResult = airLifeHandler::INCORRECT_VALUE;
            goto JUMP$isValid$Airplane;
        }
        for(auto l: COMPONENT::AirplaneList) {
            if(l->getUUID() == AirplaneUUID) {
                failedResult = airLifeHandler::REPEATED;
                interruptAirplane = l;
                break;
            }
        }
JUMP$isValid$Airplane:
        if(!isValid) {
            QString message ("Default");
            switch (failedResult) {
                case airLifeHandler::LOST: {
                    message = "Empty Input.";
                    break;
                }
                case airLifeHandler::INCORRECT_FORMAT: {
                    message = "Incorrect Format: Capacity must be integer";
                    break;
                }
                case airLifeHandler::OUT_OF_RANGE :
                case airLifeHandler::INCORRECT_VALUE: {
                    message = "Capacity must be in 1 ~ " + QString(std::to_string(USHRT_MAX).c_str());
                    break;
                }
                case airLifeHandler::REPEATED: {
                    message = "Repeated Input.";
                    message += "\n Repeated Area:\n  " + QString(interruptAirplane->toString().c_str());
                    break;
                }
                default: {
                    message = "Unknown failed reason";
                }
            }
            errorDialog->setMessage(message);
            errorDialog->show();
        } else{
            runningDialog->setMessage("Preparing...");
            runningDialog->setProcessBarCurrentValue(0);
            runningDialog->show();
            timerId = startTimer(waitTime);
        }
    }

    void informationLoggerWidget::on_airLifeAddNewFlightPushButton_clicked() {
        //添加新航班
        initWork(airLifeHandler::FLIGHT);
        std::string FlightUUID = this->ui->airLifeFlightUUIDLineEdit->text().toStdString();
        std::string airplaneUUID = this->ui->airLifeFlightAirplaneUUIDComboBox->currentText().toStdString();
        std::string Flight$AreaE = this->ui->airLifeFlightEComboBox->currentText().toStdString();
        std::string Flight$AreaS = this->ui->airLifeFlightSComboBox->currentText().toStdString();
        std::string Flight$DDate = this->ui->airLifeFlightTimeLineEdit->text().toStdString();
        std::string Flighty$TakeTime = this->ui->airLifeFlightTakeTimeLineEdit->text().toStdString();
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        COMPONENT::Flight* interruptFlight = nullptr;
        unsigned short dDate$year, dDate$month, dDate$day, dDate$hour, dDate$minute, takeTime$hour, takeTime$minute;
        if(FlightUUID.empty() || airplaneUUID.empty() || Flight$AreaE.empty() || Flight$AreaS.empty() || Flight$DDate.empty()) {
            isValid = false;
            failedResult = airLifeHandler::LOST;
            goto JUMP$isValid$Flight;
        }
        if(Flight$AreaE == Flight$AreaS) {
            isValid = false;
            failedResult = airLifeHandler::SAME_CHOICE;
            goto JUMP$isValid$Flight;
        }
        else if((sscanf(Flight$DDate.c_str(), "%hd/%hd/%hd-%hd:%hd", &dDate$year, &dDate$month, &dDate$day, &dDate$hour, &dDate$minute) != 5) || (sscanf(Flighty$TakeTime.c_str(), "%hd:%hd", &takeTime$hour, &takeTime$minute) != 2)) {
            isValid = false;
            failedResult = airLifeHandler::INCORRECT_FORMAT;
        }
        else if(dDate$month > 12 || dDate$month == 0 || dDate$day > COMPONENT::Date::getMonthDay(dDate$year, dDate$month) || dDate$day == 0 || dDate$hour >= 60 || dDate$minute >= 60) {
            isValid = false;
            failedResult = airLifeHandler::INCORRECT_VALUE;
            goto JUMP$isValid$Flight;
        }
        for(auto l : COMPONENT::FlightList) {
            if(l->getUUID() == FlightUUID) {
                failedResult = airLifeHandler::REPEATED;
                interruptFlight = l;
                goto JUMP$isValid$Flight;
            }
        }

JUMP$isValid$Flight:
        if(!isValid){
            QString message("Default");
            switch(failedResult) {
                case airLifeHandler::LOST: {
                    message = "Empty Input.";
                    break;
                }
                case airLifeHandler::INCORRECT_FORMAT: {
                    message = "Incorrect Format:\n Incorrect Date Format: XXXX/XX/XX-XX:XX \nOR\n Incorrect Time Format: XX:XX";
                    break;
                }
                case airLifeHandler::INCORRECT_VALUE: {
                    message = "Incorrect Value ,too Big or Small";
                    break;
                }
                case airLifeHandler::SAME_CHOICE: {
                    message = "StartingPoint and Destination are same Area";
                    break;
                }
                case airLifeHandler::REPEATED: {
                    message = "Repeated Input.";
                    message += "\n Repeated Flight:\n  " + QString(interruptFlight->toString().c_str());
                    break;
                }
                default: {
                    message = "Unknown failed reason";
                }
            }
            errorDialog->setMessage(message);
            errorDialog->show();
        } else {
            runningDialog->setMessage("Preparing...");
            runningDialog->setProcessBarCurrentValue(0);
            runningDialog->show();
            timerId = startTimer(waitTime);
        }
    }

    void informationLoggerWidget::clearAreaText() {
        this->ui->airLifeAddNewAreaNameLineEdit->clear();
        this->ui->airLifeAddNewAreaUUIDLineEdit->clear();
    }

    void informationLoggerWidget::clearAirplaneText() {
        this->ui->airLifeAddNewAirplaneUUIDLineEdit->clear();
        this->ui->airLifeAddNewAirplaneCapLineEdit->clear();
    }

    void informationLoggerWidget::clearFlightText() {
        this->ui->airLifeFlightUUIDLineEdit->clear();
        this->ui->airLifeFlightAirplaneUUIDComboBox->clearEditText();
        this->ui->airLifeFlightEComboBox->clearEditText();
        this->ui->airLifeFlightSComboBox->clearEditText();
        this->ui->airLifeFlightTimeLineEdit->clear();
        this->ui->airLifeFlightTakeTimeLineEdit->clear();
    }

    void informationLoggerWidget::enableWindowsSlot() {
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
        this->setWindowTitle(windowTitle);
        this->setEnabled(true);
    }

    void informationLoggerWidget::timerEvent(QTimerEvent *event) {
        if(this->runningDialog->getProcessBarValue() != 100) runningDialog->processBarValueChanged(10);
        else killTimer(timerId);
    }
} // airLifeWidget

#pragma clang diagnostic pop