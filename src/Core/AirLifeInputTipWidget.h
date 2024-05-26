#ifndef AIRLIFE_AIRLIFEINPUTTIPWIDGET_H
#define AIRLIFE_AIRLIFEINPUTTIPWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

namespace airLifeTipWidget {

    class InputTipWidget : public QWidget {
    public:
        explicit InputTipWidget(QWidget *parent = nullptr) : QWidget(parent, Qt::Popup | Qt::FramelessWindowHint) {
            // 设置提示框的样式和属性
            setAttribute(Qt::WA_TranslucentBackground);

        }

        void setText(const QString &text) {
            m_text = text;
            update(); // 请求重绘
        }
        void showEvent(QShowEvent *event) override {
            QWidget::showEvent(event);
            // 设置自动隐藏的时间，1秒
            QTimer::singleShot(1000,this,&InputTipWidget::hide);
        }

    protected:
        void paintEvent(QPaintEvent *event) override {
            QPainter painter(this);
            painter.setPen(Qt::black);
            painter.setBackground(QBrush(Qt::white));
            painter.eraseRect(rect());

            // 获取文本的宽度和高度
            QFontMetrics fontMetrics(font());
            int textWidth = fontMetrics.horizontalAdvance(m_text);
            int textHeight = fontMetrics.height();
            QRect textRect = painter.boundingRect(rect(), Qt::AlignCenter, m_text);

            // 设置绘制文本的位置
            painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignCenter, m_text);
            // 设置InputTipWidget的sizeHint，以便根据文本大小动态调整大小
            this->setFixedSize(QSize(textWidth, textHeight));
        }

    private:
        QString m_text;
    };
} // airLifeTipWidget

#endif //AIRLIFE_AIRLIFEINPUTTIPWIDGET_H
