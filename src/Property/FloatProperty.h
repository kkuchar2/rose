#pragma once

#include "../ObservableBase.h"

class FloatProperty : public ObservableBase<float> {
    public:
        explicit FloatProperty(float initValue) : ObservableBase(initValue) {}
};