package com.kkucharski.rose;

import com.kkucharski.rose.Properties.*;

public class Main {

    public static void main(String[] args) {
        SubscriptionCleaner SC = new SubscriptionCleaner();

        FloatProperty fp = new FloatProperty(0.0f);

        SC.add(fp.addObserver(System.out::println));

        for (int i = 0 ; i < 10; i++) {
            fp.setValue((float) i);
        }

        SC.unsubscribe();
    }
}
