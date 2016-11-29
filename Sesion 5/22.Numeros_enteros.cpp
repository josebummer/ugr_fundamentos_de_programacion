/*Realizar un programa que lea enteros desde teclado y calcule cuántos se han intro-ducido y cual es el mínimo de dichos valores
 (pueden ser positivos o negativos). Se dejará de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de los 
 enteros dentro de un bucle sobre una única variable llamada dato. Es importante controlar los casos extremos, como por ejemplo,
 que el primer valor leído fuese ya el terminador de entrada (en este caso, el cero).*/
 
 #include <iostream>
 
 using namespace std;
 
 int main() {
 
 	int dato, nenteros=0, maximo=0;																//Declaramos las variables
 	const int FIN=0;
 	
 	cout << "Introduce numeros enteros (pulse 0 para salir): ";					//Pedimos los datos de entrada
	cin >> dato;
 	
 	while(dato!=FIN){
	
	 	if (dato > maximo)
	 			maximo = dato;
	 	
	 	nenteros++;
	 	
	 	cout << "Introduce numeros enteros (pulse 0 para salir): ";					//Pedimos los datos de entrada de nuevo
		cin >> dato;
	 }																		
 
 	cout << "\nLa cantidad de enteros introducidos son: " << nenteros << ".\n";		//Mostramos el resultado por pantalla
 	if (nenteros != 0)
	 cout << "El entero mayor es: " << maximo << ".\n\n";
 	
 	system("pause");
 
 
 }
