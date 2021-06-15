#include <iostream>
#include <limits>
#include "DiagonalMatrix.h"
#include "../GeneralMatrixPackage/GeneralMatrix.h"

using namespace diagonalMatrixPackage;

/**
 * @fn mtrxTypeAndSizeInfo()
 * @brief Metoda informująca użytkownika jakiej wielkości oraz ilu elementowa
 * macierz diagonalna została zapisana.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void DiagonalMatrix<M>::mtrxTypeAndSizeInfo() {
  std::cout << "\nZapisalem nastepujace wymiary macierzy diagonalnej\n";
  std::cout << "o wymiarach: " << this->mtrxWidth << " x " << this->mtrxHeight;
  std::cout << ", posiadajacej liczbe " << this->mtrxWidth * this->mtrxHeight << " komorek.\n";
}

/**
 * @fn insertDiagElms()
 * @brief Metoda wprowadzająca podane przez użytkownika elementy macierzy diagonalnej (po przekątnej)
 * do tablicy dynamicznej. Metoda posiada walidację strumienia wejścia
 * pod kątem wprowadzanych znaków do macierzy diagonalnej. Jeśli znak nie jest zgody z typem zmiennej
 * we wzorcu "M" program wyrzuca błąd i daje możliwość ponownego wpisania znaków macierzy diagonalnej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param throw - błąd logiczny (niedozwolone znaki ASCII)
 */
template<class M>
void DiagonalMatrix<M>::insertMtrx() {
  bool error, repeatMess = false;
  std::cout << "\nAby przejsc dalej, podaj kolejne elementy macierzy diagonalnej.\n";
  std::cout << "Uwaga! Jesli podasz wiecej elementow, zostana one przeze mnie zignorowane.\n";
  do {
    try {
      error = false;
      std::cout << "\nWpisz tutaj" << (!repeatMess ? "" : " ponownie") << " elemety macierzy diagonalnej (po spacji):\n";
      for(unsigned int i = 0; i < this->mtrxWidth; i++) {
        std::cin >> this->diagTab[i];
      }
      if(std::cin.fail()) {
        throw std::logic_error("badInputValue");
      }
    }
    catch(std::logic_error&) {
      std::cout << "\nUwaga! W wprowadzonych przez ciebie elementach macierzy\n";
      std::cout << "diagonalnej wykrylem niedozwolone wartosci!\n";
      std::cout << "\nAby kontyuowac wprowadz ponownie wartosci macierzy diagonalnej (po przekatnej).\n";
      error = repeatMess = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(error);
}

/**
 * @fn generateDiagMtrx(bool identityMtrx)
 * @brief Metoda wprowadzająca do konkretnych komórek macierzy konkretne znaki. Jeśli parametr
 * indentityMtrx jest ustawiony na "true", generuje macierz diagonalną na podstawie znaków tablicy
 * dynamicznej diagTab[]. Jeśli jest ustawiony na "false", generuje macierz jednostkową.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param identityMtrx - przełącznik pomiędzy macierzą diagonalną a jednostkową (jednostkowa -> true)
 */
template<class M>
void DiagonalMatrix<M>::generateDiagMtrx(bool identityMtrx) {
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(i == j) {
        (!identityMtrx ? this->mtrx[i][j] = this->diagTab[j] : this->mtrx[i][j] = 1);
      } else {
        this->mtrx[i][j] = 0;
      }
    }
  }
}

template class diagonalMatrixPackage::DiagonalMatrix<int>;
template class diagonalMatrixPackage::DiagonalMatrix<double>;