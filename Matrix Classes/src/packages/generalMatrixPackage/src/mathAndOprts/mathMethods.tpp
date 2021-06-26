#include "../../GeneralMatrix.hpp"


/*!
 * @fn transposeMtrx()
 *
 * @brief Metoda wykonująca operację tranponowania macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @param mtrx - macierz, która zostanie podjęta transponacji.
 *
 * @return Metoda zwraca macierz wynikowa (obiekt) po transponacji.
 */
template<class M>
GeneralMatrix<M> GeneralMatrix<M>::transposeMtrx() {
  GeneralMatrix<M> mtrxTrans = GeneralMatrix<M>{*this}; /** Kopiowanie macierzy */
  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
      mtrxTrans.mtrx[i][j] = this->mtrx[j][i];
    }
  }
  return mtrxTrans;
}


/*!
 * @fn coupledGenMtrx()
 *
 * @brief Metoda tworząca macierz sprzężoną na podstawie macierzy pierwotnej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @param mtrx - macierz, której każda wartość otrzyma odpowiadającej jej wartość sprzężoną.
 *
 * @return - Metoda zwraca macierz sprzężona (obiekt).
 */
template<class M>
GeneralMatrix<M> GeneralMatrix<M>::coupledMtrx() {
  GeneralMatrix<M> mtrxCoup = GeneralMatrix<M>{*this}; /** Kopiowanie macierzy */
  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
      mtrxCoup.mtrx[i][j] = this->mtrx[i][j] * -1;
    }
  }
  return mtrxCoup;
}


/*!
 * @fn determinantMtrx(HANDLE& hOut)
 *
 * @brief Metoda obliczająca wyznacznik macierzy (tylko kwadratowe). Metoda sama w sobie nie oblicza wyznacznika,
 *        wywołuje zaprzyjaźniona funkcję rekurencyjną, która po wykonaniu operacji zwraca gotowy wyznacznik
 *        wartości liczb według przyjętego parametru we wzorcu M.
 *
 * @protection Metoda jest zabezpieczona pod kątem wymiarów macierzy. Jeśli wprowadzana macierz nie jest kwadratowa,
 *             nastąpi wyrzucenie wyjątka (przejęty w funkcji głównej).
 *
 * @throw logic_error -> Brak możliwości obliczenia wyznacznika z macierzy która nie jest macierzą kwadratową.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @return Metoda zwraca wyznacznik macierzy (typ wartości na podstawie parametru we wzorcu M).
 */
template<class M>
M GeneralMatrix<M>::determinantMtrx(HANDLE& hOut) {
  M mtrxDet{0}; /** Końcowy wyznacznik (int/double) */

  if(this->mtrxWidth != this->mtrxHeight) {
    throw std::logic_error("Program nie wspiera obliczania wyznacznika z macierzy prostokątnej.");
  } else {
    this->colsCount = new unsigned short int[this->mtrxWidth];
    for(unsigned short int i = 0; i < this->mtrxWidth; i++) {
      this->colsCount[i] = i;
    }
    mtrxDet = detRecursion<M>(this->mtrxWidth, 0, this->colsCount, this->mtrx);
  }
  return mtrxDet;
}


/*!
 * @fn inverseMtrx()
 *
 * @brief Metoda wyznaczająca macierz odwrotną na podstawie rozwiązania wyznaczania macierzy odwrotnej przy pomocy
 *        metody Gaussa - Jordana. Metoda polega na wyznaczeniu macierzy jednostkowej o takim samym stopniu jak
 *        macierz pierwotna, a następnie przeliczenie wartości, aby zamienić obie macierze miejscami (jeśli po prawej
 *        była dołączona macierz jednostkowa, to w obliczeniu macierzy odwrotnej, macierz jednostkowa przechodzi
 *        na stronę lewą a po prawej jest odwrócona macierz pierwotna - macierz wynikowa).
 *
 * @protection Metoda jest zabezpieczona pod kątem wymiarów macierzy. Jeśli wprowadzana macierz nie jest kwadratowa,
 *             nastąpi wyrzucenie wyjątka (przejęty w funkcji głównej).
 *
 * @throw logic_error -> Brak możliwości obliczenia wyznacznika z macierzy która nie jest macierzą kwadratową.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @return Metoda zwraca macierz odwrotną (obiekt).
 */
template<class M>
GeneralMatrix<double> GeneralMatrix<M>::inverseMtrx() {
  unsigned short int doubleWidth = this->mtrxWidth * 2;
  double tempMath{0};

  /** Macierz zawierająca elementy macierzy pierwotnej i jednostkowej */
  GeneralMatrix<M> mtrxWithIdn = GeneralMatrix<M>{doubleWidth, this->mtrxHeight};

  /** Macierz odwrotna do macierzy pierwotnej - na stałe wartość double */
  GeneralMatrix<double> mtrxInvrs = GeneralMatrix<double>{this->mtrxWidth, this->mtrxHeight};

  if(this->mtrxWidth != this->mtrxHeight) { /** Jeśli macierz nie jest kwadratowa */
    throw std::logic_error("Program nie wspiera obliczania macierzy odwrotnej z macierzy prostokątnej.");
  } else {

    /** Dodanie do istniejącej macierzy (A) macierzy jednostkowej (I) */
    for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
      for(unsigned short int j = 0; j < doubleWidth; j++) {
        if(j == i + this->mtrxWidth) { /** Diagonalna (jednostkowa) */
          mtrxWithIdn.mtrx[i][j] = 1;
        } else if(j >= this->mtrxWidth) { /** Pozostałe komórki (jednostkowa) */
          mtrxWithIdn.mtrx[i][j] = 0;
        } else { /** Przepisanie elementów macierzy pierwotnej */
          mtrxWithIdn.mtrx[i][j] = this->mtrx[i][j];
        }
      }
    }

    for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
      for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
        if(i != j) { /** Pomiń elementy na diagonalnej */
          /** Podzielenie kolejnych elementów kolumn przez kolejne wartości diagonalnej i zapisanie w tempMath */
          tempMath = mtrxWithIdn.mtrx[j][i] / mtrxWithIdn.mtrx[i][i];
          for(unsigned short int k = 0; k < doubleWidth; k++) {
            /** Przejście przez kolejne elementy wierszów macierzy wspólnej (podwójna szerokość) i odjęcie od
             * aktualnej  wartości elementu wiersza (pętla wewnętrzna) wartości w zmiennej tempMath przemnożonej
             * przez kolejne elementy wiersza (pętla zewnętrzna) */
            mtrxWithIdn.mtrx[j][k] -= mtrxWithIdn.mtrx[i][k] * tempMath;
          }
        }
      }
    }

    for(unsigned short int i = 0; i < this->mtrxWidth; i++) {
      /** Przypisanie do zmiennej tempMath wartości leżących na diagonalnej */
      tempMath = mtrxWithIdn.mtrx[i][i];
      for(unsigned short int j = 0; j < doubleWidth; j++) {
        /** Zaktualizowanie kolejnych elementów macierzy podwójnej poprzez podzielenie aktualnej wartości przez
         * wcześniej przypisaną zmienną tempMath */
        mtrxWithIdn.mtrx[i][j] /= tempMath;
      }
    }

    /** Przypisanie elementów (oprócz elm macierzy jednostkowej) do macierzy z obiektu macierzy odwrotnej */
    for(unsigned short int i = 0; i < this->mtrxWidth; i++) {
      for(unsigned short int j = this->mtrxWidth; j < doubleWidth; j++) {
        mtrxInvrs.get_Mtrx()[i][j - this->mtrxWidth] = mtrxWithIdn.mtrx[i][j];
      }
    }
  }
  return mtrxInvrs;
}