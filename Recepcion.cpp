#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "BaseDeDatos.h"

void menu(int &op){
	printf("\nModulo del Asistente ( Recepcion )\n");
	printf("\n==========================================\n\n");
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
<<<<<<< HEAD
	int op = 0, b = 1, bmenu = 1, log = 0, vFecha, dia, mes, anio, horain, minutoin, horaout, minutoout, totalTurnos;
	char usr[10], pass[10], apelYNom[30], nom[30], apel[30];
	bool coincidir = true;
=======
	int op = 0, b = 1, bmenu = 1, log = 0, vFecha, dia, mes, anio, horain, minutoin, horaout, minutoout, totalTurnos, banderaMatricula;
	char usr[10], pass[10], apelYNom[30], nom[30], apel[30], matriculaVetTurno[10];
	bool coincidir = false;
>>>>>>> 303b609a427f7385e0174d1c3344f73e74871271
	
	while(op != 5){
		menu(op);
		system("cls");
		switch (op){
			case 1:
				Asistentes=fopen("Asistentes.dat", "rb");
				
				if(Asistentes == NULL){
					printf("\nNingun Empleado registrado. Presione una tecla para continuar...");
					getch();
					system("cls");
					break;
				}
				else{
					while(b != 0){
						if(bmenu == 0 && log == 0){
							printf("\nModulo del Asistente ( Recepcion )\n");
							printf("\n==========================================\n\n");
							printf("1.- Iniciar Sesion.\n");
							printf("2.- Registrar Mascota.\n");
							printf("3.- Registrar Turno.\n");
							printf("4.- Listado de Atenciones por Veterinario y Fecha.\n");
							printf("5.- Cerrar la aplicacion.\n\n");
							printf("Ingrese opcion: 1\n");
						}
						printf("\nIngrese Usuario: ");
						_flushall();
						scanf("%s", &usr);
						
						while(fread(&asistente, sizeof(asist), 1, Asistentes) != NULL){		// Lee Empleados hasta final del archivo
							if(strcmp(usr, asistente.usuario) == 0){						// Compara usuario leido con el usuario ingresada, se iguala a 0 para ver si son iguales.
								printf("Ingrese contrasenia: ");
								scanf("%s", &pass);
								if(strcmp(pass, asistente.contrasenia) == 0){			// Compara contraseña leido con la contraseña ingresada, se iguala a 0 para ver si son iguales.
									printf("\n\n\tAsistente logueado con exito. Presione una tecla para continuar...");
									b = 0;												// Cambio valor de bandera a 0 para salir del while.
									log = 1;											// Bandera de logeo cambio a 1.
									bmenu = 0;											// Bandera menu vuelve a 0.
									strcpy(apelYNom, asistente.apellidoYNombre);			// Copio cadena de apellido y nombre de archivo y lo guardo en variable apelYNom.
									getch();
									break;
								}
								else{
									printf("\n\nContraseña incorrecta. Intente nuevamente...");
									rewind(Asistentes);									// Vuelve al principio del archivo.
									getch();
									system("cls");
									printf("\nModulo del Asistente ( Recepcion )\n");
									printf("\n==========================================\n\n");
									printf("1.- Iniciar Sesion.\n");
									printf("2.- Registrar Mascota.\n");
									printf("3.- Registrar Turno.\n");
									printf("4.- Listado de Atenciones por Veterinario y Fecha.\n");
									printf("5.- Cerrar la aplicacion.\n\n");
									printf("Ingrese opcion: 1\n");
									printf("\nIngrese Usuario: %s\n", usr);
								}
							}
							else{
								coincidir = false;										// Usuario no encontrado.
							}
						}
						if(coincidir == false){
							printf("Usuario no registrado. Intente nuevamente...");
							rewind(Asistentes);											// Vuelve al principio del archivo.
							bmenu = 0;													// Bandera menu vuelve a 0.
							getch();
						}
					system("cls");
					}
				fclose(Asistentes);														// Cierro archivo
				}
			break;
			case 2:
				b = 1;
				
				if(log == 0){
					printf("\nAsistente no logueado. No se puede realizar ninguna operacion sin loguearse.");
					getch();
					system("cls");
					break;
				}
				else{
					Asistentes = fopen("Asistentes.dat", "rb");
					
					
					if(Asistentes == NULL){
						printf("\nNingun asistente registrado. Primero registre un asistente en Administracion.");
						getch();
						system("cls");
						break;
					}
					else{
						
						Veterinarios= fopen("Veterinarios.dat","");
					    fread(&veterinario, sizeof(vet), 1, Veterinarios);
						
						printf("Ingrese la Matricula del veterinario en turno: ");
						scanf("%s",&matriculaVetTurno);
						   
							while( !feof(Veterinarios)){
			                        fread(&veterinario, sizeof(vet), 1, Veterinarios);
					                     if(veterinario.matricula==matriculaVetTurno){
							 	             banderaMatricula=0;
							            }
							        fread(&veterinario, sizeof(vet), 1, Veterinarios);
							}
					    
						    fclose (Veterinarios);
					         
					         while (banderaMatricula==1){
					         	
								 printf("\n Ingresar una matricula valida, no cumple con las matriculas registradas. ");

					             printf("Ingrese la Matricula del veterinario en turno: ");
						         scanf("%s",&matriculaVetTurno);
						         Veterinarios= fopen("Veterinarios.dat","");
					             fread(&veterinario, sizeof(vet), 1, Veterinarios);
                
                                 while( !feof(Veterinarios)){
			                             fread(&veterinario, sizeof(vet), 1, Veterinarios);
					                        if(veterinario.matricula==matriculaVetTurno){
							 	                 banderaMatricula=0;
							                }
							             fread(&veterinario, sizeof(vet), 1, Veterinarios);
							     }
					    
						         fclose (Veterinarios);
					         
                             }
						
						Mascotas = fopen("Mascotas.dat", "a+b");					
					    
		                   printf("Complete los siguientes datos de la mascota:\n\n");
						   printf("Nombre: ");
						   _flushall();
						   scanf("%s", &nom);
						   printf("Apellido: ");
						   _flushall();
						   scanf("%s", &apel);
						   strcat(nom, " ");
						   strcat(nom, apel);
						   strcpy(mascota.apellidoYNombre, nom);
						   printf("Domicilio: ");
						   _flushall();
						   scanf("%s", &mascota.domicilio);
						   printf("DNI del duenio: ");
						   _flushall();
						   scanf("%i", &mascota.dni);
						   printf("Localidad: ");
						   _flushall();
						   scanf("%s", &mascota.localidad);
						   system("cls");
						   printf("Peso: ");
						   _flushall();
						   scanf("%i", &mascota.peso);
						   printf("Fecha de nacimiento con formato (dd mm aaaa): ");
						   _flushall();
						   scanf("%i", &vFecha);
						   convertirFecha(vFecha, dia, mes, anio);
						   mascota.fechaNacimiento.dia = dia;
						   mascota.fechaNacimiento.mes = mes;
						   mascota.fechaNacimiento.anio = anio;
						   fwrite(&mascota, sizeof(masc), 1, Mascotas);
						   printf("\n\n\tMascota registrada con exito!. Presione una tecla para continuar...");
						   getch();
						   system("cls");
						   						
						fclose(Mascotas);
						//////////////////////////////////////////////////////////////////////////////////////////////////
						//////////////////////////////////////////////////////////////////////////////////////////////////
						while(fread(&veterinario, sizeof(vet), 1, Veterinarios) != NULL){
							if(strcmp(apelYNom, veterinario.apellidoYNombre) == 0){
								if(veterinario.cantRegistros == NULL || veterinario.cantRegistros == 0){
									veterinario.cantRegistros = 1;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
								else{
									asistente.cantRegistros += 1;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
							}
						}
					}
				}
				fclose(Veterinarios);
				fclose(Asistentes);
		
			break;
			case 3:
				Veterinarios = fopen("Veterinarios.dat", "r+b");
				Asistentes = fopen("Asistentes.dat", "rb");
				
				if(Asistentes == NULL){
					printf("\nNingun asistente registrado. Primero registre un asistente en Administracion.");
					getch();
					system("cls");
					break;
				}
				else{
					if(log == 0){
						printf("\nAsistente no logueado. No se puede realizar ninguna operacion sin loguearse.");
						getch();
						system("cls");
						break;
					}
					else{
						if(Veterinarios == NULL){
							printf("\nNingun veterinario registrado. Primero registre un veterinarios en Administracion.");
							getch();
							system("cls");
							break;
						}
						else{
							system("cls");
							printf("\nListado de veterinarios y sus respectivos dias y horarios: \n\n");
							while(fread(&veterinario, sizeof(vet), 1, Veterinarios) != NULL){
								printf("Nombre Completo: %s\n", veterinario.apellidoYNombre);
								
								if(veterinario.diasAtencion.lun == 1){
									printf("\n\tLunes: \n\t\t");
									convertirHora(veterinario.diasAtencion.lunh.desde, veterinario.diasAtencion.lunh.hasta, totalTurnos);
									veterinario.turnos.turnLun = totalTurnos;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
								if(veterinario.diasAtencion.mar == 1){
									printf("\n\tMartes: \n\t\t");
									convertirHora(veterinario.diasAtencion.marh.desde, veterinario.diasAtencion.marh.hasta, totalTurnos);
									veterinario.turnos.turnMar = totalTurnos;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
								if(veterinario.diasAtencion.mie == 1){
									printf("\n\tMiercoles: \n\t\t");
									convertirHora(veterinario.diasAtencion.mieh.desde, veterinario.diasAtencion.mieh.hasta, totalTurnos);
									veterinario.turnos.turnMie = totalTurnos;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
								if(veterinario.diasAtencion.jue == 1){
									printf("\n\tJueves: \n\t\t");
									convertirHora(veterinario.diasAtencion.jueh.desde, veterinario.diasAtencion.jueh.hasta, totalTurnos);
									veterinario.turnos.turnJue = totalTurnos;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
								if(veterinario.diasAtencion.vie == 1){
									printf("\n\tViernes: \n\t\t");
									convertirHora(veterinario.diasAtencion.vieh.desde, veterinario.diasAtencion.vieh.hasta, totalTurnos);
									veterinario.turnos.turnVie = totalTurnos;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
								}
								if(veterinario.diasAtencion.sab == 1){
									printf("\n\tSabado: \n\t\t");
									convertirHora(veterinario.diasAtencion.sabh.desde, veterinario.diasAtencion.sabh.hasta, totalTurnos);
									veterinario.turnos.turnSab = totalTurnos;
									fwrite(&veterinario, sizeof(vet), 1, Veterinarios);
							
								}
							
							}
							printf("Presione una tecla para continuar...");
							getch();
							system("cls");
						}
					}
				}
				fclose(Veterinarios);
				fclose(Asistentes);
				break;
			case 4:
				Veterinarios = fopen("Veterinarios.dat", "rb");
				Mascotas = fopen("Mascotas.dat", "rb");
				Asistentes = fopen("Asistentes.dat", "rb");
				Listados = fopen("Listados.dat", "rb");
				
				coincidir = false;
				
				if(Asistentes == NULL){
					printf("\nNingun asistente registrado. Primero registre un asistente en Administracion.");
					getch();
					system("cls");
					break;
				}
				else{
					if(Veterinarios == NULL){
						printf("\nNingun veterinario registrado. Primero registre un veterinario en Administracion.");
						getch();
						system("cls");
						break;
					}
					else{
						if(Mascotas == NULL){
							printf("\nNingun mascota registrada. Primero registre una mascota.");
							getch();
							system("cls");
							break;
						}
						else{
							if(Listados == NULL){
								printf("\nNingun listado registrado. Presione una tecla para continuar...");
								getch();
								system("cls");
								break;
							}
							else{
								printf("Ingrese fecha de listado (ddmmaaaa): ");
								scanf("%i", &vFecha);
								convertirFecha(vFecha, dia, mes, anio);
								printf("Fecha: %i/%i/%i.\n\n", dia, mes, anio);
								while(fread(&mascota, sizeof(masc), 1, Mascotas) != NULL){
									if(dia == mascota.fechaAtencion.dia){
										if(mes == mascota.fechaAtencion.mes){
											if(anio == mascota.fechaAtencion.anio){
												printf("Veterinario: %s", veterinario.apellidoYNombre);
												while(fread(&listado, sizeof(list), 1, Listados) != NULL){
													if(strcmp(veterinario.apellidoYNombre, listado.nomVeterinario) == 0){
														printf("Mascota: %s\n", listado.nomMascota);
													}
												}
												rewind(Listados);
												coincidir = true;
											}
										}
									}
								}
								if(coincidir == false){
									printf("No hay registros para esta fecha.");
								}
							}
						}
					}
			 	}
				fclose(Veterinarios);
				fclose(Mascotas);
				fclose(Listados);
				fclose(Asistentes);
			break;
		}
	}
	system("cls");
	printf("\n\n\n\t\tFin de la aplicacion. Presione una tecla para continuar...\n\n\n");
	getch();
}
