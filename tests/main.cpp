#include <iostream>
#include <random>
#include <gtest/gtest.h>
#include <elb/numeric/float8.hpp>



constexpr uint32_t ITERATIONS_COUNT = 10000000;

static float random_norm(const float min, const float max)
{
  static std::random_device rd;
  static std::mt19937 gen(rd());

  std::uniform_int_distribution<> dist(0, 10000);
  const float norm_random = (dist(gen) / 10000.0F);

  return (min + (max - min) * norm_random);
}

TEST(float8, is_norm)
{
  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
    const float number = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
    const elb::float8_t compressed_number = number;

    const bool is_normalized = (elb::FLT8_MIN_NORM <= number) &&
                               (number <= elb::FLT8_MAX_NORM);
    EXPECT_EQ(is_normalized, compressed_number.is_norm());
  }
}

TEST(float8, read_write)
{
  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
    const float number = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
    const elb::float8_t compressed_number = number;
    const float decompressed_number = float(compressed_number);

    const float error = fabsf(number - decompressed_number);
    if (compressed_number.is_norm())
      EXPECT_FLOAT_EQ(elb::FLT8_RESOLUTION_NORM, error);
    else
      EXPECT_FLOAT_EQ(elb::FLT8_RESOLUTION, error);
  }
}

TEST(float8, oeprators_float8_by_float8)
{
  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
    float float32_1 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
    float float32_2 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);

    const elb::float8_t float8_1 = float32_1;
    const elb::float8_t float8_2 = float32_2;

    float32_1 = float(float8_1);
    float32_2 = float(float8_2);

    EXPECT_EQ(float32_1 == float32_2, float8_1 == float8_2);
    EXPECT_EQ(float32_1 != float32_2, float8_1 != float8_2);
    EXPECT_EQ(float32_1 <  float32_2, float8_1 <  float8_2);
    EXPECT_EQ(float32_1 <= float32_2, float8_1 <= float8_2);
    EXPECT_EQ(float32_1 >  float32_2, float8_1 >  float8_2);
    EXPECT_EQ(float32_1 >= float32_2, float8_1 >= float8_2);
  }
}


TEST(float8, oeprators_float8_by_float32)
{
  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
    float float32_1 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
    float float32_2 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);

    const elb::float8_t float8_1 = float32_1;
    const elb::float8_t float8_2 = float32_2;

    float32_1 = float(float8_1);
    float32_2 = float(float8_2);

    EXPECT_EQ(float32_1 == float32_2, float8_1 == float32_1);
    EXPECT_EQ(float32_1 != float32_2, float8_1 != float32_1);
    EXPECT_EQ(float32_1 <  float32_2, float8_1 <  float32_1);
    EXPECT_EQ(float32_1 <= float32_2, float8_1 <= float32_1);
    EXPECT_EQ(float32_1 >  float32_2, float8_1 >  float32_1);
    EXPECT_EQ(float32_1 >= float32_2, float8_1 >= float32_1);

    EXPECT_EQ(float32_1 == float32_2, float32_1 == float8_1);
    EXPECT_EQ(float32_1 != float32_2, float32_1 != float8_1);
    EXPECT_EQ(float32_1 <  float32_2, float32_1 <  float8_1);
    EXPECT_EQ(float32_1 <= float32_2, float32_1 <= float8_1);
    EXPECT_EQ(float32_1 >  float32_2, float32_1 >  float8_1);
    EXPECT_EQ(float32_1 >= float32_2, float32_1 >= float8_1);
  }
}

int main()
{
  return RUN_ALL_TESTS();
  return 0;
}
