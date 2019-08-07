using System;

namespace Rose
{
    public static class RxMath
    {
        private const float EPSILON = float.Epsilon;

        public static bool Approximately(float a, float b)
        {
            var absA = Math.Abs(a);
            var absB = Math.Abs(b);
            var diff = Math.Abs(a - b);

            if (a == b)
            {
                return true;
            }
            if (a == 0.0f || b == 0 || diff < EPSILON)
            {
                return diff < EPSILON;
            }

            return diff / (absA + absB) < EPSILON;
        }

        public static float Abs(float f)
        {
            return Math.Abs(f);
        }
    }
}