using System.Collections.Generic;

namespace Rose
{
    public class SubscriptionCleaner
    {
        private readonly List<Subscription> subscriptions = new List<Subscription>();

        public void Add(Subscription subscription)
        {
            subscriptions.Add(subscription);
        }

        public void Remove(Subscription subscription)
        {
            subscriptions.Remove(subscription);
        }

        public void Unsubscribe()
        {
            subscriptions.ForEach(s => s.Unsubscribe());
        }
    }
}