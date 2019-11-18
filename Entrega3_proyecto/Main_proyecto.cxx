#include "Header.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <iomanip>

int main(int argc, const char * argv[])
{
    std::string comando;
    std::cout<<"Bienvenido\n";
    Sistema sis;
    int contenvolvente=0;
    do
    {
        std::cout<<"\n$";
        std::getline(std::cin,comando,'\n');
        std::queue<std::string> palabras;
        std::istringstream tok(comando);
        std::string aux;
        while(std::getline(tok,aux,' '))
        {
            palabras.push(aux);
        }
        if(palabras.front().compare("ruta_corta")==0)
        {
            if(palabras.size()!=4)
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
            else
            {
                palabras.pop();
                int origen, destino;
                origen=atoi(palabras.front().c_str());
                palabras.pop();
                destino=atoi(palabras.front().c_str());
                palabras.pop();
                std::string nombre=palabras.front();
                std::cout<< sis.rutaCercana(nombre,origen,destino);
            }
        }
        else if(palabras.front().compare("ruta_corta_centro")==0)
        {
            if(palabras.size()!=3)
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
            else
            {
                palabras.pop();
                int origen;
                origen=atoi(palabras.front().c_str());
                palabras.pop();
                std::string nombre=palabras.front();
                std::cout<< sis.rutaCercanaCentro(nombre,origen);
            }
        }
        else if(palabras.front().compare("cargar")==0)
        {
            if(palabras.size()!=2)
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
            else
            {
                palabras.pop();
                std::cout<<sis.CargarArchivo(palabras.front());
            }
        }
        else if(((palabras.front().compare("ayuda")==0)||palabras.front().compare("?")==0))
        {
            if(palabras.size()==1)
            {
                std::cout << "\n*cargar nombre_archivo\n*listado\n*envolvente\n\t*envolvente nombre_objeto\n\t*envolvente\n*descargar nombre_objeto\n*guardar nombre_objeto nombre_archivo\n*v_cercano px py pz nombre_objeto\n*v_cercano px py pz\n*v_cercanos_caja nombre_objeto\n*ruta_corta\n*ruta_corta_centro\n*salir"<<std::endl;
            }
            else
            {
                palabras.pop();
                if(palabras.front().compare("cargar")==0)
                {
                    std::cout << "\n*cargar:\n-Seguido del comando \"cargar\" y un espacio escriba el nombre del archivo con su respectiva extension.";
                }
                else if(((palabras.front().compare("ayuda")==0)||palabras.front().compare("?")==0))
                {
                    std::cout <<"\n*ayuda/?:\n-Ayuda/? mostraran todos los comandos disponibles.\n-Ayuda \"comando\" mostrar ayuda especifica sobre el comando indicado.";
                }
                else if(palabras.front().compare("descargar")==0)
                {
                    std::cout << "\n*descargar:\n-Seguido del comando \"descargar\" y un espacio escriba el nombre del objeto que desea eliminar de memoria.";
                }
                else if(palabras.front().compare("guardar")==0)
                {
                    std::cout << "\n*guardar:\n-Seguido del comando \"guardar\" y un espacio escriba el nombre del objeto y el nombre del archivo donde desea guardar sus datos separados por un espacio.";
                }
                else if(palabras.front().compare("listado")==0)
                {
                    std::cout << "\n*listado:\n-Listara la informacion de los objetos en memoria por nombre, cantidad de vertices, cantidad de aristas y caantidad de caras.";
                }
                else if(palabras.front().compare("salir")==0)
                {
                    std::cout<< "\n*salir:\n-Finaliza el programa.";
                }
                else if(palabras.front().compare("envolvente")==0)
                {
                    if(palabras.size()==2)
                    {
                        std::cout<<"\n*envolvente:\n-Seguido del comando \"envolvente\" y un espacio escriba el nombre del objeto del cual desea que se genera su caja envolvente";
                    }
                    else if(palabras.size()==1)
                    {
                        std::cout<<"\n*envolvente:\n-Generara una sola caja envolvente para todos los elementos cargados en el sistema";
                    }
                }
                else if(palabras.front().compare("v_cercano")==0)
                {
                    if(palabras.size()==5)
                    {
                        std::cout<<"\n*v_cercano:\n-Seguido del comando \"v_cercano\"y un espacio escriba la coordenada del punto en x, seguido otro espacio escriba la coordenada del punto en y, seguido de otro espacio escriba la coordenada del punto en z, seguido de otro espacio escriba el nombre del objeto.";
                    }
                    else if(palabras.size()==4)
                    {
                        std::cout<<"\n*v_cercano:\n-Seguido del comando \"v_cercano\"y un espacio escriba la coordenada del punto en x, seguido otro espacio escriba la coordenada del punto en y, seguido de otro espacio escriba la coordenada del punto en z.";
                    }
                }
                else if(palabras.front().compare("v_cercanos_caja")==0&&palabras.size()==2)
                {
                    std::cout<<"\n*v_cercanos_caja:\n-Seguido del comando \"v_cercanos_caja\"y un espacio escriba el nombre del objeto del cual quiere comparar sus vertices con los vertices de su caja envolvente";
                }
                else if(palabras.front().compare("ruta_corta")==0)
                {
                    std::cout << "\n*ruta_corta:\n-Seguido del comando \"ruta_corta\" y un espacio escribir (todo separado con espacios) indice del primer punto, indice del segundo punto y nombre del objeto sobre el cual realizar la operación.";
                }
                else if(palabras.front().compare("ruta_corta_centro")==0)
                {
                    std::cout << "\n*ruta_corta_centro:\n-Seguido del comando \"ruta_corta_centro\" y un espacio escribir (todo separado con espacios) indice del punto origen y el nombre del objeto sobre el cual efectuar la operacion.";
                }
                else
                {
                    std::cout << "Comando \""<< palabras.front() << "\" no reconocido.";
                }
            }
        }

        else if(palabras.front().compare("envolvente")==0)
        {
            if(palabras.size()==1)
            {
                if(sis.crearEnvolvente(contenvolvente))
                {
                    std::cout << "La caja envolvente de los objetos en memoria se ha generado con el nombre envolvente_total_"<<itoa(contenvolvente)<<".";
                    contenvolvente++;
                }
                else
                {
                    std::cout<<"Ningun objeto ha sido cargado en memoria.";
                }
            }
            else if(palabras.size()==2)
            {
                palabras.pop();
                if(sis.crearEnvolventeObjeto(palabras.front()))
                {
                    std::cout << "La caja envolvente del objeto "+palabras.front()+"se ha generado con el nombre envolvente_"+palabras.front()+".";
                }
                else
                {
                    std::cout << "El objeto "+palabras.front()+" no ha sido cargado en memoria.";
                }
            }
            else
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
        }

        else if(palabras.front().compare("descargar")==0)
        {
            if(palabras.size()!=2)
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
            else
            {
                palabras.pop();
                if(sis.eliminarObjeto(palabras.front()))
                {
                    std::cout<<"El objeto "<<palabras.front()<<" ha sido eliminado de la memoria de trabajo." << std::endl;
                }
                else
                {
                    std::cout<<"El objeto "<<palabras.front()<<" no ha sido cargado a memoria."<<std::endl;
                }
            }
        }

        else if(palabras.front().compare("guardar")==0)
        {
            if(palabras.size()!=3)
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
            else
            {
                palabras.pop();
                if(sis.buscarObjeto(palabras.front())!=sis.ObtenerObjetos().end())
                {
                    std::string auxs=palabras.front();
                    palabras.pop();
                    std::cout << sis.GuardarObjeto(auxs,palabras.front());

                }
                else
                {
                    std::cout<<"El objeto "<<palabras.front()<<" no ha sido cargado a memoria";
                }
            }
        }

        else if(palabras.front().compare("listado")==0)
        {
            std::list<std::string> lista=sis.DatosPorObjeto();
            std::list<std::string>::iterator is=lista.begin();
            for(; is!=lista.end(); is++)
            {
                std::cout<<(*is)<<std::endl;
            }
        }

        else if(palabras.front().compare("salir")==0)
        {

        }

        else if(palabras.front().compare("v_cercano")==0)
        {

            if(palabras.size()==5)  //punto 1
            {
                palabras.pop();
                float x,y,z;
                x=atof(palabras.front().c_str());
                palabras.pop();
                y=atof(palabras.front().c_str());
                palabras.pop();
                z=atof(palabras.front().c_str());
                palabras.pop();
                std::string nombre=palabras.front();
                std::cout << sis.verticeCercanoPuntoxObjeto(nombre,x,y,z);
            }
            else if(palabras.size()==4)   //punto 2
            {
                palabras.pop();
                float x,y,z;
                x=atof(palabras.front().c_str());
                palabras.pop();
                y=atof(palabras.front().c_str());
                palabras.pop();
                z=atof(palabras.front().c_str());

                std::cout<<sis.verticeCercanoPuntoxObjetoGeneral(x,y,z);

            }
            else
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }


        }

        else if(palabras.front().compare("v_cercanos_caja")==0)  //punto 3
        {
            if(palabras.size()!=2)
            {
                std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
            }
            else
            {
                palabras.pop();
                std::string nomObjeto=palabras.front();
                std::string datos=sis.verticeCercanoxEnvolvente(nomObjeto);
                std::queue<std::string> separados=Tokenizar(datos,' ');
                if(separados.front().compare("El")==0)
                {
                    std::cout << datos;
                }
                else
                {
                    std::cout<<std::setw(40)<<"Esquina"<<std::setw(40)<<"Vertice"<<std::setw(20)<<"Distacia"<<std::endl;
                    std::string datos=sis.verticeCercanoxEnvolvente(nomObjeto);
                    int i=1;
                    while(!separados.empty())
                    {
                        int espacio=40;
                        if(i==3)
                            espacio=20;
                        std::cout<<std::setw(espacio)<<separados.front();
                        separados.pop();
                        i++;
                        if(i==4)
                        {
                            std::cout<<std::endl;
                            i=1;
                        }
                    }
                }
            }
        }

        else
        {
            std::cout << "\""<<comando<<"\" no se reconoce como un comando interno. Para ayuda \"ayuda\" o \"?\""<<std::endl;
        }

    }
    while(comando.compare("salir")!=0);

    return 0;
}
