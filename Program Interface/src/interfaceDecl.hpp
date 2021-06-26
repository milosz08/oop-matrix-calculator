#ifndef PK_MATRIX_CALCULATOR_INTERFACEDECL_HPP
#define PK_MATRIX_CALCULATOR_INTERFACEDECL_HPP

#include "../../Matrix Classes/src/packages/abstractMatrixPackage/MatrixAbstract.hpp"
#include "../../Matrix Classes/src/packages/generalMatrixPackage/GeneralMatrix.hpp"
#include "../../Matrix Classes/src/packages/diagonalMatrixPackage/DiagonalMatrix.hpp"

#include <string>
#include <stdlib.h>
#include <windows.h>
#include <winnt.h>



using namespace matrixAbstractPackage;  //package klasy wirtualnej (bazowej) macierzy
using namespace generalMatrixPackage;   //package klasy pochodnej (macierze standardowa)
using namespace diagonalMatrixPackage;  //package klasy pochodnej (macierze diagonalna)



//Deklaracje funkcji zawartych w folderze ../ProgramInterface/src
void startPrg();
void mainMenu(HANDLE& hOut);
void initMtrxObj(HANDLE& hOut);



//Deklaracje funkcji zawartych w folderze ../ProgramInterface/src/initObjects
std::string saveMtrxInfo(unsigned short int& type, unsigned short int& val);
unsigned short int chooseTypeOfMatrix(HANDLE& hOut);
unsigned short int chooseTypeOfNumbers(HANDLE& hOut);
unsigned short int* setMtrxSize(HANDLE& hOut, unsigned short int& mtrxType, unsigned short int& mtrxValType);



//Deklaracje funkcji zawartych w folderze ../ProgramInterface/src/mathOperations/mathFirstMtrx
template<typename T>
  unsigned short int mathChooseMtrx(MatrixAbstract<T>* obj, HANDLE& hOut);

template<typename T>
  void createMtrxObject(unsigned short int* sizeMtrx, HANDLE& hOut,
                        unsigned short int& mtrxType, unsigned short int& mtrxValType);

template<class M, class I, typename T>
  void onlyOneMtrxMath(unsigned short int& choose, MatrixAbstract<T>* ptr, M& obj, HANDLE& hOut,
                       unsigned short int& mtrxType, unsigned short int& mtrxValType);

template<class M, typename T>
  void onlyOneMtrxMathInfo(MatrixAbstract<T>* ptr, M& outObj, HANDLE& hOut, std::vector<std::string>infMess);



//Deklaracje funkcji zawartych w folderze ../ProgramInterface/src/mathOperations/mathSecondMtrx
template<typename T>
  unsigned short int mathSecondMatrix(MatrixAbstract<T>* objF, MatrixAbstract<T>* objS, HANDLE& hOut);

template<class M>
  void secondMtrxMath(unsigned short int& choose, M& objF, M& objS, HANDLE& hOut);

template<class M>
  void secondMtrxMathInfo(M& objF, M& objS, M& objFinal, HANDLE& hOut, std::vector<std::string>infMess);




#endif