#include <iostream>
#include "DiagonalMatrix.h"
#include "../GeneralMatrixPackage/GeneralMatrix.h"

using namespace diagonalMatrixPackage;
using namespace generalMatrixPackage;

template<class M>
DiagonalMatrix<M>::DiagonalMatrix() = default;

template<class M>
DiagonalMatrix<M>::DiagonalMatrix(unsigned int& size) : diagElm{size} {
  this->diagTab = new M[this->diagElm];
  GeneralMatrix<M>::allocateMemory();
}



template<class M>
DiagonalMatrix<M>::~DiagonalMatrix() {
  delete[] this->diagTab;
}

template class diagonalMatrixPackage::DiagonalMatrix<int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;