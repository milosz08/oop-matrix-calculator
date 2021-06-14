#ifndef PK_MATRIX_CALCULATOR_INTERFACEFUNC_H
#define PK_MATRIX_CALCULATOR_INTERFACEFUNC_H

#include "Auxiliary Functions/auxiliaryFunc.h"
#include "../MatrixAbstractPackage/MatrixAbstract.h"
#include "../GeneralMatrixPackage/GeneralMatrix.h"
#include "../DiagonalMatrixPackage/DiagonalMatrix.h"

#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace matrixAbstractPackage; /** package klasy wirtualnej (bazowej) macierzy */
using namespace generalMatrixPackage; /** package klasy pochodnej (macierz standardowa) */
using namespace diagonalMatrixPackage; /** package klasy pochodnej (macierz diagonalna) */


void mainMenu();
void initialiseObjects();

unsigned int chooseTypeOfMatrix();
unsigned int chooseTypeOfNumbers();



void startPrg();

#endif
