#include "../../interfaceDecl.hpp"


/*!
 * @fn mathChooseMtrx(MatrixAbstract<T>* obj, HANDLE& hOut)
 *
 * @brief Funkcja pobierająca od użytkownika typ operacji, jaką ma wykonać program na jednej macierzy. W zależności od
 *        wskaźnika "obj", funkcja umożliwia wprowadzenie macierzy prostokątnej, kwadratowej lub diagonalnej. Opcje dla
 *        macierzy kwadratowych są inne od opcji dla macierzy prostokątnych (wyznacznik i macierz odwrotna - tylko
 *        kwadratowe).
 *
 * @protection Funkcja posiada walidację strumienia wejścia. Jeśli użytkownik nie poda liczby z zakresu 1-6
 *             (dla macierzy kwadratowych) lub 1-4 (dla macierzy prostokątnych) program zasygnalizuje
 *             błąd i po odczekaniu 5 sekund umożliwi użytkownikowi ponowne wybranie opcji.
 *
 * @tparam T - wzorzec, który reprezentuje wartości jakimi można zapełnić macierz (int/double).
 * @tparam A - wartość szablonu klasy abstrakcyjnej (używane tylko do metody z klasy abstrakcyjnej
 *             "genInfoBlock" oraz "errorMess" przy operatorze zakresu).
 *
 * @param obj - wskaźnik klasy abstrakcyjnej wskazujący na aktualnie obsługiwany obiekt klasy pochodnej.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @return Funkcja zwraca opcję wybraną przez użytkownika (w postaci wartości całkowitej) z zakresu 1-6 (macierze
 *         kwadratowe) lub 1-4 (macierze prostokątne).
 */
template<typename T>
unsigned short int mathChooseMtrx(MatrixAbstract<T>* obj, HANDLE& hOut) {
  unsigned short int choice{0};
  std::vector<std::string>strArr; /** Tablica przechowująca zawartość menu do wydrukowania */
  bool error{false};

  obj->insertMtrx(hOut); /** Wprowadzanie macierzy */
  do {
    error = false;
    obj->printMtrx(hOut, true, true); /** Drukowanie macierzy */

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
    MatrixAbstract<double>::genInfoBlock("ETAP 4", strArr);

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;

    if(std::cin.fail() || choice < 1 || choice > strArr.size() - 1) {
      error = true;
      MatrixAbstract<double>::errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }

  } while(error);
  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}