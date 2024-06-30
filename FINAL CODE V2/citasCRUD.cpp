#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "variablescitas.h"
using namespace std;

CITAS cita[MAX_CITAS];
int pos1 = 0;

int obtPos1(int id);
void agregarcita(CITAS *c);
void mostrarcitas(int id);
void eliminarcita(int id);
void editarcita(CITAS *c, int id);
void principal();
void datospaciente();
void cargarCitas();

int obtPos1(int id)
{
    for (int i = 0; i < pos1; i++)
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
    if (pos1 < MAX_CITAS)
    {
        cita[pos1] = *c;
        pos1++;
    }
    else
    {
        cout << "No se pueden agregar más citas, límite alcanzado." << endl;
    }
}

void editarcita(CITAS *c, int id)
{
    int posi = obtPos1(id);
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
    int posi = obtPos1(id);
    if (posi != -1)
    {
        for (int i = posi; i < pos1 - 1; i++)
        {
            cita[i] = cita[i + 1];
        }
        pos1--;
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
        if (!miCitas)
        {
            cout << "No se pudo crear el archivo" << endl;
            return;
        }
        miCitas.close();
        miCitas.open("citas.txt", ios::in);
        if (!miCitas)
        {
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
    citas << nuevaCita.id << "\n";
    citas << nuevaCita.nombre << "\n";
    citas << nuevaCita.descripcion << "\n";
    citas << nuevaCita.tiempo.hora << "\n";
    citas << nuevaCita.tiempo.salida << "\n";
    citas << nuevaCita.doctor << "\n";
    cout << "Paciente agregado con exito \n";
}

void mostrarcitas(int id)
{
    int posi = obtPos1(id);
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