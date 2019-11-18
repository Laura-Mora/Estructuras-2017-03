//
//  Main_proyecto.hpp
//
//
//  Created by Laura Juliana Mora on 26/08/17.
//
//

#include "Header.h"

#include "tad_grafo.h"
#include <iostream>
#include <stdio.h>
#include <list>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <queue>
#include <sstream>
#include <math.h>

//Utils

std::queue<std::string> Tokenizar(std::string linea,char separador)
{
    std::queue<std::string> palabras;
    std::istringstream tok(linea);
    std::string aux;
    while(std::getline(tok,aux,separador))
    {
        palabras.push(aux);
    }
    return palabras;
}

double distanciaVertices(Vertice origen, Vertice destino)
{
    double distancia, xf, yf, zf;
    xf=pow(origen.ObtenerCoorX() - destino.ObtenerCoorX(),2);
    yf=pow(origen.ObtenerCoorY() - destino.ObtenerCoorY(),2);
    zf=pow(origen.ObtenerCoorZ() - destino.ObtenerCoorZ(),2);
    distancia=sqrt(xf+yf+zf);
    return distancia;
}

//slitU

//Vertice
Vertice::Vertice()
{
    coordX=0.0;
    coordY=0.0;
    coordZ=0.0;
}

Vertice::Vertice(float x,float y,float z)
{
    coordX=x;
    coordY=y;
    coordZ=z;
}

float Vertice::ObtenerCoorX()
{
    return coordX;
}

void Vertice::FijarCoorX(float x)
{
    coordX=x;
}

float Vertice::ObtenerCoorY()
{
    return coordY;
}

void Vertice::FijarCoorY(float y)
{
    coordY=y;
}

float Vertice::ObtenerCoorZ()
{
    return coordZ;
}

void Vertice::FijarCoorZ(float z)
{
    coordZ=z;
}

//ecitreV

//NodoCTP

NodoCTP::NodoCTP()
{
    indice=0;
    hijo1=NULL;
    hijo2=NULL;
    hijo3=NULL;
    hijo4=NULL;
    hijo5=NULL;
    hijo6=NULL;
    hijo7=NULL;
    hijo8=NULL;
}

NodoCTP::NodoCTP(Vertice dat)
{
    dato=dat;
    indice=0;
    hijo1=NULL;
    hijo2=NULL;
    hijo3=NULL;
    hijo4=NULL;
    hijo5=NULL;
    hijo6=NULL;
    hijo7=NULL;
    hijo8=NULL;
}

void NodoCTP::fijarDato(Vertice dat)
{
    dato=dat;
}

Vertice NodoCTP::obtenerDato()
{
    return dato;
}

void NodoCTP::fijarIndice(int ind)
{
    indice=ind;
}

int NodoCTP::obtenerIndice()
{
    return indice;
}

void NodoCTP::fijarHijo1(NodoCTP* hijo)
{
    hijo1=hijo;
}

NodoCTP* NodoCTP::obtenerHijo1()
{
    return hijo1;
}

void NodoCTP::fijarHijo2(NodoCTP* hijo)
{
    hijo2=hijo;
}

NodoCTP* NodoCTP::obtenerHijo2()
{
    return hijo2;
}

void NodoCTP::fijarHijo3(NodoCTP* hijo)
{
    hijo3=hijo;
}

NodoCTP* NodoCTP::obtenerHijo3()
{
    return hijo3;
}

void NodoCTP::fijarHijo4(NodoCTP* hijo)
{
    hijo4=hijo;
}

NodoCTP* NodoCTP::obtenerHijo4()
{
    return hijo4;
}

void NodoCTP::fijarHijo5(NodoCTP* hijo)
{
    hijo5=hijo;
}

NodoCTP* NodoCTP::obtenerHijo5()
{
    return hijo5;
}

void NodoCTP::fijarHijo6(NodoCTP* hijo)
{
    hijo6=hijo;
}

NodoCTP* NodoCTP::obtenerHijo6()
{
    return hijo6;
}

void NodoCTP::fijarHijo7(NodoCTP* hijo)
{
    hijo7=hijo;
}

NodoCTP* NodoCTP::obtenerHijo7()
{
    return hijo7;
}

void NodoCTP::fijarHijo8(NodoCTP* hijo)
{
    hijo8=hijo;
}

NodoCTP* NodoCTP::obtenerHijo8()
{
    return hijo8;
}

void NodoCTP::insertarPunto(Vertice nuevo,int ind)
{
    if(dato.ObtenerCoorZ()>nuevo.ObtenerCoorZ())
    {
        if(dato.ObtenerCoorY()>nuevo.ObtenerCoorY())
        {
            if(dato.ObtenerCoorX()>nuevo.ObtenerCoorX())
            {
                if(hijo1==NULL)
                {
                    hijo1=new NodoCTP(nuevo);
                    hijo1->fijarIndice(ind);
                }
                else
                {
                    hijo1->insertarPunto(nuevo,ind);
                }
            }
            else
            {
                if(hijo2==NULL)
                {
                    hijo2=new NodoCTP(nuevo);
                    hijo2->fijarIndice(ind);
                }
                else
                {
                    hijo2->insertarPunto(nuevo,ind);
                }
            }
        }
        else
        {
            if(dato.ObtenerCoorX()>nuevo.ObtenerCoorX())
            {
                if(hijo3==NULL)
                {
                    hijo3=new NodoCTP(nuevo);
                    hijo3->fijarIndice(ind);
                }
                else
                {
                    hijo3->insertarPunto(nuevo,ind);
                }
            }
            else
            {
                if(hijo4==NULL)
                {
                    hijo4=new NodoCTP(nuevo);
                    hijo4->fijarIndice(ind);
                }
                else
                {
                    hijo4->insertarPunto(nuevo,ind);
                }
            }
        }
    }
    else
    {
        if(dato.ObtenerCoorY()>nuevo.ObtenerCoorY())
        {
            if(dato.ObtenerCoorX()>nuevo.ObtenerCoorX())
            {
                if(hijo5==NULL)
                {
                    hijo5=new NodoCTP(nuevo);
                    hijo5->fijarIndice(ind);
                }
                else
                {
                    hijo5->insertarPunto(nuevo,ind);
                }
            }
            else
            {
                if(hijo6==NULL)
                {
                    hijo6=new NodoCTP(nuevo);
                    hijo6->fijarIndice(ind);
                }
                else
                {
                    hijo6->insertarPunto(nuevo,ind);
                }
            }
        }
        else
        {
            if(dato.ObtenerCoorX()>nuevo.ObtenerCoorX())
            {
                if(hijo7==NULL)
                {
                    hijo7=new NodoCTP(nuevo);
                    hijo7->fijarIndice(ind);
                }
                else
                {
                    hijo7->insertarPunto(nuevo,ind);
                }
            }
            else
            {
                if(hijo8==NULL)
                {
                    hijo8=new NodoCTP(nuevo);
                    hijo8->fijarIndice(ind);
                }
                else
                {
                    hijo8->insertarPunto(nuevo,ind);
                }
            }
        }
    }
}

Vertice* NodoCTP::buscarVertice(int indi)
{
    if(indice==indi)
    {
        return (&dato);
    }
    else
    {
        Vertice* aux=NULL;
        if(hijo1!=NULL)
        {
            aux=hijo1->buscarVertice(indi);
        }
        if(aux!=NULL)
        {
            return aux;
        }
        else
        {
            if(hijo2!=NULL)
            {
                aux=hijo2->buscarVertice(indi);
            }
            if(aux!=NULL)
            {
                return aux;
            }
            else
            {
                if(hijo3!=NULL)
                {
                    aux=hijo3->buscarVertice(indi);
                }
                if(aux!=NULL)
                {
                    return aux;
                }
                else
                {
                    if(hijo4!=NULL)
                    {
                        aux=hijo4->buscarVertice(indi);
                    }
                    if(aux!=NULL)
                    {
                        return aux;
                    }
                    else
                    {
                        if(hijo5!=NULL)
                        {
                            aux=hijo5->buscarVertice(indi);
                        }
                        if(aux!=NULL)
                        {
                            return aux;
                        }
                        else
                        {
                            if(hijo6!=NULL)
                            {
                                aux=hijo6->buscarVertice(indi);
                            }
                            if(aux!=NULL)
                            {
                                return aux;
                            }
                            else
                            {
                                if(hijo7!=NULL)
                                {
                                    aux=hijo7->buscarVertice(indi);
                                }
                                if(aux!=NULL)
                                {
                                    return aux;
                                }
                                else
                                {
                                    if(hijo8!=NULL)
                                    {
                                        aux=hijo8->buscarVertice(indi);
                                    }
                                    if(aux!=NULL)
                                    {
                                        return aux;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return NULL;
}

std::queue<double> NodoCTP::VerticeCercano(float x,float y,float z)
{
    std::queue<double> retorno,retaux;
    double distancia,xf,yf,zf;
    xf=pow(dato.ObtenerCoorX()-x,2);
    yf=pow(dato.ObtenerCoorY()-y,2);
    zf=pow(dato.ObtenerCoorZ()-z,2);
    distancia=sqrt(xf+yf+zf);
    retorno.push(distancia);
    retorno.push(indice);
    if(hijo1!=NULL)
    {
        retaux=hijo1->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo2!=NULL)
    {
        retaux=hijo2->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo3!=NULL)
    {
        retaux=hijo3->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo4!=NULL)
    {
        retaux=hijo4->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo5!=NULL)
    {
        retaux=hijo5->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo6!=NULL)
    {
        retaux=hijo6->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo7!=NULL)
    {
        retaux=hijo7->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    if(hijo8!=NULL)
    {
        retaux=hijo8->VerticeCercano(x,y,z);
        if(distancia>retaux.front())
        {
            retorno=retaux;
        }
    }
    return retorno;
}

int NodoCTP::buscarNodoInd(Vertice *buscado)
{
    int retorno=-1;
    if(dato.ObtenerCoorX()==buscado->ObtenerCoorX()&&dato.ObtenerCoorY()==buscado->ObtenerCoorY()&&dato.ObtenerCoorZ()==buscado->ObtenerCoorZ())
    {
        retorno=indice;
    }
    else
    {
        if(hijo1!=NULL)
        {
            retorno=hijo1->buscarNodoInd(buscado);
        }
        if(hijo2!=NULL&&retorno==-1)
        {
            retorno=hijo2->buscarNodoInd(buscado);
        }
        if(hijo3!=NULL&&retorno==-1)
        {
            retorno=hijo3->buscarNodoInd(buscado);
        }
        if(hijo4!=NULL&&retorno==-1)
        {
            retorno=hijo4->buscarNodoInd(buscado);
        }
        if(hijo5!=NULL&&retorno==-1)
        {
            retorno=hijo5->buscarNodoInd(buscado);
        }
        if(hijo6!=NULL&&retorno==-1)
        {
            retorno=hijo6->buscarNodoInd(buscado);
        }
        if(hijo7!=NULL&&retorno==-1)
        {
            retorno=hijo7->buscarNodoInd(buscado);
        }
        if(hijo8!=NULL&&retorno==-1)
        {
            retorno=hijo8->buscarNodoInd(buscado);
        }
    }
    return retorno;
}
//PTCodoN

//OctreePuntos

OctreePuntos::OctreePuntos()
{
    raiz=NULL;
    cantVertices=0;
}

OctreePuntos::OctreePuntos(Vertice inicial)
{
    raiz=new NodoCTP(inicial);
    cantVertices=0;
}

void OctreePuntos::fijarRaiz(NodoCTP* nuevo)
{
    raiz=nuevo;
}

NodoCTP* OctreePuntos::obtenerRaiz()
{
    return raiz;
}

int OctreePuntos::obtenerCantVertices()
{
    return cantVertices;
}

void OctreePuntos::insertarPunto(float x,float y,float z)
{
    Vertice nuevo;
    nuevo.FijarCoorX(x);
    nuevo.FijarCoorY(y);
    nuevo.FijarCoorZ(z);
    if(raiz==NULL)
    {
        raiz=new NodoCTP(nuevo);
    }
    else
    {
        raiz->insertarPunto(nuevo,cantVertices);
    }
    cantVertices++;
}

std::vector<Vertice*> OctreePuntos::listarVertices()
{
    std::vector<Vertice*> lista;
    for(int i=0; i<cantVertices; i++)
    {
        lista.push_back(raiz->buscarVertice(i));
    }
    return lista;
}

std::queue<double> OctreePuntos::VerticeCercano(float x,float y,float z)
{
    return raiz->VerticeCercano(x,y,z);
}

int OctreePuntos::buscarNodoInd(Vertice *buscado)
{
    return raiz->buscarNodoInd(buscado);
}
//sotnuPeerTcO

//Arista

Arista::Arista()
{
    inicio= new Vertice();
    fin= new Vertice();
}

Arista::Arista(Vertice *i,Vertice *f)
{
    inicio=i;
    fin=f;
}

Vertice* Arista::ObtenerInicio()
{
    return inicio;
}

void Arista::FijarInicio(Vertice* ver)
{
    inicio=ver;
}

Vertice* Arista::ObtenerFin()
{
    return fin;
}

void Arista::FijarFin(Vertice* ver)
{
    fin=ver;
}

//atsirA

//Cara

Cara::Cara()
{
    tamano=0;
    l_aristas=*(new std::list<Arista*>());
}

Cara::Cara(unsigned long tam)
{
    tamano=tam;
    l_aristas=*(new std::list<Arista*>());
}

std::list<Arista*> Cara::ObtenerAristas()
{
    return l_aristas;
}

void Cara::FijarAristas(std::list<Arista*> lista)
{
    l_aristas=lista;
}

std::vector<int> Cara::ObtenerIndicesP()
{
    return indicesP;
}

void Cara::FijarIndicesP(std::vector<int> lista)
{
    indicesP=lista;
}

unsigned long Cara::ObtenerTamano()
{
    return tamano;
}

void Cara::FijarTamano(unsigned long tam)
{
    tamano=tam;
}

unsigned long Cara:: ObtenerCantAristas()
{
    return l_aristas.size();
}

//araC

//Objeto

Objeto::Objeto()
{
    nombre="default";
    l_caras=*(new std::list<Cara*>());
}

Objeto::Objeto(std::string nom)
{
    nombre=nom;
    l_caras=*(new std::list<Cara*>());
}

std::string Objeto::ObtenerNombre()
{
    return nombre;
}

void Objeto::FijarNombre(std::string nom)
{
    nombre=nom;
}

std::list<Cara*> Objeto::ObtenerCaras()
{
    return l_caras;
}

void Objeto::FijarCaras(std::list<Cara*> caras)
{
    l_caras=caras;
}

Vertice* Objeto::VerticeExtremoMenor()
{
    float coorx, coory, coorz;
    std::vector<Vertice*> l_vertices=Oc_vertices.listarVertices();
    std::vector<Vertice*>::iterator vIt=l_vertices.begin();
    coorx=(*vIt)->ObtenerCoorX();
    coory=(*vIt)->ObtenerCoorY();
    coorz=(*vIt)->ObtenerCoorZ();
    for(vIt=l_vertices.begin(); vIt!=l_vertices.end(); vIt++)
    {
        if((*vIt)->ObtenerCoorX()<coorx)
        {
            coorx=(*vIt)->ObtenerCoorX();
        }
        if((*vIt)->ObtenerCoorY()<coory)
        {
            coory=(*vIt)->ObtenerCoorY();
        }
        if((*vIt)->ObtenerCoorZ()<coorz)
        {
            coorz=(*vIt)->ObtenerCoorZ();
        }
    }

    Vertice *res=new Vertice(coorx,coory,coorz);
    return res;

}

Vertice* Objeto::VerticeExtremoMayor()
{
    float coorx=0, coory=0, coorz=0;
    std::vector<Vertice*> l_vertices=Oc_vertices.listarVertices();
    std::vector<Vertice*>::iterator vIt;
    for(vIt=l_vertices.begin(); vIt!=l_vertices.end(); vIt++)
    {
        if((*vIt)->ObtenerCoorX()>coorx)
        {
            coorx=(*vIt)->ObtenerCoorX();
        }
        if((*vIt)->ObtenerCoorY()>coory)
        {
            coory=(*vIt)->ObtenerCoorY();
        }
        if((*vIt)->ObtenerCoorZ()>coorz)
        {
            coorz=(*vIt)->ObtenerCoorZ();
        }
    }
    Vertice *res=new Vertice(coorx,coory,coorz);
    return res;
}


void Objeto::FijarCantVertices(unsigned long ver)
{
    cantVertices=ver;
}

void Objeto::FijarCantAristas(unsigned long ver)
{
    cantAristas=ver;
}

unsigned long Objeto::ObtenerCantVertices()
{
    return cantVertices;
}

std::string Objeto::Datos()
{
    std::string datos;

    datos=ObtenerNombre();
    datos= datos + " contiene ";
    datos= datos + itoa(ObtenerCantVertices());
    datos= datos +" vertices, ";
    datos=datos+itoa(ObtenerCantAristas());
    datos=datos+" aristas y ";
    datos=datos+itoa(l_caras.size());
    datos=datos+" caras.";
    return datos;
}

unsigned long Objeto::ObtenerCantAristas()
{
    return cantAristas;
}

void Objeto::FijarVertices(OctreePuntos vertices)
{
    Oc_vertices=vertices;
}

void Objeto::FijarAristas(std::vector<Arista> aristas)
{
    l_aristas=aristas;
}
std::vector<Arista> Objeto::ObtenerAristas()
{
    return l_aristas;
}
OctreePuntos Objeto::ObtenerVertices()
{
    return Oc_vertices;
}

std::queue<double> Objeto::VerticeCercano(float x,float y,float z)
{
    return Oc_vertices.VerticeCercano(x,y,z);
}

grafo<Vertice> Objeto::conversionAG()
{
    grafo<Vertice> retorno;
    std::vector<Vertice*> lista=ObtenerVertices().listarVertices();
    for(std::vector<Vertice*>::iterator vIt=lista.begin(); vIt!=lista.end(); vIt++)
    {
        nodoGrafo<Vertice> nodo;
        nodo.insertarDato(*(*vIt));
        retorno.insertarNuevoNodo(nodo);
    }
    for(std::vector<Arista>::iterator vIt=l_aristas.begin(); vIt!=l_aristas.end(); vIt++)
    {
        int origen,destino;
        double distancia;
        origen=Oc_vertices.buscarNodoInd(vIt->ObtenerInicio());
        destino=Oc_vertices.buscarNodoInd(vIt->ObtenerFin());
        nodoGrafo<Vertice>* nodoOrigen=retorno.buscarNodoGrafo(origen);
        nodoGrafo<Vertice>* nodoDestino=retorno.buscarNodoGrafo(destino);
        distancia=distanciaVertices(nodoOrigen->obtenerDato(),nodoDestino->obtenerDato());
        retorno.insertarVecino(origen,destino,distancia);
        retorno.insertarVecino(destino,origen,distancia);
    }
    return retorno;
}

int Objeto::calcularCentroInd()
{
    Vertice *maximo,*minimo;
    std::queue<double> cola;
    maximo=VerticeExtremoMayor();
    minimo=VerticeExtremoMenor();
    float x,y,z;
    x=(minimo->ObtenerCoorX())+(sqrt(pow(maximo->ObtenerCoorX() - minimo->ObtenerCoorX(),2)));
    y=(minimo->ObtenerCoorY())+(sqrt(pow(maximo->ObtenerCoorY() - minimo->ObtenerCoorY(),2)));
    z=(minimo->ObtenerCoorZ())+(sqrt(pow(maximo->ObtenerCoorZ() - minimo->ObtenerCoorZ(),2)));
    cola=VerticeCercano(x,y,z);
    cola.pop();
    return cola.front();
}

std::string Objeto::rutaCorta(int origen, int destino)
{
    std::string retorno;
    grafo<Vertice> provisional=conversionAG();
    retorno = provisional.dijkstra(origen,destino)+"; con una longitud de " + itoa(distanciaVertices((provisional.buscarNodoGrafo(origen)->obtenerDato()),(provisional.buscarNodoGrafo(destino)->obtenerDato()))) +".";
    return retorno;
}
//otejbO

//Sistema

Sistema::Sistema()
{
    l_objetos=*(new std::list<Objeto>());
}

std::string Sistema::CargarArchivo(std::string nom_ar)
{
    std::string mensaje;
    std::ifstream archivo;
    archivo.open(nom_ar.c_str(),std::ios::in);
    Objeto obj;
    std::list<Cara*> caras;
    if(!archivo)
    {
        mensaje="El archivo "+nom_ar+" no existe o es ilegible.";
    }
    else
    {
        bool formato=true,nuevo=true;
        std::string linea;
        int sec=0;
        OctreePuntos vertices;
        std::vector<Vertice*> v_vertices;
        while((!archivo.eof())&&(formato)&&(nuevo))
        {
            std::queue<std::string> palabras;
            if(sec==0)
            {
                std::getline(archivo,linea,'\n');
                palabras=Tokenizar(linea,' ');
                if(palabras.size()!=1)
                {
                    formato=false;
                }
                else
                {
                    obj=*(new Objeto(palabras.front()));
                    std::list<Objeto>::iterator lIt;
                    for(lIt=l_objetos.begin(); lIt!=l_objetos.end(); lIt++)
                    {
                        if(lIt->ObtenerNombre().compare(palabras.front())==0)
                        {
                            archivo.close();
                            return ("El objeto "+palabras.front()+" ya ha sido cargado en memoria.");
                        }
                    }
                }
            }
            else if(sec==1)
            {
                std::getline(archivo,linea);
                palabras=Tokenizar(linea,' ');
                if(palabras.size()!=1)
                {
                    formato=false;
                }
                else
                {
                    obj.FijarCantVertices(atoi(palabras.front().c_str()));
                }
            }
            else if(sec==2)
            {
                for(int i=0; ((i<obj.ObtenerCantVertices())&&(formato)); i++)
                {
                    std::getline(archivo,linea,'\n');
                    palabras=Tokenizar(linea,' ');
                    int tam=palabras.size()/3;
                    if((palabras.size()%3)!=0)
                    {
                        formato=false;
                    }
                    else
                    {
                        for (int j=0; j<tam; j++)
                        {
                            float x,y,z;
                            x=atof(palabras.front().c_str());
                            palabras.pop();
                            y=atof(palabras.front().c_str());
                            palabras.pop();
                            z=atof(palabras.front().c_str());
                            vertices.insertarPunto(x,y,z);
                            if(j+1!=tam)
                            {
                                i++;
                            }
                        }
                    }
                }
                obj.FijarVertices(vertices);
                v_vertices=vertices.listarVertices();
            }
            else if(sec==3)
            {
                int ban=0;
                long cont=0;
                std::vector<Arista> aristas;
                while((ban!=-1)&&(formato))
                {
                    std::getline(archivo,linea,'\n');
                    palabras=Tokenizar(linea,' ');
                    if(palabras.size()==1)
                    {
                        ban=atof(palabras.front().c_str());
                        if(ban!=-1)
                        {
                            formato=false;
                        }
                    }
                    else
                    {
                        cont++;
                        int aux=atof(palabras.front().c_str());
                        if(aux!=palabras.size()-1)
                        {
                            formato=false;
                        }
                        else
                        {
                            Cara *cara=new Cara(atoi(palabras.front().c_str()));
                            palabras.pop();
                            std::vector<int> indices;
                            std::list<Arista*> auxA;
                            std::vector<Arista>::iterator vIt1;
                            float recover=atof(palabras.front().c_str()),tam=palabras.size()-1,inicio=recover;
                            for(int i=0; i<tam; i++)
                            {
                                indices.push_back(inicio);
                                std::vector<Arista>::iterator lIt;
                                float fin;
                                palabras.pop();
                                fin=atof(palabras.front().c_str());
                                std::vector<Vertice*>::iterator vIt=v_vertices.begin();
                                if(aristas.size()==0)
                                {
                                    Arista arista;
                                    arista.FijarInicio(*(vIt+inicio));
                                    arista.FijarFin(*(vIt+fin));
                                    aristas.push_back(arista);
                                }
                                else
                                {
                                    bool existe=false;
                                    for(lIt=aristas.begin(); ((lIt!=aristas.end())&&(!existe)); lIt++)
                                    {
                                        if(lIt->ObtenerInicio()==(*(vIt+inicio)))
                                        {
                                            if(lIt->ObtenerFin()==(*(vIt+fin)))
                                            {
                                                existe=true;
                                            }
                                        }
                                        if(lIt->ObtenerInicio()==(*(vIt+fin)))
                                        {
                                            if(lIt->ObtenerFin()==(*(vIt+inicio)))
                                            {
                                                existe=true;
                                            }
                                        }
                                    }
                                    if(!existe)
                                    {
                                        Arista arista;
                                        arista.FijarInicio(*(vIt+inicio));
                                        arista.FijarFin(*(vIt+fin));
                                        aristas.push_back(arista);
                                    }
                                }
                                inicio=fin;
                            }
                            inicio=atof(palabras.front().c_str());
                            indices.push_back(inicio);
                            std::vector<Arista>::iterator lIt;
                            std::vector<Vertice*>::iterator vIt=v_vertices.begin();
                            if(aristas.size()==0)
                            {
                                Arista arista;
                                arista.FijarInicio(*(vIt+inicio));
                                arista.FijarFin(*(vIt+recover));
                                aristas.push_back(arista);
                            }
                            else
                            {
                                bool existe=false;
                                for(lIt=aristas.begin(); ((lIt!=aristas.end())&&(!existe)); lIt++)
                                {
                                    if(lIt->ObtenerInicio()==(*(vIt+inicio)))
                                    {
                                        if(lIt->ObtenerFin()==(*(vIt+recover)))
                                        {
                                            existe=true;
                                        }
                                    }
                                    if(lIt->ObtenerInicio()==(*(vIt+recover)))
                                    {
                                        if(lIt->ObtenerFin()==(*(vIt+inicio)))
                                        {
                                            existe=true;
                                        }
                                    }
                                }
                                if(!existe)
                                {
                                    Arista arista;
                                    arista.FijarInicio(*(vIt+inicio));
                                    arista.FijarFin(*(vIt+recover));
                                    aristas.push_back(arista);
                                }
                            }
                            cara->FijarIndicesP(indices);
                            while(!indices.empty())
                            {
                                indices.pop_back();
                            }
                            caras.push_back(cara);
                        }
                    }
                }
                obj.FijarAristas(aristas);
                obj.FijarCantAristas(obj.ObtenerAristas().size());
                std::list<Cara*>::iterator lIt=caras.begin();
                for(; lIt!=caras.end(); lIt++)
                {
                    int inicio, fin;
                    std::vector<int>::iterator vIt=(*lIt)->ObtenerIndicesP().begin();
                    for(int i=0; i<((*lIt)->ObtenerIndicesP().size()-1); i++)
                    {
                        inicio=*(vIt+i);
                        fin=*(vIt+(1+i));
                        std::vector<Arista>::iterator aIt=obj.ObtenerAristas().begin();
                        std::vector<Vertice*>::iterator veIt=v_vertices.begin();
                        for(; aIt!=obj.ObtenerAristas().begin(); aIt++)
                        {
                            if(aIt->ObtenerInicio()==(*(veIt+inicio)))
                            {
                                if(aIt->ObtenerFin()==(*(veIt+fin)))
                                {
                                    (*lIt)->ObtenerAristas().push_back(&(*(aIt)));
                                }
                            }
                            else if(aIt->ObtenerInicio()==(*(veIt+fin)))
                            {
                                if(aIt->ObtenerFin()==(*(veIt+inicio)))
                                {
                                    (*lIt)->ObtenerAristas().push_back(&(*(aIt)));
                                }
                            }
                        }
                    }
                    inicio=fin;
                    fin=*((*lIt)->ObtenerIndicesP().begin());
                    std::vector<Arista>::iterator aIt=obj.ObtenerAristas().begin();
                    std::vector<Vertice*>::iterator veIt=v_vertices.begin();
                    for(; aIt!=obj.ObtenerAristas().begin(); aIt++)
                    {
                        if(aIt->ObtenerInicio()==(*(veIt+inicio)))
                        {
                            if(aIt->ObtenerFin()==(*(veIt+fin)))
                            {
                                (*lIt)->ObtenerAristas().push_back(&(*(aIt)));
                            }
                        }
                        else if(aIt->ObtenerInicio()==(*(veIt+fin)))
                        {
                            if(aIt->ObtenerFin()==(*(veIt+inicio)))
                            {
                                (*lIt)->ObtenerAristas().push_back(&(*(aIt)));
                            }
                        }
                    }
                }
                obj.FijarCaras(caras);
            }
            else if(sec==4)
            {
                std::getline(archivo,linea,'\n');
            }
            else
            {
                formato=false;
            }
            sec++;
        }
        if(formato)
        {
            l_objetos.push_back(obj);
            mensaje="El objeto "+obj.ObtenerNombre()+" ha sido cargado exitosamente del archivo "+nom_ar+".";
        }
        else
        {
            mensaje="El archivo "+nom_ar+" no contiene un objeto 3D valido.";
        }
    }
    archivo.close();
    return mensaje;
}

bool Sistema::eliminarObjeto(std::string nombre)
{
    bool res=false;
    std::list<Objeto>::iterator iobj=buscarObjeto(nombre);

    if(iobj!=l_objetos.end())
    {
        l_objetos.erase(iobj);
        res=true;
    }

    return res;
}

std::list<Objeto>::iterator Sistema::buscarObjeto(std::string nombre)
{
    std::list<Objeto>::iterator iobj;

    for (iobj=l_objetos.begin();  iobj!=l_objetos.end(); iobj++)
    {
        if(iobj->ObtenerNombre().compare(nombre)==0)
        {
            return iobj;
        }
    }

    return iobj;

}

std::list<std::string> Sistema::DatosPorObjeto()
{

    std::list<std::string> res;
    std::list<Objeto>::iterator iob=l_objetos.begin();
    std::string aux;
    for(; iob!=l_objetos.end(); iob++)
    {
        aux=iob->Datos();
        res.push_back(aux);
    }
    return res;
}

std::list<Objeto> Sistema::ObtenerObjetos()
{
    return l_objetos;
}

bool Sistema::crearEnvolventeObjeto(std::string nombre)
{

    std::list<Objeto>::iterator iobj=l_objetos.begin();
    Objeto res,aux;
    OctreePuntos vertices;
    bool encontrado=false;

    for(; iobj!=l_objetos.end() && !encontrado ; iobj++)
    {
        if(iobj->ObtenerNombre()==nombre)
        {
            aux=*iobj;
            encontrado=true;
        }
    }
    if(encontrado)
    {
        Vertice *maximo=aux.VerticeExtremoMayor();
        Vertice *minimo=aux.VerticeExtremoMenor();
        float x,y,z;
        x=minimo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=minimo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=minimo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=minimo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        res.FijarVertices(vertices);

        std::vector<Arista> aristas;
        std::vector<Vertice*> l_vertices=res.ObtenerVertices().listarVertices();
        std::vector<Vertice*>::iterator vIt=l_vertices.begin();
        std::vector<int> indices;
        aristas.push_back(*(new Arista((*vIt),(*(vIt+1))))); //0
        aristas.push_back(*(new Arista((*vIt),(*(vIt+2))))); //1
        aristas.push_back(*(new Arista((*vIt),(*(vIt+3))))); //2
        aristas.push_back(*(new Arista((*(vIt+1)),(*(vIt+4)))));  //3
        aristas.push_back(*(new Arista((*(vIt+1)),(*(vIt+6)))));  //4
        aristas.push_back(*(new Arista((*(vIt+2)),(*(vIt+6)))));  //5
        aristas.push_back(*(new Arista((*(vIt+2)),(*(vIt+5)))));  //6
        aristas.push_back(*(new Arista((*(vIt+3)),(*(vIt+4)))));  //7
        aristas.push_back(*(new Arista((*(vIt+3)),(*(vIt+5)))));  //8
        aristas.push_back(*(new Arista((*(vIt+4)),(*(vIt+7)))));  //9
        aristas.push_back(*(new Arista((*(vIt+5)),(*(vIt+7)))));  //10
        aristas.push_back(*(new Arista((*(vIt+6)),(*(vIt+7)))));  //11

        res.FijarAristas(aristas);

        std::vector<Arista>::iterator lIt=res.ObtenerAristas().begin();
        std::list<Cara*> caras;
        Cara *aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*lIt));
        aux1->ObtenerAristas().push_back(&(*(lIt+2)));
        aux1->ObtenerAristas().push_back(&(*(lIt+3)));
        aux1->ObtenerAristas().push_back(&(*(lIt+7)));
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(3);
        indices.push_back(4);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*lIt));
        aux1->ObtenerAristas().push_back(&(*(lIt+1)));
        aux1->ObtenerAristas().push_back(&(*(lIt+4)));
        aux1->ObtenerAristas().push_back(&(*(lIt+5)));
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(6);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+1)));
        aux1->ObtenerAristas().push_back(&(*(lIt+2)));
        aux1->ObtenerAristas().push_back(&(*(lIt+6)));
        aux1->ObtenerAristas().push_back(&(*(lIt+8)));
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(5);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+3)));
        aux1->ObtenerAristas().push_back(&(*(lIt+4)));
        aux1->ObtenerAristas().push_back(&(*(lIt+9)));
        aux1->ObtenerAristas().push_back(&(*(lIt+11)));
        indices.push_back(1);
        indices.push_back(4);
        indices.push_back(6);
        indices.push_back(7);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+7)));
        aux1->ObtenerAristas().push_back(&(*(lIt+8)));
        aux1->ObtenerAristas().push_back(&(*(lIt+9)));
        aux1->ObtenerAristas().push_back(&(*(lIt+10)));
        indices.push_back(3);
        indices.push_back(4);
        indices.push_back(5);
        indices.push_back(7);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+5)));
        aux1->ObtenerAristas().push_back(&(*(lIt+6)));
        aux1->ObtenerAristas().push_back(&(*(lIt+10)));
        aux1->ObtenerAristas().push_back(&(*(lIt+11)));
        indices.push_back(2);
        indices.push_back(6);
        indices.push_back(5);
        indices.push_back(7);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        res.FijarCaras(caras);
        res.FijarCantVertices(8);
        res.FijarCantAristas(12);
        res.FijarNombre("envolvente_"+nombre);
        l_objetos.push_back(res);
    }
    return encontrado;
}

bool Sistema::crearEnvolvente(int num)
{

    std::list<Objeto>::iterator iobj=l_objetos.begin();
    Objeto res,aux;
    OctreePuntos vertices;
    Vertice *maximo=new Vertice();
    Vertice *minimo=new Vertice();
    bool encontrado=false;
    if(l_objetos.size()>0)
    {
        float xi=1000000,yi=1000000,zi=1000000,xa=-1000000,ya=-1000000,za=-1000000;
        encontrado=true;
        for(; iobj!=l_objetos.end(); iobj++)
        {
            if(iobj->VerticeExtremoMayor()->ObtenerCoorX()>xa)
            {
                xa=iobj->VerticeExtremoMayor()->ObtenerCoorX();
            }
            if(iobj->VerticeExtremoMayor()->ObtenerCoorY()>ya)
            {
                ya=iobj->VerticeExtremoMayor()->ObtenerCoorY();
            }
            if(iobj->VerticeExtremoMayor()->ObtenerCoorZ()>za)
            {
                za=iobj->VerticeExtremoMayor()->ObtenerCoorZ();
            }
            if(iobj->VerticeExtremoMenor()->ObtenerCoorX()<xi)
            {
                xi=iobj->VerticeExtremoMenor()->ObtenerCoorX();
            }
            if(iobj->VerticeExtremoMenor()->ObtenerCoorY()<yi)
            {
                yi=iobj->VerticeExtremoMenor()->ObtenerCoorY();
            }
            if(iobj->VerticeExtremoMenor()->ObtenerCoorZ()<zi)
            {
                zi=iobj->VerticeExtremoMenor()->ObtenerCoorZ();
            }
            maximo->FijarCoorX(xa);
            maximo->FijarCoorY(ya);
            maximo->FijarCoorZ(za);
            minimo->FijarCoorX(xi);
            minimo->FijarCoorY(yi);
            minimo->FijarCoorZ(zi);
        }
    }
    if(encontrado)
    {

        float x,y,z;
        x=minimo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=minimo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=minimo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=minimo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=minimo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=minimo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        x=maximo->ObtenerCoorX();
        y=maximo->ObtenerCoorY();
        z=maximo->ObtenerCoorZ();
        vertices.insertarPunto(x,y,z);

        res.FijarVertices(vertices);

        std::vector<Arista> aristas;
        std::vector<Vertice*> l_vertices=res.ObtenerVertices().listarVertices();
        std::vector<Vertice*>::iterator vIt=l_vertices.begin();
        std::vector<int> indices;
        aristas.push_back(*(new Arista((*vIt),(*(vIt+1)))));
        aristas.push_back(*(new Arista((*vIt),(*(vIt+2)))));
        aristas.push_back(*(new Arista((*vIt),(*(vIt+3)))));
        aristas.push_back(*(new Arista((*(vIt+1)),(*(vIt+4)))));
        aristas.push_back(*(new Arista((*(vIt+1)),(*(vIt+6)))));
        aristas.push_back(*(new Arista((*(vIt+2)),(*(vIt+6)))));
        aristas.push_back(*(new Arista((*(vIt+2)),(*(vIt+5)))));
        aristas.push_back(*(new Arista((*(vIt+3)),(*(vIt+4)))));
        aristas.push_back(*(new Arista((*(vIt+3)),(*(vIt+5)))));
        aristas.push_back(*(new Arista((*(vIt+4)),(*(vIt+7)))));
        aristas.push_back(*(new Arista((*(vIt+5)),(*(vIt+7)))));
        aristas.push_back(*(new Arista((*(vIt+6)),(*(vIt+7)))));

        res.FijarAristas(aristas);

        std::vector<Arista>::iterator lIt=res.ObtenerAristas().begin();
        std::list<Cara*> caras;
        Cara *aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*lIt));
        aux1->ObtenerAristas().push_back(&(*(lIt+2)));
        aux1->ObtenerAristas().push_back(&(*(lIt+3)));
        aux1->ObtenerAristas().push_back(&(*(lIt+7)));
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(3);
        indices.push_back(4);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*lIt));
        aux1->ObtenerAristas().push_back(&(*(lIt+1)));
        aux1->ObtenerAristas().push_back(&(*(lIt+4)));
        aux1->ObtenerAristas().push_back(&(*(lIt+5)));
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(6);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+1)));
        aux1->ObtenerAristas().push_back(&(*(lIt+2)));
        aux1->ObtenerAristas().push_back(&(*(lIt+6)));
        aux1->ObtenerAristas().push_back(&(*(lIt+8)));
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(5);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+3)));
        aux1->ObtenerAristas().push_back(&(*(lIt+4)));
        aux1->ObtenerAristas().push_back(&(*(lIt+9)));
        aux1->ObtenerAristas().push_back(&(*(lIt+11)));
        indices.push_back(1);
        indices.push_back(4);
        indices.push_back(6);
        indices.push_back(7);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+7)));
        aux1->ObtenerAristas().push_back(&(*(lIt+8)));
        aux1->ObtenerAristas().push_back(&(*(lIt+9)));
        aux1->ObtenerAristas().push_back(&(*(lIt+10)));
        indices.push_back(3);
        indices.push_back(4);
        indices.push_back(5);
        indices.push_back(7);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        while(!indices.empty())
        {
            indices.pop_back();
        }

        aux1=new Cara(4);
        aux1->ObtenerAristas().push_back(&(*(lIt+5)));
        aux1->ObtenerAristas().push_back(&(*(lIt+6)));
        aux1->ObtenerAristas().push_back(&(*(lIt+10)));
        aux1->ObtenerAristas().push_back(&(*(lIt+11)));
        indices.push_back(2);
        indices.push_back(6);
        indices.push_back(5);
        indices.push_back(7);
        aux1->FijarIndicesP(indices);
        caras.push_back(aux1);

        res.FijarCaras(caras);
        res.FijarCantVertices(8);
        res.FijarCantAristas(12);
        res.FijarNombre("envolvente_total_"+itoa(num));
        l_objetos.push_back(res);
    }
    return encontrado;
}

std::string Sistema::GuardarObjeto(std::string nombre, std::string archivo)
{
    std::fstream salida;
    salida.open(archivo.c_str(),std::ios::out);

    if(salida)
    {
        std::list<Objeto>::iterator iob=buscarObjeto(nombre);
        if(iob==l_objetos.end())
        {
            salida.close();
            std::remove(archivo.c_str());
            return ("El objeto "+nombre+" no ha sido cargado en memoria.");
        }
        salida<<iob->ObtenerNombre().c_str();
        salida<<"\n";
        salida<<itoa(iob->ObtenerCantVertices()).c_str();
        salida<<"\n";
        std::vector<Vertice*> l_vertices=iob->ObtenerVertices().listarVertices();
        std::vector<Vertice*>::iterator iver=l_vertices.begin();
        for(; iver!=l_vertices.end(); iver++)
        {
            Vertice aux=*(*iver);
            salida<<itoa(aux.ObtenerCoorX()).c_str();
            salida<<" ";
            salida<<itoa(aux.ObtenerCoorY()).c_str();
            salida<<" ";
            salida<<itoa(aux.ObtenerCoorZ()).c_str();
            salida<<"\n";
        }

        std::list<Cara*> caras = iob->ObtenerCaras();
        std::list<Cara*>::iterator icar=caras.begin();


        for(; icar!=caras.end(); icar++)
        {

            Cara cara=*(*icar);

            std::list<Arista*>::iterator iar=cara.ObtenerAristas().begin();
            std::list<int> aux;

            salida<<itoa(cara.ObtenerTamano()).c_str();
            salida<<" ";

            std::vector<int> indices = (*icar)->ObtenerIndicesP();

            std::vector<int> ::iterator it=indices.begin();

            for(; it!=indices.end(); it++)
            {
                salida<<(itoa(*it)).c_str();
                salida<<" ";
            }
            salida<<"\n";
        }

        salida<<"-1 ";
    }
    salida.close();
    return ("La información del objeto "+nombre+" ha sido guardada exitosamente en el archivo "+archivo );
}

std::string Sistema::verticeCercanoPuntoxObjeto(std::string nombre, float x, float y,float z)
{
    std::list<Objeto>::iterator obj=buscarObjeto(nombre);
    if(obj==l_objetos.end())
    {
        return ("El objeto "+nombre+" no ha sido cargado en memoria.");
    }
    else
    {
        std::queue<double> datos=obj->VerticeCercano(x,y,z);
        std::string retorno="";
        double distancia=datos.front(),indice;
        datos.pop();
        indice=datos.front();
        Vertice *cercano=obj->ObtenerVertices().obtenerRaiz()->buscarVertice(indice);
        retorno=retorno+("El vertice "+itoa(indice)+" ("+itoa(cercano->ObtenerCoorX())+","+itoa(cercano->ObtenerCoorY())+","+itoa(cercano->ObtenerCoorZ())+") ");
        retorno=retorno+("del objeto "+nombre+" es el mas cercano al punto ("+itoa(x)+","+itoa(y)+","+itoa(z)+"), a una distancia de "+itoa(distancia));
        return retorno;
    }
}

std::string Sistema::verticeCercanoPuntoxObjetoGeneral(float x, float y,float z)
{
    std::string nombre;
    std::list<Objeto>::iterator it=l_objetos.begin();
    Vertice *cercano;
    double distancia,indice;
    std::string retorno;
    for(; it!=l_objetos.end(); it++)
    {
        std::queue<double> datos=it->VerticeCercano(x,y,z);
        if(it==l_objetos.begin())
        {
            distancia=datos.front();
            datos.pop();
            indice=datos.front();
            cercano=it->ObtenerVertices().obtenerRaiz()->buscarVertice(indice);
            nombre=it->ObtenerNombre();
        }
        else
        {
            if(datos.front()<distancia)
            {
                distancia=datos.front();
                datos.pop();
                indice=datos.front();
                cercano=it->ObtenerVertices().obtenerRaiz()->buscarVertice(indice);
                nombre=it->ObtenerNombre();
            }
            datos.pop();
            datos.pop();
        }
    }
    retorno=("El verice "+itoa(indice)+" ("+itoa(cercano->ObtenerCoorX())+","+itoa(cercano->ObtenerCoorY())+","+itoa(cercano->ObtenerCoorZ())+") "+" del objeto "+nombre+" es el mas cercano al punto ("+itoa(x)+","+itoa(y)+","+itoa(z)+"), a una distancia de "+itoa(distancia));
    return retorno;
}

std::string Sistema::verticeCercanoxEnvolvente(std::string nombre)
{
    std::list<Objeto>::iterator objetoP=buscarObjeto(nombre);
    std::string retorno;
    if(buscarObjeto(nombre)==l_objetos.end())
    {
        return ("El objeto "+nombre+" no ha sido cargado en memoria. ");
    }
    else
    {
        bool ya=false;
        if(buscarObjeto("envolvente_"+nombre)==l_objetos.end())
        {
            ya=crearEnvolventeObjeto(nombre);
        }
        std::list<Objeto>::iterator objetoE=buscarObjeto("envolvente_"+nombre);
        std::vector<Vertice*> l_vertices = objetoE->ObtenerVertices().listarVertices();

        std::vector<Vertice*>:: iterator iver=l_vertices.begin();
        int i=0;
        for(iver=l_vertices.begin(); iver!=l_vertices.end(); iver++,i++)
        {
            float x=(*iver)->ObtenerCoorX();
            float y=(*iver)->ObtenerCoorY();
            float z=(*iver)->ObtenerCoorZ();
            std::queue<double> datos;
            datos=objetoP->VerticeCercano(x,y,z);
            double dista;
            dista=datos.front();
            datos.pop();
            double indice;
            indice =datos.front();
            Vertice *verti=objetoP->ObtenerVertices().obtenerRaiz()->buscarVertice(indice);
            float xO=verti->ObtenerCoorX();
            float yO=verti->ObtenerCoorY();
            float zO=verti->ObtenerCoorZ();
            retorno=retorno+(itoa(i)+"("+itoa(x)+","+itoa(y)+","+itoa(z)+") "+itoa(indice)+"("+itoa(xO)+","+itoa(yO)+","+itoa(zO)+") "+itoa(dista)+" ");
        }
        if(ya)
        {
            eliminarObjeto("envolvente_"+nombre);
        }

    }
    return retorno;

}

std::string Sistema::rutaCercana(std::string nombre,int origen,int destino)
{
    std::string retorno="";
    std::list<Objeto>::iterator lIt=buscarObjeto(nombre);
    if(lIt==l_objetos.end())
    {
        retorno="El objeto " + nombre + " no ha sido cargado en memoria.";
    }
    else
    {
        if(origen==destino)
            retorno="Los indices de los vertices dados son iguales.";
        else
        {
            if(origen<0||destino<0||origen>=lIt->ObtenerCantVertices()||destino>=lIt->ObtenerCantVertices())
                retorno="Algunos de los indices de vertices estan fuera de rango para el objeto "+nombre+".";
            else
            {

                retorno="La ruta mas corta que conecta el vertice "+itoa(origen)+" y "+itoa(destino)+" del objeto "+nombre+" pasa por: "+lIt->rutaCorta(origen,destino);
            }
        }
    }
    return retorno;
}

std::string Sistema::rutaCercanaCentro(std::string nombre,int origen)
{
    std::string retorno="";
    std::list<Objeto>::iterator lIt=buscarObjeto(nombre);
    if(lIt==l_objetos.end())
    {
        retorno="El objeto " + nombre + " no ha sido cargado en memoria.";
    }
    else
    {
        if(origen<0||origen>=lIt->ObtenerCantVertices())
            retorno="El indice del vertice esta fuera de rango para el objeto "+nombre+".";
        else
        {
            int destino=lIt->calcularCentroInd();
            if (destino!=origen)
            {
                retorno="La ruta mas corta que conecta el vertice "+itoa(origen)+" y el centro del objeto "+nombre+" pasa por: "+lIt->rutaCorta(origen,destino);
            }
            else
            {
                retorno="La ruta mas corta que conecta el vertice "+itoa(origen)+" y el centro del objeto "+nombre+" pasa por: "+itoa(origen)+"; con una longitud de 0.";
            }
        }
    }
    return retorno;
}
//ametsiS


