#include <iostream>
#include "TablicaDynamiczna.hpp"

using namespace std;

int main() {
    int wybor_glowny, wybor_tablica, wybor_pozycja;
    int rozmiar_tablicy;
    int wartosc;
    TablicaDynamiczna* tablicaDynamiczna = nullptr;

    do {
        cout << "\n==== MENU GLOWNE ====" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Lista jednokierunkowa" << endl;
        cout << "0. Zamknij program" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor_glowny;

        switch (wybor_glowny) {
            case 1:
                cout << "\n--- Tablica dynamiczna ---" << endl;


                if (tablicaDynamiczna != nullptr) {
                    delete tablicaDynamiczna;
                }

                cout << "Podaj rozmiar tablicy do wygenerowania: ";
                cin >> rozmiar_tablicy;


                tablicaDynamiczna = new TablicaDynamiczna(rozmiar_tablicy);
                cout << "Tablica:" << endl;


                tablicaDynamiczna->wyswietl();

                do {
                    cout << "\nOpcje dla tablicy dynamicznej:" << endl;
                    cout << "1. Dodaj element na koniec" << endl;
                    cout << "2. Usun element z konca" << endl;
                    cout << "3. Wyswietl zawartosc tablicy" << endl;
                    cout << "0. Powrot do glownego menu" << endl;
                    cout << "Wybierz opcje: ";
                    cin >> wybor_tablica;

                    switch (wybor_tablica) {
                        case 1:
                            if (tablicaDynamiczna != nullptr) {
                                cout << "Podaj wartosc do dodania na koniec: ";
                                cin >> wartosc;
                                tablicaDynamiczna->dodajNaKoniec(wartosc);
                                tablicaDynamiczna->wyswietl();
                            } else {

                            }
                            break;

                        case 2:
                            if (tablicaDynamiczna != nullptr) {
                                tablicaDynamiczna->usunZKonca();
                                tablicaDynamiczna->wyswietl();
                            } else {

                            }
                            break;

                        case 3:
                            if (tablicaDynamiczna != nullptr) {
                                cout << "\nZawartosc tablicy dynamicznej:" << endl;
                                tablicaDynamiczna->wyswietl();
                            } else {

                            }
                            break;

                        case 0:
                            cout << "Powrot do glownego menu." << endl;
                            break;

                        default:
                            cout << "Niepoprawny wybor." << endl;
                            break;
                    }

                } while (wybor_tablica != 0);
                break;

            case 2:
                cout << "\n--- Lista jednokierunkowa ---" << endl;

                break;

            case 0:
                cout << "Zamykanie programu..." << endl;
                break;

            default:
                cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
                break;
        }

    } while (wybor_glowny != 0);


    if (tablicaDynamiczna != nullptr) {
        delete tablicaDynamiczna;
    }

    return 0;
}
