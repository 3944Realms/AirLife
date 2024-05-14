//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_ORDERDESTROYERWIDGET_H
#define AIRLIFE_ORDERDESTROYERWIDGET_H

#include <QWidget>

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class orderDestroyerWidget; }
    QT_END_NAMESPACE

    class orderDestroyerWidget : public QWidget {
    Q_OBJECT

    public:
        explicit orderDestroyerWidget(QWidget *parent = nullptr);

        ~orderDestroyerWidget() override;

    private:
        Ui::orderDestroyerWidget *ui;
    private slots:
        void on_airLifeBackPushButton_clicked();
    };
} // airLifeWidget

#endif //AIRLIFE_ORDERDESTROYERWIDGET_H
