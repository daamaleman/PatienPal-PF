#include <iostream>
#include "pacientesCRUD.cpp"
#include "citasCRUD.cpp"
using namespace std;

void mainMenu();
void optionMainMenu();
void patientMenu();
void optionPatientMenu();
void appointmentMenu();
void optionAppointmentMenu();

void mainMenu()
{
    system("cls||clear");
    cout << "\nBienvenido!" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Ingresar al menu de pacientes" << endl;
    cout << "2. Ingresar al menu de citas" << endl;
    cout << "3. Salir" << endl;
    cout << "Su opcion: ";
}

void optionMainMenu()
{
    int option;

    while (option != 3)
    {
        mainMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            optionPatientMenu();
            break;
        case 2:
            optionAppointmentMenu();
            break;
        case 3:
            cout << "\nHasta luego!" << endl;
            exit(0);
            break;
        default:
            cout << "\nOpcion no valida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void patientMenu()
{
    system("cls||clear");
    cout << "\nElija una opcion:" << endl;
    cout << "1. Registrar nuevo paciente" << endl;
    cout << "2. Ver listado de pacientes o informacion sobre un paciente" << endl;
    cout << "3. Editar datos de un paciente" << endl;
    cout << "4. Eliminar paciente" << endl;
    cout << "5. Salir al menu principal" << endl;
    cout << "6. Salir del programa" << endl;
    cout << "Su opcion: ";
}

void optionPatientMenu()
{
    int option;

    while (option != 5 || 6)
    {
        patientMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            // Registrar nuevo paciente
            break;
        case 2:
            // Ver listado de pacientes o informacion sobre un paciente
            break;
        case 3:
            // Editar datos de un paciente
            break;
        case 4:
            // Eliminar un paciente
            break;
        case 5:
            // Salir al menu principal
            optionMainMenu();
            break;
        case 6:
            // Salir del programa
            cout << "\nHasta luego!";
            exit(0);
            break;
        default:
            cout << "\nOpcion invalida, por favor elija una opcion valida" << endl;
            system("pause");
            break;
        }
    }
}

void appointmentMenu()
{
    system("cls||clear");
    cout << "\nElija una opcion:" << endl;
    cout << "1. Agendar nueva cita" << endl;
    cout << "2. Ver listado de citas o informacion sobre una cita" << endl;
    cout << "3. Editar datos de una cita" << endl;
    cout << "4. Reprogramar cita" << endl;
    cout << "5. Eliminar cita" << endl;
    cout << "6. Salir al menu principal" << endl;
    cout << "7. Salir del programa" << endl;
    cout << "Su opcion: ";
}

void optionAppointmentMenu()
{
    int option;
    while (true)
    {
        appointmentMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            // Agendar nueva cita
            break;
        case 2:
            // Ver listado de citas o informacion sobre una cita
            break;
        case 3:
            // Editar datos de una cita
            break;
        case 4:
            // Reprogramar cita
            break;
        case 5:
            // Eliminar cita
            break;
        case 6:
            // Salir al menu principal
            optionMainMenu();
            break;
        case 7:
            // Salir del programa
            cout << "\nHasta luego" << endl;
            exit(0);
            break;
        default:
            cout << "\nOpcion invalida, por favor elija una opcion valida" << endl;
            system("pause");
            break;
        }
    }
}