#pragma once

#include <memory>
#include <functional>

template<typename T>
using ObserverInternal = std::function<void(T)>;

template<typename T>
using Observer = std::shared_ptr<ObserverInternal<T>>;

template<typename T>
Observer<T> createObserver(std::function<void(T)> func) {
    return std::make_shared<ObserverInternal<T>>(func);
}