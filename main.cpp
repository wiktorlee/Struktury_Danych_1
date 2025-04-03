#include <iostream>
#include <cstdlib>
#include "TablicaDynamiczna.hpp"
#include "TabliceGenerator.hpp"

using namespace std;

int main() {
    int wybor_glowny, wybor_tablica, wybor_operacja;
    int rozmiar_tablicy;
    int wartosc, indeks;
    TablicaDynamiczna* tablicaDynamiczna = nullptr;

    cout << "Podaj rozmiar struktury danych: ";
    cin >> rozmiar_tablicy;

    int* dane = TabliceGenerator::generujLosowaTablice(rozmiar_tablicy);
    tablicaDynamiczna = new TablicaDynamiczna(dane, rozmiar_tablicy);

    do {
        cout << "\n==== MENU GLOWNE ====" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Lista jednokierunkowa" << endl;
        cout << "0. Zamknij program" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor_glowny;

        switch (wybor_glowny) {
            case 1:
                do {
                    cout << "\nOpcje dla tablicy dynamicznej:" << endl;
                    cout << "1. Dodaj" << endl;
                    cout << "2. Usun" << endl;
                    cout << "3. Wyswietl" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "Wybierz opcje: ";
                    cin >> wybor_tablica;

                    switch (wybor_tablica) {
                        case 1:
                            cout << "\nWybierz miejsce dodania:" << endl;
                            cout << "1. Na poczatku" << endl;
                            cout << "2. Na koncu" << endl;
                            cout << "3. W losowym miejscu" << endl;
                            cout << "Wybierz opcje: ";
                            cin >> wybor_operacja;

                            cout << "Podaj wartosc: ";
                            cin >> wartosc;

                            switch (wybor_operacja) {
                                case 1:
                                    tablicaDynamiczna->dodajNaPoczatek(wartosc);
                                    break;
                                case 2:
                                    tablicaDynamiczna->dodajNaKoniec(wartosc);
                                    break;
                                case 3:
                                    break;
                                default:
                                    cout << "Niepoprawny wybor." << endl;
                            }
                            tablicaDynamiczna->wyswietl();
                            break;

                        case 2:
                            cout << "\nWybierz miejsce usuniecia:" << endl;
                            cout << "1. Z poczatku" << endl;
                            cout << "2. Z konca" << endl;
                            cout << "3. Z losowego miejsca" << endl;
                            cout << "Wybierz opcje: ";
                            cin >> wybor_operacja;

                            switch (wybor_operacja) {
                                case 1:
                                    tablicaDynamiczna->usunZPoczatku();
                                    break;
                                case 2:
                                    tablicaDynamiczna->usunZKonca();
                                    break;
                                case 3:
                                    break;
                                default:
                                    cout << "Niepoprawny wybor." << endl;
                            }
                            tablicaDynamiczna->wyswietl();
                            break;

                        case 3:
                            tablicaDynamiczna->wyswietl();
                            break;

                        case 4:
                            cout << "Powrot do glownego menu." << endl;
                            break;

                        default:
                            cout << "Niepoprawny wybor." << endl;
                            break;
                    }

                } while (wybor_tablica != 4);
                break;

            case 2:
                cout << "\n--- Lista jednokierunkowa ---" << endl;
                break;

            case 0:
                cout << "Zamykanie programu..." << endl;
                break;

            default:
                cout << "Niepoprawny wybor." << endl;
                break;
        }

    } while (wybor_glowny != 0);

    if (tablicaDynamiczna != nullptr) {
        delete tablicaDynamiczna;
    }
    delete[] dane;

    return 0;
}
