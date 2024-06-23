//
// Created by f2561 on 24-6-23.
//

#ifndef AIRLIFE_PASSWORDMODIFIER_H
#define AIRLIFE_PASSWORDMODIFIER_H

#include <QWidget>

namespace airLifeWidget {
    QT_BEGIN_NAMESPACE
    namespace Ui { class PasswordModifier; }
    QT_END_NAMESPACE

    class PasswordModifier : public QWidget {
    Q_OBJECT

    public:
        explicit PasswordModifier(QWidget *parent = nullptr);

        ~PasswordModifier() override;

    private:
        Ui::PasswordModifier *ui;
    private slots:
        void on_airLifeBackPushButton_clicked();
    };
} // airLifeWidget

#endif //AIRLIFE_PASSWORDMODIFIER_H
