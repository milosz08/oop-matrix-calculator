#ifndef PK_MATRIX_CALCULATOR_MATRIXABSTRACT_HPP
#define PK_MATRIX_CALCULATOR_MATRIXABSTRACT_HPP
#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <vector>
#include <windows.h>
#include <iomanip>


namespace matrixAbstractPackage {
  /*!
   * @class MatrixAbstract
   *
   * @brief Klasa abstrakcyjna. Interfejs programu.
   *
   * @constructors Klasa posiada 4 zadeklarowane konstruktory, z czego jest to: konstruktor bezargumentowy,
   *               konstruktor dwuargumentowy przyjmujący za parametry wywołania ilość wierszy i kolumn macierzy,
   *               konstruktor jednoargumentowy przyjmujący za parametr stopień macierzy (macierze kwadratowe),
   *               oraz konstruktor kopiujący, przyjmujący za parametr obiekt do skopiowania (niemodyfikowalny).
   *
   * @destructor Klasa posiada destruktor wirtualny delokujący pamięć, wywołujący destruktory z klas pochodnych
   *             w celu ochrony programu przed wyciekami pamięci.
   *
   * @methods Klasa posiada 3 metody statyczne, wykorzystywane na potrzeby metod składowych klas dziedziczących oraz
   *          funkcji interfejsu. Ponadto posiada 2 metody czysto wirtualne przysłaniane w klasach dziedziczących.
   *          Oprócz tego posiada 2 metody nieprzysłanialne, wspólne i jednakowe dla każdego obiektu klasy
   *          dziedziczącej. Klasa posiada również własne 3 metody niedziedziczne, stanowiące uzupełnienie metod
   *          wirtualnych.
   *
   * @getters Klasa posiada zadeklarowane 3 funkcje getter dające możliwość dostępu do chronionych pól. Są to
   *          odpowiednio: pobieranie parametrów macierzy (w postaci liczby wierszy lub kolumn) oraz pobieranie
   *          całej macierzy w postaci dynamicznej tablicy wskaźników.
   *
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   *
   * @param mtrxWidth - liczba kolumn macierzy (długość macierzy)
   * @param mtrxHeight - liczba wierszy macierzy (wysokość macierzy)
   *
   * @param scalarVal - wartość skalara wprowadzana przez użytkownika
   *
   * @param mtrx - tablica wskaźników reprezentująca macierz
   */
  template<typename M>
  class MatrixAbstract {
    public:
      MatrixAbstract();
      MatrixAbstract(unsigned short int&, unsigned short int&); /** Sygnatura konstr. dla macierzy prostokątnych */
      MatrixAbstract(unsigned short int&); /** Sygnatura konstr. dla macierzy kwadratowych */
      MatrixAbstract(const MatrixAbstract<M>&); /** Sygnatura konstr. kopiującego */

      void printMtrx(HANDLE&, const bool, const bool) const; /** Drukowanie macierzy */
      double scalarValuePush(HANDLE&); /** Wprowadzanie wartości skalara */

      virtual void mtrxTypeAndSizeInfo() = 0; /** Wypisywanie wiadomosci */
      virtual void insertMtrx(HANDLE&) = 0; /** Wprowadzanie macierzy */

      /** Metody statyczne (dodatek interfejsu użytkownika) */
      static void genInfoBlock(std::string, std::vector<std::string>);
      static void sequentialMess(unsigned short int, std::string);
      static void errorMess(std::string, HANDLE&);

      virtual ~MatrixAbstract(); /** Wirtualny destruktor wywołujący destruktory z klas pochodnych */

    private: /** Metody prywatne; dostępne tylko na użytek metod klasy abstrakcyjnej */
      void allocateMemory(); /** Alokacja pamięci */
      bool ifValueIsInt(std::string&) const;
      unsigned short int longestNumber(unsigned short int&) const;
      unsigned short int longOfCell(M&) const;

    public: /** Gettery */
      unsigned short int get_Cols() const;
      unsigned short int get_Rows() const;
      M** get_Mtrx() const;

    protected:
      unsigned short int mtrxWidth{0}, mtrxHeight{0}; /** Wymiary macierzy */
      double scalarVal{0}; /** Wartość skalara */
      M** mtrx{nullptr}; /** Tablica wskaźników typu M reprezentująca macierz */
  };

  #include "src/constructors.tpp" /** Deklaracje konstruktorów */
  #include "src/nonVirtMethods.tpp" /** Metody dziedziczące, niewirtualne */
  #include "src/staticMethods.tpp" /** Szablonowe metody statyczne */
  #include "src/privateMethods.tpp" /** Metody prywatne (niedziedziczne) */
  #include "src/getters.tpp" /** Metody zwracające wartości pól chronionych - gettery */
}

#endif