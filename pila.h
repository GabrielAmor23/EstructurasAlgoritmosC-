#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <vector>

template <typename T>
class Pila {
private:
    std::vector<T> elementos;
public:
    void apilar(T val) { elementos.push_back(val); }
    T desapilar() {
        if (elementos.empty()) throw std::out_of_range("Pila<>::desapilar(): pila vacía");
        T val = elementos.back();
        elementos.pop_back();
        return val;
    }
    bool estaVacia() const { return elementos.empty(); }
};

#endif
