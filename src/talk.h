#pragma once
#include "model.h"

#include "window.h"
namespace pp {

class talk :public window{
private:
    struct Private;
    Private* impl;
    using super = window;
public:
    explicit talk(userID uid,QWidget* parent = nullptr)noexcept;
    ~talk()noexcept;
private:
    void init();
};

}
