//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_INFORMATIONLOGGERWIDGET_H
#define AIRLIFE_INFORMATIONLOGGERWIDGET_H

#include <QWidget>
#include "../../Base/component.h"
#include "../../UI/dialogs/airlifeerrordialog.h"
#include "../../UI/dialogs/airlifeinfodialog.h"
#include "../../UI/dialogs/airliferunningdialog.h"

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class informationLoggerWidget; }
    QT_END_NAMESPACE

    class informationLoggerWidget : public QWidget {
    Q_OBJECT

    public:
        explicit informationLoggerWidget(QWidget *parent = nullptr);

        ~informationLoggerWidget() override;
    protected:
        void timerEvent(QTimerEvent *event) override;

    private:
        int timerId;
        Ui::informationLoggerWidget *ui;
        airLifeDialog::AirLifeErrorDialog* errorDialog;
        airLifeDialog::AirLifeRunningDialog* runningDialog;
        airLifeHandler::DataType dataType;
    private slots:
        void enableWindowsSlot();
        void on_airLifeBackPushButton_clicked();
        void on_airLifeAddNewAreasPushButton_clicked();
        void on_airLifeAddNewAirplanePushButton_clicked();
        void on_airLifeAddNewFlightPushButton_clicked();

        void clearAreaText();

        void clearAirplaneText();

        void clearFlightText();


        void initWork(airLifeHandler::DataType d);
    };
} // airLifeWidget

#endif //AIRLIFE_INFORMATIONLOGGERWIDGET_H
