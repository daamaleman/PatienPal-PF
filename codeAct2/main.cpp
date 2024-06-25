#include <iostream> //Libreria de entrada y salida de C++
#include <locale.h> //Libreria para el uso en espanol del code
#include "proceso.cpp" //Incluye el archivo "Proceso"

using namespace std; 

int main()
{
    setlocale(LC_ALL, "spanish"); //Configura el lenguaje a espanol
    principal(); 
    return 0;
}