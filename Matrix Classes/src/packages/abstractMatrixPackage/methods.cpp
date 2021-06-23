#include "MatrixAbstract.hpp"

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

/*!
 * @fn findMaxLength(unsigned int& col)
 * @inherit Metoda tylko na potrzeby metod wirtualnych klasy abstrakcyjnej! Metoda niedziedziczona!
 * @brief Wyznaczenie, odszukanie i zwrócenie najdłużego ciągu liczbowego w jednej kolumnie macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param col - aktualnie obsługiwana kolumna (indeks)
 * @return - najdłuższy ciąg liczbowy w n kolumnie (wartość n = param col)
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
 * @brief Metoda tylko na potrzeby metod wirtualnych klasy abstrakcyjnej! Metoda niedziedziczona!
 * Wyznaczanie i zwrócenie długości wartości liczbowej typu "unsigned int" w pojedynczej komórce macierzy.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param cell - wartość typu M przekazywana do komórki przez referencję
 * @return - długość wartości pobieranej ze zmiennej "cell" typu M przez referencję
 */
template<class M>
unsigned int MatrixAbstract<M>::lengthOfElm(M& cell) const {
  std::string elmLength{""};
  elmLength = std::to_string(cell);
  elmLength.erase(elmLength.find_last_not_of('0') + 1, std::string::npos);
  elmLength.erase(elmLength.find_last_not_of('.') + 1, std::string::npos);
  return elmLength.length();
}

/**
 * @fn pringMtrx()
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie
 * wartości zapisanych w dwuwymiarowej tablicy dynamicznej.
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 * @param textMess - jeśli "true" drukuje komunikat, jeśli "false" drukuje jednynie macierz
 * @param sharpBrc - jeśli "true" drukuje "[]", jeśli false drukuje "|".
 */
template<class M>
void MatrixAbstract<M>::printMtrx(const bool textMess, const bool sharpBrc, const bool autoFreeSpaces) const {
  HANDLE hOut; /** Obsługa kolorów w konsoli CMD */
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  unsigned int spaces{0}; /** Przerwa pomiędzy kolejnymi kolumnami */
  if(textMess) {

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("POWODZENIE!", {
      "Z wprowadzonych przez Ciebie parametrów udało mi sie wygenerować macierz!",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nZapisałem następujacą macierz ";
    std::cout << (this->mtrxHeight == this->mtrxWidth ? "kwadratową:\n\n" : "prostokatną:\n\n");
  }
  for(unsigned int i = 0; i < this->mtrxHeight; i++) {
    for(unsigned int j = 0; j < this->mtrxWidth; j++) {
      if(j == 0) { /** Jeśli jest to 1 kolumna macierzy */
        std::cout << (sharpBrc ? "  [ " : "  | ");
      }
      if(!autoFreeSpaces) {
        std::cout << this->mtrx[i][j];

        if(j == this->mtrxWidth - 1) { /** Jeśli jest to ostatnia kolumna macierzy */
          spaces = findMaxLength(j) - lengthOfElm(this->mtrx[i][j]) - 2;
        } else { /** Pozostałe kolumny macierzy */
          spaces = findMaxLength(j) - lengthOfElm(this->mtrx[i][j]);
        }

        for(unsigned int k = 0; k < spaces; k++) {
          std::cout << " ";
        }

      } else {
        std::cout << this->mtrx[i][j] << "\t";
      }
    }
    std::cout << (sharpBrc ? " ]" : " |") << "\n";
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
double MatrixAbstract<M>::scalarValuePush(HANDLE& hOut) {
  bool error{false}, repeatMess{false};
  do {
    std::cout << "\nAby przejść dalej, podaj wartość skalarną, przez ktorą chcesz przemnożyc macierz.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
      "Jeśli podasz więcej elementów, zostaną one przeze mnie zignorowane."
    });
    try {
      error = false;

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      std::cout << "\nWpisz tutaj" << (!repeatMess ? "" : " ponownie") << " wartość skalarną: ";
      std::cin >> this->scalarVal;
      if(std::cin.fail()) {
        throw std::logic_error("badScalarValue");
      }
    }
    catch(std::logic_error& e) {

      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      genInfoBlock("ERROR!", {
        "W wprowadzanej przez Ciebie wartości skalarnej znalazłem niedozwolone wartości!",
        "Aby kontyuować wprowadź ponownie swoja wartość skalarną."
      });

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");

      std::system("cls");
      error = repeatMess = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while(error);
  return this->scalarVal;
}

/*!
 * @fn genInfoBlock(std::string header, std::vector<std::string> mess)
 * @brief Funkcja interfejsu generująca wiadomości na podstawie tytułu (header) oraz stringów
 * w wektorze. Funkcja ta przyjmuje jeden argument nagłówka oraz n-elementów treści.
 * @param header - nagłówek (string)
 * @param mess - treść (każdy string umieszczony w nawiasach klamrowych, oddzielone przecinkiem)
 */
template<class M>
void MatrixAbstract<M>::genInfoBlock(std::string header, std::vector<std::string> mess) {

  /** Długość wyrazu w nagłówku powiększona o 2 */
  unsigned int headerLength = header.length() + 2;

  /** Wyrażenie lambda porównujące wielkość 2 stringów, zwracające prawdę, jeśli string b jest dłuższy od stringu a */
  auto lambdaFind = [](const std::string& a, const std::string& b) {
    return a.size() < b.size();
  };

  /** Wyznacznie maksymalnej długości stringa w wektorze stringów mess (pomniejszony o 2) */
  unsigned int maxLength = std::max_element(mess.begin(), mess.end(), lambdaFind)->length() - headerLength - 2;

  if(maxLength % 2 == 0) { /** Dla stringów parzystych */
    maxLength += 5;
  } else { /** Dla stringów nieparzystych */
    maxLength += 4;
  }

  /** Generacja nagłówka */
  std::cout << "\n";
  for(unsigned int i = 0; i < 5; i++) { std::cout << "+"; }
  std::cout << " " << header << " ";
  for(unsigned int i = 0; i < maxLength - 5; i++) { std::cout << "+"; }
  std::cout << "\n";

  /** Generacja głównego kontentu tekstowego */
  std::vector<std::string>::iterator pos;
  for(pos = mess.begin(); pos != mess.end(); pos++) {
    std::cout << " " << *pos << "\n";
  }

  /** Generowanie stopki */
  for(unsigned int i = 0; i < maxLength + headerLength; i++) { std::cout << "+"; }
  std::cout << "\n";
}

/*!
 *
 * @tparam M
 * @param mess
 * @param hOut
 */
template<class M>
void MatrixAbstract<M>::errorMess(std::string mess, HANDLE& hOut) {

  SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
  MatrixAbstract<M>::genInfoBlock("ERROR!", { mess });

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  MatrixAbstract<M>::sequentialMess(5, "Ponawianie za");
  std::system("cls");
}


/*!
 *
 * @tparam M
 * @param n
 * @param mess
 */
template<class M>
void MatrixAbstract<M>::sequentialMess(unsigned int n, std::string mess) {
  std::cout << "\n" << mess << ": ";
  for(int i = n; i >= 0; i--) {
    std::cout << i;
    Sleep(700);
    std::cout << "\b";
  }
}


/*!
 *
 * @tparam M
 * @return
 */
template<class M>
unsigned short int MatrixAbstract<M>::get_Cols() const { return this->mtrxWidth; }

/*!
 *
 * @tparam M
 * @return
 */
template<class M>
unsigned short int MatrixAbstract<M>::get_Rows() const { return this->mtrxHeight; }

/*!
 *
 * @tparam M
 * @return
 */
template<class M>
M** MatrixAbstract<M>::get_Mtrx() const { return this->mtrx; }

template class matrixAbstractPackage::MatrixAbstract<short int>;
template class matrixAbstractPackage::MatrixAbstract<double>;