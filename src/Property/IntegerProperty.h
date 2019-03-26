#pragma once

#include "../ObservableBase.h"

class IntegerProperty : public ObservableBase<int> {
    public:
        explicit IntegerProperty(int initValue) : ObservableBase(initValue) {}
};