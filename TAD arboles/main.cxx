//
//  main.cpp
//  
//
//  Created by Laura Juliana Mora on 28/09/17.
//

#include <stdio.h>
#include<iostream>
#include "TAD_expresion.h"
int main (int argc,const char* argv[]){
    ArbolExpresion *arbol=new ArbolExpresion();
    arbol->llenarDesdePrefija("* / + 5 z - 8 ^ 4 2");
    std::cout<<arbol->obtenerPrefija();
    return 0;
}
