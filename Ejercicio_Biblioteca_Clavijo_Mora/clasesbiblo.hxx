#ifndef CLASESBIBLO_HXX_INCLUDED
#define CLASESBIBLO_HXX_INCLUDED
#include <list>
#include <stdlib.h>

std::string ConvMa(std::string linea)
{
    for(int i=0;i<linea.length();i++)
    {
        linea[i]=toupper(linea[i]);
    }
    return linea;
}

Libro::Libro(std::string n_nom,std::string a_nom)
{
    nombre=n_nom;
    autor=a_nom;
    num_ejempl=1;
    cant_prestados=0;
}

std::string Libro::toString()
{
    char *num,*num1;
    itoa(num_ejempl,num,10);
    itoa((num_ejempl-cant_prestados),num1,10);
    std::string linea="\nNombre: "+nombre+"\nAutor: "+autor+"\nEjemplares: "+num+"\nDisponibles: "+num1;
    return (linea);
}

std::string Libro::ObtenerAutor()
{
    return autor;
}

std::string Libro::ObtenerNombre()
{
    return nombre;
}

unsigned long Libro::ObtenerNumEjempl()
{
    return num_ejempl;
}

unsigned long Libro::ObtenerCantPrestados()
{
    return cant_prestados;
}

void Libro::FijarAutor(std::string n_autor)
{
    autor=n_autor;
}

void Libro::FijarNombre(std::string n_nombre)
{
    nombre=n_nombre;
}

void Libro::AgregarEjemplar()
{
    num_ejempl++;
}

void Libro::EliminarEjemplar()
{
    num_ejempl--;
}
void Libro::AumentarPrestados()
{
    cant_prestados++;
}

void Libro::DisminuirPrestados()
{
    cant_prestados--;
}

AreaConocimiento::AreaConocimiento(std::string a_nom)
{
    nombre=a_nom;
    l_libros=*(new std::list<Libro>);
}

std::string AreaConocimiento::ObtenerNombre()
{
     return nombre;
}

void AreaConocimiento::FijarNombre(std::string n_nombre)
{
    nombre=n_nombre;
}

std::list<Libro>::iterator AreaConocimiento::BuscarLibro(std::string n_libro,std::string a_libro)
{
    std::list<Libro>::iterator lIt;
    n_libro=ConvMa(n_libro);
    a_libro=ConvMa(a_libro);
    for(lIt=l_libros.begin();lIt!=l_libros.end();lIt++)
    {
        std::string aux=ConvMa(lIt->ObtenerNombre());
        if(aux.compare(n_libro)==0)
        {
            aux=ConvMa(lIt->ObtenerAutor());
            if(aux.compare(a_libro)==0)
            {
                return lIt;
            }
        }
    }
    return l_libros.end();
}

void AreaConocimiento::AgregarLibro(std::string n_libro,std::string a_libro)
{
    if(BuscarLibro(n_libro,a_libro)==l_libros.end())
        l_libros.push_back(Libro(n_libro,a_libro));
}

unsigned long AreaConocimiento::ContarEjempl()
{
    return l_libros.size();
}

bool AreaConocimiento::EliminarLibro(std::string n_libro,std::string a_libro)
{
    std::list<Libro>::iterator lIt=BuscarLibro(n_libro,a_libro);
    if(lIt!=l_libros.end())
    {
        l_libros.erase(lIt);
        return true;
    }
    return false;
}

std::string AreaConocimiento::toString()
{
    return ("\nNombre: "+nombre);
}

std::string AreaConocimiento::ListarLibros()
{
    std::string linea="";
    std::list<Libro>::iterator lIt;
    for(lIt=l_libros.begin();lIt!=l_libros.end();lIt++)
    {
        linea=linea+lIt->toString();
    }
}

Biblioteca::Biblioteca(std::string nom)
{
    nombre=nom;
    l_areas=*(new std::list<AreaConocimiento>());
}

std::list<AreaConocimiento>::iterator Biblioteca::BuscarAreaC(std::string nom)
{
    std::list<AreaConocimiento>::iterator lIt;
    nom=ConvMa(nom);
    for(lIt=l_areas.begin();lIt!=l_areas.end();lIt++)
    {
        std::string aux=ConvMa(lIt->ObtenerNombre());
        if(nom.compare(aux)==0)
        {
            return lIt;
        }
    }
    return l_areas.end();
}

void Biblioteca::AgregarAreaC( std::string nom )
{
    if(BuscarAreaC(nom)==l_areas.end())
        l_areas.push_back(AreaConocimiento(nom));
}

long Biblioteca::ContarEjempl()
{
    long tot=0;
    for(std::list<AreaConocimiento>::iterator lIt=l_areas.begin();lIt!=l_areas.end();lIt++)
    {
        tot+=lIt->ContarEjempl();
    }
    return tot;
}

void Biblioteca::EliminarAreaC( std::string nom )
{
    std::list<AreaConocimiento>::iterator lIt=BuscarAreaC(nom);
    if(lIt!=l_areas.end())
    {
        l_areas.erase(lIt);
    }
}

std::list<AreaConocimiento> Biblioteca::ObtenerAreasC()
{
    return l_areas;
}

std::string Biblioteca::ListarLibros()
{
    std::string reporte="";
    for(std::list<AreaConocimiento>::iterator lIt=l_areas.begin();lIt!=l_areas.end();lIt++)
    {
        reporte+=lIt->ListarLibros();
    }
    return reporte;
}

#endif // CLASESBIBLO_HXX_INCLUDED
