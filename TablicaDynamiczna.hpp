#ifndef TABLICADYNAMICZNA_HPP
#define TABLICADYNAMICZNA_HPP

class TablicaDynamiczna {
private:
    int* tablica;
    int rozmiar;
    int pojemnosc;
    void powieksz();
    void zmniejsz();

public:
    TablicaDynamiczna(int* dane, int rozmiar);
    TablicaDynamiczna(int poczatkowyRozmiar);
    ~TablicaDynamiczna();
    void dodajNaKoniec(int wartosc);
    void dodajNaPoczatek(int wartosc);
    void dodawanieRandom(int wartosc);
    void usunZKonca();
    void usunZPoczatku();
    void usuwanieRandom();
    void wyswietl();
    int* pobierzTablice();
    int pobierzPojemnosc();
    int pobierzRozmiar();
};

#endif
