#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include "GeneralMatrix.h"

using namespace generalMatrixPackage;

/**
 * @fn mtrxTypeAndSizeInfo()
 * @brief Metoda informująca użytkownika jakiej wielkości oraz ilu elementowa
 * macierz została zapisana.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void GeneralMatrix<M>::mtrxTypeAndSizeInfo() {
  std::cout << "\nZapisalem nastepujace wymiary macierzy\n";
  if(this->mtrxWidth == this->mtrxHeight) {
    std::cout << "kwadratowej ";
  } else {
    std::cout << "prostokatnej ";
  }
  std::cout << this->mtrxWidth << " x " << this->mtrxHeight;
  std::cout << ", posiadajacej liczbe " << this->mtrxWidth * this->mtrxHeight << " komorek.\n";
}

/**
 * @fn allocateMemory()
 * @brief Metoda alokująca dynamicznie pamięć w formie tablicy wskaźników typu M (int/double)
 * o wielkości równej ilości wierszy oraz tworząca dynamiczne tablice (ich ilość jest
 * zależna od ilości wierszy) o wielkości równej ilości kolumn w macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void GeneralMatrix<M>::allocateMemory() {
  this->mtrx = new M* [this->mtrxHeight];
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    this->mtrx[i] = new M [this->mtrxWidth];
  }
}

/**
 * @fn insertData()
 * @brief Metoda umożliwiająca wprowadzenie przez użytkownika elementów macierzy do wcześniej
 * stworzonej dwuwymiarowej tablicy dynamicznej. Metoda posiada walidację strumienia wejścia
 * pod kątem wprowadzanych znaków do macierzy. Jeśli znak nie jest liczbą/cyfrą program daje
 * wyrzuca błąd i daje możliwość ponownego wpisania macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param throw - kod błędu -1 (niedozwolone znaki ASCII)
 */
template<class M>
void GeneralMatrix<M>::insertMtrx() {
  bool error, repeatMess = false;
  do {
    try {
      error = false;
      std::cout << "\nWpisz " << (!repeatMess ? "" : "ponownie ") << "swoja macierz:\n";
      for(unsigned int i = 0; i < this->mtrxHeight; i++) {
        for(unsigned int j = 0; j < this->mtrxWidth; j++) {
          std::cin >> this->mtrx[i][j];
        }
      }
      if(std::cin.fail()) {
        throw std::logic_error("nAllAsciiChars");
      }
    }
    catch(std::logic_error&) {
      std::cout << "\nUwaga! W wprowadzanej przez ciebie macierzy znalazlem niedozwolone wartosci!\n";
      std::cout << "Aby kontyuowac wprowadz ponownie swoja macierz.\n";
      error = repeatMess = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(error);
}

/**
 * @fn pringMtrx()
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie
 * wartości zapisanych w dwuwymiarowej tablicy dynamicznej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param mtrxHeight - reprezentanta ilości wierszy macierzy
 * @param mtrxWidth - reprezentanta ilości kolumn macierzy
 */
template<class M>
void GeneralMatrix<M>::printMtrx() {
  std::cout << "\nZapisalem nastepujaca macierz ";
  std::cout << (this->mtrxHeight == this->mtrxWidth ? "kwadratowa:\n" : "prostokatna:\n");
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      std::cout << this->mtrx[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

template class generalMatrixPackage::GeneralMatrix<int>;
template class generalMatrixPackage::GeneralMatrix<double>;