#include "../MatrixAbstract.hpp"


/*!
 * @fn GeneralMatrix()
 *
 * @brief Konstruktor bezargumentowy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract() = default;


/*!
 * @fn MatrixAbstract(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor dwuargumentowy (macierze prostokątne).
 *        Alokuje pamięć dla tablicy dynamicznej dwuwymiarowej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param w - szerokość macierzy (ilość kolumn).
 * @param h - wysokość macierzy (ilośc wierszy).
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned short int& w, unsigned short int& h) : mtrxWidth{w}, mtrxHeight{h} {
  allocateMemory();
}


/*!
 * @fn MatrixAbstract(unsigned int& s)
 *
 * @brief Konstruktor jednoargumentowy (macierze kwadratowe).
 *        Alokuje pamięć dla tablicy dynamicznej dwuwymiarowej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param s - wysokość oraz szerokość macierzy (ilośc kolumn oraz ilość wierszy).
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned short int& s) : mtrxWidth{s}, mtrxHeight{s} {
  allocateMemory();
}


/*!
 * @fn MatrixAbstract(const MatrixAbstract& c)
 *
 * @brief Konstruktor kopiujący. Rozwiązuje problem alokacji pamięci przy
 *        domyślnym konstruktorze kopiującym (ustawia inne adresy pamięci).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param c - Kopia obiektu przekazywana przez referencję.
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(const MatrixAbstract<M>& c) : mtrxWidth{c.mtrxWidth}, mtrxHeight{c.mtrxHeight} {
  this->mtrx = new M* [c.mtrxHeight];
  for(unsigned short int i = 0; i < c.mtrxHeight; i++) {
    this->mtrx[i] = new M [c.mtrxWidth];
  }
}


/*!
 * @fn ~MatrixAbstract()
 *
 * @brief Destruktor wirtualny. Usuwa tablicę dynamiczną wskaźników (liczba wierszy macierzy) oraz
 *        tablice dynamiczne wskazywane przez tablicę wskaźników (wartości w tablicach dynamicznych).
 *        Wywołuje również destruktory klas pochodnych.
 */
template<class M>
MatrixAbstract<M>::~MatrixAbstract() {
  for(unsigned short int i = 0; i < this->mtrxHeight; i++) {
    delete[] this->mtrx[i];
  }
  delete[] this->mtrx;
}