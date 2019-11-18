//
//  Header.h
//
//
//  Created by Laura Juliana Mora on 26/08/17.
//
//

#ifndef Header_h
#define Header_h
#include "tad_grafo.h"
#include <list>
#include <string>
#include <vector>
#include <queue>

class Vertice
{
public:
    Vertice();
    Vertice(float x,float y,float z);
    float ObtenerCoorX();
    void FijarCoorX(float x);
    float ObtenerCoorY();
    void FijarCoorY(float y);
    float ObtenerCoorZ();
    void FijarCoorZ(float z);
private:
    float coordX;
    float coordY;
    float coordZ;
};

class NodoCTP
{
public:
    NodoCTP();
    NodoCTP(Vertice dat);
    void fijarDato(Vertice dat);
    Vertice obtenerDato();
    void fijarIndice(int ind);
    int obtenerIndice();
    void fijarHijo1(NodoCTP* hijo);
    NodoCTP* obtenerHijo1();
    void fijarHijo2(NodoCTP* hijo);
    NodoCTP* obtenerHijo2();
    void fijarHijo3(NodoCTP* hijo);
    NodoCTP* obtenerHijo3();
    void fijarHijo4(NodoCTP* hijo);
    NodoCTP* obtenerHijo4();
    void fijarHijo5(NodoCTP* hijo);
    NodoCTP* obtenerHijo5();
    void fijarHijo6(NodoCTP* hijo);
    NodoCTP* obtenerHijo6();
    void fijarHijo7(NodoCTP* hijo);
    NodoCTP* obtenerHijo7();
    void fijarHijo8(NodoCTP* hijo);
    NodoCTP* obtenerHijo8();
    void insertarPunto(Vertice nuevo,int ind);
    Vertice* buscarVertice(int indi);
    std::queue<double> VerticeCercano(float x,float y,float z);
    int buscarNodoInd(Vertice *buscado);
private:
    Vertice dato;
    int indice;
    NodoCTP *hijo1;
    NodoCTP *hijo2;
    NodoCTP *hijo3;
    NodoCTP *hijo4;
    NodoCTP *hijo5;
    NodoCTP *hijo6;
    NodoCTP *hijo7;
    NodoCTP *hijo8;
};

class OctreePuntos
{
public:
    OctreePuntos();
    OctreePuntos(Vertice inicial);
    void fijarRaiz(NodoCTP* nuevo);
    NodoCTP* obtenerRaiz();
    int obtenerCantVertices();
    void insertarPunto(float x,float y,float z);
    std::vector<Vertice*> listarVertices();
    std::queue<double> VerticeCercano(float x,float y,float z);
    int buscarNodoInd(Vertice *buscado);
private:
    NodoCTP* raiz;
    int cantVertices;
};

class Arista
{
public:
    Arista();
    Arista(Vertice *i,Vertice *f);
    Vertice* ObtenerInicio();
    void FijarInicio(Vertice* ver);
    Vertice* ObtenerFin();
    void FijarFin(Vertice* ver);
private:
    Vertice *inicio;
    Vertice *fin;
};

class Cara
{
public:
    Cara();
    Cara(unsigned long tam);
    std::list<Arista*> ObtenerAristas();
    void FijarAristas(std::list<Arista*> lista);
    std::vector<int> ObtenerIndicesP();
    void FijarIndicesP(std::vector<int> lista);
    unsigned long ObtenerTamano();
    void FijarTamano(unsigned long tam);
    unsigned long ObtenerCantAristas();
private:
    std::list<Arista*> l_aristas;
    std::vector<int> indicesP;
    unsigned long tamano;
};

class Objeto
{
public:
    Objeto();
    Objeto(std::string nom);
    std::string ObtenerNombre();
    void FijarNombre(std::string nom);
    std::list<Cara*> ObtenerCaras();
    Vertice* VerticeExtremoMenor();
    Vertice* VerticeExtremoMayor();
    void FijarCaras(std::list<Cara*> caras);
    void FijarCantVertices(unsigned long ver);
    void FijarCantAristas(unsigned long ver);
    unsigned long ObtenerCantVertices();
    std::string Datos();
    unsigned long ObtenerCantAristas();
    void FijarVertices(OctreePuntos vertices);
    void FijarAristas(std::vector<Arista> aristas);
    std::vector<Arista> ObtenerAristas();
    OctreePuntos ObtenerVertices();
    std::queue<double> VerticeCercano(float x,float y,float z);
    grafo<Vertice> conversionAG();
    int calcularCentroInd();
    std::string rutaCorta(int origen, int destino);
private:
    std::string nombre;
    std::list<Cara*> l_caras;
    OctreePuntos Oc_vertices;
    std::vector<Arista> l_aristas;
    unsigned long cantVertices;
    unsigned long cantAristas;
};

class Sistema
{
public:
    Sistema();
    std::string CargarArchivo(std::string nom_ar);
    bool eliminarObjeto(std::string nombre);
    std::list<Objeto>::iterator buscarObjeto(std::string nombre);
    std::list<std::string> DatosPorObjeto();
    std::list<Objeto> ObtenerObjetos();
    bool crearEnvolventeObjeto(std::string nombre);
    bool crearEnvolvente(int num);
    std::string GuardarObjeto(std::string nombre, std::string archivo);
    std::string verticeCercanoPuntoxObjeto(std::string nombre, float x, float y,float z);
    std::string verticeCercanoxEnvolvente(std::string nombre);
    std::string verticeCercanoPuntoxObjetoGeneral(float x, float y,float z);
    std::string rutaCercana(std::string nombre,int origen,int destino);
    std::string rutaCercanaCentro(std::string nombre,int origen);
private:
    std::list<Objeto> l_objetos;

};
#include "Main_proyecto.hxx"
#endif /* Header_h */
