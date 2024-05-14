//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdministerMainWindow.h" resolved

#include "administermainwindow.h"
#include "ui_AdministerMainWindow.h"

namespace airLifeMainWindow {
    AdministerMainWindow::AdministerMainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::AdministerMainWindow) {
        ui->setupUi(this);
    }

    AdministerMainWindow::~AdministerMainWindow() {
        delete ui;
    }
} // airLifeMainWindow
