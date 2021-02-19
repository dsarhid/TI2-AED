#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "BaseDeDatos.h"

void menu (int&op)
{
	printf("\n================== CONSULTORIO VETERINARIO ===================\n\n");
	printf("1.- Iniciar Sesion\n");
	printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
	printf("3.- Registrar Evolucion de la Mascota \n");
	printf("4.- Cerrar la aplicacion \n\n");
	printf("Ingrese una opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 5)
	{
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}
main(){
	system("cls");
	int op=0, b=1, log=0, bmenu=1;
	int vFecha,Dia,Mes,Anio,Mat;
	char pass[30], apelYNom[60], nom[30],apel[30], usr[10];
	bool coincidir=true;
	while(op != 5){
		menu(op);
		switch (op){
			case 1:
				Veterinarios=fopen("Veterinarios.dat", "rb");
				
				if(Veterinarios == NULL){
					printf("\nNingun Veterinario registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(b != 0){
						if(bmenu == 0 && log == 0){
							printf("\n================== CONSULTORIO VETERINARIO ===================\n\n");
							printf("1.- Iniciar Sesion\n");
							printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
							printf("3.- Registrar Evolucion de la Mascota \n");
							printf("4.- Cerrar la aplicacion \n\n");
							printf("Ingrese una opcion: ");
						}
						printf("\nIngrese Usuario: ");
						_flushall();
						scanf("%s", &usr);
						
						while(fread(&veterinario, sizeof(vet), 1, Veterinarios) != NULL){		// Lee Empleados hasta final del archivo
							if(strcmp(usr, veterinario.usuario) == 0){						// Compara usuario leido con el usuario ingresada, se iguala a 0 para ver si son iguales.
								printf("Ingrese contrasenia: ");
								scanf("%s", &pass);
								if(strcmp(pass, veterinario.contrasenia) == 0){			// Compara contraseña leido con la contraseña ingresada, se iguala a 0 para ver si son iguales.
									printf("\n\n\tVeterinario logueado con exito. Presione una tecla para continuar...");
									b = 0;												// Cambio valor de bandera a 0 para salir del while.
									log = 1;											// Bandera de logeo cambio a 1.
									bmenu = 0;											// Bandera menu vuelve a 0.
									strcpy(apelYNom, veterinario.apellidoYNombre);			// Copio cadena de apellido y nombre de archivo y lo guardo en variable apelYNom.
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(Veterinarios);									// Vuelve al principio del archivo.
									getch();
									system("cls");
									printf("\n================== CONSULTORIO VETERINARIO ===================\n\n");
									printf("1.- Iniciar Sesion\n");
									printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
									printf("3.- Registrar Evolucion de la Mascota \n");
									printf("4.- Cerrar la aplicacion \n\n");
									printf("Ingrese una opcion: ");
									printf("\nIngrese Usuario: %s\n", usr);
								}
							}
							else{
								coincidir = false;										// Usuario no encontrado.
							}
						}
						if(coincidir != false){
							printf("Usuario no registrado. Intente nuevamente...");
							rewind(Veterinarios);											// Vuelve al principio del archivo.
							bmenu = 0;													// Bandera menu vuelve a 0.
							getch();
						}
					system("cls");
					}
				fclose(Veterinarios);														// Cierro archivo
				}
			break;
			case 2:
				b=1;
				
				if(log == 0){
					printf("\nVeterinario no logueado. No se puede realizar ninguna operacion sin loguearse.");
					getch();
					system("cls");
					break;
				}
				else{
					Veterinarios = fopen("Veterinarios.dat", "r+b");
					Mascotas = fopen("Mascotas.dat", "r+b");
					Listados = fopen("Listados.dat", "a+b");
					char apelNom[30];
					
					if(Mascotas == NULL){
						printf("\nNo hay mascotas registrados. Presione una tecla para continuar...");
						getch();
						system("cls");
						break;
					}
					else{
						while(b != 0){
							printf("\nIngrese el nombre y apellido de la mascota: \n\n");
							printf("Nombre: ");
							_flushall();
							scanf("%s", &nom);
							printf("Apellido: ");
							_flushall();
							scanf("%s", &apel);
							strcat(nom, " ");
							strcat(nom, apel);
							while(fread(&mascota, sizeof(masc), 1, Mascotas) != NULL){
								if(strcmp(nom, mascota.apellidoYNombre) == 0){
									system("cls");
									printf("\n\n\tMascota encontrada..");
									
									printf("\t\tApellido y Nombre: %s\n", mascota.apellidoYNombre);
									printf("\t\tNumero de documento (DNI): %i\n", mascota.dni);
									printf("\t\tFecha de Nacimiento: %i/%i/%i\n", mascota.fechaNacimiento.dia, mascota.fechaNacimiento.mes, mascota.fechaNacimiento.anio);
									printf("\t\tLocalidad: %s\n", mascota.localidad);
									printf("\t\tPeso: %i kg.\n", mascota.peso);
									
									
									printf("\t\tIngrese evolucion del paciente: ");
									scanf("%s", &mascota.turnos.evol);
									printf("\t\tFecha de atencion con formato (ddmmaaaa): ");
									_flushall();
									scanf("%i", &vFecha);
									convertirFecha(vFecha, Dia, Mes, Anio);
									mascota.fechaAtencion.dia = Dia;
									mascota.fechaAtencion.mes = Mes;
									mascota.fechaAtencion.anio = Anio;
									mascota.borrado = true;
									fwrite(&mascota, sizeof(vet), 1, Mascotas);
									
									
									strcpy(listado.nomVeterinario, apelYNom);
									strcpy(listado.nomMascota, mascota.apellidoYNombre);
									fwrite(&listado, sizeof(list), 1, Listados);
									
									rewind(Mascotas);
									
									coincidir = false;
									b = 0;
									
									printf("\n\n\t\t\tTurno finalizado... Presione una tecla para continuar");
									getch();
									system("cls");
									
									
									break;
								}
								else{
									coincidir = true;
								}
							}
						}
					}
					fclose(Mascotas);
					fclose(Veterinarios);
				}
			break;
			case 3:
				b=1;
				
				if(log == 0){
					printf("\nVeterinario no logueado. No se puede realizar ninguna operacion sin loguearse.");
					getch();
					system("cls");
					break;
				}
				else{
					Mascotas = fopen("Mascotas.dat", "r+b");
					Listados = fopen("Listados.dat", "a+b");
					char apelNom[30];
					
					if(Mascotas == NULL){
						printf("\nNo hay mascotas registrados. Presione una tecla para continuar...");
						getch();
						system("cls");
						break;
					}
					else{
						while(b != 0){
							printf("\t\tIngrese evolucion del paciente: ");
							scanf("%s", &mascota.turnos.evol);
							printf("\t\tFecha de atencion con formato (ddmmaaaa): ");
							_flushall();
							scanf("%i", &vFecha);
							convertirFecha(vFecha, Dia, Mes, Anio);
							mascota.fechaAtencion.dia = Dia;
							mascota.fechaAtencion.mes = Mes;
							mascota.fechaAtencion.anio = Anio;
							mascota.borrado = true;
							fwrite(&mascota, sizeof(vet), 1, Mascotas);
									
									
							strcpy(listado.nomVeterinario, apelYNom);
							strcpy(listado.nomMascota, mascota.apellidoYNombre);
							fwrite(&listado, sizeof(list), 1, Listados);
									
							rewind(Mascotas);
									
							coincidir = false;
							b = 0;
								
							printf("\n\n\t\t\tTurno finalizado... Presione una tecla para continuar");
							getch();
							system("cls");

							break;
						}
					}
				}
		}
		fclose(Mascotas);
		fclose(Listados);
	}
	
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();

}

