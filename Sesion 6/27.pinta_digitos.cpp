/*En el ejercicio 14 de la Relación de Problemas I se pedía escribir un programa que leyese
un valor entero de tres dígitos e imprimiese los dígitos separados por un espacio
en blanco. Haced lo mismo pero para un número entero arbitrario. Por ejemplo, si el
número es 3519, la salida sería:*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int numero,numero_edit;	// Dato de entrada
   int digitos,valor;
   int divisor;
   
   // Entrada

   cout << "Introduce un entero: ";
   cin >> numero;
   
   numero_edit=numero;								//Esto lo hacemos para no perder el valor de numero y poder utilizarlo mas adelante
  	for(digitos=1;numero_edit>9;digitos++)
   	numero_edit=numero_edit/10;				//Con esto sacamos el numero de elementos que tiene el numero.
   	
   divisor=pow(10,digitos-1);						//Calculamos el divisor para saber cuantas veces tenemos que dividir nuestro numero.
 
   while(divisor>=1){								//Realizamos las operaciones para mostrar los numeros separados.
	
		valor=numero/divisor;
		cout << valor << "         ";
		
		numero=numero%divisor;
		divisor=divisor/10;
	
	}

cout << "\n\n";
system("pause");

}
