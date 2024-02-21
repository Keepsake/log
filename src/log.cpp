#include <ks/log.hpp>

#include <fmt/std.h>

#include <ks/fatal.hpp>

namespace ks::log {
namespace detail {

void
log(std::FILE* const output,
    char const* level,
    fmt::string_view format,
    fmt::format_args args) noexcept
{
  fmt::print(output, "{}: ", level);
  fmt::vprint(output, format, args);
}

void
log_and_panic(std::FILE* const output,
              char const* level,
              fmt::string_view format,
              fmt::format_args args) noexcept
{
  log(output, level, format, args);
  ks::fatal::panic();
}

} // namespace detail

std::FILE* out = stdout;
std::FILE* err = stderr;

} // namespace ks::log
