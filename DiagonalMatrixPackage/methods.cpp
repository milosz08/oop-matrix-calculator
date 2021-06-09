#include <iostream>
#include "DiagonalMatrix.h"

using namespace diagonalMatrixPackage;

template<class M>
void DiagonalMatrix<M>::insertDiagElms() {
  std::cout << "\nPodaj elementy macierzy diagonalnej (po przekatnej):\n";
  for(unsigned int i = 0; i < this->diagElm; i++) {
    std::cin >> this->diagTab[i];
  }
}

template class diagonalMatrixPackage::DiagonalMatrix<int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;