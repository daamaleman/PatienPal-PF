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
			Escribir 'Se eliminó el nombre del paciente';
			Escribir 'Se eliminó el apellido del paciente';
			Escribir 'Se eliminó la edad del paciente';
			Escribir 'Se eliminó el número de cédula del paciente';
			Escribir 'Se eliminó la fecha de nacimiento del paciente';
			Escribir 'Se eliminó el género del paciente';
			Escribir 'Se eliminó la ciudad de residencia del paciente';
			Escribir 'Se eliminó la dirección del hogar del paciente';
			Escribir 'Se eliminó el número telefónico del paciente';
			Escribir 'Se eliminó el correo del paciente';
			Escribir 'Se eliminó la relación del paciente';
			
		2:
			Escribir 'No se eliminó ningún paciente';
	FinSegun
	
	Escribir "El paciente:",paciente, " fue eliminado de el registro";
	
FinProceso

