//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_INFORMATIONLOGGERWIDGET_H
#define AIRLIFE_INFORMATIONLOGGERWIDGET_H

#include <QWidget>

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class informationLoggerWidget; }
    QT_END_NAMESPACE

    class informationLoggerWidget : public QWidget {
    Q_OBJECT

    public:
        explicit informationLoggerWidget(QWidget *parent = nullptr);

        ~informationLoggerWidget() override;

    private:
        Ui::informationLoggerWidget *ui;
    };
} // airLifeWidget

#endif //AIRLIFE_INFORMATIONLOGGERWIDGET_H
