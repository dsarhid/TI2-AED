#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"  //Libreria creada donde se habilita la base de datos


void menu(int &opcion){  //Menu para ingresar a administracion
	
	printf("\n           MODULO ADMINISTRACION   \n\n");
	printf("\n===========================================\n\n");
	printf("1.- Registrar Veterinario.\n");
	printf("2.- Registrar Usuario Asistente.\n");
	printf("3.- Atenciones por veterinarios .\n");
	printf("4.- Ranking de Veterinarios por Atenciones.\n");
	printf("5.- Cerrar aplicacion.\n\n");
	printf("===============================================\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%d", &opcion);
	if(opcion <= 0 || opcion >= 6){   //Filtra numeros entre 0 y 6
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(opcion);
	}
}


main(){
	system("cls");
	int opcion = 0, bandera = 1, log = 0, contMayus = 0, contMinus = 0, contNum = 0, contEsp = 0, contLet = 0,cantidadVet=0;
	char usrAst[10], contra[10], usrVet[10], cadAux[10], nomb[10], apell[10];
	bool cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
	
	while(opcion != 6){
		menu(opcion); // Llamada a la funcion menu
		system("cls");
		
		switch (opcion){
			case 1:
				Veterinarios = fopen("Veterinarios.dat", "a+b");  //Abre y escribe el archivo veterinarios
				
				printf("\nComplete los siguientes datos del Veterinario:\n\n");
				printf("Nombre: ");
				_flushall();
				scanf("%s", &nomb);
				printf("Apellido: ");
				_flushall();
				scanf("%s", &apell);
				strcat(nomb, " ");
				strcat(nomb, apell);
				strcpy(veterinario.apellidoYNombre, nomb);  // Nombre y Apellido en el mismo vector
				printf("Matricula: ");
				_flushall();
				scanf("%s", &veterinario.matricula);
				printf("D.N.I.: ");
				scanf("%d",&veterinario.dni);
				printf("Telefono: ");
                scanf("%s",veterinario.telefono);
                cantidadVet++;
				system("cls");
	
			
				
				while(bandera != 0){  //bandera valor verdadero b=0 contrario b=1
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					
					printf("\nIngrese Usuario: \n");
					printf("\n\tA. Comenzar con una letra minuscula.");
					printf("\n\tB. Tener al menos 2 letras mayusculas.");
					printf("\n\tC. Tener como maximo 3 numeros.");
					printf("\n\tD. Minimo 6 y maximo de 10 caracteres de longitud.\n\n");
					printf("Usuario: ");
					_flushall();
					scanf("%s", &usrVet);					
					printf("\n");
					
					//Primero se considera la longitud de la cadena,
					//luego si tiene como minimo 3 caracteres numeros
					
					if(strlen(usrVet) > 10 || strlen(usrVet) < 6){  // condicion el rango de los caracteres
						printf("Usuario no cumple con la condicion \"D.\"\n");
					}
					else{
						cumpleD = true;
					}	
					contNum = contadorNum(usrVet); // Llamada contador de caracteres numeros
					//Se utiliza el contador de caracteres numeros para saber si cumple con la condicion C  
					if(contNum > 3){
						printf("Usuario no cumple con la condicion \"C.\"\n");
					}
					else{
						cumpleC = true;
					}
					
					strcpy(cadAux, usrVet); // Se utiliza una cadena auxiliar para copiar el usuario ingresado
					strupr(cadAux); // Convertidor a mayusculas
					
					for(int i=0;i<strlen(usrVet);i++){ //Utilizacion de for para contar las letras mayusculas
						if((usrVet[i] == cadAux[i]) && (usrVet[i] != 0  || usrVet[i] != 1 || usrVet[i] != 2 || usrVet[i] != 3 || usrVet[i] != 4 || usrVet[i] != 5 || usrVet[i] != 6 || usrVet[i] != 7 || usrVet[i] != 8 || usrVet[i] != 9)){
							contMayus += 1; // Contador de mayusculas
						}
					}
					if(contMayus < 2){ //Si el valor del contador es menor a 2 el usuario es erroneo
						printf("Usuario no cumple con la condicion \"B.\"\n");
					}
					else{
						cumpleB = true; // Si cumple el valor es verdadero
					}
					
					if(usrVet[0] == cadAux[0]){ //Se aprovecha que la cadena auxiliar esta en mayusculas para saber si la primera letra esta en minusculas
						printf("Usuario no cumple con la condicion \"A.\"\n");
					}
					else{
						
						strlwr(cadAux); //Convertidor de mayusculas a minusculas
						//Se averigua si el primer caracter es un numero
						if(usrVet[0] == 0 || usrVet[0] == 1 || usrVet[0] == 2 || usrVet[0] == 3 || usrVet[0] == 4 || usrVet[0] == 5 || usrVet[0] == 6 || usrVet[0] == 7 || usrVet[0] == 8 || usrVet[0] == 9){
							printf("Usuario no cumple con la condicion \"A.\"\n");
						}
						else{
							if(usrVet[0] == cadAux[0]){ // Se averigua si el primer caracter es minuscula
								cumpleA = true;
							}
							else{
								printf("Usuario no cumple con la condicion \"A.\"\n");
							}
						}
					}
					
					//Se agrupan todos los valores booleanos falsos para volver a pedir que ingrese un Usuario correcto
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false){
						
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					//Se agrupan todos los valores booleanos verdaderos para cambiar el valor de la bandera b
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true){
						bandera = 0;
					}
				}
				
				bandera = 1;
				
				while(bandera != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					system("cls");
					
					printf("\nIngrese contrase%ca: \n", -92); // se escribe de esa manera para que aparezca la ñ por pantalla
					printf("\n\tA. Debera contener al menos una letra mayuscula, una letra minuscula y un numero.");
					printf("\n\tB. No podra contener ningun caracter de puntuacion,");
					printf("\n\t   ni acentos, ni espacios. Solo caracteres alfanumericos.");
					printf("\n\tC. Debera tener entre 6 y 32 caracteres.");
					printf("\n\tD. No debe tener mas de 3 caracteres numericos consecutivos.");
					printf("\n\tE. No debe tener 2 caracteres consecutivos que refieran a letras");
					printf("\n\t   alfabeticamente consecutivas (ascendentemente). Este criterio");
					printf("\n\t   es valido tanto para letras mayusculas, minusculas o combinacion de ambas.\n\n");
					printf("Contrase%ca: ", -92);
					_flushall();
					scanf("%s", &contra);
					
					strcpy(cadAux, contra); // Se utiliza una cadena auxiliar para copiar la contraseña ingresada
					strupr(cadAux); // Convertir a mayusculas
					
					for(int i=0;i<strlen(contra);i++){ //Contador de mayusculas, pero se verifica si no es un numero primero
						if((contra[i] == cadAux[i]) && (contra[i] != 0  || contra[i] != 1 || contra[i] != 2 || contra[i] != 3 || contra[i] != 4 || contra[i] != 5 || contra[i] != 6 || contra[i] != 7 || contra[i] != 8 || contra[i] != 9)){
							contMayus += 1;
						}
					}
					
					strlwr(cadAux); // Convertidor de mayusculas a minusculas
					
					for(int i=0;i<strlen(contra);i++){ //Contador de minusculas, antes vericando si no es un numero
						if((contra[i] == cadAux[i]) && (contra[i] != 0  || contra[i] != 1 || contra[i] != 2 || contra[i] != 3 || contra[i] != 4 || contra[i] != 5 || contra[i] != 6 || contra[i] != 7 || contra[i] != 8 || contra[i] != 9)){
							contMinus += 1;
						}
					}
					contNum = contadorNum(contra);  //LLamada contador de caracteres numeros 
					
					//Se utilizan los contadores anteriores para saber si se cumple con las condiciones almenos 1 mayuscula, 1 minuscula y 1 numero
					if(contMayus < 1){ 
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contMinus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contNum < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else{
						cumpleA = true;
					}
					
					validaCarEsp(contra, contEsp); // Llamada a la funcion para validar caracteres especiales, pasando la cadena y el contador de caracteres
					//Se utiliza el contador de caracteres especiales para saber si cumple con la condicion B
					if(contEsp >= 1){
						printf("Contrase%ca no cumple con la condicion \"B.\"\n", -92);
					}
					else{
						cumpleB = true;
					}
					
					if(strlen(contra) < 6 || strlen(contra) > 32){  //Se filtra la condicion de longitud del apartado C 
						printf("Contrase%ca no cumple con la condicion \"C.\"\n", -92);
					}
					else{
						cumpleC = true;
					}
					
					numConsecutivos(contra, contNum); //Llamada a la funcion para verificar la cantidad de numeros consecutivos
					//Se utliza el contador de numeros consecutivas para ver si cumple con la condicion D
					if(contNum > 3){
						printf("Contrase%ca no cumple con la condicion \"D.\"\n", -92);
					}
					else{
						cumpleD = true;
					}
					
					letConsecutivas(contra, contLet); //Llamada a la funcion para verificar las letras consecutivas 
					//Se utliza el contador de letras consecutivas para ver si cumple con la condicion E
					if(contLet >= 1){
						printf("Contrase%ca no cumple con la condicion \"E.\"\n", -92);
					}
					else{
						cumpleE = true;
					}
					// Se agrupan todos los valores booleanos falsos para pedir que ingrese una nueva contraseña
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false || cumpleE == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					//De la misma manera se agrupan los valores booleanos verdaderos para cambiar el valor de la bandera
					// y aceptar la contraseña ingresada
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true && cumpleE == true){
						bandera = 0;
					}
				}
				bandera=1;
				// Se copia usuario y contraseña en los correspondientes registros  
				strcpy(veterinario.usuario, usrVet);
				strcpy(veterinario.contrasenia, contra);
			
				
				fwrite(&veterinario, sizeof(vet), 1, Veterinarios); //Se escribre el usuario y la contraseña en el archivo
				
				printf("\n\n\tVeterinario registrado con exito!. Presione una tecla para continuar...");
				getch();
				system("cls");
				
				fclose(Veterinarios); // Cierra archivo Veterinarios
				
			break;
		
		    case 2:
			    Asistentes = fopen("Asistentes.dat", "a+b"); // Se abre archivo Asistentes 
				
				printf("\nComplete los siguientes datos del Asistente:\n\n");
				printf("Nombre: ");
				_flushall();
				scanf("%s", &nomb);
				printf("Apellido: ");
				_flushall();
				scanf("%s", &apell);
				strcat(nomb, " ");
				strcat(nomb, apell);
				strcpy(asistente.apellidoYNombre, nomb); //copiar el contenido en otra cadena
				system("cls");
				
				
				bandera = 1; //Se utiliza la bandera de la misma manera que en el case 1
				
				while(bandera != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					printf("\nIngrese Usuario: \n");
					printf("\n\tA. Comenzar con una letra minuscula.");
					printf("\n\tB. Tener al menos 2 letras mayusculas.");
					printf("\n\tC. Tener como maximo 3 numeros.");
					printf("\n\tD. Minimo 6 y maximo de 10 caracteres de longitud.\n\n");
					printf("Usuario: ");
					_flushall();
					scanf("%s", &usrAst);					
					printf("\n");
					
					//De la misma manera que en case 1, se procese a saber si respeta la longitud requerida
					if(strlen(usrAst) > 10 || strlen(usrAst) < 6){
						printf("Usuario no cumple con la condicion \"D.\"\n");
					}
					else{
						cumpleD = true;
					}
					
					contNum = contadorNum(usrAst); //llamada a la funcion para contar numeros en la cadena
					if(contNum > 3){
						printf("Usuario no cumple con la condicion \"C.\"\n");
					}
					else{
						cumpleC = true;
					}
					
					strcpy(cadAux, usrAst); // Copia cadena usrAst a cadAux 
					strupr(cadAux); // convierte a mayusculas la cadAux
					for(int i=0;i<strlen(usrAst);i++){ //Se procede a saber cuantas letras mayusculas hay, excluyendo a los numeros
						if((usrAst[i] == cadAux[i]) && (usrAst[i] != 0  || usrAst[i] != 1 || usrAst[i] != 2 || usrAst[i] != 3 || usrAst[i] != 4 || usrAst[i] != 5 || usrAst[i] != 6 || usrAst[i] != 7 || usrAst[i] != 8 || usrAst[i] != 9)){
							contMayus += 1;
						}
					}
					if(contMayus < 2){  
						printf("Usuario no cumple con la condicion \"B.\"\n");
					}
					else{
						cumpleB = true;
					}
					
					if(usrAst[0] == cadAux[0]){ //Se aprovecha la cadAux se encuntra en mayusculas para saber si el primer caracter esta en minuscula
						printf("Usuario no cumple con la condicion \"A.\"\n");
					}
					else{
						strlwr(cadAux); //convertidor de mayusculas a minusculas
						//Se consulta si el primer caracter es un numero, caso contrario el usuario cumple con la condicion
						if(usrAst[0] == 0 || usrAst[0] == 1 || usrAst[0] == 2 || usrAst[0] == 3 || usrAst[0] == 4 || usrAst[0] == 5 || usrAst[0] == 6 || usrAst[0] == 7 || usrAst[0] == 8 || usrAst[0] == 9){
							printf("Usuario no cumple con la condicion \"A.\"\n");
						}
						else{
							if(usrAst[0] == cadAux[0]){
								cumpleA = true;
							}
							else{
								printf("Usuario no cumple con la condicion \"A.\"\n");
							}
						}
					}
					
					//Se juntan todos los valores booleanos falsos para pedir que ingrese un nuevo usuario
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					
					//Se juntan todos los valores booleanos verdaderos para cambiar el valor de bandera y solicitar la contraseña del usuario
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true){
						bandera = 0;
					}
				}
				
				
				bandera = 1; //Al cambiar el valor de la bandera se acepta el usuario y solicita contraseña del mismo
				
				while(bandera != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					system("cls");
					printf("\nIngrese contrase%ca: \n", -92);
					printf("\n\tA. Debera contener al menos una letra mayuscula, una letra minuscula y un numero.");
					printf("\n\tB. No podra contener ningun caracter de puntuacion,");
					printf("\n\t   ni acentos, ni espacios. Solo caracteres alfanumericos.");
					printf("\n\tC. Debera tener entre 6 y 32 caracteres.");
					printf("\n\tD. No debe tener mas de 3 caracteres numericos consecutivos.");
					printf("\n\tE. No debe tener 2 caracteres consecutivos que refieran a letras");
					printf("\n\t   alfabeticamente consecutivas (ascendentemente). Este criterio");
					printf("\n\t   es valido tanto para letras mayusculas, minusculas o combinacion de ambas.\n\n");
					printf("Contrase%ca: ", -92);
					_flushall();
					scanf("%s", &contra);
					
					// Al igual que el caso 1 se codifica de la misma manera el ingreso de contraseña del usuario
					strcpy(cadAux, contra); //El contenido de la cadena contraseña se copia en la cadAux
					strupr(cadAux); //Convertidor de minusculas a mayusculas
					
					for(int i=0;i<strlen(contra);i++){ //cuenta la cantidad de caracteres mayusculas
						if((contra[i] == cadAux[i]) && (contra[i] != 0  || contra[i] != 1 || contra[i] != 2 || contra[i] != 3 || contra[i] != 4 || contra[i] != 5 || contra[i] != 6 || contra[i] != 7 || contra[i] != 8 || contra[i] != 9)){
							contMayus += 1;
						}
					}
					strlwr(cadAux); //Convertidor de mayusculas a minusculas
					for(int i=0;i<strlen(contra);i++){ //cuenta la cantidad de caracteres minusculas
						if((contra[i] == cadAux[i]) && (contra[i] != 0  || contra[i] != 1 || contra[i] != 2 || contra[i] != 3 || contra[i] != 4 || contra[i] != 5 || contra[i] != 6 || contra[i] != 7 || contra[i] != 8 || contra[i] != 9)){
							contMinus += 1;
						}
					}
					contNum = contadorNum(contra); //Llamada a la funcion contador de numeros, cuenta la canitdad de caracteres numeros que existe en la cadena
					
					//Utilizando los contadores anteriores verifica si respeta el apartado A 
					if(contMayus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contMinus < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else if(contNum < 1){
						printf("Contrase%ca no cumple con la condicion \"A.\"\n", -92);
					}
					else{
						cumpleA = true;
					}
					
					validaCarEsp(contra, contEsp); //Llamada a la funcion que valida caracteres especiales
					
					if(contEsp >= 1){ //Utiliza el contador de caracteres especiales para saber si existe uno
						printf("Contrase%ca no cumple con la condicion \"B.\"\n", -92);
					}
					else{
						cumpleB = true;
					}
					
					if(strlen(contra) < 6 || strlen(contra) > 32){ //Condicion de longitud de la contraseña
						printf("Contrase%ca no cumple con la condicion \"C.\"\n", -92);
					}
					else{
						cumpleC = true;
					}
					
					numConsecutivos(contra, contNum); //Llamada a la funcion numeros consecutivos 
					
					if(contNum > 3){ //Utiliza el contador de numetos consecutivos para ver si cumple con la condicion D
						printf("Contrase%ca no cumple con la condicion \"D.\"\n", -92);
					}
					else{
						cumpleD = true;
					}
					
					letConsecutivas(contra, contLet); //Llamada a la funcion letras consecutivas
					
					if(contLet >= 1){ //Se utiliza el contador de letras consecutivas para saber si existen letras consecutivas
						printf("Contrase%ca no cumple con la condicion \"E.\"\n", -92);
					}
					else{
						cumpleE = true;
					}
					
					//Se juntan todos los valores booleanos falsos para volver a solicitar una contraseña
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false || cumpleE == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					//Se juntan todos los valores booleanos verdaderos para aceptar la contraseña, cambiando el valor de la bandera
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true && cumpleE == true){
						bandera = 0;
					}
				}
				//Se copia las cadenas en las cadenas de los registros para tener un archivo registro
				strcpy(asistente.usuario, usrAst);
				strcpy(asistente.contrasenia, contra);
				
				fwrite(&asistente, sizeof(asist), 1, Asistentes);
				
				printf("\n\n\tAsistenre registrado con exito!. Presione una tecla para continuar...");
				getch();
				system("cls");
				
				
				
			    fclose(Asistentes); //Se cierra archivo Asistentes
					
			break;
			case 3:
				Veterinarios = fopen("Veterinarios.dat", "r+b");

				if(Veterinarios == NULL){
					printf("\n\n\tNingun veterinario registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					
					fread(&veterinario, sizeof(vet), 1, Veterinarios);
					
					while( !feof(Veterinarios)){
						printf("\n\tVeterinario: %s\n", veterinario.apellidoYNombre);
						calcularSemana();
						fread(&veterinario, sizeof(vet), 1, Veterinarios);
					}
                }
                
                fclose(Veterinarios);

			break;
		
		
        }
				
	  getch();
   }}

