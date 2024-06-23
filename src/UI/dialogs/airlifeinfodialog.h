//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_AIRLIFEINFODIALOG_H
#define AIRLIFE_AIRLIFEINFODIALOG_H

#include <QDialog>

namespace airLifeDialog {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AirLifeInfoDialog; }
    QT_END_NAMESPACE

    class AirLifeInfoDialog : public QDialog {
    Q_OBJECT

    public:
        explicit AirLifeInfoDialog(QWidget *parent = nullptr);

        ~AirLifeInfoDialog() override;
        void testMethod();

    private:
        Ui::AirLifeInfoDialog *ui;

    private slots:
        void on_airLifeBackPushButton_clicked();
    };
} // airLifeDialog

#endif //AIRLIFE_AIRLIFEINFODIALOG_H
