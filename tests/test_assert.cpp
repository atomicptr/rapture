#include "../src/rapture.hpp"

int main() {
    auto a = 5;
    auto b = 7;

    // this assertion is correct -> will continue
    rpt_assert(a + b == 12, "{} + {} should be {}", a, b, 12);

    // this assertion is wrong -> hence the program will crash
    auto c = 2;
    rpt_assert(c + c == 5, "{} + {} should be {}", c, c, 5);

    return 0;
}
