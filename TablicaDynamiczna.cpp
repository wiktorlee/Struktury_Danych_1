#include "TablicaDynamiczna.hpp"
#include <iostream>
using namespace std;

TablicaDynamiczna::TablicaDynamiczna(int* dane, int rozmiar) {
    this->rozmiar = rozmiar;
    this->pojemnosc = rozmiar;
    tablica = new int[pojemnosc];
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = dane[i];
    }
    cout<<"Tablica wypelniona danymi"<<endl;
}

TablicaDynamiczna::TablicaDynamiczna(int poczatkowyRozmiar) {
    pojemnosc = poczatkowyRozmiar;
    rozmiar = 0;
    tablica = new int[pojemnosc];
}

TablicaDynamiczna::~TablicaDynamiczna() {
    delete[] tablica;
}

void TablicaDynamiczna::powieksz() {
    pojemnosc *= 2;
    int* nowaTablica = new int[pojemnosc];
    for (int i = 0; i < rozmiar; i++) {
        nowaTablica[i] = tablica[i];
    }
    delete[] tablica;
    tablica = nowaTablica;
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
    }
}

void TablicaDynamiczna::dodajNaKoniec(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    tablica[rozmiar] = wartosc;
    rozmiar++;
}

void TablicaDynamiczna::dodajNaPoczatek(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    for (int i = rozmiar; i > 0; i--) {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = wartosc;
    rozmiar++;
}

void TablicaDynamiczna::dodawanieRandom(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    srand(time(nullptr));
    int indeks = rand() % (rozmiar + 1);

    for (int i = rozmiar; i > indeks; i--) {
        tablica[i] = tablica[i - 1];
    }
    tablica[indeks] = wartosc;
    rozmiar++;
    cout << "Dodano element " << wartosc << " na pozycji " << indeks << endl;
}




void TablicaDynamiczna::usunZKonca() {
    if (rozmiar > 0) {
        rozmiar--;
        zmniejsz();
    }
}

void TablicaDynamiczna::usunZPoczatku() {
    if (rozmiar > 0) {
        for (int i = 0; i < rozmiar - 1; i++) {
            tablica[i] = tablica[i + 1];
        }
        rozmiar--;
        zmniejsz();
    }
}

void TablicaDynamiczna::usuwanieRandom() {
    if (rozmiar == 0) {
        cout << "Tablica pusta!" << endl;
        return;
    }
    int indeks = rand() % rozmiar;

    for (int i = indeks; i < rozmiar - 1; i++) {
        tablica[i] = tablica[i + 1];
    }
    rozmiar--;
    zmniejsz();
    cout << "Usunieto element z pozycji " << indeks << endl;
}


void TablicaDynamiczna::wyswietl() {
    if (rozmiar == 0) {
        cout << "Tablica pusta!!." << endl;
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
