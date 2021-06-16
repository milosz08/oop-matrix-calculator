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
#include <array>

using namespace matrixAbstractPackage; /** package klasy wirtualnej (bazowej) macierzy */
using namespace generalMatrixPackage; /** package klasy pochodnej (macierz standardowa) */
using namespace diagonalMatrixPackage; /** package klasy pochodnej (macierz diagonalna) */

void startPrg();
void mainMenu(HANDLE& hOut);
void matrixMathInit(HANDLE& hOut);
void initMtrxObj(HANDLE& hOut);
unsigned int* setMtrxSize(HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType);
template<typename T>
unsigned int mathGenrMatrix(MatrixAbstract<T>* obj, HANDLE& hOut);
template<typename T>
void createMtrxObject(unsigned int* sizeMtrx, HANDLE& hOut, unsigned int& mtrxType);
template<typename T>
void mtrxMathInit(unsigned int& choose, MatrixAbstract<T>* obj, HANDLE& hOut);



#endif
