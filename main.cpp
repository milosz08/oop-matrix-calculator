#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include "MatrixAbstractPackage/MatrixAbstract.h"
#include "GeneralMatrixPackage/GeneralMatrix.h"
#include "DiagonalMatrixPackage/DiagonalMatrix.h"

using namespace matrixAbstractPackage; /** package klasy wirtualnej (bazowej) macierzy */
using namespace generalMatrixPackage; /** package klasy pochodnej (macierz standardowa) */
using namespace diagonalMatrixPackage; /** package klasy pochodnej (macierz diagonalna) */


int main() {
  std::setlocale(LC_ALL, "polish");
  unsigned int test;

  HANDLE hOut;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  //SetConsoleTextAttribute( hOut, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED );
  //std::cout << "\n  ====================================================================\n";
  //std::cout << "        Zażółć gęślą jaźńmacierzy napisanym w obiektowym C++\n";
  //std::cout << "  ====================================================================\n";
  //SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
  //std::cout << "Aby przejsc dalej, wybierz opcje!\n";

 // std::system("pause");
  //std::system("cls");

  unsigned int w = 4, h = 4;


  GeneralMatrix<double> m1{w, h};
  m1.insertMtrx();
  m1.printMtrx(true);

  //std::cout << m1 << std::endl;

  //GeneralMatrix<double> m3 = (m1);


  //std::system("pause");
  //std::system("cls");

  //GeneralMatrix<double> m2{w, h};
  //m2.insertMtrx();
  //m2.printMtrx(true);



  //double scalar = m1.scalarValuePush();


  //GeneralMatrix<double> m3 = m1 * m2;
  //m3.printMtrx(true);

  //DiagonalMatrix<double> m2{w};
  //m2.insertDiagElms();
  //m2.generateDiagMtrx(false);
  //m2.printMtrx();

  //std::system("pause");

  return 0;

}