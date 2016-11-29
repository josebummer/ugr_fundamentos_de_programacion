//////////////////////////////////////////////////////////////////////////// 
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////  

/*
   Suma de los primeros términos de una Progresión Geométrica
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

	cout << "\nIntroduzca el primer término de la progresión: ";
	cin >> termino_primero;
	cout << "\nIntroduzca la razón de la progresión: ";
	cin >> razon;
	cout << "\nIntroduzca el índice >= 1 del último término que quiere sumar: ";
	cin >> indice_ultimo;

 /*   
   Algoritmo (Suma Progresión Geométrica):
   	
		Recorrer los índices -i- de los términos a sumar
			Calcular el término i-ésimo de la progresión
			Actualizar suma con dicho término
	*/		

	suma_total = termino_primero;

	for (int i = 2; i <= indice_ultimo; i++)     
		suma_total = suma_total + termino_primero * pow(razon, i-1);		

		
   /*   
   Para calcular r^(i-1) en vez de hacer la operación pow, que es costosa, 
	bastaría multiplicar en cada iteración, el valor de a_{i-1} por la razón, y ya tengo a_i

	Observad que en Matemáticas decimos:
		a_i = a_(i-1) * r
	Mientras que en un algoritmo debemos poner:
		termino = termino * r
		
		
   Algoritmo (Suma Progresión Geométrica):
   	
		Recorrer los índices -i- de los términos a sumar
			Calcular el término i-ésimo de la progresión
			   (Basta multiplar el término anterior por la razón)
			Actualizar suma con dicho término
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
