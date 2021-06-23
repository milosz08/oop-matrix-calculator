#include "../GeneralMatrix.hpp"

/*************************************************************
 * METODY PRZESŁONIĘTE CZYSTO WIRTUALNE Z KLASY ABSTRAKCYJNEJ
 *************************************************************/


/*!
 * @fn mtrxTypeAndSizeInfo()
 *
 * @brief Metoda informująca użytkownika jakiej wielkości oraz ilu elementowa macierz została zapisana.
 *
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


/*!
 * @fn insertMtrx()
 *
 * @brief Metoda umożliwiająca wprowadzenie przez użytkownika elementów macierzy do dwuwymiarowej
 *        tablicy dynamicznej stworzonej w klasie abstrakcyjnej.
 *
 * @protection Metoda posiada walidację strumienia wejścia pod kątem wprowadzanych znaków do macierzy diagonalnej.
 *             Jeśli znak nie jest zgody z typem zmiennej we wzorcu "M" program wyrzuca błąd i daje możliwość
 *             ponownego wpisania znaków macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 */
template<class M>
void GeneralMatrix<M>::insertMtrx(HANDLE& hOut) {
  bool error{false}, repeatMess{false};

  do {
    std::system("cls");

    mtrxTypeAndSizeInfo();
    std::cout << "\nAby przejść dalej, podaj kolejne elementy macierzy.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("UWAGA!", {
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

    if(std::cin.fail()) { /** Jeśli użytkownik wpisze wartości inne niż zdefiniowane we wzorcu */

      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      MatrixAbstract<double>::genInfoBlock("ERROR!", {
        "W wprowadzanej przez Ciebie macierzy znalazłem niedozwolone wartości!",
        "Aby kontyuować wprowadź ponownie swoją macierz."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<double>::sequentialMess(5, "Ponawianie za");

      error = repeatMess = true;

      std::cin.clear(); /** Czyszczenie strumienia wejścia */
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
  } while(error);
}