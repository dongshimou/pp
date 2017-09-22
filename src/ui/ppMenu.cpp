#include "ppMenu.h"

#include <vector>

namespace pp {
namespace ui {

struct ppMenu::Private {
    bool mutexed;
    std::vector<QWidget*>labels;
    size_t index;
};

ppMenu::ppMenu(QObject * parent) noexcept 
:QObject(parent){
    [=]() {
        impl = new Private;
        impl->mutexed = true;
        impl->index = 0;
    }();
}

ppMenu::~ppMenu() noexcept {
    delete impl;
}

void ppMenu::setMutex(bool mutexed) {
    impl->mutexed = mutexed;
}

void ppMenu::addWidget(QWidget * child) {
    impl->labels.emplace_back(child);
    connect(child, SIGNAL(isActive(const QWidget*)),
            this, SLOT(activeChange(const QWidget*)));
}

QWidget * ppMenu::getWidget(size_t index) {
    if (index < impl->labels.size())
        return std::move(impl->labels[ impl->index ]);
    else
        return nullptr;
}

void ppMenu::activeChange(const QWidget* target) {
    if (!impl->mutexed)return;
    size_t index = 0;
    static_cast<ppLabel*>(impl->labels[impl->index])->setActive(false);
    for (const auto &i : impl->labels) {
        if (i == target) {
            impl->index = index;
            emit activeWidget(target);
            emit activeIndex(index);
            break;
        }
        index++;
    }

}

}
}