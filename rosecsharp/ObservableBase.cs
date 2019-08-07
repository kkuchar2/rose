using System.Collections.Generic;

namespace Rose
{
    public class ObservableBase<T>
    {
        private readonly List<Observer<T>> observers = new List<Observer<T>>();

        private T currentValue;

        protected ObservableBase() { }

        protected ObservableBase(T initValue)
        {
            currentValue = initValue;
        }

        public T Value
        {
            get => currentValue;
            set
            {
                if (Equal(currentValue, value)) return;
                currentValue = value;
                Emit(currentValue);
            }
        }

        private void Emit(T t)
        {
            observers.ForEach(listener => listener.Invoke(t));
        }

        public Subscription AddObserver(Observer<T> consumer)
        {
            observers.Add(consumer);
            return new Subscription(() => observers.Remove(consumer));
        }

        protected virtual bool Equal(T t1, T t2) { return false; }
    }
}