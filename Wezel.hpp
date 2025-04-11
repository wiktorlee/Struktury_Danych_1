#ifndef WEZEL_HPP
#define WEZEL_HPP

/**
 * @brief Prosty węzeł używany w listach.
 */
struct Wezel {
    int dane;    ///< Przechowuje dane.
    Wezel* next; ///< Wskaźnik na następny węzeł.

    /**
     * @brief Konstruktor węzła.
     * @param wartosc Wartość przypisywana do węzła.
     */
    Wezel(int wartosc) : dane(wartosc), next(nullptr) {}
};

#endif
