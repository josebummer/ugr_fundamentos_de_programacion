/*Modificad las soluciones de los ejercicios 3 y 5 para que no se mezclen E/S y C
(entradas/salidas y cómputos) dentro de la misma estructura condicional.*/

#include <iostream>

using namespace std;

int main(){

	//EJERCICIO 3

	int edad;											// Declaramos las variables.
	double salario;
	bool salario_aumentado=false;
	
	cout << "Introduce la edad: ";					// Pedimos los datos de entrada
	cin >> edad;
	cout << "Introduce el salario: ";
	cin >> salario;
	
	if ((salario < 300) && (edad > 65)) {
		salario = salario*1.05;
		salario_aumentado=true;
	}
	
	if (salario_aumentado)
		cout << "\nEl salario final es " << salario << "\n\n";
	else
		cout << "\nNo es aplicable la subida.\n\n";

	system("pause");
	
	//EJERCICIO 5
	
	int entero1,entero2,entero3;										//Declaramos las varialbles
	bool ordenados=false;	
	
	cout << "\n\nIntroduce el primer entero: ";					// Obtenemos el valor de las variables
	cin >> entero1;
	cout << "Introduce el segundo entero: ";
	cin >> entero2;
	cout << "Introduce el tercer entero: ";
	cin >>  entero3;
	
	if ((entero1 > entero2 && entero2 > entero3) || (entero1 < entero2 && entero2 < entero3))
		ordenados=true;
		
	if (ordenados)
		cout << "\nLos tres enteros estan ordenados.\n\n";
	else
		cout << "\nLos valores no estan ordenado.\n\n";

	system("pause");

}
