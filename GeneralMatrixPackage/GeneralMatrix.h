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
   * @classFields mtrxWidth, mtrxHeight - wymiary macierzy
   * @param mtrx - tablica wskaźników reprezentująca ilość wierszy w macierzy
   */
  template<typename M>
  class GeneralMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
    public:
      GeneralMatrix();
      GeneralMatrix(unsigned int&, unsigned int&); /** Sygnatura konstr. macierzy prostokątnej */
      GeneralMatrix(unsigned int&); /** Sygnatura konstr. macierzy kwadratowej */
      GeneralMatrix(const GeneralMatrix&); /** Sygnatura konstr. kopiującego */

      void insertMtrx();

      ~GeneralMatrix();

    private:
      virtual void mtrxTypeAndSizeInfo();
  };
}

#endif