/*Escriba una funci�n en C++ LeeOpcion2Alternativas que imprima en pantalla
un mensaje, lea una opci�n como un car�cter y s�lo permita aceptar los caracteres
'S' o 'N' (may�scula o min�scula). �Qu� deber�a devolver la funci�n? �El car�cter
le�do o un bool?. Aplique esta funci�n en la soluci�n del ejercicio 13 (Renta bruta y
neta) de la relaci�n de problemas II, para leer si una persona es pensionista o si es
aut�nomo.*/

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
