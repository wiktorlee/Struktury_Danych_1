#ifndef BADANIE_HPP
#define BADANIE_HPP

#include "TablicaDynamiczna.hpp"
#include "ListaJednokierunkowa.hpp"
#include "DoublyLinkedList.h"
#include "TabliceGenerator.hpp"

class Badanie {
public:
    static void BadanieDodawaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);
    static void BadanieDodawanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);
    static void BadanieUsuwaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);
    static void BadanieUsuwanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);
    static void BadanieDodawanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);
    static void BadanieUsuwanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);
    static void BadanieSearch(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji);
};

#endif
