#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "pacientesCRUD.cpp"
#include "citasCRUD.cpp"
#define FILENAME "usuarios.txt"
using namespace std;

// Funciones
void mainMenu();
void optionMainMenu();
void patientMenu();
void optionPatientMenu();
void appointmentMenu();
void optionAppointmentMenu();
void menuLogin();
bool cargarUsuarios();
void registrarUsuario();
void iniciarSesion();
void cambiarContrasena();

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
    system("cls||clear");
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
            cargarCitas();
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
    cout << "2. Editar datos de paciente" << endl;
    cout << "3. Eliminar datos de un paciente" << endl;
    cout << "4. Mostrar pacientes" << endl;
    cout << "5. Buscar paciente por ID" << endl;
    cout << "6. Salir al menu principal" << endl;
    cout << "7. Salir del programa" << endl;
    cout << "Su opcion: ";
}

void optionPatientMenu()
{
    int option;

    while (option != 6 || 7)
    {
        leerArchivo(pacientes, pos);
        patientMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            // Registrar nuevo paciente
            system("cls||clear");
            pedirDatos();
            system("pause");
            break;
        case 2:
            // Editar datos de paciente
            system("cls||clear");
            editarDatos();
            system("pause");
            break;
        case 3:
            // Eliminar datos de un paciente
            system("cls||clear");
            eliminarDatos();
            system("pause");
            break;
        case 4:
            // Mostrar pacientes
            system("cls||clear");
            mostrarDatos();
            system("pause");
            break;
        case 5:
            // Buscar paciente por ID
            system("cls||clear");
            buscarID();
            system("pause");
            break;
        case 6:
            // Salir al menu principal
            system("cls||clear");
            optionMainMenu();
            system("pause");
            break;
        case 7:
            // Salir del programa
            system("cls||clear");
            cout << "\nHasta luego!";
            exit(0);
            break;
        default:
            system("cls||clear");
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
    cout << "2. Eliminar cita" << endl;
    cout << "3. Editar datos de una cita" << endl;
    cout << "4. Mostrar citas" << endl;
    cout << "5. Recargar archivo de citas" << endl;
    cout << "6. Salir al menu principal" << endl;
    cout << "7. Salir del programa" << endl;
    cout << "Su opcion: ";
}

void optionAppointmentMenu()
{
    int option;
    cargarCitas();
    while (true)
    {
        appointmentMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            // Agendar nueva cita
            system("cls||clear");
            datospaciente();
            system("pause");
            break;
        case 2:
            // Eliminar cita
            system("cls||clear");
            int idEliminarcita;
            cout << "Ingrese el ID de la cita que desea eliminar: ";
            cin >> idEliminarcita;
            eliminarcita(idEliminarcita);
            system("pause");
            break;
        case 3:
            // Editar datos de una cita
            system("cls||clear");
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
            system("pause");
            break;
        case 4:
            // Mostrar citas
            system("cls||clear");
            int idMostrar;
            cout << "Ingrese el ID de la cita que desea mostrar: ";
            cin >> idMostrar;
            mostrarcitas(idMostrar);
            system("pause");
            break;
        case 5:
            // Recargar archivo de citas
            system("cls||clear");
            cargarCitas();
            system("pause");
            break;
        case 6:
            // Salir al menu principal
            system("cls||clear");
            cout << "Regresando al menu principal..." << endl;
            system("pause");
            optionMainMenu();
            break;
        case 7:
            // Salir del programa
            system("cls||clear");
            cout << "\nHasta luego" << endl;
            exit(0);
            break;
        default:
            system("cls||clear");
            cout << "\nOpcion invalida, por favor elija una opcion valida" << endl;
            system("pause");
            break;
        }
    }
}

// Función principal
void menuLogin()
{
    system("cls||clear");
    int opcion;
    cout << "1. Registrar" << endl;
    cout << "2. Iniciar Sesion" << endl;
    cout << "3. Cambiar contrasena" << endl;
    cout << "4. Salir" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        system("cls||clear");
        registrarUsuario();
        system("pause");
        break;
    case 2:
        system("cls||clear");
        iniciarSesion();
        system("pause");
        break;
    case 3:
        system("cls||clear");
        cambiarContrasena();
        system("pause");
    case 4:
        system("cls||clear");
        cout << "\nHasta luego" << endl;
        system("pause");
        exit(0);
        break;
    default:
        cout << "Opción inválida.\n";
    }
}

// Función para cargar usuarios desde el archivo
bool cargarUsuarios(const string &nombreUsuario, string &contrasena)
{
    ifstream archivo(FILENAME);
    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(':');
        if (pos != string::npos)
        {
            string user = linea.substr(0, pos);
            string pass = linea.substr(pos + 1);
            if (user == nombreUsuario)
            {
                contrasena = pass;
                return true;
            }
        }
    }
    return false;
}

// Función para registrar un nuevo usuario
void registrarUsuario()
{
    string nombreUsuario, contrasena;

    cout << "Registro de Usuario\n";
    cout << "Introduce nombre de usuario: ";
    cin >> nombreUsuario;

    string contrasenaExistente;
    if (cargarUsuarios(nombreUsuario, contrasenaExistente))
    {
        cout << "El nombre de usuario ya existe. Prueba con otro.\n";
        system("pause");
        menuLogin();
    }

    cout << "Introduce la contrasena: ";
    cin >> contrasena;
    cout << endl;

    ofstream archivo(FILENAME, ios::app);
    archivo << nombreUsuario << ":" << contrasena << "\n";
    archivo.close();

    cout << "Usuario registrado exitosamente!\n";
    cout << endl;
    cout << "========================================================================" << endl;
    cout << "Nombre de usuario: " << nombreUsuario << endl;
    cout << "Contrasena: " << contrasena << endl;
    cout << "========================================================================" << endl;
    system("pause");
    menuLogin(); // Return to menuLogin
}

// Función para iniciar sesión de un usuario existente
void iniciarSesion()
{
    string nombreUsuario, contrasena;

    cout << "Inicio de Sesion\n";
    cout << "Introduce nombre de usuario: ";
    cin >> nombreUsuario;

    string contrasenaGuardada;
    while (!cargarUsuarios(nombreUsuario, contrasenaGuardada))
    {
        cout << "Nombre de usuario no encontrado.\n";
        cout << endl;
        cout << "Ingrese el nombre de usuario nuevamente: ";
        cin >> nombreUsuario;
    }

    bool contrasenaCorrecta = false;
    while (!contrasenaCorrecta)
    {
        cout << "Introduce la contrasena: ";
        char ch;
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (!contrasena.empty())
                {
                    contrasena.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                contrasena.push_back(ch);
                cout << '*';
            }
        }
        cout << endl;

        if (contrasenaGuardada == contrasena)
        {
            cout << "Inicio de sesion exitoso!\n";
            system("pause");
            optionMainMenu();
            contrasenaCorrecta = true;
        }
        else
        {
            cout << "Contrasena incorrecta.\n";
            cout << endl;
            cout << "Ingrese la contrasena nuevamente" << endl;
            contrasena.clear();
        }
    }
}

void cambiarContrasena()
{
    string contrasenaNueva;
    string nombreUsuario;
    cout << "Cambiar Contrasena" << endl;
    cout << "Ingrese el usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese la nueva contrasena: ";
    cin >> contrasenaNueva;

    // Verificar si el usuario existe
    string contrasenaExistente;
    if (cargarUsuarios(nombreUsuario, contrasenaExistente))
    {
        // Actualizar la contraseña en el archivo
        ifstream archivo(FILENAME);
        ofstream archivoTemp("temp.txt");
        string linea;
        while (getline(archivo, linea))
        {
            size_t pos = linea.find(':');
            if (pos != string::npos)
            {
                string user = linea.substr(0, pos);
                string pass = linea.substr(pos + 1);
                if (user == nombreUsuario)
                {
                    archivoTemp << user << ":" << contrasenaNueva << "\n";
                }
                else
                {
                    archivoTemp << linea << "\n";
                }
            }
        }
        archivo.close();
        archivoTemp.close();

        // Reemplazar el archivo original con el archivo temporal
        remove(FILENAME);
        rename("temp.txt", FILENAME);
    }
    else
    {
        cout << "El usuario no existe." << endl;
    }

    cout << "Contraseña cambiada exitosamente..." << endl;
    system("pause");
    menuLogin();
}