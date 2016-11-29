////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*
int ValorAbsoluto (int entero) {
	if (entero < 0)
		entero = -entero;
	else
		return entero;
}
*/

int ValorAbsoluto (int entero) {   
	if (entero < 0)
		entero = -entero;        // Esta asignaci�n s�lo afecta al par�metro formal. NO se modifica el par�metro actual :-)
	
	return entero;
}

/*
void Imprime(double a) {
   
	double a;
   cout << "\n" << a;
}
*/

void Imprime(double a) {
   cout << "\n" << a;
}

/*
void Cuadrado (int a) {
   return a*a;
}
*/


int Cuadrado (int a) {
   return a*a;
}

/*
bool EsPositivo(int valor) {
   if (valor > 0)
      return true;
}
*/

bool EsPositivo(int valor) {
   return (valor > 0);
}

int LeeEntero(string mensaje){
   int entero;
   
   cout << mensaje;
   cin >> entero;
   
   return entero;
}

void ImprimeEntero(string mensaje, int valor){
   cout << mensaje << valor << "\n";
}


int main(){
	int un_entero, abs_un_entero;
	
	un_entero = LeeEntero("Introduzca un entero ");
	abs_un_entero = ValorAbsoluto(un_entero);        // No se modifica un_entero: es un paso por valor :-)
	
	ImprimeEntero("\nEl valor absoluto del entero es ", abs_un_entero);
	
   cout << "\n\n";
	system("pause");
}
