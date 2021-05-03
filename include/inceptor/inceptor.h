/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#ifndef INCLUDE_INCEPTOR_INCEPTOR_H_
#define INCLUDE_INCEPTOR_INCEPTOR_H_

#include "core/core.h"
#include "global_defs/global_defs.h"

namespace bfs {

/* Config for a single inceptor */
struct InceptorChannel {
  int8_t ch;
  int8_t num_coef;
  float poly_coeff[MAX_POLY_COEF_SIZE];
};
/* Inceptor config */
struct InceptorConfig {
  HardwareSerial *hw;
  int32_t sampling_period_ms;
  InceptorChannel throttle_en;
  InceptorChannel mode0;
  InceptorChannel mode1;
  InceptorChannel mode2;
  InceptorChannel throttle;
  InceptorChannel pitch;
  InceptorChannel roll;
  InceptorChannel yaw;
};
/* Inceptor data */
struct InceptorData {
  bool new_data;
  bool healthy;
  bool throttle_en;
  int8_t mode0;
  int8_t mode1;
  int8_t mode2;
  float throttle;
  float pitch;
  float roll;
  float yaw;
};
/* Concept defining an inceptor interface */
template<typename T>
concept Inceptor = requires(T inceptor,
                            const InceptorConfig &cfg,
                            InceptorData * const data) {
  { inceptor.Init(cfg) } -> std::same_as<bool>;
  { inceptor.Read(data) } -> std::same_as<bool>;
};  // NOLINT - gets confused with concepts and semicolon after braces

}  // namespace bfs

#endif  // INCLUDE_INCEPTOR_INCEPTOR_H_
