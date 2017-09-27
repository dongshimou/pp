#include "ppDialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
namespace pp {
namespace ui {

struct ppDialog::Private {
    QLabel title;
    QLabel content;
    QPushButton yes;
    QPushButton no;

    int radius;
    QColor color;
    int ops;
};



ppDialog::ppDialog() noexcept
    :super(DIALOG_WINDOW) {
    impl = new Private;

    auto mainLayout = new QVBoxLayout{ this };

    mainLayout->addWidget([=]() {
        auto widget = new QWidget;
        auto layout = new QHBoxLayout{ widget };
        layout->addWidget(&impl->title, 0, Qt::AlignCenter);
        widget->setMinimumHeight(70);
        return widget;
    }());

    mainLayout->addLayout([=]() {
        auto layout = new QVBoxLayout;
        layout->addWidget(&impl->content, 1, Qt::AlignCenter);
        return layout;
    }());

    mainLayout->addWidget([=]() {
        auto widget = new QWidget;
        auto layout = new QHBoxLayout{ widget };
        layout->addWidget(&impl->yes, 0);
        layout->addWidget(&impl->no, 0);
        widget->setMinimumHeight(140);
        return widget;
    }());

    impl->color = QColor(0x123456);
    impl->radius = 0;
    impl->ops = 150;
    impl->title.setText("title");
    impl->content.setText("test\r\ntest");
    impl->yes.setText("yes");
    impl->no.setText("no");
    this->setMinimumSize(840, 480);
    this->setObjectName("ppDialog");
    this->setStyleSheet(
        "QWidget#ppDialog{"
        "background:rgba(12,34,56,128);"
        "}"
    );

    connect(&impl->no,&QPushButton::clicked,
            this, [=]() {
        this->close();
    });
}

ppDialog::~ppDialog() noexcept {
    delete impl;
}

void ppDialog::close() noexcept {
    delete this;
}

void ppDialog::paintEvent(QPaintEvent * event) {
    QPainter painter{ this };
    painter.setRenderHint(QPainter::Antialiasing, true);
    auto rect = this->rect();
    const auto size = this->size();
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRoundedRect(rect, impl->radius, impl->radius);
    painter.setRenderHint(QPainter::Antialiasing, true);

    auto color = impl->color;
    const int haloSize = 9;
    for (int i = 0; i <= haloSize; i++) {
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