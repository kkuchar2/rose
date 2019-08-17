#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <memory>

#include "Subscription.h"

using Action = std::function<void()>;

template<typename T>
void Remove(std::vector<std::shared_ptr<T>> & vector, const std::shared_ptr<T> & t) {
    vector.erase(std::find(vector.begin(), vector.end(), t));
}

template<typename T>
void println(T t) {
    std::cout << t << std::endl;
}