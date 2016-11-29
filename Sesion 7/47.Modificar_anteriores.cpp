/*Modificad los dos ejercicios anteriores para que se lea desde teclado el valor inicial
y el número de filas a imprimir. En los ejemplos anteriores, el valor inicial era 1 y se
imprimían un total de 6 filas.*/

#include <iostream>

using namespace std;

int main(){

	int i,f,c,d,aux,r=0;											//Creamos las variables
	
	//EJERCICIO 45
	
	do{
	cout << "Introduce el numero de filas: ";				//Pedimos los datos de las variables
	cin >> f;
	}while(f<1);
	do{
		cout << "Introduce el dato inicial: ";
		cin >> d;
	}while(d<0);
	
	for(i=1;i<=f;i++){								//Creamos un blucle que va a controlar el numero de filas introducidas
		aux=d;
		for(c=1;c<=f-r;c++){							//Este segundo bucle va a controlar el numero de columnas dependiendo del dato inicial
			cout << aux << " ";
			aux++;
		}
		cout << "\n";
		d++;
		r++;
	}
cout << "\n";
system("pause");

	
	
	
	// EJERCICIO 46
	
	do{
	cout << "\nIntroduce el numero de filas: ";					//Pedimos los valores para las variables.
	cin >> f;
	}while(f<1);
	
	do{
		cout << "Introduce el dato inicial: ";
		cin >> d;
	}while(d<0);
	
	for(i=1;i<=f;i++){										//Creamos el bucle que va a controlar las filas dependiendo del valor que metamos
		aux=d;
		for(c=1;c<=f;c++){								//Este segundo bucle controla el numero de columnas
			cout << aux << " ";
			aux++;
		}
		cout << "\n";
		d++;
	}
cout << "\n";
system("pause");
}
