#ifndef BADANIE_HPP
#define BADANIE_HPP

#include "TablicaDynamiczna.hpp"
#include "ListaJednokierunkowa.hpp"
#include "DoublyLinkedList.h"
#include "TabliceGenerator.hpp"

/**
 * @brief Klasa Badanie wykonuje testy operacji na różnych strukturach danych.
 */
class Badanie {
public:
    /**
     * @brief Test dodawania elementów na początek.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     * @param liczbaElementow Liczba dodawanych elementów.
     */
    static void BadanieDodawaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);

    /**
     * @brief Test dodawania elementów na koniec.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     * @param liczbaElementow Liczba dodawanych elementów.
     */
    static void BadanieDodawanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);

    /**
     * @brief Test usuwania elementów z początku.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     * @param liczbaElementow Liczba usuwanych elementów.
     */
    static void BadanieUsuwaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);

    /**
     * @brief Test usuwania elementów z końca.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     * @param liczbaElementow Liczba usuwanych elementów.
     */
    static void BadanieUsuwanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);

    /**
     * @brief Test dodawania elementu w losowym miejscu.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     * @param liczbaElementow Liczba dodawanych elementów.
     */
    static void BadanieDodawanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);

    /**
     * @brief Test usuwania elementu z losowego miejsca.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     * @param liczbaElementow Liczba usuwanych elementów.
     */
    static void BadanieUsuwanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow);

    /**
     * @brief Test szukania elementu.
     * @param rozmiar Wielkość struktury danych.
     * @param liczbaEgzemplarzy Liczba struktur.
     * @param liczbaOperacji Liczba wykonanych operacji.
     */
    static void BadanieSearch(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji);
};

#endif
