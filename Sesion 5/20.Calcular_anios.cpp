/*Sobre el mismo ejercicio del capital y los intereses, construid un programa para cal-cular cuántos años han de pasar hasta llegar a doblar, como mínimo,
 el capital inicial. Los datos que han de leerse desde teclado son el capital inicial y el interés anual.*/

#include <iostream>

using namespace std;

int main(){

	double capital, interes,doble;											//Declaramos las variables
	int anios=0;
	
	cout << "Introduce el capital: ";										//Pedimos los datos de entrada
	cin >> capital;
	cout << "Introduce el interes: ";
	cin >> interes;
	
	doble = capital*2;															//Con esta variable seleccionamos el limite al que tenemos que llegar
	
	while(capital <= doble){													//Realizamos el condicional
	
		capital += capital * (interes/100);									//Hacemos los calculos
		anios++;
	}
	
	cout << "Para doblar el capital inicial has necesitado " << anios << " a�os.\n\n";			//Mostramos el resultado
	
	system("pause");
}
