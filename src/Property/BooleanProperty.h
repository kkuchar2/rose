#pragma once

#include "../ObservableBase.h"

class BooleanProperty : public ObservableBase<bool> {
    public:
        explicit BooleanProperty(bool initValue) : ObservableBase(initValue) {}
};