#include "auxiliaryFunc.h"

void matrixFinalInfo(std::string header, std::initializer_list<std::string> mess) {
  unsigned int headerLength = header.length() + 2;
  /** Długość najdłuższego stringa + 4 */
  unsigned int maxLength = (*std::max_element(mess.begin(), mess.end())).length() - headerLength;
  if(maxLength % 2 == 0) { /** Jeśli długość jest parzysta */
    maxLength = maxLength + 5;
  } else {
    maxLength = maxLength + 4;
  }
  /** Generacja nagłówka */
  for(unsigned int i = 0; i < maxLength / 2; i++) { std::cout << "="; }
  std::cout << " " << header << " ";
  for(unsigned int i = 0; i < maxLength / 2; i++) { std::cout << "="; }
  std::cout << "\n";
  /** Generacja głównego kontentu tekstowego */
  for(auto pos = mess.begin(); pos != mess.end(); pos++) {
    std::cout << " " << *pos << "\n";
  }
  /** Generowanie stopki */
  for(unsigned int i = 0; i < maxLength + headerLength - 1; i++) { std::cout << "="; }
}