#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <vector>

template <typename T>
class Grafo {
private:
    std::vector<std::list<T>> listaAdyacencia;
public:
    Grafo(int vertices = 0) : listaAdyacencia(vertices) {}
    void agregarArista(T u, T v);
    const std::list<T>& obtenerListaAdyacencia(T v) const;
    int tamano() const { return listaAdyacencia.size(); }
};

template <typename T>
void Grafo<T>::agregarArista(T u, T v) {
    listaAdyacencia[u].push_back(v);
}

template <typename T>
const std::list<T>& Grafo<T>::obtenerListaAdyacencia(T v) const {
    return listaAdyacencia[v];
}

#endif
