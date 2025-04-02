#ifndef TABLICADYNAMICZNA_HPP
#define TABLICADYNAMICZNA_HPP

class TablicaDynamiczna {
private:
    int* tablica;
    int pojemnosc;
    int rozmiar;

    void powieksz();
    void zmniejsz();

public:
    TablicaDynamiczna(int poczatkowyRozmiar);
    ~TablicaDynamiczna();

    void dodajNaKoniec(int wartosc);
    void usunZKonca();
    void wyswietl();

    int* pobierzTablice();
    int pobierzPojemnosc();
    int pobierzRozmiar();
};

#endif //TABLICADYNAMICZNA_HPP
