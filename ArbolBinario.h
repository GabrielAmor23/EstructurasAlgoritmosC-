#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>

template <typename T>
class NodoArbol {
public:
    T dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
    NodoArbol(T val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

template <typename T>
class ArbolBinario {
private:
    NodoArbol<T>* raiz;
    void recorridoInOrden(NodoArbol<T>* nodo);
public:
    ArbolBinario() : raiz(nullptr) {}
    void insertar(T val);
    void recorridoInOrden();
};

template <typename T>
void ArbolBinario<T>::insertar(T val) {
    NodoArbol<T>* nuevoNodo = new NodoArbol<T>(val);
    if (!raiz) {
        raiz = nuevoNodo;
    } else {
        NodoArbol<T>* actual = raiz;
        NodoArbol<T>* padre = nullptr;
        while (actual) {
            padre = actual;
            if (val < actual->dato) {
                actual = actual->izquierdo;
            } else {
                actual = actual->derecho;
            }
        }
        if (val < padre->dato) {
            padre->izquierdo = nuevoNodo;
        } else {
            padre->derecho = nuevoNodo;
        }
    }
}

template <typename T>
void ArbolBinario<T>::recorridoInOrden() {
    recorridoInOrden(raiz);
    std::cout << std::endl;
}

template <typename T>
void ArbolBinario<T>::recorridoInOrden(NodoArbol<T>* nodo) {
    if (nodo) {
        recorridoInOrden(nodo->izquierdo);
        std::cout << nodo->dato << " ";
        recorridoInOrden(nodo->derecho);
    }
}

#endif
