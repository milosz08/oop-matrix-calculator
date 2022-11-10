cmake_minimum_required(VERSION 3.19)
project(PK_Matrix_Calculator)

set(CMAKE_CXX_STANDARD 20)
add_executable(PK_Matrix_Calculator main.cpp "src/GeneralMatrix.hpp" "src/DiagonalMatrix.hpp" "src/StartPrg.cpp" "src/InterfaceDecl.hpp" "src/StartPrg.cpp" "src/InterfaceDecl.hpp" "src/MainMenu.cpp" "src/SetMtrxSize.cpp" "src/ChooseMtrxType.cpp" "src/ChooseNmbrType.cpp" "src/InitMtrxObj.cpp" "src/MathControl.tpp" "src/MathFirstChooseMtrx.tpp" "src/MathFirstMtrx.tpp" "src/MathSecondChooseMtrx.tpp" "src/MathSecondMtrx.tpp" "src/MatrixAbstract.tpp" "src/MatrixAbstract.hpp")

