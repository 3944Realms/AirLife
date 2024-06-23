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
#include "../widgets/passwordmodifier.h"
#include "../dialogs/logindialog.h"

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
        void updateInfo();

        static QString getAccountSituation(COMPONENT::Account* account) {
            bool hasValidOrder = false;
            std::string result;
            std::string Total =
                    "订单数目: " + std::to_string((unsigned int)account->getAccountUser()->getOrderList().size()) +
                    "\n退单数目: " + std::to_string((unsigned int)account->getAccountUser()->getChargeBackList().size()) +
                    "\n";
            std::string ValidOrderList = "有效订单情况[OrderUUID,CreatedDate,FlightUUID]：\n";
            for (auto i : account->getAccountUser()->getOrderList()) {
                if(i->isValid()) {
                    ValidOrderList +=
                            ("[" +
                                i->getOrderUUID() + ", " +
                                i->getOrderCreatedDate().toString() + ", " +
                                i->getTargetFlight()->getUUID() +
                            "]\n");
                    hasValidOrder = true;
                }
            }
            if(!hasValidOrder) {
                ValidOrderList += "None";
            }
            /*
             * 订单数量:
             * 退单数量:
             * 有效订单情况（if isValid true显示）:
             */
            result += Total + ValidOrderList;
            return {result.c_str()};
        }
    protected:
        void showEvent(QShowEvent *event) override {
            updateInfo();
            QMainWindow::showEvent(event);
        }
    private:
        Ui::CustomerMainWindow *ui;
        COMPONENT::Account *currentAccount;
        airLifeWidget::informationFinderWidget *informationFinderWidget;
        airLifeWidget::orderCreatorWidget *orderCreatorWidget;
        airLifeWidget::orderDestroyerWidget *orderDestroyerWidget;
        airLifeWidget::PasswordModifier *passwordModifierWidget;

    private slots:
        void airLifeAccountLogOutActionSlot();
        void airLifeSearchFlightActionSlot();
        void airLifeCreateOrderActionSlot();
        void airLifeDeleteOrderActionSlot();
        void airLifePasswordModifierSlot();
        void on_airLifeCreateOrderPushButton_clicked();
        void on_airLifeDeleteOrderPushButton_clicked();
        void on_airLifeSearchFlightPushButton_clicked();
        void childWindowClosed();


    };
} // airLifeMainWindow

#endif //AIRLIFE_CUSTOMERMAINWINDOW_H
