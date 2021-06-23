#include "../MatrixAbstract.hpp"


/********************************************************
 * METODY PRYWATNE KLASY ABSTRAKCYJNEJ (NIEDZIEDZICZNE)
 ********************************************************/


/*!
 * @fn allocateMemory()
 * @inherit Metoda niedziedziczna. Tylko na użytek klasy abstrakcyjnej.
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
  this->mtrx = new M* [this->mtrxHeight];
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    this->mtrx[i] = new M [this->mtrxWidth];
  }
}


/*!
 * @fn findMaxLength(unsigned int& col)
 * @inherit Metoda niedziedziczna. Tylko na użytek klasy abstrakcyjnej.
 *
 * @brief Wyznaczenie, odszukanie i zwrócenie najdłużego ciągu liczbowego w jednej kolumnie macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param col - aktualnie obsługiwana kolumna (indeks).
 *
 * @return - Najdłuższy ciąg liczbowy w n kolumnie (wartość n = param col).
 */
template<class M>
unsigned int MatrixAbstract<M>::findMaxLength(unsigned int& col) const {
  std::string str{""};
  unsigned int freeSpace{2}; /** Ilość spacji między kolumnami macierzy */
  std::vector<unsigned int>allLength;
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    allLength.push_back(lengthOfElm(this->mtrx[i][col]));
  }
  return *max_element(allLength.begin(), allLength.end()) + freeSpace;
}


/*!
 * @fn lengthOfElm(M& cell)
 * @inherit Metoda niedziedziczna. Tylko na użytek klasy abstrakcyjnej.
 *
 * @brief Wyznaczanie i zwrócenie długości wartości liczbowej typu "unsigned int" w pojedynczej komórce macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param cell - wartość typu M przekazywana do komórki przez referencję.
 *
 * @return - Długość wartości pobieranej ze zmiennej "cell" typu M przez referencję.
 */
template<class M>
unsigned int MatrixAbstract<M>::lengthOfElm(M& cell) const {
  std::string elmLength;
  elmLength = std::to_string(cell);
  elmLength.erase(elmLength.find_last_not_of('0') + 1, std::string::npos);
  elmLength.erase(elmLength.find_last_not_of('.') + 1, std::string::npos);
  return elmLength.length();
}