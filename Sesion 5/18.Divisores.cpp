/*Realizar un programa que lea desde teclado un entero tope e imprima en pantalla todos
sus divisores propios. Para obtener los divisores, basta recorrer todos los enteros
menores que el valor introducido y comprobar si lo dividen. A continuación, mejorar el
ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
bucle post test (do while).*/

#include <iostream>

using namespace std;

int main(){

	int entero,resta;															//Declaramos las variables
	
	do{
	
		cout << "\nIntroduce un numero entero positivo: ";			//Preguntamos por los datos de entrada
		cin >> entero;
	
	}while (entero<=0);														//Ponemos la condicion de salida del bucle
	
	resta=entero;
	cout << "Divisores de " << entero << ":\n";
	while (resta>0){															//Ejecutamos los procesos para mostrar el resultado.
		if (entero%resta==0)
			cout << resta << "\n";
		resta--;
	}

	system("pause");

}
