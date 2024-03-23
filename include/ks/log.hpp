#pragma once

#include <cstdio>

#include <fmt/core.h>

#include <ks/log/detail/symbol_visibility.hpp>

namespace ks::log {

KS_LOG_EXPORT extern std::FILE* out;
KS_LOG_EXPORT extern std::FILE* err;

namespace detail {

void KS_LOG_EXPORT
log(std::FILE* const output,
    char const* level,
    fmt::string_view format,
    fmt::format_args args) noexcept;

[[noreturn]] void KS_LOG_EXPORT
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
