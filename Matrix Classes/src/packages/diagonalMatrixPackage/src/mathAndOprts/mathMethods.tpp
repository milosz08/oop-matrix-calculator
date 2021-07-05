#include "../../DiagonalMatrix.hpp"


/*!
 * @fn coupledMtrx()
 *
 * @brief Metoda wyznaczająca macierz sprzężoną. Metoda przy pomocy konstruktora kopiującego
 *        kopiuje obiekt i wypełnia go danymi (w postaci macierzy sprzężonej) i zwraca.
 *        Funkcja nie modyfikuje obiektu tworzonego w interfejsie.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @return Metoda zwraca macierz sprzężoną (obiekt klasy DiagonalMatrix).
 */
template<class M>
DiagonalMatrix<M> DiagonalMatrix<M>::coupledMtrx() {

  /** @skip Kopiowanie macierzy */
  DiagonalMatrix<M> mtrxCoup = DiagonalMatrix<M>{*this};

  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        mtrxCoup.mtrx[i][i] = this->diagTab[i] * -1;
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
 * @return Metoda zwraca macierz transponowaną (obiekt klasy DiagonalMatrix).
 */
template<class M>
DiagonalMatrix<M> DiagonalMatrix<M>::transposeMtrx() {

  /** @skip Kopiowanie macierzy */
  DiagonalMatrix<M> mtrxCoup = DiagonalMatrix<M>{*this};

  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        mtrxCoup.mtrx[i][i] = this->diagTab[i];
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
 * @return Metoda zwraca wyznacznik (w zależności od wzorca: wartość int lub double).
 */
template<class M>
M DiagonalMatrix<M>::determinantMtrx(HANDLE& hOut) {
  M mtrxDet{1}; /** @skip Końcowy wyznacznik (int/double) */

  if(this->mtrxWidth != this->mtrxHeight) { /** Jeśli macierz nie jest kwadratowa */
    throw std::logic_error("Program nie wspiera obliczania wyznacznika z macierzy która nie jest kwadratowa");
  } else {
    for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
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
 * @return Metoda zwraca macierz odwrotną (obiekt klasy DiagonalMatrix).
 */
template<class M>
DiagonalMatrix<double> DiagonalMatrix<M>::inverseMtrx(HANDLE& hOut) {

  M detCheck = this->determinantMtrx(hOut);

  /** @skip Macierz odwrotna do macierzy pierwotnej - na stałe wartość double */
  DiagonalMatrix<double> mtrxInvrs = DiagonalMatrix<double>{this->mtrxWidth};

  if(detCheck == 0) { /** @skip Jeśli wyznacznik jest równy zero - wyjątek */
    throw std::logic_error("Nie można wyznaczyć macierzy odwrotnej, jeśli wyznacznik równy jest zero");
  } else {

    /** @skip Obliczenie i przypisanie kolejnym elementom po diagonalnej wartości odwrotnej */
    for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
      for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
        if(i == j) {
          mtrxInvrs.get_Mtrx()[i][i] = 1 / this->diagTab[i];
        } else {
          mtrxInvrs.get_Mtrx()[i][j] = 0;
        }
      }
    }
  }
  return mtrxInvrs;
}