#pragma once

#include "../ObservableBase.h"

class ShortProperty : public ObservableBase<short> {
    public:
        explicit ShortProperty(short initValue) : ObservableBase(initValue) {}
};