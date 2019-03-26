#pragma once

#include "../ObservableBase.h"

class StringProperty : public ObservableBase<std::string> {
    public:
        explicit StringProperty(std::string initValue) : ObservableBase(std::move(initValue)) {}
};