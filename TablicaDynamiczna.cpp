#include "TablicaDynamiczna.hpp"
#include <iostream>
#include "TabliceGenerator.hpp"
using namespace std;

TablicaDynamiczna::TablicaDynamiczna(int poczatkowyRozmiar) {
    pojemnosc = poczatkowyRozmiar;
    rozmiar = poczatkowyRozmiar;
    tablica = TabliceGenerator::generujLosowaTablice(pojemnosc);
    cout << "Utworzono tablice dynamiczna o pojemnosci: " << pojemnosc << endl;
}


TablicaDynamiczna::~TablicaDynamiczna() {
    delete[] tablica;
    cout << "Zwolniono pamiec tablicy." << endl;
}


void TablicaDynamiczna::powieksz() {
    pojemnosc *= 2;
    int* nowaTablica = new int[pojemnosc];

    for (int i = 0; i < rozmiar; i++) {
        nowaTablica[i] = tablica[i];
    }

    delete[] tablica;
    tablica = nowaTablica;
    cout << "Tablica powiekszona do pojemnosci: " << pojemnosc << endl;
}


void TablicaDynamiczna::zmniejsz() {
    if (rozmiar <= pojemnosc / 3 && pojemnosc > 1) {
        pojemnosc /= 2;
        int* nowaTablica = new int[pojemnosc];

        for (int i = 0; i < rozmiar; i++) {
            nowaTablica[i] = tablica[i];
        }

        delete[] tablica;
        tablica = nowaTablica;
        cout << "Tablica zmniejszona do pojemnosci: " << pojemnosc << endl;
    }
}


void TablicaDynamiczna::dodajNaKoniec(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    tablica[rozmiar] = wartosc;
    rozmiar++;
    cout << "Dodano element: " << wartosc << ". Aktualny rozmiar: " << rozmiar << endl;
}


void TablicaDynamiczna::usunZKonca() {
    if (rozmiar > 0) {
        rozmiar--;
        zmniejsz();
        cout << "Usunieto element z konca. Nowy rozmiar: " << rozmiar << endl;
    } else {
        cout << "Tablica jest pusta, nie mozna usunac elementu." << endl;
    }
}


void TablicaDynamiczna::wyswietl() {
    if (rozmiar == 0) {
        cout << "Tablica jest pusta." << endl;
        return;
    }

    cout << "Zawartosc tablicy (" << rozmiar << "/" << pojemnosc << "): [";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i];
        if (i < rozmiar - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



int* TablicaDynamiczna::pobierzTablice() {
    return tablica;
}


int TablicaDynamiczna::pobierzPojemnosc() {
    return pojemnosc;
}


int TablicaDynamiczna::pobierzRozmiar() {
    return rozmiar;
}
