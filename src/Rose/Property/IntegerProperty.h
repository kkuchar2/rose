#pragma once

#include "../Observable.h"

class IntegerProperty : public Observable<int> {
    public:
        explicit IntegerProperty(int initValue) : Observable(initValue) {}
};