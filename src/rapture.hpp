#pragma once

#include <format>
#include <print>
#include <source_location>

#define assert(condition, ...)                                                                                      \
    if (!(condition)) {                                                                                             \
        auto loc = std::source_location::current();                                                                 \
        std::println("");                                                                                           \
        std::println("========= ASSERTATION FAILED {}:{}:{} =========", loc.file_name(), loc.line(), loc.column()); \
        std::println("\tAssert :\t{}", (#condition));                                                               \
        std::println("\tMessage:\t{}", std::format(__VA_ARGS__));                                                   \
        std::println("");                                                                                           \
        std::abort();                                                                                               \
    }

#define panic(...)                                                                                     \
    {                                                                                                  \
        auto loc = std::source_location::current();                                                    \
        std::println("========= PANIC {}:{}:{} =========", loc.file_name(), loc.line(), loc.column()); \
        std::println("\tMessage:\t{}", std::format(__VA_ARGS__));                                      \
        std::println("");                                                                              \
        std::abort();                                                                                  \
    }

#define unreachable() panic("Unreachable code executed!")
