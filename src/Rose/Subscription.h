#pragma once

#include "Tools.h"

class SubscriptionInternal {
    private:
        Action removeAction;

    public:
        explicit SubscriptionInternal(Action removeAction) {
            this->removeAction = std::move(removeAction);
        }

        void Unsubscribe() {
            removeAction();
        }
};