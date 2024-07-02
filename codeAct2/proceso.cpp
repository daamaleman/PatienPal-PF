#include <iostream>    //Libreria de entrada y salida de C++
#include <string.h>    //Libreria para usar cadenas
#include "variables.h" //Incluye el archivo "variables"
#include <locale.h>    //Libreria para el uso en espanol del code

using namespace std;

PERSONAS pacientes[MAX_REG]; // Estructura con max reg
int pos = 0;
int opGenSec;

// Funciones del programa
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

// Agregar ciudad
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

// Editar información de un paciente
void editar(PERSONAS *c, int id)
{
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

// Eliminar registro de un paciente
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

    cout << "Dijite el id de el usuario a eliminar: ";
    cin >> id;

    if (obtPos(id) == -1)
    {
        cout << "No se encontro registro" << endl;
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
    cout << endl;
    cout << "Menu \n";
    cout << "1. Agregar\n";
    cout << "2. Editar \n";
    cout << "3. Eliminar \n";
    cout << "4. Buscar \n";
    cout << "5. Mostrar Todo\n";
    cout << "6. Salir\n ";
    cout << "Digite la opcion: ";
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

// Mostrar datos del paciente
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

// Buscar por ID al paciente
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

// Mostrar datos del paciente
void showData(PERSONAS &c)
{
    cout << "DATOS DEL PACIENTE: " << endl;
    cout << "=====================================================================" << endl;
    cout << "El id del paciente es: " << c.id << endl;
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
    if (opGenSec == 1)
    {
        cout << "El genero secundario es: " << c.generoSec << endl;
    }
    else
    {
        cout << "No se agrego genero secundario";
    }

    cout << "La ciudad de residencia del paciente es: " << c.ciudad << endl;
    cout << "La direccion del hogar del paciente es: " << c.direccion << endl;
    cout << "El telefono celular del paciente es: " << c.telefono << endl;
    cout << "El correo electronico del paciente es: " << c.correo << endl;
    cout << "La relacion civica del paciente actualmente es: " << c.relacion << endl;
    cout << "=====================================================================" << endl;
}

// Datos que tendrá cada paciente que se quiera ingresar al registro
void pedirDatos()
{
    PERSONAS paciente;
    cout << "Datos del paciente\n";
    cout << "ID: ";
    cin >> paciente.id;
    if (obtPos(paciente.id) != -1)
    {
        cout << "El id ya esta registrado: " << endl;
        return;
    }
    cout << "Nombre: ";
    scanf(" %[^\n]", paciente.nombre);
    cout << "Apellido: ";
    scanf(" %[^\n]", paciente.apellido);
    cout << "Edad: ";
    cin >> paciente.edad;
    cout << "Fecha de nacimiento" << endl;
    cout << "Dia: ";
    cin >> paciente.dia;
    cout << "Mes: ";
    cin >> paciente.mes;
    cout << "Anio: ";
    cin >> paciente.anio;
    cout << "Cedula: ";
    scanf(" %[^\n]", paciente.cedula);
    cout << "Genero: ";
    scanf(" %[^\n]", paciente.genero);
    cout << "¿Desea agregar genero secundario? (1-Si / 2-No)" << endl;
    cin >> opGenSec;

    if (opGenSec == 1)
    {
        cout << "Genero secundario: " << endl;
        scanf(" %[^\n]", paciente.generoSec);
    }
    else if (opGenSec == 2)
    {
        cout << "No se ha agregado genero secundario..." << endl;
    }
    else
    {
        cout << "Ninguna opcion es valida..." << endl;
        exit(0);
    }
    cout << "Ciudad: ";
    scanf(" %[^\n]", paciente.ciudad);
    cout << "Direccion: ";
    scanf(" %[^\n]", paciente.direccion);
    cout << "Telefono: ";
    scanf(" %[^\n]", paciente.telefono);
    cout << "Correo: ";
    scanf(" %[^\n]", paciente.correo);
    cout << "Escriba la relacion que tiene el paciente actualmente: " << endl;
    cout << "1. Casado" << endl;
    cout << "2. Soltero" << endl;
    cout << "3. Divorciado" << endl;
    scanf(" %[^\n]", paciente.relacion);
    cout << "El paciente ha sido registrado..." << endl;
    agregar(&paciente);
    cout << "Registro Agregado....\n";
}

// Editar datos de un paciente
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

    // Menu para editar los datos del paciente
    cout << "Que dato desea editar?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Apellido" << endl;
    cout << "3. Edad" << endl;
    cout << "4. Dia del nacimiento" << endl;
    cout << "5. Mes del naciemiento" << endl;
    cout << "6. Anio del nacimiento" << endl;
    cout << "7. Cedula" << endl;
    cout << "8. Genero" << endl;
    cout << "9. Genero Secundario" << endl;
    cout << "10. Ciudad" << endl;
    cout << "11. Direccion" << endl;
    cout << "12. Correo" << endl;
    cout << "13. Relacion del paciente" << endl;
    cout << "Ingrese una de las opciones: ";
    cin >> opE;

    switch (opE)
    {
    case 1:
        cout << "Ingrese el nuevo nombre: ";
        cin >> c.nombre;
        editar(&c, id); // Llama el puntero y lo guarda conforme el id antes ingresado
        break;
    case 2:
        cout << "Ingrese el nuevo apellido: ";
        cin >> c.apellido;
        editar(&c, id);
        break;
    case 3:
        cout << "Ingrese la nueva edad: ";
        cin >> c.edad;
        editar(&c, id);
        break;
    case 4:
        cout << "Ingrese el nuevo dia del nacimiento: ";
        cin >> c.dia;
        editar(&c, id);
        break;
    case 5:
        cout << "Ingrese el nuevo mes del nacimiento: ";
        cin >> c.mes;
        editar(&c, id);
        break;
    case 6:
        cout << "Ingrese el nuevo anio del nacimiento: ";
        cin >> c.anio;
        editar(&c, id);
        break;
    case 7:
        cout << "Ingrese la nueva cedula: ";
        cin >> c.cedula;
        editar(&c, id);
        break;
    case 8:
        cout << "Ingrese la nuevo genero: ";
        cin >> c.genero;
        editar(&c, id);
        break;
    case 9:
        cout << "Ingrese la nuevo genero secundario: ";
        cin >> c.generoSec;
        editar(&c, id);
        break;
    case 10:
        cout << "Ingrese la nueva ciudad: ";
        cin >> c.ciudad;
        editar(&c, id);
        break;
    case 11:
        cout << "Ingrese la nueva direccion: ";
        cin >> c.direccion;
        editar(&c, id);
        break;
    case 12:
        cout << "Ingrese la nuevo telefono: ";
        cin >> c.telefono;
        editar(&c, id);
        break;
    case 13:
        cout << "Ingrese la nuevo correo: ";
        cin >> c.correo;
        editar(&c, id);
        break;
    case 14:
        cout << "Ingrese la nueva relacion: ";
        cin >> c.relacion;
        editar(&c, id);
        break;
    default:
        cout << "Ninguna opcion es correcta";
        exit(0);
        break;
    }

    cout << "Registro actualizado" << endl;
}