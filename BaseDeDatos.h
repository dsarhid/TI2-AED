#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//--------------------------------ARCHIVOS-----------------------------------

FILE *	Veterinarios;
FILE *  Asistentes;
FILE *	Mascotas;
FILE *	Listados;



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
<<<<<<< HEAD
	int dni, matricula;
	struct fec fechaAtencion;
	char evol[380];
=======
>>>>>>> 303b609a427f7385e0174d1c3344f73e74871271
};




struct vet{
	int dni,cantRegistros;
	char apellidoYNombre[60], matricula[10], contrasenia[10], telefono[25] ,usuario[10];
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
	struct fec fechaNacimiento;
	struct fec fechaAtencion;
	struct tur;
	bool borrado;
};
struct list{
	char nomVeterinario[30], nomMascota[30];
};

vet veterinario;
asist asistente;
masc mascota;
list listado; 
sem diasAtencion;

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


void validaCarEsp(char cadena[], int &cont){ //Funcion para validar caracteres especiales 
	cont = 0;
	
	for(int i=0;i<strlen(cadena);i++){
		for(int j=0;j<strlen(ASCII);j++){ // se utiliza la cadena ASCII para verificar
			if(cadena[i] == ASCII[j]){
				cont += 1;
			}
		}
	}
}


void numConsecutivos(char cadena[], int &cont){ //Funcion que cuenta la cantidad de numeros consecutivos
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

void letConsecutivas(char cadena[], int &cont){  //Funcion letras consecutivas
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

void calcularSemana(){ //Funcion para registrar el horario de los dias que trabaja el vet
		
	char sem;
	float hor;
	int b = 0; //utilizacion de la bandera b para salir de los whiles
	
	while(b != 1){
		
		printf("\nDias de semana que atiende: \n\n");
		printf("\n\t%cLunes? (S)i - (N)o: ", 168); // codigo ASCII para que aparezca el "¿" por pantalla
		_flushall();
		scanf("%c", &sem);
		if(sem == 'S' || sem == 's'){  // Se utiliza ambas letras para ingresar
			veterinario.diasAtencion.lun = 1;
			printf("\n\tDesde hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.lunh.desde);
			printf("\tHasta hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.lunh.hasta);
			b = 1;
			system("cls");
		}
		else if(sem == 'N' || sem == 'n'){
			veterinario.diasAtencion.lun = 0;
			b = 1;
			system("cls");
		}
		else{   // este else funciona por si el usuario aprieta una palabra que no es S o N y vuelve a preguntar
			printf("\nIngrese S o N.. Presione una tecla para volver a ingresar.");
			getch();
			system("cls");
		}
	}
	b = 0;
	
	while(b != 1){
		printf("\nDias de semana que atiende: \n\n");
		printf("\n\t%cMartes? (S)i - (N)o: ", 168);
		_flushall();
		scanf("%c", &sem);
		if(sem == 'S' || sem == 's'){
			veterinario.diasAtencion.mar = 1;
			printf("\n\tDesde hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.marh.desde);
			printf("\tHasta hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.marh.hasta);
			b = 1;
			system("cls");
		}
		else if(sem == 'N' || sem == 'n'){
			veterinario.diasAtencion.mar = 0;
			b = 1;
			system("cls");
		}
		else{
			printf("\nIngrese S o N.. Presione una tecla para volver a ingresar.");
			getch();
			system("cls");
		}
	}
	b = 0;
	
	while(b != 1){
		printf("\nDias de semana que atiende: \n\n");
		printf("\n\t%cMiercoles? (S)i - (N)o: ", 168);
		_flushall();
		scanf("%c", &sem);
		if(sem == 'S' || sem == 's'){
			veterinario.diasAtencion.mie = 1;
			printf("\n\tDesde hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.mieh.desde);
			printf("\tHasta hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.mieh.hasta);
			b = 1;
			system("cls");
		}
		else if(sem == 'N' || sem == 'n'){
			veterinario.diasAtencion.mie = 0;
			b = 1;
			system("cls");
		}
		else{
			printf("\nIngrese S o N.. Presione una tecla para volver a ingresar.");
			getch();
			system("cls");
		}
	}
	b = 0;
	
	while(b != 1){
		printf("\nDias de semana que atiende: \n\n");
		printf("\n\t%cJueves? (S)i - (N)o: ", 168);
		_flushall();
		scanf("%c", &sem);
		if(sem == 'S' || sem == 's'){
			veterinario.diasAtencion.jue = 1;
			printf("\n\tDesde hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.jueh.desde);
			printf("\tHasta hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.jueh.hasta);
			b = 1;
			system("cls");
		}
		else if(sem == 'N' || sem == 'n'){
			veterinario.diasAtencion.jue = 0;
			b = 1;
			system("cls");
		}
		else{
			printf("\nIngrese S o N.. Presione una tecla para volver a ingresar.");
			getch();
			system("cls");
		}
	}
	b = 0;
	
	while(b != 1){
		printf("\nDias de semana que atiende: \n\n");
		printf("\n\t%cViernes? (S)i - (N)o: ", 168);
		_flushall();
		scanf("%c", &sem);
		if(sem == 'S' || sem == 's'){
			veterinario.diasAtencion.vie = 1;
			printf("\n\tDesde hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.vieh.desde);
			printf("\tHasta hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.vieh.hasta);
			b = 1;
			system("cls");
		}
		else if(sem == 'N' || sem == 'n'){
			veterinario.diasAtencion.vie = 0;
			b = 1;
			system("cls");
		}
		else{
			printf("\nIngrese S o N.. Presione una tecla para volver a ingresar.");
			getch();
			system("cls");
		}
	}
	b = 0;
	
	while(b != 1){
		printf("\nDias de semana que atiende: \n\n");
		printf("\n\t%cSabado? (S)i - (N)o: ", 168);
		_flushall();
		scanf("%c", &sem);
		if(sem == 'S' || sem == 's'){
			veterinario.diasAtencion.sab = 1;
			printf("\n\tDesde hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.sabh.desde);
			printf("\tHasta hs (hhmm): ");
			_flushall();
			scanf("%d", &veterinario.diasAtencion.sabh.hasta);
			b = 1;
			system("cls");
		}
		else if(sem == 'N' || sem == 'n'){
			veterinario.diasAtencion.sab = 0;
			b = 1;
			system("cls");
		}
		else{
			printf("\nIngrese S o N.. Presione una tecla para volver a ingresar.");
			getch();
			system("cls");
		}
	}
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

