//
// Created by f2561 on 24-5-12.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_hui.h" resolved

#include "hui.h"
#include "ui_hui.h"

namespace egg {
    hui::hui(QWidget *parent) :
            QWidget(parent), ui(new Ui::hui) {
        ui->setupUi(this);
    }

    hui::~hui() {
        delete ui;
    }
} // egg
