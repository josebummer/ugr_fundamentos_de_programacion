/*Un número entero n se dice que es desgarrable (torn) si al dividirlo en dos partes
cualesquiera izda y dcha, el cuadrado de la suma de ambas partes es igual a n.
Por ejemplo, 88209 es desgarrable ya que (88 + 209)^2 = 88209; 81 también lo es
ya que 81 = (8 + 1)2. Cread un programa que lea un entero n e indique si es o no
desgarrable.*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int digitos,numero,aux,divisor;
	double parte1,parte2;
	bool desgarrable=false;
	
	do{
	cout << "Introduce un numero positivo: ";
	cin >> numero;
	}while(numero<0);
	
	aux=numero;																				
	for(digitos=1;aux>9;digitos++)							//Con esto sacamos el numero de digitos que tiene el numero introducido
   	aux /= 10;	
	
	if(digitos%2==0)
		divisor=pow(10,digitos/2);
	else
		divisor=pow(10,digitos/2+1);
	
	parte1=numero/divisor;
	parte2=numero%divisor;
	cout << divisor;
	cout << "\n";
	cout << parte2;

	desgarrable=pow(parte1+parte2,2) == numero;
	
	if(desgarrable)
		cout << "\nEl numero " << numero << " es un numero desgarrable.\n\n";
	else
		cout << "\nEl numero " << numero << " no es desgarrable.\n\n";
		
system("pause");
}
