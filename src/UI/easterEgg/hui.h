//
// Created by f2561 on 24-5-12.
//

#ifndef AIRLIFE_HUI_H
#define AIRLIFE_HUI_H

#include <QWidget>

namespace egg {
    QT_BEGIN_NAMESPACE
    namespace Ui { class hui; }
    QT_END_NAMESPACE

    class hui : public QWidget {
    Q_OBJECT

    public:
        explicit hui(QWidget *parent = nullptr);

        ~hui() override;

    private:
        Ui::hui *ui;
    };
} // egg

#endif //AIRLIFE_HUI_H
