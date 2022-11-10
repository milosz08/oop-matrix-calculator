#ifndef PK_MATRIX_CALCULATOR_DIAGONALMATRIX_HPP
#define PK_MATRIX_CALCULATOR_DIAGONALMATRIX_HPP

#include "MatrixAbstract.hpp"
#include "GeneralMatrix.hpp"
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
     *        Klasa posiada 4 zadeklarowane konstruktory, z czego jest to: konstruktor bezargumentowy,
     *        konstruktor dwuargumentowy, konstruktor jednoargumentowy oraz konstruktor kopiujący. Wszystkie
     *        oprócz konstruktora bezargumentowego wywołują konstruktory klasy bazowej (abstrakcyjnej).
     *
     *        Klasa posiada destruktor. Pełną macierz usuwa destruktor z klasy abstrakcyjnej. Destruktor z
     *        tej klasy usuwa zawartość tablicy dynamicznej reprezentującej elementy na diagonalnej.
     *
     *        Klasa posiada metody do operacji na pojedynczej macierzy. Są to odpowiednio: wyznaczanie macierzy
     *        sprzężonej, transponowanie macierzy, obliczanie wyznacznika macierzy oraz wyznaczanie macierzy odwrotnej.
     *        Klasa posiada również 2 metody prywatne, dostępne tylko na użytek metod tej klasy.
     *
     *        Klasa posiada zadeklarowaną jedną metodę getter, zwracającą elementy głównej diagonalnej w
     *        postaci wskaźnika na tablicę dynamiczną typu M.
     *
     *        Klasa posiada przeciążenia 3 operatorów w postaci funkcji zaprzyjaźnionych. Są to odpowiednio:
     *        operator dodawania "+" (dwie macierze), operator odejmowania "-" (dwie macierze), operator mnożenia "*"
     *        (dwie macierze) oraz ponownie operator mnożenia "*" (macierz przez wartość skalarną).
     *
     * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
     *
     * @param diagTab - tablica dynamiczna reprezentująca elementy znajdujące się na diagonalnej (głównej przekątnej).
     */
    template<class M>
    class DiagonalMatrix;

    template<class M> DiagonalMatrix<M> operator+(const DiagonalMatrix<M> &mtrxF, const DiagonalMatrix<M> &mtrxS);
    template<class M> DiagonalMatrix<M> operator-(const DiagonalMatrix<M> &mtrxF, const DiagonalMatrix<M> &mtrxS);
    template<class M> DiagonalMatrix<M> operator*(const DiagonalMatrix<M> &mtrxF, const DiagonalMatrix<M> &mtrxS);
    template<class M> DiagonalMatrix<M> operator*(const DiagonalMatrix<M> &mtrx, const double &scalar);

    template<class M>
    class DiagonalMatrix : public matrixAbstractPackage::MatrixAbstract<M> {
    public:
        DiagonalMatrix(unsigned short int &); /** @skip Sygnatura konstr. jednoargumentowego */
        DiagonalMatrix(unsigned short int &, unsigned short int &); /** @skip Sygnatura konstr. dwuargumentowego */
        DiagonalMatrix(const DiagonalMatrix &); /** @skip Sygnatura konstr. kopiującego */

        DiagonalMatrix<M> coupledMtrx(); /** @skip Macierz sprzężona */
        DiagonalMatrix<M> transposeMtrx(); /** @skip Transponowanie macierzy */
        M determinantMtrx(HANDLE &); /** @skip Wyznacznik macierzy */
        DiagonalMatrix<double> inverseMtrx(HANDLE &); /** @skip Macierz odwrotna */

        virtual void insertMtrx(HANDLE &); /** @skip Metoda czysto wirtualna z klasy bazowej. Wprowadzanie macierzy */

        ~DiagonalMatrix();

        M *get_DiagTab() const; /** @skip Getter */

    private:
        virtual void mtrxTypeAndSizeInfo();

        void generateDiagMtrx(bool identityMtrx);

    public:
        friend DiagonalMatrix<M> operator+<>(const DiagonalMatrix<M> &mtrxF, const DiagonalMatrix<M> &mtrxS);
        friend DiagonalMatrix<M> operator-<>(const DiagonalMatrix<M> &mtrxF, const DiagonalMatrix<M> &mtrxS);
        friend DiagonalMatrix<M> operator*<>(const DiagonalMatrix<M> &mtrxF, const DiagonalMatrix<M> &mtrxS);
        friend DiagonalMatrix<M> operator*<>(const DiagonalMatrix<M> &mtrx, const double &scalar);

    private:
        M *diagTab{nullptr};
    };

    #include "DiagonalMatrix.tpp" /** @skip Deklaracje konstruktorów */
    #include "FriendDiagonal.tpp"
}

#endif
