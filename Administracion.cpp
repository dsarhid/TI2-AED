#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"  //Libreria creada donde se habilita la base de datos


void menu(int &op){  //Menu para ingresar a administracion
	
	printf("\n---------------------- ADMINISTRACION ----------------------\n\n");
	printf("1.- Registrar Veterinario.\n");
	printf("2.- Registrar Usuario Asistente.\n");
	printf("3.- Atenciones por veterinarios .\n");
	printf("4.- Ranking de Veterinarios por Atenciones.\n");
	printf("5.- Cerrar aplicacion.\n\n");
	printf("---------------------- ADMINISTRACION ----------------------\n\n");
	printf("Ingrese opcion: ");
	_flushall();
	scanf("%d", &op);
	if(op <= 0 || op >= 6){   //Filtra numeros entre 0 y 6
		printf("Ingresar una opcion valida. Presione una tecla para continuar...");
		getch();
		system("cls");
		menu(op);
	}
}


main(){
	system("cls");
	int op = 0, b = 1, log = 0, contMayus = 0, contMinus = 0, contNum = 0, contEsp = 0, contLet = 0;
	char usrAst[30], pass[30], usrVet[30], cadAux[30], nom[30], apel[30];
	bool notFound = true, cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
	
	while(op != 6){
		menu(op); // Llamada a la funcion menu
		system("cls");
		
		switch (op){
			case 1:
				Veterinarios = fopen("Veterinarios.dat", "a+b");  //Abre el archivo veterinarios
				
				printf("\nComplete los siguientes datos del Veterinario:\n\n");
				printf("Nombre: ");
				_flushall();
				scanf("%s", &nom);
				printf("Apellido: ");
				_flushall();
				scanf("%s", &apel);
				strcat(nom, " ");
				strcat(nom, apel);
				strcpy(veterinario.apellidoYNombre, nom);  // Nombre y Apellido en el mismo vector
				printf("Matricula: ");
				_flushall();
				scanf("%s", &veterinario.matricula);
				printf("D.N.I.: ");
				scanf("%d",&veterinario.dni);
				printf("Telefono: ");
                scanf("%s",veterinario.telefono);
				system("cls");
	
			
				
				while(b != 0){  //bandera valor verdadero b=0 contrario b=1
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
					contNum = contadorNum(usrVet); // llamada contador de caracteres numeros
					
					if(contNum > 3){
						printf("Usuario no cumple con la condicion \"C.\"\n");
					}
					else{
						cumpleC = true;
					}
					
					strcpy(cadAux, usrVet); // se utiliza una cadena auxiliar para traspasar el usuario ingresado
					strupr(cadAux); // convertidor a mayusculas
					
					for(int i=0;i<strlen(usrVet);i++){ //utilizacion de for para contar las letras mayusculas
						if((usrVet[i] == cadAux[i]) && (usrVet[i] != 0  || usrVet[i] != 1 || usrVet[i] != 2 || usrVet[i] != 3 || usrVet[i] != 4 || usrVet[i] != 5 || usrVet[i] != 6 || usrVet[i] != 7 || usrVet[i] != 8 || usrVet[i] != 9)){
							contMayus += 1; // contador de mayusculas
						}
					}
					if(contMayus < 2){ //si el valor del contador es menor a 2 el usuario es erroneo
						printf("Usuario no cumple con la condicion \"B.\"\n");
					}
					else{
						cumpleB = true; // si cumple el valor es verdadero
					}
					
					if(usrVet[0] == cadAux[0]){ //se aprovecha que la cadena auxiliar esta en mayusculas para saber si la primera letra esta en minusculas
						printf("Usuario no cumple con la condicion \"A.\"\n");
					}
					else{
						
						strlwr(cadAux); //convertidor de mayusculas a minusculas
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
					
					//Se junta todos los valores booleanos falsos para volver a pedir que ingrese un Usuario correcto
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false){
						
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					//Se junta todos los valores booleanos verdaderos para cambiar el valor de la bandera b
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true){
						b = 0;
					}
				}
				
				b = 1;
				
				while(b != 0){
					cumpleA = false, cumpleB = false, cumpleC = false, cumpleD = false, cumpleE = false;
					contMayus = 0, contMinus = 0, contNum = 0;
					system("cls");
					
					printf("\nIngrese contrase%ca: \n", -92); // se escribe de esa manera para que aparezca la ņ por pantalla
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
					scanf("%s", &pass);
					
					strcpy(cadAux, pass); // se utiliza una cadena auxiliar para traspasar la contraseņa ingresada
					strupr(cadAux); // convertir a mayusculas
					
					for(int i=0;i<strlen(pass);i++){ //contador de mayusculas, pero se verifica si no es un numero primero
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMayus += 1;
						}
					}
					
					strlwr(cadAux); // convertidor de mayusculas a minusculas
					
					for(int i=0;i<strlen(pass);i++){ //contador de minusculas, antes vericando si no es un numero
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMinus += 1;
						}
					}
					contNum = contadorNum(pass);  //llamada contador de caracteres numeros 
					
					if(contMayus < 1){ //condiciones de la contraseņa
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
					
					validaCarEsp(pass, contEsp); // llamada a la funcion para validar caracteres especiales, pasando la cadena y el contador de caracteres
					
					if(contEsp >= 1){
						printf("Contrase%ca no cumple con la condicion \"B.\"\n", -92);
					}
					else{
						cumpleB = true;
					}
					
					if(strlen(pass) < 6 || strlen(pass) > 32){  //condicion de longitud 
						printf("Contrase%ca no cumple con la condicion \"C.\"\n", -92);
					}
					else{
						cumpleC = true;
					}
					
					numConsecutivos(pass, contNum); //Llamada a la funcion para verificar la cantidad de numeros consecutivos
					//Se utliza el contador de numeros consecutivas para ver si cumple con la condicion D
					if(contNum > 3){
						printf("Contrase%ca no cumple con la condicion \"D.\"\n", -92);
					}
					else{
						cumpleD = true;
					}
					
					letConsecutivas(pass, contLet); //Llamada a la funcion para verificar las letras consecutivas 
					//Se utliza el contador de letras consecutivas para ver si cumple con la condicion E
					if(contLet >= 1){
						printf("Contrase%ca no cumple con la condicion \"E.\"\n", -92);
					}
					else{
						cumpleE = true;
					}
					// Se agrupan todos los valores booleanos falsos para pedir que ingrese una nueva contraseņa
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false || cumpleE == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					//De la misma manera se agrupan los valores booleanos verdaderos para cambiar el valor de la bandera
					// y aceptar la contraseņa ingresada
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true && cumpleE == true){
						b = 0;
					}
				}
				// Se copia usuario y contraseņa en los correspondientes registros  
				strcpy(veterinario.usuario, usrVet);
				strcpy(veterinario.password, pass);
			
				
				fwrite(&veterinario, sizeof(med), 1, Veterinarios); //Se escribre el usuario y la contraseņa en el archivo
				
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
				scanf("%s", &nom);
				printf("Apellido: ");
				_flushall();
				scanf("%s", &apel);
				strcat(nom, " ");
				strcat(nom, apel);
				strcpy(asistente.apellidoYNombre, nom); //copiar el contenido en otra cadena
				system("cls");
				
				
				b = 1; //Se utiliza la bandera de la misma manera que en el case 1
				
				while(b != 0){
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
					
					//Se juntan todos los valores booleanos verdaderos para cambiar el valor de bandera y solicitar la contraseņa del usuario
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true){
						b = 0;
					}
				}
				
				
				b = 1; //Al cambiar el valor de la bandera se acepta el usuario y solicita contraseņa del mismo
				
				while(b != 0){
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
					scanf("%s", &pass);
					
					// Al igual que el caso 1 se codifica de la misma manera el ingreso de contraseņa del usuario
					strcpy(cadAux, pass); //El contenido de la cadena contraseņa se copia en la cadAux
					strupr(cadAux); //Convertidor de minusculas a mayusculas
					
					for(int i=0;i<strlen(pass);i++){ //cuenta la cantidad de caracteres mayusculas
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMayus += 1;
						}
					}
					strlwr(cadAux); //Convertidor de mayusculas a minusculas
					for(int i=0;i<strlen(pass);i++){ //cuenta la cantidad de caracteres minusculas
						if((pass[i] == cadAux[i]) && (pass[i] != 0  || pass[i] != 1 || pass[i] != 2 || pass[i] != 3 || pass[i] != 4 || pass[i] != 5 || pass[i] != 6 || pass[i] != 7 || pass[i] != 8 || pass[i] != 9)){
							contMinus += 1;
						}
					}
					contNum = contadorNum(pass); //Llamada a la funcion contador de numeros, cuenta la canitdad de caracteres numeros que existe en la cadena
					
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
					
					validaCarEsp(pass, contEsp); //Llamada a la funcion que valida caracteres especiales
					
					if(contEsp >= 1){ //Utiliza el contador de caracteres especiales para saber si existe uno
						printf("Contrase%ca no cumple con la condicion \"B.\"\n", -92);
					}
					else{
						cumpleB = true;
					}
					
					if(strlen(pass) < 6 || strlen(pass) > 32){ //Condicion de longitud de la contraseņa
						printf("Contrase%ca no cumple con la condicion \"C.\"\n", -92);
					}
					else{
						cumpleC = true;
					}
					
					numConsecutivos(pass, contNum); //Llamada a la funcion numeros consecutivos 
					
					if(contNum > 3){ //Utiliza el contador de numetos consecutivos para ver si cumple con la condicion D
						printf("Contrase%ca no cumple con la condicion \"D.\"\n", -92);
					}
					else{
						cumpleD = true;
					}
					
					letConsecutivas(pass, contLet); //Llamada a la funcion letras consecutivas
					
					if(contLet >= 1){ //Se utiliza el contador de letras consecutivas para saber si existen letras consecutivas
						printf("Contrase%ca no cumple con la condicion \"E.\"\n", -92);
					}
					else{
						cumpleE = true;
					}
					
					//Se juntan todos los valores booleanos falsos para volver a solicitar una contraseņa
					if(cumpleA == false || cumpleB == false || cumpleC == false || cumpleD == false || cumpleE == false){
						printf("\nPresione una tecla para volver a ingresar...");
						getch();
						system("cls");
					}
					//Se juntan todos los valores booleanos verdaderos para aceptar la contraseņa, cambiando el valor de la bandera
					if(cumpleA == true && cumpleB == true && cumpleC == true && cumpleD == true && cumpleE == true){
						b = 0;
					}
				}
				//Se copia las cadenas en las cadenas de los registros para tener un archivo registro
				strcpy(asistente.usuario, usrAst);
				strcpy(asistente.password, pass);
				
				fwrite(&asistente, sizeof(asist), 1, Asistentes);
				
				printf("\n\n\tAsistenre registrado con exito!. Presione una tecla para continuar...");
				getch();
				system("cls");
				
				
				
			    fclose(Asistentes); //Se cierra archivo Asistentes
					
			break;
		
		}
    }
				
	getch();
}

