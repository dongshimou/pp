#pragma once

#include <QWidget>

namespace pp {
namespace ui {
class haloBorder :public QWidget {

private:
    struct Private;
    Private *impl;
public:
    explicit haloBorder(QWidget* parent = nullptr)noexcept;
    ~haloBorder()noexcept;
    void paintEvent(QPaintEvent *event)override;

};
}
}