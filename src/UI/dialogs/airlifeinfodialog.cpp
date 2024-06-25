//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_AirLifeInfoDialog.h" resolved

#include "airlifeinfodialog.h"
#include "ui_AirLifeInfoDialog.h"

namespace airLifeDialog {
    AirLifeInfoDialog::AirLifeInfoDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::AirLifeInfoDialog) {
        ui->setupUi(this);
        selfResultList_Ptr = nullptr;
        tempFlight = nullptr;
        addEmptyItem();
        connectSelect();
    }

    void AirLifeInfoDialog::disconnectSelect() const {
        disconnect(ui->airLifeFlightComboBox, &QComboBox::currentTextChanged, nullptr, nullptr);
        disconnect(ui->airLifeEComboBox, &QComboBox::currentTextChanged, nullptr, nullptr);
        disconnect(ui->airLifeSComboBox, &QComboBox::currentTextChanged, nullptr, nullptr);
    }

    void AirLifeInfoDialog::connectSelect() {
        connect(ui->airLifeFlightComboBox, &QComboBox::currentTextChanged,
                [=](const QString & text) {
            if(selfResultList_Ptr != nullptr) {
                if(tempFlight != nullptr) {
                    if(tempFlight->getUUID() != ui->airLifeFlightComboBox->currentText().toStdString()) {
                        tempFlight = nullptr;
                    } else {
                        if(tempFlight->getStartingPointArea()->getName() == ui->airLifeEComboBox->currentText().toStdString()) {
                            ui->airLifeEComboBox->setCurrentText(tempFlight->getStartingPointArea()->getName().c_str());
                        }
                        if(tempFlight->getDestinationArea()->getName() == ui->airLifeSComboBox->currentText().toStdString()) {
                            ui->airLifeSComboBox->setCurrentText(tempFlight->getDestinationArea()->getName().c_str());
                        }
                        if(tempFlight->getDepartureTime().toString() == ui->airLifeTimeLineEdit->text().toStdString()) {
                            ui->airLifeTimeLineEdit->setText(tempFlight->getDepartureTime().toString().c_str());
                        }
                        return;
                    }
                }
                std::string AreaS, AreaE, Date;
                bool isFound = false;
                for(auto i : *selfResultList_Ptr) {
                    if(i->getUUID().c_str() == text) {
                        tempFlight = i;
                        AreaE = i->getStartingPointArea()->getName();
                        AreaS = i->getDestinationArea()->getName();
                        Date = i->getDepartureTime().toString();
                        isFound = true;
                        break;
                    }
                }
                if(isFound) {
                    if(AreaE != ui->airLifeEComboBox->currentText().toStdString()) {
                        ui->airLifeEComboBox->setCurrentText(AreaE.c_str());
                    }
                    if(AreaS != ui->airLifeSComboBox->currentText().toStdString()) {
                        ui->airLifeSComboBox->setCurrentText(AreaS.c_str());
                    }
                    if(Date != ui->airLifeEComboBox->currentText().toStdString()) {
                        ui->airLifeTimeLineEdit->setText(Date.c_str());
                    }
                }
            }
        });
        connect(ui->airLifeEComboBox, &QComboBox::currentTextChanged,
                [=](const QString & text){
            if(selfResultList_Ptr != nullptr) {
                if(tempFlight != nullptr) {
                    if(tempFlight->getStartingPointArea()->getName() != ui->airLifeEComboBox->currentText().toStdString()) {
                        tempFlight = nullptr;
                    }
                    else return;
                }
                ui->airLifeFlightComboBox->clear();
                bool hasAreaE{ui->airLifeEComboBox->currentText().toStdString().empty()},
                        hasAreaS{ui->airLifeSComboBox->currentText().toStdString().empty()};
                if(hasAreaE) {
                    if (!hasAreaS) {
                        for (auto i: *selfResultList_Ptr) {
                            if (i->getStartingPointArea()->getName() ==
                                ui->airLifeEComboBox->currentText().toStdString()){
                                ui->airLifeFlightComboBox->addItem(i->getUUID().c_str());
                            }
                        }
                    } else {
                        for (auto i: *selfResultList_Ptr) {
                            if (i->getStartingPointArea()->getName() ==
                                ui->airLifeEComboBox->currentText().toStdString() &&
                                i->getDestinationArea()->getName() ==
                                ui->airLifeSComboBox->currentText().toStdString()) {
                                ui->airLifeFlightComboBox->addItem(i->getUUID().c_str());
                            }
                        }

                    }
                }

            }
        });
        connect(ui->airLifeSComboBox, &QComboBox::currentTextChanged,
                [=](const QString & text){
            if(selfResultList_Ptr != nullptr) {
                if(tempFlight != nullptr) {
                    if(tempFlight->getDestinationArea()->getName() != ui->airLifeSComboBox->currentText().toStdString()) {
                        tempFlight = nullptr;
                    }
                    else return;
                }
                ui->airLifeFlightComboBox->clear();
                bool hasAreaE{ui->airLifeEComboBox->currentText().toStdString().empty()},
                        hasAreaS{ui->airLifeSComboBox->currentText().toStdString().empty()};
                if(hasAreaS) {
                    if (!hasAreaE) {
                        for (auto i: *selfResultList_Ptr) {
                            if (i->getDestinationArea()->getName() ==
                                ui->airLifeSComboBox->currentText().toStdString()){
                                ui->airLifeFlightComboBox->addItem(i->getUUID().c_str());
                            }
                        }
                    } else {
                        for (auto i: *selfResultList_Ptr) {
                            if (i->getStartingPointArea()->getName() ==
                                ui->airLifeEComboBox->currentText().toStdString() &&
                                i->getDestinationArea()->getName() ==
                                ui->airLifeSComboBox->currentText().toStdString()) {
                                ui->airLifeFlightComboBox->addItem(i->getUUID().c_str());
                            }
                        }

                    }
                }

            }
        });
    }

    void AirLifeInfoDialog::addEmptyItem() {
        ui->airLifeFlightComboBox->addItem("");
        ui->airLifeEComboBox->addItem("");
        ui->airLifeSComboBox->addItem("");
    }

    void AirLifeInfoDialog::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }

    AirLifeInfoDialog::~AirLifeInfoDialog() {
        delete ui;
    }

    void AirLifeInfoDialog::testMethod() {
        this->ui->airLifeEComboBox->setEditable(false);
        this->ui->airLifeEComboBox->addItem("thisGay");
    }
/**
 * Must be USE WHEN SHOW INFO DIALOG
 * @param resultList
 * @return isEMPTY
 */
    bool AirLifeInfoDialog::tryLoadingResultList(std::vector<COMPONENT::Flight*> &resultList) {
        selfResultList_Ptr = new std::vector<COMPONENT::Flight*>(resultList);
        return resultList.empty();
    }

    void AirLifeInfoDialog::loadArea() {
        std::unordered_map<std::string, COMPONENT::Area *> AreaERegistry, AreaSRegistry;
        for(auto i : *selfResultList_Ptr) {
            AreaERegistry[i->getStartingPointArea()->getUUID()] = i->getStartingPointArea();
            AreaSRegistry[i->getDestinationArea()->getUUID()] = i->getDestinationArea();
        }
        for (const auto &item: AreaERegistry) {
            ui->airLifeEComboBox->addItem(item.second->getName().c_str());
        }
        for (const auto &item: AreaSRegistry) {
            ui->airLifeSComboBox->addItem(item.second->getName().c_str());
        }
    }
} // airLifeDialog
