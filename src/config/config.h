#pragma once
#include <QString>
namespace pp {
class config {
    struct Private;
    Private* impl;
private:
    config();
    static config* getInstance();
public:
    static void init();
    static QString getAddress();
    static quint16 getPort();
};
}
