//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_AIRLIFEINFODIALOG_H
#define AIRLIFE_AIRLIFEINFODIALOG_H

#include <QDialog>
#include "../../Base/component.h"

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
        bool tryLoadingResultList(std::vector<COMPONENT::Flight*> &resultList);
    protected:
        void showEvent(QShowEvent *event) override {
            connectSelect();
            QDialog::showEvent(event);
        }
        void hideEvent(QHideEvent *event) override {
            disconnectSelect();
            QDialog::hideEvent(event);
        }
    private:
        Ui::AirLifeInfoDialog *ui;
        std::vector<COMPONENT::Flight*>* selfResultList_Ptr;
        COMPONENT::Flight* tempFlight;
    private slots:
        void on_airLifeBackPushButton_clicked();

        void addEmptyItem();

        void connectSelect();

        void disconnectSelect() const;

        void loadArea();
    };
} // airLifeDialog

#endif //AIRLIFE_AIRLIFEINFODIALOG_H
