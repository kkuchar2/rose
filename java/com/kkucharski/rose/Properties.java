package com.kkucharski.rose;

public class Properties {

    public static class BooleanProperty extends ObservableBase<Boolean> {
        public BooleanProperty(boolean v) {
            super(v);
        }

        @Override
        protected boolean equal(Boolean b1, Boolean b2) {
            return b1 == b2;
        }
    }

    public static class EnumProperty<E extends Enum> extends ObservableBase<E> {

        public EnumProperty(E e) {
            super(e);
        }

        @Override
        protected boolean equal(E e1, E e2) {
            return e1 == e2;
        }
    }

    public static class FloatProperty extends ObservableBase<Float> {

        public FloatProperty(float v) {
            super(v);
        }

        @Override
        protected boolean equal(Float f1, Float f2) {
            return RxMath.approximately(f1, f2);
        }
    }

    public static class IntegerProperty extends ObservableBase<Integer> {

        public IntegerProperty(int v) {
            super(v);
        }

        @Override
        protected boolean equal(Integer f1, Integer f2) {
            return f1.equals(f2);
        }
    }

    public static class StringProperty extends ObservableBase<String> {

        public StringProperty(String v) {
            super(v);
        }

        @Override
        protected boolean equal(String s1, String s2) {
            return s1.equals(s2);
        }
    }

    public static class ObjectProperty<T> extends ObservableBase<T> {

        public ObjectProperty(T t) {
            super(t);
        }

        @Override
        protected boolean equal(T t1, T t2) {
            return t1.equals(t2);
        }
    }
}
