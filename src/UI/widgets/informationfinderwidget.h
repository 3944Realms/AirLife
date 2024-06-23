//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_INFORMATIONFINDERWIDGET_H
#define AIRLIFE_INFORMATIONFINDERWIDGET_H

#include <QWidget>
#include "../../Base/component.h"
#include "../../Core/AirLifeInputTipWidget.h"
#include "../../UI/dialogs/airlifeerrordialog.h"
#include "../../UI/dialogs/airlifeinfodialog.h"
#include "../../UI/dialogs/airliferunningdialog.h"

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class informationFinderWidget; }
    QT_END_NAMESPACE

    class informationFinderWidget : public QWidget {
    Q_OBJECT

    public:
        explicit informationFinderWidget(QWidget *parent = nullptr);

        ~informationFinderWidget() override;
    protected:
        void timerEvent(QTimerEvent *event) override;

    private:
        Ui::informationFinderWidget *ui;
        COMPONENT::Flight* tempFlight;
        airLifeHandler::SearchMode searchMode;
        airLifeDialog::AirLifeErrorDialog* errorDialog;
        airLifeDialog::AirLifeRunningDialog* runningDialog;
        airLifeDialog::AirLifeInfoDialog* infoDialog;
        airLifeTipWidget::AirLifeInputTipWidget* tipWidget;
        std::vector<COMPONENT::Flight> ResultList;
        int timerId;
        bool isValid;
        airLifeHandler::ResultStatus resultStatus;
        void enableInputBoxToSwitchMode();
        void setMode(const QString& id);
        void runningDialogShow(const QString& message, const std::vector<COMPONENT::Flight> &resultList);
    private slots:
        void on_airLifeBackPushButton_clicked();
        void on_airLifeBeginPushButton_clicked();
        void enableWindowSlot();
        void onModeRadioButtonToggled(bool checked);

        void initWork();

        void infoResultShowTask();
    };

} // airLifeWidget

#endif //AIRLIFE_INFORMATIONFINDERWIDGET_H
