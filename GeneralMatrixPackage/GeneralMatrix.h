#ifndef PK_MATRIX_CALCULATOR_GENERALMATRIX_H
#define PK_MATRIX_CALCULATOR_GENERALMATRIX_H

namespace generalMatrixPackage {
  /**
   * @class GeneralMatrix
   * @brief Klasa bazowa na podstawie której tworzona jest macierz kwadratowa lub prostokątna.
   * Posiada 4 konstruktory, z których jeden odpowiada za stworzenie macierzy kwadratowej
   * drugi macierzy prostokątnej a pozostałe pełnią funkcje pomocnicze (kopiowanie instancji,
   * konstruktor bezargumentowy potrzebny do dziedziczenia).
   * Klasa posiada desktruktor pełniący rolę odśmiecacza pamięci.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @classFields mtrxWidth, mtrxHeight - wymiary macierzy
   * @param mtrx - tablica wskaźników reprezentująca ilość wierszy w macierzy
   */
  template<typename M>
  class GeneralMatrix {
    protected:
      unsigned int mtrxWidth{0}, mtrxHeight{0};
      M** mtrx{nullptr};
      void allocateMemory();
      unsigned int mtrxSignLength(const M&);

    public:
      GeneralMatrix();
      GeneralMatrix(unsigned int&, unsigned int&); /** Sygnatura konstr. macierzy prostokątnej */
      GeneralMatrix(unsigned int&); /** Sygnatura konstr. macierzy kwadratowej */
      GeneralMatrix(const GeneralMatrix&); /** Sygnatura konstr. kopiującego */

      void mtrxTypeAndSizeInfo();
      void insertMtrx();
      void printMtrx();

      ~GeneralMatrix();
  };
}

#endif