#include <iostream>
#include "ListaEnlazada.h"
#include "Pila.h"
#include "Cola.h"
#include "ArbolBinario.h"
#include "Grafo.h"
#include "AlgoritmosOrdenamiento.h"
#include "AlgoritmosGrafo.h"

int main() {
    // Ejemplo de uso de lista enlazada
    ListaEnlazada<int> lista;
    lista.insertarAlFinal(10);
    lista.insertarAlFinal(20);
    lista.insertarAlFinal(30);
    lista.mostrar();

    // Ejemplo de uso de pila
    Pila<int> pila;
    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);
    while (!pila.estaVacia()) {
        std::cout << "Pila desapilar: " << pila.desapilar() << std::endl;
    }

    // Ejemplo de uso de cola
    Cola<int> cola;
    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);
    while (!cola.estaVacia()) {
        std::cout << "Cola desencolar: " << cola.desencolar() << std::endl;
    }

    // Ejemplo de uso de árbol binario
    ArbolBinario<int> arbol;
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(5);
    arbol.recorridoInOrden();

    // Ejemplo de uso de grafos y algoritmos
    Grafo<int> grafo;
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(2, 0);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 3);

    BFS(grafo, 2);
    DFS(grafo, 2);
    Dijkstra(grafo, 0);

    // Algoritmos de ordenamiento
    int arr[] = {12, 11, 13, 5, 6, 7};
    int tamano = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, tamano - 1);
    std::cout << "Array ordenado (QuickSort): \n";
    imprimirArray(arr, tamano);

    return 0;
}
