/*Un número entero de n dígitos se dice que es narcisista si se puede obtener como
la suma de las potencias n-ésimas de cada uno de sus dígitos. Por ejemplo 153 y
8208 son números narcisistas porque 153 = 13 + 53 + 33 (153 tiene 3 dígitos) y
8208 = 84 +24 +04 +84 (8208 tiene 4 dígitos). Construir un programa que, dado un
número entero positivo, nos indique si el número es o no narcisista.*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int digitos,numero_real,numero,numero_edit,suma=0,valor;		//Introducimos las variables
	bool narcisista = false;
	
	do{
	cout << "Introduce un numero: ";										//Pedimos los datos de entrada
	cin >> numero_real;
	}while(numero_real<0);
	
	numero_edit=numero_real;												//Con esto sacamos el numero de digitos que tiene el numero introducido
	for(digitos=1;numero_edit>9;digitos++)
   	numero_edit/=10;

	numero=numero_real;														// Ahora hacemos la suma para comprobar si cumple la condicion que nos piden
	while(numero>=1){
		valor=numero%10;
		suma=suma+(pow(valor,digitos));
		numero=numero/10;
		
	}

	narcisista=numero_real==suma;											// Si cumple la condicion le damos el valor verdadero
	
	if (narcisista==true)													//Finalmente mostramos un mensaje dependiendo del resultado anterior
		cout << "El numero introducido es narcisista.\n\n";
	else
		cout << "El numero introducido no es narcisista.\n\n";
		
system("pause");

}
