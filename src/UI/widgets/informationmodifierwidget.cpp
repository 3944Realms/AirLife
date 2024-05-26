//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_informationModifierWidget.h" resolved

#include "informationmodifierwidget.h"
#include "ui_informationModifierWidget.h"

namespace airLifeWidget {
    static int waitTime = 1000;
    informationModifierWidget::informationModifierWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::informationModifierWidget) {
        ui->setupUi(this);
        tipWidget = new airLifeTipWidget::InputTipWidget();
        errorDialog = new airLifeDialog::AirLifeErrorDialog(this);
        runningDialog = new airLifeDialog::AirLifeRunningDialog(this);
        dataType = airLifeHandler::UNKNOWN_DATA_TYPE;
        windowTitle = this->window()->windowTitle();
        timerId = 0;
        TempArea = nullptr;
        TempAirplane = nullptr;
        TempFlight = nullptr;
        connect(errorDialog, &airLifeDialog::AirLifeErrorDialog::destroyed, this, &informationModifierWidget::enableWindowsSlot);
        connect(runningDialog, &airLifeDialog::AirLifeRunningDialog::destroyed, this, &informationModifierWidget::enableWindowsSlot);

        connect(ui->airLifeThisAreaNameComboBox, &QComboBox::editTextChanged,
                [=](const QString &text){
//            if(ui->airLifeThisAreaUUIDComboBox->currentText().toStdString() == "Not Found" || ui->airLifeThisAreaNameComboBox->currentText().toStdString().empty()) return ;
            if(TempArea != nullptr) {
                if(text != TempArea->getName().c_str()) TempArea = nullptr;
                else {
                    if(ui->airLifeThisAreaUUIDComboBox->currentText().toStdString() != TempArea->getUUID()) {
                        ui->airLifeThisAreaUUIDComboBox->setCurrentText(TempArea->getUUID().c_str());
                        return ;
                    }
                    else return ;
                }
            }
            for(auto l: COMPONENT::AreaList) {
                if(l->getName() == text.toStdString()) {
                    TempArea = l;
                    break;
                }
            }
            if(TempArea != nullptr) ui->airLifeThisAreaUUIDComboBox->setCurrentText(TempArea->getUUID().c_str());
            else {
                tipWidget->setText("NOT FOUND");
                tipWidget->move(ui->airLifeThisAreaNameComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
                tipWidget->show();
            }
        });
        connect(ui->airLifeThisAreaUUIDComboBox, &QComboBox::editTextChanged,
                [=](const QString &text) {
//            if(ui->airLifeThisAreaNameComboBox->currentText().toStdString() == "Not Found" || ui->airLifeThisAreaUUIDComboBox->currentText().toStdString().empty()) return ;
            if(TempArea != nullptr) {
                if(text != TempArea->getUUID().c_str()) TempArea = nullptr;
                else {
                    if(ui->airLifeThisAreaNameComboBox->currentText().toStdString() != TempArea->getName()) {
                        ui->airLifeThisAreaNameComboBox->setCurrentText(TempArea->getName().c_str());
                        return ;
                    }
                    else return ;
                }
            }
            for(auto l : COMPONENT::AreaList) {
                        if(l->getUUID() == text.toStdString()) {
                            TempArea = l;
                            break;
                        }
                }
            if(TempArea != nullptr) ui->airLifeThisAreaNameComboBox->setCurrentText(TempArea->getUUID().c_str());
            else {
                tipWidget->setText("NOT FOUND");
                tipWidget->move(ui->airLifeThisAreaUUIDComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
                tipWidget->show();
            }
        });
        connect(ui->airLifeThisAirplaneUUIDComboBox, &QComboBox::editTextChanged,
                [=](const QString &text){
            if(TempAirplane != nullptr) {
                if(text != TempAirplane->getUUID().c_str()) TempAirplane = nullptr;
                else {
                    ui->airLifeUpdateAirplaneCapLineEdit->setText(std::to_string(TempAirplane->getCapacity()).c_str());
                    return ;
                }
            }
            for(auto l : COMPONENT::AirplaneList) {
                if(l->getUUID() == text.toStdString()) {
                    TempAirplane = l;
                    break;
                }
            }
            if(TempAirplane != nullptr) ui->airLifeUpdateAirplaneCapLineEdit->setText((std::to_string(TempAirplane->getCapacity()).c_str()));
            else {
                    tipWidget->setText("NOT FOUND");
                    tipWidget->move(ui->airLifeThisAirplaneUUIDComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
                    tipWidget->show();
            }
        });
        connect(ui->airLifeFlightUUIDComboBox, &QComboBox::editTextChanged,
                [=](const QString &text){
            if(TempFlight != nullptr) {
                if(text != TempFlight->getUUID().c_str()) TempFlight = nullptr;
                else {
                    ui->airLifeFlightAirplaneUUIDComboBox->currentTextChanged(TempFlight->getUUID().c_str());
                    ui->airLifeFlightEComboBox->currentTextChanged(TempFlight->getStartingPointArea()->getName().c_str());
                    ui->airLifeFlightSComboBox->currentTextChanged(TempFlight->getDestinationArea()->getName().c_str());
                    ui->airLifeFlightTimeLineEdit->textChanged(TempFlight->getDepartureTime().toString().c_str());
                    ui->airLifeFlightTakeTimeLineEdit->textChanged(TempFlight->getTakeTime().toString().c_str());
                    return ;
                }
            }
            for(auto l : COMPONENT::FlightList) {
                if(l->getUUID() == text.toStdString()) {
                    TempFlight = l;
                    break;
                }
            }
            if(TempFlight != nullptr) {
                ui->airLifeFlightAirplaneUUIDComboBox->currentTextChanged(TempFlight->getUUID().c_str());
                ui->airLifeFlightEComboBox->currentTextChanged(TempFlight->getStartingPointArea()->getName().c_str());
                ui->airLifeFlightSComboBox->currentTextChanged(TempFlight->getDestinationArea()->getName().c_str());
                ui->airLifeFlightTimeLineEdit->textChanged(TempFlight->getDepartureTime().toString().c_str());
                ui->airLifeFlightTakeTimeLineEdit->textChanged(TempFlight->getTakeTime().toString().c_str());
            }
            else {
                tipWidget->setText("NOT FOUND");
                tipWidget->move(ui->airLifeFlightUUIDComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
                tipWidget->show();
            }
        });
    }

    informationModifierWidget::~informationModifierWidget() {
        delete tipWidget;
        delete errorDialog;
        delete runningDialog;
        delete ui;
    }

    void informationModifierWidget::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }

    void informationModifierWidget::on_airLifeModifyAreasPushButton_clicked() {
        //修改地点按钮
        initWork(airLifeHandler::AREA);
        std::string AreaUUID = this->ui->airLifeThisAreaUUIDComboBox->currentText().toStdString();
        std::string AreaCurrentName = this->ui->airLifeThisAreaNameComboBox->currentText().toStdString();
        std::string AreaNewName = this->ui->airLifeThisAreaNewNameLineEdit->text().toStdString();
        bool isValid = true;
        bool isFound = false;
        airLifeHandler::FailedResult failedResult;
        COMPONENT::Area* temp$Area = nullptr;
        if(AreaUUID.empty() || AreaCurrentName.empty() || AreaNewName.empty()) {
            isValid = false;
            failedResult = airLifeHandler::LOST;
            goto JUMP$isValid$AREA$Modify;
        }
        if(AreaCurrentName == AreaNewName) {
            isValid = false;
            failedResult = airLifeHandler::SAME_CHOICE;
        }
        for(auto l : COMPONENT::AreaList) {
            if(l->getUUID() == AreaUUID) {
                isFound = true;
                temp$Area = l;
            }
            else if(l->getName() == AreaNewName) {
                isValid = false;
                failedResult = airLifeHandler::REPEATED;
                temp$Area = l;
                goto JUMP$isValid$AREA$Modify;
            }
        }
        if(failedResult != airLifeHandler::REPEATED && !isFound) {
            isValid = false;
            failedResult = airLifeHandler::NOT_FOUND;
        }
JUMP$isValid$AREA$Modify:
        if(!isValid) {
            QString message ("Default Message");
            switch (failedResult) {
                case airLifeHandler::LOST: {
                    message = "Empty Input.";
                    break;
                }
                case airLifeHandler::SAME_CHOICE: {
                    message = "Old Name is as well as New Name.";
                    break;
                }
                case airLifeHandler::REPEATED: {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"
                    message = std::string("Found the name \" " + std::string(AreaNewName) + " \" already existing in " + temp$Area->toString() + ".").c_str();
#pragma clang diagnostic pop
                    break;
                }
                case airLifeHandler::NOT_FOUND: {
                    message = "Modify Object is not found.";
                    break;
                }
                default: {
                    message = "Unknown failed reason";
                }
            }
            errorDialog->setMessage(message);
            errorDialog->show();
        } else {
            //对temp$Area
            runningDialog->setMessage("Preparing...");
            runningDialog->setProcessBarCurrentValue(0);
            runningDialog->show();
            timerId = startTimer(waitTime);
        }
    }

    void informationModifierWidget::on_airLifeModifyAirplanePushButton_clicked() {
        //修改飞机按钮
        initWork(airLifeHandler::AIRPLANE);
        std::string AirplaneUUID = this->ui->airLifeThisAirplaneUUIDComboBox->currentText().toStdString();
        std::string AirplaneCapacityStr = this->ui->airLifeUpdateAirplaneCapLineEdit->text().toStdString();
        bool isValid = true;
        bool isFound = false;
        int AirplaneCapacity = -1;
        airLifeHandler::FailedResult failedResult;
        COMPONENT::Airplane* temp$Airplane = nullptr;
        if(AirplaneCapacityStr.empty() || AirplaneUUID.empty()) {
            isValid = false;
            failedResult = airLifeHandler::LOST;
            goto JUMP$isValid$AIRPLANE$Modify;//不然会被覆盖
        } else
            try{
                AirplaneCapacity = stoi(AirplaneCapacityStr);
            } catch(std::invalid_argument &a) {
                isValid = false;
                failedResult = airLifeHandler::INCORRECT_FORMAT;
                goto JUMP$isValid$AIRPLANE$Modify;
            } catch (std::out_of_range &e) {
                isValid = false;
                failedResult = airLifeHandler::OUT_OF_RANGE;
                goto JUMP$isValid$AIRPLANE$Modify;
            }

        if(AirplaneCapacity <= 0 || AirplaneCapacity > USHRT_MAX) {
            isValid = false;
            failedResult = airLifeHandler::INCORRECT_VALUE;
            goto JUMP$isValid$AIRPLANE$Modify;
        }
        for(auto l: COMPONENT::AirplaneList) {
            if(ui->airLifeThisAirplaneUUIDComboBox->currentText() == l->getUUID().c_str()) {
                isFound = true;
                temp$Airplane = l;
                break;
            }
        }
JUMP$isValid$AIRPLANE$Modify:
        if(!isValid) {
            QString message("Default");
            switch(failedResult) {
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
                default: {
                    message = "Unknown failed reason";
                }
            }
            errorDialog->setMessage(message);
            errorDialog->show();
        } else {
            //temp$Airplane
            runningDialog->setMessage("Preparing...");
            runningDialog->setProcessBarCurrentValue(0);
            runningDialog->show();
            timerId = startTimer(waitTime);
        }

    }

    void informationModifierWidget::on_airLifeModifyFlightPushButton_clicked() {
        //修改航班按钮
//        initWork(airLifeHandler::FLIGHT);
        std::string FlightUUID = this->ui->airLifeFlightUUIDComboBox->currentText().toStdString();
        std::string Flight$AirplaneUUID = this->ui->airLifeFlightAirplaneUUIDComboBox->currentText().toStdString();
        std::string Flight$AreaE = this->ui->airLifeFlightEComboBox->currentText().toStdString();
        std::string Flight$AreaS = this->ui->airLifeFlightSComboBox->currentText().toStdString();
        std::string Flight$DDate = this->ui->airLifeFlightTimeLineEdit->text().toStdString();
        std::string Flight$TakeTime = this->ui->airLifeFlightTakeTimeLineEdit->text().toStdString();
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        if(!isValid) {

        } else {

        }

    }

    void informationModifierWidget::on_airLifeDeleteAreaPushButton_clicked() {
        //删除地点按钮
//        initWork(airLifeHandler::AREA);
        std::string AreaUUID = this->ui->airLifeThisAreaUUIDComboBox->currentText().toStdString();
        std::string AreaCurrentName = this->ui->airLifeThisAreaNameComboBox->currentText().toStdString();
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        if(!isValid) {

        } else {

        }

    }

    void informationModifierWidget::on_airLifeDeleteAirplanePushButton_clicked() {
        //删除飞机按钮
//        initWork(airLifeHandler::AIRPLANE);
        std::string AirplaneUUID = this->ui->airLifeThisAirplaneUUIDComboBox->currentText().toStdString();
        std::string AirplaneCapacityStr = this->ui->airLifeUpdateAirplaneCapLineEdit->text().toStdString();
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        if(!isValid) {

        } else {

        }

    }

    void informationModifierWidget::on_airLifeDeleteFlightPushButton_clicked() {
        //删除航班按钮
//        initWork(airLifeHandler::FLIGHT);
        std::string FlightUUID = this->ui->airLifeFlightUUIDComboBox->currentText().toStdString();
        std::string Flight$AirplaneUUID = this->ui->airLifeFlightAirplaneUUIDComboBox->currentText().toStdString();
        std::string Flight$AreaE = this->ui->airLifeFlightEComboBox->currentText().toStdString();
        std::string Flight$AreaS = this->ui->airLifeFlightSComboBox->currentText().toStdString();
        std::string Flight$DDate = this->ui->airLifeFlightTimeLineEdit->text().toStdString();
        std::string Flight$TakeTime = this->ui->airLifeFlightTakeTimeLineEdit->text().toStdString();
        bool isValid = true;
        airLifeHandler::FailedResult failedResult;
        if(!isValid) {

        } else {

        }

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

    void informationModifierWidget::timerEvent(QTimerEvent *event) {
        if(this->runningDialog->getProcessBarValue() != 100) runningDialog->processBarValueChanged(10);
        else killTimer(timerId);
    }


} // airLifeWidget
