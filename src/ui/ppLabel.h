#pragma once

#include <QLabel>

namespace pp {
namespace ui {

class ppLabel :public QLabel{
    Q_OBJECT
private:
    struct Private;
    Private* impl;
public:
    explicit ppLabel(QWidget* parent = nullptr)noexcept;
    ~ppLabel();

    signals:
    void isActive(bool);

protected:
    void mousePressEvent(QMouseEvent *ev)override;
    void enterEvent(QEvent *event)override;
    void leaveEvent(QEvent *event)override;
};

}

}
