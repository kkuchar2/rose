#pragma once

#include "../Observable.h"

class LongProperty : public Observable<long> {
    public:
        explicit LongProperty(long initValue) : Observable(initValue) {}
};