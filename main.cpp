#include <iostream>
#include "Badanie.hpp"

using namespace std;

/**
 * @brief Funkcja główna programu.
 * Umożliwia wybór operacji testowych na strukturach danych.
 */
int main() {
    int rozmiarStruktury;
    int liczbaEgzemplarzy;
    int liczbaOperacji;
    int liczbaElementow;

    cout << "BADANIE" << endl;
    cout << "Podaj rozmiar struktury: ";
    cin >> rozmiarStruktury; // pobieramy rozmiar struktury
    cout << "Podaj liczbe badanych egzemplarzy: ";
    cin >> liczbaEgzemplarzy; // liczba instancji
    cout << "Podaj liczbe operacji do wykonania (na jednym egzemplarzu): ";
    cin >> liczbaOperacji;  // operacje na instancji
    cout << "Podaj liczbe elementow w jednej operacji: ";
    cin >> liczbaElementow; // elementów przy jednej operacji

    // Menu wyboru operacji
    cout << "\nWYBIERZ OPERACJE:" << endl;
    cout << "1. Dodawanie na poczatek" << endl;
    cout << "2. Dodawanie na koniec" << endl;
    cout << "3. Usuwanie z poczatku" << endl;
    cout << "4. Usuwanie z konca" << endl;
    cout << "5. Dodawanie na losowej pozycji" << endl;
    cout << "6. Usuwanie z losowej pozycji" << endl;
    cout << "7. Wyszukiwanie elementu" << endl;

    int wybor;
    cin >> wybor; // wybór operacji

    // Wywołanie odpowiedniej funkcji na podstawie wyboru użytkownika
    switch (wybor) {
        case 1:
            Badanie::BadanieDodawaniePoczatek(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji, liczbaElementow);
            break;
        case 2:
            Badanie::BadanieDodawanieKoniec(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji, liczbaElementow);
            break;
        case 3:
            Badanie::BadanieUsuwaniePoczatek(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji, liczbaElementow);
            break;
        case 4:
            Badanie::BadanieUsuwanieKoniec(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji, liczbaElementow);
            break;
        case 5:
            Badanie::BadanieDodawanieRandom(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji, liczbaElementow);
            break;
        case 6:
            Badanie::BadanieUsuwanieRandom(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji, liczbaElementow);
            break;
        case 7:
            Badanie::BadanieSearch(rozmiarStruktury, liczbaEgzemplarzy, liczbaOperacji);
            break;
        default:
            cout << "Zly wybor" << endl;
            break;
    }

    return 0;
}
