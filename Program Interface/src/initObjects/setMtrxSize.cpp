#include "../interfaceDecl.hpp"


/*!
 * @fn setMtrxSize(HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType)
 *
 * @brief Funkcja umożliwia wprowadzenie przez użytkownika parametrów dotyczących wielkości macierzy. Dla macierzy
 *        kwadratowych program prosi użytkownika o wpisanie tylko jednego parametru. Dla macierzy prostokątnych
 *        należy wpisać 2 parametry (ilość wierszy i ilość kolumn).<br>
 *
 *        Funkcja posiada walidację strumienia wejścia. Jeśli użytkownik nie poda liczby z zakresu 1-3 program
 *        zasygnalizuje błąd i po odczekaniu 5 sekund umożliwi użytkownikowi ponowne wybranie opcji.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @param mtrxType - typ macierzy. Przyjmuje dla wartości:
 *           * 1 -> macierz prostokątna,
 *           * 2 -> macierz zwykła kwadratowa,
 *           * 3 -> macierz diagonalna (typ macierzy kwadratowej).
 *
 * @param mtrxValType - typ wartości, jakie użytkownik może wprowadzić do macierzy. Przyjmuje dla wartości:
 *          * 1 -> tylko wartości całkowite (integer),
 *          * 2 -> wartości całkowite oraz zmiennoprzecinkowe (double).
 *
 * @return Funkcja zwraca wskaźnik do tablicy statycznej przechowującej ilość wierszy i kolumn (w przypadku podawania
 *         tylko jednej wartości, obie wartości w tablicy przyjmują jednakową wartość).
 */
unsigned short int* setMtrxSize(HANDLE& hOut, unsigned short int& mtrxType, unsigned short int& mtrxValType) {

  /** @skip Static użyte w celu zwrócenia wartości zmiennej lokalnej, transformacja na zmienną globalną,
   * dla 1 elementu ilość kolumn, dla 2 elementu ilośc wierszy */
  static unsigned short int mtrxSizes[2] = {0,0};
  bool error{false};

  do {
    error = false;

    std::cout << "\nZapisałem następujace parametry:\n";
    std::cout << saveMtrxInfo(mtrxType, mtrxValType) << "\n";

    MatrixAbstract<double>::genInfoBlock("ETAP 3", {
      "Podaj wielkość macierzy (w formacie ilość kolumn x ilosc wierszy) dla macierzy",
      "prostokątnych. Dla macierzy kwadratowych oraz diagonalnych podaj jedynie jeden wymiar.",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("UWAGA!", {
      "Jeśli podasz wiecej elementów, zostaną one przeze mnie zignorowane.",
      "W tym polu możesz podać jedynie liczby całkowite różne od zera."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nPodaj ";
    if(mtrxType == 2 || mtrxType == 3) {
      std::cout << "wielkosc macierzy (tylko jeden wymiar): ";
      std::cin >> mtrxSizes[0]; /** @skip Wprowadzenie ilości wierszy/kolumn */
      mtrxSizes[1] = mtrxSizes[0]; /** @skip Zapełnienie 2 komórki taką samą wartością (kwadratowe) */
    } else {
      std::cout << "liczbę wierszy i kolumn (w formacie k x w) po spacji: ";
      std::cin >> mtrxSizes[0] >> mtrxSizes[1]; /** @skip Wprowadzenie ilości kolumn i wierszy */
    }

    if(mtrxSizes[0] == 0 || mtrxSizes[1] == 0 || mtrxSizes[0] > 20 || mtrxSizes[1] > 20 || std::cin.fail()) {
      error = true;
      MatrixAbstract<double>::errorMess(
        "Podany został błedny wymiar macierzy (niedozwolony znak, zbyt duży wymiar lub liczba 0)!",
        hOut
      );
    }

  } while (error);
  std::system("cls"); /** @skip czyszczenie konsoli */
  return mtrxSizes;
}


/*!
 * @fn saveMtrxInfo(unsigned int& type, unsigned int& val)
 *
 * @brief Funkcja uzupełniająca funkcję "setMtrxSize". W zależności od wyborów użytkownika w funkcjach "chooseMtrxType"
 *        oraz w "chooseNmbrType" drukuje komunikat o zapisanych parametrach macierzy.
 *
 * @param type - typ macierzy, odpowiednio: 1 - macierz prostokątna, 2 - macierz kwadratowa, 3 - macierz diagonalna.
 *
 * @param val - typ wartości jakimi użytkownik może wypełnić macierz. Odpowiednio: 1 - tylko dla wartości całkowitych,
 *              2 - dla wartości całkowitych oraz zmiennoprzecinkowych (double).
 *
 * @return Funkcja zwraca wynikowy string z całym zapisanym komunikatem.
 */
std::string saveMtrxInfo(unsigned short int& type, unsigned short int& val) {
  std::string output;

  switch(type) {
    case 1: { /** @skip type 1 = macierz prostokątna */
      output = "Macierz prostokątna "; break;
    } case 2: { /** @skip type 2 = macierz kwadratowa */
      output = "Macierz kwadratowa "; break;
    } case 3: { /** @skip type 3 = macierz diagonalna */
      output = "Macierz diagonalna "; break;
    }
  }

  output += "możliwa do zapełnienia\n";

  switch(val) {
    case 1: { /** @skip val 1 = jedynie wartości stałoprzecinkowe */
      output += "jedynie wartościami stałoprzecinkowymi."; break;
    } case 2: { /** @skip val 1 = wartości stałoprzecinkowe oraz zmiennoprzecinkowe */
      output += "zarowno wartościami stało oraz zmiennoprzecinkowymi."; break;
    }
  }

  return output;
}