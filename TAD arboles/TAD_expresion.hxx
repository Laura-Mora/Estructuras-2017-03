

#include "TAD_expresion.h"
#include<iostream>
#include <queue>
#include <sstream>
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

//Nodo Expresion
NodoExpresion::NodoExpresion(std::string d){
    dato=d;
    hijoDer=NULL;
    hijoIzq=NULL;
    if(d.compare("+")!=0&&d.compare("-")!=0&&d.compare("*")!=0&&d.compare("/")!=0&&d.compare("^")!=0&&d.compare("%")!=0){
        operando=false;
    }else{
        operando=true;
    }
}

void NodoExpresion::asignarDato(std::string d){
    dato=d;
}

std::string NodoExpresion::  darDato(){
    return dato;
}

NodoExpresion* NodoExpresion:: obtenerHijoDer(){
    return hijoDer;
}

NodoExpresion* NodoExpresion:: obtenerHijoIzq(){
    return hijoIzq;
}

void NodoExpresion::fijarHijoIzq(NodoExpresion *hijo){
    hijoIzq=hijo;
}

void NodoExpresion::fijarHijoDer(NodoExpresion *hijo){
    hijoDer=hijo;
}
//*+++++++++++++++++++++++++++++++++++
//Arbol
ArbolExpresion::ArbolExpresion(){
    raiz=NULL;
}
void ArbolExpresion::fijarRaiz(NodoExpresion *hijo){
    raiz=hijo;
}

void ArbolExpresion::llenarDesdePrefija(std::string expresion){
    
    std::queue<std::string> cadena=Tokenizar(expresion,' ');
    
    std::string dato = cadena.front();
    NodoExpresion *aux= new NodoExpresion(dato);
    cadena.pop();
    fijarRaiz(aux);
    
    bool ya=llenarPRefijaRecursion(raiz, cadena);
    
}

bool  ArbolExpresion:: llenarPRefijaRecursion(NodoExpresion *papa, std::queue<std::string> datos){
    std::string d=papa->darDato();
    if(d.compare("+")!=0&&d.compare("-")!=0&&d.compare("*")!=0&&d.compare("/")!=0&&d.compare("^")!=0&&d.compare("%")!=0){
        return true;
    }else{
        std::string dato=datos.front();
        NodoExpresion *hijo=new NodoExpresion(dato);
        if(papa->obtenerHijoIzq()==NULL){
            datos.pop();
            papa->fijarHijoIzq(hijo);
            return llenarPRefijaRecursion(hijo,datos);
        }else{
            datos.pop();
            papa->fijarHijoDer(hijo);
            return llenarPRefijaRecursion(hijo,datos);
        }
    }
}

void ArbolExpresion::llenarDesdePosfija(std::string expresion){
    std::queue<std::string> cadena=Tokenizar(expresion,' ');
    
    std::string dato = cadena.front();
    NodoExpresion *aux= new NodoExpresion(dato);
    cadena.pop();
    fijarRaiz(aux);
    
    bool ya=llenarPosfijaRecursion(raiz, cadena);
}

bool ArbolExpresion::llenarPosfijaRecursion(NodoExpresion *papa, std::queue<std::string> datos){
    std::string d=papa->darDato();
    if(d.compare("+")!=0&&d.compare("-")!=0&&d.compare("*")!=0&&d.compare("/")!=0&&d.compare("^")!=0&&d.compare("%")!=0){
        return true;
    }else{
        std::string dato=datos.front();
        NodoExpresion *hijo=new NodoExpresion(dato);
        if(papa->obtenerHijoDer()==NULL){
            datos.pop();
            papa->fijarHijoDer(hijo);
            return llenarPosfijaRecursion(hijo,datos);
        }else{
            datos.pop();
            papa->fijarHijoIzq(hijo);
            return llenarPosfijaRecursion(hijo,datos);
        }
    }
}

std::string ArbolExpresion::obtenerPrefija(){
    return obtenerPrefijaRecursion(raiz);
}

std::string ArbolExpresion::obtenerPrefijaRecursion(NodoExpresion *papa){
    std::string dato =" "+papa->darDato();
    //std::cout<<papa->obtnerDato()<<" ";
    
    if(papa->obtenerHijoIzq()!=NULL){
       return " "+ obtenerPrefijaRecursion(papa->obtenerHijoIzq());
    }
    
    if(papa->obtenerHijoDer()!=NULL){
       return " "+ obtenerPrefijaRecursion(papa->obtenerHijoDer());
    }
    return dato;
}

std::string ArbolExpresion::obtenerPosfija(){
    return obtenerPosfijaRecursion(raiz);
}

std::string ArbolExpresion::obtenerPosfijaRecursion(NodoExpresion *papa){
    
    
    if(papa->obtenerHijoIzq()!=NULL){
        return " "+ obtenerPrefijaRecursion(papa->obtenerHijoIzq());
    }
    //std::cout<<papa->obtnerDato()<<" ";
    if(papa->obtenerHijoDer()!=NULL){
        return " "+ obtenerPrefijaRecursion(papa->obtenerHijoDer());
    }
    std::string dato =" "+papa->darDato();
    return dato;
}
