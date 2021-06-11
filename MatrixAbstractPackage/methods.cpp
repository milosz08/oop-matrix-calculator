#include <iostream>
#include "MatrixAbstract.h"

using namespace matrixAbstractPackage;

/**
 * @fn allocateMemory()
 * @brief Metoda alokująca dynamicznie pamięć w formie tablicy wskaźników typu M (int/double)
 * o wielkości równej ilości wierszy oraz tworząca dynamiczne tablice (ich ilość jest
 * zależna od ilości wierszy) o wielkości równej ilości kolumn w macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void MatrixAbstract<M>::allocateMemory() {
  this->mtrx = new M* [this->mtrxHeight];
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    this->mtrx[i] = new M [this->mtrxWidth];
  }
}

/**
 * @fn pringMtrx()
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie
 * wartości zapisanych w dwuwymiarowej tablicy dynamicznej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param textMess - jeśli "true" drukuje komunikat, jeśli "false" drukuje jednynie macierz
 */
template<class M>
void MatrixAbstract<M>::printMtrx(bool textMess) const {
  if(textMess) {
    std::cout << "\nZapisalem nastepujaca macierz ";
    std::cout << (this->mtrxHeight == this->mtrxWidth ? "kwadratowa:\n" : "prostokatna:\n");
  }
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      std::cout << this->mtrx[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

template class matrixAbstractPackage::MatrixAbstract<int>;
template class matrixAbstractPackage::MatrixAbstract<double>;