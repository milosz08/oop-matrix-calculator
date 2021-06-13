#ifndef PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H
#define PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H

namespace matrixAbstractPackage {
  /*!
   * @class MatrixAbstract
   * @brief Klasa abstrakcyjna. Posiada konstruktory: bezargumentowy, dla macierzy
   * prostokątnych, dla macierzy kwadratowych oraz konstruktor kopiujący.
   * Posiada destruktor wirtualny delokujący pamięć oraz wywołujący destruktory z klas pochodnych.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @param mtrxWidth - liczba kolumn macierzy
   * @param mtrxHeight - liczba wierszy macierzy
   * @param scalarVal - wartość skalara wprowadzana przez użytkownika
   * @param mtrx - tablica wskaźników reprezentująca ilość wierszy w macierzy
   */
  template<typename M>
  class MatrixAbstract {
    public:
      explicit MatrixAbstract();
      explicit MatrixAbstract(unsigned int&, unsigned int&); /** Sygnatura konstr. dla macierzy prostokątnych */
      explicit MatrixAbstract(unsigned int&); /** Sygnatura konstr. dla macierzy kwadratowych */
      explicit MatrixAbstract(const MatrixAbstract&); /** Sygnatura konstr. kopiującego */

      virtual void printMtrx(bool) const; /** Metoda wirtualna - drukowanie macierzy */
      virtual void allocateMemory(); /** Metoda wirtualna - alokacja pamięci */
      virtual double scalarValuePush(); /** Metoda wirtualna - wprowadzanie wartości scalar */
      virtual void mtrxTypeAndSizeInfo() = 0; /** Metoda czysto wirtualna - wypisywanie wiadomosci */

      virtual ~MatrixAbstract(); /** Wirtualny destruktor wywołujący destruktory z klas pochodnych */

    protected:
      unsigned int mtrxWidth{0}, mtrxHeight{0}; /** Wymiary macierzy */
      double scalarVal{0}; /** Wartość skalara */
      M** mtrx{nullptr}; /** Tablica wskaźników typu M reprezentująca komórki macierzy */
  };
}

#endif
