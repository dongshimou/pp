#pragma once

#include <QLabel>

namespace pp {
namespace ui {

class ppGradual :public QLabel {
private:
    using super = QLabel;
    struct Private;
    Private* impl;

public:
    explicit ppGradual(QString path,
                       QWidget* parent = nullptr)noexcept;
    ~ppGradual()noexcept;

protected:
    void paintEvent(QPaintEvent *event)override;
};

}

}

