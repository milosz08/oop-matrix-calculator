#ifndef PK_MATRIX_CALCULATOR_GENERALMATRIX_H
#define PK_MATRIX_CALCULATOR_GENERALMATRIX_H
#include "../MatrixAbstractPackage/MatrixAbstract.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <windows.h>

namespace generalMatrixPackage {
  /*!
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
  template<typename M> GeneralMatrix<M> operator+(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  template<typename M> GeneralMatrix<M> operator-(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  template<typename M> GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  template<typename M> GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrx, const double& scalar);

  template<typename M> M detRecursion(unsigned short int mtrxS, unsigned short int nextRow, unsigned short int* colCount, M** mtrx);

  template<class M>
  class GeneralMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
  public:
    explicit GeneralMatrix();
    explicit GeneralMatrix(unsigned short int&, unsigned short int&); /** Sygnatura konstr. macierzy prostokątnej */
    explicit GeneralMatrix(unsigned short int&); /** Sygnatura konstr. macierzy kwadratowej */
    GeneralMatrix(const GeneralMatrix<M>&); /** Sygnatura konstr. kopiującego */

    virtual void insertMtrx(); /** Wstawianie wartości w kom macierzy */
    GeneralMatrix<M> transposeMtrx(); /** Transponowanie macierzy */
    GeneralMatrix<M> coupledMtrx(); /** Macierz sprzężona */
    M determinantMtrx(HANDLE& hOut); /** Wyznacznik (tylko macierze kwadratowe) n-tego stopnia */

    ~GeneralMatrix();

  private:
    virtual void mtrxTypeAndSizeInfo(); /** Metoda z klasy abstrakcyjnej */

  public:
    friend GeneralMatrix<M> operator+ <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
    friend GeneralMatrix<M> operator- <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
    friend GeneralMatrix<M> operator* <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
    friend GeneralMatrix<M> operator* <>(const GeneralMatrix<M>& mtrx, const double& scalar);

    friend M detRecursion <>(unsigned short int mtrxS, unsigned short int nextRow, unsigned short int* colCount, M** mtrx);

  private:
    unsigned short int* colsCount{nullptr};
  };

  /** Dyrektywa dodająca definicje przeciążeń szablonów operatorów */
  #include "../OverloadOperators/genMtrxTemplOperators.inl"
}
#endif