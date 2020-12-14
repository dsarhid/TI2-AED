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
	int op = 0;
	while(op != 5) 
	{
		menu(op);
		switch (op){
			case 1:break;
			
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();
}

