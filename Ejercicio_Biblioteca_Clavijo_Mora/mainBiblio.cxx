#include <iostream>
#include "clasesbiblo.h"

int main(int argc,const char* argv[])
{
    int opc=0;
    std::string nom;
    std::cout<<(char)168;
    std::cout<<"Cual nombre desea para la biblioteca?\n";
    std::cin>>nom;
    Biblioteca biblo(nom);
    system("cls");
    do
    {
        std::cout<<"BIBLIOTECA "<<ConvMa(nom)<<"\n\n";
        std::cout<<"Opciones:\n1.Agregar Area \n2.Eliminar Area \n3.Listar Libros\n4.Opciones especificas de un area\n 0.Salir";
        std::cin>>opc;
        switch (opc)
        {
        case 1:
            std::cout<<(char)168;
            std::cout<<"Cual nombre desea para el area?";
            std::cin>>nom;
            biblo.AgregarAreaC(nom);
            break;

        case 2:
            std::cout<<(char)168;
            std::cout<<"Cual nombre desea para el area?";
            std::cin>>nom;
            biblo.EliminarAreaC(nom);
            break;
        case 3:
            std::cout<<biblo.ListarLibros();
            break;

        case 4:
        {
            std::string n_area;
            std::cout<<(char)168;
            std::cout<<"Cual area esta buscando?";
            std::cin>>n_area;

            std::list<AreaConocimiento>::iterator area=biblo.BuscarAreaC(n_area);
            if(area!=biblo.ObtenerAreasC().end())
            {
                int opc2=0;
                std::cout<<"Opciones:\n 1.Agregar Libro\n 2.ELiminar Libro\n 3.Listar Libros\n 4.Opciones avansadas libro";
                std::cin>>opc2;
                std::string n_libro,n_autor;


                switch (opc2)
                {
                case 1:
                    std::cout<<"Nombre del libro: ";
                    std::cin>>n_libro;
                    std::cout<<"Autor: ";
                    std::cin>>n_autor;

                    area->AgregarLibro(n_libro,n_autor);
                    break;

                case 2:
                    std::cout<<"Nombre del libro: ";
                    std::cin>>n_libro;
                    std::cout<<"Autor: ";
                    std::cin>>n_autor;
                    area->EliminarLibro(n_libro,n_autor);
                    break;

                case 3:
                    std::cout<<area->ListarLibros();
                    break;

                case 4:
                {
                    std::string nombre,autor;
                    std::cout<<area->ListarLibros();
                    std::cout<<"¿Cual libro esta buscando?\n Libro: ";
                    std::cin>>nombre;
                    std::cout<<"Autor: ";
                    std::cin>>autor;

                    std::list<Libro>::iterator lib;
                    lib=area->BuscarLibro(nombre,autor);

                    int opc3=0;
                    std::cout<<"Opciones:\n 1.Añadir Ejemplares\n 2.Eliminar Ejemplares\n 3.Prestar Ejemplares\n 4.Devolover ejemplares";
                    std::cin>>opc3;

                    switch (opc3)
                    {
                    case 1:
                        lib->AgregarEjemplar();
                        break;

                    case 2:
                        lib->EliminarEjemplar();
                        break;

                    case 3:
                        lib->AumentarPrestados();
                        break;

                    case 4:
                        lib->DisminuirPrestados();
                        break;

                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
            }
            break;
        }
        default:
            break;
        }

    }
    while(opc!=0);
    return 0;
}
