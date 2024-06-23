//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_ADMINISTERMAINWINDOW_H
#define AIRLIFE_ADMINISTERMAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "../../Core/GuiHandler.h"
#include "../widgets/informationloggerwidget.h"
#include "../widgets/informationmodifierwidget.h"
#include "../widgets/informationfinderwidget.h"
#include "../widgets/passwordmodifier.h"
#include "../widgets/userandaccountmanager.h"
namespace airLifeMainWindow {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AdministerMainWindow; }
    QT_END_NAMESPACE

    class AdministerMainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit AdministerMainWindow(QWidget *parent = nullptr);
        void disconnectAllSignalsAndSlots();
        ~AdministerMainWindow() override;

    private:
        Ui::AdministerMainWindow *ui;
        airLifeWidget::informationLoggerWidget *informationLoggerWidget;
        airLifeWidget::informationModifierWidget *informationModifierWidget;
        airLifeWidget::informationFinderWidget *informationFinderWidget;
        airLifeWidget::PasswordModifier *passwordModifierWidget;
        airLifeWidget::UserAndAccountManager *userAndAccountManagerWidget;
    private slots:
        void airLifeAccountLogOutActionSlot();
        void airLifeSearchFlightActionSlot();
        void airLifeAddInformationActionSlot();
        void airLifeMRInformationActionSlot();
        void airLifeUserAndAccountManagerActionSlot();
        void airLifePasswordModifierSlot();
        void on_airLifeAddInformationPushButton_clicked();
        void on_airLifeMRInformationPushButton_clicked();
        void childWindowClosed();
    };
} // airLifeMainWindow

#endif //AIRLIFE_ADMINISTERMAINWINDOW_H
