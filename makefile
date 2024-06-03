CXX = g++
CXXFLAGS = -std=c++11 -Wall
DEPS = ListaEnlazada.h Pila.h Cola.h ArbolBinario.h Grafo.h AlgoritmosOrdenamiento.h AlgoritmosGrafo.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f *.o main
