#include <iostream>
#include "GeneralMatrixPackage/GeneralMatrix.h"
#include "DiagonalMatrixPackage/DiagonalMatrix.h"

using namespace generalMatrixPackage; //package dla klasy bazowej macierzy
using namespace diagonalMatrixPackage; //package dla klasy pochodnej (macierz diagonalna)

int main() {

  unsigned int w = 6, h = 6, s = 6;
  //GeneralMatrix<double> m1{w, h};
  //m1.mtrxTypeAndSizeInfo();
  //m1.insertMtrx();
  //m1.printMtrx();

  DiagonalMatrix<double> m2{w, h};
  m2.insertDiagElms();
  m2.generateDiagMtrx(false);
  //m2.insertMtrx();
  m2.printMtrx();

  return 0;
}
