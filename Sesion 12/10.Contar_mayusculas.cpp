/*
En este ejercicio no hay que definir ninguna clase. Todas las operaciones se realizan
directamente en el main.
Construya un programa que vaya leyendo caracteres hasta que se encuentre un punto
'.' y cuente el n�mero de veces que aparece cada una de las letras may�sculas.
Imprimir el resultado.
Una posibilidad ser�a declarar un vector contador_mayusculas con tantas componentes
como letras may�sculas hay ('Z'-'A'+1) y conforme se va leyendo cada
car�cter, ejecutar lo siguiente:
cin >> letra;
if (letra == 'A')
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == 'B')
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == 'C')
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este c�digo es muy redundante. Como soluci�n se propone calcular de
forma directa el �ndice entero que le corresponde a cada may�scula, de forma que
todos los if-else anteriores los podamos resumir en una �nica sentencia del tipo:
contador_mayusculas[indice] = contador_mayusculas[indice] + 1;
Hacedlo, declarando el vector directamente dentro del main.
*/

#include <iostream>

using namespace std;

int main(){

	const int TAMANIOCONT=26;
	char caracter;
	int contador_mayusculas[TAMANIOCONT];
	
	for(int i=0;i<TAMANIOCONT;i++)											//Inicializamos todos los valores del vector contador a 0
		contador_mayusculas[i]=0;
	
	cout << "Introduce la primera letra (. para salir): ";							//Pedimos los valores de entrada
	cin >> caracter;
	
	while(caracter!='.'){
		
		if(caracter>='A' && caracter<='Z')
			contador_mayusculas[caracter-'A']+=1;															//A�adimos el valor introducido al vector
		
		
		cout << "Introduce otra letra (. para salir): ";
		cin >> caracter;
	}

	cout << "\n\n";
	for(int i=0;i<TAMANIOCONT;i++)													//Mostramos el resultado final con las repeticiones de cada letra.
		if(contador_mayusculas[i]!=0){
			caracter=i+'A';
			cout << "La letra " << caracter << " se ha repetido " << contador_mayusculas[i] << " veces.\n";
		}
	cout << "\n";
system("pause");
}
