//
//  tad_arboles.hxx
//  
//
//  Created by Laura Juliana Mora on 19/09/17.
//
//

#include"tad_arboles.h"
#include<list>
#include<iostream>
//NODO BINARIO

template<class T>
NodoBinario<T>::NodoBinario(T val){
	dato=val;
    hijoDer=NULL;
    hijoIzq=NULL;
}

template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq){
    hijoIzq=izq;
}

template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der){
    hijoDer=der;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq(){
    return hijoIzq;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer(){
    return hijoDer;
}

template<class T>
void NodoBinario<T>::fijarDato(T& val){
    dato=val;
}

template<class T>
T& NodoBinario<T>::obtenerDato(){
    return dato;
}

//ÁRBOL BINARIO

template<class T>
arbolBi<T>::arbolBi(){
    raiz=NULL;
}

template<class T>
bool arbolBi<T>::esVacio(){
    return(raiz==NULL);
}

template<class T>
T& arbolBi<T>::datoRaiz(){
    return raiz->dato;
}
template<class T>
int arbolBi<T>::altura(NodoBinario<T> *inicio){
    int mayor=0;
    int der=0;
    int izq=0;
    
    if(inicio->obtenerHijoDer()==NULL&&inicio->obtenerHijoIzq()==NULL){
        return 1;
    }else{
    
        if(inicio->obtenerHijoDer()!=NULL){
            der = this->altura(inicio->obtenerHijoDer());
        }
        if(inicio->obtenerHijoIzq()!=NULL){
            izq= this->altura(inicio->obtenerHijoIzq());
        }
    }
    if (der < izq){
        mayor = izq;
    }else{
        mayor = der;
    }
    
    return mayor + 1;
    
}

template<class T>
int arbolBi<T>::tamano(NodoBinario<T> *inicio){
    int cant=1;
    if(inicio->obtenerHijoDer()==NULL&&inicio->obtenerHijoIzq()==NULL){
        return 1;
    }else{
        if(inicio->obtenerHijoIzq()!=NULL){
            cant += tamano(inicio->obtenerHijoIzq());
        }
        if(inicio->obtenerHijoDer()!=NULL){
            cant += tamano(inicio->obtenerHijoDer());
        }
        return cant;
    }
}

template<class T>
bool arbolBi<T>::insertarIzq(T& val,NodoBinario<T> *padre){
    NodoBinario<T> *aux=new NodoBinario<T>(val);
    padre->fijarHijoIzq(aux);
    //std::cout<<"Papa: "<<padre->obtenerDato()<<"hijo izq: "<<aux->obtenerDato()<<"\n";
    return true;
}

template<class T>
bool arbolBi<T>::insertarDer(T& val,NodoBinario<T> *padre){
    NodoBinario<T> *aux=new NodoBinario<T>(val);
    padre->fijarHijoDer(aux);
    //std::cout<<"Papa: "<<padre->obtenerDato()<<"hijo der: "<<aux->obtenerDato()<<"\n";
    return true;
}
template<class T>
bool arbolBi<T>::insertarRaiz(T val){
    this->raiz=new NodoBinario<T>(val);
    return true;
}
template<class T>
bool arbolBi<T>::insertar(T val,NodoBinario<T> *padre){
	if(val<padre->obtenerDato()){
        if(padre->obtenerHijoIzq()!=NULL){
            return insertar(val,padre->obtenerHijoIzq());
        }else{
            return insertarIzq(val,padre);
        }
    }else if(val>padre->obtenerDato()){
        if(padre->obtenerHijoDer()!=NULL){
            return insertar(val,padre->obtenerHijoDer());
        }else{
            return insertarDer(val,padre);
        }
    }else {
        return false;
    }
}

template<class T>
void arbolBi<T>::preOrden(NodoBinario<T> *inicio){
    std::cout<<inicio->obtenerDato()<<" ";
    
    if(inicio->obtenerHijoIzq()!=NULL){
        preOrden(inicio->obtenerHijoIzq());
    }
    
    if(inicio->obtenerHijoDer()!=NULL){
        preOrden(inicio->obtenerHijoDer());
    }
    
}

template<class T>
void arbolBi<T>::inOrden(NodoBinario<T> *inicio){
    
    if(inicio->obtenerHijoIzq()!=NULL){
        preOrden(inicio->obtenerHijoIzq());
    }
    std::cout<<inicio->obtenerDato()<<" ";
    if(inicio->obtenerHijoDer()!=NULL){
        preOrden(inicio->obtenerHijoDer());
    }
}

template<class T>
void arbolBi<T>::posOrden(NodoBinario<T> *inicio){
    if(inicio->obtenerHijoIzq()!=NULL){
        preOrden(inicio->obtenerHijoIzq());
    }
    
    if(inicio->obtenerHijoDer()!=NULL){
        preOrden(inicio->obtenerHijoDer());
    }
    std::cout<<inicio->obtenerDato()<<" ";
}


template<class T>
void arbolBi<T>::forNivelOrden(NodoBinario<T> *inicio){
    for(int i=0;i<tamano(inicio);i++){
        nivelOrden(i,inicio);
    }
}

template<class T>
void arbolBi<T>::nivelOrden(int nivel,NodoBinario<T> *inicio){
    if(nivel==0)
        std::cout<<inicio->obtenerDato();
    if(inicio->obtenerHijoIzq())
        nivelOrden(nivel-1,inicio->obtenerHijoIzq());
    if(inicio->obtenerHijoDer())
        nivelOrden(nivel-1,inicio->obtenerHijoDer());
}

template<class T>
bool arbolBi<T>::buscar(T& val,NodoBinario<T> *actual){
    NodoBinario<T> *aux=actual;
    while(aux!=NULL){
        if(val==aux->obtenerDato()){
            return true;
        }else if(val<aux->obtenerDato()){
            aux=aux->obtenerHijoIzq();
            return buscar(val,aux);
        }else if(val>aux->obtenerDato()){
            aux=aux->obtenerHijoDer();
            return buscar(val,aux());
        }
    }
    return false;
}

template<class T>
bool arbolBi<T>::eliminar(T& val){
    NodoBinario<T> *actual=raiz;
    NodoBinario<T> *padre;
    NodoBinario<T> *auxActual;
    T dato;
    bool hecho =false;
    while(actual!=NULL){
        if(val==actual->obtenerDato()){
            if(padre!=NULL){
                if(actual->obtenerHijoDer()==NULL&&actual->obtenerHijoIzq()==NULL){
                    if(padre->obtenerHijoDer()==actual){
                        padre->fijarHijoDer(NULL);
                    }else{
                        padre->fijarHijoIzq(NULL);
                    }
                    actual=NULL;
                    hecho=true;
                }
                
                else if(actual->obtenerHijoDer()!=NULL&&actual->obtenerHijoIzq()==NULL){
                    if(padre->obtenerHijoDer()==actual){
                        padre->fijarHijoDer(actual->obtenerHijoDer());
                    }else{
                        padre->fijarHijoIzq(actual->obtenerHijoIzq());
                    }
                    actual=NULL;
                    hecho=true;

                }else if(actual->obtenerHijoDer()==NULL&&actual->obtenerHijoIzq()!=NULL){
                    if(padre->obtenerHijoDer()==actual){
                        padre->fijarHijoDer(actual->obtenerHijoIzq());
                    }else{
                        padre->fijarHijoIzq(actual->obtenerHijoIzq());
                    }
                    actual=NULL;
                    hecho=true;

                }else{
                    auxActual=actual->obtenerHijoIzq();
                    while(auxActual->obtenerHijoDer()){
                        padre=auxActual;
                        auxActual=auxActual->obtenerHijoDer();
                    }
                    dato=actual->obtenerDato();
                    actual->fijarDato(auxActual->obtenerDato());
                    padre->fijarHijoDer(NULL);
                    actual=padre->obtenerHijoDer();
                    hecho=true;

                }
                
            }
        }else{
            padre=actual;
            if(val>actual->obtenerDato()){
                actual=actual->obtenerHijoDer();
            }
            else if(val<actual->obtenerDato()){
                actual=actual->obtenerHijoIzq();
            }
        }
    }
    return hecho;
}

template<class T>
NodoBinario<T> * arbolBi<T>::obtenerRaiz(){
    return raiz;
}
