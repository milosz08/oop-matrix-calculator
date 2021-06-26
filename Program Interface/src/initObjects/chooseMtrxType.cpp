#include "../interfaceDecl.hpp"


/*!
 * @fn chooseTypeOfMatrix(HANDLE& hOut)
 *
 * @brief Funkcja pobierająca od użytkownika typ macierzy, na jakiej chce wykonywać operacje w programie. Spośród
 *        opcji użytkownik może wybrać odpowiednio: 1 - macierz zwykła prostokątna, 2 - macierz zwykła kwadratowa,
 *        3 - macierz diagonalna (typ macierzy kwadratowej).
 *
 * @protection Funkcja posiada walidację strumienia wejścia. Jeśli użytkownik nie poda liczby z zakresu 1-3 program
 *             zasygnalizuje błąd i po odczekaniu 5 sekund umożliwi użytkownikowi ponowne wybranie opcji.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @return Funkcja zwraca opcję wybraną przez użytkownika (w postaci wartości całkowitej z zakresu 1-3)
 */
unsigned short int chooseTypeOfMatrix(HANDLE& hOut) {
  unsigned short int choice{0};
  bool error{false};

  do {
    error = false;

    MatrixAbstract<double>::genInfoBlock("ETAP 1", {
      "Wybierz, na jakim typie macierzy chcesz przeprowadzać operacje:",
      "1. Chcę przeprowadzać operacje na zwykłej macierzy prostokatnej.",
      "2. Chcę przeprowadzać operacje na zwykłej macierzy kwadratowej.",
      "3. Chcę przeprowadzać operacje na kwadratowej macierzy diagonalnej."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("INFO", {
      "Macierz diagonalna to macierz, która poza swoją głowna przekątną (diagonalna)",
      "posiada wartosci zerowe. Na przekątnej diagonalnej znajdą sie podane przez Ciebie wartosci."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;

    if((choice < 1 || choice > 3) || std::cin.fail()) {
      error = true;
      MatrixAbstract<double>::errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }

  } while(error);

  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}