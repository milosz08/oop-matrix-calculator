#include "../../DiagonalMatrix.hpp"


/*!
 * @overload Operator dodawania (+) - macierze diagonalne
 *
 * @brief Przeciążenie operatora "+" (dodawania) pod kątem dodania do
 *        siebie dwóch macierzy przekazywanych w argumentach funkcji.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxF - macierz pierwotna pierwsza.
 * @param mtrxS - macierz pierwotna druga.
 *
 * @return - macierz wynikowa (obiekt) po dodaniu do siebie macierzy diagonalnych.
 */
template<class M>
DiagonalMatrix<M> operator+(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxAdd = DiagonalMatrix<M>{mtrxF};

  for(unsigned short int i = 0; i < mtrxF.mtrxHeight; i++) {
    mtrxAdd.diagTab[i] = mtrxF.diagTab[i] + mtrxS.diagTab[i];
    for(unsigned short int j = 0; j < mtrxF.mtrxWidth; j++) {
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
 * @overload Operator odejmowania (-) - macierze diagonalne
 *
 * @brief Przeciążenie operatora "-" (odejmowania) pod kątem odjęcia od
 *        siebie dwóch macierzy przekazywanych w argumentach funkcji.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxF - macierz pierwotna pierwsza.
 * @param mtrxS - macierz pierwotna druga.
 *
 * @return - macierz wynikowa (obiekt) po odjęciu od siebie macierzy diagonalnych.
 */
template<class M>
DiagonalMatrix<M> operator-(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxAdd = DiagonalMatrix<M>{mtrxF};

  for(unsigned short int i = 0; i < mtrxF.mtrxHeight; i++) {
    mtrxAdd.diagTab[i] = mtrxF.diagTab[i] - mtrxS.diagTab[i];
    for(unsigned short int j = 0; j < mtrxF.mtrxWidth; j++) {
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
 * @overload Operator mnożenia (*) - macierze diagonalne
 *
 * @brief Przeciążenie operatora "*" (mnożenia) pod kątem przemnożenia przez
 *        siebie dwóch macierzy przekazywanych w argumentach funkcji.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxF - macierz pierwotna pierwsza.
 * @param mtrxS - macierz pierwotna druga.
 *
 * @return - macierz wynikowa (obiekt) po pomnożeniu obu macierzy diagonalnych przez siebie.
 */
template<class M>
DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxAdd = DiagonalMatrix<M>{mtrxF};

  for(unsigned short int i = 0; i < mtrxF.mtrxHeight; i++) {
    mtrxAdd.diagTab[i] = mtrxF.diagTab[i] * mtrxS.diagTab[i];
    for(unsigned short int j = 0; j < mtrxF.mtrxWidth; j++) {
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
 * @overload Operator mnożenia (*) - macierze diagonalne
 *
 * @brief Przeciążenie operatora "*" (mnożenia) pod kątem przemnożenia wszystkich
 *        elementów macierzy przez wartość skalarną.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrx - macierz, której elementy będą mnożone przez wartość skalara.
 * @param scalar - wartość scalarna wprowadzana przez użytkownika.
 *
 * @return - macierz wynikowa (obiekt) po przemnożeniu macierzy diagonalnej przez skalar.
 */
template<class M>
DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrx, const double& scalar) {

  /** Kopiowanie obiektu - kostruktor kopiujący */
  DiagonalMatrix<M> mtrxScal = DiagonalMatrix<M>{mtrx};

  for(unsigned short int i = 0; i < mtrx.mtrxHeight; i++) {
    mtrxScal.diagTab[i] = mtrx.diagTab[i] * scalar;
    for(unsigned short int j = 0; j < mtrx.mtrxWidth; j++) {
      if(i == j) {
        mtrxScal.mtrx[i][j] = mtrxScal.diagTab[i];
      } else {
        mtrxScal.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxScal;
}