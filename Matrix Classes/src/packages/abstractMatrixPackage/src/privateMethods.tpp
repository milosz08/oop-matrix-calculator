#include "../MatrixAbstract.hpp"


/*!
 * @fn allocateMemory()
 * @inherit Metoda niedziedziczna. Tylko na użytek konstruktorów klasy abstrakcyjnej.
 *
 * @brief Metoda prywatna klasy abstrakcyjnej. Alokuje dynamicznie pamięć w formie tablicy wskaźników
 *        typu M (int/double) o wielkości równej ilości wierszy oraz tworząca dynamiczne tablice
 *        (ich ilość jest zależna od ilości wierszy) o wielkości równej ilości kolumn w macierzy.
 *        Wywoływana w konstruktorach klasy abstrakcyjnej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void MatrixAbstract<M>::allocateMemory() {
  mtrx = new M* [mtrxHeight];

  for(unsigned short int i = 0; i < mtrxHeight; i++) {
    mtrx[i] = new M [mtrxWidth];
  }
}


/*!
 * @fn ifValueIsInt(std::string& elm)
 * @inherit Metoda niedziedziczna. Tylko na użytek metod klasy abstrakcyjnej.
 *
 * @brief Weryfikacja, czy dana wartość jest typu int czy double.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param elm - badana wartość komórki (w postaci stringa).
 *
 * @return Metoda zwraca wartość logiczną. Jeśli jest to int -> true, w przeciwnym wypadku false.
 */
template<class M>
bool MatrixAbstract<M>::ifValueIsInt(std::string& elm) const {
  for(unsigned short int i = 0; i < elm.length(); i++) {
    if(elm[i] == '.') {
      return false;
    }
  }
  return true;
}


/*!
 * @fn findMaxLength(unsigned int& col)
 * @inherit Metoda niedziedziczna. Tylko na użytek metod klasy abstrakcyjnej.
 *
 * @brief Wyznaczenie, odszukanie i zwrócenie najdłużego ciągu liczbowego w jednej kolumnie macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param col - aktualnie obsługiwana kolumna (indeks).
 *
 * @return Najdłuższy ciąg liczbowy w n kolumnie (wartość n = param col).
 */
template<class M>
unsigned short int MatrixAbstract<M>::longestNumber(unsigned short int& indexOfRow) const {
  std::vector<unsigned short int> colSizes;
  std::string cellStr, changeStr;

  for(unsigned short int i = 0; i < mtrxWidth; i++) {
    cellStr = std::to_string(mtrx[i][indexOfRow]);

    if(!ifValueIsInt(cellStr)) { /** @skip Tylko dla wartości double */
      cellStr.erase(cellStr.find_last_not_of('0') + 1, std::string::npos);
    }

    colSizes.push_back(cellStr.length());
  }

  return *std::max_element(colSizes.begin(), colSizes.end());
}


/*!
 * @fn longOfCell(M& cell)
 * @inherit Metoda niedziedziczna. Tylko na użytek metod klasy abstrakcyjnej.
 *
 * @brief Wyznaczanie i zwrócenie długości wartości liczbowej typu "unsigned int" w pojedynczej komórce macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param cell - wartość typu M przekazywana do komórki przez referencję.
 *
 * @return Długość wartości pobieranej ze zmiennej "cell" typu M przez referencję.
 */
template<class M>
unsigned short int MatrixAbstract<M>::longOfCell(M& cell) const {
  std::string cellStr;

  cellStr = std::to_string(cell);

  if(!ifValueIsInt(cellStr)) { /** @skip Tylko dla wartości double */
    cellStr.erase(cellStr.find_last_not_of('0') + 1, std::string::npos);
    cellStr.erase(cellStr.find_last_not_of('.') + 1, std::string::npos);
  }

  return cellStr.length();
}