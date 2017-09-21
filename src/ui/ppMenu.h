#pragma once

#include "ppLabel.h"

namespace pp {
namespace ui {

class ppMenu :public QObject{
    Q_OBJECT
private:
    struct Private;
    Private* impl;
public:
    explicit ppMenu(QObject* parent = nullptr)noexcept;
    ~ppMenu()noexcept;

    void setMutex(bool mutexed = true);
    void addWidget(QWidget* child);

    public slots:

    void changeMutexed(const QWidget*);
};

}

}
