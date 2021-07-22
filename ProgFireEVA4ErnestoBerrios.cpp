#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>

#include "controlLog.h"
#include "EstadoIface_NelsonAlonso.h"
#include "VerificarConexion_ErnestoBerrios.h"



using namespace std;

//menu de navegacion
void menu(){
	
	cout<< "\n1 Cambio de estado de tarjetas de red\n";
	cout<< "2 Probar conexion\n";
	cout<< "3 SALIR\n";
	cout<< "Ingrese una de las opciones:\n\n";
}
//funcion de mensajeria con limpieza de pantalla
void mensaje(string str){
	system("clear");
	cout<< str;
}

int main(){
	int opcion=0;
	int estado, sw=1;
	char valor[100];

	string var;
	do{
		menu();
		cin >> opcion;
		//apagar o encender tarjeta de red segun parametros del usuario
		if (opcion==1){
			mensaje("Esta funcion permite apagar, encender una de las conexiones de red que se ven a continuacion\n\n");
			system("ip addr show");
			cout << "\n Ingrese una de las Iface para bloquear:";
			cin >> valor;
			cout << "\n Ingrese\n1.- Si se apaga\n2.- Si se enciende:\n";
			cin >> estado;
			var = EstadoIface(valor, estado);
			//guaradar log
			log("Apaga o enciende red", var);
		//verificar conexion ejecutando un ping a un dominio dado 
		} else if (opcion==2){
			mensaje("Esta funcion permite verificar la conexion \n\n");
			cout << "\n Ingrese el dominio y/o IP a consultar:\n";
			cin >> valor;
			var = ping(valor);
			//guardar log
			log("Verifica conexion", var);
		//Salir del programa
		} else if(opcion == 3){
			mensaje("Adios!!\n");
			sw=2;
			log("Cierre se sesion", var);
		}
	} while (sw==1);
	return 0;
}
