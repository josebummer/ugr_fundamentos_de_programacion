///////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

/*
   Un n�mero entero de n d�gitos se dice que es narcisista si se puede obtener como la
   suma de las potencias n-�simas de cada uno de sus d�gitos. Por ejemplo 153 y 8208
   son n�meros narcisistas porque 153 = 1^3 + 5^3 + 3^3 y 8208 = 8^4 + 2^4 + 0^4 + 8^4.
   Construir un programa que, dado un n�mero entero positivo, nos indique si el n�mero
   es o no narcisista. Si se va a usar la funci�n pow, no pueden ser ambos argumentos
   enteros, por lo que forzaremos a que la base (por ejemplo) sea double, multiplicando
   por 1.0.
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
	Algoritmo:

		Calcular el n�mero de d�gitos de n

		Recorrer los d�gitos de n
			Sacar la �ltima cifra (n%10) y sumarla
			Quitar la �ltima cifra (n/10)

      Comprobar si la suma es igual al valor original de n
*/

int main(){
	bool es_narcisista;
	int n_copia, n, i;
	int num_digitos, ultima_cifra;
	double suma;

	cout << "\nIntroduzca un entero: ";
	cin >> n;

	n_copia = n;
	num_digitos = 1;

	while (n_copia > 9){
		n_copia = n_copia / 10;
		num_digitos++;
	}   

	n_copia = n;
	suma = 0;

	for (i = 1 ; i <= num_digitos; i++){
		ultima_cifra = n_copia % 10;
		suma = suma + pow(ultima_cifra, num_digitos);
		n_copia = n_copia / 10;
	}

	es_narcisista = (suma == n);

	if (es_narcisista)
		cout << "\nEs narcisista";
	else
		cout << "\nNo es narcisista";

	cout << "\n\n";
	system("pause");
}
