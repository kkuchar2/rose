#pragma once

#include "../Observable.h"

class FloatProperty : public Observable<float> {
    public:
        explicit FloatProperty(float initValue) : Observable(initValue) {}
};