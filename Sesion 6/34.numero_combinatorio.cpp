/*Calcular mediante un programa en C++ el combinatorio
(  n	)
(  m	)
con n, m valores enteros. No pueden usarse las funciones de la biblioteca cmath.
El combinatorio de n sobre m (con n mayor o igual a m) es un número entero que se define como
sigue:*/

#include <iostream>

using namespace std;

int main(){

	cout << "	|	     Vamos a calcular ( n )			|\n";
	cout << "	|			      ( m )			|\n\n";

	int n,m,i,solucion,factorialn,factorialm,factorial_conjunto;
	
	do{
	cout << "Introduce el valor de n: ";
	cin >> n;
	}while(n<0);

	do{
		cout << "Introduce el valor de m (debe ser menor o igual que n): ";
		cin >> m;
	}while(m<0 || m>n);
	
	factorialn=n;								//Sacamos el factorial multimplicando el numero por los numeros que van antes de el hasta el 2.
	for(i=2;i<n;i++)
		factorialn *= i;
	
	factorialm=m;								//Sacamos el factorial multimplicando el numero por los numeros que van antes de el hasta el 2.
	for(i=2;i<m;i++)
		factorialm *= i;
		
	factorial_conjunto=n-m;								//Sacamos el factorial multimplicando el numero por los numeros que van antes de el hasta el 2.
	for(i=2;i<n-m;i++)
		factorial_conjunto *= i;
		
	solucion= factorialn/(factorialm*factorial_conjunto);
	
	cout << "\nLa solucion es: " << solucion << "\n\n";
	
system("pause");
}
