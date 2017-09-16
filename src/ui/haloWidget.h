#pragma once

#include <QWidget>

namespace pp {
namespace ui {

class haloWidget :public QWidget {

private:
    struct Private;
    Private *impl;
public:
    explicit haloWidget(QWidget* parent = nullptr)noexcept;
    ~haloWidget()noexcept;
    void paintEvent(QPaintEvent *event)override;

};
}
}