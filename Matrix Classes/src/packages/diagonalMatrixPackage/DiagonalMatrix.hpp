#ifndef PK_MATRIX_CALCULATOR_DIAGONALMATRIX_HPP
#define PK_MATRIX_CALCULATOR_DIAGONALMATRIX_HPP
#include "../abstractMatrixPackage/MatrixAbstract.hpp"
#include "../generalMatrixPackage/GeneralMatrix.hpp"
#include <iostream>
#include <limits>

namespace diagonalMatrixPackage {
  /*!
   * @class DiagonalMatrix
   * @inherit MatrixAbstract
   *
   * @brief Klasa pochodna dziedzicząca po klasie abstrakcyjnej "MatrixAbstract". Obsługuje macierze diagonalne.
   *        Macierze diagonalne to specjalny typ macierzy kwadratowej, która poza swoją główną przekątną -
   *        diagonalną jest wypełniona zerami.
   *
   * @constructors Klasa posiada 4 zadeklarowane konstruktory, z czego jest to: konstruktor bezargumentowy,
   *               konstruktor dwuargumentowy, konstruktor jednoargumentowy oraz konstruktor kopiujący. Wszystkie
   *               oprócz konstruktora bezargumentowego wywołują konstruktory klasy bazowej (abstrakcyjnej).
   *
   * @destructor Klasa posiada destruktor. Pełną macierz usuwa destruktor z klasy abstrakcyjnej. Destruktor z
   *             tej klasy usuwa zawartość tablicy dynamicznej reprezentującej elementy na diagonalnej.
   *
   * @methods Klasa posiada metody do operacji na pojedynczej macierzy. Są to odpowiednio: wyznaczanie macierzy
   *          sprzężonej, transponowanie macierzy, obliczanie wyznacznika macierzy oraz wyznaczanie macierzy odwrotnej.
   *          Klasa posiada również 2 metody prywatne, dostępne tylko na użytek metod tej klasy.
   *
   * @getters Klasa posiada zadeklarowaną jedną metodę getter, zwracającą elementy głównej diagonalnej w
   *          postaci wskaźnika na tablicę dynamiczną typu M.
   *
   * @overload Klasa posiada przeciążenia 3 operatorów w postaci funkcji zaprzyjaźnionych. Są to odpowiednio:
   *           operator dodawania "+" (dwie macierze), operator odejmowania "-" (dwie macierze), operator mnożenia "*"
   *           (dwie macierze) oraz ponownie operator mnożenia "*" (macierz przez wartość skalarną).
   *
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
   *
   * @param diagTab - tablica dynamiczna reprezentująca elementy znajdujące się na diagonalnej (głównej przekątnej).
   */
  template<class M> class DiagonalMatrix;
  template<class M> DiagonalMatrix<M> operator+(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
  template<class M> DiagonalMatrix<M> operator-(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
  template<class M> DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
  template<class M> DiagonalMatrix<M> operator*(const DiagonalMatrix<M>& mtrx, const double& scalar);

  template<class M>
  class DiagonalMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
    public:
      DiagonalMatrix();
      DiagonalMatrix(unsigned short int&); /** Sygnatura konstr. jednoargumentowego */
      DiagonalMatrix(unsigned short int&, unsigned short int&); /** Sygnatura konstr. dwuargumentowego */
      DiagonalMatrix(const DiagonalMatrix&); /** Sygnatura konstr. kopiującego */

      DiagonalMatrix<M> coupledMtrx(); /** Macierz sprzężona */
      DiagonalMatrix<M> transposeMtrx(); /** Transponowanie macierzy */
      M determinantMtrx(HANDLE& hOut); /** Wyznacznik macierzy */
      DiagonalMatrix<double> inverseMtrx(); /** Macierz odwrotna */

      virtual void insertMtrx(HANDLE&); /** Metoda czysto wirtualna z klasy bazowej. Wprowadzanie macierzy */

      ~DiagonalMatrix();

      M* get_DiagTab() const; /** Getter */

    private:
      virtual void mtrxTypeAndSizeInfo();
      void generateDiagMtrx(bool identityMtrx);

    public:
      friend DiagonalMatrix<M> operator+ <>(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
      friend DiagonalMatrix<M> operator- <>(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
      friend DiagonalMatrix<M> operator* <>(const DiagonalMatrix<M>& mtrxF, const DiagonalMatrix<M>& mtrxS);
      friend DiagonalMatrix<M> operator* <>(const DiagonalMatrix<M>& mtrx, const double& scalar);

    private:
      M* diagTab{nullptr};
  };

  #include "src/constructors.tpp" /** Deklaracje konstruktorów */
  #include "src/pureVirtMethods.tpp" /** Metody przysłaniające metody czysto wirtualne klasy abstrakcyjnej */
  #include "src/getters.tpp" /** Metody zwracające wartości pól chronionych - gettery */
  #include "src/privateMethods.tpp" /** Metody prywatne (niedziedziczne) */

  #include "src/mathAndOprts/mathMethods.tpp" /** Operacje arytmetyczne - metody */
  #include "src/mathAndOprts/friendOprts.inl" /** Przeciążenia operatorów (funkcje zaprzyjaźnione) */
}

#endif
