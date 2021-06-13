#include "MatrixAbstract.h"

using namespace matrixAbstractPackage;

/**
 * @fn GeneralMatrix()
 * @brief Konstruktor bezargumentowy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract() = default;

/**
 * @fn MatrixAbstract(unsigned int& w, unsigned int& h)
 * @brief Konstruktor dwuargumentowy. Alokuje pamięć dla tablicy dynamicznej dwuwymiarowej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param w - szerokość macierzy (ilość kolumn)
 * @param h - wysokość macierzy (ilośc wierszy)
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned int& w, unsigned int& h) : mtrxWidth{w}, mtrxHeight{h} {
  allocateMemory();
}

/**
 * @fn MatrixAbstract(unsigned int& s)
 * @brief Konstruktor jednoargumentowy. Alokuje pamięć dla tablicy dynamicznej dwuwymiarowej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param s - wysokość oraz szerokość macierzy (ilośc kolumn oraz ilość wierszy)
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned int& s) : mtrxWidth{s}, mtrxHeight{s} {
  allocateMemory();
}

/**
 * @fn MatrixAbstract(const MatrixAbstract& c)
 * @brief Konstruktor kopiujący. Rozwiązuje problem alokacji pamięci przy
 * domyślnym konstruktorze kopiującym (ustawia inne adresy pamięci).
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param c - kopia obiektu przekazywana przez referencję
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(const MatrixAbstract& c) : mtrxWidth{c.mtrxWidth}, mtrxHeight{c.mtrxHeight} {
  this->mtrx = new M* [c.mtrxHeight];
  for(unsigned int i = 0; i < c.mtrxHeight; i++) {
    this->mtrx[i] = new M [c.mtrxWidth];
  }
}

/**
 * @fn ~MatrixAbstract()
 * @brief Destruktor. Manualny Garbage Collector. Usuwa tablicę dynamiczną wskaźników (liczba wierszy macierzy)
 * oraz tablice dynamiczne wskazywane przez tablicę wskaźników (wartości w tablicach dynamicznych).
 */
template<class M>
MatrixAbstract<M>::~MatrixAbstract() {
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    delete[] this->mtrx[i];
  }
  delete[] this->mtrx;
}

template class matrixAbstractPackage::MatrixAbstract<int>;
template class matrixAbstractPackage::MatrixAbstract<double>;