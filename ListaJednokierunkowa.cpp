#include "ListaJednokierunkowa.hpp"

using namespace std;

ListaJednokierunkowa::ListaJednokierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {
    cout << "Utworzono pusta liste " << endl;
}

ListaJednokierunkowa::ListaJednokierunkowa(int* dane, int rozmiar) : head(nullptr), tail(nullptr), rozmiar(0) {
    if (rozmiar == 0) return;

    for (int i = 0; i < rozmiar; i++) {
        dodajKoniec(dane[i]);
    }
    cout << "Lista wypelniona danymi." << endl;
}

void ListaJednokierunkowa::dodajKoniec(int wartosc) {
    Wezel* newWezel = new Wezel(wartosc);

    if (head == nullptr) {
        head = tail = newWezel;
    } else {
        tail->next = newWezel;
        tail = newWezel;
    }
    rozmiar++;
}

ListaJednokierunkowa::~ListaJednokierunkowa() {
    while (head != nullptr) {
        Wezel* temp = head;
        head = head->next;
        delete temp;
    }
}

void ListaJednokierunkowa::wyswietl() const {
    if (head == nullptr) {
        cout << "Lista jest pusta!" << endl;
        return;
    }

    Wezel* aktualny = head;
    cout << "Lista: ";
    while (aktualny != nullptr) {
        cout << aktualny->dane << " ";
        aktualny = aktualny->next;
    }
    cout << endl;
}

int ListaJednokierunkowa::pobierzRozmiar() const {
    return rozmiar;
}
