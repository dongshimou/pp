#include "ppLabel.h"
#include <QVariant>
#include <QStyle>
#include <QMouseEvent>
#include <QDebug>
namespace pp {
namespace ui {

struct ppLabel::Private { };

ppLabel::ppLabel(QWidget * parent) noexcept
    :QLabel(parent) {
    impl = new Private;
    [=]() {

    }();
    this->setProperty("ppLabel", false);
    //最小化 frame 占用
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

ppLabel::ppLabel(QString label, QWidget * parent) noexcept 
:ppLabel(parent){
    this->setText(label);
}

ppLabel::~ppLabel() noexcept {
    delete impl;
}

bool ppLabel::isActive() const {
    return this->property("ppLabel").toBool();
}

void ppLabel::resetActiveStyle(bool status) {
    this->setProperty("ppLabel", status);
    this->style()->unpolish(this);
    this->style()->polish(this);
    qDebug() << this->property("ppLabel").toBool();
    this->update();
}

void ppLabel::setActive(bool status) {
    emit isActive(status);
    if (status)
        emit isActive(static_cast<const QWidget*>(this));
    resetActiveStyle(status);
}

void ppLabel::mousePressEvent(QMouseEvent * ev) {
    if (ev->button() == Qt::LeftButton) {
        auto status = this->property("ppLabel").toBool();
        setActive(!status);
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