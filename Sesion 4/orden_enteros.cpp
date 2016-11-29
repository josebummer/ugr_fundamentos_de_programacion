/*Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están.*/

#include <iostream>

using namespace std;

int main () {

	int entero1,entero2,entero3;								//Declaramos las varialbles
	
	cout << "Introduce el primer entero: ";					// Obtenemos el valor de las variables
	cin >> entero1;
	cout << "Introduce el segundo entero: ";
	cin >> entero2;
	cout << "Introduce el tercer entero: ";
	cin >>  entero3;
	
	if ((entero1 > entero2 && entero2 > entero3) || (entero1 < entero2 && entero2 < entero3))
		cout << "\nLos tres enteros estan ordenados.\n\n";
	else
		cout << "\nLos valores no estan ordenado.\n\n";

	system("pause");

}
