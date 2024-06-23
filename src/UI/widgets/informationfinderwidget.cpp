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
        tempFlight = nullptr;
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
        delete tempFlight;
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
            runningDialogShow("Flight-Mode", ResultList);
        }
        else if(searchMode == airLifeHandler::AreaMode ) {
            runningDialogShow("Area-Mode", ResultList);
        }
        else if(searchMode == airLifeHandler::DateMode ) {
            runningDialogShow("Data-Mode", ResultList);
        }
        else {
            message = "Unknown Fault";
            isValid = false;
        }
        if(!isValid) {
            initWork();
            errorDialog->setMessage(message);
            errorDialog->show();
        }
    }

    void informationFinderWidget::timerEvent(QTimerEvent *event) {
        if(this->runningDialog->getProcessBarValue() != 100) runningDialog->processBarValueChanged(10);
        else {
            if(resultStatus == airLifeHandler::RUNNING) {
                resultStatus = airLifeHandler::WAITING;
                infoResultShowTask();
            }
            killTimer(timerId);
        }
    }
    void informationFinderWidget::infoResultShowTask() {
        if(ResultList.empty()) isValid = false;
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


    void informationFinderWidget::runningDialogShow(const QString& message, const std::vector<COMPONENT::Flight> &resultList) {
        if(resultStatus != airLifeHandler::INITIAL_FAILED) resultStatus = airLifeHandler::RUNNING;
        else return;
        initWork();
        runningDialog->setMessage(message);
        runningDialog->setProcessBarCurrentValue(0);
        runningDialog->show();
        timerId = startTimer(waitTime);
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
