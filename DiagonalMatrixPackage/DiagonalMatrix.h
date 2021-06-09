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
      DiagonalMatrix();
      DiagonalMatrix(unsigned int&);

      void insertDiagElms();

      ~DiagonalMatrix();
  };
}


#endif