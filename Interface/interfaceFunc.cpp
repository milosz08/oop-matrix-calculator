#include "interfaceFunc.h"

void mainMenu() {
  unsigned int choice{0}, retChoice{0};
  bool error{false};
  HANDLE hOut;
  hOut = GetStdHandle( STD_OUTPUT_HANDLE );

  do {
    error = false;

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
      "2. Chce zakonczyc dzialanie programu.",
    });

    try {
      std::cout << "\nTwoj wybor: ";
      std::cin >> choice;
      switch(choice) {
        case 1: { std::system("cls"); break; }
        case 2: {
          sequentialMess(5, "Program zakonczy dzialanie za");
          std::cout << "\nDziekuje za skorzystanie z kalkulatora macierzy. Program zakonczyl dzialanie.\n";
          abort();
        }
        default: { throw std::runtime_error("notExistValue"); break; }
      }
    }
    catch(std::runtime_error) {
      SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
      genInfoBlock("ERROR!", {
        "Wybrana przez Ciebie opcja menu nie istnieje!"
      });

      error = true;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
      sequentialMess(5, "Ponawianie za");
      std::system("cls");
    }
  } while(error);
}

void chooseTypeOfMatrix() {
  HANDLE hOut;
  hOut = GetStdHandle( STD_OUTPUT_HANDLE );

  genInfoBlock("TYP MACIERZY", {
    "Wybierz, na jakim typie macierzy chcesz przeprowadzac operacje:",
    "1. Chce przeprowadzac operacje na macierzy prostokatnej.",
    "2. Chce przeprowadzac operacje na macierzy kwadratowej."
  });
}



void startPrg() {
  mainMenu();
  chooseTypeOfMatrix();
}