#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"  //libreria creada donde se habilita la base de datos


void menu(int &op){  //menu para ingresar a administracion
	printf("\nModulo Administracion\n\n");
	printf("\n==========================================\n\n");
	printf("1.- Registrar Veterinario.\n");
	printf("2.- Registrar Usuario Asistente.\n");
	printf("3.- Atenciones por Veterinarios\n");
	printf("4.- Ranking de Veterinarios por Atenciones\n");
	printf("6.- Cerrar la aplicacion.\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 6){   //Filtra numeros entre 0 y 7
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}

