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

#include "inceptor/inceptor.h"

/* Example class compliant with the inceptor interface */
class InceptorExample {
 public:
  bool Init(const bfs::InceptorConfig &cfg) {}
  bool Read(bfs::InceptorData * const data) {}
};
/* Using static_assert to check compliance */
static_assert(bfs::Inceptor<InceptorExample>,
  "Inceptor Example should be compliant with the Inceptor interface");
/* Example of a function templated against the Inceptor interface */
template<bfs::Inceptor T>
bool InitInceptor(T inceptor, const bfs::InceptorConfig &ref) {
  return inceptor.Init(ref);
}

int main() {

}
