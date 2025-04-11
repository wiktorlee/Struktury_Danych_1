

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


#include <iostream>

/**
 * @brief Węzeł listy dwukierunkowej
 */
struct Node {
    int data;       ///< Wartość przechowywana w węźle
    Node* prev;     ///< Poprzedni węzeł
    Node* next;     ///< Następny węzeł

    /**
     * @brief Tworzy nowy węzeł z daną wartością
     * @param value Liczba, którą zapisujemy w węźle
     */
    Node(int value);
};

/**
 * @brief Klasa listy dwukierunkowej
 */
class DoublyLinkedList {
private:
    Node* head;     ///< Pierwszy węzeł listy
    Node* tail;     ///< Ostatni węzeł listy
    int size;       ///< Ilość elementów w liście

public:
    /**
     * @brief Tworzy pustą listę
     */
    DoublyLinkedList();

    /**
     * @brief Tworzy listę z danych w tablicy
     * @param data Tablica z liczbami
     * @param size Ile liczb jest w tablicy
     */
    DoublyLinkedList(int* data, int size);

    /**
     * @brief Usuwa całą listę i zwalnia pamięć
     */
    ~DoublyLinkedList();

    /**
     * @brief Dodaje nowy element na początku listy
     * @param value Wartość do dodania
     */
    void prepend(int value);

    /**
     * @brief Dodaje nowy element na końcu listy
     * @param value Wartość do dodania
     */
    void append(int value);

    /**
     * @brief Dodaje element w losowym miejscu listy
     * @param value Wartość do dodania
     */
    void insertRandom(int value);

    /**
     * @brief Usuwa pierwszy element z listy
     */
    void removeHead();

    /**
     * @brief Usuwa ostatni element z listy
     */
    void removeTail();

    /**
     * @brief Usuwa losowy element z listy
     */
    void removeRandom();

    /**
     * @brief Sprawdza, czy dana wartość jest w liście
     * @param value Szukana wartość
     * @return true jeśli znaleziono, false jeśli nie
     */
    bool contains(int value) const;

    /**
     * @brief Szuka elementu w liście
     * @param value Wartość do znalezienia
     * @return Pozycja elementu w liście lub -1 jeśli nie znaleziono
     */
    int search(int value) const;

    /**
     * @brief Wyświetla wszystkie elementy listy
     */

};



#endif
