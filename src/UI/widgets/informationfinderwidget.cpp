#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_informationFinderWidget.h" resolved

#include "informationfinderwidget.h"
#include "ui_informationFinderWidget.h"

namespace airLifeWidget {
    static int waitTime = 50;
    informationFinderWidget::informationFinderWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::informationFinderWidget) {
        ui->setupUi(this);
//        tempFlight = nullptr;
        infoDialog = new airLifeDialog::AirLifeInfoDialog(this);
        errorDialog = new airLifeDialog::AirLifeErrorDialog(this);
        runningDialog = new airLifeDialog::AirLifeRunningDialog(this);
        tipWidget = new airLifeTipWidget::AirLifeInputTipWidget(this);
        searchMode = airLifeHandler::NullMode;
        timerId = -1;
        isValid = true;
        resultStatus = airLifeHandler::INITIAL;
        enableInputBoxToSwitchMode();
        connect(infoDialog, &airLifeDialog::AirLifeInfoDialog::destroyed, this, &informationFinderWidget::enableWindowSlot);
        connect(errorDialog, &airLifeDialog::AirLifeErrorDialog::destroyed, this, &informationFinderWidget::enableWindowSlot);
        connect(runningDialog, &airLifeDialog::AirLifeRunningDialog::destroyed, this, &informationFinderWidget::enableWindowSlot);

        connect(ui->airLifeSearchByFlightRadioButton, &QRadioButton::toggled, this, &informationFinderWidget::onModeRadioButtonToggled);
        connect(ui->airLifeSearchByAreaRadioButton, &QRadioButton::toggled, this, &informationFinderWidget::onModeRadioButtonToggled);
        connect(ui->airLifeSearchByDateRadioButton, &QRadioButton::toggled, this, &informationFinderWidget::onModeRadioButtonToggled);
//        connect(ui->airLifeModeGroupBox, &QGroupBox::clicked, [=](){
//            std::cout<<"Hello There";
//        });
    }

    informationFinderWidget::~informationFinderWidget() {
        disconnect(infoDialog, &airLifeDialog::AirLifeInfoDialog::destroyed, this, &informationFinderWidget::enableWindowSlot);
        disconnect(errorDialog, &airLifeDialog::AirLifeErrorDialog::destroyed, this, &informationFinderWidget::enableWindowSlot);
        disconnect(runningDialog, &airLifeDialog::AirLifeRunningDialog::destroyed, this, &informationFinderWidget::enableWindowSlot);
//        delete tempFlight;
        delete infoDialog;
        delete errorDialog;
        delete runningDialog;
        delete tipWidget;
        delete ui;
    }

    void informationFinderWidget::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }

    void informationFinderWidget::enableWindowSlot() {
        this->setEnabled(true);
    }

    void informationFinderWidget::onModeRadioButtonToggled(bool checked) {
        if(checked) {
            auto* radioButton = qobject_cast<QRadioButton *>(sender());
            if(radioButton) {
                setMode(radioButton->objectName());
                enableInputBoxToSwitchMode();
            }
        }
    }

    void informationFinderWidget::enableInputBoxToSwitchMode() {
        if(this->searchMode == airLifeHandler::FlightMode) {
            ui->airLifeFlightComboBox->setEnabled(true);
            ui->airLifeTimeLineEdit->setEnabled(false);
            ui->airLifeSComboBox->setEnabled(false);
            ui->airLifeEComboBox->setEnabled(false);
        }
        else if(this->searchMode == airLifeHandler::AreaMode) {
            ui->airLifeFlightComboBox->setEnabled(false);
            ui->airLifeTimeLineEdit->setEnabled(false);
            ui->airLifeSComboBox->setEnabled(true);
            ui->airLifeEComboBox->setEnabled(true);
        }
        else if(this->searchMode == airLifeHandler::DateMode) {
            ui->airLifeFlightComboBox->setEnabled(false);
            ui->airLifeTimeLineEdit->setEnabled(true);
            ui->airLifeSComboBox->setEnabled(false);
            ui->airLifeEComboBox->setEnabled(false);
        }
        else {
            ui->airLifeFlightComboBox->setEnabled(false);
            ui->airLifeTimeLineEdit->setEnabled(false);
            ui->airLifeSComboBox->setEnabled(false);
            ui->airLifeEComboBox->setEnabled(false);
        }
    }

    void informationFinderWidget::setMode(const QString& id) {
        if(id == ui->airLifeSearchByFlightRadioButton->objectName()) searchMode = airLifeHandler::FlightMode;
        else if(id == ui->airLifeSearchByDateRadioButton->objectName()) searchMode = airLifeHandler::DateMode;
        else if(id == ui->airLifeSearchByAreaRadioButton->objectName()) searchMode = airLifeHandler::AreaMode;
        else searchMode = airLifeHandler::NullMode;
    }

    void informationFinderWidget::on_airLifeBeginPushButton_clicked() {
        isValid = true;
        QString message = "Default";
        if(searchMode == airLifeHandler::NullMode) {
            isValid = false;
            message = "Please choose one Mode";
            resultStatus = airLifeHandler::FAILED;
        }
        else if(searchMode == airLifeHandler::FlightMode ) {
            FlightUUID = ui->airLifeFlightComboBox->currentText().toStdString();
            if(FlightUUID.empty()) {
                isValid = false;
                message = "Empty Input";
                goto JUMP$isValid$GetFlight;
            }
            runningDialogShow("Flight-Mode", ResultList);
        }
        else if(searchMode == airLifeHandler::AreaMode ) {
            AreaE = ui->airLifeEComboBox->currentText().toStdString(), AreaS = ui->airLifeSComboBox->currentText().toStdString();
            if(AreaE.empty() && AreaS.empty()) {
                isValid = false;
                message = "All Empty Input";
                goto JUMP$isValid$GetFlight;
            } else if(AreaS == AreaE) {
                isValid = false;
                message = "StartingPoint is as well as Destination.";
                goto JUMP$isValid$GetFlight;
            }
            runningDialogShow("Area-Mode", ResultList);
        }
        else if(searchMode == airLifeHandler::DateMode ) {
            std::string Date(ui->airLifeTimeLineEdit->text().toStdString());
            if(Date.empty()) {
                isValid = false;
                message = "Empty Input";
                goto JUMP$isValid$GetFlight;
            } else if(sscanf(Date.c_str(), "%hd/%hd/%hd-%hd:%hd", &dDate$year, &dDate$month, &dDate$day, &dDate$hour, &dDate$minute) != 5) {
                isValid = false;
                message = "Incorrect Format:\n Incorrect Date Format: XXXX/XX/XX-XX:XX";
                goto JUMP$isValid$GetFlight;
            } else if(dDate$month > 12 || dDate$month == 0 || dDate$day > COMPONENT::Date::getMonthDay(dDate$year, dDate$month) || dDate$day == 0 || dDate$hour >= 60 || dDate$minute >= 60) {
                isValid = false;
                message = "Incorrect DateValue ,too Big or Small";
                goto JUMP$isValid$GetFlight;
            }
            runningDialogShow("Data-Mode", ResultList);
        }
        else {
            message = "Unknown Fault";
            isValid = false;
        }
JUMP$isValid$GetFlight:
        if(!isValid) {
            resultStatus = airLifeHandler::FAILED;
            initWork();
            errorDialog->setMessage(message);
            errorDialog->show();
        }
    }

    void informationFinderWidget::timerEvent(QTimerEvent *event) {
        if(this->runningDialog->getProcessBarValue() != 100) {
            isTimerOver = false;
            runningDialog->processBarValueChanged(10);
        }
        else {
            if(resultStatus == airLifeHandler::RUNNING) {
                resultStatus = airLifeHandler::WAITING;
                infoResultShowTask();
            }
            isTimerOver = true;
            killTimer(timerId);
        }
    }
    void informationFinderWidget::infoResultShowTask() {
        if(ResultList.empty()) {
            isValid = false;
            if(ErrorMessage != "UNKNOWN_MODE") ErrorMessage = "Not Found";
        } else if(!isOver) {
            isValid = false;
            ErrorMessage = "Not Enough Time to get all information";
        }
        if(!isValid){
            errorDialog->setMessage("Not Found");
            errorDialog->show();
            resultStatus = airLifeHandler::FAILED;
        } else {
            infoDialog->show();
            resultStatus = airLifeHandler::SUCCESSFUL;
        }
        initWork();
    }


    void informationFinderWidget::runningDialogShow(const QString& message, std::vector<COMPONENT::Flight*> &resultList) {
        if(resultStatus != airLifeHandler::INITIAL_FAILED) resultStatus = airLifeHandler::RUNNING;
        else return;
        initWork();
        runningDialog->setMessage(message);
        runningDialog->setProcessBarCurrentValue(0);
        runningDialog->show();
        timerId = startTimer(waitTime);
        ErrorMessage = TaskRunning(resultList)?"NONE":"UNKNOWN_MODE";
    }

    bool informationFinderWidget::TaskRunning(std::vector<COMPONENT::Flight*> &resultList) {
        isOver = false;
        resultList.clear();
        if(searchMode == airLifeHandler::FlightMode) {
            for(auto i : COMPONENT::FlightList) {
                if(FlightUUID == i->getUUID() && !isTimerOver) {
                    resultList.push_back(i);
                    isOver = true;
                    break;
                }
            }
        }
        else if(searchMode == airLifeHandler::AreaMode) {
            bool hasAreaE{!AreaE.empty()}, hasAreaS{!AreaS.empty()};
            if (hasAreaE && hasAreaS) {
                for (auto it = COMPONENT::FlightList.begin(); it != COMPONENT::FlightList.end(); ++it) {
                    COMPONENT::Flight* i = *it;
                    if (AreaE == i->getStartingPointArea()->getName() && AreaS == i->getDestinationArea()->getName()) {
                        resultList.push_back(i);
                    }
                    if (std::next(it) == COMPONENT::FlightList.end()) {
                        isOver = true;
                    }
                }
            } else if (hasAreaS) {
                for (auto it = COMPONENT::FlightList.begin(); it != COMPONENT::FlightList.end(); ++it) {
                    COMPONENT::Flight* i = *it;
                    if (AreaS == i->getDestinationArea()->getName()) {
                        resultList.push_back(i);
                    }
                    if (std::next(it) == COMPONENT::FlightList.end()) {
                        isOver = true;
                    }
                }
            } else if (hasAreaE) {
                for (auto it = COMPONENT::FlightList.begin(); it != COMPONENT::FlightList.end(); ++it) {
                    COMPONENT::Flight* i = *it;
                    if (AreaE == i->getStartingPointArea()->getName()) {
                        resultList.push_back(i);
                    }
                    if (std::next(it) == COMPONENT::FlightList.end()) {
                        isOver = true;
                    }
                }
            }
        } else if(searchMode == airLifeHandler::DateMode) {
            for (auto it = COMPONENT::FlightList.begin(); it != COMPONENT::FlightList.end(); ++it) {
                COMPONENT::Flight* i = *it;
                if (i->getDepartureTime().getYear() == dDate$year &&
                    i->getDepartureTime().getMonth() == dDate$month &&
                    i->getDepartureTime().getDay() == dDate$day &&
                    i->getDepartureTime().getTime().getHour() == dDate$hour &&
                    i->getDepartureTime().getTime().getMinute() == dDate$minute
                ) {
                    resultList.push_back(i);
                }
                if (std::next(it) == COMPONENT::FlightList.end()) {
                    isOver = true;
                }
            }
        } else {
            return false;
        }
        return true;
    }

    void informationFinderWidget::initWork() {
        this->setEnabled(false);
        switch (resultStatus) {
            case airLifeHandler::INITIAL:
                break;
            case airLifeHandler::FAILED:
            case airLifeHandler::INITIAL_FAILED:
                errorDialog->setEnabled(true);
                break;
            case airLifeHandler::WAITING:
            case airLifeHandler::RUNNING:
                runningDialog->setEnabled(true);
                break;
            case airLifeHandler::SUCCESSFUL:
                infoDialog->setEnabled(true);
                break;
        }

    }
} // airLifeWidget

#pragma clang diagnostic pop