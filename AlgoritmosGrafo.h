#ifndef ALGORITMOSGRAFO_H
#define ALGORITMOSGRAFO_H

#include "Grafo.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <limits>
#include <set>

template <typename T>
void BFS(const Grafo<T>& grafo, T inicio) {
    std::vector<bool> visitado(grafo.tamano(), false);
    std::queue<T> cola;

    visitado[inicio] = true;
    cola.push(inicio);

    while (!cola.empty()) {
        T v = cola.front();
        cola.pop();
        std::cout << v << " ";

        for (auto adyacente : grafo.obtenerListaAdyacencia(v)) {
            if (!visitado[adyacente]) {
                visitado[adyacente] = true;
                cola.push(adyacente);
            }
        }
    }
    std::cout << std::endl;
}

template <typename T>
void DFS(const Grafo<T>& grafo, T inicio) {
    std::vector<bool> visitado(grafo.tamano(), false);
    std::stack<T> pila;

    pila.push(inicio);

    while (!pila.empty()) {
        T v = pila.top();
        pila.pop();

        if (!visitado[v]) {
            visitado[v] = true;
            std::cout << v << " ";

            for (auto adyacente : grafo.obtenerListaAdyacencia(v)) {
                if (!visitado[adyacente]) {
                    pila.push(adyacente);
                }
            }
        }
    }
    std::cout << std::endl;
}

template <typename T>
void Dijkstra(const Grafo<T>& grafo, T inicio) {
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist(grafo.tamano(), INF);
    std::set<std::pair<int, T>> setds;

    dist[inicio] = 0;
    setds.insert({0, inicio});

    while (!setds.empty()) {
        T u = setds.begin()->second;
        setds.erase(setds.begin());

        for (auto i : grafo.obtenerListaAdyacencia(u)) {
            int v = i;
            int peso = 1;

            if (dist[v] > dist[u] + peso) {
                if (dist[v] != INF)
                    setds.erase(setds.find({dist[v], v}));

                dist[v] = dist[u] + peso;
                setds.insert({dist[v], v});
            }
        }
    }

    for (int i = 0; i < dist.size(); ++i)
        std::cout << "Vértice " << i << " Distancia desde el origen " << dist[i] << std::endl;
}

#endif
