#pragma once

#include "Subscription.h"
#include "Observer.h"

using Subscription = std::shared_ptr<SubscriptionInternal>;

template<class T>
class Observable {

    private:
        std::vector<Observer<T>> observerPtrs;
        T currentValue;

    protected:
        virtual bool equal(T t1, T t2);

    public:
        explicit Observable(T initValue);
        T getValue();
        void setValue(T t);
        void emit(T t);
        Subscription Subscribe(const Observer<T> & observerPtr);
        unsigned int getObserverCount();
        ~Observable();
};


template<class T>
Observable<T>::Observable(T initValue) {
    currentValue = initValue;
}

template<class T>
T Observable<T>::getValue() {
    return currentValue;
}

template<class T>
void Observable<T>::setValue(T t) {
    if (equal(currentValue, t)) {
        return;
    }

    currentValue = t;
    emit(currentValue);
}

template<class T>
void Observable<T>::emit(T t) {
    for (int i = 0; i < observerPtrs.size(); i++) {
        (*observerPtrs[i].get())(t);
    }
}

template<class T>
bool Observable<T>::equal(T t1, T t2) {
    return t1 == t2;
}

template<typename T>
Subscription Observable<T>::Subscribe(const Observer<T> & observerPtr) {
    observerPtrs.push_back(observerPtr);
    return std::make_shared<SubscriptionInternal>([this, &observerPtr]() {
        Remove(observerPtrs, observerPtr);
    });
}

template<class T>
Observable<T>::~Observable() {
    for (int i = 0; i < observerPtrs.size(); i++) {
        Remove(observerPtrs, observerPtrs[i]);
    }
}

template<class T>
unsigned int Observable<T>::getObserverCount() {
    return observerPtrs.size();
}