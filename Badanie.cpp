#include <iostream>
#include "Badanie.hpp"
#include <chrono>


using namespace std;
using namespace std::chrono;

void Badanie::BadanieDodawaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);

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
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas dodawania na poczatek - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na poczatek - Lista: " << (sumaLista / liczbaPomiarow) << " ns" << endl;

}

void Badanie::BadanieDodawanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);

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
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas dodawania na koniec - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na koniec - Lista: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieDodawanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar);
        int* daneOperacja = TabliceGenerator::generujLosowaTablice(liczbaElementow);

        TablicaDynamiczna tablica(danePoczatkowe, rozmiar);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar);

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
            }
        }

        delete[] danePoczatkowe;
        delete[] daneOperacja;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas dodawania na losowej pozycji - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas dodawania na losowej pozycji - Lista: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieUsuwaniePoczatek(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);
        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

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
            }
        }

        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania z poczatku - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z poczatku - Lista: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieUsuwanieKoniec(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);
        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

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
            }
        }

        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania z konca - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z konca - Lista: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
}

void Badanie::BadanieUsuwanieRandom(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji, int liczbaElementow) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* danePoczatkowe = TabliceGenerator::generujLosowaTablice(rozmiar + liczbaOperacji * liczbaElementow);
        TablicaDynamiczna tablica(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);
        ListaJednokierunkowa lista(danePoczatkowe, rozmiar + liczbaOperacji * liczbaElementow);

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
            }
        }

        delete[] danePoczatkowe;
    }

    long long liczbaPomiarow = static_cast<long long>(liczbaEgzemplarzy) * liczbaOperacji * liczbaElementow;
    cout << "Sredni czas usuwania z losowej pozycji - Tablica: " << (sumaTablica / liczbaPomiarow) << " ns" << endl;
    cout << "Sredni czas usuwania z losowej pozycji - Lista: " << (sumaLista / liczbaPomiarow) << " ns" << endl;
}
void Badanie::BadanieSearch(int rozmiar, int liczbaEgzemplarzy, int liczbaOperacji) {
    long long sumaTablica = 0;
    long long sumaLista = 0;

    for (int x = 0; x < liczbaEgzemplarzy; x++) {
        cout << "Badanie numer: " << x + 1 << endl;

        int* dane = TabliceGenerator::generujLosowaTablice(rozmiar);
        TablicaDynamiczna tablica(dane, rozmiar);
        ListaJednokierunkowa lista(dane, rozmiar);

        for (int y = 0; y < liczbaOperacji; y++) {
            int indeks = rand() % rozmiar;
            int szukana = dane[indeks];

            //cout<<"Szukana teraz liczba to : "<<szukana<<endl;

            auto start = high_resolution_clock::now();
            tablica.zawiera(szukana);
            auto end = high_resolution_clock::now();
            sumaTablica += duration_cast<nanoseconds>(end - start).count();

            start = high_resolution_clock::now();
            lista.zawiera(szukana);
            end = high_resolution_clock::now();
            sumaLista += duration_cast<nanoseconds>(end - start).count();
        }

        delete[] dane;
    }

    cout << "Sredni czas wyszukiwania - Tablica: " << (sumaTablica / (liczbaEgzemplarzy * liczbaOperacji)) << " ns" << endl;
    cout << "Sredni czas wyszukiwania - Lista: " << (sumaLista / (liczbaEgzemplarzy * liczbaOperacji)) << " ns" << endl;
}
