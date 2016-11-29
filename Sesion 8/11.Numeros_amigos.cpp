/*Examen Septiembre 2014. Dos números amigos son dos números naturales a y b,
tales que la suma de los divisores propios de a más uno es igual a b, y viceversa. Un
ejemplo de números amigos es el par de naturales (220; 284), ya que:
 Los divisores propios de 220 son 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110, que suman
283, y 283 + 1 = 284.
 Los divisores propios de 284 son 2, 4, 71 y 142, que suman 219, y 219 + 1 = 220.
Realice un programa que implemente estas dos tareas:
a) En primer lugar debe leer dos números naturales e indicar si son o no amigos.
b) A continuación leerá otro número natural, n, e informará si existe algún número
amigo de n en el intervalo centrado en n y de radio 3.
Utilice las funciones que estime oportuno.*/

#include <iostream>

using namespace std;

int SumaDivisores(int numero){

	int suma=0,i;

	for(i=1; i<numero; i++)
		if(numero%i==0)
			suma+=i;
			
return suma; 
}

bool NumerosAmigos(int numero1, int numero2){

	bool amigos=false;

	if(SumaDivisores(numero1)==numero2 && SumaDivisores(numero2)==numero1)
		amigos=true;
		
return amigos;
}

int main(){

	int numero1, numero2;
	bool amigos=false;
	
	do{
	cout << "Introduce el primer numero: ";
	cin >> numero1;
	}while(numero1<1);
	do{
	cout << "Introduce el segundo numero: ";
	cin >> numero2;
	}while(numero2<1);
	
	amigos=NumerosAmigos(numero1,numero2);
	
	if(amigos)
		cout << "\nEl numero " << numero1 << " y el numero " << numero2 << " son numeros amigos.\n\n";
	else
		cout << "\nEl numero " << numero1 << " y el numero " << numero2 << " NO son numeros amigos.\n\n";
		
	cout << "\n\n";
	
	int numero, ultimo_numero;
	
	cout << "Introduce un numero para comprobar si tiene numeros amigos que esten cerca de el en un radio 3: ";
	cin >> numero;
	
	for(ultimo_numero=3*numero; ultimo_numero>numero; ultimo_numero--){
		if(NumerosAmigos(ultimo_numero,numero)==true){
			cout << "Radio 3 por encima: " << 3*numero;
			cout << "\nHemos encontrado un numero amigo para " << numero << " y es " << ultimo_numero << "\n\n";
		}
	}

	for(ultimo_numero=(-3)*numero; ultimo_numero<numero; ultimo_numero++){
		if(NumerosAmigos(ultimo_numero,numero)==true){
			cout << "Radio 3 por debajo: " << (-3)*numero;
			cout << "\nHemos encontrado un numero amigo para " << numero << " y es " << ultimo_numero << "\n\n";
		}
	}
	
system("pause");
}
