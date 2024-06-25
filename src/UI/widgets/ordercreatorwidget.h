//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_ORDERCREATORWIDGET_H
#define AIRLIFE_ORDERCREATORWIDGET_H

#include <QWidget>
#include <ctime>
#include <sstream>
#include "../../Base/component.h"
#include "../../UI/dialogs/airlifeerrordialog.h"
#include "../../UI/dialogs/airlifeinfodialog.h"
#include "../../UI/dialogs/airliferunningdialog.h"

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class orderCreatorWidget; }
    QT_END_NAMESPACE

    class orderCreatorWidget : public QWidget {
    Q_OBJECT

    public:
        explicit orderCreatorWidget(QWidget *parent = nullptr);
//        void test() {
//            time_t t = time(nullptr);
//            struct tm* now = localtime(&t);
//            std::stringstream timeStr;
//            timeStr << now->tm_year + 1900;
//
//        };
        ~orderCreatorWidget() override;

    private:
        Ui::orderCreatorWidget *ui;
    private slots:
        void on_airLifeBackPushButton_clicked();
    };
} // airLifeWidget

#endif //AIRLIFE_ORDERCREATORWIDGET_H
