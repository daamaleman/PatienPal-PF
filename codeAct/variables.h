#include <stdlib.h>
#include <fstream>
#define MAX_REG 100
    
typedef struct PERSONAS {  
    
    char nombre[100];
    char apellido[100];
    char cedula[16];
    char genero[100];
    char generoSec[100];
    char ciudad[100];
    char direccion[150];
    char telefono[13];
    char correo[100];
    char  relacion[100];
    int edad;
    int dia;
    int mes;
    int anio;
    int id;                                          
};       