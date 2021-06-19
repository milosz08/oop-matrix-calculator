#include <iostream>
#include "../GeneralMatrixPackage/GeneralMatrix.h"

/*!
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
  GeneralMatrix<M> mtrxAdd = GeneralMatrix<M>{mtrxF};
  try {
    if(mtrxF.mtrxWidth != mtrxS.mtrxWidth && mtrxF.mtrxHeight != mtrxS.mtrxHeight) {
      throw std::logic_error("badMtrxsSize");
    } else {
      for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
        for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
          mtrxAdd.mtrx[i][j] = mtrxF.mtrx[i][j] + mtrxS.mtrx[i][j];
        }
      }
      std::cout << "\nWlasnie dodalem do siebie dwie podane przez Ciebie macierze.\n";
      std::cout << "Z dodanych do siebie macierzy powstala macierz potomna:\n";
      mtrxAdd.printMtrx(false);
    }
  }
  catch(std::logic_error& e) {
    std::cout << "\nError! Blad logiczny, kod bledu: " << e.what() << "!\n";
    std::cout << "Dodanie do siebie dwoch macierzy roznych rozmiarow nie jest mozliwe!\n";
  }
  return mtrxAdd;
}

/*!
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
  GeneralMatrix<M> mtrxSubt = GeneralMatrix<M>{mtrxF};
  try {
    if(mtrxF.mtrxWidth != mtrxS.mtrxWidth && mtrxF.mtrxHeight != mtrxS.mtrxHeight) {
      throw std::logic_error("badMtrxsSize");
    } else {
      for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
        for(unsigned int j = 0; j < mtrxF.mtrxWidth; j++) {
          mtrxSubt.mtrx[i][j] = mtrxF.mtrx[i][j] - mtrxS.mtrx[i][j];
        }
      }
      std::cout << "\nWlasnie odjalem od siebie dwie podane przez Ciebie macierze.\n";
      std::cout << "Z odjetych od siebie macierzy powstala macierz potomna:\n";
      mtrxSubt.printMtrx(false);
    }
  }
  catch(std::logic_error& e) {
    std::cout << "\nError! Blad logiczny, kod bledu: " << e.what() << "!\n";
    std::cout << "Odjecie od siebie dwoch macierzy roznych rozmiarow nie jest mozliwe!\n";
  }
  return mtrxSubt;
}

/*!
 * @overload Operator Mnożenia
 * @brief Przeciążenie operatora "*" (mnożenia) mnożącego przez siebie dwie macierze.
 * Funkcja posiada walidację obliczanych macierzy (jeśli ilośc kolumn pierwszej macierzy
 * nie jest równa ilości wierszy drugiej macierzy (i na odwrót) - błąd).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrxF - pierwsza mnożona macierz
 * @param mtrxS - druga mnożona macierz
 * @return - macierz wynikowa (obiekt) po monożeniu przez siebie dwóch macierzy
 */
template<class M>
GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS) {
  GeneralMatrix<M> mtrxMult = GeneralMatrix<M>{mtrxF};
  try {
    if(mtrxF.mtrxWidth != mtrxS.mtrxHeight || mtrxS.mtrxWidth != mtrxF.mtrxHeight) {
      throw std::logic_error("badMtrxsSize");
    } else {
      unsigned int sum{0};
      for(unsigned int i = 0; i < mtrxF.mtrxHeight; i++) {
        for(unsigned int j = 0; j < mtrxS.mtrxWidth; j++) {
          sum = 0;
          for(unsigned int k = 0; k < mtrxF.mtrxWidth; k++) {
            sum += mtrxF.mtrx[i][k] * mtrxS.mtrx[k][j];
            mtrxMult.mtrx[i][j] = sum;
          }
        }
      }
      std::cout << "\nWlasnie przemnozylem przez siebie dwie podane przez Ciebie macierze.\n";
      std::cout << "Z pomnozonych przez siebie macierzy powstala macierz potomna:\n";
      mtrxMult.printMtrx(false, true);
    }
  }
  catch(std::logic_error& e) {
    std::cout << "\nError! Blad logiczny, kod bledu: " << e.what() << "!\n";
    std::cout << "Pomnozenie przez siebie macierzy, ktorych pierwsza z nich nie ma tyle samo wierszy\n";
    std::cout << "co druga kolumn (i na odwrot) nie jest mozliwe !\n";
  }
  return mtrxMult;
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
GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrx, const double& scalar) {
  GeneralMatrix<M> mtrxScalar = GeneralMatrix<M>{mtrx};
  for(unsigned int i = 0; i < mtrx.mtrxHeight; i++) {
    for(unsigned int j = 0; j < mtrx.mtrxWidth; j++) {
      mtrxScalar.mtrx[i][j] = mtrx.mtrx[i][j] * scalar;
    }
  }
  return mtrxScalar;
}

/*!
 *
 * @tparam M
 * @param mtrxS
 * @param nextRow
 * @param colCount
 * @param mtrx
 * @return
 */
template<class M>
M detRecursion(unsigned short int mtrxS, unsigned short int nextRow, unsigned short int* colCount, M** mtrx) {
  M recDet{0}; /** Obliczony wyznacznik */
  unsigned short int* colRecCount{nullptr}; /** indeksy kolumn przekazywane w rekurencji */
  unsigned short int mtrxElm{0};
  signed char sign{1};

  if(mtrxS == 1) { /** Jeśli wielkość macierzy potomnej 1 to zakończ rekurencję */
    return mtrx[nextRow][colCount[0]];
  } else {
    colRecCount = new unsigned short int[mtrxS - 1]; /** Macierz potomna pomniejszona o 1 */

    for(unsigned int i = 0; i < mtrxS; i++) {
      mtrxElm = 0; /** Ustawianie pierwotnej pozycji obsługiwanego elementu */
      for(unsigned int j = 0; j < mtrxS - 1; j++) {
        if(mtrxElm == i) { /** Jeśli element jest taki sam, pomiń */
          mtrxElm++;
        }
        colRecCount[j] = colCount[mtrxElm++];
      }
      recDet += sign * mtrx[nextRow][colCount[i]] * detRecursion<M>(mtrxS - 1, nextRow + 1, colRecCount, mtrx);
      sign *= -1; /** Odwrócenie znaku */
    }
    delete [] colRecCount; /** Odśmiecanie pamięci */
  }
  return recDet;
}
