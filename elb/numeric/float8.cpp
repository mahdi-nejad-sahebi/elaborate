#include "float8.hpp"
#include <cmath>

#include <iostream>
//  const funcitons and operations

typedef union __attribute__((aligned(1)))// extra
{
  uint8_t Mem;

  struct
  {
    uint8_t Man : 6;
    uint8_t Exp : 1;
    uint8_t Sgn : 1;
  }__attribute__((aligned(1)));
}Float8_t;

typedef union __attribute__((packed))//extra
{
  float Mem;

  struct
  {
    uint32_t Man : 23;
    uint8_t  Exp : 8;
    uint8_t  Sgn : 1;
  }__attribute__((packed));
}Float32_t;

constexpr uint8_t FLT8_NAN = 0xff;
constexpr uint8_t COEF     = 2;
constexpr float   END_NORM = (128.0F - (COEF * 63));



namespace elb
{
float8_t::float8_t() : m_num(0)
{

}

void float8_t::Compress(float _num)
{
  Float8_t f8 = {0};
  float numf = _num;
  Float32_t* const f32 = (Float32_t*)&numf;

  f8.Sgn = f32->Sgn;

  float const val = fabsf(numf);
  if (0.0F == val)
    f8.Sgn = 0;
  uint8_t const con = (val < END_NORM);

  if (con)
  {
    f8.Man = (uint8_t)(roundf(val * 100.0F) / COEF);
    f8.Exp = 0;
  }
  else
  {
    f8.Man = (uint8_t)roundf((val - END_NORM) / COEF);
    f8.Exp = 1;
  }

  if (1 == f8.Sgn)
  {
    f8.Man = ~f8.Man;
    f8.Exp = !f8.Exp;

   //if (FLT8_NAN == f8.Mem)
    //  f8.Mem = 0;
  }

  m_num = f8.Mem;
}

  float float8_t::Decompress() const
  {
    Float8_t f8 = {0};
    f8.Mem = m_num;
    Float32_t f32 = {0};

    if (1 == f8.Sgn)
    {
      f8.Man = ~f8.Man;
      f8.Exp = !f8.Exp;
    }

    uint8_t const con = (0 == f8.Exp);//!

    if (con)
    {
      f32.Mem = (roundf(f8.Man * COEF) / 100.0F);
    }
    else
    {
      f32.Mem = roundf((f8.Man * COEF) + END_NORM);
    }

    f32.Sgn = f8.Sgn;
    return f32.Mem;
  }


 
  float8_t& float8_t::operator=(const float& _num)
  {
    this->Compress(_num);
    return *this;
  }

  float8_t& float8_t::operator=(const uint64_t& _num)
  {
    return *this;
  }
 
  float8_t& float8_t::operator=(const int64_t& _num)
  {
    return *this;
  }

  float8_t& float8_t::operator=(const uint32_t& _num)
  {  
    return *this;
  }
 
  float8_t& float8_t::operator=(const int32_t& _num)
  {
    return *this;
  }

  float8_t& float8_t::operator=(const uint16_t& _num)
  {
    return *this;
  }
 
  float8_t& float8_t::operator=(const int16_t& _num)
  {
    return *this;
  }

  float8_t& float8_t::operator=(const uint8_t& _num)
  {  
    return *this;
  }
 
  float8_t& float8_t::operator=(const int8_t& _num)
  {
    return *this;
  }


  float8_t::operator float()
  {
    return Decompress();
  }

  float8_t::operator uint64_t()
  {
    return uint64_t(Decompress());
  }

  float8_t::operator int64_t()
  {
    return int64_t(Decompress());
  }

  float8_t::operator uint32_t()
  {
    return uint32_t(Decompress());
  }

  float8_t::operator int32_t()
  {
    return int32_t(Decompress());
  }

  float8_t::operator uint16_t()
  {
    return uint16_t(Decompress());
  }

  float8_t::operator int16_t()
  {
    return int16_t(Decompress());
  }

  float8_t::operator uint8_t()
  {
    return uint8_t(Decompress());
  }

  float8_t::operator int8_t()
  {
    return int8_t(Decompress());
  }

  float8_t::operator char()
  {
    return char(Decompress());
  }
 
  float8_t::operator bool()
  {
    return bool(Decompress());
  }
 
  
  bool operator==(const float8_t& _flt8, const float& _flt32)
  {
    return (_flt8.Decompress() == _flt32);
  }
  
  bool operator==(const float& _flt32, const float8_t& _flt8)
  {
    return (_flt8.Decompress() == _flt32);
  }
   
   
  bool operator!=(const float8_t& _flt8, const float& _flt32)
  {
    return (_flt8.Decompress() != _flt32);
  }
  
  bool operator!=(const float& _flt32, const float8_t& _flt8)
  {
    return (_flt8.Decompress() != _flt32);
  }
 
    
  bool operator<=(const float8_t& _flt8, const float& _flt32)
  {
    return (_flt8.Decompress() <= _flt32);
  }
  
  bool operator<=(const float& _flt32, const float8_t& _flt8)
  {
    return (_flt32 <= _flt8.Decompress());
  }
 
   
   
  bool operator>=(const float8_t& _flt8, const float& _flt32)
  {
    return (_flt8.Decompress() >= _flt32);
  }
  
  bool operator>=(const float& _flt32, const float8_t& _flt8)
  {
    return (_flt32 >= _flt8.Decompress());
  }
   
   
  bool operator<(const float8_t& _flt8, const float& _flt32)
  {
    return (_flt8.Decompress() < _flt32);
  }
  
  bool operator<(const float& _flt32, const float8_t& _flt8)
  {
    return (_flt32 < _flt8.Decompress());
  }
   
   
  bool operator>(const float8_t& _flt8, const float& _flt32)
  {
    return (_flt8.Decompress() > _flt32);
  }
  
  bool operator>(const float& _flt32, const float8_t& _flt8)
  {
    return (_flt32 > _flt8.Decompress());
  }
}
