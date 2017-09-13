#pragma once

#include "model.h"

#include <QObject>
namespace pp {

class client : public QObject {
    Q_OBJECT
private:
    struct Private;
    Private* impl;
    enum PARSE_STATUS {
        ERROR,
        LOGIN_SUCCESS,
        LOGIN_FAILED,
        MESSAGE,
    };

public:
    enum LOGIN_STATUS {
        SUCCESS,
        UNKNOW_ERROR,
        UNKNOW_USER,
        WRONG_PASSWORD,
    };
public:
    static client* getInstance();
    static void init();
    void loginIn(const QString&,const QString&);
    void loginOut();
    void getUserInfo();
signals:
    void loginStatus(LOGIN_STATUS);
    void setUserInfo(const userInfo*);
    void recvSingleMessage(const singleMessage*);
    void recvMulitMessage(const mulitMessage*);

    void recvAddUser(uint32_t);
    void recvDelUser(uint32_t);

    void happenError();
public slots:

    void sendSingleMessage(const singleMessage*);
    void sendMulitMessage(const mulitMessage*);

    void sendAddUser(uint32_t);
    void sendDelUser(uint32_t);

    void error();
private:
    explicit client()noexcept;
    PARSE_STATUS parseServerMessage(QByteArray&&);
    void recvData();
};

}
