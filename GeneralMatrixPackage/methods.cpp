#include <iostream>
#include <limits>
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
  std::cout << "\nZapisalem nastepujace wymiary macierzy ";
  if(this->mtrxWidth == this->mtrxHeight) {
    std::cout << "kwadratowej";
  } else {
    std::cout << "prostokatnej";
  }
  std::cout << "\no wymiarach: " << this->mtrxWidth << " x " << this->mtrxHeight;
  std::cout << ", posiadajacej liczbe " << this->mtrxWidth * this->mtrxHeight << " komorek.\n";
}

/**
 * @fn insertMtrx()
 * @brief Metoda umożliwiająca wprowadzenie przez użytkownika elementów macierzy do dwuwymiarowej
 * tablicy dynamicznej stworzonej w klasie abstrakcyjnej. Metoda posiada walidację strumienia wejścia
 * pod kątem wprowadzanych znaków do macierzy. Jeśli znak nie jest zgody z typem zmiennej
 * we wzorcu "M" program wyrzuca błąd i daje możliwość ponownego wpisania macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param throw - błąd logiczny (niedozwolone znaki ASCII)
 */
template<class M>
void GeneralMatrix<M>::insertMtrx() {
  bool error, repeatMess = false;
  std::cout << "\nAby przejsc dalej, podaj kolejne elementy macierzy.\n";
  std::cout << "Uwaga! Jesli podasz wiecej elementow, zostana one przeze mnie zignorowane.\n";
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

template class generalMatrixPackage::GeneralMatrix<int>;
template class generalMatrixPackage::GeneralMatrix<double>;