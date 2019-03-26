#pragma once

#include "Subscription.h"

using SubscriptionPtr = std::shared_ptr<Subscription>;

template<class T>
class ObservableBase {

    private:
        std::vector<ObserverPtr<T>> observerPtrs;
        T currentValue;

    protected:
        virtual bool equal(T t1, T t2);

    public:
        explicit ObservableBase(T initValue);
        T getValue();
        void setValue(T t);
        void emit(T t);
        SubscriptionPtr Subscribe(const ObserverPtr<T> & observerPtr);
        unsigned int getObserverCount();
        ~ObservableBase();
};


template<class T>
ObservableBase<T>::ObservableBase(T initValue) {
    currentValue = initValue;
}

template<class T>
T ObservableBase<T>::getValue() {
    return currentValue;
}

template<class T>
void ObservableBase<T>::setValue(T t) {
    if (equal(currentValue, t)) {
        return;
    }

    currentValue = t;
    emit(currentValue);
}

template<class T>
void ObservableBase<T>::emit(T t) {
    for (int i = 0; i < observerPtrs.size(); i++) {
        (*observerPtrs[i].get())(t);
    }
}

template<class T>
bool ObservableBase<T>::equal(T t1, T t2) {
    return t1 == t2;
}

template<typename T>
SubscriptionPtr ObservableBase<T>::Subscribe(const ObserverPtr<T> & observerPtr) {
    observerPtrs.push_back(observerPtr);

    for (auto & ptr : observerPtrs) {
        std::cout << "\t" << &observerPtrs << std::endl;
    }

    return std::make_shared<Subscription>([this, &observerPtr]() {
        Remove(observerPtrs, observerPtr);
    });
}

template<class T>
ObservableBase<T>::~ObservableBase() {
    for (int i = 0; i < observerPtrs.size(); i++) {
        Remove(observerPtrs, observerPtrs[i]);
    }
}

template<class T>
unsigned int ObservableBase<T>::getObserverCount() {
    return observerPtrs.size();
};