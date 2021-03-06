// ----------------------------------------------------------------- //
//             The Speech Signal Processing Toolkit (SPTK)           //
//             developed by SPTK Working Group                       //
//             http://sp-tk.sourceforge.net/                         //
// ----------------------------------------------------------------- //
//                                                                   //
//  Copyright (c) 1984-2007  Tokyo Institute of Technology           //
//                           Interdisciplinary Graduate School of    //
//                           Science and Engineering                 //
//                                                                   //
//                1996-2019  Nagoya Institute of Technology          //
//                           Department of Computer Science          //
//                                                                   //
// All rights reserved.                                              //
//                                                                   //
// Redistribution and use in source and binary forms, with or        //
// without modification, are permitted provided that the following   //
// conditions are met:                                               //
//                                                                   //
// - Redistributions of source code must retain the above copyright  //
//   notice, this list of conditions and the following disclaimer.   //
// - Redistributions in binary form must reproduce the above         //
//   copyright notice, this list of conditions and the following     //
//   disclaimer in the documentation and/or other materials provided //
//   with the distribution.                                          //
// - Neither the name of the SPTK working group nor the names of its //
//   contributors may be used to endorse or promote products derived //
//   from this software without specific prior written permission.   //
//                                                                   //
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            //
// CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       //
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          //
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          //
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS //
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          //
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   //
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     //
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON //
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   //
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    //
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           //
// POSSIBILITY OF SUCH DAMAGE.                                       //
// ----------------------------------------------------------------- //

#ifndef SPTK_QUANTIZER_INVERSE_UNIFORM_QUANTIZATION_H_
#define SPTK_QUANTIZER_INVERSE_UNIFORM_QUANTIZATION_H_

#include "SPTK/quantizer/uniform_quantization.h"
#include "SPTK/utils/sptk_utils.h"

namespace sptk {

class InverseUniformQuantization {
 public:
  //
  InverseUniformQuantization(
      double absolute_maximum_value, int num_bit,
      UniformQuantization::QuantizationType quantization_type);

  //
  virtual ~InverseUniformQuantization() {
  }

  //
  double GetAbsoluteMaximumValue() const {
    return absolute_maximum_value_;
  }

  //
  int GetNumBit() const {
    return num_bit_;
  }

  //
  UniformQuantization::QuantizationType GetQuantizationType() const {
    return quantization_type_;
  }

  //
  bool IsValid() const {
    return is_valid_;
  }

  //
  int GetQuantizationLevels() const {
    return quantization_levels_;
  }

  //
  bool Run(int input, double* output) const;

 private:
  //
  const double absolute_maximum_value_;

  //
  const int num_bit_;

  //
  const UniformQuantization::QuantizationType quantization_type_;

  //
  bool is_valid_;

  //
  int quantization_levels_;

  //
  double step_size_;

  //
  DISALLOW_COPY_AND_ASSIGN(InverseUniformQuantization);
};

}  // namespace sptk

#endif  // SPTK_QUANTIZER_INVERSE_UNIFORM_QUANTIZATION_H_
