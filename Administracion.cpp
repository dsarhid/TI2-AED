#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"  //libreria creada donde se habilita la base de datos


void menu(int &op){  //menu para ingresar a administracion
	printf("\n---------------------- ADMINISTRACION ----------------------\n\n");
	printf("1.- Registrar Veterinario.\n");
	printf("2.- Registrar Usuario Asistente.\n");
	printf("3.- Registrar Obra Social y Monto.\n");
	printf("4.- Liquidacion de Medicos.\n");
	printf("5.- Empleado con Mayor Registro.\n");
	printf("6.- Salir del Programa.\n\n");
	printf("---------------------- ADMINISTRACION ----------------------\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%i", &op);
	if(op <= 0 || op >= 7){   //Filtra numeros entre 0 y 7
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}

