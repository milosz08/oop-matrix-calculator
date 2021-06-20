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
  /** Długość najdłuższego stringa (wykorzystane iteratory i wyrażenie lambda) */
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

/*!
 *
 * @param mess
 */
void errorMess(std::string mess, HANDLE& hOut) {

  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
  genInfoBlock("ERROR!", { mess });

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  sequentialMess(5, "Ponawianie za");
  std::system("cls");
}

/*!
 *
 * @param type
 * @param val
 * @return
 */
std::string saveMtrxInfo(unsigned int& type, unsigned int& val) {
  std::string output{""};
  switch(type) {
    case 1: { /** type 1 = macierz prostokątna */
      output = "Macierz prostokątna "; break;
    } case 2: { /** type 2 = macierz kwadratowa */
      output = "Macierz kwadratowa "; break;
    } case 3: { /** type 3 = macierz diagonalna */
      output = "Macierz diagonalna "; break;
    }
  }
  output += "możliwa do zapełnienia\n";
  switch(val) {
    case 1: { /** val 1 = jedynie wartości stałoprzecinkowe */
      output += "jedynie wartościami stałoprzecinkowymi."; break;
    } case 2: { /** val 1 = wartości stałoprzecinkowe oraz zmiennoprzecinkowe */
      output += "zarowno wartościami stało oraz zmiennoprzecinkowymi."; break;
    }
  }
  return output;
}

/*!
 *
 * @param hOut
 * @return
 */
unsigned int chooseTypeOfMatrix(HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};
  do {
    error = false;

    genInfoBlock("ETAP 1", {
      "Wybierz, na jakim typie macierzy chcesz przeprowadzać operacje:",
      "1. Chcę przeprowadzać operacje na zwykłej macierzy prostokatnej.",
      "2. Chcę przeprowadzać operacje na zwykłej macierzy kwadratowej.",
      "3. Chcę przeprowadzać operacje na kwadratowej macierzy diagonalnej."
    });
    /** Kolor cyjanowy */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("INFO", {
      "Macierz diagonalna to macierz, która poza swoją głowna przekątną (diagonalna)",
      "posiada wartosci zerowe. Na przekątnej diagonalnej znajdą sie podane przez Ciebie wartosci."
    });
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;
    if((choice < 1 || choice > 3) || std::cin.fail()) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }
  } while(error);
  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}

/*!
 *
 * @param hOut
 * @return
 */
unsigned int chooseTypeOfNumbers(HANDLE& hOut) {
  unsigned int choice{0};
  bool error{false};
  do {
    error = false;

    genInfoBlock("ETAP 2", {
      "Wybierz, na jakim typie wartości macierzy chcesz przeprowadzać operacje:",
      "1. Chcę przeprowadzać operacje tylko i wyłącznie na liczbach stałoprzecinkowych.",
      "2. Chcę przeprowadzać operacje na liczbach stałoprzecinkowych i zmiennoprzecinkowych.",
    });
    /** Kolor żółty */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jeśli wybierzesz tylko liczby stałoprzecinkowe, próba zapełnienia macierzy liczbami",
      "zmiennoprzecinkowymi zakończy się błedem. Preferowany typ to macierz obsługująca zarówno",
      "liczby zmiennoprzecinkowe jak i stałoprzecinkowe.",
    });
    /** Kolor biały - reset (wartość domyślna) */
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nTwój wybór: ";
    std::cin >> choice;
    if((choice != 1 && choice != 2) || std::cin.fail()) {
      error = true;
      errorMess("Wybrana przez Ciebie opcja menu nie istnieje!", hOut);
    }
  } while(error);
  std::system("cls"); /** czyszczenie konsoli */
  return choice;
}