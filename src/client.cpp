#include "client.h"
#include "queue.h"
#include "queue.cpp"

#include "config.h"

#include <QNetworkAccessManager>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
namespace pp {

static client* ptr = nullptr;

struct client::Private {
    pp::queue<singleMessage>mq;
    QNetworkAccessManager manager;
    QTcpSocket tcp;
};

void client::init() {
    config::init();
    auto p = getInstance();
    // recv data
    connect(&p->impl->tcp, &QTcpSocket::readyRead, 
            p, &client::recvData);
    // socket error
    connect(&p->impl->tcp, SIGNAL(error(QAbstractSocket::SocketError)),
            p, SLOT(error()));
    // start connect
    p->impl->tcp.connectToHost(config::getAddress(), config::getPort());
}

client::client() noexcept {
    impl = new Private;
}

client::PARSE_STATUS client::parseServerMessage(QByteArray&&data) {
    qDebug() << data;
    return client::ERROR;
}

void client::recvData() {
    auto status = parseServerMessage(std::move(impl->tcp.readAll()));
    switch (status) {
    case LOGIN_SUCCESS:
        ///todo
        emit loginStatus(LOGIN_STATUS::SUCCESS);
        break;
    case LOGIN_FAILED:
        ///todo
        emit loginStatus(LOGIN_STATUS::UNKNOW_ERROR);
        break;
    case MESSAGE:

        break;
    default:
        break;
    }
}

client * client::getInstance() {

    if (ptr == nullptr) {
        ptr = new client();
    }
    return ptr;
}

void client::loginIn(const QString&username,const QString&passwod) {
    QJsonObject obj;
    QVariantMap mp;
    mp.insert("username", username);
    mp.insert("passwod", passwod);
    obj.fromVariantMap(mp);
    auto doc=QJsonDocument::fromVariant(mp);
    impl->tcp.write(doc.toJson());
}

void client::loginOut() {
}

void client::getUserInfo() {
    ///todo
    auto info = new userInfo;
    emit setUserInfo(info);
}


void client::sendSingleMessage(const singleMessage* msg) {

}

void client::sendMulitMessage(const mulitMessage* msg) {
}

void client::sendAddUser(uint32_t uid) {
}

void client::sendDelUser(uint32_t uid) {
}

void client::error() {
    emit happenError();
}



}
