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

        void resetMessage();
        void setMessage(const QString& pMessage);
        void addMessage(const QString& pMessage);
        void setProcessBarCurrentValue(int processValue_);
        void processBarValueChanged(int valueChanged);
        int getProcessBarValue();
    protected:
        void closeEvent(QCloseEvent *event) override;
    private:
        Ui::AirLifeRunningDialog *ui;
        int processValue;
        QString message;

    private slots:
        void onAirLifeProgressBarValueChange();

    };
} // airLifeDialog

#endif //AIRLIFE_AIRLIFERUNNINGDIALOG_H
