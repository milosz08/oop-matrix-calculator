#include "DiagonalMatrix.hpp"
#include "../../../../Program Interface/src/interfaceDecl.hpp"

using namespace diagonalMatrixPackage;

/**
 * @fn mtrxTypeAndSizeInfo()
 * @brief Metoda informująca użytkownika jakiej wielkości oraz ilu elementowa
 * macierz diagonalna została zapisana.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void DiagonalMatrix<M>::mtrxTypeAndSizeInfo() {
  std::cout << "\nZapisałem następujące informacje na temat macierzy diagonalnej\n";
  std::cout << "o wymiarach: " << this->mtrxWidth << " x " << this->mtrxHeight;
  std::cout << ", posiadającej liczbę " << this->mtrxWidth * this->mtrxHeight << " komórek.\n";
}

/**
 * @fn insertDiagElms()
 * @brief Metoda wprowadzająca podane przez użytkownika elementy macierzy diagonalnej (po przekątnej)
 * do tablicy dynamicznej. Metoda posiada walidację strumienia wejścia
 * pod kątem wprowadzanych znaków do macierzy diagonalnej. Jeśli znak nie jest zgody z typem zmiennej
 * we wzorcu "M" program wyrzuca błąd i daje możliwość ponownego wpisania znaków macierzy diagonalnej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param throw - błąd logiczny (niedozwolone znaki ASCII)
 */
template<class M>
void DiagonalMatrix<M>::insertMtrx(HANDLE& hOut) {
  bool error, repeatMess = false;

  do {
    mtrxTypeAndSizeInfo();
    std::cout << "\nAby przejść dalej, podaj kolejne elementy macierzy diagonalnej.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    DiagonalMatrix::genInfoBlock("UWAGA!", {
      "Jeśli podasz więcej elementow, zostaną one przeze mnie zignorowane."
    });

    try {
      error = false;

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      std::cout << "\nWpisz poniżej" << (!repeatMess ? "" : " ponownie");
      std::cout << " elemety macierzy diagonalnej (po spacji):\n";
      for(unsigned int i = 0; i < this->mtrxWidth; i++) {
        std::cin >> this->diagTab[i];
      }

      if(std::cin.fail()) {
        throw std::logic_error("badInputValue");
      } else {
        generateDiagMtrx(false);
        std::system("cls");
      }
    }
    catch(std::logic_error&) {

      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      DiagonalMatrix::genInfoBlock("ERROR!", {
        "W wprowadzanej przez Ciebie macierzy znalazłem niedozwolone wartości!",
        "Aby kontyuować wprowadź ponownie swoją macierz."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");

      std::system("cls");
      error = repeatMess = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(error);
}

/**
 * @fn generateDiagMtrx(bool identityMtrx)
 * @brief Metoda wprowadzająca do konkretnych komórek macierzy konkretne znaki. Jeśli parametr
 * indentityMtrx jest ustawiony na "false", generuje macierz diagonalną na podstawie znaków tablicy
 * dynamicznej diagTab[]. Jeśli jest ustawiony na "true", generuje macierz jednostkową.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param identityMtrx - przełącznik pomiędzy macierzą diagonalną a jednostkową (jednostkowa -> true)
 */
template<class M>
void DiagonalMatrix<M>::generateDiagMtrx(bool identityMtrx) {
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        (!identityMtrx ? this->mtrx[i][j] = this->diagTab[j] : this->mtrx[i][j] = 1);
      } else {
        this->mtrx[i][j] = 0;
      }
    }
  }
}

/*!
 *
 * @tparam M
 * @return
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

template<class M>
M DiagonalMatrix<M>::determinantMtrx(HANDLE& hOut) {
  M mtrxDet{1}; /** Końcowy wyznacznik (int/double) */
  try {
    if(this->mtrxWidth != this->mtrxHeight) { /** Jeśli macierz nie jest kwadratowa */
      throw std::logic_error("badMtrxSize");
    } else {
      for(unsigned int i = 0; i < this->mtrxHeight; i++) {
        mtrxDet *= this->diagTab[i];
      }
    }
  }
  catch(std::logic_error) {

  }
  return mtrxDet;
}

template<class M>
DiagonalMatrix<double> DiagonalMatrix<M>::inverseMtrx() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  M detCheck = this->determinantMtrx(hOut);

  /** Macierz odwrotna do macierzy pierwotnej - na stałe wartość double */
  DiagonalMatrix<double> mtrxInvrs = DiagonalMatrix<double>{this->mtrxWidth};

  if(detCheck == 0) { /** Jeśli wyznacznik jest równy zero - wyjątek */
    throw std::logic_error("badMtrxSize");
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


template<class M>
M* DiagonalMatrix<M>::get_DiagTab() const { return this->diagTab; }


template class diagonalMatrixPackage::DiagonalMatrix<short int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;