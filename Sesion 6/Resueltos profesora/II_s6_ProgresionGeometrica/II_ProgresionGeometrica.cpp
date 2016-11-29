//////////////////////////////////////////////////////////////////////////// 
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////  

/*
   Suma de los primeros t�rminos de una Progresi�n Geom�trica
   	a_i = a * r^(i-1)
*/

#include <iostream> 
#include <cmath>  
using namespace std;   
    
int main(){     
	double termino_primero, razon;
	int  indice_ultimo;
	double suma_total;
	double termino;

	cout << "\nIntroduzca el primer t�rmino de la progresi�n: ";
	cin >> termino_primero;
	cout << "\nIntroduzca la raz�n de la progresi�n: ";
	cin >> razon;
	cout << "\nIntroduzca el �ndice >= 1 del �ltimo t�rmino que quiere sumar: ";
	cin >> indice_ultimo;

 /*   
   Algoritmo (Suma Progresi�n Geom�trica):
   	
		Recorrer los �ndices -i- de los t�rminos a sumar
			Calcular el t�rmino i-�simo de la progresi�n
			Actualizar suma con dicho t�rmino
	*/		

	suma_total = termino_primero;

	for (int i = 2; i <= indice_ultimo; i++)     
		suma_total = suma_total + termino_primero * pow(razon, i-1);		

		
   /*   
   Para calcular r^(i-1) en vez de hacer la operaci�n pow, que es costosa, 
	bastar�a multiplicar en cada iteraci�n, el valor de a_{i-1} por la raz�n, y ya tengo a_i

	Observad que en Matem�ticas decimos:
		a_i = a_(i-1) * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
		
		
   Algoritmo (Suma Progresi�n Geom�trica):
   	
		Recorrer los �ndices -i- de los t�rminos a sumar
			Calcular el t�rmino i-�simo de la progresi�n
			   (Basta multiplar el t�rmino anterior por la raz�n)
			Actualizar suma con dicho t�rmino
	*/	

	termino = termino_primero;
	suma_total = termino; 

	for (int i = 2; i <= indice_ultimo ; i++){     
		termino = termino * razon;
		suma_total = suma_total +  termino;
	}
	
	cout << "\nSuma hasta " << indice_ultimo << " = " << suma_total;
	
   cout << "\n\n";
	system("pause");
}
