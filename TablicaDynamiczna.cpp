#include <iostream>
#include "TablicaDynamiczna.hpp"

using namespace std;

/**
 * @brief Tworzy tablicę dynamiczną na podstawie przekazanej tablicy.
 * @param dane Tablica z danymi.
 * @param rozmiar Liczba elementów do skopiowania.
 */
TablicaDynamiczna::TablicaDynamiczna(int* dane, int rozmiar) {
    this->rozmiar = rozmiar;            // liczba elementów
    this->pojemnosc = rozmiar;          // początkowa pojemność
    tablica = new int[pojemnosc];       // alokujemy pamięć
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = dane[i];         // kopiujemy dane
    }
    cout << "Tablica wypelniona danymi" << endl;
}

/**
 * @brief Tworzy pustą tablicę o zadanej początkowej pojemności.
 * @param poczatkowyRozmiar Początkowa pojemność tablicy.
 */
TablicaDynamiczna::TablicaDynamiczna(int poczatkowyRozmiar) {
    pojemnosc = poczatkowyRozmiar;      // ustawiamy początkową pojemność
    rozmiar = 0;                       // początkowo brak elementów
    tablica = new int[pojemnosc];      // alokacja pamięci
}

/**
 * @brief Destruktor zwalniający pamięć tablicy.
 */
TablicaDynamiczna::~TablicaDynamiczna() {
    delete[] tablica; // zwolnienie pamięci
}

/**
 * @brief Powiększa tablicę przez podwojenie jej pojemności.
 */
void TablicaDynamiczna::powieksz() {
    pojemnosc *= 2;                      // podwajamy pojemność
    int* nowaTablica = new int[pojemnosc];
    for (int i = 0; i < rozmiar; i++) {   // kopiujemy dane
        nowaTablica[i] = tablica[i];
    }
    delete[] tablica;                    // usuwamy starą tablicę
    tablica = nowaTablica;
}

/**
 * @brief Zmniejsza tablicę, gdy jest zbyt dużo wolnego miejsca.
 */
void TablicaDynamiczna::zmniejsz() {
    if (rozmiar <= pojemnosc / 3 && pojemnosc > 1) { // warunek zmniejszenia
        pojemnosc /= 2;                // zmniejszamy pojemność
        int* nowaTablica = new int[pojemnosc];
        for (int i = 0; i < rozmiar; i++) {
            nowaTablica[i] = tablica[i]; // kopiujemy dane
        }
        delete[] tablica;              // zwalniamy starą tablicę
        tablica = nowaTablica;
    }
}

/**
 * @brief Dodaje element na koniec tablicy.
 * @param wartosc Wartość do dodania.
 */
void TablicaDynamiczna::dodajNaKoniec(int wartosc) {
    if (rozmiar == pojemnosc) { // gdy tablica pełna
        powieksz();           // powiększamy tablicę
    }
    tablica[rozmiar] = wartosc; // wstawiamy nowy element
    rozmiar++;                  // zwiększamy rozmiar
}

/**
 * @brief Dodaje element na początek tablicy.
 * @param wartosc Wartość do dodania.
 */
void TablicaDynamiczna::dodajNaPoczatek(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    for (int i = rozmiar; i > 0; i--) { // przesuwamy elementy w prawo
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = wartosc;     // wstawiamy na początku
    rozmiar++;
}

/**
 * @brief Dodaje element w losowej pozycji.
 * @param wartosc Wartość do dodania.
 */
void TablicaDynamiczna::dodawanieRandom(int wartosc) {
    if (rozmiar == pojemnosc) {
        powieksz();
    }
    srand(time(nullptr));                   // ustawiamy ziarno dla losowania
    int indeks = rand() % (rozmiar + 1);      // losujemy indeks
    for (int i = rozmiar; i > indeks; i--) {  // przesuwamy elementy
        tablica[i] = tablica[i - 1];
    }
    tablica[indeks] = wartosc;  // wstawiamy element na losowej pozycji
    rozmiar++;
}

/**
 * @brief Usuwa element z końca tablicy.
 */
void TablicaDynamiczna::usunZKonca() {
    if (rozmiar > 0) {
        rozmiar--;         // usuwamy ostatni element (logicznie)
        zmniejsz();        // ewentualnie zmniejszamy tablicę
    }
}

/**
 * @brief Usuwa element z początku tablicy.
 */
void TablicaDynamiczna::usunZPoczatku() {
    if (rozmiar > 0) {
        for (int i = 0; i < rozmiar - 1; i++) { // przesuwamy elementy na lewo
            tablica[i] = tablica[i + 1];
        }
        rozmiar--;         // zmniejszamy rozmiar
        zmniejsz();        // ewentualnie zmniejszamy tablicę
    }
}

/**
 * @brief Usuwa element z losowej pozycji.
 */
void TablicaDynamiczna::usuwanieRandom() {
    if (rozmiar == 0) {
        cout << "Tablica pusta!" << endl;
        return;
    }
    int indeks = rand() % rozmiar;        // losujemy indeks
    for (int i = indeks; i < rozmiar - 1; i++) { // przesuwamy elementy w lewo
        tablica[i] = tablica[i + 1];
    }
    rozmiar--;       // zmniejszamy licznik elementów
    zmniejsz();      // ewentualnie zmniejszamy tablicę
}

/**
 * @brief Wyświetla zawartość tablicy.
 */
void TablicaDynamiczna::wyswietl() {
    if (rozmiar == 0) {
        cout << "Tablica pusta!!." << endl;
        return;
    }
    cout << "Zawartosc tablicy (" << rozmiar << "/" << pojemnosc << "): ["; // nagłówek
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i];
        if (i < rozmiar - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief Sprawdza, czy tablica zawiera daną wartość.
 * @param wartosc Wartość do sprawdzenia.
 * @return true, jeśli wartość jest obecna; false w przeciwnym wypadku.
 */
bool TablicaDynamiczna::zawiera(int wartosc) {
    for (int i = 0; i < rozmiar; i++) {
        if (tablica[i] == wartosc) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Zwraca wskaźnik na tablicę.
 * @return Wskaźnik na dynamicznie alokowaną tablicę.
 */
int* TablicaDynamiczna::pobierzTablice() {
    return tablica;
}

/**
 * @brief Zwraca pojemność tablicy.
 * @return Aktualna pojemność tablicy.
 */
int TablicaDynamiczna::pobierzPojemnosc() {
    return pojemnosc;
}

/**
 * @brief Zwraca liczbę elementów w tablicy.
 * @return Rozmiar tablicy.
 */
int TablicaDynamiczna::pobierzRozmiar() {
    return rozmiar;
}
