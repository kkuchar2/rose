package com.kkucharski.rose;

import java.util.LinkedList;
import java.util.List;

public class ObservableBase<T> {
    private final List<Observer<T>> observers = new LinkedList<>();

    private T currentValue;

    protected ObservableBase() {
    }

    ObservableBase(T initValue) {
        currentValue = initValue;
    }

    public T getValue() {
        return currentValue;
    }

    public void setValue(T t) {
        if (equal(currentValue, t)) return;
        currentValue = t;
        emit(currentValue);
    }

    private void emit(T t) {
        observers.forEach(observer -> observer.call(t));
    }

    public Subscription addObserver(Observer<T> consumer) {
        observers.add(consumer);
        return new Subscription(() -> observers.remove(consumer));
    }

    protected boolean equal(T t1, T t2) {
        return false;
    }
}