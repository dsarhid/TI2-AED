#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"

void menu(int &op){
	printf("\nModulo del Asistente ( Recepcion )\n");
	printf("\n==========================================\n\n");
	printf("1.- Iniciar Sesion.\n");
	printf("2.- Registrar Mascota.\n");
	printf("3.- Registrar Turno.\n");
	printf("4.- Listado de Atenciones por Veterinario y Fecha.\n");
	printf("5.- Cerrar la aplicacion.\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 6){
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}


main(){
	system("cls");
	int op = 0, b = 1, bmenu = 1, log = 0;
	char usr[10], pass[10], apelYNom[30];
	bool coincidir = false;
	
	while(op != 5){
		menu(op);
		switch (op){
			case 1:
				Asistentes = fopen("Asistentes.dat", "rb");											// Abro archivo Empleados en modo lectura para binarios.
				if(Asistentes == NULL){
					printf("\nNingun Empleado registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(b != 0){
						if(bmenu == 0){
							printf("\nModulo del Asistente ( Recepcion )\n");
							printf("\n==========================================\n\n");
							printf("1.- Iniciar Sesion.\n");
							printf("2.- Registrar Mascota.\n");
							printf("3.- Registrar Turno.\n");
							printf("4.- Listado de Atenciones por Veterinario y Fecha.\n");
							printf("5.- Cerrar la aplicacion.\n\n");
							printf("Ingrese opcion: 1\n");
						}
						printf("\nIngrese Usuario: ");
						_flushall();
						scanf("%s", &usr);
						
						while(fread(&asistente, sizeof(asist), 1, Asistentes) != NULL){		// Lee Empleados hasta final del archivo
							if(strcmp(usr, asistente.usuario) == 0){						// Compara usuario leido con el usuario ingresada, se iguala a 0 para ver si son iguales.
								coincidir = true;										// Usuario encontrado.
								printf("Ingrese contrasenia: ", -92);
								scanf("%s", &pass);
								if(strcmp(pass, asistente.contrasenia) == 0){			// Compara contraseña leido con la contraseña ingresada, se iguala a 0 para ver si son iguales.
									printf("\n\n\tAsistente logueado con exito. Presione una tecla para continuar...");
									b = 0;												// Cambio valor de bandera a 0 para salir del while.
									log = 1;											// Bandera de logeo cambio a 1.
									bmenu = 0;											// Bandera menu vuelve a 0.
									strcpy(apelYNom, asistente.apellidoYNombre);			// Copio cadena de apellido y nombre de archivo y lo guardo en variable apelYNom.
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(Asistentes);									// Vuelve al principio del archivo.
									getch();
									system("cls");
									printf("\nModulo del Asistente ( Recepcion )\n");
									printf("\n==========================================\n\n");
									printf("1.- Iniciar Sesion.\n");
									printf("2.- Registrar Mascota.\n");
									printf("3.- Registrar Turno.\n");
									printf("4.- Listado de Atenciones por Veterinario y Fecha.\n");
									printf("5.- Cerrar la aplicacion.\n\n");
									printf("Ingrese opcion: 1\n");
									printf("\nIngrese Usuario: %s\n", usr);
								}
							}
							else{
								coincidir = false;										// Usuario no encontrado.
							}
						}
						if(coincidir == false){
							printf("Usuario no registrado. Intente nuevamente...");
							rewind(Asistentes);											// Vuelve al principio del archivo.
							bmenu = 0;													// Bandera menu vuelve a 0.
							getch();
						}
					system("cls");
					}
				fclose(Asistentes);														// Cierro archivo
				}
			break;
			case 2:break;
			case 3:break;
			case 4:break;
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();
}
