#include "../GeneralMatrix.hpp"

using namespace matrixAbstractPackage;

/**************************************************************************************
 * KONSTRUKTORY KLASY GENERALMATRIX (DZIEDZICZĄCEJ PO KLASIE ABSTRAKCYJNEJ - BAZOWEJ)
 **************************************************************************************/


/*!
 * @fn GeneralMatrix()
 *
 * @brief Konstruktor bezargumentowy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix() = default;


/*!
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor dwuargumentowy. Wywoływany dla macierzy prostokątnych. Wywołuje konstruktor
 *        z klasy abstrakcyjnej oraz wyświetla informacje na temat wprowadzanej macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param w - szerokość macierzy (ilość kolumn).
 * @param h - wysokość macierzy (ilośc wierszy).
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned short int& w, unsigned short int& h) : MatrixAbstract<M>{w, h} {}


/*!
 * @fn GeneralMatrix(unsigned int & s)
 *
 * @brief Konstruktor jednoargumentowy. Wywoływany dla macierzy kwadratowych. Wywołuje konstruktor
 *        z klasy abstrakcyjnej oraz wyświetla informacje na temat wprowadzanej macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param s - stopień macierzy (ilośc kolumn oraz ilość wierszy).
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned short int & s) : MatrixAbstract<M>{s, s} {}

/*!
 * @fn GeneralMatrix(const GeneralMatrix& mtrxCopy)
 *
 * @brief Konstruktor kopiujący. Wywołuje konstruktor z klasy abstrakcyjnej,
 *        który kopiuje zawartość objektu.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param mtrxCopy - kopia obiektu przekazywana przez referencję
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(const GeneralMatrix<M>& mtrxCopy) : MatrixAbstract<M>{mtrxCopy} {}


/*!
 * @fn ~GeneralMatrix()
 * @brief Destruktor pełniący rolę odśmiecacza pamięci. Usuwa dynamiczną tablicę indeksów kolumn (potrzebna do
 *        obliczenia wyznacznika rekurencyjną metodą Laplace'a).
 */
template<class M>
GeneralMatrix<M>::~GeneralMatrix() {
  delete[] this->colsCount;
}