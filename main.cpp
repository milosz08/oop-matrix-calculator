#include "Program Interface/src/interfaceDecl.hpp"

/*!
 * @title KALKULATOR MACIERZY
 *
 * @author Miłosz Gilga
 *
 * @date 06/2021
 *
 * @copyright (c) 2021 by Miłosz Gilga. Cały kod wraz z opisem oraz kolejnymi etapami produkcji programu
 *            (wszystkie commity wraz z tagami razem z opisem) znajduje się na moim repozytorium
 *            GitHub pod adresem: https://github.com/Milosz08/Matrix-Calculator-Objective-Cpp.
 *
 * @brief Program wykonany na przedmiot Programowanie Komputerów z wykorzystaniem elementów
 *        obiektowości języka C++. Wydział Elektryczny, Politechnika Śląska, Gliwice 2021.<br><br>
 *
 *        Program oparłem na 3 klasach, z czego jedna to klasa abstrakcyjna (interfejs) zawierająca metody i
 *        pola dziedziczące po 2 klasach pochodnych, z których jedna to zwykłe macierze kwadratowe/prostokątne
 *        a druga to macierze diagonalne (tylko kwadratowe). Zdecydowałem się użyć osobnych klas ze względu na
 *        różne metody matematyczne obliczające m. in. wyznacznik, czy macierz odwrotną.<br><br>
 *
 *        W programie wykorzystałem programowanie generyczne w postaci: szablonów klas, w celu zdefiniowania
 *        typu wprowadzanych wartości do macierzy (int/double), szablonów funkcji, w celu zdefiniowania typu
 *        przekazywanych argumentów (klasy/wartości).<br><br>
 *
 *        Program obsługujący podstawowe działania na macierzach kwadratowych, prostokątnych oraz specjalnym
 *        typie macierzy kwadratowych - diagonalnych (macierz diagonalna to macierz, która poza swoją główną
 *        przekątną - diagonalną posiada wartości zerowe).<br><br>
 *
 *        Program wspiera następujące operacje matematyczne na macierzach:<br>
 *          + Obliczanie wyznacznika macierzy n elementowej (tylko macierze kwadratowe),<br>
 *          + Obliczanie macierzy odwrotnej względem macierzy pierwotnej (tylko macierze kwadratowe),<br>
 *          + Obliczanie macierzy sprzężonej względem macierzy pierwotnej,<br>
 *          + Podstawowe działania arytmetyczne (dodawanie, odejmowanie, mnożenie),<br>
 *          + Mnożenie macierzy przez wartość skalarną.<br>
 *          + Transponowanie macierzy.<br>
 */
int main() {
  SetConsoleOutputCP(CP_UTF8); /** @skip Polskie znaki w konsoli */

  startPrg();

  return 0;
}