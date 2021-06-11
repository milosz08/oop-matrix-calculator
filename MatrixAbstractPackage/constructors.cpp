#include <iostream>
#include "MatrixAbstract.h"

using namespace matrixAbstractPackage;

template<class M>
MatrixAbstract<M>::MatrixAbstract() = default;

template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned int& w, unsigned int& h) : mtrxWidth{w}, mtrxHeight{h} {
  allocateMemory();
}

template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned int& s) : mtrxWidth{s}, mtrxHeight{s} {
  allocateMemory();
}

template<class M>
MatrixAbstract<M>::MatrixAbstract(const MatrixAbstract& c) : mtrxWidth{c.mtrxWidth}, mtrxHeight{c.mtrxHeight} {
  this->mtrx = new M* [c.mtrxHeight];
  for(unsigned int i = 0; i < c.mtrxHeight; i++) {
    this->mtrx[i] = new M [c.mtrxWidth];
  }
}

template<class M>
MatrixAbstract<M>::~MatrixAbstract() {
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    delete[] this->mtrx[i];
  }
  delete[] this->mtrx;
}

template class matrixAbstractPackage::MatrixAbstract<int>;
template class matrixAbstractPackage::MatrixAbstract<double>;