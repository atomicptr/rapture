#include "../src/rapture.hpp"

enum class State {
    A,
    B,
    C // newly added
};

void print_state(State s) {
    switch (s) {
    case State::A:
        std::println("State::A");
        return;
    case State::B:
        std::println("State::B");
        return;
    default: // never added here though...
        unreachable();
    }
}

int main() {
    print_state(State::A);
    print_state(State::B);
    print_state(State::C);
}
