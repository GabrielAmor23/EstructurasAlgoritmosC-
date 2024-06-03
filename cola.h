#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <queue>

template <typename T>
class Cola {
private:
    std::queue<T> elementos;
public:
    void encolar(T val) { elementos.push(val); }
    T desencolar() {
        if (elementos.empty()) throw std::out_of_range("Cola<>::desencolar(): cola vacía");
        T val = elementos.front();
        elementos.pop();
        return val;
    }
    bool estaVacia() const { return elementos.empty(); }
};

#endif
