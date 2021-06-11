#ifndef PK_MATRIX_CALCULATOR_GENERALMATRIX_H
#define PK_MATRIX_CALCULATOR_GENERALMATRIX_H
#include "../MatrixAbstractPackage/MatrixAbstract.h"

namespace generalMatrixPackage {
  /**
   * @class GeneralMatrix
   * @inherit MatrixAbstract
   * @brief Klasa na podstawie której tworzona jest macierz kwadratowa lub prostokątna.
   * Posiada 4 konstruktory, z których jeden odpowiada za stworzenie macierzy kwadratowej
   * drugi macierzy prostokątnej a pozostałe pełnią funkcje pomocnicze (kopiowanie instancji,
   * konstruktor bezargumentowy potrzebny do dziedziczenia).
   * Klasa posiada desktruktor pełniący rolę odśmiecacza pamięci.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   */
  template<class M> class GeneralMatrix;
  template<class M> GeneralMatrix<M> operator+(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);

  template<class M>
  class GeneralMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
    public:
      explicit GeneralMatrix();
      explicit GeneralMatrix(unsigned int&, unsigned int&); /** Sygnatura konstr. macierzy prostokątnej */
      explicit GeneralMatrix(unsigned int&); /** Sygnatura konstr. macierzy kwadratowej */
      GeneralMatrix(const GeneralMatrix<M>&); /** Sygnatura konstr. kopiującego */

      void insertMtrx();

      ~GeneralMatrix();

    private:
      virtual void mtrxTypeAndSizeInfo();

    public:
      friend GeneralMatrix<M> operator+ <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  };

  /** Dyrektywa dodająca definicje przeciążeń szablonów operatorów dla obiektów klasy */
  #include "../AdditionalFiles/genMtrxTemplOperators.inl"
}
#endif