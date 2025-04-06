#ifndef WEZEL_HPP
#define WEZEL_HPP
struct Wezel {
    int dane;
    Wezel* next;


    Wezel(int wartosc) : dane(wartosc), next(nullptr) {}
};

#endif
