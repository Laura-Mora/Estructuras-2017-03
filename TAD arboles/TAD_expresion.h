

#ifndef TAD_expresion_h
#define TAD_expresion_h
#include <iostream>
#include<queue>
class NodoExpresion{
    protected:
        std::string dato;
        bool operando;
        NodoExpresion *hijoDer;
        NodoExpresion *hijoIzq;
    public:
        NodoExpresion(std::string d);
        void asignarDato(std::string d);
        std::string darDato();
        NodoExpresion* obtenerHijoDer();
        NodoExpresion* obtenerHijoIzq();
        void fijarHijoDer(NodoExpresion *hijo);
        void fijarHijoIzq(NodoExpresion *hijo);
};

class ArbolExpresion{
    protected:
        NodoExpresion *raiz;
    
    public:
        ArbolExpresion();
        void fijarRaiz(NodoExpresion *hijo);
        void llenarDesdePrefija(std::string expresion);
        bool llenarPRefijaRecursion(NodoExpresion *papa, std::queue<std::string> datos);
        void llenarDesdePosfija(std::string expresion);
        bool llenarPosfijaRecursion(NodoExpresion *papa, std::queue<std::string> datos);
        std::string obtenerPrefija();
        std::string obtenerPrefijaRecursion(NodoExpresion *papa);
        std::string obtenerInfija();
        std::string obtenerPosfija();
        std::string obtenerPosfijaRecursion(NodoExpresion *papa);
        int evaluar();
};

#include "TAD_expresion.hxx"
#endif /* TAD_expresion_h */
