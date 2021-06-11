#include <iostream>
#include "../GeneralMatrixPackage/GeneralMatrix.h"

/**
 * @overload Operator Dodawania
 * @brief Przeciążenie operatora "+" (dodawania) dodającego do siebie dwie macierze.
 * Funkcja posiada walidację obliczanych macierzy (jeśli nie mają tych samych rozmiarów - błąd).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrxF - pierwsza dodawana macierz
 * @param mtrxS - druga dodawana macierz
 * @return - macierz wynikowa (obiekt) po dodaniu
 */
template<class M>
GeneralMatrix<M> operator+(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS) {
  GeneralMatrix<M> mtrxAdd = GeneralMatrix<M>{mtrxF}; /** Kopiowanie macierzy */
  try {
    if(mtrxF.mtrxWidth == mtrxS.mtrxWidth && mtrxF.mtrxHeight == mtrxS.mtrxHeight) {
      for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
        for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
          mtrxAdd.mtrx[i][j] = mtrxF.mtrx[i][j] + mtrxS.mtrx[i][j];
        }
      }
      std::cout << "\nWlasnie dodalem do siebie dwie podane przez Ciebie macierze.\n";
      std::cout << "Z dodanych do siebie macierzy powstala macierz potomna:\n";
      mtrxAdd.printMtrx(false);
    } else {
      throw std::logic_error("badMtrxsSize");
    }
  }
  catch(std::logic_error) {
    std::cout << "\nError! Niedozwolona operacja!\n";
    std::cout << "Dodanie do siebie dwoch macierzy roznych rozmiarow nie jest mozliwe!\n";
  }
  return mtrxAdd;
}

/**
 * @overload Operator Odejmowania
 * @brief Przeciążenie operatora "-" (odejmowania) odejmującego od siebie dwie macierze.
 * Funkcja posiada walidację obliczanych macierzy (jeśli nie mają tych samych rozmiarów - błąd).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrxF - pierwsza odejmowana macierz
 * @param mtrxS - druga odejmowana macierz
 * @return - macierz wynikowa (obiekt) po odjęciu
 */
template<class M>
GeneralMatrix<M> operator-(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS) {
  GeneralMatrix<M> mtrxSubt = GeneralMatrix<M>{mtrxF}; /** Kopiowanie macierzy */
  try {
    if(mtrxF.mtrxWidth == mtrxS.mtrxWidth && mtrxF.mtrxHeight == mtrxS.mtrxHeight) {
      for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
        for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
          mtrxSubt.mtrx[i][j] = mtrxF.mtrx[i][j] - mtrxS.mtrx[i][j];
        }
      }
      std::cout << "\nWlasnie odjalem od siebie dwie podane przez Ciebie macierze.\n";
      std::cout << "Z odjetych od siebie macierzy powstala macierz potomna:\n";
      mtrxSubt.printMtrx(false);
    } else {
      throw std::logic_error("badMtrxsSize");
    }
  }
  catch(std::logic_error) {
    std::cout << "\nError! Niedozwolona operacja!\n";
    std::cout << "Odjecie od siebie dwoch macierzy roznych rozmiarow nie jest mozliwe!\n";
  }
  return mtrxSubt;
}

/**
 *
 * @tparam M
 * @param mtrx
 * @param scalar - wartość scalarna wprowadzana przez użytkownika
 * @return
 */
template<class M>
GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrx, double& scalar) {
  GeneralMatrix<M> mtrxScalar = GeneralMatrix<M>{mtrx}; /** Kopiowanie macierzy */
  for(unsigned int i = 0; i < mtrx.mtrxHeight; i++) {
    for(unsigned int j = 0; j < mtrx.mtrxWidth; j++) {
      mtrxScalar.mtrx[i][j] = mtrx.mtrx[i][j] * scalar;
    }
  }
  std::cout << "\nWlasnie pomnozylem podana przez Ciebie macierz przez wartosc scalara.\n";
  std::cout << "Z przemnozenia macierzy przez skalar powstala macierz potomna:\n";
  mtrxScalar.printMtrx(false);
  return mtrxScalar;
}