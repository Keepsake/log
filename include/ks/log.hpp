#pragma once

#include <cstdio>

#include <fmt/core.h>

namespace ks::log {

extern std::FILE* out;
extern std::FILE* err;

namespace detail {

void
log(std::FILE* const output,
    char const* level,
    fmt::string_view format,
    fmt::format_args args) noexcept;

[[noreturn]] void
log_and_panic(std::FILE* const output,
              char const* level,
              fmt::string_view format,
              fmt::format_args args) noexcept;

}

template<typename... Args>
constexpr void
info(fmt::format_string<Args...> format, Args&&... args) noexcept
{
  detail::log(out, "info", format, fmt::make_format_args(args...));
}

template<typename... Args>
constexpr void
warning(fmt::format_string<Args...> format, Args&&... args) noexcept
{
  detail::log(err, "warning", format, fmt::make_format_args(args...));
}

template<typename... Args>
[[noreturn]] constexpr void
fatal(fmt::format_string<Args...> format, Args&&... args) noexcept
{
  detail::log_and_panic(
      err, "fatal", format, fmt::make_format_args(args...));
}

} // namespace ks::log
