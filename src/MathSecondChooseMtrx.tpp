#include "InterfaceDecl.hpp"


/*!
 * @fn mathSecondMatrix(MatrixAbstract<T>* objF, MatrixAbstract<T>* objS, HANDLE& hOut)
 *
 * @brief Funkcja umożliwiająca użytkownikowi wpisanie macierzy (na podstawie wskaźnika klasy abstrakcyjnej) oraz
 *        wybranie działania, jakie program ma zrobić na dwóch wprowadzonych macierzach. Dostępne działania to:
 *        dodawanie, odejmowanie oraz mnożenie.<br>
 *
 *        Funkcja posiada walidację strumienia wejścia. Jeśli użytkownik nie poda liczby z zakresu 1-3
 *        program zasygnalizuje błąd i po odczekaniu 5 sekund umożliwi użytkownikowi ponowne wybranie opcji.
 *
 * @tparam T - wzorzec, który reprezentuje wartości jakimi można zapełnić macierz (int/double).
 * @tparam A - wartość szablonu klasy abstrakcyjnej (używane tylko do metody z klasy abstrakcyjnej
 *             "genInfoBlock" oraz "errorMess" przy operatorze zakresu).
 *
 * @param objF - wskaźnik klasy abstrakcyjnej reprezentujący obiekt klasy dziedziczącej (macierz pierwsza)
 * @param objS - wskaźnik klasy abstrakcyjnej reprezentujący obiekt klasy dziedziczącej (macierz druga)
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @return Funkcja zwraca opcję wybraną przez użytkownika (w postaci wartości całkowitej) z zakresu 1-3.
 */
template<typename T>
unsigned short int mathSecondMatrix(MatrixAbstract<T> *objF, MatrixAbstract<T> *objS, HANDLE &hOut) {

    unsigned short int choice{0}; /** @skip Zwracany wybór opcji */
    bool error{false}; /** @skip Zwalnianie/ustawianie blokady pętli */

    objS->insertMtrx(hOut); /** @skip Wprowadzanie macierzy */

    do {

        error = false;

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        MatrixAbstract<double>::genInfoBlock("SUKCES!", {
                "Z wprowadzonych przez Ciebie parametrów wygenerowałem poniższe macierze.",
        });

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        std::cout << "\nPierwsza wprowadzona przez Ciebie macierz:\n\n";
        objF->printMtrx(hOut, false, true);

        std::cout << "\nDruga wprowadzona przez Ciebie macierz:\n\n";
        objS->printMtrx(hOut, false, true);

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "\n";

        MatrixAbstract<double>::genInfoBlock("ETAP 5", {
                "Wybierz działanie, jakie chcesz wykonać na podanych przez Ciebie macierzach:",
                "1. Chcę dodać do siebie wpisane przeze mnie macierze.",
                "2. Chcę odjąć od siebie wpisane przeze mnie macierze.",
                "3. Chcę pomnożyć przez siebie wpisane przeze mnie macierze."
        });

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        std::cout << "\nTwój wybór: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 3) {
            error = true;
            MatrixAbstract<double>::errorMess("Błąd strumienia wejścia. Wybrana opcja nie istnieje.", hOut);
        }

    } while (error);
    std::system("cls"); /** @skip czyszczenie konsoli */
    return choice;
}