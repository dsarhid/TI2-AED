#include <stdio.h>
#include <stdlib.h>


void menu(int &op){
	printf("\nModulo del Asistente ( Recepcion )\n\n");
	printf("\n=========================\n\n");
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
	int op = 0
	while(op != 5){
		menu(op);
		switch (op){
			case 1:
			case 2:
			case 3:
			case 4:
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();
}
