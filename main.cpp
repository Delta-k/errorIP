#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <string>

#include "Info.h"
using namespace std;

//Busqueda por dia y mes iniciales y finales
void busqueda(vector<Info> vec, int mi, int di, int mf, int df){ //Complejidad O(n)
  int n = vec.size(); //longitud del vector
  for(int i = 0; i < n-1; i++) {
    if(vec[i].getMes() >= mi && vec[i].getMes() <= mf){
      if(vec[i].getDia() >= di && vec[i].getDia() <= df){
        cout << vec[i].mostrarDatos();
      }
    }
  }
}//final busqueda

//Insertion sort - Comlejidad O(n^2)
void ordenarDatos(vector<Info> vec){
  int mi,di,mf,df;
  cin >> mi; //mes inicial
  cin >> di; //dia inicial
  cin >> mf; //mes final
  cin >> df; //mes final

  int n = vec.size(); //longitud del vector
  int i, j;
  Info aux; //para hacer los cambios

  for(i = 1; i < n; i++){ //segundos
    aux = vec[i];
    j = i-1; //elemento Anterior
    while(j >= 0 && vec[j].getSegs() > aux.getSegs()){
      vec[j+1] = vec[j];
      j = j-1;
    }
    vec[j+1] = aux;
  }
  for(i = 1; i < n; i++){ //minutos
    aux = vec[i];
    j = i-1; //elemento Anterior
    while(j >= 0 && vec[j].getMins() > aux.getMins()){
      vec[j+1] = vec[j];
      j = j-1;
    }
    vec[j+1] = aux;
  }

  for(i = 1; i < n; i++){ //horas
    aux = vec[i];
    j = i-1; //elemento Anterior
    while(j >= 0 && vec[j].getHora() > aux.getHora()){
      vec[j+1] = vec[j];
      j = j-1;
    }
    vec[j+1] = aux;
  }

  for(i = 1; i < n; i++){ //meses
    aux = vec[i];
    j = i-1; //elemento Anterior
    while(j >= 0 &&  vec[j].getDia() > aux.getDia() ){
      vec[j+1] = vec[j];
      j = j-1;
    }
    vec[j+1] = aux;
  }

  for(i = 1; i < n; i++){ //días
    aux = vec[i];
    j = i-1; //elemento Anterior
    while(j >= 0 && vec[j].getMes() > aux.getMes()){
      vec[j+1] = vec[j];
      j = j-1;
    }
    vec[j+1] = aux;
  }
  //Búsqueda related
  busqueda(vec, mi, di, mf, df);

  //Salida sorted.txt
  ofstream archivo;
  archivo.open("sorted.txt");
  for(int i = 0; i < n-1; i++) {
    archivo << vec[i].mostrarDatos();
  }
  archivo.close ();
}//fin ordenarDatos



int main(){

  vector<Info> vec;
  Info aux;
  string  _mes, _dia, _hora, _minutos, _segs, _ip;
  //Todo entra como string, uso de función c_str() para ingresar a los valores y convertirlos a números con arof
  ifstream archivo("bitacora.txt");
  while(getline(archivo, _mes, ' ')){
      aux.setMes(_mes);
      getline(archivo, _dia, ' ');
      aux.setdia(atof( _dia.c_str() ));
      getline(archivo, _hora, ':');
      aux.sethora(atof( _hora.c_str() ));
      getline(archivo,_minutos,':');
      aux.setminuto(atof( _minutos.c_str() ));
      getline(archivo, _segs, ' ');
      aux.setsegundo(atof( _segs.c_str() ));
      getline(archivo, _ip);
      aux.setip(_ip);
      vec.push_back(aux);
  }
  ordenarDatos(vec);

  return 0;
}
