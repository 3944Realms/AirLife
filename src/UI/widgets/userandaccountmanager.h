//
// Created by f2561 on 24-6-9.
//

#ifndef AIRLIFE_USERANDACCOUNTMANAGER_H
#define AIRLIFE_USERANDACCOUNTMANAGER_H

#include <QWidget>
#include "../../Core/AirLifeInputTipWidget.h"

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class UserAndAccountManager; }
    QT_END_NAMESPACE

    class UserAndAccountManager : public QWidget {
    Q_OBJECT

    public:
        explicit UserAndAccountManager(QWidget *parent = nullptr);

        ~UserAndAccountManager() override;

    private:
        Ui::UserAndAccountManager *ui;
        airLifeTipWidget::AirLifeInputTipWidget *tipWidget;

    private slots:
        void on_airLifeBackPushButton_clicked();
        void on_airLifeSearchButton_clicked();
        void on_airLifeFlushButton_clicked();
        void on_airLifeRegisterPushButton_clicked();
        void on_airLifeSearchButton_2_clicked();
    };
} // airLifeWidget

#endif //AIRLIFE_USERANDACCOUNTMANAGER_H
