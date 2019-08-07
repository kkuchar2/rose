namespace Rose
{
        public delegate void Observer();
        public delegate void Observer<T>(T t);
        public delegate void Observer<T, P>(T t, P p);
}