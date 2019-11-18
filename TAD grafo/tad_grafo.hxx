//
//  tad_grafo.hxx
//  
//
//  Created by Laura Juliana Mora on 25/10/17.
//

#include "tad_grafo.h"
#include <list>
#include <iostream>

//nodoGrafo
nodoGrafo:: nodoGrafo(){
    yaPase=false;
    vecinos=new std::list<vecinos<T>>();
}

template <class T>
nodoGrafo:: nodoGrafo(T datoNuevo, int indi){
    dato=datoNuevo;
    yaPase=false;
    indice=indi;
    
}

template <class T>
void nodoGrafo:: insertarDato(T datoNuevo){
    dato=datoNuevo;
}

template <class T>
T nodoGrafo::obtenerDato(){
    return dato;
}

template <class T>
std::list<vecino<T>> nodoGrafo::obtenerVecinos(){
    return vecinos;
}

template <class T>
void nodoGrafo::insertarVecino(vecino<T> nodo){
    vecinos.push(nodo);
}
template <class T>
std::list<vecino>::iterator nodoGrafo::buscarVecino(nodoGrafo<T>* veci){
    std::list<vecino>::iterador it=vecinos.begin();
    for(;it!=vecinos.end();it++){
        if(veci==it->obtenerDato()){
            return it;
        }
    }
    return it;
}

bool nodoGrafo::yaPaso(){
    return yaPaso;
}

void fijarYaPase(bool estado){
    yaPaso=estado;
}

int obtenerIndice(){
    return indice;
}
void fijarIndice(int i){
    indice=i;
}

void nodoGrafo::eliminarVecino(nodoGrafo<T>* nodo){
    std::list<vecino>::iterador it=buscarVecino(nodo);
    if(it!=vecinos.end())
        vecinos.erase(it);
}

int nodoGrafo::cantVecinos(){
    return vecinos.size();
}

bool nodoGrafo::vecinosVisitados(){
    std::list<vecino>::iterador it=vecinos.begin();
    bool esta=true;
    for(;it!=vecinos.begin()&&esta;it++){
        if(!(*it).obtenerDato()->yaPaso()){
            esta=false;
        }
    }
    return esta;
}

std::string nodoGrafo::profundidad(){
    std::string retorno=itoa(indice)+" ";
    yaPaso=true;
    if(vecinos.empty()||!vecinosVisitados()){
        return retorno;
    }else{
        std::list<vecino>:: iterador it=vecinos.begin();
        for(;it!=vecinos.end();it++){
            retorno+=it->obtenerDato()->profundidad();
        }
        return retorno ;
    }
}

std::string nodoGrafo::anchura(){
    std::string retorno=" ";
    yaPaso=true;
    if(vecinos.empty()||!vecinosVisitados()){
        return itoa(indice);
    }else{
        std::list<vecino>:: iterador it=vecinos.begin();
        for(;it!=vecinos.end();it++){
            retorno+=it->obtenerDato()->profundidad();
        }
        return retorno ;
    }
}
template <class T>
vecino nodoGrafo<T>::menorVecino(){
    vecino veci=*(new vecino(NULL,0));
    std::list<vecino>::iterator it=vecinos.begin();
    float menor=it->obtenerPrecio();
    
    for(;it!=vecinos.end();it++){
        if(menor>=it->obtenerPrecio()&&it->obtenerDato()->yaPaso()==false){
            menor=it->obtenerPrecio();
            veci=(*it);
        }
    }
    return veci;
}
//ofarGodon

//vecino
template <class T>
vecino::vecino(nodoGrafo<T>*nuevo,float costo){
    dato=nuevo;
    precio=costo;
}

template <class T>
void vecino:: insertarDato(nodoGrafo<T> nuevo){
    dato=nuevo;
}

template <class T>
nodoGrafo<T>* vecino::obtenerDato(){
    return dato;
}

template <class T>
void vecino::fijarPrecio(float nuevo){
    precio=nuevo;
}

template <class T>
float vecino::obtenerPrecio(){
    return precio;
}
//oniceV
//Grafo

template <class T>
grafo::grafo(bool direc){
    cantVer=0;
    dirigido=direc;
}
//insertar vertice
template <class T>
void grafo::insertarNuevoNodo(nodoGrafo<T> nuevo){
    nuevo->fijarIndice(cantVer);
    g.insert(std::pair<int,nodoGrafo<T>>(cantVer,nuevo));
    cantVer++;
}
//buscar vertice
template <class T>
nodoGrafo<T>* grafo::buscarNodoGrafo(int indice){
    std::map<int,nodoGrafo<T>>::iterator it;
    it=g.find(indice);
    if(it==g.end()){
        return NULL;
    }
    return &(it->second);
}

//insertar arista
template <class T>
void grafo::insertarVecino(int indiceA, int indiceB, float peso){
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    nodoGrafo<T>* b=buscarNodoGrafo(indiceB);
    if(a!=NULL&&b!=NULL){
        std::list<vecino>::iterator it=a->buscarVecino(b);
        if(it==a->obtenerVecinos().end()){
            vecino veci=*(new vecino(b,peso));
            a->insertarVecino(veci);
        }
        
        if(!dirigido){
            std::list<vecino>::iterator itB=b->buscarVecino(a);
            if(itB==b->obtenerVecinos().end()){
                vecino veci=*(new vecino(a,peso));
                b->insertarVecino(veci);
            }
        }
    }
}

//buscar arista
template <class T>
bool grafo::buscarArista(int indiceA, int indiceB){
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    nodoGrafo<T>* b=buscarNodoGrafo(indiceB);
    if(a!=NULL&&b!=NULL){
        std::list<vecino>::iterator it=a->buscarVecino(b);
        if(it!=a->obtenerVecinos().end()){
            return true;
        }
    }
    return false;
}
//número Vertices
int grafo::numeroVertices(){
    return cantVer;
}

//eliminar arista
template <class T>
void grafo::eliminarArista(int indiceA, int indiceB){
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    nodoGrafo<T>* b=buscarNodoGrafo(indiceB);
    if(a!=NULL&&b!=NULL){
        a->eliminarVecino(b);
        if(!dirigido){
            b->eliminarVecino(a);
        }
    }
}
//eliminar verice
template <class T>
void grafo::eliminarVertice(int indiceA){
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    if(a!=NULL){
        std::map<int,nodoGrafo<T>>:: iterator it=g.begin();
        for(;it!=g.end();it++){
            it->second.eliminarVecino(a);
        }
        g.erase(indiceA);
        
    }
}

//numero aristas
long grafo::numeroAristas(){
    std::map<int,nodoGrafo<T>>:: iterator it=g.begin();
    long cant=0;
    for(;it!=g.end();it++){
        cant+=it->second.cantVecinos();
    }
    return cant;
}

//imprimir
void grafo::imprimir(){
    std::cout<<"Listado vertices:\n";
    std::map<int,nodoGrafo<T>>:: iterator it=g.begin();
    for(;it!=g.end();it++){
        std::cout<<it->first<<" ";
    }
    std::cout<<"Listado aristas:\n";
    for(it=g.begin();it!=g.end();it++){
        std::list<vecino> iterator itL=it->second.obtenerVecinos().begin();
        for(;itL!=it->second.obtenerVecinos().end();itL++){
            std::map<int,nodoGrafo<T>>:: iterator it2=g.begin();
            for(;it2!=g.end();it2++){
                if(itL->obtenerDato()==(&(it2->second))){
                    std::cout<<"("<<it->first<<","<<it2->first<<") ";
                }
            }
            std::cout<<"\n";
        }
        
    }
}

//recorrido plano
template<class T>
void grafo::plano(){
    std::map<int,nodoGrafo<T>>:: iterator it=g.begin();
    for(;it!=g.end();it++){
        std::cout<<it->first<<" ";
    }
}

//recorrido profundidad
template<class T>
void grafo::profundidad(int indice){
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    if(nodo){
            std::cout<<nodo->profundidad();
    }
}

template <class T>
void grafo::anchura(int indice){
    std::queue<odoGrafo<T>*> cola;
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    if(nodo){
        cola.push(nodo);
        while(!cola.empty()){
            std::cout << cola.front()->obtenerIndice() << " ";
            cola.front()->fijarYaPase(true);
            std::list<vecino> vecinos=cola.front()->obtenerVecinos();
            std::list<vecino>::iterador lIt=vecinos.begin();
            for(;lIt!=vecinos.end();lIt++){
                if(!lIt->obtenerDato()->yaPaso()){
                    cola.push(lIt->obtenerDato());
                    lIt->obtenerDato()->fijarYaPase(true);
                }
            }
            cola.pop();
        }
    }
}

int grafo::componentesConectado(nodoGrafo<T>* nodo){
    
}
//prim .|||.
template <class T>
std::list<nodoGrafo<T>> grafo::prim(int indice){
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    nodoGrafo<T> origen;
    std::list<nodoGrafo<T>*> lista;
    std::list<nodoGrafo<T>> aristas;
    if(nodo){
        lista.push(nodo);
        vecino veci=nodo->menorVecino();
        nodo->fijarYaPase(true);
        origen=(*nodo);
        while(veci.obtenerDato()){
            lista.push(veci.obtenerDato());
            origen.insertarVecino(veci);
            aristas.push(origen);
            origen=*(veci.obtenerDato());
            veci=veci.obtenerDato()->menorVecino();
            vecino auxv;
            std::list<nodoGrafo<T>*>::iterador lIt=lista.begin();
            for(;lIt!=lista.end();lIt++){
                auxv=(*lIt)->menorVecino();
                if(auxv.obtenerDato()){
                    if(!veci.obtenerDato()){
                        veci=auxv;
                        origen=(*(*lIt));
                    }
                    else{
                        if(auxv.obtenerPrecio()<veci.obtenerPrecio()){
                            veci=auxv;
                            origen=(*(*lIt));
                        }
                    }
                }
            }
        }
    }
    return aristas;
}

//Dijkstra
template <class T>
void grafo:: dijkstra(int indice){
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    float precioI=0;
    nodoGrafo<T> origen;
    std::list<nodoGrafo<T>*> lista;
    std::queue<nodoGrafo<T> menores;
    float valores [cantVer];
    int predecesores[cantVer];
    for(int i=0;i<cantVer;i++){
        valores[i]=99999999;
    }
    if(nodo){
        do{
            menores.push(*nodo);
            valores[nodo->obtenerIndice()]=precioI;
            list<vecino>::iterador it=nodo->obtenerVecinos().begin();
            for(;it!=nodo->obtenerVecinos().end();it++){
                float precioAux=precioI+(*it)->obtenerPrecio();
                int i=(*it)->obtenerDato()->obtenerIndice();
                if(valores[i]>precioAux){
                    predecesores[i]=nodo->obtenerIndice();
                    valores[i]=precioAux;
                }
            }
            float menor=9999999;
            for(int i=0;i<cantVer;i++){
                nodoGrafo<T>* nodoaux=buscarNodoGrafo(indice);
                if(menor>valores[i]&&nodo->yaPaso()==false){
                    menor=valores[i];
                    nodo=nodoaux;
                }
            }
            
            precioI=menor;
            
        }while (nodo);
    }
}
 //ofarG
