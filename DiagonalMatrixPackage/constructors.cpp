#include <iostream>
#include "DiagonalMatrix.h"

using namespace diagonalMatrixPackage;

template<class M>
DiagonalMatrix<M>::DiagonalMatrix() {
  std::cout << "Konstruktor z klasy DiagonalMatrix\n";
}

template<class M>
DiagonalMatrix<M>::DiagonalMatrix(unsigned int& size) : mtrxSize{size} {
  this->diagElms = new M[this->mtrxSize];
}



template<class M>
DiagonalMatrix<M>::~DiagonalMatrix() {
  delete[] this->diagElms;
}

template class diagonalMatrixPackage::DiagonalMatrix<int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;