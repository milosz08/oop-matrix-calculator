#include "../../DiagonalMatrix.hpp"

/*********************************************************************************************************
 * METODY OPERACJI MATEMATYCZNYCH KLASY DIAGONALMATRIX (DZIEDZICZĄCEJ PO KLASIE ABSTRAKCYJNEJ - BAZOWEJ)
 *********************************************************************************************************/


/*!
 * @fn coupledMtrx()
 *
 * @brief Metoda wyznaczająca macierz sprzężoną. Metoda przy pomocy konstruktora kopiującego
 *        kopiuje obiekt i wypełnia go danymi (w postaci macierzy sprzężonej) i zwraca.
 *        Funkcja nie modyfikuje obiektu tworzonego w interfejsie.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @return Macierz sprzężona (obiekt klasy DiagonalMatrix).
 */
template<class M>
DiagonalMatrix<M> DiagonalMatrix<M>::coupledMtrx() {
  DiagonalMatrix<M> mtrxCoup = DiagonalMatrix<M>{*this}; /** Kopiowanie macierzy */
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        mtrxCoup.mtrx[i][j] = this->diagTab[j] * -1;
      } else {
        mtrxCoup.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxCoup;
}


/*!
 * @fn coupledMtrx()
 *
 * @brief Metoda wyznaczająca macierz transponowaną. Metoda przy pomocy konstruktora kopiującego
 *        kopiuje obiekt i wypełnia go danymi (w postaci macierzy transponowanej) i zwraca.
 *        Funkcja nie modyfikuje obiektu tworzonego w interfejsie.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @return Macierz transponowana (obiekt klasy DiagonalMatrix).
 */
template<class M>
DiagonalMatrix<M> DiagonalMatrix<M>::transposeMtrx() {
  DiagonalMatrix<M> mtrxCoup = DiagonalMatrix<M>{*this}; /** Kopiowanie macierzy */
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        mtrxCoup.mtrx[i][j] = this->diagTab[i];
      } else {
        mtrxCoup.mtrx[i][j] = 0;
      }
    }
  }
  return mtrxCoup;
}


/*!
 * @fn determinantMtrx()
 *
 * @brief Metoda obliczająca wyznacznik z macierzy pierwotnej. Wyznacznik w macierzy diagonalnej
 *        obliczany jest poprzez iloczyn wszysktkich elementów na diagonalnej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @throw Metoda rzuca wyjątek, jeśli odkryje, że macierz nie jest kwadratowa.
 *
 * @return Wyznacznik (w zależności od wzorca: wartość int lub double).
 */
template<class M>
M DiagonalMatrix<M>::determinantMtrx(HANDLE& hOut) {
  M mtrxDet{1}; /** Końcowy wyznacznik (int/double) */

  if(this->mtrxWidth != this->mtrxHeight) { /** Jeśli macierz nie jest kwadratowa */
    throw std::logic_error("Program nie wspiera obliczania wyznacznika z macierzy która nie jest kwadratowa");
  } else {
    for(unsigned int i = 0; i < this->mtrxHeight; i++) {
      mtrxDet *= this->diagTab[i];
    }
  }
  return mtrxDet;
}


/*!
 * @fn determinantMtrx()
 *
 * @brief Metoda wyznaczająca macierz odwrotną. Rozpoczyna od obliczenia wyznacznika macierzy. Jeśli ten jest równy
 *        zero, następuje wyrzucenie wyjątka. Jeśli nie jest równy zero, program wykonuje kopie obiektu a następnie
 *        zamienia kolejne elementy leżące na diagonalnej na wartość odwrotną (1 dzieli przez element).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @throw Metoda rzuca wyjątek, jeśli odkryje, że macierz nie jest kwadratowa.
 *
 * @return Macierz odwrotna (obiekt klasy DiagonalMatrix).
 */
template<class M>
DiagonalMatrix<double> DiagonalMatrix<M>::inverseMtrx() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  M detCheck = this->determinantMtrx(hOut);

  /** Macierz odwrotna do macierzy pierwotnej - na stałe wartość double */
  DiagonalMatrix<double> mtrxInvrs = DiagonalMatrix<double>{this->mtrxWidth};

  if(detCheck == 0) { /** Jeśli wyznacznik jest równy zero - wyjątek */
    throw std::logic_error("Nie można wyznaczyć macierzy odwrotnej, jeśli wyznacznik równy jest zero");
  } else {

    /** Obliczenie i przypisanie kolejnym elementom po diagonalnej wartości odwrotnej */
    for(unsigned int i = 0; i < this->mtrxHeight; i++) {
      mtrxInvrs.get_DiagTab()[i] = 1 / this->diagTab[i];
      for(unsigned int j = 0; j < this->mtrxWidth; j++) {
        if(i == j) {
          mtrxInvrs.get_Mtrx()[i][j] = mtrxInvrs.get_DiagTab()[i];
        } else {
          mtrxInvrs.get_Mtrx()[i][j] = 0;
        }
      }
    }
  }
  return mtrxInvrs;
}