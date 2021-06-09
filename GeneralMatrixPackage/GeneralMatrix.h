#ifndef PK_MATRIX_CALCULATOR_GENERALMATRIX_H
#define PK_MATRIX_CALCULATOR_GENERALMATRIX_H

namespace generalMatrixPackage {
  /**
   * @class GeneralMatrix
   * @brief Klasa bazowa na podstawie której tworzona jest macierz kwadratowa lub prostokątna.
   * Posiada 2 konstruktory, z których jeden odpowiada za stworzenie macierzy kwadratowej
   * a drugi macierzy prostokątnej. Klasa posiada desktruktor pełniący rolę odśmiecacza pamięci.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @classFields mtrxWidth, mtrxHeight - wymiary macierzy
   * @param mtrx - tablica wskaźników reprezentująca ilość wierszy w macierzy
   */
  template<typename M>
  class GeneralMatrix {
      unsigned int mtrxWidth{0}, mtrxHeight{0};
      M** mtrx{nullptr};
      void allocateMemory();
      unsigned int mtrxSignLength(const M&);

    public:
      GeneralMatrix(); //konstruktor bezargumentowy (dziedziczenie, klasa bazowa)
      GeneralMatrix(unsigned int&, unsigned int&); //sygnatura dla prostokątnej
      GeneralMatrix(unsigned int&); //sygnatura dla kwadratowej
      GeneralMatrix(const GeneralMatrix&); //konstruktor kopiujący

      void mtrxTypeAndSizeInfo();
      void insertMtrx();
      void printMtrx();

      ~GeneralMatrix();
  };
}

#endif