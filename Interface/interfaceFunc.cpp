#include "interfaceFunc.h"

unsigned int mainMenu() {
  unsigned int choice{0};
  HANDLE hOut;
  hOut = GetStdHandle( STD_OUTPUT_HANDLE );

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  std::cout << "\n#####################################################\n";
  std::cout << "###############  KALKULATOR MACIERZY  ###############\n";
  std::cout << "#####################################################\n";

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  genInfoBlock("AUTOR", {
    "Napisane w C++ z uzyciem mechanizmow obiektowosci przez Milosz Gilga.",
    "Programowanie Komputerow, Wydzial Elektryczny, Politechnika Slaska, Gliwice.",
    "(c) 2021 by Milosz Gilga (github.com/Milosz08)."
  });

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  genInfoBlock("WSPIERANE OPERACJE", {
    "* Obliczanie wyznacznika macierzy 1, 2 oraz n-elementowej (tylko macierze kwadratowe).",
    "* Obliczanie macierzy odwrotnej wzgledem macierzy pierwotnej (tylko macierze kwadratowe).",
    "* Obliczanie macierzy sprzezonej wzgledem macierzy pierwotnej.",
    "* Podstawowe dzialania arytmetyczne (dodawanie, odejmowanie, mnozenie).",
    "* Mnozenie macierzy przez wartosc skalarna.",
    "* Transponowanie macierzy.",
  });

  SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
  genInfoBlock("MENU POCZATKOWE", {
    "Aby zainicjalizowac program, wybierz jedna opcje z ponizszego menu:",
    "1. Chce przesc do glownego menu wyboru operacji.",
    "2. Chce zakonczyc działanie programu.",
  });

  std::cout << "\nTwoj wybor: ";
  std::cin >> choice;
  return choice;
}

unsigned int checkInput(unsigned int& choice) {

}


void startPrg() {
  int initChoice = mainMenu();

}