//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_INFORMATIONMODIFIERWIDGET_H
#define AIRLIFE_INFORMATIONMODIFIERWIDGET_H

#include <QWidget>

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class informationModifierWidget; }
    QT_END_NAMESPACE

    class informationModifierWidget : public QWidget {
    Q_OBJECT

    public:
        explicit informationModifierWidget(QWidget *parent = nullptr);

        ~informationModifierWidget() override;

    private:
        Ui::informationModifierWidget *ui;
    private slots:
        void on_airLifeBackPushButton_clicked();
    };
} // airLifeWidget

#endif //AIRLIFE_INFORMATIONMODIFIERWIDGET_H
