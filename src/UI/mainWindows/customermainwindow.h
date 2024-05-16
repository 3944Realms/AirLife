//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_CUSTOMERMAINWINDOW_H
#define AIRLIFE_CUSTOMERMAINWINDOW_H

#include <QMainWindow>
#include "../widgets/informationfinderwidget.h"
#include "../widgets/ordercreatorwidget.h"
#include "../widgets/orderdestroyerwidget.h"
#include "../../Core/GuiHandler.h"

namespace airLifeMainWindow {
    QT_BEGIN_NAMESPACE
    namespace Ui { class CustomerMainWindow; }
    QT_END_NAMESPACE

    class CustomerMainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit CustomerMainWindow(QWidget *parent = nullptr);
        void disconnectAllSignalsAndSlots();
        ~CustomerMainWindow() override;

    private:
        Ui::CustomerMainWindow *ui;
        airLifeWidget::informationFinderWidget *informationFinderWidget;
        airLifeWidget::orderCreatorWidget *orderCreatorWidget;
        airLifeWidget::orderDestroyerWidget *orderDestroyerWidget;

    private slots:
        void airLifeAccountLogOutActionSlot();
        void airLifeSearchFlightActionSlot();
        void airLifeCreateOrderActionSlot();
        void airLifeDeleteOrderActionSlot();
        void on_airLifeCreateOrderPushButton_clicked();
        void on_airLifeDeleteOrderPushButton_clicked();
        void on_airLifeSearchFlightPushButton_clicked();
        void childWindowClosed();
    };
} // airLifeMainWindow

#endif //AIRLIFE_CUSTOMERMAINWINDOW_H
