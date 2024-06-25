Proceso registroNuevoPaciente
	Definir nombre, apellido,cedula, genero, generoSec, cuidad, direccion, telefono, correo, relacion Como Caracter;
	Definir edad, dia, mes, anio, opGenSec, opRelacion Como Entero;
	Escribir "Datos del paciente";
	Escribir "Nombre: ";
	Leer nombre;
	Escribir "Apellido: ";
	Leer apellido;
	Escribir "Edad: ";
	Leer edad;
	Escribir "Numero de Cedula: ";
	Leer cedula;
	Escribir "Fecha de nacimiento";
	Escribir "Dia: ";
	Leer dia;
	Escribir "Mes :";
	Leer mes;
	Escribir "Anio :";
	Leer anio;
	Escribir "Genero: ";
	Leer genero;
	Escribir "¿Desea agregar genero secundario? (1=S/2=N)";
	Leer opGenSec;
	Segun opGenSec Hacer
		1:
			Escribir "Agrege genero secundario: ";
			Leer generoSec;
		2:
			Escribir "No se agregó genero secundario...";
	FinSegun
	Escribir "Cuidad: ";
	Leer Cuidad;
	Escribir "Direccion: ";
	Leer direccion;
	Escribir "Telefono: ";
	Leer telefono;
	Escribir "Correo: ";
	Leer correo;
	Escribir "Relacion actual (Casado, Soltero, Divorciado) ";
	Leer relacion;
	Escribir "Paciente registrado exitosamente...";
FinProceso