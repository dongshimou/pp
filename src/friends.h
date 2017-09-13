#pragma once
#include "window.h"

namespace pp {
class friends :public window {
    Q_OBJECT
    struct Private;
    Private* impl;
    using super = window;
public:
    explicit friends(QWidget* parent=nullptr);
    ~friends();
private:
    void init();
};

}
