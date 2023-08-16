#include "float8.hpp"

#include <iostream>

namespace elb
{
  float8_t::float8_t() : m_num(0)
  {
    
  }
   
  float8_t float8_t::operator=(const float& _num)
  {
    float8_t float8;
    return float8;
  }

  float8_t float8_t::operator=(const uint64_t& _num)
  {  
    float8_t float8;
    return float8;
  }
 
  float8_t float8_t::operator=(const int64_t& _num)
  {
    float8_t float8;
    return float8;
  }

  float8_t float8_t::operator=(const uint32_t& _num)
  {  
    float8_t float8;
    return float8;
  }
 
  float8_t float8_t::operator=(const int32_t& _num)
  {
    float8_t float8;
    return float8;
  }

  float8_t float8_t::operator=(const uint16_t& _num)
  {  
    float8_t float8;
    return float8;
  }
 
  float8_t float8_t::operator=(const int16_t& _num)
  {
    float8_t float8;
    return float8;
  }

  float8_t float8_t::operator=(const uint8_t& _num)
  {  
    float8_t float8;
    return float8;
  }
 
  float8_t float8_t::operator=(const int8_t& _num)
  {
    float8_t float8;
    return float8;
  }


  float8_t::operator float()
  {
    std::cout << "float() " << uint32_t(m_num) << std::endl;
    return float(m_num);
  }

  float8_t::operator uint64_t()
  {
    return m_num;
  }

  float8_t::operator int64_t()
  {
    return m_num;
  }

  float8_t::operator uint32_t()
  {
    return m_num;
  }

  float8_t::operator int32_t()
  {
    return m_num;
  }

  float8_t::operator uint16_t()
  {
    return m_num;
  }

  float8_t::operator int16_t()
  {
    return m_num;
  }

  float8_t::operator uint8_t()
  {
    return m_num;
  }

  float8_t::operator int8_t()
  {
    return m_num;
  }

  float8_t::operator char()
  {
    return m_num;
  }
}

