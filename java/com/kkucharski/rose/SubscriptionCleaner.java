package com.kkucharski.rose;

import java.util.LinkedList;
import java.util.List;

public class SubscriptionCleaner {
    private final List<Subscription> subscriptions = new LinkedList<>();

    public void add(Subscription subscription) {
        subscriptions.add(subscription);
    }

    public void remove(Subscription subscription) {
        subscriptions.remove(subscription);
    }

    public void unsubscribe() {
        subscriptions.forEach(Subscription::unsubscribe);
    }
}
