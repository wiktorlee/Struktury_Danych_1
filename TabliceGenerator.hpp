#ifndef TABLICEGENERATOR_HPP
#define TABLICEGENERATOR_HPP

/**
 * @brief Klasa TabliceGenerator tworzy i miesza tablice.
 */
class TabliceGenerator {
public:
    /**
     * @brief Generuje tablicę losowych liczb.
     * @param rozmiar Wielkość tablicy.
     * @return Wskaźnik do wygenerowanej tablicy.
     */
    static int* generujLosowaTablice(int rozmiar);

    /**
     * @brief Miesza elementy w tablicy metodą Fishera-Yatesa.
     * @param tab Tablica do przetasowania.
     * @param rozmiar Wielkość tablicy.
     */
    static void fisherYatesShuffle(int* tab, int rozmiar);
};

#endif
