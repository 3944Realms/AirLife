//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_INFORMATIONFINDERWIDGET_H
#define AIRLIFE_INFORMATIONFINDERWIDGET_H

#include <QWidget>

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class informationFinderWidget; }
    QT_END_NAMESPACE

    class informationFinderWidget : public QWidget {
    Q_OBJECT

    public:
        explicit informationFinderWidget(QWidget *parent = nullptr);

        ~informationFinderWidget() override;

    private:
        Ui::informationFinderWidget *ui;
    };
} // airLifeWidget

#endif //AIRLIFE_INFORMATIONFINDERWIDGET_H
