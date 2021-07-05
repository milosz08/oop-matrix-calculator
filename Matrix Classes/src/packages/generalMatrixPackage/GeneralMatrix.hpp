#ifndef PK_MATRIX_CALCULATOR_GENERALMATRIX_HPP
#define PK_MATRIX_CALCULATOR_GENERALMATRIX_HPP
#include "../abstractMatrixPackage/MatrixAbstract.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <windows.h>

namespace generalMatrixPackage {
  /*!
   * @class DiagonalMatrix
   * @inherit MatrixAbstract
   *
   * @brief Klasa pochodna dziedzicząca po klasie abstrakcyjnej "MatrixAbstract". Obsługuje zwykłe macierze
   *        prostokątne oraz kwadratowe.
   *
   *        Klasa posiada 4 zadeklarowane konstruktory, z czego jest to: konstruktor bezargumentowy,
   *        konstruktor dwuargumentowy, konstruktor jednoargumentowy oraz konstruktor kopiujący. Wszystkie
   *        oprócz konstruktora bezargumentowego wywołują konstruktory klasy bazowej (abstrakcyjnej).
   *
   *        Klasa posiada destruktor. Pełną macierz usuwa destruktor z klasy abstrakcyjnej. Destruktor z
   *        tej klasy usuwa zawartość tablicy dynamicznej reprezentującej indeksy kolumn macierzy (potrzebne
   *        w celu wyznaczenia wyznacznika rekurencyjną metodą Laplace'a).
   *
   *        Klasa posiada metody do operacji na pojedynczej macierzy. Są to odpowiednio: wyznaczanie macierzy
   *        sprzężonej, transponowanie macierzy, obliczanie wyznacznika macierzy oraz wyznaczanie macierzy odwrotnej.
   *        Klasa posiada również 1 metodę prywatną (metoda przysłaniająca metodę czysto wirtualną z klasy
   *        abstrakcyjnej), dostępną tylko na użytek metod tej klasy.
   *
   *        Klasa posiada przeciążenia 3 operatorów w postaci funkcji zaprzyjaźnionych. Są to odpowiednio:
   *        operator dodawania "+" (dwie macierze), operator odejmowania "-" (dwie macierze), operator mnożenia "*"
   *        (dwie macierze) oraz ponownie operator mnożenia "*" (macierz przez wartość skalarną). W funkcjach
   *        zaprzyjaźnionych znajduje sie również funkcja rekurencyjna obliczająca wyznacznik metodą Laplace'a.
   *
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
   *
   * @param diagTab - tablica dynamiczna reprezentująca elementy znajdujące się na diagonalnej (głównej przekątnej).
   */
  template<class M> class GeneralMatrix;

  template<class M> GeneralMatrix<M> operator+(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  template<class M> GeneralMatrix<M> operator-(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  template<class M> GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
  template<class M> GeneralMatrix<M> operator*(const GeneralMatrix<M>& mtrx, const double& scalar);

  template<class M> M detRecursion(unsigned short int mtrxS, unsigned short int nextRow,
                                   unsigned short int* colCount, M** mtrx);

  template<class M>
  class GeneralMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
    public:
      GeneralMatrix(unsigned short int&, unsigned short int&); /** @skip Sygnatura konstr. macierzy prostokątnej */
      GeneralMatrix(unsigned short int&); /** @skip Sygnatura konstr. macierzy kwadratowej */
      GeneralMatrix(const GeneralMatrix<M>&); /** @skip Sygnatura konstr. kopiującego */

      virtual void insertMtrx(HANDLE&); /** @skip Wstawianie macierzy */

      GeneralMatrix<M> transposeMtrx(); /** @skip Transponowanie macierzy */
      GeneralMatrix<M> coupledMtrx(); /** @skip Macierz sprzężona */
      M determinantMtrx(HANDLE&); /** @skip Wyznacznik (tylko macierze kwadratowe) n-tego stopnia */
      GeneralMatrix<double> inverseMtrx(HANDLE&); /** @skip Macierz odwrotna */

      ~GeneralMatrix();

    private:
      virtual void mtrxTypeAndSizeInfo(); /** @skip Metoda z klasy abstrakcyjnej */

    public:
      friend GeneralMatrix<M> operator+ <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
      friend GeneralMatrix<M> operator- <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
      friend GeneralMatrix<M> operator* <>(const GeneralMatrix<M>& mtrxF, const GeneralMatrix<M>& mtrxS);
      friend GeneralMatrix<M> operator* <>(const GeneralMatrix<M>& mtrx, const double& scalar);

      friend M detRecursion <>(unsigned short int mtrxS, unsigned short int nextRow,
                               unsigned short int* colCount, M** mtrx);

    private:
      unsigned short int* colsCount{nullptr};
  };

  #include "src/constructors.tpp" /** @skip Deklaracje konstruktorów */
  #include "src/pureVirtMethods.tpp" /** @skip Metody przysłaniające metody czysto wirtualne klasy abstrakcyjnej */

  #include "src/mathAndOprts/mathMethods.tpp" /** @skip Operacje arytmetyczne - metody */
  #include "src/mathAndOprts/friendOprts.tpp" /** @skip Przeciążenia operatorów (funkcje zaprzyjaźnione) */
}
#endif