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

TEST(float8, storage)
{
  for (uint32_t test_index = 0; test_index < 1000000; test_index++) {
    const float f32 = random_norm(elb::float8::FLT8_MIN, elb::float8::FLT8_MAX);
//    Elb_F8_t const f8 = Elb_F8_Set(f32);
//    float const decomrpess32 = Elb_F8_Get(f8);
//    printf("%3.3u,  %+3.3" PRIi8 ", %+7.2f,  %+7.2f\n", num, (int8_t)num, f32, decomrpess32);

//    assert(decomrpess32 == f32);
    std::cout << f32 << std::endl;
  }
}


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

