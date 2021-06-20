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

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "\n#####################################################\n";
    std::cout << "################ KALKULATOR MACIERZY ################\n";
    std::cout << "#####################################################\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    genInfoBlock("AUTOR", {
      "Napisane w C++ z użyciem mechanizmów obiektowosci przez Milosz Gilga.",
      "Programowanie Komputerów, Wydział Elektryczny, Politechnika Ślaska, Gliwice.",
      "(c) 2021 by Milosz Gilga (github.com/Milosz08)."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("WSPIERANE OPERACJE", {
      "* Obliczanie wyznacznika macierzy 1, 2 oraz n-elementowej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy odwrotnej względem macierzy pierwotnej (tylko macierze kwadratowe).",
      "* Obliczanie macierzy sprzężonej względem macierzy pierwotnej.",
      "* Podstawowe działania arytmetyczne (dodawanie, odejmowanie, mnożenie).",
      "* Mnożenie macierzy przez wartość skalarną.",
      "* Transponowanie macierzy.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    genInfoBlock("MENU POCZATKOWE", {
    "Aby zainicjalizowac program, wybierz jedną opcje z poniższego menu:",
    "1. Chcę prześć do głownego menu wyboru operacji.",
    "2. Chcę zakonczyć działanie programu.",
    });

    std::cout << "\nTwój wybór: ";
    std::cin >> choice;
    switch(choice) {
      case 1: {
        std::system("cls"); break;
      } case 2: {
        sequentialMess(5, "Program zakończy działanie za");
        std::cout << "\nDziękuje za skorzystanie z kalkulatora macierzy. Program zakonczył działanie.\n";
        exit(0);
      } default: {
        error = true;
        errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
        break;
      }
    }
  } while(error);
}

/*!
 *
 * @param hOut
 * @param mtrxType
 * @param mtrxValType
 * @return
 */
unsigned short int* setMtrxSize(HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType) {
  static unsigned short int mtrxSizes[2] = {0,0}; /** dla 1 elementu ilość kolumn, dla 2 elementu ilośc wierszy */
  bool error{false};
  do {
    error = false;

    std::cout << "\nZapisałem następujace parametry:\n";
    std::cout << saveMtrxInfo(mtrxType, mtrxValType) << "\n";

    genInfoBlock("ETAP 3", {
      "Podaj wielkość macierzy (w formacie ilość kolumn x ilosc wierszy) dla macierzy",
      "prostokątnych. Dla macierzy kwadratowych oraz diagonalnych podaj jedynie jeden wymiar.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jeśli podasz wiecej elementów, zostaną one przeze mnie zignorowane.",
      "W tym polu możesz podać jedynie liczby całkowite różne od zera."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nPodaj ";
    if(mtrxType == 2 || mtrxType == 3) {
      std::cout << "wielkosc macierzy (tylko jeden wymiar): ";
      std::cin >> mtrxSizes[0]; /** Wprowadzenie ilości wierszy/kolumn */
      mtrxSizes[1] = mtrxSizes[0]; /** Zapełnienie 2 komórki taką samą wartością (kwadratowe) */
    } else {
      std::cout << "liczbę wierszy i kolumn (w formacie k x w) po spacji: ";
      std::cin >> mtrxSizes[0] >> mtrxSizes[1]; /** Wprowadzenie ilości kolumn i wierszy */
    }

    if(!(mtrxSizes[0] != 0 || mtrxSizes[1] != 0 || !std::cin.fail())) {
      error = true;
      errorMess("Podany został błedny wymiar macierzy (niedozwolony znak lub liczba 0)!", hOut);
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

  obj->insertMtrx(hOut); /** Wprowadzanie macierzy */
  do {
    error = false;
    obj->printMtrx(true, true, false); /** Drukowanie macierzy */

    if(obj->get_Cols() == obj->get_Rows()) { /** Macierz kwadratowa */
      strArr = {
        "Wybierz działanie, jakie chcesz wykonać na macierzy:",
        "1. Chcę wprowadzić drugą macierz w celu wykonania operacji arytmetycznych.",
        "2. Chcę pomnożyć macierz przez wartość skalarną.",
        "3. Chcę wyznaczyć macierz sprzężoną z wprowadzonej macierzy.",
        "4. Chcę wyznaczyć macierz transponowaną z wprowadzonej macierzy.",
        "5. Chcę obliczyć wyznacznik z wprowadzonej macierzy.",
        "6. Chcę obliczyć macierz odwrotna z wprowadzonej macierzy."
      };
    } else { /** Macierz prostokątna */
      strArr = {
        "Wybierz działanie, jakie chcesz wykonać na macierzy:",
        "1. Chcę wprowadzić drugą macierz w celu wykonania operacji arytmetycznych.",
        "2. Chcę pomnozyć macierz przez wartość skalarną.",
        "3. Chcę wyznaczyć macierz sprzężoną z wprowadzonej macierzy.",
        "4. Chcę wyznaczyć macierz transponowaną z wprowadzonej macierzy.",
      };
    }

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "\n";
    genInfoBlock("ETAP 4", strArr);

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;

    if(std::cin.fail() || choice < 1 || choice > strArr.size() - 1) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }

  } while(error);
  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}


template<typename T>
unsigned int mathSecondMatrix(MatrixAbstract<T>* objF, MatrixAbstract<T>* objS, HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};

  objS->insertMtrx(hOut); /** Wprowadzanie macierzy */

  do {
    error = false;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("SUKCES!", {
      "Z wprowadzonych przez Ciebie parametrów wygenerowałem poniższe macierze.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nPierwsza wprowadzona przez Ciebie macierz:\n\n";
    objF->printMtrx(false, true, false);

    std::cout << "\nDruga wprowadzona przez Ciebie macierz:\n\n";
    objS->printMtrx(false, true, false);

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "\n";
    genInfoBlock("ETAP 5", {
      "Wybierz działanie, jakie chcesz wykonać na podanych przez Ciebie macierzach:",
      "1. Chcę dodać do siebie wpisane przeze mnie macierze.",
      "2. Chcę odjąć od siebie wpisane przeze mnie macierze.",
      "3. Chcę pomnożyć przez siebie wpisane przeze mnie macierze."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;

    if(std::cin.fail() || choice < 1 || choice > 3) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }

  } while(error);
  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}



template<typename T>
void createMtrxObject(unsigned short int* sizeMtrx, HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType) {
  unsigned int chooseMtrxMath{0}; /** Wybór przez użytkownika operacji matematycznej na macierzy */
  MatrixAbstract<T>* ptr{nullptr}; /** Wzkaźnik wskazujący na obiekt typu T */

  switch(mtrxType) {
    case 1: { /** macierze prostokątne */
      GeneralMatrix<T> rectObj{sizeMtrx[0], sizeMtrx[1]};
      ptr = &rectObj;

      chooseMtrxMath = mathGenrMatrix(ptr, hOut);
      onlyOneMtrxMath<GeneralMatrix<T>, GeneralMatrix<double>, T>(
        chooseMtrxMath, ptr, rectObj, hOut, mtrxType, mtrxValType
      );

      break;
    } case 2: { /** macierze kwadratowe */
      GeneralMatrix<T> sqrObj{sizeMtrx[0]};
      ptr = &sqrObj;

      chooseMtrxMath = mathGenrMatrix(ptr, hOut);
      onlyOneMtrxMath<GeneralMatrix<T>, GeneralMatrix<double>, T>(
        chooseMtrxMath, ptr, sqrObj, hOut, mtrxType, mtrxValType
      );

      break;
    } case 3: { /** macierze diagonalne */
      DiagonalMatrix<T> diagObj{sizeMtrx[0]};
      ptr = &diagObj;

      chooseMtrxMath = mathGenrMatrix(ptr, hOut);
      onlyOneMtrxMath<DiagonalMatrix<T>, DiagonalMatrix<double>, T>(
        chooseMtrxMath, ptr, diagObj, hOut, mtrxType, mtrxValType
      );

      break;
    }
  }
}

template<class M>
void secondMtrxMathInfo(M& objF, M& objS, M& objFinal, HANDLE& hOut, std::vector<std::string>infMess) {

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  genInfoBlock("SUKCES!", { infMess[0],
    "Poniżej wyświetlam dwie macierze pierwotne i macierz wynikową."
  });

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  std::cout << "\nPierwsza macierz pierwotna:\n\n";
  objF.printMtrx(false, true, false);

  std::cout << "\n" << infMess[1] << "\n\n";
  objS.printMtrx(false, true, false);

  std::cout << "\ndała nastepujacą macierz wynikową:\n\n";
  objFinal.printMtrx(false, true, false);
}

/*!
 *
 * @param hOut
 */
void initMtrxObj(HANDLE& hOut) {
  unsigned int mtrxType = chooseTypeOfMatrix(hOut); /** typ macierzy (kwadratowa/prostokątna/diagonalna) */
  unsigned int mtrxValType = chooseTypeOfNumbers(hOut); /** typ wartości przekazywany we wzorcu (int/double) */

  /** Przechowalnia ilości wierszy i/lub kolumn */
  unsigned short int* sizeMtrx = setMtrxSize(hOut, mtrxType, mtrxValType);

  if(mtrxValType == 1) { /** Macierz tylko znaki stałoprzecinkowe */
    createMtrxObject<short int>(sizeMtrx, hOut, mtrxType, mtrxValType);
  } else { /** Macierz znaki zmienno i stałoprzecinkowe */
    createMtrxObject<double>(sizeMtrx, hOut, mtrxType, mtrxValType);
  }
}

/*!
 *
 * @tparam M
 * @tparam T
 * @param ptr
 * @param outObj
 * @param hOut
 * @param infMess
 */
template<class M, typename T>
void onlyOneMtrxMathInfo(MatrixAbstract<T>* ptr, M& outObj, HANDLE& hOut, std::vector<std::string>infMess) {

  std::system("cls"); /** Czyszczenie konsoli przed wypisaniem podsumowania */

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  genInfoBlock("INFO", { infMess[0],
    "Poniżej wyświetlam macierz pierwotną i macierz wynikową."
  });

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  std::cout << "\nMacierz pierwotna:\n\n";
  ptr->printMtrx(false, true, false); /** Drukuje macierz pierwotną na podstawie wskaźnika */

  std::cout << "\n" << infMess[1] <<"\n";
  std::cout << "dała nastepujacą macierz wynikową:\n\n";
  outObj.printMtrx(false, true, false); /** Drukuje macierz wynikową na podstawie obiektu */
}

/*!
 *
 * @tparam M
 * @tparam T
 * @param choose
 * @param obj
 * @param hOut
 */
template<class M, class I, typename T>
void onlyOneMtrxMath(unsigned int& choose,MatrixAbstract<T>* ptr, M& obj, HANDLE& hOut,
                     unsigned int& mtrxType, unsigned int& mtrxValType) {
  switch(choose) {
    case 1: { /** Operacje arytmetyczne na dwóch macierzach */
      unsigned int chooseMath{0};

      /** Przechowalnia ilości wierszy i/lub kolumn */
      unsigned short int* sizeMtrx = setMtrxSize(hOut, mtrxType, mtrxValType);
      MatrixAbstract<T>* ptrS{nullptr}; /** Wzkaźnik wskazujący na obiekt typu T */

      M secondObj{sizeMtrx[0], sizeMtrx[1]};
      ptrS = &secondObj;

      chooseMath = mathSecondMatrix<T>(ptr, ptrS, hOut);
      secondMtrxMath<M>(chooseMath, obj, secondObj, hOut);

      break;
    } case 2: { /** Mnożenie macierzy przez skalar */
      T scalar = ptr->scalarValuePush(hOut);
      M afterScl = obj * scalar;

      onlyOneMtrxMathInfo<M, T>(ptr, afterScl, hOut, {
        "Pomnożenie macierzy przez skalar przebiegło pomyślnie!",
        "pomnożona przez wartość skalarną"
      });

      break;
    } case 3: { /** Macierz sprzężona */
      M afterCpl = obj.coupledMtrx();

      onlyOneMtrxMathInfo<M, T>(ptr, afterCpl, hOut, {
        "Wykonanie operacji sprzężenia macierzy przebiegło pomyślnie!",
        "w wyniku operacji sprzeżenia (odwrócenia znaku)"
      });

      break;
    } case 4: { /** Macierz transponowana */
      M afterTrsp = obj.transposeMtrx();

      onlyOneMtrxMathInfo<M, T>(ptr, afterTrsp, hOut, {
        "Wykonanie operacji transpozycji macierzy przebiegło pomyślnie!",
        "w wyniku operacji transpozycji (zamiana wierszy/kolumn na kolumny/wiersze)"
      });

      break;
    } case 5: { /** Wyznacznik z macierzy (tylko kwadratowe) */
      T detOfMtrx = obj.determinantMtrx(hOut);

      std::system("cls"); /** Czyszczenie konsoli przed wypisaniem podsumowania */

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      genInfoBlock("INFO", {
        "Poniżej wyświetlam macierz pierwotną i wyznaczony",
        "przeze mnie wyznacznik tej macierzy."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

      std::cout << "\nZ macierzy pierwotnej (A):\n\n";
      ptr->printMtrx(false, false, false); /** Drukuje macierz pierwotną z obiektu na podstawie wskaźnika */

      std::cout << "\nwyznaczyłem następujacy wyznacznik (determinant):\n\n";
      std::cout.precision(3); /** Zaokrąglenie wyniku do 3 miejsc po przecinku */
      std::cout << "  det(A): " << std::fixed << detOfMtrx << "\n";

      break;
    } case 6: { /** Macierz odwrotna (tylko kwadratowe) */
      I afterInvr = obj.inverseMtrx();

      std::system("cls"); /** Czyszczenie konsoli przed wypisaniem podsumowania */

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      genInfoBlock("INFO", {
        "Wykonanie operacji wyznaczenia macierzy odwrotnej przebiegło pomyslnie!",
        "Poniżej wyswietlam macierz pierwotną i macierz wynikową."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

      std::cout << "\nMacierz pierwotna:\n\n";
      ptr->printMtrx(false, true, false); /** Drukuje macierz pierwotną z obiektu na podstawie wskaźnika */

      std::cout << "\npo dokonaniu operacji odwrócenia\ndała następujacą macierz wynikową:\n\n";
      std::cout.precision(6); /** Zaokrąglenie wyniku do 6 miejsc po przecinku */
      std::cout << std::fixed;
      afterInvr.printMtrx(false, true, true);

      break;
    }
  }
}

template<class M>
void secondMtrxMath(unsigned int& choose,  M& objF, M& objS, HANDLE& hOut) {
  switch(choose) {
    case 1: { /** Dodawanie macierzy */
      M objAdd = objF + objS;

      secondMtrxMathInfo(objF, objS, objAdd, hOut, {
        "Dodanie do siebie dwóch macierzy pierwotnych przebiegło pomyślnie.",
        "po dodaniu do niej drugiej macierzy pierwotnej"
      });

      break;
    } case 2: { /** Odejmowanie macierzy */
      M objSub = objF - objS;

      secondMtrxMathInfo(objF, objS, objSub, hOut, {
        "Odjęcie od siebie dwóch macierzy pierwotnych przebiegło pomyślnie.",
        "po odjęciu od niej drugiej macierzy pierwotnej"
      });

      break;
    } case 3: { /** Mnożenie macierzy */
      M objMlt = objF * objS;

      secondMtrxMathInfo(objF, objS, objMlt, hOut, {
        "Pomnożenie przez siebie dwóch macierzy pierwotnych przebiegło pomyślnie.",
        "po pomnożeniu przez nią drugiej macierzy pierwotnej"
      });

      break;
    }
  }
}


/*!
 *
 */
void startPrg() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); /** Obsługa kolorów w konsoli CMD */

  try {

    mainMenu(hOut);
    initMtrxObj(hOut);

  } catch(std::logic_error& e) {

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("Error!", {
      "Błąd podczas wykonywania operacji matematycznej.", e.what(),
      "Błąd ten skutkuje zakończeniem działania programu."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nDziękuję za skorzystanie z kalkulatora macierzy.\n";
    sequentialMess(5, "Program zakończy działanie za");
    std::cout << "\nProgram zakończył działanie!\n";
  }
}