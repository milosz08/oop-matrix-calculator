#include "../../interfaceDecl.hpp"


/*!
 * @fn secondMtrxMath(unsigned int& choose,  M& objF, M& objS, HANDLE& hOut)
 *
 * @brief Funkcja wykonująca operacje matematyczne na dwóch macierzach (dodawanie, odejmowanie, mnożenie) na
 *        podstawie obiektów klasy wzorca M przekazywanych w argumentach funkcji.
 *
 * @tparam M - wzorzec reprezentujący klasę jako typ danych (klasa GeneralMatrix<T> lub DiagonalMatrix<T>).
 *
 * @param choose - wybór wykonywanego działania przez użytkownika (1 - dodawanie, 2 - odejmowanie, 3 - mnożenie).
 *
 * @param objF - obiekt klasy ustalanej wg wzorca M przechowujący pierwszą macierz wprowadzoną przez użytkownika.
 * @param objS - obiekt klasy ustalanej wg wzorca M przechowujący drugą macierz prowadzoną przez użytkownika.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 */
template<class M>
void secondMtrxMath(unsigned short int& choose, M& objF, M& objS, HANDLE& hOut) {
  switch(choose) {
    case 1: { /** @skip Dodawanie macierzy */
      M objAdd = objF + objS;

      secondMtrxMathInfo(objF, objS, objAdd, hOut, {
        "Dodanie do siebie dwóch macierzy pierwotnych przebiegło pomyślnie.",
        "po dodaniu do niej drugiej macierzy pierwotnej"
      });

      break;
    } case 2: { /** @skip Odejmowanie macierzy */
      M objSub = objF - objS;

      secondMtrxMathInfo(objF, objS, objSub, hOut, {
        "Odjęcie od siebie dwóch macierzy pierwotnych przebiegło pomyślnie.",
        "po odjęciu od niej drugiej macierzy pierwotnej"
      });

      break;
    } case 3: { /** @skip Mnożenie macierzy */
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
 * @fn secondMtrxMathInfo(M& objF, M& objS, M& objFinal, HANDLE& hOut, std::vector<std::string>infMess)
 *
 * @brief Funkcja pomocnicza, dopełnienie funkcji "secondMtrxMath". Wyświetla informacje na temat wprowadzonych
 *        dwóch macierzy pierwotnych (przekazywanych jako obiekty klasy na podstawie wzorca M), drukowanie ich oraz
 *        wyświetla informacje na temat macierzy wynikowej (przekazywanej w argumentach funkcji jako obiekt klasy
 *        na podstawie wzorca M).
 *
 * @tparam M - wzorzec reprezentujący klasę jako typ danych (klasa GeneralMatrix<T> lub DiagonalMatrix<T>).
 * @tparam A - wartość szablonu klasy abstrakcyjnej (używane tylko do metody z klasy abstrakcyjnej
 *             "genInfoBlock" przy operatorze zakresu).
 *
 * @param objF - obiekt klasy ustalanej wg wzorca M przechowujący pierwszą macierz (przekazywany przez referencję
 *               z funkcji "secondMtrxMath").
 *
 * @param objS - obiekt klasy ustalanej wg wzorca M przechowujący drugą macierz (przekazywany przez referencję
 *               z funkcji "secondMtrxMath").
 *
 * @param objFinal - obiekt klasy ustalanej wg wzorca M przechowujący macierz po wykonaniu działań arytmetycznych
 *                   (macierz wynikowa), (przekazywany przez referencję z funkcji "secondMtrxMath").
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @param infMess - wektor typu string reprezentujący przekazywane wiadomości wstawiane dynamicznie.
 */
template<class M>
void secondMtrxMathInfo(M& objF, M& objS, M& objFinal, HANDLE& hOut, std::vector<std::string>infMess) {

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  MatrixAbstract<double>::genInfoBlock("SUKCES!", { infMess[0],
    "Poniżej wyświetlam dwie macierze pierwotne i macierz wynikową."
  });

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  std::cout << "\nPierwsza macierz pierwotna:\n\n";
  objF.printMtrx(hOut, false, true);

  std::cout << "\n" << infMess[1] << "\n\n";
  objS.printMtrx(hOut, false, true);

  std::cout << "\ndała nastepujacą macierz wynikową:\n\n";
  objFinal.printMtrx(hOut, false, true);
}