/*Escriba una función en C++ LeeOpcion2Alternativas que imprima en pantalla
un mensaje, lea una opción como un carácter y sólo permita aceptar los caracteres
'S' o 'N' (mayúscula o minúscula). ¿Qué debería devolver la función? ¿El carácter
leído o un bool?. Aplique esta función en la solución del ejercicio 13 (Renta bruta y
neta) de la relación de problemas II, para leer si una persona es pensionista o si es
autónomo.*/

#include <iostream>

using namespace std;

bool LeeOpcion2Alternativas(char c){
	bool SN=false;
	
	if (c=='s' || c=='S')
		SN=true;
		
return SN;
}

int main(){

	char caracter;
	bool SN;
	
	do{
	cout << "Introduce un caracter (S/N): ";
	cin >> caracter;
	}while(caracter!='s' && caracter!='S' && caracter!='n' && caracter!='N');

	SN=LeeOpcion2Alternativas(caracter);
	
	if (SN)
		cout << "\nHas introducido una s.\n\n";
	else
		cout << "\nHas introducio una n.\n\n";

system("pause");
}
