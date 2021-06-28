# Kalkulator Macierzy

## Temat zadania
Macierze prostokątne, pamięć alokowana dynamicznie, sprawdzanie
wymiarów podczas operacji, podstawowe działania jak dodawanie,
odejmowanie, mnożenie, obliczanie wyznacznika. Oprócz podstawowych
działań na macierzach należy: wyznacznyć macierz odwrotną, macierz
transponowaną itp. Należy obowiązkowo zastosować wzorce.

## Autor
Program wykonany przez Miłosz Gilga na przedmiot **Programowanie Komputerów** z
wykorzystaniem elementów obiektowości języka C++. Wydział Elektryczny, Politechnika
Śląska, Gliwice 2021.

## Wspierane operacje matematyczne
* Obliczanie wyznacznika macierzy `n` elementowej (tylko macierze kwadratowe),
* Obliczanie macierzy odwrotnej względem macierzy pierwotnej (tylko macierze kwadratowe),
* Obliczanie macierzy sprzężonej względem macierzy pierwotnej,
* Podstawowe działania arytmetyczne (dodawanie, odejmowanie, mnożenie),
* Mnożenie macierzy przez wartość skalarną,
* Transponowanie macierzy.


## Techniczne aspekty programu
### Opis klas
Program oparłem na 3 klasach, z czego jedna to klasa abstrakcyjna `MatrixAbstract`
(interfejs) zawierająca metody i pola dziedziczące po 2 klasach pochodnych, z których
jedna `GeneralMatrix` to zwykłe macierze kwadratowe/prostokątne, a druga `DiagonalMatrix`
to macierze diagonalne (które z definicji są tylko kwadratowe). Zdecydowałem się
użyć osobnych klas ze względu na różne metody matematyczne obliczające między innymi
wyznacznik, czy macierz odwrotną.<br>

### Programowanie generyczne (szablony)
W programie wykorzystałem programowanie generyczne w postaci:
* **szablonów klas**, w celu zdefiniowania typu wprowadzanych wartości do macierzy (int/double),
* **szablonów funkcji**, w celu zdefiniowania typu przekazywanych argumentów (klasy/wartości),

### Obsługa wyjątów (throw)
W programie zaimplementowałem obsługę wyjątków (błędów typu `std::logic_error`) powstałych
na skutek wykonania niedozwolonych operacji arytmetycznych, między innymi: wyznacznik
z macierzy, która nie jest kwadratowa, czy macierz odwrotna z macierzy, której wyznacznik
jest równy zero. Wszystkie wyjątki metod obliczających oraz funkcji zaprzyjaźnionych
obsługiwane są w funkcji interfejsu `startPrg()`. Wyrzucenie każdego wyjątku kończy 
działanie programu z informacją o błędzie.

## Rozszerzalność programu
Dzięki użyciu klasy abstrakcyjnej w formie interfejsu przechowującego metody i pola
definiujące różne składowe funkcji matematycznych oraz samych macierzy, dodanie nowej
klasy (np. definiującej macierze jednostkowe) nie będzie zbyt dużym problemem.

### Przestrzenie nazw
W programie wykorzystałem przestrzenie nazw. Użyte w celu opakowania klas składowych programu
pełnią podobną funkcję do pakietów w Javie. Dzięki temu konflikty nazw (jeśli użytkownik odwołuje
się do składowych metod klasy poprzez operator zakresu) są zniwelowane.

## Uruchamianie programu
Program można uruchomić poprzez plik `PK_Matrix_Calculator.exe` znajdujący się w katalogu
`../cmake-build-debug/PK_Matrix_Calculator.exe`. Program ten jest programem konsolowym.
Pełne wsparcie dla systemu Windows 10 (v20H2) 64-bit. Program nietestowany na systemach
Linux oraz macOS.

## Dokumentacja DOXYGEN
Komentarze programu są zgodne ze standardem Doxygen. Dla projektu wygenerowałem dokumentację przy pomocy
Doxygena w formie strony HTML. Możliwość wygenerowania także w formie PDF przy użyciu narzędzi 
pracujących w formacie LaTeX.