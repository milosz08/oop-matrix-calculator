#include "auxiliaryFunc.h"

/*!
 * @fn genInfoBlock(std::string header, std::initializer_list<std::string> mess)
 * @brief Funkcja interfejsu generująca wiadomości na podstawie tytułu (header) oraz stringów
 * w liście inicjalizacyjnej. Funkcja ta przyjmuje jeden argument nagłówka oraz n-elementów treści.
 * @param header - nagłówek (string)
 * @param mess - treść (każdy string umieszczony w nawiasach klamrowych, oddzielone przecinkiem)
 */
void genInfoBlock(std::string header, std::initializer_list<std::string> mess) {
  unsigned int headerLength = header.length() + 2;
  /** Długość najdłuższego stringa + 4 */
  unsigned int maxLength = (*std::max_element(mess.begin(), mess.end())).length() - headerLength;
  if(maxLength % 2 == 0) { /** Jeśli długość jest parzysta */
    maxLength = maxLength + 5;
  } else {
    maxLength = maxLength + 4;
  }
  /** Generacja nagłówka */
  std::cout << "\n";
  for(unsigned int i = 0; i < maxLength / 2; i++) { std::cout << "+"; }
  std::cout << " " << header << " ";
  for(unsigned int i = 0; i < maxLength / 2; i++) { std::cout << "+"; }
  std::cout << "\n";
  /** Generacja głównego kontentu tekstowego */
  for(auto pos = mess.begin(); pos != mess.end(); pos++) {
    std::cout << " " << *pos << "\n";
  }
  /** Generowanie stopki */
  for(unsigned int i = 0; i < maxLength + headerLength - 1; i++) { std::cout << "+"; }
  std::cout << "\n";
}

/*!
 * @fn errorSequentialMess()
 * @brief Funkcja interfejsu generująca asynchroniczny licznik błędu, zliczający od
 * n czasu do zera, gdzie n to skończona liczba całkowita (licznik zlicza z prędkością 700ms).
 */
void errorSequentialMess(int n) {
  std::cout << "\nPonawianie za: ";
  for(int i = n; i >= 0; i--) {
    std::cout << i;
    Sleep(700);
    std::cout << "\b";
  }
}