#pragma once

#include "../ObservableBase.h"

class LongProperty : public ObservableBase<long> {
    public:
        explicit LongProperty(long initValue) : ObservableBase(initValue) {}
};