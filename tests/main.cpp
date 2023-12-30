#include <gtest/gtest.h>
#include <elb/numeric/float8.hpp>
#include <iostream>
#include <random>



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
  float number;
  elb::float8_t compressed_number;

  for (uint32_t test_index = 0; test_index < 1000000; test_index++) {
    number = random_norm(elb::float8::FLT8_MIN, elb::float8::FLT8_MAX);
    compressed_number = number;

    const bool is_normalized = (elb::float8::FLT8_MIN_NORM <= number) &&
                               (number <= elb::float8::FLT8_MAX_NORM);
    EXPECT_EQ(is_normalized, compressed_number.is_norm());
  }
}

//TEST(float8, storage)
//{
//  float number;
//  elb::float8_t compressed_number;

//  for (uint32_t test_index = 0; test_index < 1000000; test_index++) {
//    number = random_norm(elb::float8::FLT8_MIN, elb::float8::FLT8_MAX);
//    compressed_number = number;
//    const float decompressed_number = compressed_number;

//    const float error = fabsf(number - decompressed_number);
//    // TODO(MN): Add is_norm()
//    EXPECT_FLOAT_EQ(number, decompressed_number);
//  }
//}


int main()
{
  return RUN_ALL_TESTS();
  elb::float8_t f8;
//  float f = 0;
//  float fSrc = 0;
  
//  fSrc = -5.78F;
//  f8 = fSrc;
//  f = f8;
//  std::cout << "Main: " << fSrc << ", " << uint32_t(f8.m_num) << ", " << f << std::endl;

//  fSrc = 0.08F;
//  f8 = fSrc;
//  f = f8;
//  std::cout << "Main: " << fSrc << ", " << uint32_t(f8.m_num) << ", " << f << std::endl;

f8 = 76.54F;
elb::float8_t g8;
g8 = 76.54F; 
bool t1 = (f8 == g8);std::cout << "bool: " << t1 << ", " << float(f8) << std::endl;
f8 = 0.0F;
bool t2 = (f8 == g8);std::cout << "bool: " << t2 << ", " << float(f8) << std::endl;
  
  bool b = false;
  b = (45.0F < f8);std::cout << b << ", " << float(f8) << std::endl;
  b = (f8 < -0.08F);std::cout << b << ", " << float(f8) << std::endl;
  b = (f8 < 0.08F);std::cout << b << ", " << float(f8) << std::endl;


  if (elb::float8::FLT8_MIN == f8)
  {
    std::cout << "min\n";
  } 
  else if (elb::float8::FLT8_MAX == f8)
  {
    std::cout << "max\n";
  }
 // else if (elb::float8::FLT8_NAN == f8)
  //  x1++;
  

  std::cout << "Test Done" << std::endl;
  return 0;
}

