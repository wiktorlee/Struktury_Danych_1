#include <iostream>
#include "ListaJednokierunkowa.hpp"
#include <cstdlib>

using namespace std;

/**
 * @brief Konstruktor domyślny listy jednokierunkowej.
 * Tworzy pustą listę – wskaźniki head i tail ustawione na nullptr.
 */
ListaJednokierunkowa::ListaJednokierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {
    cout << "Utworzono pusta liste " << endl; // komunikat
}

/**
 * @brief Konstruktor tworzący listę z przekazanej tablicy.
 * @param dane Tablica z danymi.
 * @param rozmiar Liczba elementów do dodania.
 */
ListaJednokierunkowa::ListaJednokierunkowa(int* dane, int rozmiar) : head(nullptr), tail(nullptr), rozmiar(0) {
    if (rozmiar == 0) return; // jeśli brak danych, zakończ
    for (int i = 0; i < rozmiar; i++) {
        dodajKoniec(dane[i]); // dodaj każdy element na koniec
    }
    cout << "Lista wypelniona danymi." << endl;
}

/**
 * @brief Dodaje element na koniec listy.
 * @param wartosc Wartość do dodania.
 */
void ListaJednokierunkowa::dodajKoniec(int wartosc) {
    Wezel* newWezel = new Wezel(wartosc); // tworzymy nowy węzeł
    if (head == nullptr) {                // jeśli lista jest pusta
        head = tail = newWezel;           // ustaw nowy węzeł jako pierwszy i ostatni
    } else {
        tail->next = newWezel;            // poprzedni ostatni węzeł wskazuje na nowy
        tail = newWezel;                  // nowy węzeł staje się ostatnim
    }
    rozmiar++; // zwiększamy licznik elementów
}

/**
 * @brief Dodaje element na początek listy.
 * @param wartosc Wartość do dodania.
 */
void ListaJednokierunkowa::dodajPoczatek(int wartosc) {
    Wezel* newWezel = new Wezel(wartosc);
    newWezel->next = head;   // nowy węzeł wskazuje na obecny początek
    head = newWezel;         // ustawiamy nowy węzeł jako początek
    if (tail == nullptr) {   // jeśli lista była pusta
        tail = newWezel;
    }
    rozmiar++;
}

/**
 * @brief Dodaje element w losowej pozycji listy.
 * @param wartosc Wartość do dodania.
 */
void ListaJednokierunkowa::dodajRandom(int wartosc) {
    int indeks = rand() % (rozmiar + 1); // losuj indeks
    if (indeks == 0) {
        dodajPoczatek(wartosc);         // jeśli 0, dodaj na początek
        return;
    }
    if (indeks == rozmiar) {
        dodajKoniec(wartosc);           // jeśli na końcu, dodaj na koniec
        return;
    }
    Wezel* newWezel = new Wezel(wartosc);
    Wezel* aktualny = head;
    for (int i = 1; i < indeks; i++) {   // przechodzimy do pozycji
        aktualny = aktualny->next;
    }
    newWezel->next = aktualny->next;       // wstawiamy nowy węzeł
    aktualny->next = newWezel;
    rozmiar++;
}

/**
 * @brief Usuwa pierwszy element listy.
 */
void ListaJednokierunkowa::usunPoczatek() {
    if (head == nullptr) {
        cout << "Lista jest pusta!" << endl; // komunikat
        return;
    }
    Wezel* temp = head;        // zapamiętujemy pierwszy
    head = head->next;         // przesuwamy head
    delete temp;               // usuwamy poprzedni head
    if (head == nullptr) {     // jeśli lista teraz pusta
        tail = nullptr;
    }
    rozmiar--; // zmniejszamy licznik
}

/**
 * @brief Usuwa ostatni element listy.
 */
void ListaJednokierunkowa::usunKoniec() {
    if (head == nullptr) {
        cout << "Lista jest pusta!" << endl;
        return;
    }
    if (head == tail) {      // gdy tylko jeden element
        delete head;
        head = tail = nullptr;
    } else {
        Wezel* aktualny = head;
        while (aktualny->next != tail) { // szukamy elementu przed ostatnim
            aktualny = aktualny->next;
        }
        delete tail;         // usuwamy ostatni
        tail = aktualny;     // ustawiamy nowy ostatni
        tail->next = nullptr;
    }
    rozmiar--;
}

/**
 * @brief Usuwa element z losowej pozycji.
 */
void ListaJednokierunkowa::usunRandom() {
    if (rozmiar == 0) {
        cout << "Lista jest pusta!" << endl;
        return;
    }
    int indeks = rand() % rozmiar; // losujemy indeks
    if (indeks == 0) {
        usunPoczatek();         // jeśli pierwszy, usuń pierwszy
        return;
    }
    if (indeks == rozmiar - 1) {
        usunKoniec();           // jeśli ostatni, usuń ostatni
        return;
    }
    Wezel* aktualny = head;
    for (int i = 1; i < indeks; i++) {  // przechodzimy do elementu przed usuwanym
        aktualny = aktualny->next;
    }
    Wezel* doUsuniecia = aktualny->next;
    aktualny->next = doUsuniecia->next;  // pomijamy usuwany element
    delete doUsuniecia;                  // usuwamy element
    rozmiar--;
}

/**
 * @brief Destruktor listy – usuwa wszystkie elementy.
 */
ListaJednokierunkowa::~ListaJednokierunkowa() {
    while (head != nullptr) {            // dopóki lista nie pusta
        Wezel* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief Wyświetla zawartość listy.
 */
void ListaJednokierunkowa::wyswietl() const {
    if (head == nullptr) {
        cout << "Lista jest pusta!" << endl;
        return;
    }
    Wezel* aktualny = head;
    cout << "Lista: ";
    while (aktualny != nullptr) {         // wypisujemy każdy element
        cout << aktualny->dane << " ";
        aktualny = aktualny->next;
    }
    cout << endl;
}

/**
 * @brief Zwraca liczbę elementów w liście.
 * @return Rozmiar listy.
 */
int ListaJednokierunkowa::pobierzRozmiar() const {
    return rozmiar;
}

/**
 * @brief Sprawdza, czy lista zawiera daną wartość.
 * @param wartosc Wartość do sprawdzenia.
 * @return true, jeśli wartość jest w liście, false w przeciwnym razie.
 */
bool ListaJednokierunkowa::zawiera(int wartosc) const {
    Wezel* aktualny = head;
    while (aktualny != nullptr) {
        if (aktualny->dane == wartosc) { // znajdź wartość
            return true;
        }
        aktualny = aktualny->next;
    }
    return false;
}
