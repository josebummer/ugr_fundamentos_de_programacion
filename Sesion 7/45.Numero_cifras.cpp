/*(Examen Septiembre 2014) ¿Cuántas veces aparece el dígito 9 en todos los números
que hay entre el 1 y el 100? Por ejemplo, el 9 aparece una vez en los números 19 y
92 mientras que aparece dos veces en el 99. Pretendemos diseñar un algoritmo que
responda a esta sencilla pregunta, pero de forma suficientemente generalizada. Para
ello, se pide construir un programa que lea una cifra (entre 1 y 9), dos enteros min
y max y calcule el número de apariciones del dígito cifra en los números contenidos
en el intervalo cerrado [min, max].*/

#include <iostream>

using namespace std;

int NumeroApariciones(int minimo,int maximo,int cifra){				//Creamos una funcion para comprobar el numero de apariciones de una cifra

	const int DIVISOR=10;														//Creamos una costante divisor que le damos el valor 10
	int resto,aux=minimo,suma=0;
	
	while(minimo<=maximo){														//Con este bucle vamos a recorrer el intervalo introducido.
			
		do{																			//Creamos un blucle para que compruebe cifra por cifra si es la que el usuario a introducido,
			resto=aux%DIVISOR;													//lo hacemos con do por si el minimo es de 1 sola cifra entre tambien.
			if(resto==cifra)
				suma++;
			aux/=DIVISOR;
		}while(aux!=0);
		
	minimo++;
	aux=minimo;
	}
return suma;																		//Nos devuelve el resultado final
}

int main(){

	int max,min,cifra,total;																		//Creamos las variables
	
	cout << "Introduce un minimo para el intervalo: ";										//Pedimos los valor de las variables.
	cin >> min;
	cout << "Introduce un maximo para el intervalo: ";
	cin >> max;
	do{
	cout << "Introduce una cifra para contar el numero de veces que aparece: ";
	cin >> cifra;	
	}while((cifra<0) || (cifra>9));

	total=NumeroApariciones(min,max,cifra);												//Llamamos a la funcion metiendole los datos que ha introducido el usuario.
	
	cout << "\nEl numero de veces que aparece la cifra '" << cifra << "' es: " << total << "\n\n";			//Mostramos el resultado.

system("pause");
}
