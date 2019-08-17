package com.kkuchar2.rose;

public interface Observer<T> {
    void call(T t);
}