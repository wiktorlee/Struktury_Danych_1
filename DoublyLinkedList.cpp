#include "DoublyLinkedList.h"
#include <iostream>


Node::Node(int value)
    : data(value), prev(nullptr), next(nullptr) {}


// Konstruktor
DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr), size(0) {
    std::cout << "Utworzono liste dwukierunkowa." << std::endl;
}


// Towrzenie listy na podstawie tablicy
DoublyLinkedList::DoublyLinkedList(int* data, int size)
    : head(nullptr), tail(nullptr), size(0) {
    if(size <= 0) return;
    for(int i = 0; i < size; i++) {
        append(data[i]);
    }
}

// Destruktor
DoublyLinkedList::~DoublyLinkedList() {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
/** @brief Dodawanie elementów
*/
// Dodawanie na początek listy
void DoublyLinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    if(head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    size++;
}

// Dodawanie na koniec listy
void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value);
    if(tail != nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Dodawanie na losową pozycje
void DoublyLinkedList::insertRandom(int value) {
    int index = rand() % (size + 1);
    if(index == 0) {
        prepend(value);
        return;
    }
    if(index == size) {
        append(value);
        return;
    }
    Node* current = head;
    for(int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* newNode = new Node(value);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}
/**
 *@brief usuwanie elementów
 */
// Usuwa element na początku listy
void DoublyLinkedList::removeHead() {
    Node* temp = head;
    head = head->next;
    if(head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

// Usuwa element na końcu listy
void DoublyLinkedList::removeTail() {
    Node* temp = tail;
    tail = tail->prev;
    if(tail != nullptr) {
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

// Usuwa element losowy

void DoublyLinkedList::removeRandom() {
    int index = rand() % size;
    if(index == 0) {
        removeHead();
        return;
    }
    if(index == size - 1) {
        removeTail();
        return;
    }
    Node* current = head;
    for(int i = 0; i < index; i++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}


// Sprawdza, czy lista zawiera element o zadanej wartości
bool DoublyLinkedList::contains(int value) const {
    Node* current = head;
    while(current != nullptr) {
        if(current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}


// Wyszukuje element w liście i zwraca jego indeks

int DoublyLinkedList::search(int value) const {
    Node* current = head;
    int index = 0;
    while(current != nullptr) {
        if(current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}



