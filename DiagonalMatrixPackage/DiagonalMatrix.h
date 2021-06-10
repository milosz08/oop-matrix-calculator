#ifndef PK_MATRIX_CALCULATOR_DIAGONALMATRIX_H
#define PK_MATRIX_CALCULATOR_DIAGONALMATRIX_H
#include "../GeneralMatrixPackage/GeneralMatrix.h"

namespace diagonalMatrixPackage {
  /**
   * @class DiagonalMatrix
   * @inherit GeneralMatrix
   * @brief Klasa pochodna dziedzicząca po klasie bazowej "GeneralMatrix". Jest ona niżej w hierarchii.
   * Obsługuje operacje macierzy diagonalnych (takich, których wartości oprócz 1 przekątnej są równe zero).
   * Posiada 3 konstruktory: bazowy, bezargumentowy (dziedzieczenie) oraz kopiujący.
   * Klasa posiada desktruktor pełniący rolę odśmiecacza pamięci.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @param diagElm - ilość elementów macierzy diagonalnej/jednostkowej (po przekątnej)
   * @param diagTab - tablica dynamiczna o ilości elementów równej liczbie
   * kolumn/wierszy macierzy przechowująca elementy macierzy diagonalnej
   */
  template<typename M>
  class DiagonalMatrix : public generalMatrixPackage::GeneralMatrix<M> {
    protected:
      unsigned int diagElms{0};
      M* diagTab{nullptr};
    public:
      DiagonalMatrix();
      DiagonalMatrix(unsigned int&); /** Sygnatura konstr. bazowego */
      DiagonalMatrix(const DiagonalMatrix&); /** Sygnatura konstr. kopiującego */

      void insertDiagElms();
      void generateDiagMtrx(bool);

      ~DiagonalMatrix();
  };
}

#endif