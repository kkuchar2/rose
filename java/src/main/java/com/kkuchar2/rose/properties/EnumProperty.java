package com.kkuchar2.rose.properties;


import com.kkuchar2.rose.ObservableBase;

public class EnumProperty<E extends Enum> extends ObservableBase<E> {

    public EnumProperty(E e) {
        super(e);
    }

    @Override
    protected boolean equal(E e1, E e2) {
        return e1 == e2;
    }
}