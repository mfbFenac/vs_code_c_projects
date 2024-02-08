#include <stdio.h>

// Enumeration for the states
enum DoorState {
        LOCKED,
        UNLOCKED,
        OPENING
};

// Enumeration for the events
enum DoorEvent {
        LOCK,
        UNLOCK,
        OPEN
};

// Function to handle state transitions
enum DoorState transition(enum DoorState currentState, enum DoorEvent event)
{
        switch (currentState) {
                case LOCKED:
                        switch (event) {
                                case UNLOCK:
                                        return UNLOCKED;
                                default:
                                        return LOCKED;
                        }

                case UNLOCKED:
                        switch (event) {
                                case LOCK:
                                        return LOCKED;
                                case OPEN:
                                        return OPENING;
                                default:
                                        return UNLOCKED;
                        }

                case OPENING:
                        switch (event) {
                                case LOCK:
                                        return LOCKED;
                                default:
                                        return OPENING;
                        }

                default:
                        return currentState;
        }
}

int main() 
{
        // Initial state
        enum DoorState currentState = LOCKED;

        // Example of transitions
        currentState = transition(currentState, UNLOCK);
        printf("Current State: %d\n", currentState);  // Output: 1 (UNLOCKED)

        currentState = transition(currentState, OPEN);
        printf("Current State: %d\n", currentState);  // Output: 2 (OPENING)

        currentState = transition(currentState, LOCK);
        printf("Current State: %d\n", currentState);  // Output: 0 (LOCKED)

        return 0;
}
