#include "haloBorder.h"

#include "../window/content.h"
#include <QPushButton>
#include <QLabel>
#include <QPainter>

#include <QStaticText>
#include <QGraphicsOpacityEffect>
#include <QGraphicsDropShadowEffect>
#include <QTimer>
#include <QDebug>

namespace pp {
namespace ui {
struct haloBorder::Private {
    QString label;
    QColor color;
    int radius;
    int ops;
    bool ud;
    QTimer tick;
};
haloBorder::haloBorder(QWidget * parent) noexcept
    :QWidget(parent) {

    impl = new Private;

#if 0
    {
        auto effect = new QGraphicsOpacityEffect{ this };
        effect->setOpacity(0.5);
        impl->btn.setGraphicsEffect(effect);
    }
    {
        auto effect = new QGraphicsDropShadowEffect{ this };
        effect->setOffset(2.8);
        impl->btn.setGraphicsEffect(effect);
}
#else

#endif
    impl->label = "123";
    impl->color = QColor(255, 204, 102, 50);
    impl->radius = 0;
    impl->ops = 150;
    impl->ud = true;

    connect(&impl->tick, &QTimer::timeout, this, [=]() {
        if (impl->ud) {
            impl->ops += 10;
        } else {
            impl->ops -= 10;
        }
        if (impl->ops == 250 || impl->ops == 150)
            impl->ud = !impl->ud;
        this->repaint();
    });
    impl->tick.start(100);

    this->setFixedSize(100, 100);

}

haloBorder::~haloBorder() noexcept {
    delete impl;
}

void haloBorder::paintEvent(QPaintEvent * event) {
    QPainter painter{ this };
    painter.setRenderHint(QPainter::Antialiasing, true);
    auto rect = this->rect();
    const auto size = this->size();
    {
        QStaticText st{ impl->label };
        st.prepare({ }, QFont());
        painter.drawStaticText(size.width() / 2 - st.size().width() / 2,
                               size.height() / 2 - st.size().height() / 2,
                               st);
    }
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRoundedRect(rect, impl->radius, impl->radius);
    painter.setRenderHint(QPainter::Antialiasing, true);

    auto color = impl->color;
    const int haloSize = 9;
    for (int i = haloSize; i >= 0; i--) {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        rect.setRect(rect.left() + 1,
                     rect.top() + 1,
                     rect.width() - 2,
                     rect.height() - 2);

        path.addRoundedRect(rect, impl->radius, impl->radius);
        color.setAlpha(impl->ops - std::sqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}
}
}
