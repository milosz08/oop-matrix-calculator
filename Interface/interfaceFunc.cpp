#include "interfaceFunc.h"
#include "Auxiliary Functions/auxiliaryFunc.h"

/*!
 *
 * @param hOut
 */
void mainMenu(HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};
  std::system("cls"); /** czyszczenie konsoli */
  do {
    error = false;
    /** Kolor żółty */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n#####################################################\n";
    std::cout << "###############  KALKULATOR MACIERZY  ###############\n";
    std::cout << "#####################################################\n";
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    genInfoBlock("AUTOR", {
      "Napisane w C++ z uzyciem mechanizmow obiektowosci przez Milosz Gilga.",
      "Programowanie Komputerow, Wydzial Elektryczny, Politechnika Slaska, Gliwice.",
      "(c) 2021 by Milosz Gilga (github.com/Milosz08)."
    });
    /** Kolor cyjanowy */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("WSPIERANE OPERACJE", {
      "* Obliczanie wyznacznika macierzy 1, 2 oraz n-elementowej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy odwrotnej wzgledem macierzy pierwotnej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy sprzezonej wzgledem macierzy pierwotnej.",
      "* Podstawowe dzialania arytmetyczne (dodawanie, odejmowanie, mnozenie).",
      "* Mnozenie macierzy przez wartosc skalarna.",
      "* Transponowanie macierzy.",
    });
    /** Kolor biały - reset (wartość domyślna) */
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
        errorMess("Wybrana przez Ciebie opcja menu nie istnieje!");
        break;
      }
    }
  } while(error);
}

/*!
 *
 * @param hOut
 * @return
 */
unsigned int chooseTypeOfMatrix(HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};
  std::system("cls"); /** czyszczenie konsoli */
  do {
    error = false;

    genInfoBlock("ETAP 1", {
      "Wybierz, na jakim typie macierzy chcesz przeprowadzac operacje:",
      "1. Chce przeprowadzac operacje na zwyklej macierzy prostokatnej.",
      "2. Chce przeprowadzac operacje na zwyklej macierzy kwadratowej.",
      "3. Chce przeprowadzac operacje na kwadratowej macierzy diagonalnej."
    });
    /** Kolor cyjanowy */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("INFO", {
      "Macierz diagonalna to macierz, ktora poza swoja glowna przekatna (diagonalna)",
      "posiada wartosci zerowe. Na przekatnej diagonalnej znajda sie podane przez Ciebie wartosci."
    });
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    if(choice != 1 && choice != 2 && choice != 3) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!");
    }
  } while(error);
  return choice;
}

/*!
 *
 * @param hOut
 * @return
 */
unsigned int chooseTypeOfNumbers(HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};
  std::system("cls"); /** czyszczenie konsoli */
  do {
    error = false;

    genInfoBlock("ETAP 2", {
      "Wybierz, na jakim typie wartosci macierzy chcesz przeprowadzac operacje:",
      "1. Chce przeprowadzac operacje tylko i wylacznie na liczbach staloprzecinkowych.",
      "2. Chce przeprowadzac operacje na liczbach staloprzecinkowych i zmiennoprzecinkowych.",
    });
    /** Kolor żółty */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jesli wybierzesz tylko liczby staloprzecinkowe, proba zapelnienia macierzy liczbami",
      "zmiennoprzecinkowymi zakonczy sie bledem. Preferowany typ to macierz obslugujaca zarowno",
      "liczby zmiennoprzecinkowe jak i staloprzecinkowe.",
    });
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    if(choice != 1 && choice != 2) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!");
    }
  } while(error);
  std::system("cls");
  return choice;
}

/*!
 *
 * @param hOut
 * @param mtrxType
 * @param mtrxValType
 * @return
 */
unsigned int* setMtrxSize(HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType) {
  static unsigned int mtrxSizes[2] = {0,0}; /** dla 1 elementu ilość kolumn, dla 2 elementu ilośc wierszy */
  bool error{false};
  do {
    error = false;
    /** Kolor cyjanowy */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("POWODZENIE!", {
      "Zapisalem nastepujace parametry:",
      saveMtrxInfo(mtrxType, mtrxValType), /** Informacja, jakiego typu macierz została wybrana */
    });
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    genInfoBlock("ETAP 3", {
      "Podaj wielkosc macierzy (w formacie ilosc kolumn x ilosc wierszy) dla macierzy",
      "prostokatnych. Dla macierzy kwadratowych oraz diagonalnych podaj jedynie jeden wymiar.",
    });
    /** Kolor żółty */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jesli podasz wiecej elementow, zostana one przeze mnie zignorowane.",
      "W tym polu mozesz podac jedynie liczby calkowite rozne od zera."
    });
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nPodaj ";
    if(mtrxType == 2 || mtrxType == 3) {
      std::cout << "wielkosc macierzy (tylko jeden wymiar): ";
      std::cin >> mtrxSizes[0]; /** Wprowadzenie ilości wierszy/kolumn */
    } else {
      std::cout << "liczbe wierszy i kolumn (w formacie k x w) po spacji: ";
      std::cin >> mtrxSizes[0] >> mtrxSizes[1]; /** Wprowadzenie ilości kolumn i wierszy */
    }
    if(mtrxSizes[0] != 0 || mtrxSizes[1] != 0 || !std::cin.fail()) {
      //for(unsigned int i = 0; i < 2; i++) std::cout << mtrxSizes[i];
    } else {
      error = true;
      errorMess("Podany zostal bledny wymiar macierzy (niedozwolony znak lub liczba 0)!");
    }
  } while (error);
  return mtrxSizes;
}

/*!
 *
 * @param hOut
 */
void initMtrxObj(HANDLE& hOut) {
  unsigned int mtrxType = chooseTypeOfMatrix(hOut); /** typ macierzy (kwadratowa/prostokątna/diagonalna) */
  unsigned int mtrxValType = chooseTypeOfNumbers(hOut); /** typ wartości przekazywany we wzorcu (int/double) */
  /** Przechowalnia ilości wierszy i/lub kolumn */
  unsigned int* sizeOfMatrix = setMtrxSize(hOut, mtrxType, mtrxValType);

}

/*!
 *
 */
void startPrg() {
  HANDLE hOut; /** Obsługa kolorów w konsoli CMD */
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  mainMenu(hOut);
  initMtrxObj(hOut);

}