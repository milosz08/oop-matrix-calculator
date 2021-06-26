#include "../MatrixAbstract.hpp"


/*!
 * @fn pringMtrx()
 * @inherit Metoda, którą dziedziczą wszyskie klasy pochodne od klasy abstrakcyjnej. Metoda niewirtualna.
 *
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie wartości
 *        zapisanych w dwuwymiarowej tablicy dynamicznej. Metoda niemodyfikująca elementów obiektu (const).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param textMess - jeśli "true" drukuje komunikat, jeśli "false" drukuje jednynie macierz.
 *
 * @param sharpBrc - "true" dla zaznaczenia macierzy, "false" dla zaznaczenia wyznacznika macierzy.
 *
 * @param autoFreeSpaces - jeśli "true" kolejne elementy macierzy ustawiane są automatycznie przy pomocy tabulatora,
 *                         jeśli "false" kolejne elementy macierzy ustawiane są na podstawie ich długości.
 */
template<class M>
void MatrixAbstract<M>::printMtrx(HANDLE& hOut, const bool textMess, const bool sharpBrc,
                                        const bool autoFreeSpaces) const {

  unsigned short int spaces{0}; /** Przerwa pomiędzy kolejnymi kolumnami */

  if(textMess) {

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("POWODZENIE!", {
      "Z wprowadzonych przez Ciebie parametrów udało mi sie wygenerować macierz!",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nZapisałem następujacą macierz ";
    std::cout << (this->mtrxHeight == this->mtrxWidth ? "kwadratową:\n\n" : "prostokatną:\n\n");
  }

  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned short int j = 0; j < this->mtrxWidth; j++) {

      if(j == 0) { /** Jeśli jest to 1 kolumna macierzy */
        std::cout << (sharpBrc ? "  [ " : "  | ");
      }

      if(!autoFreeSpaces) {
        std::cout << this->mtrx[i][j];

        if(j == this->mtrxWidth - 1) { /** Jeśli jest to ostatnia kolumna macierzy */
          spaces = findMaxLength(j) - lengthOfElm(this->mtrx[i][j]) - 2;
        } else { /** Pozostałe kolumny macierzy */
          spaces = findMaxLength(j) - lengthOfElm(this->mtrx[i][j]);
        }

        for(unsigned short int k = 0; k < spaces; k++) {
          std::cout << " ";
        }

      } else {
        std::cout << this->mtrx[i][j] << "\t";
      }
    }
    std::cout << (sharpBrc ? " ]" : " |") << "\n";
  }
}


/*!
 * @fn scalarValuePush()
 * @inherit Metoda, którą dziedziczą wszyskie klasy pochodne od klasy abstrakcyjnej. Metoda niewirtualna.
 *
 * @brief Wprowadzanie przez użytkownika wartości skalara.
 *
 * @protection Metoda posiada walidację pod kątem strumienia wejścia. Jeśli zostaną podane nieprawidłowe wartości,
 *             program wyświetli błąd i umożliwi ponowne wpisanie wartości skalara przez użytkownika.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @return - Wartość skalara zapisaną w polu klasy.
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
    std::cin >> this->scalarVal;
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