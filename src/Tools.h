#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <memory>

#include "Subscription.h"

template<typename T>
using ObserverInternal = std::function<void(T)>;

template<typename T>
using Observer = std::shared_ptr<ObserverInternal<T>>;

template<typename T>
Observer<T> createObserver(std::function<void(T)> func) {
    return std::make_shared<ObserverInternal<T>>(func);
}

using Action = std::function<void()>;

template<typename T>
void Remove(std::vector<std::shared_ptr<T>> & vector, const std::shared_ptr<T> & t) {
    /*
    Remove shared_ptr from vector, where that shared_ptr points to same address as t because
    shared pointers in vector are copies and we cannot remove them by referencing only t)
    */
    int index_to_remove = -1;

    for (unsigned int i = 0; i < vector.size(); i++) {
        if (vector[i].get() == t.get()) {
            index_to_remove = i;
        }
    }

    if (index_to_remove != -1) {
        // After that only copy of shared pointer in vector will be removed
        vector.erase(vector.begin() + index_to_remove);
    }
}

template<typename T>
void println(T t) {
    std::cout << t << std::endl;
}