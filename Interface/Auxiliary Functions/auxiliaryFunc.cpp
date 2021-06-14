#include "auxiliaryFunc.h"

/*!
 * @fn genInfoBlock(std::string header, std::vector<std::string> mess)
 * @brief Funkcja interfejsu generująca wiadomości na podstawie tytułu (header) oraz stringów
 * w wektorze. Funkcja ta przyjmuje jeden argument nagłówka oraz n-elementów treści.
 * @param header - nagłówek (string)
 * @param mess - treść (każdy string umieszczony w nawiasach klamrowych, oddzielone przecinkiem)
 */
void genInfoBlock(std::string header, std::vector<std::string> mess) {
  unsigned int headerLength = header.length() + 2;
  /** Długość najdłuższego stringa */
  unsigned int maxLength = std::max_element(mess.begin(), mess.end(), [](const auto& a, const auto& b){
    return a.size() < b.size();
  })->length() - headerLength - 2;
  if(maxLength % 2 == 0) { /** Jeśli długość jest parzysta */
    maxLength += 5;
  } else {
    maxLength += 4;
  }
  /** Generacja nagłówka */
  std::cout << "\n";
  for(unsigned int i = 0; i < 5; i++) { std::cout << "+"; }
  std::cout << " " << header << " ";
  for(unsigned int i = 0; i < maxLength - 5; i++) { std::cout << "+"; }
  std::cout << "\n";
  /** Generacja głównego kontentu tekstowego */
  for(auto pos = mess.begin(); pos != mess.end(); pos++) {
    std::cout << " " << *pos << "\n";
  }
  /** Generowanie stopki */
  for(unsigned int i = 0; i < maxLength + headerLength; i++) { std::cout << "+"; }
  std::cout << "\n";
}

/*!
 * @fn errorSequentialMess()
 * @brief Funkcja interfejsu generująca asynchroniczny licznik błędu, zliczający od
 * n czasu do zera, gdzie n to skończona liczba całkowita (licznik zlicza z prędkością 700ms).
 */
void sequentialMess(int n, std::string mess) {
  std::cout << "\n" << mess << ": ";
  for(int i = n; i >= 0; i--) {
    std::cout << i;
    Sleep(700);
    std::cout << "\b";
  }
}