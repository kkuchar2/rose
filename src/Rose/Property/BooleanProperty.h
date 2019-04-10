#pragma once

#include "../Observable.h"

class BooleanProperty : public Observable<bool> {
    public:
        explicit BooleanProperty(bool initValue) : Observable(initValue) {}
};