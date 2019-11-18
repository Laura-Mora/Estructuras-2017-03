//
//  tad_arboles.h
//  
//
//  Created by Laura Juliana Mora on 16/09/17.
//
//

#ifndef tad_arboles_h
#define tad_arboles_h
#include <list>
template <class T>
class NodoBinario{
    private:
        T dato;
        NodoBinario<T> *hijoDer;
        NodoBinario<T> *hijoIzq;
    
    public:
		NodoBinario(T val);
        T& obtenerDato();
        void fijarDato(T& val);
        NodoBinario<T>* obtenerHijoIzq();
        NodoBinario<T>* obtenerHijoDer();
        void fijarHijoIzq(NodoBinario<T> *izq);
        void fijarHijoDer(NodoBinario<T> *der);
};

template <class T>
class arbolBi{
    private:
        NodoBinario<T> *raiz;
    public:
        arbolBi();
        bool esVacio();
        T& datoRaiz();
        int altura(NodoBinario<T> *inicio); //ya
        int tamano(NodoBinario<T> *inicio); //ya
        bool insertarIzq(T& val,NodoBinario<T> *padre); //ya
        bool insertarDer(T& val,NodoBinario<T> *padre); //ya
        bool eliminar(T& val);//ya
        bool buscar(T& val,NodoBinario<T> *actual); //ya
        void preOrden(NodoBinario<T> *inicio); //ya
        void inOrden(NodoBinario<T> *inicio); //ya
        void posOrden(NodoBinario<T> *inicio); //ya
        void nivelOrden(int nivel,NodoBinario<T> *inicio); //ya
  		void forNivelOrden(NodoBinario<T> *inicio); //ya
        bool insertarRaiz(T val);
        bool insertar(T val,NodoBinario<T> *padre); //ya
        NodoBinario<T> *obtenerRaiz();
};

#include "tad_arboles.hxx"

#endif /* tad_arboles_h */
