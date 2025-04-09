#ifndef LISTA_JEDNOKIERUNKOWA_HPP
#define LISTA_JEDNOKIERUNKOWA_HPP

#include <iostream>

struct Wezel {
    int dane;
    Wezel* next;
    Wezel(int wartosc) : dane(wartosc), next(nullptr) {}
};

class ListaJednokierunkowa {
private:
    Wezel* head;
    Wezel* tail;
    int rozmiar;

public:
    ListaJednokierunkowa();
    ListaJednokierunkowa(int* dane, int rozmiar);
    ~ListaJednokierunkowa();

    void dodajKoniec(int wartosc);
    void dodajPoczatek(int wartosc);
    void usunPoczatek();
    void usunKoniec();
    void dodajRandom(int wartosc);
    void usunRandom();
    void wyswietl() const;
    bool zawiera(int wartosc) const;
    int pobierzRozmiar() const;
};

#endif
