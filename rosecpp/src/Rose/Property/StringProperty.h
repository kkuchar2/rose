#pragma once

#include "../Observable.h"

class StringProperty : public Observable<std::string> {
    public:
        explicit StringProperty(std::string initValue) : Observable(std::move(initValue)) {}
};