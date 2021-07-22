#include <iostream>
#include <cstring>

using namespace std;

//funcion que permite activar o desactivar una tarjeta de red, segun parametros ingresados por el usuario (tanto tarjeta como acyivacion y desactivacion)
string EstadoIface(char ip[100], int estado){
    	char var[2000] ="";
	strcat(var, "sudo ifconfig ");
	strcat(var, ip);
	if (estado == 1)
		strcat(var, " down");
	if (estado == 2)    	
		strcat(var, " up");
	cout << "\n" << var << "\n";
    	system(var);
    	return var;
}
