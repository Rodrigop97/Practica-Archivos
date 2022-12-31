/*
    *Se desea realizar un informe con las cantidades de multas por exceso de velocidad que se labran
en el país durante un mes.
Se cuenta con la información que envían todos los municipios: código de provincia y cantidad de
multas. Un código de provincia igual a 99 indica el fin de datos.
Informe:
 */

#include <fstream>
#include <iostream>
#include <iomanip>

std::string* levantar_archivo()
{
    int x;
    std::string *prov = new std::string[24];
    std::ifstream arch("PROVINCIAS.TXT");
    if (arch.fail())
        std::cout<<"Error..";
    else{
        arch>>x;
        while (!arch.eof()){
            arch.ignore();
            std::getline(arch,prov[x]);

            arch>>x;
        }
    }
    arch.close();
    return prov;
}


void informe()
{
    int cantMultas[24]={0}, cod = 0, multas;
    std::cout<<"Codigo de provincia";
    std::cin>>cod;
    while(cod != 99){
        std::cout<<"Cantidad de multas de municipio: ";
        std::cin>>multas;
        cantMultas[cod] += multas;

        std::cout<<"Codigo de provincia";
        std::cin>>cod;
    }

    std::string *provincias;
    provincias = levantar_archivo();

    std::cout<<std::setw(8)<<std::left<<"Codigo"<<std::setw(20)<<std::left<<"Provincia "<<std::left<<"Cant. multas "<<std::endl;
    for (int i=0; i<24;i++)
        std::cout<<std::setw(8)<<std::left<<i<<std::setw(20)<<std::left<<provincias[i]<<std::left<<cantMultas[i]<<std::endl;

}
