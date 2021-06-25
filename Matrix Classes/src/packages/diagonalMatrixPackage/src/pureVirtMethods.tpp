#include "../DiagonalMatrix.hpp"

/*************************************************************
 * METODY PRZESŁONIĘTE CZYSTO WIRTUALNE Z KLASY ABSTRAKCYJNEJ
 *************************************************************/


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
 *        użytkownika elementy macierzy diagonalnej (po przekątnej) do tablicy dynamicznej.
 *
 * @protection Metoda posiada walidację strumienia wejścia pod kątem wprowadzanych znaków do macierzy diagonalnej.
 *             Jeśli znak nie jest zgody z typem zmiennej we wzorcu "M" program wyrzuca błąd i daje możliwość
 *             ponownego wpisania znaków macierzy diagonalnej.
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
    for(unsigned int i = 0; i < this->mtrxWidth; i++) {
      std::cin >> this->diagTab[i];
    }

    if(std::cin.fail()) { /** Jeśli użytkownik nie wpisze porządanych wartości w strumień wejścia */
      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      DiagonalMatrix::genInfoBlock("ERROR!", {
        "W wprowadzanej przez Ciebie macierzy znalazłem niedozwolone wartości!",
        "Aby kontyuować wprowadź ponownie swoją macierz."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");

      std::system("cls");
      error = repeatMess = true;
      std::cin.clear(); /** Czyszczenie strumienia wejścia */
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } else {
      generateDiagMtrx(false); /** Wstawianie wartości diagonalnej do macierzy */
      std::system("cls");
    }
  } while(error);
  std::system("cls");
}