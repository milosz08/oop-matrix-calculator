#include <iostream>
#include "DiagonalMatrix.h"
#include "../GeneralMatrixPackage/GeneralMatrix.h"

using namespace diagonalMatrixPackage;

template<class M>
DiagonalMatrix<M>::DiagonalMatrix() = default;

template<class M>
DiagonalMatrix<M>::DiagonalMatrix(unsigned int& width, unsigned int& height)
: generalMatrixPackage::GeneralMatrix<M>{width, height}, diagElm{width} {
  this->diagTab = new M[this->diagElm];
}

template<class M>
DiagonalMatrix<M>::~DiagonalMatrix() {
  delete[] this->diagTab;
}

template class diagonalMatrixPackage::DiagonalMatrix<int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;