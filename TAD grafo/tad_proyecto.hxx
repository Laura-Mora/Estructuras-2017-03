

#include "tad_proyecto.h"
#include <iostream>

//NODO PUNTO

nodoPunto::nodoPunto(float x, float y, float z){
    coordX=x;
    coordY=y;
    coordZ=z;
    hijo1=NULL;
    hijo2=NULL;
    hijo3=NULL;
    hijo4=NULL;
    hijo5=NULL;
    hijo6=NULL;
    hijo7=NULL;
    hijo8=NULL;
}

void nodoPunto::insertarCoordX(float valor){
    coordX=valor;
}

float nodoPunto::obtenerCoordX(){
    return coordX;
}

void nodoPunto::insertarCoordY(float valor){
    coordY=valor;
}

float nodoPunto::obtenerCoordY(){
    return coordX;
}

void nodoPunto::insertarCoordZ(float valor){
    coordZ=valor;
}

float nodoPunto::obtenerCoordZ(){
    return coordX;
}

void nodoPunto::insertarHijo1(nodoPunto *nodo){
    hijo1=nodo;
}

nodoPunto* nodoPunto::obtenerHijo1(){
    return hijo1;
}

void nodoPunto::insertarHijo2(nodoPunto *nodo){
    hijo2=nodo;
}

nodoPunto* nodoPunto::obtenerHijo2(){
    return hijo2;
}

void nodoPunto::insertarHijo3(nodoPunto *nodo){
    hijo3=nodo;
}

nodoPunto* nodoPunto::obtenerHijo3(){
    return hijo3;
}

void nodoPunto::insertarHijo4(nodoPunto *nodo){
    hijo4=nodo;
}
nodoPunto* nodoPunto::obtenerHijo4(){
    return hijo4;
}

void nodoPunto::insertarHijo5(nodoPunto *nodo){
    hijo5=nodo;
}
nodoPunto* nodoPunto::obtenerHijo5(){
    return hijo5;
}

void nodoPunto::insertarHijo6(nodoPunto *nodo){
    hijo6=nodo;
}
nodoPunto* nodoPunto::obtenerHijo6(){
    return hijo6;
}

void nodoPunto::insertarHijo7(nodoPunto *nodo){
    hijo7=nodo;
}
nodoPunto* nodoPunto::obtenerHijo7(){
    return hijo7;
}

void nodoPunto::insertarHijo8(nodoPunto *nodo){
    hijo8=nodo;
}
nodoPunto* nodoPunto::obtenerHijo8(){
    return hijo8;
}

//arbol OBJETO

arbolObjeto::arbolObjeto(){
    raiz=NULL;
}

void arbolObjeto::fijarRaiz(nodoPunto *nodo){
    raiz=nodo;
}

nodoPunto* arbolObjeto::obtenerRaiz(){
    return raiz;
}

void arbolObjeto::insertarHijo(nodoPunto *papa,nodoPunto *nodo){
    
}

