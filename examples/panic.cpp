#include "../src/rapture.hpp"

int safeDiv(int a, int b) {
    if (b == 0) {
        panic("can't divide by zero");
    }

    return a / b;
}

int main() {
    std::println("{} / {} = {}", 10, 2, safeDiv(10, 2));
    std::println("{} / {} = {}", 10, 0, safeDiv(10, 0));
}
