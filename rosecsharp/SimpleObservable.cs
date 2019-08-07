using System.Collections.Generic;

namespace Rose
{
    public class SimpleObservableBase<Q>
    {
        protected readonly List<Q> observers = new List<Q>();
        
        public Subscription AddObserver(Q consumer)
        {
            observers.Add(consumer);
            return new Subscription(() => observers.Remove(consumer));
        }
    }
    
    public class SimpleObservable<T> : SimpleObservableBase<Observer<T>>
    {
        public void Emit(T t)
        {
            observers.ForEach(listener => listener.Invoke(t));
        }
    }

    public class SimpleObservable : SimpleObservableBase<Observer>
    {
        public void Emit()
        {
            observers.ForEach(listener => listener.Invoke());
        }
    }
}