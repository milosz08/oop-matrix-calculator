#include "../DiagonalMatrix.hpp"

/*****************************************************************************************
 * METODY PRYWATNE KLASY DIAGONALMATRIX (DZIEDZICZĄCEJ PO KLASIE ABSTRAKCYJNEJ - BAZOWEJ)
 *****************************************************************************************/


/*!
 * @fn generateDiagMtrx(bool identityMtrx)
 *
 * @brief Metoda tylko na użytek metod tej klasy. Metoda prywatna. Metoda wprowadzająca do konkretnych komórek
 *        macierzy konkretne znaki. Jeśli parametr indentityMtrx jest ustawiony na "false", generuje macierz
 *        diagonalną na podstawie znaków tablicy dynamicznej diagTab[]. Jeśli jest ustawiony na "true",
 *        generuje macierz jednostkową.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param identityMtrx - przełącznik pomiędzy macierzą diagonalną a jednostkową (jednostkowa -> true).
 */
template<class M>
void DiagonalMatrix<M>::generateDiagMtrx(bool identityMtrx) {
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        (!identityMtrx ? this->mtrx[i][j] = this->diagTab[j] : this->mtrx[i][j] = 1);
      } else {
        this->mtrx[i][j] = 0;
      }
    }
  }
}