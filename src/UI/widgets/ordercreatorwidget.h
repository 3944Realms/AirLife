//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_ORDERCREATORWIDGET_H
#define AIRLIFE_ORDERCREATORWIDGET_H

#include <QWidget>

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class orderCreatorWidget; }
    QT_END_NAMESPACE

    class orderCreatorWidget : public QWidget {
    Q_OBJECT

    public:
        explicit orderCreatorWidget(QWidget *parent = nullptr);

        ~orderCreatorWidget() override;

    private:
        Ui::orderCreatorWidget *ui;
    };
} // airLifeWidget

#endif //AIRLIFE_ORDERCREATORWIDGET_H
