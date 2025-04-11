#ifndef LISTA_JEDNOKIERUNKOWA_HPP
#define LISTA_JEDNOKIERUNKOWA_HPP

#include <iostream>

/**
 * @brief Prosty węzeł listy jednokierunkowej.
 */
struct Wezel {
    int dane;    ///< Przechowywane dane.
    Wezel* next; ///< Wskaźnik do następnego węzła.

    /**
     * @brief Konstruktor węzła.
     * @param wartosc Wartość dla węzła.
     */
    Wezel(int wartosc) : dane(wartosc), next(nullptr) {}
};

/**
 * @brief Klasa ListaJednokierunkowa obsługuje listę jednokierunkową.
 */
class ListaJednokierunkowa {
private:
    Wezel* head;   ///< Pierwszy element listy.
    Wezel* tail;   ///< Ostatni element listy.
    int rozmiar;   ///< Liczba elementów.

public:
    /**
     * @brief Konstruktor domyślny.
     */
    ListaJednokierunkowa();

    /**
     * @brief Konstruktor tworzy listę na podstawie tablicy.
     * @param dane Tablica danych.
     * @param rozmiar Liczba elementów w tablicy.
     */
    ListaJednokierunkowa(int* dane, int rozmiar);

    /**
     * @brief Destruktor, który usuwa listę.
     */
    ~ListaJednokierunkowa();

    /**
     * @brief Dodaje element na koniec listy.
     * @param wartosc Wartość dodawanego elementu.
     */
    void dodajKoniec(int wartosc);

    /**
     * @brief Dodaje element na początek listy.
     * @param wartosc Wartość dodawanego elementu.
     */
    void dodajPoczatek(int wartosc);

    /**
     * @brief Usuwa pierwszy element z listy.
     */
    void usunPoczatek();

    /**
     * @brief Usuwa ostatni element z listy.
     */
    void usunKoniec();

    /**
     * @brief Dodaje element w losowym miejscu.
     * @param wartosc Wartość dodawanego elementu.
     */
    void dodajRandom(int wartosc);

    /**
     * @brief Usuwa element z losowego miejsca.
     */
    void usunRandom();

    /**
     * @brief Wyświetla elementy listy.
     */
    void wyswietl() const;

    /**
     * @brief Sprawdza, czy element występuje w liście.
     * @param wartosc Wartość do sprawdzenia.
     * @return true jeśli element jest w liście, false w przeciwnym przypadku.
     */
    bool zawiera(int wartosc) const;

    /**
     * @brief Zwraca liczbę elementów na liście.
     * @return Liczba elementów.
     */
    int pobierzRozmiar() const;
};

#endif
