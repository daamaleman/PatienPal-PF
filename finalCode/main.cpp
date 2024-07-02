#include <iostream>
#include "proceso.cpp"
using namespace std;


int main()
{
    leerArchivo(pacientes,pos);
    setlocale( LC_ALL, "spanish");
    principal();

    return 0;
}
