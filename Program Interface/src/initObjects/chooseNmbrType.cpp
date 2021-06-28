#include "../interfaceDecl.hpp"


/*!
 * @fn chooseTypeOfNumbers(HANDLE& hOut)
 *
 * @brief Funkcja pobierająca od użytkownika typ wartości, jakie będzie mógł wpisać do macierzy. Spośród opcji
 *        użytkownik może wybrać odpowiednio: 1 - macierz możliwa do zapełnienia tylko przez wartości
 *        całkowite, 2 - macierz możliwa do zapełnienia zarówno przez wartości całkowite
 *        jak i zmiennoprzecinkowe (double).<br>
 *
 *        Funkcja posiada walidację strumienia wejścia. Jeśli użytkownik nie poda liczby z zakresu 1-2 program
 *        zasygnalizuje błąd i po odczekaniu 5 sekund umożliwi użytkownikowi ponowne wybranie opcji.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @return Funkcja zwraca opcję wybraną przez użytkownika (w postaci wartości całkowitej z zakresu 1-2)
 */
unsigned short int chooseTypeOfNumbers(HANDLE& hOut) {
  unsigned short int choice{0};
  bool error{false};

  do {
    error = false;

    MatrixAbstract<double>::genInfoBlock("ETAP 2", {
      "Wybierz, na jakim typie wartości macierzy chcesz przeprowadzać operacje:",
      "1. Chcę przeprowadzać operacje tylko i wyłącznie na liczbach stałoprzecinkowych.",
      "2. Chcę przeprowadzać operacje na liczbach stałoprzecinkowych i zmiennoprzecinkowych.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("UWAGA!", {
      "Jeśli wybierzesz tylko liczby stałoprzecinkowe, próba zapełnienia macierzy liczbami",
      "zmiennoprzecinkowymi zakończy się błedem. Preferowany typ to macierz obsługująca zarówno",
      "liczby zmiennoprzecinkowe jak i stałoprzecinkowe.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;

    if((choice != 1 && choice != 2) || std::cin.fail()) {
      error = true;
      MatrixAbstract<double>::errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }

  } while(error);

  std::system("cls"); /** @skip czyszczenie konsoli */
  return choice;
}