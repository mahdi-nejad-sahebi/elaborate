#ifndef ELB_FLOAT8_H_
#define ELB_FLOAT8_H_

#include <cstdint>
#include <cstdbool>

namespace elb
{
  namespace float8
  {
    constexpr int8_t MIN = -128;
    constexpr int8_t MAX = +128;
    constexpr int8_t NAN = 0xff;
  }

  struct float8_t
  {
    float8_t();

    float8_t operator=(const float& _float);
    float8_t operator=(const uint64_t& _num);
    float8_t operator=(const int64_t& _num);
    float8_t operator=(const uint32_t& _num);
    float8_t operator=(const int32_t& _num);
    float8_t operator=(const uint16_t& _num);
    float8_t operator=(const int16_t& _num);
    float8_t operator=(const uint8_t& _num);
    float8_t operator=(const int8_t& _num);
    float8_t operator=(const char& _num);

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

    int8_t m_num;
  };
}

#endif // ELB_FLOAT8_H_
