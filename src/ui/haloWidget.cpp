#include "haloWidget.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>

#include <QLabel>
#include <QGraphicsColorizeEffect>
#include <QGridLayout>
namespace pp {
namespace ui {

struct haloWidget::Private {
    int radius;
    int ops;
    bool ud;
    QColor color;
    QTimer tick;
};
haloWidget::~haloWidget() noexcept {
    delete impl;
}

haloWidget::haloWidget(QWidget * parent) noexcept {
    const int OP_S = 200;
    const int OP_E = 250;
    impl = new Private;
    [=]() {
        impl->radius = 20;
        impl->ops = OP_S;
        impl->color = QColor(0xffcc66);
        impl->ud = true;
    }();
    auto layout = new QGridLayout{ this };
    layout->addWidget(new QLabel("fuck you"), 0, 0,Qt::AlignCenter);
    connect(&impl->tick, &QTimer::timeout, this, [=]() {
        if (impl->ud) {
            impl->ops += 10;
        } else {
            impl->ops -= 10;
        }
        if (impl->ops >= OP_E || impl->ops <= OP_S)
            impl->ud = !impl->ud;
        //this->repaint();
        this->update();
    });
    impl->tick.start(100);

    this->setFixedSize(100, 100);
}



void haloWidget::paintEvent(QPaintEvent * event) {
    QPainter painter{ this };

    auto color = impl->color;
    const auto haloDeep = 25;
    const auto haloX = this->width() / haloDeep / 2;
    const auto haloY = this->height() / haloDeep / 2;
    auto rect = this->rect();
    auto deepSum = 0;
    for (int i = haloDeep; i >= 0; i--) {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        rect.setRect(rect.left() + haloX,
                     rect.top() + haloY,
                     rect.width() - haloX - haloX,
                     rect.height() - haloY - haloX);

        path.addRoundedRect(rect, impl->radius, impl->radius);
        color.setAlpha( (impl->ops - i * 2)/25 );
        painter.setPen(Qt::transparent);
        painter.setBrush(color);
        painter.drawPath(path);
        deepSum = i;
    }
}

}
}