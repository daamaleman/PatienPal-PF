#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <locale.h>
#include "variablespacientes.h"

using namespace std;

PERSONAS pacientes[MAX_REG];
int pos = 0;
int opGenSec;

// CRUD
void leerArchivo(PERSONAS pacientes[], int &cantidad);
int obtPos(int id);
void agregar(PERSONAS *c);
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

// Manejo de archivos
void escribirArchivo(const PERSONAS &person);
void saveAll();

// Agregar paciente
void agregar(PERSONAS *c)
{
    pacientes[pos] = *c;
    pos++;
}

// Buscar pacientes de las cuales se ingresaron
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

// Editar informacion del paciente
void editar(PERSONAS *c, int id)
{
    int posi = obtPos(id);
    if (posi == -1)
    {
        cout << "Usuario no existe" << endl;
    }
    else
    {
        strcpy(pacientes[posi].nombre, c->nombre);
        strcpy(pacientes[posi].apellido, c->apellido);
        pacientes[posi].edad = c->edad;
        pacientes[posi].dia = c->dia;
        pacientes[posi].mes = c->mes;
        pacientes[posi].anio = c->anio;
        strcpy(pacientes[posi].cedula, c->cedula);
        pacientes[posi].genero = c->genero;
        strcpy(pacientes[posi].ciudad, c->ciudad);
        strcpy(pacientes[posi].direccion, c->direccion);
        strcpy(pacientes[posi].telefono, c->telefono);
        strcpy(pacientes[posi].correo, c->correo);
        strcpy(pacientes[posi].relacion, c->relacion);
    }
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

    saveAll();
}

void eliminarDatos()
{
    int id;
    cout << "Digite el ID del usuario a eliminar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro registro" << endl;
        return;
    }
    eliminar(id);
    cout << "Se eliminaron los datos correctamente" << endl;
}

// Mostrar
void mostrarDatos()
{
    if (pos == 0)
    {
        cout << endl;
        cout << "No hay datos" << endl;
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        showData(pacientes[i]);
    }
}

// Buscar por ID
void buscarID()
{
    int id;
    cout << "Digite el ID del paciente a buscar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro registro" << endl;
        return;
    }
    PERSONAS c = buscar(id);
    showData(c);
    cout << "===========================";
}

// Mostrar datos
void showData(PERSONAS &c)
{
    cout << "DATOS DEL PACIENTE: " << endl;
    cout << "=====================================================================" << endl;
    cout << "El ID del paciente es: " << c.id << endl;
    cout << "El nombre del paciente es: " << c.nombre << endl;
    cout << "El apellido del paciente es: " << c.apellido << endl;
    cout << "La edad del paciente es: " << c.edad << endl;
    cout << endl;
    cout << "Fecha de nacimiento" << endl;
    cout << "Dia: " << c.dia << endl;
    cout << "Mes: " << c.mes << endl;
    cout << "Anio: " << c.anio << endl;
    cout << endl;
    cout << "La cedula del paciente es: " << c.cedula << endl;
    cout << "El genero del paciente es: " << c.genero << endl;
    if (c.generoSec != '\0')
    {
        cout << "El genero secundario del paciente es: " << c.generoSec << endl;
    }
    else
    {
        cout << "No se ha agregado genero secundario..." << endl;
    }
    cout << "La ciudad de residencia del paciente es: " << c.ciudad << endl;
    cout << "La direccion del hogar del paciente es: " << c.direccion << endl;
    cout << "El telefono celular del paciente es: " << c.telefono << endl;
    cout << "El correo electronico del paciente es: " << c.correo << endl;
    cout << "La relacion civil del paciente actualmente es: " << c.relacion << endl;
    cout << "=====================================================================" << endl;
}

// Datos que tendra cada paciente que se quiera ingresar al registro
void pedirDatos()
{
    PERSONAS paciente;
    cout << "Datos del paciente\n";
    cout << "ID: ";
    cin >> paciente.id;
    if (obtPos(paciente.id) != -1)
    {
        cout << "El ID ya esta registrado: " << endl;
        return;
    }
    cout << "Nombre: ";
    cin >> ws;
    cin.getline(paciente.nombre, 50);
    cout << "Apellido: ";
    cin.getline(paciente.apellido, 50);
    cout << "Edad: ";
    cin >> paciente.edad;
    cout << "Fecha de nacimiento\n";
    cout << "Dia: ";
    cin >> paciente.dia;
    cout << "Mes: ";
    cin >> paciente.mes;
    cout << "Anio: ";
    cin >> paciente.anio;
    cout << "Cedula: ";
    cin >> ws;
    cin.getline(paciente.cedula, 16);
    bool bandera = true;
    do
    {
        cout << "Genero (M/F): ";
        cin >> paciente.genero;
        if (paciente.genero != 'M' && paciente.genero != 'm' && paciente.genero != 'F' && paciente.genero != 'f')
        {
            cout << "Opcion incorrecta, intente de nuevo..." << endl;
            bandera = false;
        }
        else
        {
            bandera = true;
        }
    } while (!bandera);
    cout << "Genero secundario: ";
    cin >> paciente.generoSec;
    cout << "Ciudad: ";
    cin >> ws;
    cin.getline(paciente.ciudad, 50);
    cout << "Direccion: ";
    cin.getline(paciente.direccion, 150);
    cout << "Telefono: ";
    cin.getline(paciente.telefono, 13);
    cout << "Correo: ";
    cin.getline(paciente.correo, 50);
    cout << "Escriba la relacion que tiene el paciente actualmente: " << endl;
    cout << "1. Casado" << endl;
    cout << "2. Soltero" << endl;
    cout << "3. Divorciado" << endl;
    cin.getline(paciente.relacion, 50);
    cout << "El paciente ha sido registrado..." << endl;
    agregar(&paciente);
    cout << "Registro Agregado....\n";
    escribirArchivo(paciente);
}

void editarDatos()
{
    int id;
    int opE;
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
    cout << endl;
    // Menu para editar los datos
    cout << "¿Qué dato desea editar?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Apellido" << endl;
    cout << "3. Edad" << endl;
    cout << "4. Dia del nacimiento" << endl;
    cout << "5. Mes del nacimiento" << endl;
    cout << "6. Anio del nacimiento" << endl;
    cout << "7. Cedula" << endl;
    cout << "8. Genero" << endl;
    cout << "9. Genero Secundario" << endl;
    cout << "10. Ciudad" << endl;
    cout << "11. Direccion" << endl;
    cout << "12. Telefono" << endl;
    cout << "13. Correo" << endl;
    cout << "14. Relacion del paciente" << endl;
    cout << "Ingrese alguna de las opciones: " << endl;
    cin >> opE;

    switch (opE)
    {
    case 1:
        cout << "Nuevo nombre: ";
        cin >> ws;
        cin.getline(c.nombre, 50);
        break;
    case 2:
        cout << "Nuevo apellido: ";
        cin >> ws;
        cin.getline(c.apellido, 50);
        break;
    case 3:
        cout << "Nueva edad: ";
        cin >> c.edad;
        break;
    case 4:
        cout << "Nuevo dia de nacimiento: ";
        cin >> c.dia;
        break;
    case 5:
        cout << "Nuevo mes de nacimiento: ";
        cin >> c.mes;
        break;
    case 6:
        cout << "Nuevo anio de nacimiento: ";
        cin >> c.anio;
        break;
    case 7:
        cout << "Nueva cedula: ";
        cin >> ws;
        cin.getline(c.cedula, 16);
        break;
    case 8:
        cout << "Nuevo genero: ";
        cin >> c.genero;
        break;
    case 9:
        cout << "Nuevo genero secundario: ";
        cin >> c.generoSec;
        break;
    case 10:
        cout << "Nueva ciudad: ";
        cin >> ws;
        cin.getline(c.ciudad, 50);
        break;
    case 11:
        cout << "Nueva direccion: ";
        cin >> ws;
        cin.getline(c.direccion, 150);
        break;
    case 12:
        cout << "Nuevo telefono: ";
        cin >> ws;
        cin.getline(c.telefono, 13);
        break;
    case 13:
        cout << "Nuevo correo: ";
        cin >> ws;
        cin.getline(c.correo, 50);
        break;
    case 14:
        cout << "Nueva relacion civil: ";
        cin >> ws;
        cin.getline(c.relacion, 50);
        break;
    default:
        cout << "Opcion no valida" << endl;
        return;
    }
    editar(&c, id);
    cout << "Datos actualizados correctamente" << endl;
    saveAll();
}

// Funcion que escribe archivo
void escribirArchivo(const PERSONAS &person)
{
    ofstream archivo("pacientes.txt", ios::app);
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    archivo << "Id del paciente: " << person.id << endl;
    archivo << "Nombre del paciente: " << person.nombre << endl;
    archivo << "Apellido del paciente: " << person.apellido << endl;
    archivo << "Edad del paciente: " << person.edad << endl;
    archivo << "Dia de nacimiento del paciente: " << person.dia << endl;
    archivo << "Mes de nacimiento del paciente: " << person.mes << endl;
    archivo << "Anio de nacimiento del paciente: " << person.anio << endl;
    archivo << "Cedula del paciente: " << person.cedula << endl;
    archivo << "Genero del paciente: " << person.genero << endl;
    archivo << "Genero Secundario del paciente: "<< person.generoSec << endl;
    archivo << "Ciudad del paciente: " << person.ciudad << endl;
    archivo << "Direccion del paciente: " << person.direccion << endl;
    archivo << "Telefono del paciente: " << person.telefono << endl;
    archivo << "Correo del paciente: " << person.correo << endl;
    archivo << "Relacion del paciente: " << person.relacion << endl;
    archivo.close();
}

// Leer archivo de los pacientes
void leerArchivo(PERSONAS pacientes[], int &cantidad)
{
    ifstream archivo("Pacientes.txt");

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cantidad = 0;
    string linea;
    while (getline(archivo, linea))
    {
        if (linea.find("Id del paciente: ") == 0)
        {
            pacientes[cantidad].id = stoi(linea.substr(17));
            //cout << pacientes[cantidad].id << endl;

            getline(archivo, linea);
            strcpy(pacientes[cantidad].nombre, linea.substr(21).c_str());

            getline(archivo, linea);
            strcpy(pacientes[cantidad].apellido, linea.substr(23).c_str());

            getline(archivo, linea);
            pacientes[cantidad].edad = stoi(linea.substr(19));
            //cout << pacientes[cantidad].edad << endl;

            getline(archivo, linea);
            pacientes[cantidad].dia = stoi(linea.substr(32));
            //cout << pacientes[cantidad].dia << endl;

            getline(archivo, linea);
            pacientes[cantidad].mes = stoi(linea.substr(32));
            //cout << pacientes[cantidad].mes << endl;

            getline(archivo, linea);
            pacientes[cantidad].anio = stoi(linea.substr(32));
            //cout << pacientes[cantidad].anio << endl;

            getline(archivo, linea);
            strcpy(pacientes[cantidad].cedula, linea.substr(21).c_str());

            getline(archivo, linea);
            pacientes[cantidad].genero = linea.substr(21)[0];

            getline(archivo, linea);
            pacientes[cantidad].generoSec = linea.substr(32)[0];

            getline(archivo, linea);
            strcpy(pacientes[cantidad].ciudad, linea.substr(21).c_str());

            getline(archivo, linea);
            strcpy(pacientes[cantidad].direccion, linea.substr(24).c_str());

            getline(archivo, linea);
            strcpy(pacientes[cantidad].telefono, linea.substr(23).c_str());

            getline(archivo, linea);
            strcpy(pacientes[cantidad].correo, linea.substr(21).c_str());

            getline(archivo, linea);
            strcpy(pacientes[cantidad].relacion, linea.substr(23).c_str());

            cantidad++;
        }
    }

    //std::cout<<"Cantidad de pacientes: "<<pos;

    archivo.close();
}

// Guardar todos los pacientes en el archivo (para el proceso de edicion)
void saveAll()
{
    ofstream archivo("pacientes.txt", ios::trunc);
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        escribirArchivo(pacientes[i]);
    }

    archivo.close();
}