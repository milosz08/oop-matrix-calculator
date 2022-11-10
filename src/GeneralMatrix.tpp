#include "GeneralMatrix.hpp"

using namespace matrixAbstractPackage;


/*!
 * @fn GeneralMatrix(unsigned int& w, unsigned int& h)
 *
 * @brief Konstruktor dwuargumentowy. Wywoływany dla macierzy prostokątnych. Wywołuje konstruktor
 *        z klasy abstrakcyjnej oraz wyświetla informacje na temat wprowadzanej macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param w - szerokość macierzy (ilość kolumn).
 * @param h - wysokość macierzy (ilośc wierszy).
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned short int &w, unsigned short int &h) : MatrixAbstract<M>{w, h} {}


/*!
 * @fn GeneralMatrix(unsigned int & s)
 *
 * @brief Konstruktor jednoargumentowy. Wywoływany dla macierzy kwadratowych. Wywołuje konstruktor
 *        z klasy abstrakcyjnej oraz wyświetla informacje na temat wprowadzanej macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param s - stopień macierzy (ilośc kolumn oraz ilość wierszy).
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(unsigned short int &s) : MatrixAbstract<M>{s, s} {}

/*!
 * @fn GeneralMatrix(const GeneralMatrix& mtrxCopy)
 *
 * @brief Konstruktor kopiujący. Wywołuje konstruktor z klasy abstrakcyjnej,
 *        który kopiuje zawartość objektu.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param mtrxCopy - kopia obiektu przekazywana przez referencję
 */
template<class M>
GeneralMatrix<M>::GeneralMatrix(const GeneralMatrix<M> &mtrxCopy) : MatrixAbstract<M>{mtrxCopy} {}


/*!
 * @fn ~GeneralMatrix()
 * @brief Destruktor pełniący rolę odśmiecacza pamięci. Usuwa dynamiczną tablicę indeksów kolumn (potrzebna do
 *        obliczenia wyznacznika rekurencyjną metodą Laplace'a).
 */
template<class M>
GeneralMatrix<M>::~GeneralMatrix() {
    delete[] this->colsCount;
}


/*!
 * @fn mtrxTypeAndSizeInfo()
 *
 * @brief Metoda informująca użytkownika jakiej wielkości oraz ilu elementowa macierz została zapisana.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 */
template<class M>
void GeneralMatrix<M>::mtrxTypeAndSizeInfo() {
    std::cout << "\nZapisałem następujace informacje na temat macierzy ";
    if (this->mtrxWidth == this->mtrxHeight) {
        std::cout << "kwadratowej";
    } else {
        std::cout << "prostokątnej";
    }
    std::cout << "\no wymiarach: " << this->mtrxWidth << " x " << this->mtrxHeight;
    std::cout << ", posiadającej liczbę " << this->mtrxWidth * this->mtrxHeight << " komórek.\n";
}


/*!
 * @fn insertMtrx()
 *
 * @brief Metoda umożliwiająca wprowadzenie przez użytkownika elementów macierzy do dwuwymiarowej
 *        tablicy dynamicznej stworzonej w klasie abstrakcyjnej.<br>
 *
 *        Metoda posiada walidację strumienia wejścia pod kątem wprowadzanych znaków do macierzy diagonalnej.
 *        Jeśli znak nie jest zgody z typem zmiennej we wzorcu "M" program wyrzuca błąd i daje możliwość
 *        ponownego wpisania znaków macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double)
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 */
template<class M>
void GeneralMatrix<M>::insertMtrx(HANDLE &hOut) {
    bool error{false}, repeatMess{false};

    do {
        std::system("cls");

        mtrxTypeAndSizeInfo();
        std::cout << "\nAby przejść dalej, podaj kolejne elementy macierzy.\n";

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        MatrixAbstract<double>::genInfoBlock("UWAGA!", {
                "Jeśli podasz więcej elementów, zostaną one przeze mnie zignorowane."
        });

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        GeneralMatrix::genInfoBlock("INFO", {
                "Macierz możesz wpisać zarówno w formie jednoliniowej poziomej lub pionowej tablicy",
                "lub w wygodnej formie wizualnej macierzy (kolejne elementy należy wypisywać po spacji",
                "a w przechodzeniu do nowego wiersza należy uzyć klawisza \"enter\")."
        });

        error = false;

        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        std::cout << "\nWpisz " << (!repeatMess ? "" : "ponownie ") << "swoją macierz:\n";

        for (unsigned short int i = 0; i < this->mtrxHeight; i++) {
            for (unsigned short int j = 0; j < this->mtrxWidth; j++) {
                std::cin >> this->mtrx[i][j];
            }
        }

        if (std::cin.fail()) { /** @skip Jeśli użytkownik wpisze wartości inne niż zdefiniowane we wzorcu */

            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            MatrixAbstract<double>::genInfoBlock("ERROR!", {
                    "W wprowadzanej przez Ciebie macierzy znalazłem niedozwolone wartości!",
                    "Aby kontyuować wprowadź ponownie swoją macierz."
            });

            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            MatrixAbstract<double>::sequentialMess(5, "Ponawianie za");

            error = repeatMess = true;

            std::cin.clear(); /** @skip Czyszczenie strumienia wejścia */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    } while (error);
    std::system("cls");
}


/*!
 * @fn transposeMtrx()
 *
 * @brief Metoda wykonująca operację tranponowania macierzy.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @param mtrx - macierz, która zostanie podjęta transponacji.
 *
 * @return Metoda zwraca macierz wynikowa (obiekt) po transponacji.
 */
template<class M>
GeneralMatrix<M> GeneralMatrix<M>::transposeMtrx() {

    /** Kopiowanie macierzy */
    GeneralMatrix<M> mtrxTrans = GeneralMatrix<M>{*this};

    for (unsigned short int i = 0; i < this->mtrxHeight; i++) {
        for (unsigned short int j = 0; j < this->mtrxWidth; j++) {
            mtrxTrans.mtrx[i][j] = this->mtrx[j][i];
        }
    }
    return mtrxTrans;
}


/*!
 * @fn coupledGenMtrx()
 *
 * @brief Metoda tworząca macierz sprzężoną na podstawie macierzy pierwotnej.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 * @param mtrx - macierz, której każda wartość otrzyma odpowiadającej jej wartość sprzężoną.
 *
 * @return - Metoda zwraca macierz sprzężona (obiekt).
 */
template<class M>
GeneralMatrix<M> GeneralMatrix<M>::coupledMtrx() {

    /** Kopiowanie macierzy */
    GeneralMatrix<M> mtrxCoup = GeneralMatrix<M>{*this};

    for (unsigned short int i = 0; i < this->mtrxHeight; i++) {
        for (unsigned short int j = 0; j < this->mtrxWidth; j++) {
            mtrxCoup.mtrx[i][j] = this->mtrx[i][j] * -1;
        }
    }
    return mtrxCoup;
}


/*!
 * @fn determinantMtrx(HANDLE& hOut)
 *
 * @brief Metoda obliczająca wyznacznik macierzy (tylko kwadratowe). Metoda sama w sobie nie oblicza wyznacznika,
 *        wywołuje zaprzyjaźniona funkcję rekurencyjną, która po wykonaniu operacji zwraca gotowy wyznacznik
 *        wartości liczb według przyjętego parametru we wzorcu M.<br>
 *
 *        Metoda jest zabezpieczona pod kątem wymiarów macierzy. Jeśli wprowadzana macierz nie jest kwadratowa,
 *        nastąpi wyrzucenie wyjątka (przejęty w funkcji głównej).
 *
 * @throw logic_error -> Brak możliwości obliczenia wyznacznika z macierzy która nie jest macierzą kwadratową.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @param hOut - uchwyt na wyjście z konsoli (zadeklarowany w funkcji startPrg i przekazywany przez referencję).
 *
 * @return Metoda zwraca wyznacznik macierzy (typ wartości na podstawie parametru we wzorcu M).
 */
template<class M>
M GeneralMatrix<M>::determinantMtrx(HANDLE &hOut) {
    M mtrxDet{0}; /** Końcowy wyznacznik (int/double) */

    if (this->mtrxWidth != this->mtrxHeight) {
        throw std::logic_error("Program nie wspiera obliczania wyznacznika z macierzy prostokątnej.");
    } else {
        this->colsCount = new unsigned short int[this->mtrxWidth];
        for (unsigned short int i = 0; i < this->mtrxWidth; i++) {
            this->colsCount[i] = i;
        }
        mtrxDet = detRecursion<M>(this->mtrxWidth, 0, this->colsCount, this->mtrx);
    }
    return mtrxDet;
}


/*!
 * @fn inverseMtrx()
 *
 * @brief Metoda wyznaczająca macierz odwrotną na podstawie rozwiązania wyznaczania macierzy odwrotnej przy pomocy
 *        metody Gaussa - Jordana. Metoda polega na wyznaczeniu macierzy jednostkowej o takim samym stopniu jak
 *        macierz pierwotna, a następnie przeliczenie wartości, aby zamienić obie macierze miejscami (jeśli po prawej
 *        była dołączona macierz jednostkowa, to w obliczeniu macierzy odwrotnej, macierz jednostkowa przechodzi
 *        na stronę lewą a po prawej jest odwrócona macierz pierwotna - macierz wynikowa).<br>
 *
 *        Metoda jest zabezpieczona pod kątem wymiarów macierzy. Jeśli wprowadzana macierz nie jest kwadratowa,
 *        nastąpi wyrzucenie wyjątka (przejęty w funkcji głównej).
 *
 * @throw logic_error -> Brak możliwości obliczenia wyznacznika z macierzy która nie jest macierzą kwadratową.
 *
 * @tparam M - wzór reprezentujący typ wartości wprowadzanych do macierzy (int/double).
 *
 * @return Metoda zwraca macierz odwrotną (obiekt).
 */
template<class M>
GeneralMatrix<double> GeneralMatrix<M>::inverseMtrx(HANDLE &hOut) {
    unsigned short int doubleWidth = this->mtrxWidth * 2;
    double tempMath{0};

    /** @skip Macierz zawierająca elementy macierzy pierwotnej i jednostkowej */
    GeneralMatrix<M> mtrxWithIdn = GeneralMatrix<M>{doubleWidth, this->mtrxHeight};

    /** @skip Macierz odwrotna do macierzy pierwotnej - na stałe wartość double */
    GeneralMatrix<double> mtrxInvrs = GeneralMatrix<double>{this->mtrxWidth, this->mtrxHeight};

    if (this->mtrxWidth != this->mtrxHeight) { /** @skip Jeśli macierz nie jest kwadratowa */
        throw std::logic_error("Program nie wspiera obliczania macierzy odwrotnej z macierzy prostokątnej.");
    } else {

        /** @skip Dodanie do istniejącej macierzy (A) macierzy jednostkowej (I) */
        for (unsigned short int i = 0; i < this->mtrxHeight; i++) {
            for (unsigned short int j = 0; j < doubleWidth; j++) {
                if (j == i + this->mtrxWidth) { /** @skip Diagonalna (jednostkowa) */
                    mtrxWithIdn.mtrx[i][j] = 1;
                } else if (j >= this->mtrxWidth) { /** @skip Pozostałe komórki (jednostkowa) */
                    mtrxWithIdn.mtrx[i][j] = 0;
                } else { /** @skip Przepisanie elementów macierzy pierwotnej */
                    mtrxWithIdn.mtrx[i][j] = this->mtrx[i][j];
                }
            }
        }

        for (unsigned short int i = 0; i < this->mtrxHeight; i++) {
            for (unsigned short int j = 0; j < this->mtrxWidth; j++) {
                if (i != j) { /** @skip Pomiń elementy na diagonalnej */
                    /** @skip Podzielenie kolejnych elementów kolumn przez kolejne wartości diagonalnej i zapisanie w tempMath */
                    tempMath = mtrxWithIdn.mtrx[j][i] / mtrxWithIdn.mtrx[i][i];
                    for (unsigned short int k = 0; k < doubleWidth; k++) {
                        /** @skip Przejście przez kolejne elementy wierszów macierzy wspólnej (podwójna szerokość) i odjęcie od
                         * aktualnej  wartości elementu wiersza (pętla wewnętrzna) wartości w zmiennej tempMath przemnożonej
                         * przez kolejne elementy wiersza (pętla zewnętrzna) */
                        mtrxWithIdn.mtrx[j][k] -= mtrxWithIdn.mtrx[i][k] * tempMath;
                    }
                }
            }
        }

        for (unsigned short int i = 0; i < this->mtrxWidth; i++) {
            /** @skip Przypisanie do zmiennej tempMath wartości leżących na diagonalnej */
            tempMath = mtrxWithIdn.mtrx[i][i];
            for (unsigned short int j = 0; j < doubleWidth; j++) {
                /** @skip Zaktualizowanie kolejnych elementów macierzy podwójnej poprzez podzielenie aktualnej wartości przez
                 * wcześniej przypisaną zmienną tempMath */
                mtrxWithIdn.mtrx[i][j] /= tempMath;
            }
        }

        /** @skip Przypisanie elementów (oprócz elm macierzy jednostkowej) do macierzy z obiektu macierzy odwrotnej */
        for (unsigned short int i = 0; i < this->mtrxWidth; i++) {
            for (unsigned short int j = this->mtrxWidth; j < doubleWidth; j++) {
                mtrxInvrs.get_Mtrx()[i][j - this->mtrxWidth] = mtrxWithIdn.mtrx[i][j];
            }
        }
    }
    return mtrxInvrs;
}