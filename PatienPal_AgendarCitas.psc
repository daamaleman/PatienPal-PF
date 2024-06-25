Proceso PatienPal_AgendarCitas
	Definir opcion Como Entero;
	Definir i Como Entero;
	Definir posicion Como Entero;
	Definir llegada Como Logico;
	Definir nombre Como Cadena;
	Definir nombres Como Cadena;
	Dimensionar nombres(100);
	Definir fecha Como Cadena;
	Definir fechas Como Cadena;
	Dimensionar fechas(100);
	Definir paciente Como Entero;
	Definir pacientes Como Entero;
	Dimensionar pacientes(100);
	Definir hora Como Entero;
	Definir horas Como Entero;
	Dimensionar horas(100);
	Definir minuto Como Entero;
	Definir minutos Como Entero;
	Dimensionar minutos(100);
	posicion <- 0;
	Repetir
		Escribir 'Escoge tus opciones';
		Escribir '1. Agregar cita';
		Escribir '2. Mostrar citas';
		Escribir '3. Editar listado de citas';
		Escribir '4. Salir';
		Leer opcion;
		Segun opcion Hacer
			1:
				Escribir 'Ingresa tu nombre:';
				Leer nombre;
				nombres[posicion] <- nombre;
				Escribir 'Ingresa tu numero de telefono:';
				Leer paciente;
				pacientes[posicion] <- paciente;
				Escribir 'Ingresa la fecha de la cita :';
				Leer fecha;
				fechas[posicion] <- fecha;
				Escribir 'Ingresa la hora de tu llegada del paciente(formato 24 horas):';
				Leer hora;
				horas[posicion] <- hora;
				Escribir 'Ingrese los minutos de llegada:';
				Leer minuto;
				minutos[posicion] <- minuto;
				posicion <- posicion+1;
			2:
				Para i<-0 Hasta posicion-1 Con Paso 1 Hacer
					Si horas[i]>9 O (horas[i]=9 Y minutos[i]>0) Entonces
						llegada <- Verdadero;
					SiNo
						llegada <- Falso;
					FinSi
					Si llegada Entonces
						Escribir 'El paciente ', nombres[i], ' su numero telefonico es: ', pacientes[i], ' llegó tarde a la cita ', fechas[i], ' a las ', horas[i], ':', minutos[i];
						Escribir '';
					SiNo
						Escribir 'El paciente ', nombres[i], ' su numero telefonico es: ', pacientes[i], ' llegó puntual a la cita ', fechas[i], ' a las ', horas[i], ':', minutos[i];
						Escribir '';
					FinSi
				FinPara
			3:
				Escribir 'Editar cita';
				Escribir 'Ingresa tu nombre:';
				Leer nombre;
				nombres[posicion] <- nombre;
				Escribir 'Ingresa tu numero de telefono:';
				Leer paciente;
				pacientes[posicion] <- paciente;
				Escribir 'Ingresa la fecha de la cita:';
				Leer fecha;
				fechas[posicion] <- fecha;
				Escribir 'Ingresa la hora de llegada del paciente(formato 24 horas):';
				Leer hora;
				horas[posicion] <- hora;
				Escribir 'Ingrese los minutos de llegada:';
				Leer minuto;
				minutos[posicion] <- minuto;
				posicion <- posicion+1;
			4:
				Escribir 'Saliendo...';
			De Otro Modo:
				Escribir 'Opcion invalida, vuelve a intentarlo';
		FinSegun
	Hasta Que opcion=3
FinProceso
