#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>

using namespace std;

PERSONAS pacientes[MAX_REG];
int pos = 0;
int opGenSec;

// crud
int obtPos(int id);
void agregar(PERSONAS *c); // punteros
void editar(PERSONAS *c, int id);
void eliminar(int id);
void eliminarDatos();
PERSONAS buscar(int id);
void buscarID();
int menu();
void principal();
void pedirDatos();
void mostrarDatos();
void showData(PERSONAS &c);
void editarDatos();

// Agregar ciudada
void agregar(PERSONAS *c)
{
    pacientes[pos] = *c;
    pos++;
}

// Buscar ciudades de las cuales se ingresaron
PERSONAS buscar(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (id == pacientes[i].id)
        {
            return pacientes[i];
        }
    }
    PERSONAS c;
    return c;
}



int obtPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (pacientes[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

// Editar información de una ciudad
void editar(PERSONAS *c, int id)
{
    //Se necesita mejora --------------------------------------------------------------------------
    int posi = obtPos(id);
    strcpy(pacientes[posi].nombre, c->nombre);
    strcpy(pacientes[posi].apellido, c->apellido);
    pacientes[posi].edad = c->edad;
    pacientes[posi].dia = c->dia;
    pacientes[posi].mes = c->mes;
    pacientes[posi].anio = c->anio;
    strcpy(pacientes[posi].cedula, c->cedula);
    strcpy(pacientes[posi].genero, c->genero);
    strcpy(pacientes[posi].ciudad, c->ciudad);
    strcpy(pacientes[posi].direccion, c->direccion);
    strcpy(pacientes[posi].telefono, c->telefono);
    strcpy(pacientes[posi].correo, c->correo);
    strcpy(pacientes[posi].relacion, c->relacion);
}

// Eliminar registro de una ciudad
void eliminar(int id)
{
    int posi = obtPos(id);
    for (int i = posi; i < pos - 1; i++)
    {
        pacientes[i] = pacientes[i + 1];
    }
    pos--;
}

void eliminarDatos()
{
    int id;

    cout << "Dijita el id de el usuario a eliminar: " << endl;
    cin >> id;

    if (obtPos(id) == -1)
    {
        cout << "No se encontro registro: " << endl;
        return;
    }

    eliminar(id);

    cout << "Se eliminaron los datos correctamente" << endl;
}

// Menu para seleccionar los que se quiere hacer
int menu()
{
    setlocale(LC_ALL, "spanish");
    int op;
    cout << "Menu \n";
    cout << "1. Agregar\n";
    cout << "2. Editar \n";
    cout << "3. Eliminar \n";
    cout << "4. Buscar \n";
    cout << "5. Mostrar Todo\n";
    cout << "6. Salir\n ";
    cout << "Digite la opción ";
    cin >> op;
    return op;
}

// Principal
void principal()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            pedirDatos();
            break;
        case 2:
            editarDatos();
            break;
        case 3:
            eliminarDatos();
            break;
        case 4:
            buscarID();
            break;
        case 5:
            mostrarDatos();
            break;
        case 6:
            cout << "Adios\n";
            break;
        default:
            cout << "ERROR\n";
            break;
        }

    } while (op != 6);
}

//Mostrar
void mostrarDatos()
{

    if (pos == 0)
    {
        cout << "No hay datos: " << endl;
        return;
    }

    for (int i = 0; i < pos; i++)
    {

        showData(pacientes[i]);
    }
}

//Buscar por ID
void buscarID()
{
    int id;

    cout << "Digite el id de el paciente a buscar: " << endl;
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro registro: " << endl;
        return;
    }

    PERSONAS c;
    c = buscar(id);
    showData(c);
    cout << "===========================";
}

//Mostrar datos
void showData(PERSONAS &c)
{
    cout<< "DATOS DEL PACIENTE: "<<endl;
    cout<< "=====================================================================" << endl;
    cout << "El id del paciente es: "<< c.id << endl;
    cout << "El nombre del paciente es: " << c.nombre << endl;
    cout << "El apellido del paciente es: "<< c.apellido << endl;
    cout << "La edad del paciente es: "<<  c.edad << endl;
    cout<<"Fecha de nacimiento: "<<endl;
    cout << "El dia de naciemiento del pacinete es: "<< c.dia << endl;
    cout << "El mes de nacimiento del paciente es: "<<  c.mes << endl;
    cout << "El año de nacimiento del paciente es: "<<  c.anio << endl;
    cout << "La cedula del paciente es: "<<  c.cedula << endl;
    cout << "El género del paciente es: "<<  c.genero << endl;
    cout << "La ciudad de residencia del paciente es: "<<  c.ciudad << endl;
    cout << "La direccion del hogar del paciente es: "<< c.direccion << endl;
    cout << "El telefono celular del paciente es: " << c.telefono  << endl;
    cout << "El correo electrónico del paciente es: "<< c.correo << endl;
    cout << "La relacion cibica del paciente actualmente es: "<<  c.relacion << endl;
    cout<< "=====================================================================" << endl;
}

// Datos que tendrá cada ciudad que se quiera ingresar al registro
void pedirDatos()
{
    PERSONAS paciente; 
    cout << "Datos del paciente\n";
    cout << "ID: ";
    cin >> paciente.id;
    if (obtPos(paciente.id) != -1)
    {
        cout << "El id ya está registrado: " << endl;
        return;
    }
    cout << "NOMBRE: ";
    scanf(" %[^\n]", paciente.nombre);
    cout << "Apellido: ";
    scanf(" %[^\n]", paciente.apellido);
    //cin.ignore();
    cout << "Edad: " << endl;
    cin >> paciente.edad;
    //cin.ignore();
    cout << "Fecha de nacimiento" << endl;
    cout << "Dia: " << endl;
    cin >> paciente.dia;
    //cin.ignore();
    cout << "Mes: " << endl;
    cin >> paciente.mes;
    //cin.ignore();
    cout << "Anio: " << endl;
    cin >> paciente.anio;
    //cin.ignore();
    cout << "Cedula: " << endl;
    scanf(" %[^\n]", paciente.cedula);
    //cin.ignore();
    cout << "Genero: " << endl;
    scanf(" %[^\n]", paciente.genero);
    //cin.ignore();
    /*cout << "¿Desea agregar genero secundario? (1=SI/2=N)" << endl;
    cin >> opGenSec;
    //cin.ignore();

    if (opGenSec == 1)
    {
        cout << "Genero secundario: " << endl;
        scanf(" %[^\n]", paciente.generoSec);
        //cin.ignore();
    }
    else if (opGenSec == 2)
    {
        cout << "No se ha agregado genero secundario..." << endl;
    }
    else
    {
        cout << "Ninguna opcion es valida..." << endl;
        exit(0);
    }*/

    cout << endl;
    cout << "Ciudad: " << endl;
    scanf(" %[^\n]", paciente.ciudad);
    //cin.ignore();
    cout << "Direccion: " << endl;
   scanf(" %[^\n]", paciente.direccion);
    //cin.ignore();
    cout << "Telefono: " << endl;
    scanf(" %[^\n]", paciente.telefono);
    //cin.ignore();
    cout << "Correo: " << endl;
    scanf(" %[^\n]", paciente.correo);
    //cin.ignore();
    cout << "Escriba la relacion que tiene el paciente actualmente: " << endl;
    cout << "1. Casado" << endl;
    cout << "2. Soltero" << endl;
    cout << "3. Divorciado" << endl;
    scanf(" %[^\n]", paciente.relacion);

    //cin.ignore();
    cout << "El paciente ha sido registrado..." << endl;
    agregar(&paciente);
    cout << "Registro Agregado....\n";
}

void editarDatos(){ // se necesita mejora
    int id;

    cout << "Escribe el ID del paciente a editar: " << endl;
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro registro: " << endl;
        return;
    }

    PERSONAS c = buscar(id);

    cout << "Datos actuales: " << endl;
    showData(c);

    cout << "Datos del paciente\n";
    

    /*if (obtPos(pacientes->id) != -1)
    {
        cout << "El id ya está registrado: " << endl;
        return;
    }*/

    cout << "Nombres: ";
    scanf(" %[^\n]", c.nombre);
    cout << "Apellidos: " << endl;
    scanf(" %[^\n]", c.apellido);  
    cout << "Edad: " << endl;
    cin >> c.edad;
    //cin.ignore();
    cout << "Fecha de nacimiento" << endl;
    cout << "Dia: " << endl;
    cin >> c.dia;
    //cin.ignore();
    cout << "Mes: " << endl;
    cin >> c.mes;
    //cin.ignore();
    cout << "Anio: " << endl;
    cin >> c.anio;
    //cin.ignore();
    cout << "Cedula: " << endl;
    scanf(" %[^\n]", c.cedula);
    //cin.ignore();
    cout << "Genero: " << endl;
    scanf(" %[^\n]", c.genero);
    //cin.ignore();
    /*cout << "¿Desea agregar genero secundario? (1=SI/2=N)" << endl;
    cin >> opGenSec;
    //cin.ignore();

    if (opGenSec == 1)
    {
        cout << "Genero secundario: " << endl;
        scanf(" %[^\n]", pacientes->generoSec);
        //cin.ignore();
    }
    else if (opGenSec == 2)
    {
        cout << "No se ha agregado genero secundario..." << endl;
    }
    else
    {
        cout << "Ninguna opcion es valida..." << endl;
        exit(0);
    }*/

    cout << endl;
    cout << "Ciudad: " << endl;
    scanf(" %[^\n]", c.ciudad);
    //cin.ignore();
    cout << "Direccion: " << endl;
    scanf(" %[^\n]", c.direccion);
    //cin.ignore();
    cout << "Telefono: " << endl;
    scanf(" %[^\n]", c.telefono);
    //cin.ignore();
    cout << "Correo: " << endl;
    scanf(" %[^\n]", c.correo);
    //cin.ignore();
    cout << "Escriba la relacion que tiene el paciente actualmente: " << endl;
    cout << "1. Casado" << endl;
    cout << "2. Soltero" << endl;
    cout << "3. Divorciado" << endl;
    scanf(" %[^\n]", c.relacion);

    editar(&c, id);

    cout << "Registro actualizado" << endl;
}

// shift+alt+f