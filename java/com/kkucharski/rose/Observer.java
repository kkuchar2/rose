package com.kkucharski.rose;

public interface Observer<T> {
    void call(T t);
}
