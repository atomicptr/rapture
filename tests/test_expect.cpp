#include "../src/rapture.hpp"

int main() {
    auto a = 5;
    auto b = 7;

    // this expection is correct -> will continue
    rpt_expect(a + b == 12);

    // this expection is wrong -> hence the program will crash
    auto c = 2;
    rpt_expect(c + c == 5);

    return 0;
}
