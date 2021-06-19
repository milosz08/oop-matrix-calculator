#include <iostream>
#include "../DiagonalMatrixPackage/DiagonalMatrix.h"

/*!
 * @overload Operator Mnożenia
 * @brief Przeciążenie operatora "*" (mnożenia) pod kątem przemnożenia wszystkich
 * elementów macierzy przez wartość skalarną.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrx - macierz, której elementy będą mnożone przez wartość skalara
 * @param scalar - wartość scalarna wprowadzana przez użytkownika
 * @return - macierz wynikowa (obiekt) po przemnożeniu przez skalar
 */
template<class M>
DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrx, const double& scalar) {
  DiagonalMatrix<M> mtrxScalar = DiagonalMatrix<M>{mtrx};
  for(unsigned int i = 0; i < mtrx.mtrxHeight; i++) {
    for(unsigned int j = 0; j < mtrx.mtrxWidth; j++) {
      if(i == j) {
        mtrxScalar.mtrx[i][j] = mtrx.diagTab[j] * scalar;
      } else {
        mtrxScalar.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxScalar;
}