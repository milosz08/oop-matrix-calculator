#ifndef PK_MATRIX_CALCULATOR_MATRIXABSTRACT_HPP
#define PK_MATRIX_CALCULATOR_MATRIXABSTRACT_HPP
#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <vector>
#include <windows.h>

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
    MatrixAbstract();
    MatrixAbstract(unsigned short int&, unsigned short int&); /** Sygnatura konstr. dla macierzy prostokątnych */
    MatrixAbstract(unsigned short int&); /** Sygnatura konstr. dla macierzy kwadratowych */
    MatrixAbstract(const MatrixAbstract<M>&); /** Sygnatura konstr. kopiującego */

    virtual void printMtrx(const bool, const bool, const bool) const; /** Metoda wirtualna - drukowanie macierzy */
    void allocateMemory(); /** Alokacja pamięci */
    double scalarValuePush(HANDLE&); /** Wprowadzanie wartości skalara */

    virtual void mtrxTypeAndSizeInfo() = 0; /** Metoda czysto wirtualna - wypisywanie wiadomosci */
    virtual void insertMtrx(HANDLE&) = 0; /** Metoda czysto wirtualna - wprowadzanie macierzy */

    static void genInfoBlock(std::string header, std::vector<std::string> mess);
    static void sequentialMess(unsigned int, std::string);
    static void errorMess(std::string, HANDLE&);

    virtual ~MatrixAbstract(); /** Wirtualny destruktor wywołujący destruktory z klas pochodnych */

  private: /** Metody prywatne; dostępne tylko na użytek metod klasy abstrakcyjnej */
    unsigned int findMaxLength(unsigned int&) const;
    unsigned int lengthOfElm(M&) const;

  public: /** Gettery */
    unsigned short int get_Cols() const;
    unsigned short int get_Rows() const;
    M** get_Mtrx() const;

  protected:
    unsigned short int mtrxWidth{0}, mtrxHeight{0}; /** Wymiary macierzy */
    double scalarVal{0}; /** Wartość skalara */
    M** mtrx{nullptr}; /** Tablica wskaźników typu M reprezentująca komórki macierzy */
  };
}

#endif