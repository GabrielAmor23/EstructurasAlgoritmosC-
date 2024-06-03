#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;
    Nodo(T val) : dato(val), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
public:
    ListaEnlazada() : cabeza(nullptr) {}
    void insertarAlFinal(T val);
    void mostrar();
    // Agregar más métodos según sea necesario
};

template <typename T>
void ListaEnlazada<T>::insertarAlFinal(T val) {
    Nodo<T>* nuevoNodo = new Nodo<T>(val);
    if (!cabeza) {
        cabeza = nuevoNodo;
    } else {
        Nodo<T>* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

template <typename T>
void ListaEnlazada<T>::mostrar() {
    Nodo<T>* temp = cabeza;
    while (temp) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "null" << std::endl;
}

#endif
