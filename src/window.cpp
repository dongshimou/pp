#include "window.h"

#include "content.h"

namespace pp {

struct window::Private {
    WINDOW_TYPE type;
    content *content;
};

window::window(WINDOW_TYPE type, QWidget * parent) noexcept
    :QWidget(parent) {
    impl = new Private;
    [=]() {
        impl->type = type;
        impl->content = new content{ this };
    }();

    ///magic
    this->setObjectName("window");
    this->setStyleSheet("QWidget#window{"
                        "background:transparent;"
                        "}"
    );
}

constexpr window::WINDOW_TYPE window::getWindowType() const noexcept {
    return impl->type;
}

window::~window() noexcept {
    impl->content->close();
    delete impl;
}

}