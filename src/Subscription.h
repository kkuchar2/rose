#pragma once

#include "Tools.h"

class Subscription {
    private:
        Action removeAction;

    public:
        explicit Subscription(Action removeAction) {
            this->removeAction = std::move(removeAction);
        }

        void Unsubscribe() {
            removeAction();
        }
};