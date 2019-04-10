#pragma once

#include "../Observable.h"

class DoubleProperty : public Observable<double> {
    public:
        explicit DoubleProperty(double initValue) : Observable(initValue) {}
};