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
	char Pass[30], Mat[30]; ApellidoNombre[60];
	bool Coincidir=true;
	int op = 0;
	while(op != 5) 
	{
		menu(op);
		switch (op){
			case 1:
				Veterinarios = fopen("Veterinarios.dat", "rb");
	
				if( == NULL){
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
						
						while(fread(&veterinario, sizeof(vet), 1, veterinarios) != NULL){
							if(strcmp(Mat, veterinario.matricula) == 0){
								Coincidir = true;
								printf("Ingrese contrasenia: ", -92);
								scanf("%s", &Pass);
								if(strcmp(Pass, veterinario.password) == 0){
									printf("\n\n\tveterinario logueado con exito. Presione una tecla para continuar...");
									band = 0;
									loguear = 1;
									bandMenu = 0;
									strcpy(apellidoNombre, veterinario.apellidoYNombre);
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(veterinarios);
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
							rewind(veterinarios);
							bandMenu = 0;
							getch();
						}
					system("cls");
					}
				fclose(veterinarios);
				}
			break;
			
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();
}

