#include "ppLabel.h"
#include <QVariant>
#include <QStyle>
#include <QMouseEvent>
#include <QDebug>
namespace pp {
namespace ui {

struct ppLabel::Private {
};

ppLabel::ppLabel(QWidget * parent) noexcept
    :QLabel(parent) {
    impl = new Private;
    [=]() {

    }();
    this->setProperty("ppLabel", false);
    //最小化 frame 占用
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

ppLabel::~ppLabel() {
    delete impl;
}

void ppLabel::mousePressEvent(QMouseEvent * ev) {
    if (ev->button() == Qt::LeftButton) {
        auto status = this->property("ppLabel").toBool();
        emit isActive(!status);
        this->setProperty("ppLabel", !status);
        this->style()->unpolish(this);
        this->style()->polish(this);
        qDebug() << this->property("ppLabel").toBool();
        this->update();
    }
    ev->accept();
}

void ppLabel::enterEvent(QEvent * event) {
    this->setCursor(Qt::PointingHandCursor);
    event->accept();
}

void ppLabel::leaveEvent(QEvent * event) {
    this->setCursor(Qt::ArrowCursor);
    event->accept();
}

}
}