//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_ADMINISTERMAINWINDOW_H
#define AIRLIFE_ADMINISTERMAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "../../Core/GuiHandler.h"

namespace airLifeMainWindow {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AdministerMainWindow; }
    QT_END_NAMESPACE

    class AdministerMainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit AdministerMainWindow(QWidget *parent = nullptr);

        ~AdministerMainWindow() override;

    private:
        Ui::AdministerMainWindow *ui;
    private slots:
        void airLifeAccountLogOutActionSlot();
    };
} // airLifeMainWindow

#endif //AIRLIFE_ADMINISTERMAINWINDOW_H
