#include <iostream>
#include "GeneralMatrix.h"
#include "../MatrixAbstractPackage/MatrixAbstract.h"

using namespace generalMatrixPackage;
using namespace matrixAbstractPackage;

/**
 * @fn GeneralMatrix()
 * Konstruktor bezargumentowy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix() = default;

/**
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 * @brief Konstruktor dwuargumentowy. Wywoływany dla macierzy prostokątnych. Wywołuje
 * konstruktor z klasy abstrakcyjnej oraz wyświetla informacje na temat wprowadzanej macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param w - szerokość macierzy (ilość kolumn)
 * @param h - wysokość macierzy (ilośc wierszy)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned int& w, unsigned int& h) : MatrixAbstract<M>{w, h} {
  mtrxTypeAndSizeInfo();
}

/**
 * @fn GeneralMatrix(unsigned int & s)
 * @brief Konstruktor jednoargumentowy. Wywoływany dla macierzy kwadratowych. Wywołuje
 * konstruktor z klasy abstrakcyjnej oraz wyświetla informacje na temat wprowadzanej macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param s - wysokość oraz szerokość macierzy (ilośc kolumn oraz ilość wierszy)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned int & s) : MatrixAbstract<M>{s, s} {
  mtrxTypeAndSizeInfo();
}

/**
 * @fn GeneralMatrix(const GeneralMatrix& mtrxCopy)
 * Konstruktor kopiujący. Wywołuje konstruktor z klasy abstrakcyjnej, który kopiuje zawartość objektu.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrxCopy - kopia obiektu przekazywana przez referencję
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(const GeneralMatrix& mtrxCopy) : MatrixAbstract<M>{mtrxCopy} {}

/**
 * @fn ~GeneralMatrix()
 * @brief Destruktor domyślny. Rolę odśmiecania pamięci
 * przejmuje destruktor z klasy abstrakcyjnej.
 */
template<class M>
GeneralMatrix<M>::~GeneralMatrix() = default;

template class generalMatrixPackage::GeneralMatrix<int>;
template class generalMatrixPackage::GeneralMatrix<double>;