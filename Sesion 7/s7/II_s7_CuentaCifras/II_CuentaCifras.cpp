////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
�Cu�ntas veces aparece el d�gito 9 en todos los n�meros que hay entre el 1 y el 100? 
Por ejemplo, el 9 aparece una vez en los n�meros 19 y
92 mientras que aparece dos veces en el 99. Pretendemos dise�ar un algoritmo que
responda a esta sencilla pregunta, pero de forma suficientemente generalizada. 
Para ello, se pide construir un programa que lea tres enteros cifra (entre 1 y 9), min y
max y calcule el n�mero de apariciones del d�gito cifra en los n�meros contenidos
en el intervalo cerrado [min, max].
*/

#include <iostream>
#include <cmath>
using namespace std;


int main(){
	int a_buscar, min, max, recorre_div_10, numero_apariciones;
	
	cout << "Cuenta Cifras\n\n";
	cout << "Introduce la cifra a buscar ";
	cin >> a_buscar;
	cout << "\nIntroduce el valor m�nimo del rango ";
	cin >> min;
	cout << "\nIntroduce el valor m�ximo del rango ";
	cin >> max;
	
	numero_apariciones = 0;	
	
	/*
	Algoritmo (Cuenta cifras):
		
		Recorrer todos los enteros -recorre- entre min y max
			Contar el n�mero de veces que la cifra
				est� en recorre			
	*/
	
	for (int recorre = min; recorre <= max; recorre++){
		recorre_div_10 = recorre;

		while (recorre_div_10 > 0){
			if (recorre_div_10 % 10 == a_buscar)
				numero_apariciones++;

			recorre_div_10 = recorre_div_10 / 10;
		}
	}
	
	cout << "\n\nLa cifra " << a_buscar << " se encuentra " << numero_apariciones << " veces " 
		  << "en los n�meros que hay entre " << min << " y " << max;
			
	
	cout << "\n\n";
   system ("pause");
}
