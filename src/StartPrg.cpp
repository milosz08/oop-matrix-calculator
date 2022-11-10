#include "InterfaceDecl.hpp"


/*!
 * @fn startPrg()
 *
 * @brief Funkcja sterująca wywołująca wyświetlanie menu początkowego (opis programu) oraz inicjująca program.
 *        W funkcji zadelkarowany jest uchwyt do konsoli, przekazywany przez referencję do reszty funkcji.
 *        Funkcja posiada wyłapywanie wyjątków z operacji arytmetycznych (metody klas oraz przeciążenia operatorów).
 *
 * @throws Obsługa błędów logicznych. Typ błędu logicznego przekazywany w zmiennej e przez referencję.
 *         Spośród obsługiwanych wyjątków (błędów matematycznych) można wyróżnić:
 *              * dodawanie lub odejmowanie macierzy różnych rozmiarów
 *              * mnożenie macierzy posiadających różną liczbę kolumn w stosunku do wierszy (i na odwrót)
 */
void startPrg() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); /** @skip Uchwyt konsoli CMD */

    try {

        mainMenu(hOut);
        initMtrxObj(hOut);

        std::cout << "\nDziękuję za skorzystanie z kalkulatora macierzy. Program zakończył działanie.\n";
        std::system("pause"); /** @skip Zachowanie okna konsoli po zakończeniu działania programu */

    } catch (std::logic_error &e) {

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