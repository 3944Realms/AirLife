#ifndef AIRLIFE_AIRLIFEINPUTTIPWIDGET_H
#define AIRLIFE_AIRLIFEINPUTTIPWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QFontMetrics>
#include <QFont>

namespace airLifeTipWidget {

    class AirLifeInputTipWidget : public QWidget {
    public:
        explicit  AirLifeInputTipWidget(QWidget *parent = nullptr,
                                        Qt::GlobalColor fontColor = Qt::black,
                                        Qt::GlobalColor backgroundColor = Qt::white,
                                        bool isFontBold = false,
                                        unsigned int remainedTime = 1000,
                                        int fontPixelSize = 15
                                )
                                : QWidget(parent, Qt::Popup | Qt::FramelessWindowHint) ,
                                fontColor(fontColor),
                                backgroundColor(backgroundColor),
                                isBold(isFontBold),
                                remainedTime(remainedTime),
                                fontPixelSize(fontPixelSize),
                                m_text("default") {
            // 设置提示框的样式和属性
            setAttribute(Qt::WA_TranslucentBackground);
        }

        void setText(const QString &text) {
            m_text = text;
            update(); // 请求重绘
        }
        void showEvent(QShowEvent *event) override {
            QWidget::showEvent(event);
            // 设置自动隐藏的时间，默认1秒
            QTimer::singleShot(remainedTime,this,&AirLifeInputTipWidget::hide);
        }

    protected:
        void paintEvent(QPaintEvent *event) override {
            QPainter painter(this);
            painter.setPen(fontColor);
            painter.setBackground(QBrush(backgroundColor));
            painter.eraseRect(rect());

            //设置字体和文字粗细
            QFont font = painter.font();
            font.setBold(isBold);
            font.setPixelSize(fontPixelSize);
            painter.setFont(font);

            // 获取文本的宽度和高度
            QFontMetrics fontMetrics(font);
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
        bool isBold;
        Qt::GlobalColor fontColor, backgroundColor;
        unsigned int remainedTime;
        int fontPixelSize;
    };
} // airLifeTipWidget

#endif //AIRLIFE_AIRLIFEINPUTTIPWIDGET_H
