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

using Subscription = std::shared_ptr<SubscriptionInternal>;


class SubscriptionContainer {
    private:
        std::vector<Subscription> subscriptions;

    public:
        SubscriptionContainer() = default;

        void add(const Subscription & subscription) {
            subscriptions.push_back(subscription);
        }

        void unsubscribe(const Subscription & subscription) {

            int indexToRemove = -1;

            for (int i = 0; i < subscriptions.size(); i++) {

                auto ptr1 = subscriptions[i].get();
                auto ptr2 = subscription.get();

                if (!ptr1 || !ptr2) continue;

                if (ptr1 == ptr2) {
                    indexToRemove = i;
                }
            }

            if (indexToRemove != -1) {
                subscriptions[indexToRemove]->Unsubscribe();
                subscriptions.erase(subscriptions.begin() + indexToRemove);
            }
        }

        void unsubscribeAll() {
            for (auto & s : subscriptions) {
                s->Unsubscribe();
            }

            subscriptions.clear();
        }
};