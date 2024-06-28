Proceso menuLogin
	Definir opcion_1 Como Entero;
	Definir nombreUsuario, contrasena, nuevoUsuario, nuevaContrasena Como Caracter;
	
	Escribir "Menu Login";
	Escribir "1. Registrar nuevo usuario";
	Escribir "2. Iniciar sesión";
	Escribir "3. Salir del programa";
	Leer opcion_1;
	
	Segun opcion_1 Hacer
		1:
			Escribir "Registro de Usuario";
			Escribir "Introduce nombre de usuario: ";
			Si nuevoUsuario == nombreUsuario Entonces
				Escribir "El nombre de usuario ya existe. Prueba con otro.";
			FinSi
			Escribir "Introduce la contrasena: ";
			Leer nuevaContrasena;
			Escribir "Usuario registrado exitosamente!";
		2:
			Escribir "Inicio de Sesion";
			Escribir "Introduce nombre de usuario: ";
			Si nombreUsuario == nuevoUsuario Entonces
				Escribir "Nombre de usuario no encontrado";
			FinSi
			Escribir "Introduce la contrasena: ";
			Si contrasena == nuevaContrasena Entonces
				Escribir "Inicio de sesion exitoso!";
			SiNo
				Escribir "Contrasena incorrecta.";
			FinSi
		De Otro Modo:
			Escribir "Opcion incorrecta, elija otra opcion";
	FinSegun
FinProceso
