//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_AIRLIFEERRORDIALOG_H
#define AIRLIFE_AIRLIFEERRORDIALOG_H

#include <QDialog>

namespace airLifeDialog {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AirLifeErrorDialog; }
    QT_END_NAMESPACE

    class AirLifeErrorDialog : public QDialog {
    Q_OBJECT

    public:
        explicit AirLifeErrorDialog(QWidget *parent = nullptr);

        ~AirLifeErrorDialog() override;

    private:
        Ui::AirLifeErrorDialog *ui;
    };
} // airLifeDialog

#endif //AIRLIFE_AIRLIFEERRORDIALOG_H
