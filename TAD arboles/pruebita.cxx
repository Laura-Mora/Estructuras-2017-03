#include<iostream>
#include "tad_arboles.h"

int main (int argc,const char* argv[])
{
    arbolBi<int> *arbol=new arbolBi<int>();
	bool hecho;

	hecho=arbol->insertarRaiz(12);    
    hecho=arbol->insertar(6,arbol->obtenerRaiz());
    hecho=arbol->insertar(2,arbol->obtenerRaiz());
    hecho=arbol->insertar(4,arbol->obtenerRaiz());
    hecho=arbol->insertar(5,arbol->obtenerRaiz());
    hecho=arbol->insertar(12,arbol->obtenerRaiz());
    hecho=arbol->insertar(14,arbol->obtenerRaiz());
    hecho=arbol->insertar(17,arbol->obtenerRaiz());
    hecho=arbol->insertar(25,arbol->obtenerRaiz());
    hecho=arbol->insertar(11,arbol->obtenerRaiz());
    hecho=arbol->insertar(32,arbol->obtenerRaiz());
    hecho=arbol->insertar(16,arbol->obtenerRaiz());
    hecho=arbol->insertar(9,arbol->obtenerRaiz());
    hecho=arbol->insertar(7,arbol->obtenerRaiz());
    hecho=arbol->insertar(19,arbol->obtenerRaiz());
    
    
    std::cout<<"tamaño: "<<arbol->tamano(arbol->obtenerRaiz())<<"\n";
    std::cout<<"Altura: "<<arbol->altura(arbol->obtenerRaiz())<<"\n";
    std::cout<<"Pre-orden:"<<"\n";
    arbol->preOrden(arbol->obtenerRaiz());
    std::cout<<"\n";
    int val=14;
    hecho=arbol->eliminar(val);
    std::cout<<"Pre-orden:"<<"\n";
    arbol->preOrden(arbol->obtenerRaiz());
    std::cout<<"\n";
	return 0;
}
