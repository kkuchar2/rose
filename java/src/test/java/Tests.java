import com.kkuchar2.rose.*;
import com.kkuchar2.rose.properties.IntegerProperty;
import org.junit.jupiter.api.Test;

import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Function;

class Tests {

    private static final int INITIAL_VALUE = 0;
    private static final int EXPECTED_VALUE = 8;

    private static final Function<Integer, String> expectedValueMessage
            = v -> "Value of test variable did not change from 0 to: " + v;

    private static final String observersNotEmptyMessage = "Event still contains observers";

    private AtomicInteger testValue = new AtomicInteger(INITIAL_VALUE);

    @Test
    void test_in_readme() {
        cleanTestState();

        IntegerProperty property = new IntegerProperty(0);

        Subscription subscription = property.addObserver(v -> System.out.println(v * 2.25236));

        for (int i = 0; i <= 5; i++) {
            property.setValue(i);
        }

        subscription.unsubscribe();

        assertObserversCount(property);
    }


    @Test
    void empty_event_test_emitting_number() {
        cleanTestState();

        SubscriptionContainer SC = new SubscriptionContainer();
        SimpleEvent event = new SimpleEvent();
        SC.addSubscription(event.addObserver(() -> testValue.set(EXPECTED_VALUE)));
        event.emit();
        SC.unsubscribe();

        assertExpectedValue();
        assertObserversCount(event);
    }

    @Test
    void test_number_property() {
        cleanTestState();

        SubscriptionContainer SC = new SubscriptionContainer();
        IntegerProperty property = new IntegerProperty(0);
        SC.addSubscription(property.addObserver(testValue::set));
        property.setValue(EXPECTED_VALUE);
        SC.unsubscribe();

        assertExpectedValue();
        assertObserversCount(property);
    }

    @Test
    void object_event_test_emitting_number() {
        cleanTestState();

        SubscriptionContainer SC = new SubscriptionContainer();
        Event<Integer> event = new Event<>();
        SC.addSubscription(event.addObserver(testValue::set));
        event.emit(EXPECTED_VALUE);
        SC.unsubscribe();

        assertExpectedValue();
        assertObserversCount(event);
    }

    private void cleanTestState() {
        testValue.set(INITIAL_VALUE);
    }

    private void assertExpectedValue() {
        assert(testValue.get() == EXPECTED_VALUE) : expectedValueMessage.apply(EXPECTED_VALUE);
    }

    private void assertObserversCount(Event event) {
        assert(event.getObserverCount() == 0) : observersNotEmptyMessage;
    }

    private void assertObserversCount(SimpleEvent event) {
        assert(event.getObserverCount() == 0) : observersNotEmptyMessage;
    }

    private <T> void assertObserversCount(ObservableBase<T> observable) {
        assert(observable.getObserverCount() == 0) : observersNotEmptyMessage;
    }
}