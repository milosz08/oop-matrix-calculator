#include "../MatrixAbstract.hpp"


/*!
 * @fn pringMtrx()
 * @inherit Metoda, którą dziedziczą wszyskie klasy pochodne od klasy abstrakcyjnej. Metoda niewirtualna.
 *
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie wartości
 *        zapisanych w dwuwymiarowej tablicy dynamicznej. Metoda niemodyfikująca obiektu (const).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param textMess - jeśli "true" drukuje komunikat, jeśli "false" drukuje jednynie macierz.
 *
 * @param sharpBrc - "true" dla zaznaczenia macierzy, "false" dla zaznaczenia wyznacznika macierzy.
 */
template<class M>
void MatrixAbstract<M>::printMtrx(HANDLE& hOut, const bool textMess, const bool sharpBrc) const {

  unsigned short int spaces{0}, longestNr{0};

  if(textMess) {

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("POWODZENIE!", {
      "Z wprowadzonych przez Ciebie parametrów udało mi sie wygenerować macierz!",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nZapisałem następujacą macierz ";
    std::cout << (this->mtrxHeight == mtrxWidth ? "kwadratową:\n\n" : "prostokatną:\n\n");
  }

  for(unsigned short int i = 0; i < mtrxHeight; i++) {
    for(unsigned short int j = 0; j < mtrxWidth; j++) {

      longestNr = longestNumber(j); /** @skip Najdłuższa liczba w kolumnie */
      spaces = longestNr - longOfCell(mtrx[i][j]) + 2; /** @skip Ilość pustych znaków */

      if(j == 0) { /** @skip Jeśli jest to 1 kolumna macierzy */
        std::cout << (sharpBrc ? "  [ " : "  | ");
      }

      /** @skip Wypisanie macierzy z precyzją cyfr na podstawie najdłuższej liczby w kolumnie */
      std::cout << std::setprecision(longestNr - 1) << mtrx[i][j];

      /** @skip Dodaj puste znaki w celu wyrównania kolumn */
      for(unsigned short int k = 0; k < spaces; k++) {
        std::cout << " ";
      }

    }
    std::cout << (sharpBrc ? "]" : "|") << "\n";
  }
}


/*!
 * @fn scalarValuePush()
 * @inherit Metoda, którą dziedziczą wszyskie klasy pochodne od klasy abstrakcyjnej. Metoda niewirtualna.
 *
 * @brief Wprowadzanie przez użytkownika wartości skalara.<br>
 *
 *        Metoda posiada walidację pod kątem strumienia wejścia. Jeśli zostaną podane nieprawidłowe wartości,
 *        program wyświetli błąd i umożliwi ponowne wpisanie wartości skalara przez użytkownika.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @return Metoda zwraca wartość skalara zapisaną w polu klasy.
 */
template<class M>
double MatrixAbstract<M>::scalarValuePush(HANDLE& hOut) {
  bool error{false}, repeatMess{false};

  do {
    error = false;

    std::cout << "\nAby przejść dalej, podaj wartość skalarną, przez ktorą chcesz przemnożyc macierz.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jeśli podasz więcej elementów, zostaną one przeze mnie zignorowane."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nWpisz tutaj" << (!repeatMess ? "" : " ponownie") << " wartość skalarną: ";
    std::cin >> scalarVal;
    if(std::cin.fail()) {

      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      genInfoBlock("ERROR!", {
        "W wprowadzanej przez Ciebie wartości skalarnej znalazłem niedozwolone wartości!",
        "Aby kontyuować wprowadź ponownie swoja wartość skalarną."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");

      std::system("cls");
      error = repeatMess = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

  } while(error);
  return this->scalarVal;
}