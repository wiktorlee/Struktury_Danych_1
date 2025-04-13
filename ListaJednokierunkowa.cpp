#include <iostream>
#include "ListaJednokierunkowa.hpp"
#include <cstdlib>
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

    if (head == nullptr) {                      //dodanie elementu na koniec, aktualizacja tail'a i rozmiaru
        head = tail = newWezel;
    } else {
        tail->next = newWezel;
        tail = newWezel;
    }
    rozmiar++;
}

void ListaJednokierunkowa::dodajPoczatek(int wartosc) {         //dodanie elementu na poczatek, aktualizacja head'a
    Wezel* newWezel = new Wezel(wartosc);
    newWezel->next = head;
    head = newWezel;

    if (tail == nullptr) {
        tail = newWezel;
    }
    rozmiar++;
   // cout <<"Wykonano operacje" << endl;
}

void ListaJednokierunkowa::dodajRandom(int wartosc) {
    int indeks = rand() % (rozmiar + 1);

    if (indeks == 0) {                  //losowanie ziarna, sprawdzenie czy nie dodajemy na poczatku lub koncu, dodanie w wybrane miejsce
        dodajPoczatek(wartosc);
        return;
    }
    if (indeks == rozmiar) {
        dodajKoniec(wartosc);
        return;
    }

    Wezel* newWezel = new Wezel(wartosc);
    Wezel* aktualny = head;

    for (int i = 1; i < indeks; i++) {
        aktualny = aktualny->next;
    }
    newWezel->next = aktualny->next;
    aktualny->next = newWezel;
    rozmiar++;

    //cout<<"Wykonano operacje" << endl;
}

void ListaJednokierunkowa::usunPoczatek() {
    if (head == nullptr) {                      //usuniecie elementu z poczatku, aktualizacja head
        cout << "Lista jest pusta!" << endl;
        return;
    }

    Wezel* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
    rozmiar--;
    //cout <<"Wykonano operacje" << endl;
}

void ListaJednokierunkowa::usunKoniec() {       //usuniecie z ostatniego elementu listy, znalezienie przedostatniego wezla
    if (head == nullptr) {
        cout << "Lista jest pusta!" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Wezel* aktualny = head;
        while (aktualny->next != tail) {
            aktualny = aktualny->next;
        }
        delete tail;
        tail = aktualny;
        tail->next = nullptr;
    }
    rozmiar--;
     //cout <<"Wykonano operacje" << endl;
}



void ListaJednokierunkowa::usunRandom() {       //losowanie ziarna, sprawdzenie czy nie usuwamy z poczatku lub z konca, usuniecie w wybranym miejscu
    if (rozmiar == 0) {
        cout << "Lista jest pusta!" << endl;
        return;
    }

    int indeks = rand() % rozmiar;

    if (indeks == 0) {
        usunPoczatek();
        return;
    }
    if (indeks == rozmiar - 1) {
        usunKoniec();
        return;
    }
    Wezel* aktualny = head;

    for (int i = 1; i < indeks; i++) {
        aktualny = aktualny->next;
    }
    Wezel* doUsuniecia = aktualny->next;
    aktualny->next = doUsuniecia->next;
    delete doUsuniecia;
    rozmiar--;

     //cout <<"Wykonano operacje" << endl;
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
bool ListaJednokierunkowa::zawiera(int wartosc) const {
    Wezel* aktualny = head;                                 //przechodzenie po wskazniku next i szukanie zadanej wartosci
    while (aktualny != nullptr) {
        if (aktualny->dane == wartosc) {
            return true;
        }
        aktualny = aktualny->next;
    }
    return false;
}
