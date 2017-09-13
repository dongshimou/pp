#pragma once
namespace pp {

template<class T>
class queue {
private:
    struct Private;
    Private* impl;
public:
    queue()noexcept;
    queue(const queue&) = delete;
    queue&operator=(const queue&) = delete;
    ~queue()noexcept;
    T front();
    T back();
    void pop();
    void push(const T& value);
    void push(T&& value);
    size_t size();
    bool empty();
    void clear();
};

}
