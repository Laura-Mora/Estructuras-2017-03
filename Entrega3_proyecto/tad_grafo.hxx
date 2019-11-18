//
//  tad_grafo.hxx
//
//
//  Created by Laura Juliana Mora on 25/10/17.
//

#include "tad_grafo.h"
#include <list>
#include <iostream>
#include <vector>
#include <queue>

//Utils
std::string itoa(float num)
{
    std::ostringstream sin;
    sin << num;
    std::string val = sin.str();
    return val;
}
//slitU

//nodoGrafo
template <class T>
nodoGrafo<T>:: nodoGrafo()
{
    yaPase=false;
}

template <class T>
nodoGrafo<T>:: nodoGrafo(T datoNuevo, int indi)
{
    dato=datoNuevo;
    yaPase=false;
    indice=indi;

}

template <class T>
void nodoGrafo<T>:: insertarDato(T datoNuevo)
{
    dato=datoNuevo;
}

template <class T>
T nodoGrafo<T>::obtenerDato()
{
    return dato;
}

template <class T>
std::list<vecino<nodoGrafo<T>* > > nodoGrafo<T>::obtenerVecinos()
{
    return vecinos;
}

template <class T>
void nodoGrafo<T>::insertarVecino(vecino<nodoGrafo<T>* > nodo)
{
    vecinos.push_back(nodo);
}
template <class T>
typename std::list<vecino<nodoGrafo<T>* > >::iterator nodoGrafo<T>::buscarVecino(nodoGrafo<T>* veci)
{
    typename std::list<vecino<nodoGrafo<T>* > >::iterator it=vecinos.begin();
    for(; it!=vecinos.end(); it++)
    {
        if(veci==it->obtenerDato())
        {
            return it;
        }
    }
    return it;
}

template <class T>
bool nodoGrafo<T>::yaPaso()
{
    return yaPase;
}

template <class T>
void nodoGrafo<T>::fijarYaPase(bool estado)
{
    yaPase=estado;
}

template <class T>
int nodoGrafo<T>::obtenerIndice()
{
    return indice;
}

template <class T>
void nodoGrafo<T>::fijarIndice(int i)
{
    indice=i;
}

template <class T>
void nodoGrafo<T>::eliminarVecino(nodoGrafo<T>* nodo)
{
    typename std::list<vecino<nodoGrafo<T>* > >::iterador it=buscarVecino(nodo);
    if(it!=vecinos.end())
        vecinos.erase(it);
}

template <class T>
int nodoGrafo<T>::cantVecinos()
{
    return vecinos.size();
}

template <class T>
bool nodoGrafo<T>::vecinosVisitados()
{
    typename std::list<vecino<nodoGrafo<T>* > >::iterador it=vecinos.begin();
    bool esta=true;
    for(; it!=vecinos.begin()&&esta; it++)
    {
        if(!(*it).obtenerDato()->yaPaso())
        {
            esta=false;
        }
    }
    return esta;
}

template <class T>
std::string nodoGrafo<T>::profundidad()
{
    std::string retorno=itoa(indice);
    retorno=retorno+" ";
    yaPase=true;
    if(vecinos.empty()||!vecinosVisitados())
    {
        return retorno;
    }
    else
    {
        typename std::list<vecino<nodoGrafo<T>*> >:: iterador it=vecinos.begin();
        for(; it!=vecinos.end(); it++)
        {
            retorno+=it->obtenerDato()->profundidad();
        }
        return retorno ;
    }
}

template <class T>
std::string nodoGrafo<T>::anchura()
{
    std::string retorno=" ";
    yaPase=true;
    if(vecinos.empty()||!vecinosVisitados())
    {
        retorno=itoa(indice);
        return retorno;
    }
    else
    {
        typename std::list<vecino<nodoGrafo<T>*> >:: iterador it=vecinos.begin();
        for(; it!=vecinos.end(); it++)
        {
            retorno+=it->obtenerDato()->profundidad();
        }
        return retorno ;
    }
}
template <class T>
vecino<nodoGrafo<T>*> nodoGrafo<T>::menorVecino()
{
    vecino<nodoGrafo<T>*> veci=*(new vecino<nodoGrafo<T>*>(NULL,0));
    typename std::list<vecino<nodoGrafo<T>* > >::iterator it=vecinos.begin();
    float menor=it->obtenerPrecio();

    for(; it!=vecinos.end(); it++)
    {
        if(menor>=it->obtenerPrecio()&&it->obtenerDato()->yaPaso()==false)
        {
            menor=it->obtenerPrecio();
            veci=(*it);
        }
    }
    return veci;
}
//ofarGodon

//vecino
template <class T>
vecino<T>::vecino()
{
    dato=NULL;
}
template <class T>
vecino<T>::vecino(T nuevo,float costo)
{
    dato=nuevo;
    precio=costo;
}

template <class T>
void vecino<T>:: insertarDato(T nuevo)
{
    dato=nuevo;
}

template <class T>
T vecino<T>::obtenerDato()
{
    return dato;
}

template <class T>
void vecino<T>::fijarPrecio(float nuevo)
{
    precio=nuevo;
}

template <class T>
float vecino<T>::obtenerPrecio()
{
    return precio;
}
//oniceV
//Grafo
template <class T>
grafo<T>::grafo()
{
    cantVer=0;
}

template <class T>
grafo<T>::grafo(bool direc)
{
    cantVer=0;
    dirigido=direc;
}
//insertar vertice
template <class T>
void grafo<T>::insertarNuevoNodo(nodoGrafo<T> nuevo)
{
    nuevo.fijarIndice(cantVer);
    g.insert(std::pair<int,nodoGrafo<T> >(cantVer,nuevo));
    cantVer++;
}
//buscar vertice
template <class T>
nodoGrafo<T>* grafo<T>::buscarNodoGrafo(int indice)
{
    typename std::map<int,nodoGrafo<T> >::iterator it;
    it=g.find(indice);
    if(it==g.end())
    {
        return NULL;
    }
    return &(it->second);
}

//insertar arista
template <class T>
void grafo<T>::insertarVecino(int indiceA, int indiceB, float peso)
{
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    nodoGrafo<T>* b=buscarNodoGrafo(indiceB);
    if(a!=NULL&&b!=NULL)
    {
        typename std::list<vecino<nodoGrafo<T>*> >::iterator it=a->buscarVecino(b);
        // if(it==a->obtenerVecinos().end())
        // {
        vecino<nodoGrafo<T>*> veci;
        veci.fijarPrecio(peso);
        veci.insertarDato(b);
        a->insertarVecino(veci);
        // }

        /*if(!dirigido)
        {
            typename std::list<vecino<nodoGrafo<T>*> >::iterator itB=b->buscarVecino(a);
            //if(itB==b->obtenerVecinos().end())
            //{
                vecino<nodoGrafo<T>*> veci;
                veci.fijarPrecio(peso);
                veci.insertarDato(a);
                b->insertarVecino(veci);
            //}
        }*/
    }
}

//buscar arista
template <class T>
bool grafo<T>::buscarArista(int indiceA, int indiceB)
{
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    nodoGrafo<T>* b=buscarNodoGrafo(indiceB);
    if(a!=NULL&&b!=NULL)
    {
        typename std::list<vecino<nodoGrafo<T>*> >::iterator it=a->buscarVecino(b);
        if(it!=a->obtenerVecinos().end())
        {
            return true;
        }
    }
    return false;
}
//número Vertices
template <class T>
int grafo<T>::numeroVertices()
{
    return cantVer;
}

//eliminar arista
template <class T>
void grafo<T>::eliminarArista(int indiceA, int indiceB)
{
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    nodoGrafo<T>* b=buscarNodoGrafo(indiceB);
    if(a!=NULL&&b!=NULL)
    {
        a->eliminarVecino(b);
        if(!dirigido)
        {
            b->eliminarVecino(a);
        }
    }
}
//eliminar verice
template <class T>
void grafo<T>::eliminarVertice(int indiceA)
{
    nodoGrafo<T>* a=buscarNodoGrafo(indiceA);
    if(a!=NULL)
    {
        typename std::map<int,nodoGrafo<T> >:: iterator it=g.begin();
        for(; it!=g.end(); it++)
        {
            it->second.eliminarVecino(a);
        }
        g.erase(indiceA);

    }
}

//numero aristas
template <class T>
long grafo<T>::numeroAristas()
{
    typename std::map<int,nodoGrafo<T> >:: iterator it=g.begin();
    long cant=0;
    for(; it!=g.end(); it++)
    {
        cant+=it->second.cantVecinos();
    }
    return cant;
}

//imprimir
template <class T>
void grafo<T>::imprimir()
{
    std::cout<<"Listado vertices:\n";
    typename std::map<int,nodoGrafo<T> > :: iterator it=g.begin();
    for(; it!=g.end(); it++)
    {
        std::cout<<it->first<<" ";
    }
    std::cout<<"Listado aristas:\n";
    for(it=g.begin(); it!=g.end(); it++)
    {
        typename std::list<vecino<nodoGrafo<T>*> >:: iterator itL=it->second.obtenerVecinos().begin();
        for(; itL!=it->second.obtenerVecinos().end(); itL++)
        {
            typename std::map<int,nodoGrafo<T> >:: iterator it2=g.begin();
            for(; it2!=g.end(); it2++)
            {
                if(itL->obtenerDato()==(&(it2->second)))
                {
                    std::cout<<"("<<it->first<<","<<it2->first<<") ";
                }
            }
            std::cout<<"\n";
        }

    }
}

//recorrido plano
template<class T>
void grafo<T>::plano()
{
    typename std::map<int,nodoGrafo<T> >:: iterator it=g.begin();
    for(; it!=g.end(); it++)
    {
        std::cout<<it->first<<" ";
    }
}

//recorrido profundidad
template<class T>
void grafo<T>::profundidad(int indice)
{
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    if(nodo)
    {
        std::cout<<nodo->profundidad();
    }
}

template <class T>
void grafo<T>::anchura(int indice)
{
    std::queue<nodoGrafo<T>*> cola;
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    if(nodo)
    {
        cola.push(nodo);
        while(!cola.empty())
        {
            std::cout << cola.front()->obtenerIndice() << " ";
            cola.front()->fijarYaPase(true);
            typename std::list<vecino<nodoGrafo<T>*> > vecinos=cola.front()->obtenerVecinos();
            typename std::list<vecino<nodoGrafo<T>*> >::iterador lIt=vecinos.begin();
            for(; lIt!=vecinos.end(); lIt++)
            {
                if(!lIt->obtenerDato()->yaPaso())
                {
                    cola.push(lIt->obtenerDato());
                    lIt->obtenerDato()->fijarYaPase(true);
                }
            }
            cola.pop();
        }
    }
}

//prim .|||.
template <class T>
void grafo<T>::prim(int indice)
{
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    nodoGrafo<T> origen;
    std::list<nodoGrafo<T>*> lista;
    std::list<nodoGrafo<T> > aristas;
    if(nodo)
    {
        lista.push_back(nodo);
        vecino<nodoGrafo<T>*> veci=nodo->menorVecino();
        nodo->fijarYaPase(true);
        origen=(*nodo);
        while(veci.obtenerDato())
        {
            lista.push_back(veci.obtenerDato());
            origen.insertarVecino(veci);
            aristas.push_back(origen);
            origen=*(veci.obtenerDato());
            veci=veci.obtenerDato()->menorVecino();
            vecino<nodoGrafo<T>*> auxv;
            typename std::list<nodoGrafo<T>*>::iterator lIt=lista.begin();
            for(; lIt!=lista.end(); lIt++)
            {
                auxv=(*lIt)->menorVecino();
                if(auxv.obtenerDato())
                {
                    if(!veci.obtenerDato())
                    {
                        veci=auxv;
                        origen=(*(*lIt));
                    }
                    else
                    {
                        if(auxv.obtenerPrecio()<veci.obtenerPrecio())
                        {
                            veci=auxv;
                            origen=(*(*lIt));
                        }
                    }
                }
            }
        }
    }

    std::cout<<"Distancia segun Prim, vertice "<<indice<<": ";
    typename std::list<nodoGrafo<T> >::iterador itL=aristas.begin();
    for(; itL!=aristas.end(); itL++)
    {
        std::cout<<itL->obtenerIndice()<<"- ";
    }
}
template <class T>
void grafo<T>::primGeneral()
{

    typename std::map<int,nodoGrafo<T> >::iterator it=g.begin();
    for(; it!=g.end(); it++)
    {
        prim(it->first);
    }

}
//Dijkstra
template <class T>
std::string grafo<T>::dijkstra(int indice, int fin)
{
    std::string camino="";
    std::vector<nodoGrafo<T> > retorno;
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    float precioI=0;

    std::list<nodoGrafo<T>*> lista;
    std::queue<nodoGrafo<T>*> prioridad;
    nodoGrafo<T>* nodo2;
    float valores [cantVer];
    int predecesores[cantVer];



    for(int i=0; i<cantVer; i++)
    {
        predecesores[i]=-1;
        valores[i]=999999;
    }
    if(nodo)
    {
        int indice=nodo->obtenerIndice();
        valores[indice]=0;
        prioridad.push(nodo);
        bool esVecino=false;
        predecesores[0]=0;
        while(!prioridad.empty()&&indice!=fin)
        {

            do
            {
                nodo2=prioridad.front();
                prioridad.pop();
                indice=nodo2->obtenerIndice();


            }
            while(nodo2->yaPaso()==true&&!prioridad.empty());

            std::list<vecino<nodoGrafo<T>*> > listaaux=nodo2->obtenerVecinos();
            typename std::list<vecino<nodoGrafo<T>*> >::iterator itV=listaaux.begin();
            for(; itV!=listaaux.end()&&esVecino==false; itV++)
            {

                if(itV->obtenerDato()->obtenerIndice()==fin)
                {
                    while(!prioridad.empty())
                    {
                        prioridad.pop();
                    }
                    esVecino=true;
                    prioridad.push(itV->obtenerDato());
                    predecesores[itV->obtenerDato()->obtenerIndice()]=nodo2->obtenerIndice();

                }
            }

            if(!esVecino)
            {

                itV=listaaux.begin();
                for (; itV!=listaaux.end(); itV++)
                {
                    precioI=valores[indice];
                    float precioAux=precioI+itV->obtenerPrecio();

                    int i=itV->obtenerDato()->obtenerIndice();
                    if(valores[i]>precioAux)
                    {
                        predecesores[indice]=nodo->obtenerIndice();
                        valores[i]=precioAux;
                        prioridad.push(itV->obtenerDato());
                    }
                }
            }
            lista.push_back(nodo2);
            nodo2->fijarYaPase(true);
            nodo=nodo2;
        }

        typename std::list<nodoGrafo<T>*>::iterator itL=lista.begin();
        for(; itL!=lista.end(); itL++)
        {
            bool esta=false;
            for(int i=0; i<cantVer&&esta==false; i++)
            {
                if((*itL)->obtenerIndice()==predecesores[i])
                {
                    esta=true;
                }
            }
            if(esta||(*itL)->obtenerIndice()==fin)
            {
                camino=camino+itoa((*itL)->obtenerIndice())+",";
            }

        }
        std::string::iterator sIt=camino.end();
        sIt--;
        camino.erase(sIt);
    }
    return camino;
}
template <class T>
std::string grafo<T>:: dijkstraGeneral()
{
    typename std::map<int,nodoGrafo<T> >::iterator it=g.begin();
    it++;
    std::string retorno="";
    for(; it!=g.end(); it++)
    {
        retorno=retorno+dijkstra(0,it->first)+"\n";
    }
    return retorno;
}
template <class T>
std::string grafo<T>:: dijkstraTotal(int indice)
{
    std::string camino="";
    std::vector<nodoGrafo<T> > retorno;
    nodoGrafo<T>* nodo=buscarNodoGrafo(indice);
    float precioI=0;
    std::list<nodoGrafo<T>*> lista;
    std::queue<nodoGrafo<T>*> prioridad;
    nodoGrafo<T>* nodo2;
    float valores [cantVer];
    int predecesores[cantVer];

    for(int i=0; i<cantVer; i++)
    {
        valores[i]=999999;
    }
    if(nodo)
    {
        int indice=nodo->obtenerIndice();
        valores[indice]=0;
        prioridad.push(nodo);
        predecesores[0]=0;
        while(!prioridad.empty())
        {

            do
            {
                nodo2=prioridad.front();
                prioridad.pop();

            }
            while(nodo2->yaPaso()==true&&!prioridad.empty());

            std::list<vecino<nodoGrafo<T>*> > listaaux=nodo2->obtenerVecinos();
            typename std::list<vecino<nodoGrafo<T>*> >::iterator itV=listaaux.begin();
            for (; itV!=listaaux.end(); itV++)
            {
                indice=nodo2->obtenerIndice();
                precioI=valores[indice];
                float precioAux=precioI+itV->obtenerPrecio();

                int i=itV->obtenerDato()->obtenerIndice();
                if(valores[i]>precioAux)
                {
                    predecesores[indice]=nodo->obtenerIndice();
                    valores[i]=precioAux;
                    prioridad.push(itV->obtenerDato());
                }
            }
            lista.push_back(nodo2);
            nodo=nodo2;
        }

        typename std::list<nodoGrafo<T>*>::iterator itL=lista.begin();

        for(; itL!=lista.end(); itL++)
        {

            camino=camino+itoa((*itL)->obtenerIndice())+",";
        }
        std::string::iterator sIt=camino.end();
        sIt--;
        camino.erase(sIt);
    }
    return camino;
}
//ofarG
