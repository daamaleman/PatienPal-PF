Proceso registroNuevoPaciente
	
	Definir  op Como Entero;
	Definir paciente como cadena;
	Escribir 'Eliminar datos del paciente';
	
	Escribir "Ingrese el nombre del paciente el cual se quiera eliminar su registro:";
	Leer paciente;
	Escribir "Desea eliminar los datos del paciente? (1=S/2=N)";
	Leer op;
	
	Segun op Hacer
		1:
			Escribir 'Se elimin� el nombre del paciente';
			Escribir 'Se elimin� el apellido del paciente';
			Escribir 'Se elimin� la edad del paciente';
			Escribir 'Se elimin� el n�mero de c�dula del paciente';
			Escribir 'Se elimin� la fecha de nacimiento del paciente';
			Escribir 'Se elimin� el g�nero del paciente';
			Escribir 'Se elimin� la ciudad de residencia del paciente';
			Escribir 'Se elimin� la direcci�n del hogar del paciente';
			Escribir 'Se elimin� el n�mero telef�nico del paciente';
			Escribir 'Se elimin� el correo del paciente';
			Escribir 'Se elimin� la relaci�n del paciente';
			
		2:
			Escribir 'No se elimin� ning�n paciente';
	FinSegun
	
	Escribir "El paciente:",paciente, " fue eliminado de el registro";
	
FinProceso

