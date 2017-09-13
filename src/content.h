#pragma once

#include<QWidget>

namespace pp {
class content :public QWidget {
    Q_OBJECT
private:
    struct Private;
    Private* impl;
    using super = QWidget;
public:
    explicit content(QWidget* child=nullptr)noexcept;
    ~content() noexcept;

protected:
    void mousePressEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void mouseDoubleClickEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
};

}
