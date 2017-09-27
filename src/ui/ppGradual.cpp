#include "ppGradual.h"

#include <QPainter>
#include <QImage>
namespace pp {
namespace ui {

struct ppGradual::Private {
    QColor origin;
    QColor target;
    bool leftToRight = true;
    QPixmap pixmap;
};

ppGradual::ppGradual(QString path, 
                     QWidget * parent) noexcept
    :QLabel(parent){
    impl = new Private;
    [=]() {
        impl->origin = Qt::black;
        impl->origin.setAlpha(192);
        impl->target = Qt::white;
        impl->target.setAlpha(64);
        impl->pixmap = QPixmap(path);
    }();
}

ppGradual::~ppGradual() noexcept {
    delete impl;
}
#if 1
void ppGradual::paintEvent(QPaintEvent * event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    qreal width = this->width();
    qreal height = this->height();
    auto start = QPointF{ 0.0f,height / 2 };
    auto end = QPointF{ width,height / 2 };
    QLinearGradient lg;

    if (impl->leftToRight) {
        lg.setStart(start);
        lg.setFinalStop(end);
    }
    else {
        lg.setStart(end);
        lg.setFinalStop(start);
    }

    lg.setColorAt(0, impl->origin);
    lg.setColorAt(1, impl->target);

    lg.setSpread(QGradient::PadSpread);
    painter.setPen(Qt::transparent);
    painter.setBrush(lg);
    painter.drawRect(this->rect());

    //painter.drawPixmap(impl->pixmap.rect(), impl->pixmap);

    /// todo 
    /// draw a background image
}
#endif
}
}