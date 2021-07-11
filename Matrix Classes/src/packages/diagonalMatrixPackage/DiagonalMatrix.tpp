#include "DiagonalMatrix.hpp"


using namespace matrixAbstractPackage;


/*!
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor jednoargumentowy alokujący pamięć dla tablicy dynamicznej przechowującej
 *        elementy przekątnej macierzy diagonalnej. W liście inicjalizacyjnej wywołanie konstruktora z
 *        klasy abstrakcyjnej z wpisaniem do niej wartości ze zmiennej z (rozmiar macierzy).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param s - stopień macierzy (ilość kolumn oraz wierszy).
 */
template<class M>
DiagonalMatrix<M>::DiagonalMatrix(unsigned short int& s) : MatrixAbstract<M>{s, s} {
  diagTab = new M[this->mtrxWidth];
}


/*!
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor dwuargumentowy alokujący pamięć dla tablicy dynamicznej przechowującej
 *        elementy przekątnej macierzy diagonalnej. W liście inicjalizacyjnej wywołanie konstruktora z
 *        klasy abstrakcyjnej z wpisaniem do niej wartości ze zmiennej z (rozmiar macierzy).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param w - szerokość macierzy (ilość kolumn).
 * @param h - wysokość macierzy (ilośc wierszy).
 */
template<class M>
DiagonalMatrix<M>::DiagonalMatrix(unsigned short int& w, unsigned short int& h) : MatrixAbstract<M>{w, h} {
  diagTab = new M[this->mtrxWidth];
}


/*!
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor kopiujący. W liście inicjalizacyjnej wywołanie konstruktora z
 *        klasy abstrakcyjnej z kopiowaniem danych na podstawie przesyłanego obiektu.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param mtrxCopy - kopiowany obiekt.
 */
template<class M>
DiagonalMatrix<M>::DiagonalMatrix(const DiagonalMatrix<M>& mtrxCopy) : MatrixAbstract<M>{mtrxCopy} {}


/*!
 * @fn ~GeneralMatrix()
 *
 * @brief Destruktor pełniący rolę odśmiecacza pamięci. Usuwa tablicę dynamiczną
 *        reprezentującą elementy macierzy diagonalnej (po przekątnej).
 */
template<class M>
DiagonalMatrix<M>::~DiagonalMatrix() {
  delete[] diagTab;
}


/*!
 * @fn get_DiagTab()
 * @brief Getter klasy "DiagonalAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca tablicę dynamiczną elementów na diagonalnej (przekątnej macierzy diagonalnej).
 */
template<class M>
M* DiagonalMatrix<M>::get_DiagTab() const { return diagTab; }


/*!
 * @fn generateDiagMtrx(bool identityMtrx)
 *
 * @brief Metoda tylko na użytek metod tej klasy. Metoda prywatna. Metoda wprowadzająca do konkretnych komórek
 *        macierzy konkretne znaki. Jeśli parametr indentityMtrx jest ustawiony na "false", generuje macierz
 *        diagonalną na podstawie znaków tablicy dynamicznej diagTab[]. Jeśli jest ustawiony na "true",
 *        generuje macierz jednostkową.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param identityMtrx - przełącznik pomiędzy macierzą diagonalną a jednostkową (jednostkowa -> true).
 */
template<class M>
void DiagonalMatrix<M>::generateDiagMtrx(bool identityMtrx) {
  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned short int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        (!identityMtrx ? this->mtrx[i][j] = this->diagTab[j] : this->mtrx[i][j] = 1);
      } else {
        this->mtrx[i][j] = 0;
      }
    }
  }
}


/*!
 * @fn mtrxTypeAndSizeInfo()
 *
 * @brief Metoda przysłaniająca medotę czysto wirtualną klasy abstrakcyjnej. Metoda informująca
 *        użytkownika jakiej wielkości oraz ilu elementowa macierz diagonalna została zapisana.
 *        Metoda dostępna tylko na użytek metod klasy. Metoda prywatna.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 */
template<class M>
void DiagonalMatrix<M>::mtrxTypeAndSizeInfo() {
  std::cout << "\nZapisałem następujące informacje na temat macierzy diagonalnej\n";
  std::cout << "o wymiarach: " << this->mtrxWidth << " x " << this->mtrxHeight;
  std::cout << ", posiadającej liczbę " << this->mtrxWidth * this->mtrxHeight << " komórek.\n";
}


/*!
 * @fn insertDiagElms()
 *
 * @brief Metoda przysłaniająca medotę czysto wirtualną klasy abstrakcyjnej. Metoda wprowadzająca podane przez
 *        użytkownika elementy macierzy diagonalnej (po przekątnej) do tablicy dynamicznej.<br>
 *
 *        Metoda posiada walidację strumienia wejścia pod kątem wprowadzanych znaków do macierzy diagonalnej.
 *        Jeśli znak nie jest zgody z typem zmiennej we wzorcu "M" program wyrzuca błąd i daje możliwość
 *        ponownego wpisania znaków macierzy diagonalnej.<br>
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 */
template<class M>
void DiagonalMatrix<M>::insertMtrx(HANDLE& hOut) {
  bool error{false}, repeatMess{false};

  do {
    error = false;

    mtrxTypeAndSizeInfo();
    std::cout << "\nAby przejść dalej, podaj kolejne elementy macierzy diagonalnej.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    DiagonalMatrix::genInfoBlock("UWAGA!", {
            "Jeśli podasz więcej elementow, zostaną one przeze mnie zignorowane."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nWpisz poniżej" << (!repeatMess ? "" : " ponownie");
    std::cout << " elemety macierzy diagonalnej (po spacji):\n";
    for(unsigned short int i = 0; i < this->mtrxWidth; i++) {
      std::cin >> this->diagTab[i];
    }

    if(std::cin.fail()) { /** @skip Jeśli użytkownik nie wpisze porządanych wartości w strumień wejścia */
      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      DiagonalMatrix::genInfoBlock("ERROR!", {
              "W wprowadzanej przez Ciebie macierzy znalazłem niedozwolone wartości!",
              "Aby kontyuować wprowadź ponownie swoją macierz."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");

      std::system("cls");
      error = repeatMess = true;
      std::cin.clear(); /** @skip Czyszczenie strumienia wejścia */
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } else {
      generateDiagMtrx(false); /** @skip Wstawianie wartości diagonalnej do macierzy */
      std::system("cls");
    }
  } while(error);
  std::system("cls");
}


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