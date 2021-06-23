#include "interfaceDecl.hpp"


void startPrg() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); /** Obsługa kolorów w konsoli CMD */

  try {

    mainMenu(hOut);
    initMtrxObj(hOut);

  } catch(std::logic_error& e) {

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    MatrixAbstract<double>::genInfoBlock("Error!", {
      "Błąd podczas wykonywania operacji matematycznej.", e.what(),
      "Błąd ten skutkuje zakończeniem działania programu."
    });

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    std::cout << "\nDziękuję za skorzystanie z kalkulatora macierzy.\n";
    MatrixAbstract<double>::sequentialMess(5, "Program zakończy działanie za");
    std::cout << "\nProgram zakończył działanie!\n";
  }
}