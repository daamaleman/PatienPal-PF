#include <iostream>
#include <string.h>

#define MAX_CITAS 100

struct HORARIOS
{
    char fechas[20];
    char hora[10];
    char salida[10];
};

struct CITAS 
{
    int id;
    char nombre[50];
    char descripcion[100];
    char doctor[50];
    HORARIOS tiempo;
};