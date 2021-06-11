#include <iostream>
#include "DiagonalMatrix.h"
#include "../MatrixAbstractPackage/MatrixAbstract.h"

using namespace diagonalMatrixPackage;
using namespace matrixAbstractPackage;

/**
 * Konstruktor bezargumentowy wykorzystywany jedynie przy dziedziczeniu.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
DiagonalMatrix<M>::DiagonalMatrix() = default;

/**
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 * @brief Konstruktor jednoargumentowy alokujący pamięć dla tablicy dynamicznej przechowującej
 * elementy przekątnej macierzy diagonalnej. W liście inicializacyjnej przypisuje on konstruktorowi
 * klasy bazowej wartości przekazywane przez referencję (s -> s^2 - max elementów macierzy),
 * jako jednoczesną szerokość i wysokość macierzy diagonalnej (macierz kwadratowa).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param w - szerokość macierzy (ilość kolumn)
 * @param h - wysokość macierzy (ilośc wierszy)
 */
template<class M>
DiagonalMatrix<M>::DiagonalMatrix(unsigned int& s) : MatrixAbstract<M>{s, s} {
  this->diagTab = new M[this->mtrxWidth];
  mtrxTypeAndSizeInfo();
}

/**
 * @fn ~GeneralMatrix()
 * @brief Destruktor pełniący rolę odśmiecacza pamięci (manualny Garbage Collector).
 * Usuwa tablicę dynamiczną reprezentującą elementy macierzy diagonalnej (po przekątnej).
 */
template<class M>
DiagonalMatrix<M>::~DiagonalMatrix() {
  delete[] this->diagTab;
}

template class diagonalMatrixPackage::DiagonalMatrix<int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;