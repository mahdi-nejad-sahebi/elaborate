#include <elb/numeric/float8.hpp>
#include <iostream>

using namespace elb;

int main()
{
  elb::float8_t f8;
  
  f8 = 0.08F;
 std::cout << "Main- f8.m_num: " << (uint32_t)f8.m_num << std::endl << std::endl;
  
  float f= f8;
  std::cout << "\nf: " << f << std::endl << std::endl;

  
  bool b = false;
  b = (45.0F == f8);
  std::cout << "b: " << b << ", f: " << f << std::endl;
  b = (f8 == -0.08F);
  std::cout << "b: " << b << ", f: " << f << std::endl;
  b = (f8 == 0.08F);
  std::cout << "b: " << b << ", f: " << f << std::endl;


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

