#ifndef PK_MATRIX_CALCULATOR_INTERFACEFUNC_H
#define PK_MATRIX_CALCULATOR_INTERFACEFUNC_H

#include "Auxiliary Functions/auxiliaryFunc.h"
#include "../MatrixAbstractPackage/MatrixAbstract.h"
#include "../GeneralMatrixPackage/GeneralMatrix.h"
#include "../DiagonalMatrixPackage/DiagonalMatrix.h"

#include <string>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>

using namespace matrixAbstractPackage; /** package klasy wirtualnej (bazowej) macierzy */
using namespace generalMatrixPackage; /** package klasy pochodnej (macierz standardowa) */
using namespace diagonalMatrixPackage; /** package klasy pochodnej (macierz diagonalna) */

void mainMenu(HANDLE& hOut);
unsigned int* setMtrxSize(HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType);
template<typename T> void mathGenrMatrix(GeneralMatrix<T>& obj, HANDLE& hOut);
template<typename T> void mathDiagMatrix(DiagonalMatrix<T>& obj, HANDLE& hOut);
unsigned int mathMtrxSquareMenu(HANDLE& hOut);
unsigned int mathMtrxRectglMenu(HANDLE& hOut);
void initMtrxObj(HANDLE& hOut);
void startPrg();

#endif
