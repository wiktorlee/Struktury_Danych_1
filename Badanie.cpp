#include "Badanie.hpp"
#include "TablicaDynamiczna.hpp"
#include "ListaJednokierunkowa.hpp"
#include "DoublyLinkedList.h"
#include "TabliceGenerator.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
// Metoda odpowiedzialna za przeprowadzenie badań czasowych dla wskazanej operacji na trzech strukturach danych:
//  tablicy dynamicznej, liście jednokierunkowej oraz liście dwukierunkowej.
// Działa zgodnie z ustalonym harmonogramem badań: wykonuje testy dla zadanej liczby egzemplarzy,
// z których każdy otrzymuje losowo wygenerowane dane początkowe oraz zestaw danych do operacji.
// Dla każdej instancji wykonywana jest określona liczba operacji,
// z których każda polega na wykonaniu działania (np. dodania lub usunięcia) na ustalonej liczbie elementów.
// Czas trwania każdej pojedynczej operacji (np. jednego dodania/usunięcia elementu) jest mierzony osobno.
// Po zakończeniu wszystkich pomiarów obliczana jest uśredniona wartość globalna,
// będąca ilorazem sumy wszystkich pomiarów i całkowitej liczby operacji.
// Finalnie, dla każdej ze struktur wypisywany jest średni czas wykonania danej operacji w nanosekundach.
// Każda z metod badawczych zbudowana jest według tego samego schematu.



void Badanie::BadanieDodawaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0, sumaLista = 0, sumaDwukierunkowa = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {                // test dla każdej instancji
        cout << "Badanie numer: " << x + 1 << endl;
        // Generacja danych startowych oraz operacyjnych
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar); // dane startowe
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow); // elementy do dodania

        // Inicjalizacja struktur
        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar);

        // Wykonujemy określoną liczbę operacji dodawania na początek
        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.dodajNaPoczatek(daneOperacja[i]); // dodaj do tablicy
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count(); // mierzymy czas

                start = high_resolution_clock::now();
                lista.dodajPoczatek(daneOperacja[i]);      // dodaj do listy jednokierunkowej
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.prepend(daneOperacja[i]);           // dodaj do listy dwukierunkowej
                end = high_resolution_clock::now();
                sumaDwukierunkowa += duration_cast<nanoseconds>(end - start).count();
            }
        }
        // Zwolnienie pamięci dynamicznej
        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }
    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow; // łączna liczba operacji
    cout << "Sredni czas dodawania na poczatek - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na poczatek - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na poczatek - Lista dwukierunkowa: " << (sumaDwukierunkowa / liczbaPomiarow) << " ns" << endl;
}


void Badanie::BadanieDodawanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0, sumaLista = 0, sumaDwukierunkowa = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {               // dla każdej instancji testowej
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar);

        // Operacja dodania na koniec
        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.dodajNaKoniec(daneOperacja[i]); // dodaj do tablicy
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.dodajKoniec(daneOperacja[i]);      // dodaj do listy jednokierunkowej
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.append(daneOperacja[i]);           // dodaj do listy dwukierunkowej
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
    long long sumaTablica = 0, sumaLista = 0, sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {              // test dla każdej instancji
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);                  // dane startowe
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);            // elementy do dodania

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar);

        // Dodawanie elementów w losowych miejscach
        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.dodawanieRandom(daneOperacja[i]);   // dodaj do tablicy
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.dodajRandom(daneOperacja[i]);         // dodaj do listy jednokierunkowej
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.insertRandom(daneOperacja[i]);       // dodaj do listy dwukierunkowej
                end = high_resolution_clock::now();
                sumaLista2 += duration_cast<nanoseconds>(end - start).count();
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;  // łaczna liczba operacji
    cout << "Sredni czas dodawania losowo - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania losowo - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania losowo - Lista dwukierunkowa: " << (sumaLista2 / liczbaPomiarow) << " ns" << endl;
}


void Badanie::BadanieUsuwaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0, sumaLista = 0, sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {                // iterujemy po instancjach
        cout << "Badanie numer: " << x + 1 << endl;
        // Generujemy dane o rozmiarze, który uwzględnia dodatkowe operacje
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

        // Usuwamy elementy z początku
        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.usunZPoczatku();      // usuń z tablicy
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.usunPoczatek();         // usuń z listy jednokierunkowej
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.removeHead();          // usuń z listy dwukierunkowej
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
    long long sumaTablica = 0, sumaLista = 0, sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

        // Usuwanie z końca
        for (int y = 0; y < liczbaOperacji; y++) {
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.usunZKonca();       // usuń z tablicy
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.usunKoniec();         // usuń z listy jednokierunkowej
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.removeTail();        // usuń z listy dwukierunkowej
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
    long long sumaTablica = 0, sumaLista = 0, sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {              // test dla każdej instancji
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow); // dane początkowe

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        DoublyLinkedList lista2(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);


        for (int y = 0; y < liczbaOperacji; y++) {      // Usuwanie elementów z losowych miejsc
            for (int i = 0; i < liczbaElementow; i++) {
                auto start = high_resolution_clock::now();
                tablica.usuwanieRandom();      // usuń z tablicy
                auto end = high_resolution_clock::now();
                sumaTablica += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista.usunRandom();            // usuń z listy jednokierunkowej
                end = high_resolution_clock::now();
                sumaLista += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                lista2.removeRandom();         // usuń z listy dwukierunkowej
                end = high_resolution_clock::now();
                sumaLista2 += duration_cast<nanoseconds>(end - start).count();
            }
        }

        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania losowo - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania losowo - Lista jednokierunkowa: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania losowo - Lista dwukierunkowa: " << (sumaLista2 / liczbaPomiarow) << " ns" << endl;
}



void Badanie::BadanieSearch(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji) {
    long long sumaTablica = 0, sumaLista = 0, sumaLista2 = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;
        int* dane = TabliceGenerator::generujLosowaTablice(rozmiar);

        TablicaDynamiczna tablica(dane, rozmiar);
        ListaJednokierunkowa lista(dane, rozmiar);
        DoublyLinkedList lista2(dane, rozmiar);

        for (int y = 0; y < liczbaOperacji; y++) {
            int indeks = rand() % rozmiar; // losujemy indeks
            int szukana = dane[indeks];     // pobieramy szukaną wartość

            auto start = high_resolution_clock::now();
            tablica.zawiera(szukana);       // sprawdzamy tablicę
            auto end = high_resolution_clock::now();
            sumaTablica += duration_cast<nanoseconds>(end - start).count();

            start = high_resolution_clock::now();
            lista.zawiera(szukana);         // sprawdzamy listę jednokierunkową
            end = high_resolution_clock::now();
            sumaLista += duration_cast<nanoseconds>(end - start).count();

            start = high_resolution_clock::now();
            lista2.contains(szukana);       // sprawdzamy listę dwukierunkową
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
