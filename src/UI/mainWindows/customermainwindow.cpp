//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CustomerMainWindow.h" resolved

#include "customermainwindow.h"
#include "ui_CustomerMainWindow.h"

namespace airLifeMainWindow {
    CustomerMainWindow::CustomerMainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::CustomerMainWindow) {
        ui->setupUi(this);
    }

    CustomerMainWindow::~CustomerMainWindow() {
        delete ui;
    }
} // airLifeMainWindow
