#include <iostream>
#include <locale.h>
//#include "variables.h" //para usar  idioma español 
#include "proceso.cpp"


using namespace std;

int main()
{
    setlocale( LC_ALL, "spanish");
    
    principal();
    return 0;
}