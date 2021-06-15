#ifndef PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H
#define PK_MATRIX_CALCULATOR_MATRIXABSTRACT_H
#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <vector>

namespace matrixAbstractPackage {
  /*!
   * @class MatrixAbstract
   * @brief Klasa abstrakcyjna. Posiada konstruktory: bezargumentowy, dla macierzy
   * prostokątnych, dla macierzy kwadratowych oraz konstruktor kopiujący.
   * Posiada destruktor wirtualny delokujący pamięć oraz wywołujący destruktory z klas pochodnych.
   * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
   * @param mtrxWidth - liczba kolumn macierzy
   * @param mtrxHeight - liczba wierszy macierzy
   * @param scalarVal - wartość skalara wprowadzana przez użytkownika
   * @param mtrx - tablica wskaźników reprezentująca ilość wierszy w macierzy
   */
  template<typename M>
  class MatrixAbstract {
    public:
      explicit MatrixAbstract();
      explicit MatrixAbstract(unsigned int&, unsigned int&); /** Sygnatura konstr. dla macierzy prostokątnych */
      explicit MatrixAbstract(unsigned int&); /** Sygnatura konstr. dla macierzy kwadratowych */
      explicit MatrixAbstract(const MatrixAbstract&); /** Sygnatura konstr. kopiującego */

      virtual void printMtrx(const bool, const bool) const; /** Metoda wirtualna - drukowanie macierzy */
      void allocateMemory(); /** Alokacja pamięci */
      double scalarValuePush(); /** Wprowadzanie wartości skalara */

      virtual void mtrxTypeAndSizeInfo() = 0; /** Metoda czysto wirtualna - wypisywanie wiadomosci */
      virtual void insertMtrx() = 0; /** Metoda czysto wirtualna - wprowadzanie macierzy */
      virtual void finalMathInfo(const std::list<std::string>&);

      virtual ~MatrixAbstract(); /** Wirtualny destruktor wywołujący destruktory z klas pochodnych */

    private: /** Metody prywatne; dostępne tylko na użytek metod klasy abstrakcyjnej */
      unsigned int findMaxLength(unsigned int&) const;
      unsigned int lengthOfElm(M&) const;

    public: /** Gettery */
      unsigned int get_Cols() const;
      unsigned int get_Rows() const;

    protected:
      unsigned int mtrxWidth{0}, mtrxHeight{0}; /** Wymiary macierzy */
      double scalarVal{0}; /** Wartość skalara */
      M** mtrx{nullptr}; /** Tablica wskaźników typu M reprezentująca komórki macierzy */
  };
}

#endif
