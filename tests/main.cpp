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

//TEST(float8, is_norm)
//{
//  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
//    const float float32 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
//    const elb::float8_t float8 = float32;

//    const bool is_normalized = (elb::FLT8_MIN_NORM <= float32) &&
//                               (float32 <= elb::FLT8_MAX_NORM);
//    EXPECT_EQ(is_normalized, float8.is_norm());
//  }
//}

//TEST(float8, read_write_sign)
//{
//  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
//    const float float32 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
//    const elb::float8_t float8 = float32;

//    EXPECT_EQ(0 == float32, 0 == float8);
//    EXPECT_EQ(0 != float32, 0 != float8);
//    EXPECT_EQ(0 <= float32, 0 <= float8);
//    EXPECT_EQ(0 <  float32, 0 <  float8);
//    EXPECT_EQ(0 >= float32, 0 >= float8);
//    EXPECT_EQ(0 >  float32, 0 >  float8);
//  }
//}

//TEST(float8, read_write)
//{
//  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
//    const float src_float32 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
//    const elb::float8_t compressed_number = src_float32;
//    const float decompressed_number = float(compressed_number);

//    const float error = fabsf(src_float32 - decompressed_number);
//    if (compressed_number.is_norm())
//      EXPECT_LE(error, elb::FLT8_RESOLUTION_NORM);
//    else
//      EXPECT_LE(error, elb::FLT8_RESOLUTION);
//  }
//}

//TEST(float8, oeprators_float8_by_float8)
//{
//  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
//    const float src_float32_1 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
//    const float src_float32_2 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);

//    const elb::float8_t float8_1 = src_float32_1;
//    const elb::float8_t float8_2 = src_float32_2;

//    const float float32_1 = float(float8_1);
//    const float float32_2 = float(float8_2);

//    EXPECT_EQ(float32_1 == float32_2, float8_1 == float8_2);
//    EXPECT_EQ(float32_1 != float32_2, float8_1 != float8_2);
//    EXPECT_EQ(float32_1 <  float32_2, float8_1 <  float8_2);
//    EXPECT_EQ(float32_1 <= float32_2, float8_1 <= float8_2);
//    EXPECT_EQ(float32_1 >  float32_2, float8_1 >  float8_2);
//    EXPECT_EQ(float32_1 >= float32_2, float8_1 >= float8_2);
//  }
//}


TEST(float8, oeprators_float8_by_float32)
{
  for (uint32_t test_index = 0; test_index < ITERATIONS_COUNT; test_index++) {
    const float src_float32_1 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);
    const float src_float32_2 = random_norm(elb::FLT8_MIN, elb::FLT8_MAX);

    const elb::float8_t float8_1 = src_float32_1;
    const elb::float8_t float8_2 = src_float32_2;

    const float float32_1 = float(float8_1);
    const float float32_2 = float(float8_2);

    EXPECT_EQ(float32_1 == float32_2, float8_1 == float32_2);
    EXPECT_EQ(float32_1 == float32_2, float8_2 == float32_1);
    EXPECT_EQ(float32_1 != float32_2, float8_1 != float32_2);
    EXPECT_EQ(float32_1 != float32_2, float8_2 != float32_1);
    EXPECT_EQ(float32_1 <  float32_2, float8_1 <  float32_2);
    EXPECT_EQ(float32_1 <  float32_2, float32_1 <  float8_2);
    EXPECT_EQ(float32_1 <= float32_2, float8_1 <= float32_2);
    EXPECT_EQ(float32_1 <= float32_2, float32_1 <= float8_2);
    EXPECT_EQ(float32_1 >  float32_2, float8_1 >  float32_2);
    EXPECT_EQ(float32_1 >  float32_2, float32_1 >  float8_2);
    EXPECT_EQ(float32_1 >= float32_2, float8_1 >= float32_2);
    EXPECT_EQ(float32_1 >= float32_2, float32_1 >= float8_2);
  }
}

int main()
{
   testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

