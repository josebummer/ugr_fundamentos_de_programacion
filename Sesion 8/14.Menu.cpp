/*En el ejercicio 28 se pedía presentar un menú de operaciones al usuario. Resolved
este ejercicio definiendo una función para leer la opción del usuario y definiendo otra
para calcular el máximo de dos números.*/

#include <iostream>

using namespace std;

void MostrarMenu(){

	cout << "\n----------\n";
	cout << "S. Suma\n";
	cout << "P. Producto\n";
	cout << "M. Maximo\n";
	cout << "R. Salir\n";
	cout << "----------\n\n";
	cout << "Introduce la opcion: ";
	
}

int Maximo(int numero1, int numero2){

	int maximo=numero1;

	if(maximo<numero2)
		maximo=numero2;

return maximo;
}

int Suma(int numero1,int numero2){

	int suma;

	suma=numero1+numero2;

return suma;
}

int Producto(int numero1, int numero2){

	int producto;
	
	producto=numero1*numero2;

return producto;
}

char LeerOpcion(){

	char opcion;
	
	do{
	cin >> opcion;
	}while(opcion!='S' && opcion!='P' && opcion!='M' && opcion!='R');

return opcion;
}

int Resultado(char opcion,int numero1,int numero2){

	int resultado;
	
	switch(opcion){
		case 'M':
			resultado=Maximo(numero1,numero2);
		break;
		case 'S':
			resultado=Suma(numero1,numero2);
		break;
		case 'P':
			resultado=Producto(numero1,numero2);
		break;
	}

return resultado;
}

int main(){

	char opcion;
	int final,numero1,numero2;
	
	cout << "Introduce el numero 1: ";
	cin >> numero1;
	cout << "Introduce el numero 2: ";
	cin >> numero2;
	
	MostrarMenu();
	opcion=LeerOpcion();
	
	final=Resultado(opcion,numero1,numero2);
	
	if(opcion=='S')
		cout << "\nLa suma de " << numero1 << " y " << numero2 << " es: " << final << "\n\n";
	else if(opcion=='P')
		cout << "\nEl producto de " << numero1 << " y " << numero2 << " es: " << final << "\n\n";
	else if(opcion=='M')
		cout << "\nEl maximo de " << numero1 << " y " << numero2 << " es: " << final << "\n\n";
	else
		cout << "\nHasta luego\n\n";
	
system("pause");
}
