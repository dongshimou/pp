#include "config.h"

#include<QSettings>

namespace pp {

config* ptr = nullptr;
struct config::Private {
    QString address;
    quint16 port;
};
config::config() {
    impl = new Private;
    QSettings setting("./client.ini", QSettings::IniFormat);
    setting.beginGroup("client");
    impl->address=setting.value("address", "127.0.0.1").toString();
    impl->port=setting.value("port", "20000").toUInt();
    setting.endGroup();
}

void config::init() {
    getInstance();
}

config* config::getInstance() {
    if (ptr == nullptr)
        ptr = new config;
    return ptr;
}

QString config::getAddress() {
    return getInstance()->impl->address;
}

quint16 config::getPort() {
    return getInstance()->impl->port;
}


}
