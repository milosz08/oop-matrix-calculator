#include "../MatrixAbstract.hpp"


/*!
 * @fn get_Cols()
 * @brief Getter klasy abstrakcyjnej "MatrixAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca ilość kolumn macierzy (szerokość macierzy).
 */
template<class M>
unsigned short int MatrixAbstract<M>::get_Cols() const { return mtrxWidth; }


/*!
 * @fn get_Rows()
 * @brief Getter klasy abstrakcyjnej "MatrixAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca ilość wierszy macierzy (wysokość macierzy).
 */
template<class M>
unsigned short int MatrixAbstract<M>::get_Rows() const { return mtrxHeight; }


/*!
 * @fn get_Mtrx()
 * @brief Getter klasy abstrakcyjnej "MatrixAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca macierz w postaci dynamicznej dwuwymiarowej tablicy.
 */
template<class M>
M** MatrixAbstract<M>::get_Mtrx() const { return mtrx; }