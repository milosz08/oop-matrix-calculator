#ifndef PK_MATRIX_CALCULATOR_DIAGONALMATRIX_H
#define PK_MATRIX_CALCULATOR_DIAGONALMATRIX_H
#include "../GeneralMatrixPackage/GeneralMatrix.h"

namespace diagonalMatrixPackage {
  template<typename M>
  class DiagonalMatrix : public generalMatrixPackage::GeneralMatrix<M> {
    protected:
      unsigned int diagElm{0};
      M* diagTab{nullptr};
    public:
      DiagonalMatrix(); /** Sygnatura dla konstruktora bezargumentowego (dziedziczenie, klasa pochodna -> bazowa) */
      DiagonalMatrix(unsigned int&, unsigned int&); /** Sygnatura dla konstruktora bazowego */
      DiagonalMatrix(const DiagonalMatrix&); /** Sygnatura dla konstruktora kopiującego */

      void insertDiagElms();
      void generateDiagMtrx(bool);

      ~DiagonalMatrix();
  };
}

#endif