#include "../MatrixAbstract.hpp"


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
    return a.size() < b.size();
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