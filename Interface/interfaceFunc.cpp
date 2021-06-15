#include "interfaceFunc.h"
#include "Auxiliary Functions/auxiliaryFunc.h"

/*!
 *
 * @param hOut
 */
void mainMenu(HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};
  do {
    error = false;
    /** Kolor żółty */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n#####################################################\n";
    std::cout << "################ KALKULATOR MACIERZY ################\n";
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
  std::system("cls"); /** czyszczenie konsoli */
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

    std::cout << "\nZapisalem nastepujace parametry:\n";
    std::cout << saveMtrxInfo(mtrxType, mtrxValType) << "\n";

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
    if(!(mtrxSizes[0] != 0 || mtrxSizes[1] != 0 || !std::cin.fail())) {
      error = true;
      errorMess("Podany zostal bledny wymiar macierzy (niedozwolony znak lub liczba 0)!");
    }
  } while (error);
  std::system("cls"); /** czyszczenie konsoli */
  return mtrxSizes;
}

/*!
 *
 * @tparam T
 * @param obj
 * @param hOut
 */
template<typename T>
unsigned int mathGenrMatrix(MatrixAbstract<T>* obj, HANDLE& hOut) {
  unsigned int choice{0};
  std::vector<std::string>strArr; /** Tablica przechowująca zawartość menu do wydrukowania */
  bool error{false};

  obj->insertMtrx(); /** Wprowadzanie macierzy */
  do {
    error = false;
    obj->printMtrx(true, true); /** Drukowanie macierzy */

    if(obj->get_Cols() == obj->get_Rows()) { /** Macierz kwadratowa */
      strArr = {
        "Wybierz dzialanie, jakie chcesz wykonac na macierzy:",
        "1. Chce wprowadzic druga macierz w celu wykonania operacji arytmetycznych.",
        "2. Chce pomnozyc macierz przez wartosc skalara.",
        "3. Chce wyznaczyc macierz sprzezona z wprowadzonej macierzy.",
        "4. Chce wyznaczyc macierz transponowana z wprowadzonej macierzy.",
        "5. Chce obliczyc wyznacznik z wprowadzonej macierzy.",
        "6. Chce obliczyc macierz odwrotna z wprowadzonej macierzy."
      };
    } else { /** Macierz prostokątna */
      strArr = {
        "Wybierz dzialanie, jakie chcesz wykonac na macierzy:",
        "1. Chce wprowadzic druga macierz w celu wykonania operacji arytmetycznych.",
        "2. Chce pomnozyc macierz przez wartosc skalara.",
        "3. Chce wyznaczyc macierz sprzezona z wprowadzonej macierzy.",
        "4. Chce wyznaczyc macierz transponowana z wprowadzonej macierzy.",
      };
    }

    /** Kolor cyjanowy */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "\n";
    genInfoBlock("ETAP 4", strArr);

    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    if(std::cin.fail() || choice < 1 || choice > strArr.size() - 1) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!");
    }
  } while(error);
  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}

template<typename T>
unsigned int createMtrxObject(unsigned int* sizeMtrx, HANDLE& hOut, unsigned int& mtrxType) {
  unsigned int chooseMtrxMath{0}; /** Wybór przez użytkownika operacji matematycznej na macierzy */
  MatrixAbstract<T>* ptr{nullptr}; /** Wzkaźnik wskazujący na obiekt klasy abstrakcyjną typu T */

  if(mtrxType == 1) {
    GeneralMatrix<T> rectObj{sizeMtrx[0], sizeMtrx[1]};
    ptr = &rectObj;
    chooseMtrxMath = mathGenrMatrix(ptr, hOut);
  } else if(mtrxType == 2) {
    GeneralMatrix<T> sqrObj{sizeMtrx[0]};
    ptr = &sqrObj;
    chooseMtrxMath = mathGenrMatrix(ptr, hOut);
  } else if(mtrxType == 3) {
    DiagonalMatrix<T> diagObj{sizeMtrx[0]};
    ptr = &diagObj;
    chooseMtrxMath = mathGenrMatrix(ptr, hOut);
  }

  return chooseMtrxMath;
}

/*!
 *
 * @param hOut
 */
unsigned int initMtrxObj(HANDLE& hOut) {
  unsigned int mtrxType = chooseTypeOfMatrix(hOut); /** typ macierzy (kwadratowa/prostokątna/diagonalna) */
  unsigned int mtrxValType = chooseTypeOfNumbers(hOut); /** typ wartości przekazywany we wzorcu (int/double) */
  /** Przechowalnia ilości wierszy i/lub kolumn */
  unsigned int* sizeMtrx = setMtrxSize(hOut, mtrxType, mtrxValType);
  unsigned int chooseMtrxMath{0}; /** Wybór przez użytkownika operacji matematycznej na macierzy */

  if(mtrxValType == 1) { /** Macierz tylko znaki stałoprzecinkowe */
    chooseMtrxMath = createMtrxObject<int>(sizeMtrx, hOut, mtrxType);
  } else { /** Macierz znaki zmienno i stałoprzecinkowe */
    chooseMtrxMath = createMtrxObject<double>(sizeMtrx, hOut, mtrxType);
  }

  return chooseMtrxMath;
}

void mtrxMathInit(HANDLE& hOut) {
  unsigned int choose = initMtrxObj(hOut);
  std::cout << choose << "\n";
}


/*!
 *
 */
void startPrg() {
  HANDLE hOut; /** Obsługa kolorów w konsoli CMD */
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  mainMenu(hOut);
  mtrxMathInit(hOut);

}