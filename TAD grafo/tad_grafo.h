//
//  tad_grafo.h
//  
//
//  Created by Laura Juliana Mora on 25/10/17.
//

#ifndef tad_grafo_h
#define tad_grafo_h

#include <list>
#include <map>
template <class T>
class nodoGrafo{
    private:
        T dato;
        std::list<vecino> vecinos;
        bool yaPase;
        int indice;
    public:
        nodoGrafo();
        nodoGrafo(T datoNuevo, int indi);
        void insertarDato(T datoNuevo);
        T obtenerDato();
        std::list<vecino<T>> obtenerVecinos();
        void insertarVecino(vecino<T> nodo);
        bool yaPaso();
        void fijarYaPase(bool estado);
        std::list<vecino>::iterator buscarVecino(nodoGrafo<T>* veci);
        void eliminarVecino(nodoGrafo<T>* nodo);
        int cantVecinos();
        std::string profundidad();
        int obtenerIndice();
        void fijarIndice(int i);
        bool vecinosVisitados(); //RETORNA SI TODOS LOS VECINOS YA FUERON VISITADOS
};

template <class T>
class vecino{
    private:
        nodoGrafo<T> *dato;
        float precio;
    
    public:
        vecino();
        vecino(nodoGrafo<T>*nuevo,float costo);
        void insertarDato(nodoGrafo<T> nuevo);
        nodoGrafo<T>* obtenerDato();
        void fijarPrecio(float nuevo);
        float obtenerPrecio();
};

template <class T>
class grafo{
    private:
        std::map<int,nodoGrafo<T>> g;
        int cantVer;
        bool dirigido;
    public:
        grafo();
        void insertarNuevoNodo(nodoGrafo<T> nuevo);
        nodoGrafo<T>* buscarNodoGrafo(int indice);
        void insertarVecino(int indiceA, int indiceB, float peso);
        bool buscarArista(int indiceA, int indiceB);
        int numeroVertices();
        void eliminarArista(int indiceA, int indiceB);
        void eliminarVertice(int indiceA);
        long numeroAristas();
        void imprimir();
        void plano();
        void profundidad(int indice);
        void anchura(int indice);
};

#include "tad_grafo.hxx"
#endif /* tad_grafo_h */
