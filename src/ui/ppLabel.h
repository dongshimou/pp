#pragma once

#include <QLabel>

namespace pp {
namespace ui {

class ppLabel :public QLabel{
    Q_OBJECT
private:
    struct Private;
    Private* impl;
public:
    explicit ppLabel(QWidget* parent = nullptr)noexcept;
    ppLabel(QString label, QWidget* parent = nullptr)noexcept;
    ~ppLabel()noexcept;
    
    bool isActive()const;
private:
    void resetActiveStyle(bool);

    signals:
    void isActive(bool);
    void isActive(const QWidget*);
    public slots:
    void setActive(bool);

protected:
    void mousePressEvent(QMouseEvent *ev)override;
    void enterEvent(QEvent *event)override;
    void leaveEvent(QEvent *event)override;
};

}

}
