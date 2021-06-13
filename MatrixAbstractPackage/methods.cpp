#include <iostream>
#include <limits>
#include "MatrixAbstract.h"

using namespace matrixAbstractPackage;

/**
 * @fn allocateMemory()
 * @brief Metoda alokująca dynamicznie pamięć w formie tablicy wskaźników typu M (int/double)
 * o wielkości równej ilości wierszy oraz tworząca dynamiczne tablice (ich ilość jest
 * zależna od ilości wierszy) o wielkości równej ilości kolumn w macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void MatrixAbstract<M>::allocateMemory() {
  this->mtrx = new M* [this->mtrxHeight];
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    this->mtrx[i] = new M [this->mtrxWidth];
  }
}

/**
 * @fn pringMtrx()
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie
 * wartości zapisanych w dwuwymiarowej tablicy dynamicznej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param textMess - jeśli "true" drukuje komunikat, jeśli "false" drukuje jednynie macierz
 */
template<class M>
void MatrixAbstract<M>::printMtrx(bool textMess) const {
  if(textMess) {
    std::cout << "\n  Zapisalem nastepujaca macierz ";
    std::cout << (this->mtrxHeight == this->mtrxWidth ? "kwadratowa:\n" : "prostokatna:\n");
  }
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(j == 0) {
        std::cout << "  [\t";
      }
      std::cout << this->mtrx[i][j] << "\t";
      if(j == this->mtrxWidth - 1) {
        std::cout << "\t]";
      }
    }
    std::cout << "\n";
  }
}

/**
 * @fn scalarValuePush()
 * @brief Wprowadzanie przez użytkownika wartości skalara. Metoda posiada walidację pod kątem
 * strumienia wejścia. Jeśli zostaną podane nieprawidłowe wartości, program wyświetli błąd i
 * umożliwi ponowne wpisanie wartości skalara przez użytkownika.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @return - wartość skalara zapisaną w polu klasy.
 */
template<class M>
double MatrixAbstract<M>::scalarValuePush() {
  bool error{false}, repeatMess{false};
  std::cout << "\nAby przejsc dalej, podaj wartosc skalara, przez ktora chcesz przemnozyc macierz.\n";
  std::cout << "Uwaga! Jesli podasz wiecej elementow (po spacji), zostana one przeze mnie zignorowane!\n";
  do {
    try {
      error = false;
      std::cout << "\nWpisz tutaj" << (!repeatMess ? "" : " ponownie") << " wartosc skalara:\n";
      std::cin >> this->scalarVal;
      if(std::cin.fail()) {
        throw std::logic_error("badScalarValue");
      }
    }
    catch(std::logic_error& e) {
      std::cout << "\nError! Blad logiczny, kod bledu: " << e.what() << "!\n";
      std::cout << "Wartosc skalarna zawiera nieprawidlowe znaki!\n";
      std::cout << "Aby kontyuowac wprowadz ponownie wartosc skalara.\n";
      error = repeatMess = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(error);
  return this->scalarVal;
}

template class matrixAbstractPackage::MatrixAbstract<int>;
template class matrixAbstractPackage::MatrixAbstract<double>;