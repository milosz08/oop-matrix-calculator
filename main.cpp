#include <iostream>
#include "GeneralMatrixPackage/GeneralMatrix.h"
#include "DiagonalMatrixPackage/DiagonalMatrix.h"

using namespace generalMatrixPackage; //package dla klasy bazowej macierzy
using namespace diagonalMatrixPackage; //package dla klasy pochodnej (macierz diagonalna)

int main() {

  unsigned int w = 3, h = 3, s = 3;
  //GeneralMatrix<double> m1{w, h};
  //m1.mtrxTypeAndSizeInfo();
  //m1.insertMtrx();
  //m1.printMtrx();

  DiagonalMatrix<int> m2{s};
  m2.insertDiagElms();
  m2.printMtrx();

  return 0;
}
