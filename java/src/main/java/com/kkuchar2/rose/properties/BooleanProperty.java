package com.kkuchar2.rose.properties;

import com.kkuchar2.rose.ObservableBase;

public class BooleanProperty extends ObservableBase<Boolean> {

    public BooleanProperty(boolean v) {
        super(v);
    }

    @Override
    protected boolean equal(Boolean b1, Boolean b2) {
        return b1 == b2;
    }
}
