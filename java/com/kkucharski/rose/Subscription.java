package com.kkucharski.rose;

public class Subscription {
    private final Action unsubscribeAction;

    public Subscription(Action unsubscribeAction)
    {
        this.unsubscribeAction = unsubscribeAction;
    }

    public void unsubscribe()
    {
        unsubscribeAction.call();
    }
}
