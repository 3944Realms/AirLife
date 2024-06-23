//
// Created by f2561 on 24-6-9.
//

#ifndef AIRLIFE_USERANDACCOUNTMANAGER_H
#define AIRLIFE_USERANDACCOUNTMANAGER_H

#include <QWidget>

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

    private slots:
        void on_airLifeBackPushButton_clicked();
    };
} // airLifeWidget

#endif //AIRLIFE_USERANDACCOUNTMANAGER_H
