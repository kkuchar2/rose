package com.kkucharski.rose;

class RxMath {
    private static final float EPSILON = 0.000001f;

    static boolean approximately(float a, float b)
    {
        float absA = Math.abs(a);
        float absB = Math.abs(b);
        float diff = Math.abs(a - b);

        if (a == b) {
            return true;
        }

        if (a == 0.0f || b == 0 || diff < EPSILON) {
            return diff < EPSILON;
        }

        return diff / (absA + absB) < EPSILON;
    }
}
