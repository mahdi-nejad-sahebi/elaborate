#ifndef ELB_FLOAT8_H_
#define ELB_FLOAT8_H_

/** \page float8
 * This module has been implemented for floating-ponit
 * 8-bit which can be used for temperatures, humidity,
 * normalized values, percentage, int8_t, etc.
 * Is compatible with floating-point 754.
 *
 * \section Data Representation
 *
 * |     +Norm      |    -Un-Norm    |     -Norm      |     +Un-Norm   |
 * |----------------|----------------|----------------|----------------|
 * |  +2.00  +66.00 |-128.00  -64.00 |  -1.26   -0.62 |  +0.00   +0.64 |
 * |  +4.00  +68.00 |-126.00  -62.00 |  -1.24   -0.60 |  +0.02   +0.66 |
 * |  +6.00  +70.00 |-124.00  -60.00 |  -1.22   -0.58 |  +0.04   +0.68 |
 * |  +8.00  +72.00 |-122.00  -58.00 |  -1.20   -0.56 |  +0.06   +0.70 |
 * | +10.00  +74.00 |-120.00  -56.00 |  -1.18   -0.54 |  +0.08   +0.72 |
 * | +12.00  +76.00 |-118.00  -54.00 |  -1.16   -0.52 |  +0.10   +0.74 |
 * | +14.00  +78.00 |-116.00  -52.00 |  -1.14   -0.50 |  +0.12   +0.76 |
 * | +16.00  +80.00 |-114.00  -50.00 |  -1.12   -0.48 |  +0.14   +0.78 |
 * | +18.00  +82.00 |-112.00  -48.00 |  -1.10   -0.46 |  +0.16   +0.80 |
 * | +20.00  +84.00 |-110.00  -46.00 |  -1.08   -0.44 |  +0.18   +0.82 |
 * | +22.00  +86.00 |-108.00  -44.00 |  -1.06   -0.42 |  +0.20   +0.84 |
 * | +24.00  +88.00 |-106.00  -42.00 |  -1.04   -0.40 |  +0.22   +0.86 |
 * | +26.00  +90.00 |-104.00  -40.00 |  -1.02   -0.38 |  +0.24   +0.88 |
 * | +28.00  +92.00 |-102.00  -38.00 |  -1.00   -0.36 |  +0.26   +0.90 |
 * | +30.00  +94.00 |-100.00  -36.00 |  -0.98   -0.34 |  +0.28   +0.92 |
 * | +32.00  +96.00 | -98.00  -34.00 |  -0.96   -0.32 |  +0.30   +0.94 |
 * | +34.00  +98.00 | -96.00  -32.00 |  -0.94   -0.30 |  +0.32   +0.96 |
 * | +36.00 +100.00 | -94.00  -30.00 |  -0.92   -0.28 |  +0.34   +0.98 |
 * | +38.00 +102.00 | -92.00  -28.00 |  -0.90   -0.26 |  +0.36   +1.00 |
 * | +40.00 +104.00 | -90.00  -26.00 |  -0.88   -0.24 |  +0.38   +1.02 |
 * | +42.00 +106.00 | -88.00  -24.00 |  -0.86   -0.22 |  +0.40   +1.04 |
 * | +44.00 +108.00 | -86.00  -22.00 |  -0.84   -0.20 |  +0.42   +1.06 |
 * | +46.00 +110.00 | -84.00  -20.00 |  -0.82   -0.18 |  +0.44   +1.08 |
 * | +48.00 +112.00 | -82.00  -18.00 |  -0.80   -0.16 |  +0.46   +1.10 |
 * | +50.00 +114.00 | -80.00  -16.00 |  -0.78   -0.14 |  +0.48   +1.12 |
 * | +52.00 +116.00 | -78.00  -14.00 |  -0.76   -0.12 |  +0.50   +1.14 |
 * | +54.00 +118.00 | -76.00  -12.00 |  -0.74   -0.10 |  +0.52   +1.16 |
 * | +56.00 +120.00 | -74.00  -10.00 |  -0.72   -0.08 |  +0.54   +1.18 |
 * | +58.00 +122.00 | -72.00   -8.00 |  -0.70   -0.06 |  +0.56   +1.20 |
 * | +60.00 +124.00 | -70.00   -6.00 |  -0.68   -0.04 |  +0.58   +1.22 |
 * | +62.00 +126.00 | -68.00   -4.00 |  -0.66   -0.02 |  +0.60   +1.24 |
 * | +64.00 +128.00 | -66.00   -2.00 |  -0.64   -0.00 |  +0.62   +1.26 |
 */

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
    void compress(float value);
    float decompress() const;

    float8_t& operator=(const float& number);
    float8_t& operator=(const uint64_t& number);
    float8_t& operator=(const int64_t& number);
    float8_t& operator=(const uint32_t& number);
    float8_t& operator=(const int32_t& number);
    float8_t& operator=(const uint16_t& number);
    float8_t& operator=(const int16_t& number);
    float8_t& operator=(const uint8_t& number);
    float8_t& operator=(const int8_t& number);
    float8_t& operator=(const char& number);
    float8_t& operator=(const bool& number);

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

  bool operator==(const float8_t& flt8_1, const float8_t& flt8_2);
  bool operator==(const float8_t& flt8, const float& float32);
  bool operator==(const float& float32, const float8_t& flt8);
  bool operator!=(const float8_t& flt8_1, const float8_t& flt8_2);
  bool operator!=(const float8_t& flt8, const float& float32);
  bool operator!=(const float& float32, const float8_t& flt8);
  bool operator<=(const float8_t& flt8_1, const float8_t& flt8_2);
  bool operator<=(const float8_t& flt8, const float& float32);
  bool operator<=(const float& float32, const float8_t& flt8);
  bool operator>=(const float8_t& flt8_1, const float8_t& flt8_2);
  bool operator>=(const float8_t& flt8, const float& float32);
  bool operator>=(const float& float32, const float8_t& flt8);
  bool operator< (const float8_t& flt8_1, const float8_t& flt8_2);
  bool operator< (const float8_t& flt8, const float& float32);
  bool operator< (const float& float32, const float8_t& flt8);
  bool operator> (const float8_t& flt8_1, const float8_t& flt8_2);
  bool operator> (const float8_t& flt8, const float& float32);
  bool operator> (const float& float32, const float8_t& flt8);

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
