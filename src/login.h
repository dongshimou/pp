#pragma once

#include "window.h"

namespace pp {

class login : public window {
    Q_OBJECT
private:
    struct Private;
    Private* impl;
    using super = window;
public:
    explicit login(QWidget *parent = 0)noexcept;
    virtual ~login()noexcept;

private:
    void init()noexcept;
};

}
