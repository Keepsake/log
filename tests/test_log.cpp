#include <cstdio>

#include <string>

#include <gtest/gtest.h>

#include <ks/log.hpp>

namespace {

class capture final
{
public:
  capture(std::FILE*& target) noexcept
    : target_(target)
    , origin_(target)
  {
    target_ = std::tmpfile();
  }

  ~capture() noexcept
  {
    std::fclose(target_);

    target_ = origin_;
  }

  std::string get() const noexcept
  {
    std::fflush(target_);

    std::string str;
    str.resize(std::ftell(target_));

    std::rewind(target_);

    std::fread(str.data(), 1U, str.size(), target_);

    return str;
  }

private:
  std::FILE*& target_;
  std::FILE* origin_;
};

} // namespace

TEST(LogTest, CanLogInfo)
{
  std::string captured;

  {
    capture c{ ks::log::out };
    ks::log::info("{} - {}\n", "test", 42);
    captured = c.get();
  }

  ASSERT_EQ(captured, "info: test - 42\n");
}

TEST(LogTest, CanLogWarning)
{
  std::string captured;

  {
    capture c{ ks::log::err };
    ks::log::warning("{} - {}\n", "test", 42);
    captured = c.get();
  }

  ASSERT_EQ(captured, "warning: test - 42\n");
}

TEST(LogTest, CanLogFatal)
{
  EXPECT_DEATH_IF_SUPPORTED(ks::log::fatal("{} - {}\n", "test", 42),
                            "fatal: test - 42");
}
