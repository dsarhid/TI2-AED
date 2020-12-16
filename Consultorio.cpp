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
	int op=0, Bandera=1, Loguear=0, BanderaMenu=1;
	char Pass[30], Mat[30], ApellidoNombre[60];
	char Nombre[30],Apellido[30];
	bool Coincidir=true;
	while(op != 5) 
	{
		menu(op);
		switch (op){
			case 1:
				Veterinarios = fopen("Veterinarios.dat", "rb");
	
				if( Veterinarios == NULL){
					printf("\nNingun veterinario registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(Bandera != 0){
						if(BanderaMenu == 0){
							printf("\n================== CONSULTORIO VETERINARIO ===================\n\n");
							printf("1.- Iniciar Sesion\n");
							printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
							printf("3.- Registrar Evolucion de la Mascota \n");
							printf("4.- Cerrar la aplicacion \n\n");
							printf("========================= CONSULTORIO VETERINARIO ========================\n\n");
							printf("Ingrese una opcion: ");
							
						}
						printf("\nIngrese Matricula: ");
						_flushall();
						scanf("%s", &Mat);
						
						while(fread(&veterinario, sizeof(vet), 1, Veterinarios) != NULL){
							if(strcmp(Mat, veterinario.matricula) == 0){
								Coincidir = true;
								printf("Ingrese contrasenia: ", -92);
								scanf("%s", &Pass);
								if(strcmp(Pass, veterinario.password) == 0){
									printf("\n\n\tveterinario logueado con exito. Presione una tecla para continuar...");
									Bandera = 0;
									Loguear = 1;
									BanderaMenu = 0;
									strcpy(ApellidoNombre, veterinario.apellidoYNombre);
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(Veterinarios);
									getch();
									system("cls");
								    printf("\n================== CONSULTORIO VETERINARIO ===================\n\n");
									printf("1.- Iniciar Sesion\n");
									printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
									printf("3.- Registrar Evolucion de la Mascota \n");
									printf("4.- Cerrar la aplicacion \n\n");
									printf("========================= CONSULTORIO VETERINARIO ========================\n\n");
									printf("Ingrese una opcion: ");
									printf("\nIngrese Matricula: %s\n", Mat);
								}
							}
							else{
								Coincidir = false;
							}
						}
						if(Coincidir == false){
							printf("Matricula no registrada. Intente nuevamente...");
							rewind(Veterinarios);
							BanderaMenu = 0;
							getch();
						}
					system("cls");
					}
				fclose(Veterinarios);
				}
			break;
			case 2:
				Bandera=1;
				
				if(Loguear == 0){
					printf("\nveterinario no logueado. No se puede realizar ninguna operacion sin loguearse.");
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
						while(Bandera != 0){
							printf("\nIngrese el nombre y apellido de la mascota: \n\n");
							printf("Nombre: ");
							_flushall();
							scanf("%s", &Nombre);
							printf("Apellido: ");
							_flushall();
							scanf("%s", &Apellido);
							strcat(Nombre, " ");
							strcat(Nombre, Apellido);
							while(fread(&mascota, sizeof(masc), 1, Mascotas) != NULL){
								if(strcmp(Nombre, mascota.apellidoYNombre) == 0){
									system("cls");
									printf("\n\n\tMascota encontrada..");
									//Sleep(700);
									//printf("\n\n\tCargando datos");
									//Sleep(700);
									//printf(".");
									//Sleep(700);
									//printf(".");
									//Sleep(700);
									//printf(".");
									//Sleep(700);
									//printf(".\n\n\n");
									//Sleep(300);
									printf("\t\tApellido y Nombre: %s\n", mascota.apellidoYNombre);
									printf("\t\tNumero de documento (DNI): %i\n", mascota.dni);
									printf("\t\tFecha de Nacimiento: %i/%i/%i\n", paciente.fechaNacimiento.dia, paciente.fechaNacimiento.mes, paciente.fechaNacimiento.anio);
									printf("\t\tLocalidad: %s\n", mascota.localidad);
									//printf("\t\tEdad: %i a%os\n", mascota.edad, -92);
									printf("\t\tPeso: %i kg.\n", mascota.peso);
									printf("\t\tIngrese evolucion del paciente: ");
									scanf("%s", &mascota.evol);
									printf("\t\tFecha de atencion con formato (ddmmaaaa): ");
									_flushall();
									scanf("%i", &vFecha);
									convertirFecha(vFecha, dia, mes, anio);
									paciente.fechaAtencion.dia = dia;
									paciente.fechaAtencion.mes = mes;
									paciente.fechaAtencion.anio = anio;
									paciente.borrado = true;
									fwrite(&paciente, sizeof(pac), 1, Pacientes);
									
									strcpy(paciente.sawBy, ApellidoNombre);
									strcpy(listado.nomMedico, ApellidoNombre);
									strcpy(listado.nomPaciente, paciente.apellidoYNombre);
									fwrite(&listado, sizeof(list), 1, Listados);
									
									rewind(Pacientes);
									
									notFound = false;
									Bandera = 0;
									
									printf("\n\n\t\t\tTurno finalizado... Presione una tecla para continuar");
									getch();
									system("cls");
									
									while(fread(&veterinario, sizeof(vet), 1, Veterinarios) != NULL){
										if(strcmp(paciente.sawBy, veterinario.apellidoYNombre) == 0){
											veterinario.liquidacion += paciente.obraSocial.monto;
											fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
										}
									}
									break;
								}
								else{
									notFound = true;
								}
							}
							if(notFound == true){
								rewind(Pacientes);
								printf("\nNo se encontro paciente solicitado. Busque otro paciente...");
								getch();
								system("cls");
								printf("\n---------------------- CONSULTORIO ----------------------\n\n");
								printf("1.- Iniciar Sesion.\n");
								printf("2.- Llamar paciente.\n");
								printf("3.- Salir del Programa.\n\n");
								printf("---------------------- CONSULTORIO ----------------------\n\n");
								printf("Ingrese opcion: 2\n");
							}
						}
					}
					fclose(Pacientes);
					fclose(Veterinarios);
				}
			break;
			
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();
}

