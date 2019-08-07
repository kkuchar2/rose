using System;
using System.Collections.Generic;

namespace Rose
{
    public class PropertyBase<T> : ObservableBase<T>
    {
        protected PropertyBase(T initValue) : base(initValue) { }
    }

    public class BooleanProperty : PropertyBase<bool>
    {
        public BooleanProperty(bool v) : base(v) { }

        protected override bool Equal(bool t1, bool t2)
        {
            return t1 == t2;
        }
    }
    
    public class EnumProperty<T> : PropertyBase<T> where T : struct, IConvertible
    {
        public EnumProperty(T v) : base(v) { }

        protected override bool Equal(T t1, T t2)
        {
            return EqualityComparer<T>.Default.Equals(t1, t2);
        }
    }
    
    public class FloatProperty : PropertyBase<float>
    {
        public FloatProperty(float v) : base(v) { }

        protected override bool Equal(float t1, float t2)
        {
            return RxMath.Approximately(t1, t2);
        }
    }
    
    public class IntegerProperty : PropertyBase<int>
    {
        public IntegerProperty(int v) : base(v) { }

        protected override bool Equal(int t1, int t2)
        {
            return t1 == t2;
        }
    }
    
    public class StringProperty : PropertyBase<string>
    {
        public StringProperty(string defaultValue) : base(defaultValue) { }

        protected override bool Equal(string t1, string t2)
        {
            return string.Compare(t1, t2) == 0;
        }
    }
    
    public class ObjectProperty : PropertyBase<object>
    {
        public ObjectProperty(object v) : base(v) { }

        protected override bool Equal(object t1, object t2)
        {
            return EqualityComparer<object>.Default.Equals(t1, t2);
        }
    }

    public class ObjectProperty<T> : PropertyBase<T> where T : class
    {
        public ObjectProperty(T t) : base(t) { }

        protected override bool Equal(T t1, T t2)
        {
            if ((t1 == null && t2 != null) || (t2 == null && t1 != null))
            {
                return false;
            }

            return EqualityComparer<T>.Default.Equals(t1, t2);
        }
    }
}