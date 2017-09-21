#include "ppMenu.h"

#include <vector>

namespace pp {
namespace ui {

struct ppMenu::Private {
    bool mutexed;
    std::vector<QWidget*>labels;
};

ppMenu::ppMenu(QObject * parent) noexcept 
:QObject(parent){
    [=]() {
        impl = new Private;
        impl->mutexed = true;
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
            this, SLOT(changeMutexed(const QWidget*)));
}

void ppMenu::changeMutexed(const QWidget* target) {
    if (!impl->mutexed)return;
    for (const auto &i : impl->labels) {
        if (i == target)continue;
        static_cast<ppLabel*>(i)->reStyle(false);
    }
}

}
}