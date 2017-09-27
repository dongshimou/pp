#include "ppButton.h"

#include <QPainter>
#include <QPolygonF>
#include <QStaticText>
#include <QDebug>

namespace pp {
namespace ui {

struct ppButton::Private {

    static const int width = 150;
    static const int height = 70;

    static const int radiusWidth = 25;
    static const int radiusHeight = height / 2;

    QColor color;
    QString label;
};

ppButton::ppButton(QWidget * parent) noexcept
    :super(parent) {
    impl = new Private;
    [=]() {
        impl->color = Qt::blue;
    }();
    this->setMinimumSize(impl->width, impl->height);
}

ppButton::ppButton(QString label, QWidget * parent) noexcept
    : ppButton(parent) {
    impl->label=label;
}

ppButton::~ppButton() noexcept {
    delete impl;
}
void ppButton::paintEvent(QPaintEvent * event) {
    QPainter painter{ this };
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    QPolygon poly;
    poly.append({ 0, impl->radiusHeight });
    poly.append({ impl->radiusWidth, impl->height });
    poly.append({ impl->width - impl->radiusWidth,impl->height });
    poly.append({ impl->width,impl->radiusHeight });
    poly.append({ impl->width - impl->radiusWidth,0 });
    poly.append({ impl->radiusWidth,0 });
    path.addPolygon(poly);
    path.closeSubpath();


    auto color = impl->color;
    painter.setBrush(color);
    color.setAlpha(64);
    painter.setPen(color);
    painter.drawPath(path);

    QStaticText text(impl->label);
    text.setPerformanceHint(QStaticText::AggressiveCaching);
    text.prepare({ }, QFont());
    qDebug() << "text = "<<text.size();
    painter.setPen(Qt::green);
    painter.drawStaticText(impl->width / 2 - text.size().width() / 2,
                           impl->height / 2 - text.size().height() / 2,
                           text);
}

}
}