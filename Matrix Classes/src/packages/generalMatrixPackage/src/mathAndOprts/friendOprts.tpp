#include "../../GeneralMatrix.hpp"


/*!
 * @overload Operator dodawania (+)
 *
 * @brief Przeciążenie operatora "+" (dodawania) dodającego do siebie dwie macierze.<br>
 *        Funkcja posiada walidację obliczanych macierzy (jeśli nie mają tych samych rozmiarów - błąd).
 *
 * @throw logic_error -> Brak możliwości dodania macierzy które nie mają tych samych rozmiarów.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxF - pierwsza dodawana macierz.
 * @param mtrxS - druga dodawana macierz.
 *
 * @return Funkcja zwraca macierz wynikową (obiekt) po dodaniu.
 */
template<class M>
GeneralMatrix<M> operator+(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS) {

  /** @skip Kopiowanie obiektu */
  GeneralMatrix<M> mtrxAdd = GeneralMatrix<M>{mtrxF};

  if(mtrxF.mtrxWidth != mtrxS.mtrxWidth && mtrxF.mtrxHeight != mtrxS.mtrxHeight) {
    throw std::logic_error("Dodawanie do siebie macierzy o różnych wielkościach jest niedozwolone!");
  } else {
    for(unsigned short int i = 0; i < mtrxF.mtrxHeight; i++) {
      for(unsigned short int j = 0; j < mtrxF.mtrxWidth; j++) {
        mtrxAdd.mtrx[i][j] = mtrxF.mtrx[i][j] + mtrxS.mtrx[i][j];
      }
    }
  }
  return mtrxAdd;
}


/*!
 * @overload Operator odejmowania (-)
 *
 * @brief Przeciążenie operatora "-" (odejmowania) odejmującego od siebie dwie macierze.<br>
 *        Funkcja posiada walidację obliczanych macierzy (jeśli nie mają tych samych rozmiarów - błąd).
 *
 * @throw logic_error -> Brak możliwości odjęcia macierzy które nie mają tych samych rozmiarów.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxF - pierwsza dodawana macierz.
 * @param mtrxS - druga dodawana macierz.
 *
 * @return Funkcja zwraca macierz wynikową (obiekt) po odjęciu.
 */
template<class M>
GeneralMatrix<M> operator-(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS) {

  /** @skip Kopiowanie obiektu */
  GeneralMatrix<M> mtrxSubt = GeneralMatrix<M>{mtrxF};

  if(mtrxF.mtrxWidth != mtrxS.mtrxWidth && mtrxF.mtrxHeight != mtrxS.mtrxHeight) {
    throw std::logic_error("Odejmowanie od siebie macierzy o różnych wielkościach jest niedozwolone!");
  } else {
    for(unsigned short int i = 0; i < mtrxF.mtrxHeight; i++) {
      for(unsigned short int j = 0; j < mtrxF.mtrxWidth; j++) {
        mtrxSubt.mtrx[i][j] = mtrxF.mtrx[i][j] - mtrxS.mtrx[i][j];
      }
    }
  }
  return mtrxSubt;
}


/*!
 * @overload Operator mnożenia (*)
 *
 * @brief Przeciążenie operatora "*" (mnożenia) mnożącego przez siebie dwie macierze.<br>
 *        Funkcja posiada walidację obliczanych macierzy (jeśli macierz pierwsza nie ma tyle samo wierszy co
 *        macierz druga kolumn lub macierz pierwsza nie ma tyle samo kolumn co macierz druga wierszy - błąd).
 *
 * @throw logic_error -> Brak możliwości odjęcia macierzy które nie mają tych samych rozmiarów.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxF - pierwsza dodawana macierz.
 * @param mtrxS - druga dodawana macierz.
 *
 * @return Funkcja zwraca macierz wynikową (obiekt) po odjęciu.
 */
template<class M>
GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS) {

  /** @skip Kopiowanie obiektu */
  GeneralMatrix<M> mtrxMult = GeneralMatrix<M>{mtrxF};

  if(mtrxF.mtrxWidth != mtrxS.mtrxHeight || mtrxS.mtrxWidth != mtrxF.mtrxHeight) {
    throw std::logic_error("Podane przez ciebie macierze nie spełniają zasad dot. mnożenia macierzy!");
  } else {
    M sum{0};

    for(unsigned short int i = 0; i < mtrxF.mtrxHeight; i++) {
      for(unsigned short int j = 0; j < mtrxS.mtrxWidth; j++) {
        sum = 0;
        for(unsigned short int k = 0; k < mtrxF.mtrxWidth; k++) {
          sum += mtrxF.mtrx[i][k] * mtrxS.mtrx[k][j];
          mtrxMult.mtrx[i][j] = sum;
        }
      }
    }
  }
  return mtrxMult;
}


/*!
 * @overload Operator mnożenia (*)
 *
 * @brief Przeciążenie operatora "*" (mnożenia) mnożącego macierz przez wartość skalarną.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrx - pierwsza dodawana macierz.
 * @param scalar - wartość skalarna.
 *
 * @return Funkcja zwraca macierz wynikową (obiekt) po odjęciu.
 */
template<class M>
GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrx, const double& scalar) {

  /** @skip Kopiowanie obiektu */
  GeneralMatrix<M> mtrxScalar = GeneralMatrix<M>{mtrx};

  for(unsigned short int i = 0; i < mtrx.mtrxHeight; i++) {
    for(unsigned short int j = 0; j < mtrx.mtrxWidth; j++) {
      mtrxScalar.mtrx[i][j] = mtrx.mtrx[i][j] * scalar;
    }
  }
  return mtrxScalar;
}


/*!
 * @fn detRecursion(unsigned short int mtrxS, unsigned short int nextRow, unsigned short int* colCount, M** mtrx)
 *
 * @brief Funkcja rekurencyjna obliczająca wyznacznik macierzy kwadratowych nxn metodą Laplace'a. Jeśli n > 1 funkcja
 *        wybiera wiersz/kolumnę po czym następuje przemnożenie każdego elementu wiersza/kolumny przez wyznacznik
 *        macierzy której rozmiar to n - 1 (wyznaczany rekurencyjnie). Pod koniec funkcja mnoży otrzymaną wartość
 *        wyznacznika przez -1 w celu odwrócenia znaku (znaki na przemian). Wszystkie wyznaczniki powstałe na skutek
 *        rekurencji są dodawane i zwracane przez funkcję. Rekurencja działa aż do momentu osiągnięcia n = 1.<br>
 *
 *        Funkcję oparłem na podstawie algorytmu rozwinięcia Laplace'a odpowiednio przystosowanym na standardy
 *        języka C++ ze strony: https://en.wikipedia.org/wiki/Laplace_expansion.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mtrxS - stopień macierzy (jednoczesna ilość wierszy i kolumn - tylko macierze kwadratowe).
 *
 * @param nextRow - indeks wiersza rozpoczynający macierz powstałą na skutek rekurencji.
 *
 * @param colCount - przechowywanie indeksów elementów kolumn z macierzy pierwotnej.
 *
 * @param mtrx - macierz w postaci dwuwymiarowej tablicy dynamicznej przekazywanej przez rekurencję.
 *
 * @return Funkcja zwraca obliczony wyznacznik w postaci typu wartości na podstawie wzorca M.
 */
template<class M>
M detRecursion(unsigned short int mtrxS, unsigned short int nextRow, unsigned short int* colCount, M** mtrx) {
  M recDet{0}; /** @skip Obliczony wyznacznik */
  unsigned short int* colRecCount{nullptr}; /** @skip indeksy kolumn przekazywane w rekurencji */
  unsigned short int mtrxElm{0};
  signed char sign{1};

  if(mtrxS == 1) { /** @skip Jeśli wielkość macierzy potomnej 1 to zakończ rekurencję */
    return mtrx[nextRow][colCount[0]];
  } else {
    colRecCount = new unsigned short int[mtrxS - 1]; /** @skip Macierz potomna pomniejszona o 1 */

    for(unsigned short int i = 0; i < mtrxS; i++) {
      mtrxElm = 0; /** @skip Ustawianie pierwotnej pozycji obsługiwanego elementu */
      for(unsigned short int j = 0; j < mtrxS - 1; j++) {
        if(mtrxElm == i) { /** @skip Jeśli element jest taki sam, pomiń */
          mtrxElm++;
        }
        colRecCount[j] = colCount[mtrxElm++];
      }
      recDet += sign * mtrx[nextRow][colCount[i]] * detRecursion<M>(mtrxS - 1, nextRow + 1, colRecCount, mtrx);
      sign *= -1; /** @skip Odwrócenie znaku */
    }
    delete[] colRecCount; /** @skip Usuwanie tablicy */
  }
  return recDet;
}