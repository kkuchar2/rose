package com.kkuchar2.rose.properties;

import com.kkuchar2.rose.FloatingPointComparator;
import com.kkuchar2.rose.ObservableBase;

public class DoubleProperty extends ObservableBase<Double> {

    public DoubleProperty(double v) {
        super(v);
    }

    @Override
    protected boolean equal(Double d1, Double d2) {
        return FloatingPointComparator.approximately(d1, d1);
    }
}