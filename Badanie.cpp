#include "Badanie.hpp"
#include "TablicaDynamiczna.hpp"
#include "ListaJednokierunkowa.hpp"
#include "DoublyLinkedList.h"
#include "TabliceGenerator.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void Badanie::BadanieDodawaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0, sumaLista = 0, sumaDwukierunkowa = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar);

        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.dodajNaPoczatek(daneOperacja[i]);
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.dodajPoczatek(daneOperacja[i]);
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.prepend(daneOperacja[i]);
                end = high_resolution_clock::now();
                sumaDwukierunkowa += duration_cast<nanoseconds>(end - start).count();
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas dodawania na poczatek - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na poczatek - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na poczatek - Lista dwukierunkowa: " << (sumaDwukierunkowa / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieDodawanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0, sumaLista = 0, sumaDwukierunkowa = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar);

        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.dodajNaKoniec(daneOperacja[i]);
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.dodajKoniec(daneOperacja[i]);
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.append(daneOperacja[i]);
                end = high_resolution_clock::now();
                sumaDwukierunkowa += duration_cast<nanoseconds>(end - start).count();
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas dodawania na koniec - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na koniec - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na koniec - Lista dwukierunkowa: " << (sumaDwukierunkowa / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieDodawanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0, sumaLista = 0, sumaDwukierunkowa = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar);

        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.dodawanieRandom(daneOperacja[i]);
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.dodajRandom(daneOperacja[i]);
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.insertRandom(daneOperacja[i]);
                end = high_resolution_clock::now();
                sumaDwukierunkowa += duration_cast<nanoseconds>(end - start).count();
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas dodawania losowo - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania losowo - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania losowo - Lista dwukierunkowa: " << (sumaDwukierunkowa / liczbaPomiarow) << " ns" << endl;
}
void Badanie::BadanieUsuwaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;
    long long sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.usunZPoczatku();
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.usunPoczatek();
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.removeHead();
                end = high_resolution_clock::now();
                sumaLista2 += duration_cast<nanoseconds>(end - start).count();
            }
        }
        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania z poczatku - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z poczatku - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z poczatku - Lista dwukierunkowa: " << (sumaLista2 / liczbaPomiarow) << " ns" << endl;
}


void Badanie::BadanieUsuwanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;
    long long sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.usunZKonca();
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.usunKoniec();
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.removeTail();
                end = high_resolution_clock::now();
                sumaLista2 += duration_cast<nanoseconds>(end - start).count();
            }
        }
        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania z konca - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z konca - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z konca - Lista dwukierunkowa: " << (sumaLista2 / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieUsuwanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;
    long long sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.usuwanieRandom();
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.usunRandom();
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.removeRandom();
                end = high_resolution_clock::now();
                sumaLista2 += duration_cast<nanoseconds>(end - start).count();
            }
        }
        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania z losowej pozycji - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z losowej pozycji - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z losowej pozycji - Lista dwukierunkowa: " << (sumaLista2 / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieSearch(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji) {
    long long sumaTablica = 0;
    long long sumaLista = 0;
    long long sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* dane = TabliceGenerator::generujLosowaTablice(rozmiar);

        TablicaDynamiczna tablica(dane, rozmiar);
        ListaJednokierunkowa lista(dane, rozmiar);
        DoublyLinkedList lista2(dane, rozmiar);

        for (int y = 0; y < liczbaOperacji; y++) {
            int indeks = rand() % rozmiar;
            int szukana = dane[indeks];

            auto start = high_resolution_clock::now();
            tablica.zawiera(szukana);
            auto end = high_resolution_clock::now();
            sumaTablica += duration_cast<nanoseconds>(end - start).count();

            start = high_resolution_clock::now();
            lista.zawiera(szukana);
            end = high_resolution_clock::now();
            sumaLista += duration_cast<nanoseconds>(end - start).count();

            start = high_resolution_clock::now();
            lista2.contains(szukana);
            end = high_resolution_clock::now();
            sumaLista2 += duration_cast<nanoseconds>(end - start).count();
        }

        delete[] dane;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji;
    cout << "Sredni czas wyszukiwania - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas wyszukiwania - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas wyszukiwania - Lista dwukierunkowa: " << (sumaLista2 / liczbaPomiarow) << " ns" << endl;
}
