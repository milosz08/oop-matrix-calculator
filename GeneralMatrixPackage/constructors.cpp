#include <iostream>
#include "GeneralMatrix.h"
#include "../MatrixAbstractPackage/MatrixAbstract.h"

using namespace generalMatrixPackage;
using namespace matrixAbstractPackage;

/**
 * Konstruktor bezargumentowy wykorzystywany jedynie przy dziedziczeniu.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix() = default;

/**
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 * @brief Konstruktor dwuargumentowy przypisany wywoływaniu funkcji alokującej pamięć
 * dla macierzy prostokątnej (o różnych wymiarach).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param w - szerokość macierzy (ilość kolumn)
 * @param h - wysokość macierzy (ilośc wierszy)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned int& w, unsigned int& h) : MatrixAbstract<M>{w, h} {
  mtrxTypeAndSizeInfo();
}

/**
 * @fn GeneralMatrix(unsigned int & size)
 * @brief Konstruktor jednoargumentowy przypisany wywoływaniu funkcji alokującej pamięć
 * dla macierzy kwadratowej (o takich samych wymiarach).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param s - wysokość oraz szerokość macierzy (ilośc kolumn oraz ilość wierszy)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned int & s) : MatrixAbstract<M>{s, s} {
  mtrxTypeAndSizeInfo();
}

/**
 * @fn GeneralMatrix(const GeneralMatrix& mtrxCopy)
 * Konstruktor kopiujący (używany głównie przy kopiowaniu macierzy podczas wykonywania operacji)
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrxCopy - kopia obiektu przekazywana przez referencję
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(const GeneralMatrix& mtrxCopy) : MatrixAbstract<M>{mtrxCopy} {}

/**
 * @fn ~GeneralMatrix()
 * @brief Destruktor pełniący rolę odśmiecacza pamięci (manualny Garbage Collector).
 * Usuwa tablice dynamiczne reprezentujące wiersze macierzy oraz tablicę wskaźników
 * które wskazują na w/w tablice dynamiczne reprezentującą ilość wierszy w macierzy.
 */
template<class M>
GeneralMatrix<M>::~GeneralMatrix() = default;

template class generalMatrixPackage::GeneralMatrix<int>;
template class generalMatrixPackage::GeneralMatrix<double>;