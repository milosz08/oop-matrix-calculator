#ifndef PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H
#define PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H

namespace matrixAbstractPackage {
  template<typename M>
  class MatrixAbstract {
    protected:
      unsigned int mtrxWidth{0}, mtrxHeight{0};
      M** mtrx{nullptr};
    public:
      MatrixAbstract();
      MatrixAbstract(unsigned int&, unsigned int&);
      MatrixAbstract(unsigned int&);
      MatrixAbstract(const MatrixAbstract&);

      virtual void printMatrix(); //metoda wirtualna drukowanie macierzy
      virtual void allocateMemory(); //metoda wirtualna alokacja pamięci
      virtual void mtrxTypeAndSizeInfo() = 0; //metoda czystu wirtualna - wypisywanie wiadomosci

      virtual ~MatrixAbstract(); //wirtualny destruktor (wywołuje pozostałe destruktory wirtualne)
  };
}

#endif
