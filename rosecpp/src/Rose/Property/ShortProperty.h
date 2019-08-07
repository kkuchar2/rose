#pragma once

#include "../Observable.h"

class ShortProperty : public Observable<short> {
    public:
        explicit ShortProperty(short initValue) : Observable(initValue) {}
};