//
// Created by f2561 on 24-5-15.
//

#ifndef AIRLIFE_AIRLIFERUNNINGDIALOG_H
#define AIRLIFE_AIRLIFERUNNINGDIALOG_H

#include <QDialog>

namespace airLifeDialog {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AirLifeRunningDialog; }
    QT_END_NAMESPACE

    class AirLifeRunningDialog : public QDialog {
    Q_OBJECT

    public:
        explicit AirLifeRunningDialog(QWidget *parent = nullptr);

        ~AirLifeRunningDialog() override;

    private:
        Ui::AirLifeRunningDialog *ui;
    };
} // airLifeDialog

#endif //AIRLIFE_AIRLIFERUNNINGDIALOG_H
