
#include <iostream>
#include <cmath>

using namespace std;

int main(){
   // Declaracion de las variables necesarias
   double lado1;
   double lado2;
   double hip;
   
   // Se leen los datos de entrada
   cout << "Introduzca la longitud del primer lado: ";
   cin >> lado1;
   cout << "Introduzca la longitud del segundo lado: ";
   cin >> lado2;
   
   // Se realiza el calculo
   hip=sqrt(lado1*lado1 - lado2*lado2);
   
   // Se muestra el resultado
   cout << "El valor de la hipotenusa es : " << hip << endl;
}
 
