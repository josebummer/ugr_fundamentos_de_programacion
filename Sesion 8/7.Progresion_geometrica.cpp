/*Cree las siguientes funciones relacionadas con la progresi�n geom�trica que se vio en
el ejercicio 36 de la relaci�n de problemas II. Analizad cu�les deben ser los par�metros
a estas funciones.*/

#include <iostream>
#include <cmath>

using namespace std;

/*a)Una funci�n SumaHasta que calcule la suma de los primeros k valores de una
progresi�n geom�trica.
Para implementarla, use el mismo algoritmo (con un bucle for) que se vio como
soluci�n del ejercicio 36 de la relaci�n de problemas II.*/

double SumaHasta(double valor, double razon, int tope){

	int i;
	double suma;
	
	suma = valor;

	for (i=2; i<=tope; i++)     
		suma += valor * pow(razon, i-1);

return suma;
}

/*Una funci�n ProductoHasta para que multiplique los k primeros elementos de
la progresi�n, aplicando la siguiente f�rmula:*/

double ProductoHasta(double valor, double razon, int tope){

	double ultimo=valor*pow(razon,tope-1), total;
	
	total=sqrt(pow(valor*ultimo,tope));

return total;
}

/*c)Una funci�n SumaHastaInfinito para calcular la suma hasta infinito, seg�n la
siguiente f�rmula:*/

double SumaHastaInfinito(double valor, double razon){

	double suma=valor/(1-razon);

return suma;
}

double ValorAbsoluto(double razon){
	
	if(razon<0)
		razon = -razon;

return razon;
}

int main(){

	double valor_inicial, razon, suma, suma_infinito;
	int tope;
	long double producto;
	
	do{
	cout << "Introduce el valor inicial: ";
	cin >> valor_inicial;
	}while(valor_inicial==0);
	do{
	cout << "Introduce la razon: ";
	cin >> razon;
	}while(razon==0);
	do{
	cout << "Introduce el tope: ";
	cin >> tope;
	}while(tope<1);

	suma=SumaHasta(valor_inicial,razon,tope);
	producto=ProductoHasta(valor_inicial,razon,tope);
	if(ValorAbsoluto(razon)<1)
		suma_infinito=SumaHastaInfinito(valor_inicial,razon);
	
	cout << fixed;
	cout << "\nLa suma de todos los numeros es " << suma << "\n";
	cout << "El producto de todos los numero es " << producto << "\n";
	if(ValorAbsoluto(razon)<=1)
		cout << "La suma hasta infinito de los numeros es " << suma_infinito << "\n";

system("pause");
}
