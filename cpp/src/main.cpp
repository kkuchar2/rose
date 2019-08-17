#include "Rose/Property/IntegerProperty.h"

int main() {

    // Define observable

    IntegerProperty integerProperty(0);

    // Define observer

    Observer<int> observer = createObserver<int>(([](auto v) { println(v * 2.25236); }));

    // Subscribe to observable change and register subscription

    Subscription subscription = integerProperty.Subscribe(observer);

    // Change value of observable

    for (int i = 0; i <= 5; i++) {
        integerProperty.setValue(i);
    }

    // Unsubscribe at the end

    subscription->Unsubscribe();

    return 0;
}