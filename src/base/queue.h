#pragma once

#include "spinlock.h"
#include <queue>

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

template<class T>
struct queue<T>::Private {
    std::queue<T>q;
    SpinLock l;
};
template<class T>
queue<T>::queue() noexcept {
    impl = new Private;
}

template<class T>
queue<T>::~queue() noexcept {
    delete impl;
}

template<class T>
void queue<T>::push(T&& value) {
    impl->l.lock();
    impl->q.push(std::forward<T>(value));
    impl->l.unlock();
}

template<class T>
void queue<T>::push(const T& value) {
    impl->l.lock();
    impl->q.push(std::forward<T>(value));
    impl->l.unlock();
}

template<class T>
void queue<T>::pop() {
    impl->l.lock();
    impl->q.pop();
    impl->l.unlock();
}

template<class T>
T queue<T>::front() {
    impl->l.lock();
    auto r = impl->q.front();
    impl->l.unlock();
    return std::move(r);
}

template<class T>
T queue<T>::back() {
    impl->l.lock();
    auto r = impl->q.back();
    impl->l.unlock();
    return std::move(r);
}

template<class T>
size_t queue<T>::size() {
    impl->l.lock();
    auto r = impl->q.size();
    impl->l.unlock();
    return r;
}

template<class T>
bool queue<T>::empty() {
    impl->l.lock();
    auto r = impl->q.empty();
    impl->l.unlock();
    return r;
}

template<class T>
void queue<T>::clear() {
    impl->l.lock();
    impl->q.clear();
    impl->l.unlock();
}
}
