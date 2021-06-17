#ifndef PK_MATRIX_CALCULATOR_DIAGONALMATRIX_H
#define PK_MATRIX_CALCULATOR_DIAGONALMATRIX_H
#include "../MatrixAbstractPackage/MatrixAbstract.h"
#include "../GeneralMatrixPackage/GeneralMatrix.h"
#include "../Interface/Auxiliary Functions/auxiliaryFunc.h"
#include <iostream>
#include <limits>

namespace diagonalMatrixPackage {
  /**
   * @class DiagonalMatrix
   * @inherit MatrixAbstract
   * @brief Klasa pochodna dziedzicząca po klasie abstrakcyjnej "MatrixAbstract".
   * Obsługuje operacje macierzy diagonalnych (takich, których wartości poza główną przekątną są równe zero).
   * Posiada 3 konstruktory: bazowy, bezargumentowy (dziedzieczenie) oraz kopiujący.
   * Klasa posiada desktruktor pełniący rolę odśmiecacza pamięci.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @param diagTab - tablica dynamiczna o ilości elementów równej liczbie
   * kolumn/wierszy macierzy przechowująca elementy macierzy diagonalnej
   */
  template<typename M>
  class DiagonalMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
  private:
    M* diagTab{nullptr};

  public:
    DiagonalMatrix();
    DiagonalMatrix(unsigned int&); /** Sygnatura konstr. bazowego */
    DiagonalMatrix(const DiagonalMatrix&); /** Sygnatura konstr. kopiującego */

    DiagonalMatrix<M> coupledMtrx() const; /** Macierz sprzężona */

    virtual void insertMtrx();

    ~DiagonalMatrix();

  private:
    virtual void mtrxTypeAndSizeInfo();
    void generateDiagMtrx(bool);
  };
}

#endif
