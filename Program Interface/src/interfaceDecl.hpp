#ifndef PK_MATRIX_CALCULATOR_INTERFACEDECL_HPP
#define PK_MATRIX_CALCULATOR_INTERFACEDECL_HPP

#include "../../Matrix Classes/src/packages/abstractMatrixPackage/MatrixAbstract.hpp"
#include "../../Matrix Classes/src/packages/generalMatrixPackage/GeneralMatrix.hpp"
#include "../../Matrix Classes/src/packages/diagonalMatrixPackage/DiagonalMatrix.hpp"

#include <string>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>
#include <type_traits>

using namespace matrixAbstractPackage; /** package klasy wirtualnej (bazowej) macierzy */
using namespace generalMatrixPackage; /** package klasy pochodnej (macierz standardowa) */
using namespace diagonalMatrixPackage; /** package klasy pochodnej (macierz diagonalna) */

void startPrg();
void mainMenu(HANDLE& hOut);
void initMtrxObj(HANDLE& hOut);

template<typename T>
void createMtrxObject(unsigned short int* sizeMtrx, HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType);

std::string saveMtrxInfo(unsigned int& type, unsigned int& val);
unsigned int chooseTypeOfMatrix(HANDLE& hOut);
unsigned int chooseTypeOfNumbers(HANDLE& hOut);

unsigned short int* setMtrxSize(HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType);

template<typename T>
unsigned int mathChooseMtrx(MatrixAbstract<T>* obj, HANDLE& hOut);

template<typename T>
unsigned int mathSecondMatrix(MatrixAbstract<T>* objF, MatrixAbstract<T>* objS, HANDLE& hOut);

template<class M, class I, typename T>
void onlyOneMtrxMath(unsigned int& choose, MatrixAbstract<T>* ptr, M& obj, HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType);

template<class M, typename T>
void onlyOneMtrxMathInfo(MatrixAbstract<T>* ptr, M& outObj, HANDLE& hOut, std::vector<std::string>infMess);

template<class M>
void secondMtrxMath(unsigned int& choose, M& objF, M& objS, HANDLE& hOut);

template<class M>
void secondMtrxMathInfo(M& objF, M& objS, M& objFinal, HANDLE& hOut, std::vector<std::string>infMess);

#endif