#include <iostream>
#include "MatrixAbstractPackage/MatrixAbstract.h"
#include "GeneralMatrixPackage/GeneralMatrix.h"
#include "DiagonalMatrixPackage/DiagonalMatrix.h"

using namespace matrixAbstractPackage; //package dla klasy wirtualnej (bazowej) macierzy
using namespace generalMatrixPackage; //package dla klasy pochodnej (macierz standardowa)
using namespace diagonalMatrixPackage; //package dla klasy pochodnej (macierz diagonalna)


int main() {

  unsigned int w = 2, h = 2;
  GeneralMatrix<double> m1{w, h};
  m1.insertMtrx();
  m1.printMatrix();

  //DiagonalMatrix<double> m2{w};
  //m2.insertDiagElms();
  //m2.generateDiagMtrx(false);
  //m2.insertMtrx();
  //m2.printMatrix();

  return 0;
}
