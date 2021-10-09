#include <iostream>
#include <string>
using namespace std;

class Info{ //una clase para formar objetos con los datos de cada línea de la bitácora
protected:
    string strmes; //mes como string
    int mes;
    int dia;
    int hora;
    int minutos;
    int segundos;
    string ip; //dirección ip e información de error

public:

//Setter del mes
void setMes(string _mes){ //recibe el número
  if (_mes == "Jan")
    mes = 1;
  if (_mes == "Feb")
    mes = 2;
  if (_mes == "Mar")
    mes = 3;
  if (_mes == "Apr")
    mes = 4;
  if (_mes == "May")
    mes = 5;
  if (_mes == "Jun")
    mes = 6;
  if (_mes == "Jul")
    mes = 7;
  if (_mes == "Aug")
    mes = 8;
  if (_mes == "Sep")
    mes = 9;
  if (_mes == "Oct")
    mes = 10;
  if (_mes == "Nov")
    mes = 11;
  if (_mes == "Dic")
    mes = 12;
  strmes = _mes;
}

/*En la entrada de datos todo se toma como string, estas funciones son para pasar de nuevo a numeros
y desplegar la info*/
string backToNums(int cad){
  if (cad < 10)
    return "0" + to_string(cad); //para que se muestre como 01,02,...
  else
    return to_string(cad);
}//finbacktonums
string mostrarDatos(){
return  strmes + " " + backToNums(dia) + " " + backToNums(hora) + ":" + backToNums(minutos) + ":" + backToNums(segundos) + " " + ip + "\n";
}

//Setters
void setdia(int _dia){
  dia = _dia;
}

void sethora(int _hora){
  hora = _hora;
}

void setminuto(int _minutos){
  minutos = _minutos;
}

void setsegundo(int _segs){
  segundos = _segs;
}

void setip(string _ip){
  ip = _ip;
}

//Getters
string getstrmes(){
  return strmes;
}
int getMes(){
  return mes;
}

int getDia(){
  return dia;
}

int getHora(){
  return hora;
}

int getMins(){
  return minutos;
}

int getSegs(){
   return segundos;
}

string getIp(){
  return ip;
}

};
