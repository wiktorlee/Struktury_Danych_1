#include <iostream>
#include "TablicaDynamiczna.hpp"
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
    int* nowaTablica = new int[pojemnosc];          //metoda zwiekszajaca rozmiar struktury, alokuje nowa wieksza tablice i kopiuje do niej dane
    for (int i = 0; i < rozmiar; i++) {
        nowaTablica[i] = tablica[i];
    }
    delete[] tablica;
    tablica = nowaTablica;
}

void TablicaDynamiczna::zmniejsz() {
    if (rozmiar <= pojemnosc / 3 && pojemnosc > 1) {
        pojemnosc /= 2;                                 //metoda zmniejszajaca rozmiar struktury, jesli zajeta jest mniej niz 1/3 zasobow
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
        powieksz();                                 //dodawanie na koniec ze sprawdzeniem, czy jest wymagane powiekszenie
    }
    tablica[rozmiar] = wartosc;
    rozmiar++;
    //cout<<"Wykonano operacje"<<endl;
}

void TablicaDynamiczna::dodajNaPoczatek(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();                                 //sprawdzenie czy jest wymagane powiekszenie, przesuniecie elementow i dodanie na poczatek
    }
    for (int i = rozmiar; i > 0; i--) {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = wartosc;
    rozmiar++;
    //cout<<"Wykonano operacje"<<endl;
}

void TablicaDynamiczna::dodawanieRandom(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    srand(time(nullptr));
    int indeks = rand() % (rozmiar + 1);        //sprawdzenie czy jest wymagane powiekszenie, losowanie ziarna, przesuniecie elementow i wstawienie nowego

    for (int i = rozmiar; i > indeks; i--) {
        tablica[i] = tablica[i - 1];
    }
    tablica[indeks] = wartosc;
    rozmiar++;
    //cout<<"Wykonano operacje"<<endl;
}




void TablicaDynamiczna::usunZKonca() {
    if (rozmiar > 0) {
        rozmiar--;
        zmniejsz();                             //usuniecie elementu poprzez usuniecie wskaznika i sprawdzenie czy przestrzen nie jest marnowana
    }
    //cout<<"Wykonano operacje"<<endl;
}

void TablicaDynamiczna::usunZPoczatku() {
    if (rozmiar > 0) {
        for (int i = 0; i < rozmiar - 1; i++) {
            tablica[i] = tablica[i + 1];
        }                                               //przesuniecie elementow, usuniecie poprzez wskaznik i sprawdzenie czy przestrzen nie jest marnowana
        rozmiar--;
        zmniejsz();
    }
    //cout<<"Wykonano operacje"<<endl;
}

void TablicaDynamiczna::usuwanieRandom() {
    if (rozmiar == 0) {
        cout << "Tablica pusta!" << endl;
        return;                                         //generowanie losowego ziarna, przesuniecie elementow i usuniecie przez wskaznik, sprawdzenie marnowania zasobow
    }
    int indeks = rand() % rozmiar;

    for (int i = indeks; i < rozmiar - 1; i++) {
        tablica[i] = tablica[i + 1];
    }
    rozmiar--;
    zmniejsz();
    //cout<<"Wykonano operacje"<<endl;
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

bool TablicaDynamiczna::zawiera(int wartosc) {
    for (int i = 0; i < rozmiar; i++) {                     //iteracja po wszystkich elementach wcelu sprawdzenia obecnosci elementu w strukturze
        if (tablica[i] == wartosc) {
            return true;
        }
    }
    return false;
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
