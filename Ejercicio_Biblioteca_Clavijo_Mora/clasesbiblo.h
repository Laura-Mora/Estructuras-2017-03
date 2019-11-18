#ifndef CLASESBIBLO_H_INCLUDED
#define CLASESBIBLO_H_INCLUDED
#include <list>

std::string ConvMa(std::string linea);

class Libro
{
public:
    Libro(std::string n_nom,std::string a_nom);
    std::string ObtenerAutor();
    std::string ObtenerNombre();
    unsigned long ObtenerNumEjempl();
    unsigned long ObtenerCantPrestados();
    void FijarAutor(std::string n_autor);
    void FijarNombre(std::string n_nombre);
    void AgregarEjemplar();
    void EliminarEjemplar();
    void AumentarPrestados();
    void DisminuirPrestados();
    std::string toString();
protected:
    std::string nombre;
    unsigned long num_ejempl;
    std::string autor;
    unsigned long cant_prestados;
};

class AreaConocimiento
{
public:
    AreaConocimiento(std::string a_nom);
    std::string ObtenerNombre();
    void FijarNombre(std::string n_nombre);
    std::list<Libro>::iterator BuscarLibro(std::string n_libro,std::string a_libro);
    void AgregarLibro(std::string n_libro,std::string a_libro);
    unsigned long ContarEjempl();
    bool EliminarLibro(std::string n_libro,std::string a_libro);
    std::string ListarLibros();
    std::string toString();
protected:
    std::string nombre;
    std::list<Libro> l_libros;

};

class Biblioteca
{
public:
    Biblioteca(std::string nom);
    std::list<AreaConocimiento>::iterator BuscarAreaC(std::string nom);
    std::list<AreaConocimiento> ObtenerAreasC();
    void AgregarAreaC( std::string nom );
    long ContarEjempl();
    void EliminarAreaC( std::string nom );
    std::string ListarLibros();
protected:
    std::string nombre;
    std::list<AreaConocimiento> l_areas;
};

#include "clasesbiblo.hxx"

#endif // CLASESBIBLO_H_INCLUDED
