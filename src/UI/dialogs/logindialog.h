//
// Created by f2561 on 24-5-12.
//

#ifndef AIRLIFE_LOGINDIALOG_H
#define AIRLIFE_LOGINDIALOG_H

#include <QDialog>
#include <iostream>
#include "../../Base/component.h"
#include "../easterEgg/hui.h"
#include "../../Core/LoginHandler.h"
#include "../../Core/GuiHandler.h"

namespace airLifeDialog {
    QT_BEGIN_NAMESPACE
    namespace Ui { class loginDialog; }
    QT_END_NAMESPACE

    class loginDialog : public QDialog {
    Q_OBJECT

    public:
        explicit loginDialog(QWidget *parent = nullptr);

        ~loginDialog() override;

    private:
        Ui::loginDialog *ui;
    private slots:
        void on_loginButton_clicked();
        void on_cancelButton_clicked();
    };
} // airLifeDialog

#endif //AIRLIFE_LOGINDIALOG_H
