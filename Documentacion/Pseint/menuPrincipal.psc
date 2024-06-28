Proceso PatientPall
	Definir opcion_1, opcion_2, opcion_3 Como Entero;
	
	
	Escribir "Menu principal";
	Escribir "1. Ingresar al menu pacientes";
	Escribir "2. Ingresar al menu citas";
	Escribir "3. Salir";
	Leer opcion_1;
	
	Segun opcion_1 Hacer
		1:
			Escribir "Menu paciente";
			Escribir "1. Registrar nuevo paciente";
			Escribir "2. Editar datos de paciente";
			Escribir "3. Eliminar datos de un paciente";
			Escribir "4. Mostrar pacientes";
			Escribir "5. Buscar paciente por ID";
			Escribir "6. Salir al menu principal";
			Escribir "7. Salir del programa";
		2:
			Escribir "Menu citas";
			Escribir "1. Agendar nueva cita";
			Escribir "2. Eliminar cita";
			Escribir "3. Editar datos de una cita";
			Escribir "4. Mostrar citas";
			Escribir "5. Recargar archivo de citas";
			Escribir "6. Salir al menu principal";
			Escribir "7. Salir del programa";
		De Otro Modo:
			Escribir "Opcion incorrecta, elija otra opcion";
	FinSegun
FinProceso
