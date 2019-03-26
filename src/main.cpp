#include "Properties.h"

int main() {
    IntegerProperty integerProperty = IntegerProperty(-1);

    std::shared_ptr<Observer<int>> observerPtr = std::make_shared<Observer<int>>(([](auto newValue) {
        println(newValue * 2.25236);
    }));

    std::shared_ptr<Subscription> subscription = integerProperty.Subscribe(observerPtr);

    for (int i = 1; i <= 10; i++) {
        integerProperty.setValue(i);
    }

    std::cout << ">>> Before unsubscribe: " << integerProperty.getObserverCount() << std::endl;

    subscription->Unsubscribe();

    std::cout << ">>> After unsubscribe: " << integerProperty.getObserverCount() << std::endl;

    return 0;
}