//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_AIRLIFERUNNIGDIALOG_H
#define AIRLIFE_AIRLIFERUNNIGDIALOG_H

#include <QDialog>

namespace airLifeDialog {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AirLifeRunnigDialog; }
    QT_END_NAMESPACE

    class AirLifeRunnigDialog : public QDialog {
    Q_OBJECT

    public:
        explicit AirLifeRunnigDialog(QWidget *parent = nullptr);

        ~AirLifeRunnigDialog() override;

    private:
        Ui::AirLifeRunnigDialog *ui;
    };
} // airLifeDialog

#endif //AIRLIFE_AIRLIFERUNNIGDIALOG_H
