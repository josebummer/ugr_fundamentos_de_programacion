/*Supongamos una serie num�rica cuyo t�rmino general es:
ai = a1*r^(i-1)
Si analizamos la expresi�n algebraica de la serie num�rica, nos damos cuenta
que es una progresi�n geom�trica ya que cada t�rmino de la serie queda definido
por la siguiente expresi�n: a(i+1) = ai*r
Se pide crear un programa que lea desde teclado r, el primer elemento a1 y el tope k
y calcule la suma de los primeros k valores de la serie.		*/

#include <iostream>

using namespace std;

int main(){

	cout << "Vamos a calcular a suma de varios elementos 'a' multiplicados por un elemento 'r' hasta llegar al tope marcado por el elemento 'k'.\n\n";
	
	int suma=0,valor,tope,i,r;
	
	do{
	cout << "Introduce el valor r: ";
	cin >> r;
	}while(r<=0);
	do{
	cout << "Introduce el valor de a: ";
	cin >> valor;
	}while(valor<0);
	do{
	cout << "Introduce el valor del elemento k: ";
	cin >> tope;
	}while(tope<0);
	
	for(i=0;i<tope;i++){
		suma+=valor;
		valor*= r;
		
	}
	
	cout << "\nLa suma total es: " << suma << "\n\n";	
system("pause");
}
