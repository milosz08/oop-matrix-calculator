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

    ///** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    std::cout << "\nTwoj wybor: ";
    std::cin >> choice;
    if(std::cin.fail() || choice < 1 || choice > strArr.size() - 1) {
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
 */
unsigned int initMtrxObj(HANDLE& hOut) {
  unsigned int mtrxType = chooseTypeOfMatrix(hOut); /** typ macierzy (kwadratowa/prostokątna/diagonalna) */
  unsigned int mtrxValType = chooseTypeOfNumbers(hOut); /** typ wartości przekazywany we wzorcu (int/double) */
  /** Przechowalnia ilości wierszy i/lub kolumn */
  unsigned int* sizeMtrx = setMtrxSize(hOut, mtrxType, mtrxValType);
  unsigned int chooseMtrxMath{0}; /** Wybór przez użytkownika operacji matematycznej na macierzy */

  MatrixAbstract<int>* ptrAbstIntObj; /** Wzkaźnik na klase abstrakcyjną z parametrem typy int */
  MatrixAbstract<double>* ptrAbstDblObj; /** Wzkaźnik na klase abstrakcyjną z parametrem typy double */

  switch(mtrxType) {
    case 1: { /** Macierze prostokątne */
      if(mtrxValType == 1) {
        GeneralMatrix<int> mRectInt{sizeMtrx[0], sizeMtrx[1]};
        ptrAbstIntObj = &mRectInt;
        chooseMtrxMath = mathGenrMatrix(ptrAbstIntObj, hOut);
      } else {
        GeneralMatrix<double> mRectDbl{sizeMtrx[0], sizeMtrx[1]};
        ptrAbstDblObj = &mRectDbl;
        chooseMtrxMath = mathGenrMatrix(ptrAbstDblObj, hOut);
      }
      break;
    } default: { /** Macierze kwadratowe (zwykła / diagonalna) */
      switch(mtrxType) {
        case 2: { /** Macierz kwadratowa zwykła */
          if(mtrxValType == 1) {
            GeneralMatrix<int> mSqrInt{sizeMtrx[0]};
            ptrAbstIntObj = &mSqrInt;
            chooseMtrxMath = mathGenrMatrix(ptrAbstIntObj, hOut);
          } else {
            GeneralMatrix<double> mRectDbl{sizeMtrx[0]};
            ptrAbstDblObj = &mRectDbl;
            chooseMtrxMath = mathGenrMatrix(ptrAbstDblObj, hOut);
          }
          break;
        } case 3: { /** Macierz diagonalna */
          if(mtrxValType == 1) {
            DiagonalMatrix<int> mDiagInt{sizeMtrx[0]};
            ptrAbstIntObj = &mDiagInt;
            chooseMtrxMath = mathGenrMatrix(ptrAbstIntObj, hOut);
          } else {
            DiagonalMatrix<double> mDiagDbl{sizeMtrx[0]};
            ptrAbstDblObj = &mDiagDbl;
            chooseMtrxMath = mathGenrMatrix(ptrAbstDblObj, hOut);
          }
          break;
        }
      }
      break;
    }
  }
  delete ptrAbstIntObj; /** Wywóz śmieci tak o xD */
  delete ptrAbstDblObj;
  return chooseMtrxMath;
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