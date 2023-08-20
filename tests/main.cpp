#include <elb/numeric/float8.hpp>
#include <iostream>

using namespace elb;


  
int main()
{
  elb::float8_t f8;
  float f = 0;
  float fSrc = 0;
  
  fSrc = -5.78F;
  f8 = fSrc;
  f = f8;
  std::cout << "Main: " << fSrc << ", " << uint32_t(f8.m_num) << ", " << f << std::endl;

  fSrc = 0.08F;
  f8 = fSrc;
  f = f8;
  std::cout << "Main: " << fSrc << ", " << uint32_t(f8.m_num) << ", " << f << std::endl;

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

