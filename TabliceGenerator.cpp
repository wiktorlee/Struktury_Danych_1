#include <iostream>
#include "TabliceGenerator.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

/**
 * @brief Generuje tablicę losowych liczb.
 * Tablica zawiera liczby od 0 do (rozmiar-1) i jest tasowana.
 * @param rozmiar Rozmiar tworzonej tablicy.
 * @return Wskaźnik do wygenerowanej tablicy.
 */
int* TabliceGenerator::generujLosowaTablice(int rozmiar) {
    int* tab = new int[rozmiar]; // alokacja tablicy
    for (int i = 0; i < rozmiar; i++)
        tab[i] = i;              // wypełnienie tablicy wartościami
    fisherYatesShuffle(tab, rozmiar); // tasujemy tablicę
    return tab;
}

/**
 * @brief Tasuje elementy tablicy metodą Fishera-Yatesa.
 * @param tab Tablica do przetasowania.
 * @param rozmiar Rozmiar tablicy.
 */
void TabliceGenerator::fisherYatesShuffle(int* tab, int rozmiar) {
    srand(time(nullptr)); // ustawienie ziarna losowania
    for (int i = rozmiar - 1; i > 0; --i) {
        int j = rand() % (i + 1); // losujemy indeks
        swap(tab[i], tab[j]);     // zamieniamy elementy
    }
}
