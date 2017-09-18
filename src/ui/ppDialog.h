#pragma once

#include "../window.h"

namespace pp {
namespace ui {

class ppDialog :public window{
private:
    using super = window;
    struct Private;
    Private* impl;

public:
    explicit ppDialog()noexcept;
    ~ppDialog()noexcept;

protected:
    void paintEvent(QPaintEvent * event)override;
};

}
}
