#include "../../interfaceDecl.hpp"


/*!
 * @fn createMtrxObject(unsigned short int* sizeMtrx, HANDLE& hOut, unsigned int& mtrxType, unsigned int& mtrxValType)
 *
 * @brief Funkcja sterująca. Powołuje ona do życia obiekty na podstawie wzorca z funkcji "initMtrxObj". Wywołuje ona
 *        poszczególne funkcje sterujące dalszym przebiegiem programu. Są to odpowiednio: wybór operacji spośród
 *        możliwych do wykonania na jednej macierzy, oraz na podstawie tego wyboru zastosowanie na macierzy (obiekcie)
 *        wybranej operacji matematycznej.
 *
 * @tparam T - wzorzec, który wskazuje na wartości jakimi można zapełnić macierz (int/double)
 *
 * @param sizeMtrx - wskaźnik wskazujący na jednowymiarową tablicę statyczną dwuelementową przechowującą liczbę wierszy
 *                   oraz liczbę kolumn macierzy.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @param mtrxType - typ macierzy, odpowiednio: 1 - macierz prostokątna, 2 - macierz kwadratowa, 3 - macierz diagonalna.
 *
 * @param mtrxValType - typ wartości jakimi użytkownik może wypełnić macierz. Odpowiednio: 1 - tylko dla wartości
 *                      całkowitych, 2 - dla wartości całkowitych oraz zmiennoprzecinkowych (double).
 */
template<typename T>
void createMtrxObject(unsigned short int* sizeMtrx, HANDLE& hOut,
                      unsigned short int& mtrxType, unsigned short int& mtrxValType) {

  unsigned short int chooseMtrxMath{0}; /** Wybór przez użytkownika operacji matematycznej na macierzy */
  MatrixAbstract<T>* ptr{nullptr}; /** Wzkaźnik wskazujący na obiekt typu T (int/double) */

  switch(mtrxType) {
    case 1: { /** macierze prostokątne */
      GeneralMatrix<T> rectObj{sizeMtrx[0], sizeMtrx[1]};
      ptr = &rectObj;

      chooseMtrxMath = mathChooseMtrx(ptr, hOut);
      onlyOneMtrxMath<GeneralMatrix<T>, GeneralMatrix<double>, T>(
        chooseMtrxMath, ptr, rectObj, hOut, mtrxType, mtrxValType
      );

      break;
    } case 2: { /** macierze kwadratowe */
      GeneralMatrix<T> sqrObj{sizeMtrx[0]};
      ptr = &sqrObj;

      chooseMtrxMath = mathChooseMtrx(ptr, hOut);
      onlyOneMtrxMath<GeneralMatrix<T>, GeneralMatrix<double>, T>(
        chooseMtrxMath, ptr, sqrObj, hOut, mtrxType, mtrxValType
      );

      break;
    } case 3: { /** macierze diagonalne */
      DiagonalMatrix<T> diagObj{sizeMtrx[0]};
      ptr = &diagObj;

      chooseMtrxMath = mathChooseMtrx(ptr, hOut);
      onlyOneMtrxMath<DiagonalMatrix<T>, DiagonalMatrix<double>, T>(
        chooseMtrxMath, ptr, diagObj, hOut, mtrxType, mtrxValType
      );

      break;
    }
  }
}

#include "mathChooseMtrx.tpp"
#include "mathMtrx.tpp"