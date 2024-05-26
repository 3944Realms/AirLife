//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_INFORMATIONMODIFIERWIDGET_H
#define AIRLIFE_INFORMATIONMODIFIERWIDGET_H

#include <QWidget>
#include "../../Base/component.h"
#include "../../UI/dialogs/airlifeerrordialog.h"
#include "../../UI/dialogs/airlifeinfodialog.h"
#include "../../UI/dialogs/airliferunningdialog.h"

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class informationModifierWidget; }
    QT_END_NAMESPACE

    class informationModifierWidget : public QWidget {
    Q_OBJECT

    public:
        explicit informationModifierWidget(QWidget *parent = nullptr);

        ~informationModifierWidget() override;

    private:
        int timerId;
        Ui::informationModifierWidget *ui;
        airLifeDialog::AirLifeErrorDialog* errorDialog;
        airLifeDialog::AirLifeRunningDialog* runningDialog;
        airLifeHandler::DataType dataType;
        QString windowTitle;
        void initWork(airLifeHandler::DataType d);
        void clearAreaText();
        void clearAirplaneText();
        void clearFlightText();
    private slots:
        void enableWindowsSlot();
        void on_airLifeBackPushButton_clicked();

        void on_airLifeModifyAreasPushButton_clicked();
        void on_airLifeModifyAirplanePushButton_clicked();
        void on_airLifeModifyFlightPushButton_clicked();

        void on_airLifeDeleteAreaPushButton_clicked();
        void on_airLifeDeleteAirplanePushButton_clicked();
        void on_airLifeDeleteFlightPushButton_clicked();


    };
} // airLifeWidget

#endif //AIRLIFE_INFORMATIONMODIFIERWIDGET_H
