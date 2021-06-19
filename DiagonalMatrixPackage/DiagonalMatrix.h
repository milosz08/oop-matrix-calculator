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
  template<class M> class DiagonalMatrix;
  //template<class M> DiagonalMatrix<M>& operator+(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
  //template<class M> DiagonalMatrix<M>& operator-(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
  //template<class M> DiagonalMatrix<M>& operator*(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
  template<class M>
    DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrx, const double& scalar);

  template<class M>
  class DiagonalMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
    public:
      DiagonalMatrix();
      DiagonalMatrix(unsigned short int&); /** Sygnatura konstr. bazowego */
      DiagonalMatrix(const DiagonalMatrix&); /** Sygnatura konstr. kopiującego */

      DiagonalMatrix<M> coupledMtrx(); /** Macierz sprzężona */
      DiagonalMatrix<M> transposeMtrx(); /** Transponowanie macierzy */
      M determinantMtrx(HANDLE& hOut); /** Wyznacznik macierzy */
      DiagonalMatrix<double> inverseMtrx(); /** Macierz odwrotna */
      virtual void insertMtrx();

      ~DiagonalMatrix();

      M* get_DiagTab() const; /** Getter */

  private:
    virtual void mtrxTypeAndSizeInfo();
    void generateDiagMtrx(bool identityMtrx);

  public:
    //friend DiagonalMatrix<M>& operator+ <>(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
    //friend DiagonalMatrix<M>& operator- <>(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
    //friend DiagonalMatrix<M>& operator* <>(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
    friend DiagonalMatrix<M> operator* <>(const DiagonalMatrix<M>& mtrx, const double& scalar);

  private:
    M* diagTab{nullptr};
  };

  /** Dyrektywa dodająca definicje przeciążeń szablonów operatorów */
  #include "../OverloadOperators/diagMtrxTemplOperators.inl"
}

#endif
