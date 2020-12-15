#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//--------------------------------ARCHIVOS-----------------------------------

FILE *	Veterinarios;
FILE *  Asistentes;
FILE *	Mascotas;



//-------------------------------REGISTROS-----------------------------------
struct fec{
	int dia, mes, anio;
};
struct hor{
	int desde, hasta;
};
struct sem{
	int lun, mar, mie, jue, vie, sab;
	struct hor lunh;
	struct hor marh;
	struct hor mieh;
	struct hor jueh;
	struct hor vieh;
	struct hor sabh;
};
struct tur{
	int turnLun, turnMar, turnMie, turnJue, turnVie, turnSab;
};
struct vet{
	int dni;
	char apellidoYNombre[60], matricula[30], password[30], telefono[25] ,usuario[30];
	struct sem diasAtencion;
	struct tur turnos;
};
struct asist{
	int cantRegistros;
	char apellidoYNombre[30], usuario[10], contrasenia[10];
};
struct masc{
	int dni, peso;
	char apellidoYNombre[60], localidad[0], evol[380], domicilio[60];
	//struct fec fechaAtencion;
	struct fec fechaNacimiento;
	bool borrado;
};


vet veterinario;
asist asistente;
masc mascota;


// --------------------------------FUNCIONES---------------------------------

int contadorNum(char cadena[]){  //funcion cuenta la cantidad de numeros que hay en la cadena
	int cont = 0;
	int i = 0;
	int cero = 0;
	int uno = 0;
	int dos = 0;
	int tres = 0;
	int cuatro = 0;
	int cinco = 0;
	int seis = 0;
	int siete = 0;
	int ocho = 0;
	int nueve = 0;
	
	while(cadena[i]!='\0'){
		switch(cadena[i]){ 
 			case '0':
          		cero++;
          	break;
          	
          	case '1':
          		uno++;
          	break;
          	
          	case '2':
          		dos++;
          	break;
          	
          	case '3':
          		tres++;
          	break;
          	
          	case '4':
          		cuatro++;
          	break;
          	
          	case '5':
          		cinco++;
          	break;
          	
          	case '6':
          		seis++;
          	break;
          	
          	case '7':
          		siete++;
          	break;
          	
          	case '8':
          		ocho++;
          	break;
          	
          	case '9':
          		nueve++;
          	break;
        }
    	i++;
	}
	cont = uno + dos + tres + cuatro + cinco + seis + siete + ocho + nueve;
	
	return cont;
}

//Cadena de caracteres especiales con valores ASCII
char ASCII[] = {160, 130, 161, 162, 163, 32, 181, 144, 214, 224, 233, 132, 137, 139, 148, 129, 142, 211, 216, 153, 154, 64, 168, 63, 173, 33, 58, 57, 92, 34, 39, 40, 41, 91, 93, 123, 125, 174, 175, 36, 156, 190, 189, 207, 169, 184, 166, 167, 248};


void validaCarEsp(char cadena[], int &cont){ //funcion para validad caracteres especiales 
	cont = 0;
	
	for(int i=0;i<strlen(cadena);i++){
		for(int j=0;j<strlen(ASCII);j++){ // se utiliza la cadena ASCII para verificar
			if(cadena[i] == ASCII[j]){
				cont += 1;
			}
		}
	}
}


void numConsecutivos(char cadena[], int &cont){ //Funcion que cuneta la cantidad de numeros consecutivos
	cont = 0;
	
	for(int i=0;i<strlen(cadena);i++){
		if(cadena[i] == '0'){
			cont += 1;
		}
		else if(cadena[i] == '1'){
			cont += 1;
		}
		else if(cadena[i] == '2'){
			cont += 1;
		}
		else if(cadena[i] == '3'){
			cont += 1;
		}
		else if(cadena[i] == '4'){
			cont += 1;
		}
		else if(cadena[i] == '5'){
			cont += 1;
		}
		else if(cadena[i] == '6'){
			cont += 1;
		}
		else if(cadena[i] == '7'){
			cont += 1;
		}
		else if(cadena[i] == '8'){
			cont += 1;
		}
		else if(cadena[i] == '9'){
			cont += 1;
		}
		else{
			cont = 0;
		}
	}
}

void letConsecutivas(char cadena[], int &cont){  //funcion letras consecutivas
	cont = 0;
	int esp = 0;
	
	for(int i=0;i<strlen(cadena)-1;i++){
		esp = cadena[i+1] - cadena[i];
		if(esp == 1 || esp == 33 || esp == -31){ // se utiliza los numeros ASCII para ver si son mayusculas o minusculas consecutivas
			cont += 1;
		}
	}
}

void convertirFecha(int vFecha, int &dia, int &mes, int &anio){
	anio = vFecha % 10000;
	mes = ((vFecha % 1000000) - anio) / 10000;
	dia = ((vFecha % 100000000) - mes) / 1000000;
}

void convertirHora(int desde, int hasta, int &totalTurnos){
	totalTurnos = ((hasta - desde) / 20) * 0.6;
	
	int minutoin = desde % 100;
	int horain = ((desde % 10000) - minutoin) / 100;
	int minutoout = hasta % 100;
	int horaout = ((hasta % 10000) - minutoout) / 100;
	
	if((minutoin >= 0 && minutoin < 10) && (horain >= 0 && horain < 10)){
		printf("Horario: 0%i:0%i\n", horain, minutoin);
	}
	else if((minutoin >= 0 && minutoin < 10) && (horain > 10)){
		printf("Horario: %i:0%i\n", horain, minutoin);
	}
	else if((horain >= 0 && horain < 10) && (minutoin > 10)){
		printf("Horario: 0%i:%i\n", horain, minutoin);
	}
	else{
		printf("Horario: %i:%i", horain, minutoin);
	}	
	if((minutoout >= 0 && minutoout < 10) && (horaout >= 0 && horaout < 10)){
		printf("Horario: 0%i:0%i\n", horaout, minutoout);
	}
	else if((minutoout >= 0 && minutoout < 10) && (horaout > 10)){
		printf("Horario: %i:0%i\n", horaout, minutoout);
	}
	else if((horaout >= 0 && horaout < 10) && (minutoout > 10)){
		printf("Horario: 0%i:%i\n", horaout, minutoout);
	}
	else{
		printf("Horario: %i:%i", horaout, minutoout);
	}
	
	printf("Cantidad de turnos aproximados del dia: %i\n\n", totalTurnos);
}
