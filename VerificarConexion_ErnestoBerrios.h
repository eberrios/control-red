#include <iostream>
#include <cstring>

using namespace std;
//Funcion que ejecuta, con el parametro ingresado por el usuario el comando ping SOLO 3 veces
string ping(char dominio[100]){
    	char var[2000] ="";
	strcat(var, "ping -c 3 ");
	strcat(var, dominio);
	cout << "\n" << var << "\n";
    	system(var);
    	return var;
}
