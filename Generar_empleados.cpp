/*
 * Una empresa posee N empleados y de cada uno de ellos los siguientes datos: Código de
empleado (numérico), cantidad de horas normales trabajadas, cantidad de horas extras trabajadas.
La cantidad de empleados y el valor de la hora normal de trabajo se leen como primeros datos
Se pide:
- Generar un archivo SUELDOS.TXT donde figure Cod de empleado, sueldo a cobrar.
Tenga en cuenta que las horas extras se pagan el doble que las horas normales de trabajo
 */

#include <iostream>
#include <fstream>

void generar_empleados()
{
    int n;
    float valorHra;
    std::cout<<"Cantidad de epleados: ";
    std::cin>>n;
    std::cout<<"Valor por hora: ";
    std::cin>>valorHra;
    int codEmpleado, hn, he;
    float sueldoEmpleado;

    std::ofstream arch("SUELDOS.TXT");
    if (arch.fail())
        std::cout<<"Error..";
    else{
        for (int i=0; i<n; i++){
            hn = 0;
            he = 0;
            std::cout<<"Codigo de empleado: ";
            std::cin>>codEmpleado;
            std::cout<<"Cant. horas normales: ";
            std::cin>>hn;
            std::cout<<"Cant. horas extra: ";
            std::cin>>he;
            sueldoEmpleado = (hn * valorHra) + (he * valorHra * 2);

            arch<<codEmpleado<<" "<<sueldoEmpleado<<std::endl;
        }
    }
    arch.close();
}
