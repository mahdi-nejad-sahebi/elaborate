#ifndef ELB_FLOAT8_H_
#define ELB_FLOAT8_H_

#include <cstdint>
#include <cstdbool>

namespace elb
{
  namespace float8
  {
    constexpr float FLT8_MIN = -128.0F;
    constexpr float FLT8_MAX = +128.0F;
    // TODO(MN): MIN/MAX NORM
  }

  struct float8_t
  {
    float8_t();
    void Compress(float _flt32);
    float Decompress() const;

    float8_t& operator=(const float& _float);
    float8_t& operator=(const uint64_t& _num);
    float8_t& operator=(const int64_t& _num);
    float8_t& operator=(const uint32_t& _num);
    float8_t& operator=(const int32_t& _num);
    float8_t& operator=(const uint16_t& _num);
    float8_t& operator=(const int16_t& _num);
    float8_t& operator=(const uint8_t& _num);
    float8_t& operator=(const int8_t& _num);
    float8_t& operator=(const char& _num);
    float8_t& operator=(const bool& _num);

    operator float();
    operator uint64_t();
    operator int64_t();
    operator uint32_t();
    operator int32_t();
    operator uint16_t();
    operator int16_t();
    operator uint8_t();
    operator int8_t();
    operator char();
    operator bool();

    bool operator==(const float8_t& _num);

    uint8_t m_num;
  };
  
  
  bool operator==(const float8_t& _flt8, const float& _flt32);
  bool operator==(const float& _flt32, const float8_t& _flt8);
  bool operator!=(const float8_t& _flt8, const float& _flt32);
  bool operator!=(const float& _flt32, const float8_t& _flt8);
  bool operator<=(const float8_t& _flt8, const float& _flt32);
  bool operator<=(const float& _flt32, const float8_t& _flt8);
  bool operator>=(const float8_t& _flt8, const float& _flt32);
  bool operator>=(const float& _flt32, const float8_t& _flt8);
  bool operator<(const float8_t& _flt8, const float& _flt32);
  bool operator<(const float& _flt32, const float8_t& _flt8);
  bool operator>(const float8_t& _flt8, const float& _flt32);
  bool operator>(const float& _flt32, const float8_t& _flt8);
} /* elb */

#endif /* ELB_FLOAT8_H_ */
