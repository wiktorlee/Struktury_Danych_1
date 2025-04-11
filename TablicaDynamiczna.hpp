#ifndef TABLICADYNAMICZNA_HPP
#define TABLICADYNAMICZNA_HPP

/**
 * @brief Klasa TablicaDynamiczna reprezentuje tablicę zmiennych rozmiarów.
 */
class TablicaDynamiczna {
private:
    int* tablica;   ///< Tablica elementów.
    int rozmiar;    ///< Ilość aktualnych elementów.
    int pojemnosc;  ///< Maksymalna ilość elementów przed rozszerzeniem.

    /**
     * @brief Powiększa tablicę, gdy nie ma wystarczająco miejsca.
     */
    void powieksz();

    /**
     * @brief Zmniejsza tablicę, gdy jest za dużo wolnego miejsca.
     */
    void zmniejsz();

public:
    /**
     * @brief Konstruktor tworzy tablicę z początkowymi danymi.
     * @param dane Tablica z danymi.
     * @param rozmiar Ilość elementów początkowych.
     */
    TablicaDynamiczna(int* dane, int rozmiar);

    /**
     * @brief Konstruktor tworzy pustą tablicę o zadanym rozmiarze.
     * @param poczatkowyRozmiar Początkowa pojemność tablicy.
     */
    TablicaDynamiczna(int poczatkowyRozmiar);

    /**
     * @brief Destruktor, który usuwa tablicę.
     */
    ~TablicaDynamiczna();

    /**
     * @brief Dodaje element na koniec tablicy.
     * @param wartosc Wartość dodawanego elementu.
     */
    void dodajNaKoniec(int wartosc);

    /**
     * @brief Dodaje element na początek tablicy.
     * @param wartosc Wartość dodawanego elementu.
     */
    void dodajNaPoczatek(int wartosc);

    /**
     * @brief Dodaje element w losowej pozycji.
     * @param wartosc Wartość dodawanego elementu.
     */
    void dodawanieRandom(int wartosc);

    /**
     * @brief Usuwa element z końca tablicy.
     */
    void usunZKonca();

    /**
     * @brief Usuwa element z początku tablicy.
     */
    void usunZPoczatku();

    /**
     * @brief Usuwa element z losowej pozycji.
     */
    void usuwanieRandom();

    /**
     * @brief Wyświetla elementy tablicy.
     */
    void wyswietl();

    /**
     * @brief Sprawdza, czy tablica zawiera dany element.
     * @param wartosc Wartość do sprawdzenia.
     * @return true jeśli element jest w tablicy, false w przeciwnym przypadku.
     */
    bool zawiera(int wartosc);

    /**
     * @brief Zwraca wskaźnik na tablicę.
     * @return Wskaźnik do tablicy.
     */
    int* pobierzTablice();

    /**
     * @brief Zwraca aktualną pojemność tablicy.
     * @return Pojemność tablicy.
     */
    int pobierzPojemnosc();

    /**
     * @brief Zwraca liczbę elementów w tablicy.
     * @return Ilość elementów.
     */
    int pobierzRozmiar();
};

#endif
