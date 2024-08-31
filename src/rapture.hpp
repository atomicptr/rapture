#pragma once

#include <format>
#include <print>
#include <source_location>

#define assert(condition, ...)                                    \
    if (!(condition)) {                                           \
        auto rapture_loc = std::source_location::current();       \
        std::println("");                                         \
        std::println(                                             \
            "========= ASSERTATION FAILED {}:{}:{} =========",    \
            rapture_loc.file_name(),                              \
            rapture_loc.line(),                                   \
            rapture_loc.column()                                  \
        );                                                        \
        std::println("\tAssert :\t{}", (#condition));             \
        std::println("\tMessage:\t{}", std::format(__VA_ARGS__)); \
        std::println("");                                         \
        std::abort();                                             \
    }

#define panic(...)                                                                                                  \
    {                                                                                                               \
        auto rapture_loc = std::source_location::current();                                                         \
        std::println(                                                                                               \
            "========= PANIC {}:{}:{} =========", rapture_loc.file_name(), rapture_loc.line(), rapture_loc.column() \
        );                                                                                                          \
        std::println("\tMessage:\t{}", std::format(__VA_ARGS__));                                                   \
        std::println("");                                                                                           \
        std::abort();                                                                                               \
    }

#define unreachable() panic("Unreachable code executed!")
