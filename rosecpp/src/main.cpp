#include "Rose/Properties.h"
#include "Rose/Observable.h"

int main() {
    IntegerProperty integerProperty(-1);

    Observer<int> observer = createObserver<int>(([](auto v) { println(v * 2.25236); }));

    Subscription subscription = integerProperty.Subscribe(observer);

    for (int i = 1; i <= 10; i++) {
        integerProperty.setValue(i);
    }

    std::cout << ">>> Before unsubscribe: " << integerProperty.getObserverCount() << std::endl;

    subscription->Unsubscribe();

    std::cout << ">>> After unsubscribe: " << integerProperty.getObserverCount() << std::endl;

    return 0;
}