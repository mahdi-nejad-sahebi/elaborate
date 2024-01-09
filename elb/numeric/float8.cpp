#include "float8.hpp"
#include <cmath>


union float8
{
  uint8_t memory;

  struct
  {
    uint8_t mantisa  : 6;
    uint8_t exponent : 1;
    uint8_t sign     : 1;
  }__attribute__((packed));
};

union float32
{
  float memory;

  struct
  {
    uint32_t mantisa  : 23;
    uint8_t  exponent : 8;
    uint8_t  sign     : 1;
  }__attribute__((packed));
};

constexpr uint8_t FLT8_NAN = 0xff;
constexpr uint8_t COEF     = 2;
constexpr float   END_NORM = (128.0F - (COEF * 63));



namespace elb
{

float8_t::float8_t() : m_num(0)
{

}

float8_t::float8_t(const float& value)
{
  compress(value);
}

bool float8_t::is_norm() const
{
  const float magnitude = fabsf(decompress());
  return (magnitude <= FLT8_MAX_NORM);
}

void float8_t::compress(float value)
{
  union float8 f8 = {0};
  float numf = value;
  union float32* const f32 = (union float32*)&numf;

  f8.sign = f32->sign;

  const float magnitude = fabsf(numf);
  if (0.0F == magnitude)
    f8.sign = 0;

  const bool is_in_norm_range = (magnitude < elb::FLT8_MAX_NORM);

 if (is_in_norm_range) {
    f8.mantisa = (uint8_t)(roundf(magnitude * 100.0F) / COEF);
    f8.exponent = 0;
  } else {
    f8.mantisa = (uint8_t)roundf((magnitude - END_NORM) / COEF);
    f8.exponent = 1;
  }

  if (1 == f8.sign) {
    f8.mantisa = ~f8.mantisa;
    f8.exponent = !f8.exponent;
  }

  m_num = f8.memory;
}

  float float8_t::decompress() const
  {
    union float8 f8 = {0};
    f8.memory = m_num;
    union float32 f32 = {0};

    if (1 == f8.sign) {
      f8.mantisa = ~f8.mantisa;
      f8.exponent = !f8.exponent;
    }

    if (0 == f8.exponent)
      f32.memory = (roundf(f8.mantisa * COEF) / 100.0F);
    else
      f32.memory = roundf((f8.mantisa * COEF) + END_NORM);

    f32.sign = f8.sign;
    return f32.memory;
  }


 
  float8_t& float8_t::operator=(const float& number)
  {
    this->compress(number);
    return *this;
  }

  float8_t& float8_t::operator=(const uint64_t& number)
  {
    this->compress(float(number));
    return *this;
  }
 
  float8_t& float8_t::operator=(const int64_t& number)
  {
    this->compress(float(number));
    return *this;
  }

  float8_t& float8_t::operator=(const uint32_t& number)
  {
    this->compress(float(number));
    return *this;
  }
 
  float8_t& float8_t::operator=(const int32_t& number)
  {
    this->compress(float(number));
    return *this;
  }

  float8_t& float8_t::operator=(const uint16_t& number)
  {
    this->compress(float(number));
    return *this;
  }
 
  float8_t& float8_t::operator=(const int16_t& number)
  {
    this->compress(float(number));
    return *this;
  }

  float8_t& float8_t::operator=(const uint8_t& number)
  {
    this->compress(float(number));
    return *this;
  }
 
  float8_t& float8_t::operator=(const int8_t& number)
  {
    this->compress(float(number));
    return *this;
  }

  float8_t& float8_t::operator=(const bool& number)
  {
    this->compress(float(number));
    return *this;
  }


  float8_t::operator float() const
  {
    return decompress();
  }

  float8_t::operator uint64_t() const
  {
    return uint64_t(decompress());
  }

  float8_t::operator int64_t() const
  {
    return int64_t(decompress());
  }

  float8_t::operator uint32_t() const
  {
    return uint32_t(decompress());
  }

  float8_t::operator int32_t() const
  {
    return int32_t(decompress());
  }

  float8_t::operator uint16_t() const
  {
    return uint16_t(decompress());
  }

  float8_t::operator int16_t() const
  {
    return int16_t(decompress());
  }

  float8_t::operator uint8_t() const
  {
    return uint8_t(decompress());
  }

  float8_t::operator int8_t() const
  {
    return int8_t(decompress());
  }

  float8_t::operator char() const
  {
    return char(decompress());
  }
 
  float8_t::operator bool() const
  {
    return bool(decompress());
  }


  bool operator==(const float8_t& flt8_1, const float8_t& flt8_2)
  {
    return (flt8_1.m_num == flt8_2.m_num);
  }

  bool operator==(const float8_t& flt8, const float& float32)
  {
    return (flt8.decompress() == float32);
  }
  
  bool operator==(const float& float32, const float8_t& flt8)
  {
    return (flt8.decompress() == float32);
  }
   

  bool operator!=(const float8_t& flt8_1, const float8_t& flt8_2)
  {
    return (flt8_1.m_num != flt8_2.m_num);
  }

  bool operator!=(const float8_t& flt8, const float& float32)
  {
    return (flt8.decompress() != float32);
  }
  
  bool operator!=(const float& float32, const float8_t& flt8)
  {
    return (flt8.decompress() != float32);
  }
 

  bool operator<=(const float8_t& flt8_1, const float8_t& flt8_2)
  {
    return (flt8_1.decompress() <= flt8_2.decompress());
  }

  bool operator<=(const float8_t& flt8, const float& float32)
  {
    return (flt8.decompress() <= float32);
  }
  
  bool operator<=(const float& float32, const float8_t& flt8)
  {
    return (float32 <= flt8.decompress());
  }
 
   
  bool operator>=(const float8_t& flt8_1, const float8_t& flt8_2)
  {
    return (flt8_1.decompress() >= flt8_2.decompress());
  }

  bool operator>=(const float8_t& flt8, const float& float32)
  {
    return (flt8.decompress() >= float32);
  }

  bool operator>=(const float& float32, const float8_t& flt8)
  {
    return (float32 >= flt8.decompress());
  }
   

  bool operator<(const float8_t& flt8_1, const float8_t& flt8_2)
  {
    return (flt8_1.decompress() < flt8_2.decompress());
  }

  bool operator<(const float8_t& flt8, const float& float32)
  {
    return (flt8.decompress() < float32);
  }
  
  bool operator<(const float& float32, const float8_t& flt8)
  {
    return (float32 < flt8.decompress());
  }
   

  bool operator>(const float8_t& flt8_1, const float8_t& flt8_2)
  {
    return (flt8_1.decompress() > flt8_2.decompress());
  }

  bool operator>(const float8_t& flt8, const float& float32)
  {
    return (flt8.decompress() > float32);
  }
  
  bool operator>(const float& float32, const float8_t& flt8)
  {
    return (float32 > flt8.decompress());
  }


  bool operator==(const float8_t& flt8_value, const int& int_value)
  {
    return (flt8_value.decompress() == int_value);
  }

  bool operator==(const int& int_value, const float8_t& flt8_value)
  {
    return (int_value == flt8_value.decompress());
  }

  bool operator!=(const float8_t& flt8_value, const int& int_value)
  {
    return (flt8_value.decompress() != int_value);
  }

  bool operator!=(const int& int_value, const float8_t& flt8_value)
  {
    return (int_value != flt8_value.decompress());
  }

  bool operator<=(const float8_t& flt8_value, const int& int_value)
  {
    return (flt8_value.decompress() <= int_value);
  }

  bool operator<=(const int& int_value, const float8_t& flt8_value)
  {
    return (int_value <= flt8_value.decompress());
  }

  bool operator<(const float8_t& flt8_value, const int& int_value)
  {
    return (flt8_value.decompress() < int_value);
  }

  bool operator<(const int& int_value, const float8_t& flt8_value)
  {
    return (int_value < flt8_value.decompress());
  }

  bool operator>=(const float8_t& flt8_value, const int& int_value)
  {
    return (flt8_value.decompress() >= int_value);
  }

  bool operator>=(const int& int_value, const float8_t& flt8_value)
  {
    return (int_value >= flt8_value.decompress());
  }

  bool operator>(const float8_t& flt8_value, const int& int_value)
  {
    return (flt8_value.decompress() > int_value);
  }

  bool operator>(const int& int_value, const float8_t& flt8_value)
  {
    return (int_value > flt8_value.decompress());
  }

}
