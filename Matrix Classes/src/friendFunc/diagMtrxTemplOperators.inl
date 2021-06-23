#include <iostream>
#include "../packages/diagonalMatrixPackage/DiagonalMatrix.hpp"

template<class M>
DiagonalMatrix<M> operator+(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxAdd = DiagonalMatrix<M>{mtrxF};

  for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
    mtrxAdd.diagTab[i] = mtrxF.diagTab[i] + mtrxS.diagTab[i];
    for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
      if(i == j) {
        mtrxAdd.mtrx[i][j] = mtrxAdd.diagTab[i];
      } else {
        mtrxAdd.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxAdd;
}


template<class M>
DiagonalMatrix<M> operator-(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxAdd = DiagonalMatrix<M>{mtrxF};

  for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
    mtrxAdd.diagTab[i] = mtrxF.diagTab[i] - mtrxS.diagTab[i];
    for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
      if(i == j) {
        mtrxAdd.mtrx[i][j] = mtrxAdd.diagTab[i];
      } else {
        mtrxAdd.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxAdd;
}


template<class M>
DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxAdd = DiagonalMatrix<M>{mtrxF};

  for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
    mtrxAdd.diagTab[i] = mtrxF.diagTab[i] * mtrxS.diagTab[i];
    for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
      if(i == j) {
        mtrxAdd.mtrx[i][j] = mtrxAdd.diagTab[i];
      } else {
        mtrxAdd.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxAdd;
}


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

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxScal = DiagonalMatrix<M>{mtrx};

  for(unsigned int i = 0; i < mtrx.mtrxHeight; i++) {
    mtrxScal.diagTab[i] = mtrx.diagTab[i] * scalar;
    for(unsigned int j = 0; j < mtrx.mtrxWidth; j++) {
      if(i == j) {
        mtrxScal.mtrx[i][j] = mtrxScal.diagTab[i];
      } else {
        mtrxScal.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxScal;
}