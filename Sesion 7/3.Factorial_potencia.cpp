/*Reescribid la soluci�n del ejercicio 33 (factorial y potencia) de la Relaci�n de Problemas
II, modulariz�ndola con funciones.
Para obligar a que el valor le�do de n sea positivo, implemente y llame a la funci�n
int LeeEnteroPositivo()*/

#include <iostream>

using namespace std;

int Factorial(int entero){												//Creamos la funcion que calcula el factorial de un numero
	
	int i,factorial;
	
	factorial=entero;											
	for(i=2;i<entero;i++)												
		factorial *= i;
		
return factorial;
}

double Potencia(double real, int entero){							//Creamos la funcion que calcula la potencia de un numero

	int i;
	double potencia=1;
	
	for(i=0;i<entero;i++)						
		potencia *= real;

return potencia;
}

int LeeEnteroPositivo(int n_positivo){								//Creamos una funcion que asegura que el numero introducido sea positivo

	int numero=0;
	
	if(n_positivo>=0)
		numero=n_positivo;
	else
		numero=-n_positivo;
		
return numero;
}

int main(){

	int nentero,factorial;													//Creamos las variables
	double xreal,potencia;
	

	cout << "Introduce un numero entero: ";							//Pedimos los valores de las variables
	cin >> nentero;
	cout << "Introduce un numero real: ";
	cin >> xreal;
	
	nentero=LeeEnteroPositivo(nentero);									//Llamamos a la funcion para asegurarnos que el entero es positivo
	
	potencia=Potencia(xreal,nentero);									//Llamamos a las demas funciones para que nos calcule el resultado.
	factorial=Factorial(nentero);	
	
	cout << "\nLa potencia de " << xreal << " elevado a " << nentero << " es: " << potencia << "\n";			//Mostramos el resultado
	cout << "El facorial de " << nentero << " es: " << factorial << "\n\n";
system("pause");
}
