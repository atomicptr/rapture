# rapture

A tiny single file header only assertion library for C++23

This library makes use of std::print, std::format and std::source_location so make sure your compiler supports this!

## Provides

- assert(condition, message) - If the condition fails, crashes the program with message
- expect(condition) - Assert but without message
- panic(message) - Crashes the program with message
- unreachable() - Crashes the program with message, used to make sure unreachable code sections will not be run
- unimplemented() - Crashes the program with message, used to mark certain code paths as unimplemented

See How to use section or examples

## Install

Just copy the file into your project and adjust accordingly

## How to use

<details>
<summary>Example: assert</summary>

```cpp
int main() {
    auto a = 5;
    auto b = 7;

    // this assertion is correct -> will continue
    assert(a + b == 12, "{} + {} should be {}", a, b, 12);

    // this assertion is wrong -> hence the program will crash
    auto c = 2;
    assert(c + c == 5, "{} + {} should be {}", c, c, 5);

    return 0;
}
```

</details>

<details>
<summary>Example: expect</summary>

```cpp
int main() {
    auto a = 5;
    auto b = 7;

    // this expection is correct -> will continue
    expect(a + b == 12);

    // this expection is wrong -> hence the program will crash
    auto c = 2;
    expect(c + c == 5);

    return 0;
}
```

</details>

<details>
<summary>Example: panic</summary>

```cpp
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
````

</details>

<details>
<summary>Example: unreachable</summary>

```cpp
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
````

</details>

<details>
<summary>Example: unimplemented</summary>

```cpp
void solve_every_problem_in_the_universe() {
    unimplemented();
}

int main(void) {
    solve_every_problem_in_the_universe();
}
````

</details>

## License

BSD 0-Clause
