 Proceso registroNuevoPaciente
		Definir nombre, apellido,cedula, genero, generoSec, cuidad, direccion, telefono, correo, relacion Como Caracter;
		Definir edad, dia, mes, anio, opGenSec, opRelacion Como Entero;
		
		Escribir "Editar datos del paciente";
		
		Escribir "Nuevos datos del paciente";
		Escribir "Ingrese el nombre: ";
		Leer nombre;
		Escribir " Ingrese el apellido: ";
		Leer apellido;
		Escribir "Ingrese la edad: ";
		Leer edad;
		Escribir "Ingrese le nuevo n�mero de Cedula: ";
		Leer cedula;
		Escribir "Fecha de nacimiento";
		Escribir "Ingresar dia de nacimiento: ";
		Leer dia;
		Escribir "Ingressar mes de nacimiento  :";
		Leer mes;
		Escribir "Ingresar a�o de nacimiento:";
		Leer anio;
		Escribir "Ingrese el g�nero: ";
		Leer genero;
		Escribir "�Desea agregar g�nero secundario? (1=S/2=N)";
		Leer opGenSec;
		Segun opGenSec Hacer
			1:
				Escribir "Agregue g�nero secundario: ";
				Leer generoSec;
			2:
				Escribir "No se agreg� genero secundario...";
		FinSegun
		Escribir "Ingresar nueva ciudad: ";
		Leer Cuidad;
		Escribir "Ingresar nueva direcci�n: ";
		Leer direccion;
		Escribir "Ingresar nuevo n�mero telef�nico: ";
		Leer telefono;
		Escribir "Ingresar nuevo correo: ";
		Leer correo;
		Escribir "Relaci�n actual (Casado, Soltero, Divorciado) ";
		Leer relacion;
		Escribir "Paciente registrado exitosamente...";
FinProceso
	

