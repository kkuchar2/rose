using System;

namespace Rose
{
    public class Subscription
    {
        private readonly Action unsubscribeAction;

        public Subscription(Action unsubscribeAction)
        {
            this.unsubscribeAction = unsubscribeAction;
        }

        public void Unsubscribe()
        {
            unsubscribeAction.Invoke();
        }
    }
}