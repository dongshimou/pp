#include "login.h"
#include "client.h"
#include "friends.h"

#include "manager.h"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
namespace pp {

struct login::Private {
    //QHBoxLayout unLayout;
    QLineEdit username;
    QLabel un;

    //QHBoxLayout pwLayout;
    QLineEdit password;
    QLabel pw;

    //QHBoxLayout loginLayout;
    QPushButton loginIn;
    QPushButton signUp;
    QPushButton forgetPW;
    //QVBoxLayout mainLayout;

};
login::login(QWidget *parent)noexcept
    : super(LOGIN_WINDOW,parent) {
    impl = new Private;
    init();
}

login::~login() noexcept {
    delete impl;
}

void login::init() noexcept {
    client::init();

    setObjectName("login");

    impl->un.setText(QString::fromUtf16(u"ÓÃ»§Ãû"));
    impl->pw.setText(QString::fromUtf16(u"ÃÜÂë"));

    impl->loginIn.setText(QString::fromUtf16(u"µÇÂ¼"));
    impl->signUp.setText(QString::fromUtf16(u"×¢²á"));
    impl->forgetPW.setText(QString::fromUtf16(u"Íü¼ÇÃÜÂë"));

#if 0
    this->setLayout(&impl->mainLayout);
    impl->mainLayout.addLayout(&impl->unLayout);
    impl->mainLayout.addLayout(&impl->pwLayout);
    impl->mainLayout.addLayout(&impl->loginLayout);

    impl->unLayout.addWidget(&impl->un);
    impl->unLayout.addWidget(&impl->username);
    impl->pwLayout.addWidget(&impl->pw);
    impl->pwLayout.addWidget(&impl->password);

    impl->loginLayout.addWidget(&impl->signUp);
    impl->loginLayout.addWidget(&impl->loginIn);
    impl->loginLayout.addWidget(&impl->forgetPW);
#else
    auto mainLayout = new QVBoxLayout{ this };
    auto unLayout = new QHBoxLayout;
    auto pwLayout = new QHBoxLayout;
    auto loginLayout = new QHBoxLayout;

    mainLayout->addLayout(unLayout);
    mainLayout->addLayout(pwLayout);
    mainLayout->addLayout(loginLayout);

    unLayout->addWidget(&impl->un);
    unLayout->addWidget(&impl->username);
    pwLayout->addWidget(&impl->pw);
    pwLayout->addWidget(&impl->password);

    loginLayout->addWidget(&impl->signUp);
    loginLayout->addWidget(&impl->loginIn);
    loginLayout->addWidget(&impl->forgetPW);
#endif

    connect(&impl->loginIn, &QPushButton::clicked,
            this, [=]() {
        // ÍøÂç³õÊ¼»¯

        manager::openFriends();
    });

    connect(client::getInstance(), &client::loginStatus,
            this, [=](client::LOGIN_STATUS status) {
        //µÇÂ¼×´Ì¬
        switch (status)
        {
        case client::LOGIN_STATUS::SUCCESS:
            //µÇÂ¼³É¹¦
            manager::openFriends();
            break;
        default:
            break;
        }
    });

}

}
