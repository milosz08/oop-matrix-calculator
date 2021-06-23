#include "../../interfaceDecl.hpp"


/*!
 * @fn onlyOneMtrxMath(unsigned int& choose,MatrixAbstract<T>* ptr, M& obj, HANDLE& hOut,
 *                     unsigned int& mtrxType, unsigned int& mtrxValType)
 *
 * @brief Funkcja wykonują odpowiednią operację matematyczną (wybraną przez użytkownika, na podstawie wartości w
 *        zmiennej choose). Jeśli użytkownik wybierze opcję 1, funkcja umożliwi wpisanie drugiej macierzy poprzez
 *        powołanie do życia objektu z klasy na podstawie wartości wzorca M, wybranie wielkości macierzy oraz jej
 *        wprowadzenie.
 *
 * @tparam M - wzorzec reprezentujący klasę jako typ danych (klasa GeneralMatrix<T> lub DiagonalMatrix<T>).
 * @tparam I - wzorzec reprezentujący klasę z przypisaną wartością double jako typ danych dla zapisania macierzy
 *             odwrotnej (klasa GeneralMatrix<double> lub DiagonalMatrix<double>).
 *
 * @tparam T - wzorzec, który reprezentuje wartości jakimi można zapełnić macierz (int/double).
 * @tparam A - wartość szablonu klasy abstrakcyjnej (używane tylko do metody z klasy abstrakcyjnej
 *             "genInfoBlock" przy operatorze zakresu).
 *
 * @param choose - zmienna przechowująca wybór operacji matematycznej dokonanej przez użytkownika.
 *
 * @param ptr - wskaźnik klasy abstrakcyjnej wskazujący na wybrany obiekt klasy dziedziczącej po klasie abstrakcyjnej.
 *
 * @param obj - obiekt klasy (na podstawie wzorca M) przekazywany przez referencję
 *              (tworzony w funkcji "createMtrxObject").
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @param mtrxType - typ macierzy, odpowiednio: 1 - macierz prostokątna, 2 - macierz kwadratowa, 3 - macierz diagonalna.
 *
 * @param mtrxValType - typ wartości jakimi użytkownik może wypełnić macierz. Odpowiednio: 1 - tylko dla wartości
 *                      całkowitych, 2 - dla wartości całkowitych oraz zmiennoprzecinkowych (double).
 */
template<class M, class I, typename T>
void onlyOneMtrxMath(unsigned int& choose, MatrixAbstract<T>* ptr, M& obj, HANDLE& hOut,
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
      MatrixAbstract<double>::genInfoBlock("INFO", {
        "Poniżej wyświetlam macierz pierwotną i wyznaczony",
        "przeze mnie wyznacznik tej macierzy."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

      std::cout << "\nZ macierzy pierwotnej (A):\n\n";
      ptr->printMtrx(hOut, false, false, false); /** Drukuje macierz pierwotną z obiektu na podstawie wskaźnika */

      std::cout << "\nwyznaczyłem następujacy wyznacznik (determinant):\n\n";
      std::cout.precision(3); /** Zaokrąglenie wyniku do 3 miejsc po przecinku */
      std::cout << "  det(A): " << std::fixed << detOfMtrx << "\n";

      break;
    } case 6: { /** Macierz odwrotna (tylko kwadratowe) */
      I afterInvr = obj.inverseMtrx();

      std::system("cls"); /** Czyszczenie konsoli przed wypisaniem podsumowania */

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
      MatrixAbstract<double>::genInfoBlock("INFO", {
        "Wykonanie operacji wyznaczenia macierzy odwrotnej przebiegło pomyslnie!",
        "Poniżej wyswietlam macierz pierwotną i macierz wynikową."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

      std::cout << "\nMacierz pierwotna:\n\n";
      ptr->printMtrx(hOut, false, true, false); /** Drukuje macierz pierwotną z obiektu na podstawie wskaźnika */

      std::cout << "\npo dokonaniu operacji odwrócenia\ndała następujacą macierz wynikową:\n\n";
      std::cout.precision(6); /** Zaokrąglenie wyniku do 6 miejsc po przecinku */
      std::cout << std::fixed;
      afterInvr.printMtrx(hOut, false, true, true);

      break;
    }
  }
}


/*!
 * @fn onlyOneMtrxMathInfo(MatrixAbstract<T>* ptr, M& outObj, HANDLE& hOut, std::vector<std::string>infMess)
 *
 * @brief Funkcja pomocnicza, dopełnienie funkcji "onlyOneMtrxMath". Wyświetla informacje na temat wprowadzonej
 *        macierzy pierwotnej (przekazywanej poprzez wskaźnik klasy abstrakcyjnej), drukuje ją oraz wyświetla
 *        informacje na temat macierzy wynikowej (przekazywanej w argumentach funkcji jako obiekt klasy wzorca M).
 *
 * @tparam M - wzorzec reprezentujący klasę jako typ danych (klasa GeneralMatrix<T> lub DiagonalMatrix<T>).
 *
 * @tparam T - wzorzec, który reprezentuje wartości jakimi można zapełnić macierz (int/double).
 * @tparam A - wartość szablonu klasy abstrakcyjnej (używane tylko do metody z klasy abstrakcyjnej
 *             "genInfoBlock" przy operatorze zakresu).
 *
 * @param ptr - wskaźnik klasy abstrakcyjnej wskazujący na obiekt przechowujący macierz pierwotną
 *
 * @param outObj - obiekt klasy wzorca M przechowujący macierz wynikową
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @param infMess - wektor typu string reprezentujący przekazywane wiadomości wstawiane dynamicznie.
 */
template<class M, typename T>
void onlyOneMtrxMathInfo(MatrixAbstract<T>* ptr, M& outObj, HANDLE& hOut, std::vector<std::string>infMess) {

  std::system("cls"); /** Czyszczenie konsoli przed wypisaniem podsumowania */

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  MatrixAbstract<double>::genInfoBlock("INFO", { infMess[0],
    "Poniżej wyświetlam macierz pierwotną i macierz wynikową."
  });

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  std::cout << "\nMacierz pierwotna:\n\n";
  ptr->printMtrx(hOut, false, true, false); /** Drukuje macierz pierwotną na podstawie wskaźnika */

  std::cout << "\n" << infMess[1] <<"\n";
  std::cout << "dała nastepujacą macierz wynikową:\n\n";
  outObj.printMtrx(hOut, false, true, false); /** Drukuje macierz wynikową na podstawie obiektu */
}

#include "../mathSecondMtrx/mathChooseMtrx.tpp"
#include "../mathSecondMtrx/mathMtrx.tpp"