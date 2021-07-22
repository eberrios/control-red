#include <iostream>
#include <time.h>
#include <fstream>
#include <stdio.h>

using namespace std;

//fecha y hora del log
string ahora(){
    time_t ahora = time(0);
    struct tm * timeinfo;
    char hora[160];
    time(&ahora);
    timeinfo = localtime(&ahora);
    strftime (hora,160,"%d/%m/%Y %H:%M:%S",timeinfo);
    return hora;
}

//guardar en archivo log con formato establecido
void log(string descripcion, string comando){
    ofstream salida;
    string formatoLog, accionF;
    salida.open("LOG_ErnestoBerrios.log",ios::out | ios::app);
    accionF = ahora();
    formatoLog = (accionF+","+descripcion+","+comando+";");
    salida<<formatoLog<<endl;
    salida.close();
}
