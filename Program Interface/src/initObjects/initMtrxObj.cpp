#include "../../interfaceDecl.hpp"


/*!
 * @fn initMtrxObj(HANDLE& hOut)
 *
 * @brief Funkcja wywołująca pozostałe funkcje ("chooseMtrxType", "chooseMtrxNmbr" oraz "setMtrxSize") które
 *        odpowiednio zapisują informację na temat: typu macierzy, typu liczb wprowadzających do macierzy oraz
 *        wielkości macierzy w postaci wskaźnika wskazującego na 2 - elementową tablicę statyczną przechowująca
 *        ilość wierszy i kolumn wprowadzanej macierzy.
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
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

#include "../mathOperations/mathFirstMtrx/mathControl.tpp"