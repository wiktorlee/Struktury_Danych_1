#include "TabliceGenerator.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


int* TabliceGenerator::generujLosowaTablice(int rozmiar) {
    int* tab = new int[rozmiar];


    for(int i = 0; i < rozmiar; i++)
        tab[i] = i;


    fisherYatesShuffle(tab, rozmiar);

    return tab;
}


void TabliceGenerator::fisherYatesShuffle(int* tab, int rozmiar) {

    srand(time(nullptr));

    for (int i = rozmiar - 1; i > 0; --i) {

        int j = rand() % (i + 1);

        swap(tab[i], tab[j]);
    }
}
