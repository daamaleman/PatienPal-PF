#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "variables.h"
using namespace std;

CITAS cita[MAX_CITAS];
int pos = 0;

int obtPos(int id);
void agregarcita(CITAS *c);
void mostrarcitas(int id);
void eliminarcita(int id);
void editarcita(CITAS *c, int id);
int menu();
void principal();
void datospaciente();
void cargarCitas();

int obtPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (cita[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void agregarcita(CITAS *c)
{
    if (pos < MAX_CITAS) 
    {
        cita[pos] = *c;
        pos++;
    } 
    else 
    {
        cout << "No se pueden agregar más citas, límite alcanzado." << endl;
    }
}

void editarcita(CITAS *c, int id)
{
    int posi = obtPos(id);
    if (posi != -1)
    {
        strcpy(cita[posi].nombre, c->nombre);
        strcpy(cita[posi].descripcion, c->descripcion);
        strcpy(cita[posi].tiempo.fechas, c->tiempo.fechas);
        strcpy(cita[posi].tiempo.hora, c->tiempo.hora);
        strcpy(cita[posi].tiempo.salida, c->tiempo.salida);
        strcpy(cita[posi].doctor, c->doctor);
    }
    else
    {
        cout << "Cita no encontrada." << endl;
    }
}

void eliminarcita(int id)
{
    int posi = obtPos(id);
    if (posi != -1)
    {
        for (int i = posi; i < pos - 1; i++)
        {
            cita[i] = cita[i + 1];
        }
        pos--;
    }
    else
    {
        cout << "Cita no encontrada." << endl;
    }
}

void cargarCitas()
{
    fstream miCitas("citas.txt", ios::in);
    if (!miCitas)
    {
        miCitas.open("citas.txt", ios::out);
        if (!miCitas) {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }
        miCitas.close();
        miCitas.open("citas.txt", ios::in);
        if (!miCitas) {
            cout << "No se pudo abrir el archivo para lectura" << endl;
            return;
        }
    }

    CITAS c;
    while (miCitas >> c.id)
    {
        miCitas.ignore(); // Ignorar el salto de línea después del ID
        miCitas.getline(c.nombre, 50);
        miCitas.getline(c.descripcion, 100);
        miCitas.getline(c.tiempo.fechas, 20);
        miCitas.getline(c.tiempo.hora, 10);
        miCitas.getline(c.tiempo.salida, 10);
        miCitas.getline(c.doctor, 50);

        agregarcita(&c);
    }

    miCitas.close();
}


int menu()
{
    int op = 0;
    cout << "-----Menu----- \n";
    cout << "1. Agregar cita \n";
    cout << "2. Eliminar cita \n";
    cout << "3. Editar cita \n";
    cout << "4. Mostrar citas \n";
    cout << "5. Cargar citas \n";
    cout << "6. Salir \n";
    cout << "Ingrese una opcion: ";
    cin >> op;

    return op;
}

void principal()
{
    int op = 0;
    do
    {
        op = menu();
        switch (op)
        {
            case 1:
                datospaciente();
                break;
            case 2:
            {
                int idEliminarcita;
                cout << "Ingrese el ID de la cita que desea eliminar: ";
                cin >> idEliminarcita;
                eliminarcita(idEliminarcita);
                break;
            }
            case 3:
            {
                int idEditar;
                cout << "Ingrese el ID de la cita que desea editar: ";
                cin >> idEditar;
                CITAS citaeditar;

                cout << "Ingrese los nuevos datos del paciente: \n";
                cout << "Nombre: ";
                cin.ignore(); // Ignorar el salto de línea anterior
                cin.getline(citaeditar.nombre, 50);

                cout << "Descripcion: ";
                cin.getline(citaeditar.descripcion, 100);

                cout << "Fecha: ";
                cin.getline(citaeditar.tiempo.fechas, 20);

                cout << "Hora: ";
                cin.getline(citaeditar.tiempo.hora, 10);

                cout << "Hora de salida: ";
                cin.getline(citaeditar.tiempo.salida, 10);

                cout << "Doctor: ";
                cin.getline(citaeditar.doctor, 50);

                editarcita(&citaeditar, idEditar);
                break;
            }
            case 4:
            {
                int idMostrar;
                cout << "Ingrese el ID de la cita que desea mostrar: ";
                cin >> idMostrar;
                mostrarcitas(idMostrar);
                break;
            }
            case 5:
                cargarCitas();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion incorrecta, por favor ingrese una opcion valida\n";
                break;
        }
    } while (op != 6);
}

void datospaciente()
{
    ofstream citas("citas.txt", ios::app);
    CITAS nuevaCita;
    cout << "Datos del paciente\n";  
    cout << "ID: ";
    cin >> nuevaCita.id;
    cout << "Nombre: ";
    cin.ignore(); // Ignorar el salto de línea anterior
    cin.getline(nuevaCita.nombre, 50);
    cout << "Descripcion: ";
    cin.getline(nuevaCita.descripcion, 100);
    cout << "Fecha: ";
    cin.getline(nuevaCita.tiempo.fechas, 20);
    cout << "Hora de llegada del paciente: ";
    cin.getline(nuevaCita.tiempo.hora, 10);
    cout << "Hora de salida del paciente: ";
    cin.getline(nuevaCita.tiempo.salida, 10);
    cout << "Doctor que atendio: ";
    cin.getline(nuevaCita.doctor, 50);
    agregarcita(&nuevaCita);
    citas << "ID: " << nuevaCita.id << "\n";
    citas << "Nombre: " <<  nuevaCita.nombre << "\n";
    citas << "Descripcion: " << nuevaCita.descripcion << "\n";
    citas << "Hora de entrada del paciente: " << nuevaCita.tiempo.hora << "\n";
    citas << "Hora de salida del paciente: " << nuevaCita.tiempo.salida << "\n";
    citas << "Doctor que atendio: " << nuevaCita.doctor << "\n";
    cout << "Paciente agregado con exito \n";
}

void mostrarcitas(int id)
{
    int posi = obtPos(id);
    if (posi != -1)
    {   
        cout << "--------------------------------------------" << endl;
        cout << "|" << "ID del paciente: " << cita[posi].id << endl;
        cout << "|" << "Nombre: " << cita[posi].nombre << endl;
        cout << "|" << "Descripcion: " << cita[posi].descripcion << endl;
        cout << "|" << "Fecha: " << cita[posi].tiempo.fechas << endl;
        cout << "|" << "Hora de llegada del paciente: " << cita[posi].tiempo.hora << endl;
        cout << "|" << "Hora de salida del paciente: " << cita[posi].tiempo.salida << endl;
        cout << "|" << "Doctor que atendio: " << cita[posi].doctor << endl;
        cout << "---------------------------------------------" << endl;
    }
    else
    {
        cout << "Cita no encontrada." << endl;
    }
}