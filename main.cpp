#include <iostream>
#include "MatrixAbstractPackage/MatrixAbstract.h"
#include "GeneralMatrixPackage/GeneralMatrix.h"
#include "DiagonalMatrixPackage/DiagonalMatrix.h"

using namespace matrixAbstractPackage; /** package klasy wirtualnej (bazowej) macierzy */
using namespace generalMatrixPackage; /** package klasy pochodnej (macierz standardowa) */
using namespace diagonalMatrixPackage; /** package klasy pochodnej (macierz diagonalna) */

int main() {

  unsigned int w = 2, h = 2;
  GeneralMatrix<double> m1{w, h};
  m1.insertMtrx();
  m1.printMtrx(true);

  GeneralMatrix<double> m2{w, h};
  m2.insertMtrx();
  m2.printMtrx(true);

  GeneralMatrix<double> m3 = m1 + m2;
  //m3.printMtrx();



  //DiagonalMatrix<double> m2{w};
  //m2.insertDiagElms();
  //m2.generateDiagMtrx(false);
  //m2.printMtrx();

  return 0;
}