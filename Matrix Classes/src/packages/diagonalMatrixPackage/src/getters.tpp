#include "../DiagonalMatrix.hpp"

/*********************************************************************************
 * GETTERY KLASY DIAGONALMATRIX (DZIEDZICZĄCEJ PO KLASIE ABSTRAKCYJNEJ - BAZOWEJ)
 *********************************************************************************/


/*!
 * @fn get_DiagTab()
 * @brief Getter klasy "DiagonalAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca tablicę dynamiczną elementów na diagonalnej (przekątnej macierzy diagonalnej).
 */
template<class M>
M* DiagonalMatrix<M>::get_DiagTab() const { return this->diagTab; }