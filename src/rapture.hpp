#pragma once

#include <format>
#include <print>
#include <source_location>

#ifdef assert
    #ifndef RAPTURE_QUIET
        #warning "rapture: 'assert' is already defined and has been #undef'd"
    #endif
    #undef assert
#endif

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

#ifdef panic
    #ifndef RAPTURE_QUIET
        #warning "rapture: 'panic' is already defined and has been #undef'd"
    #endif
    #undef panic
#endif

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

#ifdef unreachable
    #ifndef RAPTURE_QUIET
        #warning "rapture: 'unreachable' is already defined and has been #undef'd"
    #endif
    #undef unreachable
#endif

#define unreachable()                                                                                 \
    {                                                                                                 \
        auto rapture_loc = std::source_location::current();                                           \
        std::println(                                                                                 \
            "========= UNREACHABLE CODE {}:{}:{} =========",                                          \
            rapture_loc.file_name(),                                                                  \
            rapture_loc.line(),                                                                       \
            rapture_loc.column()                                                                      \
        );                                                                                            \
        std::println("\tMessage:\tThis point was marked as unreachable, but was reached regardless"); \
        std::println("");                                                                             \
        std::abort();                                                                                 \
    }

#ifdef unimplemented
    #ifndef RAPTURE_QUIET
        #warning "rapture: 'unimplemented' is already defined and has been #undef'd"
    #endif
    #undef unimplemented
#endif

#define unimplemented()                                                   \
    {                                                                     \
        auto rapture_loc = std::source_location::current();               \
        std::println(                                                     \
            "========= UNIMPLEMENTED CODE {}:{}:{} =========",            \
            rapture_loc.file_name(),                                      \
            rapture_loc.line(),                                           \
            rapture_loc.column()                                          \
        );                                                                \
        std::println("\tMessage:\tThis feature is not yet implemented."); \
        std::println("");                                                 \
        std::abort();                                                     \
    }
