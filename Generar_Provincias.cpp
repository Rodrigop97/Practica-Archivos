
/* * *
 * Se necesita generar un archivo con los nombres de las 24 provincias. De acuerdo al orden de
ingreso se les asigna un código (entre 0 y 23).
En el archivo PROVINCIAS.TXT se almacena, por renglón, código y nombre separados por espacio
en blanco
 * * */
#include <fstream>
#include <iostream>

void Generar_Provincias()
{
    std::ofstream arch;
    arch.open("PROVINCIAS.TXT");
    if (arch.fail())
        std::cout<<"Error...";
    else{
        std::string nombre;
        for (int i=0; i<24; i++){
            std::cout<<"Nombre ";
            std::getline(std::cin,nombre);
            arch<<i<<" "<<nombre<<std::endl;
        }
    }
    arch.close();
}
