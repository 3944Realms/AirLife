//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_CUSTOMERMAINWINDOW_H
#define AIRLIFE_CUSTOMERMAINWINDOW_H

#include <QMainWindow>
#include "../../Core/GuiHandler.h"

namespace airLifeMainWindow {
    QT_BEGIN_NAMESPACE
    namespace Ui { class CustomerMainWindow; }
    QT_END_NAMESPACE

    class CustomerMainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit CustomerMainWindow(QWidget *parent = nullptr);

        ~CustomerMainWindow() override;

    private:
        Ui::CustomerMainWindow *ui;

    private slots:
        void airLifeAccountLogOutActionSlot();
    };
} // airLifeMainWindow

#endif //AIRLIFE_CUSTOMERMAINWINDOW_H
