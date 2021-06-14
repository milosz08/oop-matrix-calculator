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


void errorMess(std::string mess) {
  HANDLE hOut;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
  genInfoBlock("ERROR!", { mess });

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  sequentialMess(5, "Ponawianie za");
  std::system("cls");
}


std::string saveMtrxInfo(unsigned int& type, unsigned int& val) {
  std::string output{""};
  switch(type) {
    case 1: { /** type 1 = macierz prostokątna */
      output = "Macierz prostokatna "; break;
    } case 2: { /** type 2 = macierz kwadratowa */
      output = "Macierz kwadratowa "; break;
    } case 3: { /** type 3 = macierz diagonalna */
      output = "Macierz diagonalna "; break;
    }
  }
  output += "mozliwa do zapelnienia";
  switch(val) {
    case 1: { /** val 1 = jedynie wartości stałoprzecinkowe */
      output += " jedynie wartosciami staloprzecinkowymi."; break;
    } case 2: { /** val 1 = wartości stałoprzecinkowe oraz zmiennoprzecinkowe */
      output += " zarowno wartosciami staloprzecinkowymi jak i zmiennoprzecinkowymi."; break;
    }
  }
  return output;
}