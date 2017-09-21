#pragma once
#include "../base/model.h"

#include "window.h"
namespace pp {

class talk :public window{
private:
    struct Private;
    Private* impl;
    using super = window;
public:
    explicit talk(userID uid)noexcept;
    ~talk()noexcept;
private:
    void init();
};

}
