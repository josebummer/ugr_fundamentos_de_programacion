/*
Construya la función con cabecera:
string Digitos (int n)
para que extraiga en un string los dígitos del número n tal y como se indica en el
ejercicio 27 de la relación de problemas II.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string Digitos(int n){

	string cadena="";
	int digitos,numero_edit,divisor,valor;
	
	numero_edit=n;										//Esto lo hacemos para no perder el valor de numero y poder utilizarlo mas adelante
  	for(digitos=1;numero_edit>9;digitos++)
   	numero_edit=numero_edit/10;				//Con esto sacamos el numero de elementos que tiene el numero.
   	
   divisor=pow(10,digitos-1);						//Calculamos el divisor para saber cuantas veces tenemos que dividir nuestro numero.
 
   while(divisor>=1){								//Realizamos las operaciones para mostrar los numeros separados.
	
		valor=n/divisor;
		cadena = cadena + " " + to_string(valor) + " ";
		
		n=n%divisor;
		divisor=divisor/10;
	}
	
return cadena;
}

int main(){

	int numero;														//Creamos las variables de entrada
	string cadena;
	
	do{
	cout << "Introduce un numero: ";							//Introducimos los valores
	cin >> numero;
	}while(numero<0);
	
	cadena=Digitos(numero);										//Obtenemos el resultado llamando a la funcion
	
	cout << "\n\n " << cadena << "\n\n";					//Mostramos el resultado

system("pause");
}
