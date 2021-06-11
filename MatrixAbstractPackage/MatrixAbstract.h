#ifndef PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H
#define PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H

namespace matrixAbstractPackage {
  /**
   * @class MatrixAbstract
   * @brief Klasa abstrakcyjna. Posiada konstruktory: bezargumentowy, dla macierzy
   * prostokątnych, dla macierzy kwadratowych oraz konstruktor kopiujący.
   * Posiada destruktor wirtualny delokujący pamięć oraz wywołujący destruktory z klas pochodnych.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @classFields mtrxWidth, mtrxHeight - wymiary macierzy
   * @param mtrx - tablica wskaźników reprezentująca ilość wierszy w macierzy
   */
  template<typename M>
  class MatrixAbstract {
    protected:
      unsigned int mtrxWidth{0}, mtrxHeight{0};
      M** mtrx{nullptr};

    public:
      explicit MatrixAbstract();
      explicit MatrixAbstract(unsigned int&, unsigned int&);
      explicit MatrixAbstract(unsigned int&);
      explicit MatrixAbstract(const MatrixAbstract&);

      virtual void printMtrx(bool) const; /** metoda wirtualna - drukowanie macierzy */
      virtual void allocateMemory(); /** metoda wirtualna - alokacja pamięci */
      virtual void mtrxTypeAndSizeInfo() = 0; /** metoda czysto wirtualna - wypisywanie wiadomosci */

      virtual ~MatrixAbstract();
  };
}

#endif
