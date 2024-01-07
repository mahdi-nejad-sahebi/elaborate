#ifndef ELB_FLOAT8_H_
#define ELB_FLOAT8_H_

#include <cstdint>
#include <cstdbool>

namespace elb
{
  constexpr float FLT8_MIN             = -128.0F;
  constexpr float FLT8_MAX             = +128.0F;
  constexpr float FLT8_RESOLUTION      = 2.0F;

  constexpr float FLT8_MIN_NORM        = -1.26F;
  constexpr float FLT8_MAX_NORM        = +1.26F;
  constexpr float FLT8_RESOLUTION_NORM = 0.02F;

  struct float8_t
  {
    float8_t();
    float8_t(const float& value);
    bool is_norm() const;
    // TODO(MN): is_nan()
    void compress(float _flt32);
    float decompress() const;

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

    operator float() const;
    operator uint64_t() const;
    operator int64_t() const;
    operator uint32_t() const;
    operator int32_t() const;
    operator uint16_t() const;
    operator int16_t() const;
    operator uint8_t() const;
    operator int8_t() const;
    operator char() const;
    operator bool() const;

    uint8_t m_num;
  };

  bool operator==(const float8_t& _flt8L, const float8_t& _flt8R);
  bool operator==(const float8_t& _flt8, const float& _flt32);
  bool operator==(const float& _flt32, const float8_t& _flt8);
  bool operator!=(const float8_t& _flt8_1, const float8_t& _flt8_2);
  bool operator!=(const float8_t& _flt8, const float& _flt32);
  bool operator!=(const float& _flt32, const float8_t& _flt8);
  bool operator<=(const float8_t& _flt8_1, const float8_t& _flt8_2);
  bool operator<=(const float8_t& _flt8, const float& _flt32);
  bool operator<=(const float& _flt32, const float8_t& _flt8);
  bool operator>=(const float8_t& _flt8_1, const float8_t& _flt8_2);
  bool operator>=(const float8_t& _flt8, const float& _flt32);
  bool operator>=(const float& _flt32, const float8_t& _flt8);
  bool operator< (const float8_t& _flt8_1, const float8_t& _flt8_2);
  bool operator< (const float8_t& _flt8, const float& _flt32);
  bool operator< (const float& _flt32, const float8_t& _flt8);
  bool operator> (const float8_t& _flt8_1, const float8_t& _flt8_2);
  bool operator> (const float8_t& _flt8, const float& _flt32);
  bool operator> (const float& _flt32, const float8_t& _flt8);

  bool operator==(const float8_t& flt8_value, const int& int_value);
  bool operator==(const int& int_value, const float8_t& flt8_value);
  bool operator!=(const float8_t& flt8_value, const int& int_value);
  bool operator!=(const int& int_value, const float8_t& flt8_value);
  bool operator<=(const float8_t& flt8_value, const int& int_value);
  bool operator<=(const int& int_value, const float8_t& flt8_value);
  bool operator< (const float8_t& flt8_value, const int& int_value);
  bool operator< (const int& int_value, const float8_t& flt8_value);
  bool operator>=(const float8_t& flt8_value, const int& int_value);
  bool operator>=(const int& int_value, const float8_t& flt8_value);
  bool operator> (const float8_t& flt8_value, const int& int_value);
  bool operator> (const int& int_value, const float8_t& flt8_value);
}

#endif /* ELB_FLOAT8_H_ */
