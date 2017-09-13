#pragma once

#include <QString>
#include <vector>
namespace pp {

using userID = uint64_t;

struct message {
    QString words;
    uint32_t timet;
    bool isRead;
};

struct user {
    QString name;
    userID uid;
};

struct userInfo {
    user self;
    std::vector<user>friends;
};

struct group {
    QString name;
    uint32_t ID;
};
struct singleMessage {
    message msg;
    user origin;
    user target;
};

struct mulitMessage {
    message msg;
    user origin;
    group target;
};

}