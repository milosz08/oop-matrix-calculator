#include "interfaceDecl.hpp"

/*!
 * @fn mainMenu(HANDLE& hOut)
 *
 * @brief Funkcja generująca początkowe menu. Informuje o: autorze, wspieranych operacjach oraz daje
 *        możliwość użytkownikowi wybrania opcji: przejścia dalej lub zakończenia działania programu.<br>
 *
 *        Funkcja posiada walidację strumienia wejścia. Jeśli użytkownik nie poda liczb z zakresu 1-2 program
 *        zasygnalizuje błąd i po odczekaniu 5 sekund umożliwi użytkownikowi ponowne wybranie opcji.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 */
void mainMenu(HANDLE& hOut) {
  unsigned short int choice{0};
  bool error{false};

  do {
    error = false;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n#####################################################\n";
    std::cout << "################ KALKULATOR MACIERZY ################\n";
    std::cout << "#####################################################\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    MatrixAbstract<double>::genInfoBlock("AUTOR", {
      "Napisane w C++ z użyciem mechanizmów obiektowości przez Miłosz Gilga.",
      "Programowanie Komputerów, Wydział Elektryczny, Politechnika Śląska, Gliwice.",
      "(c) 2021 by Miłosz Gilga (github.com/Milosz08)."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("WSPIERANE OPERACJE", {
      "* Obliczanie wyznacznika macierzy n-elementowej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy odwrotnej względem macierzy pierwotnej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy sprzężonej względem macierzy pierwotnej.",
      "* Podstawowe działania arytmetyczne (dodawanie, odejmowanie, mnożenie).",
      "* Mnożenie macierzy przez wartość skalarną.",
      "* Transponowanie macierzy.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("UWAGA!", {
      "Z uwagi na dużą złożoność obliczeniową wyznacznika macierzy O(n!) rekurencyjną",
      "metodą Laplace'a, maksymalną macierz jaką program może przyjąć to 20x20.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    MatrixAbstract<double>::genInfoBlock("MENU POCZATKOWE", {
      "Aby zainicjalizowac program, wybierz jedną opcje z poniższego menu:",
      "1. Chcę prześć do głownego menu wyboru operacji.",
      "2. Chcę zakonczyć działanie programu.",
    });

    std::cout << "\nTwój wybór: ";
    std::cin >> choice;

    switch(choice) {
      case 1: {
        std::system("cls");
        break;
      } case 2: {
        MatrixAbstract<double>::sequentialMess(5, "Program zakończy działanie za");
        std::cout << "\nDziękuję za skorzystanie z kalkulatora macierzy. Program zakończył działanie.\n";
        exit(0);
      } default: {
        error = true;
        MatrixAbstract<double>::errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
        break;
      }
    }
  } while(error);
}