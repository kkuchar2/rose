package com.kkuchar2.rose.properties;

import com.kkuchar2.rose.FloatingPointComparator;
import com.kkuchar2.rose.ObservableBase;

public class FloatProperty extends ObservableBase<Float> {

    public FloatProperty(float v) {
        super(v);
    }

    @Override
    protected boolean equal(Float f1, Float f2) {
        return FloatingPointComparator.approximately(f1, f2);
    }
}