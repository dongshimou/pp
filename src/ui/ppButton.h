#pragma once

#include <QLabel>

namespace pp {
namespace ui {

class ppButton :public QLabel {
    Q_OBJECT
private:
    struct Private;
    Private* impl;
    using super = QLabel;
public:
    explicit ppButton(QWidget* parent = nullptr)noexcept;
    ppButton(QString label, QWidget* parent = nullptr)noexcept;
    ~ppButton()noexcept;

signals:

    public slots:

private:

};

}
}
