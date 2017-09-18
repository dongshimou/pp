#include "friends.h"

#include "manager.h"
#include "client.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
namespace pp {

struct friends::Private {
    QLabel name;
    QWidgetList friendList;
};
friends::friends() 
:super(FRIENDS_WINDOW){
    impl = new Private;
    init();
}

void friends::init() {
    auto mainLayout = new QVBoxLayout{ this };
    mainLayout->addLayout([=]() {
        auto layout = new QHBoxLayout;
        ///todo
        layout->addWidget(&impl->name);
        impl->name.setText("123123123123");
        return layout;
    }());

    mainLayout->addLayout([=]() {
        auto layout = new QVBoxLayout;
        ///todo
        return layout;
    }());

}

friends::~friends() {
    delete impl;
}


}
