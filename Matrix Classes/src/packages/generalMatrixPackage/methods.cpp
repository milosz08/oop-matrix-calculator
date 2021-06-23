#include "GeneralMatrix.hpp"
#include "../abstractMatrixPackage/MatrixAbstract.hpp"

using namespace generalMatrixPackage;
using namespace matrixAbstractPackage;

/**
 * @fn mtrxTypeAndSizeInfo()
 * @brief Metoda informująca użytkownika jakiej wielkości oraz ilu elementowa
 * macierz została zapisana.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void GeneralMatrix<M>::mtrxTypeAndSizeInfo() {
  std::cout << "\nZapisałem następujace informacje na temat macierzy ";
  if(this->mtrxWidth == this->mtrxHeight) {
    std::cout << "kwadratowej";
  } else {
    std::cout << "prostokątnej";
  }
  std::cout << "\no wymiarach: " << this->mtrxWidth << " x " << this->mtrxHeight;
  std::cout << ", posiadającej liczbę " << this->mtrxWidth * this->mtrxHeight << " komórek.\n";
}

/**
 * @fn insertMtrx()
 * @brief Metoda umożliwiająca wprowadzenie przez użytkownika elementów macierzy do dwuwymiarowej
 * tablicy dynamicznej stworzonej w klasie abstrakcyjnej. Metoda posiada walidację strumienia wejścia
 * pod kątem wprowadzanych znaków do macierzy. Jeśli znak nie jest zgody z typem zmiennej
 * we wzorcu "M" program wyrzuca błąd i daje możliwość ponownego wpisania macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param throw - błąd logiczny (niedozwolone znaki ASCII)
 */
template<class M>
void GeneralMatrix<M>::insertMtrx(HANDLE& hOut) {
  bool error, repeatMess = false;

  do {
    std::system("cls");

    mtrxTypeAndSizeInfo();
    std::cout << "\nAby przejść dalej, podaj kolejne elementy macierzy.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    GeneralMatrix::genInfoBlock("UWAGA!", {
      "Jeśli podasz więcej elementów, zostaną one przeze mnie zignorowane."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    GeneralMatrix::genInfoBlock("INFO", {
      "Macierz możesz wpisać zarówno w formie jednoliniowej poziomej lub pionowej tablicy",
      "lub w wygodnej formie wizualnej macierzy (kolejne elementy należy wypisywać po spacji",
      "a w przechodzeniu do nowego wiersza należy uzyć klawisza \"enter\")."
    });

    error = false;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nWpisz " << (!repeatMess ? "" : "ponownie ") << "swoją macierz:\n";

    for(unsigned int i = 0; i < this->mtrxHeight; i++) {
      for(unsigned int j = 0; j < this->mtrxWidth; j++) {
        std::cin >> this->mtrx[i][j];
      }
    }

    if(std::cin.fail()) {

      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      GeneralMatrix::genInfoBlock("ERROR!", {
        "W wprowadzanej przez Ciebie macierzy znalazłem niedozwolone wartości!",
        "Aby kontyuować wprowadź ponownie swoją macierz."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");

      error = repeatMess = true;

      std::cin.clear(); /** Czyszczenie strumienia wejścia */
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
  } while(error);
  std::system("cls");
}

/**
 * @fn transposeMtrx(const GeneralMatrix<M>& mtrx)
 * @brief Metoda wykonująca operację tranponowania macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrx - macierz, która zostanie podjęta transponacji
 * @return - macierz wynikowa (obiekt) po transponacji
 */
template<class M>
GeneralMatrix<M> GeneralMatrix<M>::transposeMtrx() {
  GeneralMatrix<M> mtrxTrans = GeneralMatrix<M>{*this}; /** Kopiowanie macierzy */
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      mtrxTrans.mtrx[i][j] = this->mtrx[j][i];
    }
  }
  return mtrxTrans;
}

/**
 * @fn coupledGenMtrx(const GeneralMatrix<M>& mtrx)
 * @brief Metoda tworząca macierz sprzężoną na podstawie macierzy pierwotnej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrx - macierz, której każda wartość otrzyma odpowiadającej jej wartość sprzężoną
 * @return - macierz sprzężona (obiekt)
 */
template<class M>
GeneralMatrix<M> GeneralMatrix<M>::coupledMtrx() {
  GeneralMatrix<M> mtrxCoup = GeneralMatrix<M>{*this}; /** Kopiowanie macierzy */
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      mtrxCoup.mtrx[i][j] = this->mtrx[i][j] * -1;
    }
  }
  return mtrxCoup;
}

/**
 *
 * @return
 */
template<class M>
M GeneralMatrix<M>::determinantMtrx(HANDLE& hOut) {
  M mtrxDet{0}; /** Końcowy wyznacznik (int/double) */
  try {
    if(this->mtrxWidth != this->mtrxHeight) {
      throw std::logic_error("Program nie wspiera obliczania wyznacznika z macierzy prostokątnej.");
    } else {
      colsCount = new unsigned short int[this->mtrxWidth];
      for(unsigned int i = 0; i < this->mtrxWidth; i++) {
        colsCount[i] = i;
      }
      mtrxDet = detRecursion<M>(this->mtrxWidth, 0, colsCount, this->mtrx);
    }
  }
  catch(std::logic_error) {

  }
  return mtrxDet;
}


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
    for(unsigned int i = 0; i < this->mtrxHeight; i++) {
      for(unsigned int j = 0; j < doubleWidth; j++) {
        if(j == i + this->mtrxWidth) { /** Diagonalna (jednostkowa) */
          mtrxWithIdn.mtrx[i][j] = 1;
        } else if(j >= this->mtrxWidth) { /** Pozostałe komórki (jednostkowa) */
          mtrxWithIdn.mtrx[i][j] = 0;
        } else { /** Przepisanie elementów macierzy pierwotnej */
          mtrxWithIdn.mtrx[i][j] = this->mtrx[i][j];
        }
      }
    }

    /**  */
    for(unsigned int i = 0; i < this->mtrxHeight; i++) {
      for(unsigned int j = 0; j < this->mtrxWidth; j++) {
        if(i != j) { /** Pomiń elementy na diagonalnej */
          tempMath = mtrxWithIdn.mtrx[j][i] / mtrxWithIdn.mtrx[i][i];
          for(unsigned int k = 0; k < doubleWidth; k++) {
            mtrxWithIdn.mtrx[j][k] -= mtrxWithIdn.mtrx[i][k] * tempMath;
          }
        }
      }
    }

    /**  */
    for(unsigned int i = 0; i < this->mtrxWidth; i++) {
      tempMath = mtrxWithIdn.mtrx[i][i];
      for(unsigned int j = 0; j < doubleWidth; j++) {
        mtrxWithIdn.mtrx[i][j] /= tempMath;
      }
    }

    /** Przypisanie elementów (oprócz elm macierzy jednostkowej) do macierzy z obiektu macierzy odwrotnej */
    for(unsigned int i = 0; i < this->mtrxWidth; i++) {
      for(unsigned int j = this->mtrxWidth; j < doubleWidth; j++) {
        mtrxInvrs.get_Mtrx()[i][j - this->mtrxWidth] = mtrxWithIdn.mtrx[i][j];
      }
    }
  }
  return mtrxInvrs;
}


template class generalMatrixPackage::GeneralMatrix<short int>;
template class generalMatrixPackage::GeneralMatrix<double>;