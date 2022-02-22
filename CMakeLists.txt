cmake_minimum_required(VERSION 3.19)
project(PK_Matrix_Calculator)

set(CMAKE_CXX_STANDARD 20)
add_executable(PK_Matrix_Calculator main.cpp "Matrix Classes/src/packages/generalMatrixPackage/GeneralMatrix.hpp" "Matrix Classes/src/packages/diagonalMatrixPackage/DiagonalMatrix.hpp" "Program Interface/src/startPrg.cpp" "Program Interface/src/interfaceDecl.hpp" "Program Interface/src/startPrg.cpp" "Program Interface/src/interfaceDecl.hpp" "Program Interface/src/mainMenu.cpp" "Program Interface/src/initObjects/setMtrxSize.cpp" "Program Interface/src/initObjects/chooseMtrxType.cpp" "Program Interface/src/initObjects/chooseNmbrType.cpp" "Program Interface/src/initObjects/initMtrxObj.cpp" "Program Interface/src/mathOperations/mathFirstMtrx/mathControl.tpp" "Program Interface/src/mathOperations/mathFirstMtrx/mathChooseMtrx.tpp" "Program Interface/src/mathOperations/mathFirstMtrx/mathMtrx.tpp" "Program Interface/src/mathOperations/mathSecondMtrx/mathChooseMtrx.tpp" "Program Interface/src/mathOperations/mathSecondMtrx/mathMtrx.tpp" "Matrix Classes/src/packages/abstractMatrixPackage/MatrixAbstract.tpp" "Matrix Classes/src/packages/abstractMatrixPackage/MatrixAbstract.hpp")

