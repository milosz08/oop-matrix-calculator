#include "interfaceFunc.h"
#include "Auxiliary Functions/auxiliaryFunc.h"

void mainMenu() {
  unsigned int choice{0};
  bool error{false};
  HANDLE hOut;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  std::system("cls");

  do {
    error = false;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n#####################################################\n";
    std::cout << "###############  KALKULATOR MACIERZY  ###############\n";
    std::cout << "#####################################################\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    genInfoBlock("AUTOR", {
      "Napisane w C++ z uzyciem mechanizmow obiektowosci przez Milosz Gilga.",
      "Programowanie Komputerow, Wydzial Elektryczny, Politechnika Slaska, Gliwice.",
      "(c) 2021 by Milosz Gilga (github.com/Milosz08)."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("WSPIERANE OPERACJE", {
      "* Obliczanie wyznacznika macierzy 1, 2 oraz n-elementowej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy odwrotnej wzgledem macierzy pierwotnej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy sprzezonej wzgledem macierzy pierwotnej.",
      "* Podstawowe dzialania arytmetyczne (dodawanie, odejmowanie, mnozenie).",
      "* Mnozenie macierzy przez wartosc skalarna.",
      "* Transponowanie macierzy.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    genInfoBlock("MENU POCZATKOWE", {
      "Aby zainicjalizowac program, wybierz jedna opcje z ponizszego menu:",
      "1. Chce przesc do glownego menu wyboru operacji.",
      "2. Chce zakonczyc dzialanie programu.",
    });

    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    switch(choice) {
      case 1: { std::system("cls"); break; }
      case 2: {
        sequentialMess(5, "Program zakonczy dzialanie za");
        std::cout << "\nDziekuje za skorzystanie z kalkulatora macierzy. Program zakonczyl dzialanie.\n";
        exit(0);
      }
      default: {
        error = true;
        errorMess();
        break;
      }
    }
  } while(error);
}

unsigned int chooseTypeOfMatrix() {
  unsigned int choice{0};
  bool error{false};
  std::system("cls");

  do {
    error = false;

    genInfoBlock("ETAP 1", {
      "Wybierz, na jakim typie macierzy chcesz przeprowadzac operacje:",
      "1. Chce przeprowadzac operacje na zwyklej macierzy prostokatnej.",
      "2. Chce przeprowadzac operacje na zwyklej macierzy kwadratowej.",
      "3. Chce przeprowadzac operacje na kwadratowej macierzy diagonalnej."
    });

    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    if(choice != 1 && choice != 2 && choice != 3) {
      error = true;
      errorMess();
    }
  } while(error);
  return choice;
}

unsigned int chooseTypeOfNumbers() {
  unsigned int choice{0};
  bool error{false};
  HANDLE hOut;
  hOut = GetStdHandle( STD_OUTPUT_HANDLE );
  std::system("cls");

  do {
    error = false;

    genInfoBlock("ETAP 2", {
      "Wybierz, na jakim typie wartosci macierzy chcesz przeprowadzac operacje:",
      "1. Chce przeprowadzac operacje tylko i wylacznie na liczbach staloprzecinkowych.",
      "2. Chce przeprowadzac operacje na liczbach staloprzecinkowych i zmiennoprzecinkowych.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jesli wybierzesz tylko liczby staloprzecinkowe, proba zapelnienia macierzy liczbami",
      "zmiennoprzecinkowymi zakonczy sie bledem. Preferowany typ to macierz obslugujaca zarowno",
      "liczby zmiennoprzecinkowe jak i staloprzecinkowe.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    if(choice != 1 && choice != 2) {
      error = true;
      errorMess();
    }
  } while(error);
  return choice;
}


void initialiseObjects() {
  HANDLE hOut;
  hOut = GetStdHandle( STD_OUTPUT_HANDLE );

  unsigned int mtrxType = chooseTypeOfMatrix(); /** typ macierzy (kwadratowa/prostokątna/diagonalna) */
  unsigned int mtrxValType = chooseTypeOfNumbers(); /** typ wartości przekazywany we wzorcu (int/double) */

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  genInfoBlock("POWODZENIE!", {
    "Zapisalem nastepujace parametry:",
    saveMtrxInfo(mtrxType, mtrxValType), /** Informacja, jakiego typu macierz została wybrana */
  });

}



void startPrg() {
  mainMenu();
  initialiseObjects();

}