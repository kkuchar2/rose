#pragma once

#include "../ObservableBase.h"

class DoubleProperty : public ObservableBase<double> {
    public:
        explicit DoubleProperty(double initValue) : ObservableBase(initValue) {}
};