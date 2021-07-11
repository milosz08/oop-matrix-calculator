#include "MatrixAbstract.hpp"

/*!
 * @fn MatrixAbstract(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor dwuargumentowy (macierze prostokątne).
 *        Alokuje pamięć dla tablicy dynamicznej dwuwymiarowej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param w - szerokość macierzy (ilość kolumn).
 * @param h - wysokość macierzy (ilośc wierszy).
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(unsigned short int& w, unsigned short int& h) : mtrxWidth{w}, mtrxHeight{h} {
  allocateMemory();
}


/*!
 * @fn MatrixAbstract(const MatrixAbstract& c)
 *
 * @brief Konstruktor kopiujący. Rozwiązuje problem alokacji pamięci przy
 *        domyślnym konstruktorze kopiującym (ustawia inne adresy pamięci).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param c - Kopia obiektu przekazywana przez referencję.
 */
template<class M>
MatrixAbstract<M>::MatrixAbstract(const MatrixAbstract<M>& c) : mtrxWidth{c.mtrxWidth}, mtrxHeight{c.mtrxHeight} {
  mtrx = new M* [c.mtrxHeight];

  for(unsigned short int i = 0; i < c.mtrxHeight; i++) {
    mtrx[i] = new M [c.mtrxWidth];
  }
}


/*!
 * @fn ~MatrixAbstract()
 *
 * @brief Destruktor wirtualny. Usuwa tablicę dynamiczną wskaźników (liczba wierszy macierzy) oraz
 *        tablice dynamiczne wskazywane przez tablicę wskaźników (wartości w tablicach dynamicznych).
 *        Wywołuje również destruktory klas pochodnych.
 */
template<class M>
MatrixAbstract<M>::~MatrixAbstract() {
  for(unsigned short int i = 0; i < mtrxHeight; i++) {
    delete[] mtrx[i];
  }
  delete[] mtrx;
}


/*!
 * @fn get_Cols()
 * @brief Getter klasy abstrakcyjnej "MatrixAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca ilość kolumn macierzy (szerokość macierzy).
 */
template<class M>
unsigned short int MatrixAbstract<M>::get_Cols() const { return mtrxWidth; }


/*!
 * @fn get_Rows()
 * @brief Getter klasy abstrakcyjnej "MatrixAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca ilość wierszy macierzy (wysokość macierzy).
 */
template<class M>
unsigned short int MatrixAbstract<M>::get_Rows() const { return mtrxHeight; }


/*!
 * @fn get_Mtrx()
 * @brief Getter klasy abstrakcyjnej "MatrixAbstract".
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @return Getter zwraca macierz w postaci dynamicznej dwuwymiarowej tablicy.
 */
template<class M>
M** MatrixAbstract<M>::get_Mtrx() const { return mtrx; }


/*!
 * @fn pringMtrx()
 * @inherit Metoda, którą dziedziczą wszyskie klasy pochodne od klasy abstrakcyjnej. Metoda niewirtualna.
 *
 * @brief Metoda drukująca na ekran zawartość macierzy na podstawie wartości
 *        zapisanych w dwuwymiarowej tablicy dynamicznej. Metoda niemodyfikująca obiektu (const).
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param textMess - jeśli "true" drukuje komunikat, jeśli "false" drukuje jednynie macierz.
 *
 * @param sharpBrc - "true" dla zaznaczenia macierzy, "false" dla zaznaczenia wyznacznika macierzy.
 */
template<class M>
void MatrixAbstract<M>::printMtrx(HANDLE& hOut, const bool textMess, const bool sharpBrc) const {

  unsigned short int spaces{0}, longestNr{0};

  if(textMess) {

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    genInfoBlock("POWODZENIE!", {
            "Z wprowadzonych przez Ciebie parametrów udało mi sie wygenerować macierz!",
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nZapisałem następujacą macierz ";
    std::cout << (mtrxHeight == mtrxWidth ? "kwadratową:\n\n" : "prostokatną:\n\n");
  }

  for(unsigned short int i = 0; i < mtrxHeight; i++) {
    for(unsigned short int j = 0; j < mtrxWidth; j++) {

      longestNr = longestNumber(j); /** @skip Najdłuższa liczba w kolumnie */
      spaces = longestNr - longOfCell(mtrx[i][j]) + 2; /** @skip Ilość pustych znaków */

      if(j == 0) { /** @skip Jeśli jest to 1 kolumna macierzy */
        std::cout << (sharpBrc ? "  [  " : "  |  ");
      }

      /** @skip Wypisanie macierzy z precyzją cyfr na podstawie najdłuższej liczby w kolumnie */
      std::cout << std::setprecision(longestNr - 1) << mtrx[i][j];

      /** @skip Dodaj puste znaki w celu wyrównania kolumn */
      for(unsigned short int k = 0; k < spaces; k++) {
        std::cout << " ";
      }

    }
    std::cout << (sharpBrc ? "]" : "|") << "\n";
  }
}


/*!
 * @fn scalarValuePush()
 * @inherit Metoda, którą dziedziczą wszyskie klasy pochodne od klasy abstrakcyjnej. Metoda niewirtualna.
 *
 * @brief Wprowadzanie przez użytkownika wartości skalara.<br>
 *
 *        Metoda posiada walidację pod kątem strumienia wejścia. Jeśli zostaną podane nieprawidłowe wartości,
 *        program wyświetli błąd i umożliwi ponowne wpisanie wartości skalara przez użytkownika.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @return Metoda zwraca wartość skalara zapisaną w polu klasy.
 */
template<class M>
double MatrixAbstract<M>::scalarValuePush(HANDLE& hOut) {
  bool error{false}, repeatMess{false};

  do {
    error = false;

    std::cout << "\nAby przejść dalej, podaj wartość skalarną, przez ktorą chcesz przemnożyc macierz.\n";

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    genInfoBlock("UWAGA!", {
            "Jeśli podasz więcej elementów, zostaną one przeze mnie zignorowane."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nWpisz tutaj" << (!repeatMess ? "" : " ponownie") << " wartość skalarną: ";
    std::cin >> scalarVal;

    if(std::cin.fail()) {

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
  return scalarVal;
}


/*!
 * @fn allocateMemory()
 * @inherit Metoda niedziedziczna. Tylko na użytek konstruktorów klasy abstrakcyjnej.
 *
 * @brief Metoda prywatna klasy abstrakcyjnej. Alokuje dynamicznie pamięć w formie tablicy wskaźników
 *        typu M (int/double) o wielkości równej ilości wierszy oraz tworząca dynamiczne tablice
 *        (ich ilość jest zależna od ilości wierszy) o wielkości równej ilości kolumn w macierzy.
 *        Wywoływana w konstruktorach klasy abstrakcyjnej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void MatrixAbstract<M>::allocateMemory() {
  mtrx = new M* [mtrxHeight];

  for(unsigned short int i = 0; i < mtrxHeight; i++) {
    mtrx[i] = new M [mtrxWidth];
  }
}


/*!
 * @fn ifValueIsInt(std::string& elm)
 * @inherit Metoda niedziedziczna. Tylko na użytek metod klasy abstrakcyjnej.
 *
 * @brief Weryfikacja, czy dana wartość jest typu int czy double.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param elm - badana wartość komórki (w postaci stringa).
 *
 * @return Metoda zwraca wartość logiczną. Jeśli jest to int -> true, w przeciwnym wypadku false.
 */
template<class M>
bool MatrixAbstract<M>::ifValueIsInt(std::string& elm) const {
  for(unsigned short int i = 0; i < elm.length(); i++) {
    if(elm[i] == '.') {
      return false;
    }
  }
  return true;
}


/*!
 * @fn findMaxLength(unsigned int& col)
 * @inherit Metoda niedziedziczna. Tylko na użytek metod klasy abstrakcyjnej.
 *
 * @brief Wyznaczenie, odszukanie i zwrócenie najdłużego ciągu liczbowego w jednej kolumnie macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param col - aktualnie obsługiwana kolumna (indeks).
 *
 * @return Najdłuższy ciąg liczbowy w n kolumnie (wartość n = param col).
 */
template<class M>
unsigned short int MatrixAbstract<M>::longestNumber(unsigned short int& indexOfRow) const {
  std::vector<unsigned short int> colSizes;
  std::string cellStr, changeStr;

  for(unsigned short int i = 0; i < mtrxWidth; i++) {
    cellStr = std::to_string(mtrx[i][indexOfRow]);

    if(!ifValueIsInt(cellStr)) { /** @skip Tylko dla wartości double */
      cellStr.erase(cellStr.find_last_not_of('0') + 1, std::string::npos);
    }

    colSizes.push_back(cellStr.length());
  }

  return *std::max_element(colSizes.begin(), colSizes.end());
}


/*!
 * @fn longOfCell(M& cell)
 * @inherit Metoda niedziedziczna. Tylko na użytek metod klasy abstrakcyjnej.
 *
 * @brief Wyznaczanie i zwrócenie długości wartości liczbowej typu "unsigned int" w pojedynczej komórce macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param cell - wartość typu M przekazywana do komórki przez referencję.
 *
 * @return Długość wartości pobieranej ze zmiennej "cell" typu M przez referencję.
 */
template<class M>
unsigned short int MatrixAbstract<M>::longOfCell(M& cell) const {
  std::string cellStr;

  cellStr = std::to_string(cell);

  if(!ifValueIsInt(cellStr)) { /** @skip Tylko dla wartości double */
    cellStr.erase(cellStr.find_last_not_of('0') + 1, std::string::npos);
    cellStr.erase(cellStr.find_last_not_of('.') + 1, std::string::npos);
  }

  return cellStr.length();
}


/*!
 * @fn genInfoBlock(std::string header, std::vector<std::string> mess)
 *
 * @brief Funkcja interfejsu generująca wiadomości na podstawie tytułu (header) oraz stringów
 *        w wektorze. Funkcja ta przyjmuje jeden argument nagłówka oraz n-elementów treści.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param header - nagłówek (string)
 *
 * @param mess - treść (każdy string umieszczony w nawiasach klamrowych, oddzielone przecinkiem)
 */
template<class M>
void MatrixAbstract<M>::genInfoBlock(std::string header, std::vector<std::string> mess) {

  /** @skip Długość wyrazu w nagłówku powiększona o 2 */
  unsigned int headerLength = header.length() + 2;

  /** @skip Wyrażenie lambda porównujące wielkość 2 stringów, zwracające prawdę, jeśli string
   * b jest dłuższy od stringu a */
  auto lambdaFind = [](const std::string& a, const std::string& b) {
    return a.length() < b.length();
  };

  /** @skip Wyznacznie maksymalnej długości stringa w wektorze stringów mess (pomniejszony o 2) */
  unsigned int maxLength = std::max_element(mess.begin(), mess.end(), lambdaFind)->length() - headerLength - 2;

  if(maxLength % 2 == 0) { /** @skip Dla stringów parzystych */
    maxLength += 5;
  } else { /** @skip Dla stringów nieparzystych */
    maxLength += 4;
  }

  /** @skip Generacja nagłówka */
  std::cout << "\n";
  for(unsigned int i = 0; i < 5; i++) { std::cout << "+"; }
  std::cout << " " << header << " ";
  for(unsigned int i = 0; i < maxLength - 5; i++) { std::cout << "+"; }
  std::cout << "\n";

  /** @skip Generacja głównego kontentu tekstowego (jeśli w headerze error -> strumień wyjścia błędu cerr) */
  std::vector<std::string>::iterator pos;
  for(pos = mess.begin(); pos != mess.end(); pos++) {
    if(header != "error!" || header != "ERROR!") {
      std::cout << " " << *pos << "\n";
    } else {
      std::cerr << " " << *pos << "\n";
    }
  }

  /** @skip Generowanie stopki */
  for(unsigned int i = 0; i < maxLength + headerLength; i++) { std::cout << "+"; }
  std::cout << "\n";
}


/*!
 * @fn errorMess(std::string mess, HANDLE& hOut)
 *
 * @brief Metoda statyczna klasy abstrakcyjnej. Drukowanie na ekranie komunikatu błędu na podstawie stringa
 *        przekazywanego w argumentach funkcji. Metoda posiada czyszczenie strumienia wejścia.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param mess - wiadomość, która zostanie wygenerowana (string).
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
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
 * @fn sequentialMess(unsigned int n, std::string mess)
 *
 * @brief Metoda statyczna klasy abstrakcyjnej. Generuje sekwencyjne odliczanie.
 *        Używana głównie w komunikatach błędu.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param n - czas odliczania (wartość całkowita, bezznakowa)
 *
 * @param mess - wiadomość pojawiająca się przy odliczaniu
 */
template<class M>
void MatrixAbstract<M>::sequentialMess(unsigned short int n, std::string mess) {
  std::cout << "\n" << mess << ": ";
  for(int i = n; i >= 0; i--) {
    std::cout << i;
    Sleep(700);
    std::cout << "\b";
  }
}