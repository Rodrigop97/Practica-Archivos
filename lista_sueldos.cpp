/*
 *  Se desea realizar un informe ordenado por el sueldo a percibir por cada empleado de mayor a
menor con la información existente en el archivo SUELDOS.TXT.
 */

#include <fstream>
#include <iostream>
#include <iomanip>

void ordenar(int* &cod, float* & sueldo, int cant)
{
    for (int i=0; i<cant-1; i++){
        for (int j=i+1; j<cant; j++){
            if (sueldo[i] < sueldo[j]){
                int auxC = cod[i];
                float auxS = sueldo[i];
                cod[i] = cod[j];
                sueldo[i] = sueldo[j];
                cod[j] = auxC;
                sueldo[j] = auxS;
            }
        }
    }
}


int leer_sueldos(int* & codEmpleados, float* & sueldoEmpleados)
{
    int cont = 0, aux;
    int *auxE;
    float *auxS;
    std::ifstream arch("SUELDOS.TXT");
    if (arch.fail())
        std::cout<<"Error...";
    else{

        arch>>aux;
        while(!arch.eof()){
            auxE = new int[cont+1];
            auxE[cont] = aux;
            auxS = new float[cont+1];
            arch>>auxS[cont];

            for (int i=0; i<cont; i++){
                auxE[i] = codEmpleados[i];
                auxS[i] = sueldoEmpleados[i];

            }
            cont++;
            delete [] codEmpleados;
            delete [] sueldoEmpleados;
            codEmpleados = auxE;
            sueldoEmpleados = auxS;

            arch>>aux;
        }
    }
    arch.close();
    return cont;
}

void informe_empleados()
{
    int *cod = nullptr, cant;
    float *sueldo = nullptr;
    cant = leer_sueldos(cod, sueldo);
    ordenar(cod, sueldo, cant);
    std::cout<<std::setw(18)<<std::left<<"Codigo empelado"<<std::setw(10)<<std::left<<"Sueldo"<<std::endl;
    for (int i=0; i<cant; i++)
        std::cout<<std::setw(18)<<std::left<<cod[i]<<"$"<<std::setw(10)<<std::left<<sueldo[i]<<std::endl;

    delete [] cod;
    delete [] sueldo;
}
