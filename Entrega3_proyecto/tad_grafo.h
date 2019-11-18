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
#include <vector>
#include <string>
#include <sstream>

template <class T>
class vecino
{
private:
    T dato;
    float precio;

public:
    vecino();
    vecino(T nuevo,float costo);
    void insertarDato(T nuevo);
    T obtenerDato();
    void fijarPrecio(float nuevo);
    float obtenerPrecio();
};

template <class T>
class nodoGrafo
{
public:
    nodoGrafo();
    nodoGrafo(T datoNuevo, int indi);
    void insertarDato(T datoNuevo);
    T obtenerDato();
    std::list<vecino<nodoGrafo<T>* > > obtenerVecinos();
    void FijarVecinos(std::list<vecino<nodoGrafo<T>* > > lista);
    void insertarVecino(vecino<nodoGrafo<T>* > nodo);
    bool yaPaso();
    void fijarYaPase(bool estado);
    typename std::list<vecino<nodoGrafo<T>* > >::iterator buscarVecino(nodoGrafo<T>* veci);
    void eliminarVecino(nodoGrafo<T>* nodo);
    int cantVecinos();
    std::string profundidad();
    int obtenerIndice();
    void fijarIndice(int i);
    bool vecinosVisitados();
    std::string anchura();
    vecino<nodoGrafo<T>*> menorVecino(); //RETORNA SI TODOS LOS VECINOS YA FUERON VISITADOS
private:
    T dato;
    std::list<vecino<nodoGrafo<T>* > > vecinos;
    bool yaPase;
    int indice;
};

template <class T>
class grafo
{
private:
    std::map<int,nodoGrafo<T> > g;
    int cantVer;
    bool dirigido;
public:
    grafo();
    grafo(bool direc);
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
    std::string dijkstra(int indice, int fin);
    void prim(int indice);
    void primGeneral();
    std::string dijkstraGeneral();
    std::string dijkstraTotal(int indice);
};


#include "tad_grafo.hxx"
#endif /* tad_grafo_h */
