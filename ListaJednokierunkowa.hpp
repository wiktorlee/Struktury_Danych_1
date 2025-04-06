#ifndef LISTA_JEDNOKIERUNKOWA_HPP
#define LISTA_JEDNOKIERUNKOWA_HPP

#include "Wezel.hpp"
#include <iostream>

using namespace std;

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
    void wyswietl() const;
    int pobierzRozmiar() const;
};

#endif
