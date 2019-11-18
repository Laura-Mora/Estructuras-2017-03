

#ifndef tad_proyecto_h
#define tad_proyecto_h

class nodoPunto{
    private:
        float coordX;
        float coordY;
        float coordZ;
        nodoPunto *hijo1;//hijo menor menor menor 1
        nodoPunto *hijo2;//hijo menor menor mayor 2
        nodoPunto *hijo3;//hijo menor Mayor menor 3
        nodoPunto *hijo4;//hijo Mayor menor menor 4
        nodoPunto *hijo5;//hijo menor Mayor Mayor 5
        nodoPunto *hijo6;//hijo Mayor menor Mayor 6
        nodoPunto *hijo7;//hijo Mayor Mayor menor 7
        nodoPunto *hijo8;//hijo Mayor Mayor Mayor 8
    public:
        nodoPunto(float x,float y, float z);
        void insertarCoordX(float valor);
        float obtenerCoordX();
        void insertarCoordY(float valor);
        float obtenerCoordY();
        void insertarCoordZ(float valor);
        float obtenerCoordZ();
        void insertarHijo1(nodoPunto *nodo);
        nodoPunto* obtenerHijo1();
        void insertarHijo2(nodoPunto *nodo);
        nodoPunto* obtenerHijo2();
        void insertarHijo3(nodoPunto *nodo);
        nodoPunto* obtenerHijo3();
        void insertarHijo4(nodoPunto *nodo);
        nodoPunto* obtenerHijo4();
        void insertarHijo5(nodoPunto *nodo);
        nodoPunto* obtenerHijo5();
        void insertarHijo6(nodoPunto *nodo);
        nodoPunto* obtenerHijo6();
        void insertarHijo7(nodoPunto *nodo);
        nodoPunto* obtenerHijo7();
        void insertarHijo8(nodoPunto *nodo);
        nodoPunto* obtenerHijo8();
};

class arbolObjeto{
    private:
        nodoPunto *raiz;
    public:
        arbolObjeto();
        void fijarRaiz(nodoPunto *nodo);
        nodoPunto* obtenerRaiz();
        void insertarHijo(nodoPunto *papa);
};

#include "tad_proyecto.hxx"
#endif /* tad_proyecto_h */
