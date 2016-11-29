/*
Tenga en cuenta la observación al inicio de esta relación de problemas sobre la lectura
de los caracteres. Para poder leer caracteres, incluyendo los espacios en blanco, hay
que usar caracter = cin.get(), en vez de cin >> caracter.
En este ejercicio trabajaremos con un vector directamente en el main, sin utilizar
clases.
Declare un vector de caracteres de tamaño 100. Lea las componentes considerando
como terminador el carácter # (éste no forma parte de la secuencia) y que no se
introduzcan más de 100 caracteres. Las componentes leídas ocuparán las primeras
posiciones contiguas del vector. El resto de las posiciones se quedarán con el valor
indeterminado (basura) que el compilador le asignase al principio. Para conocer cuántas
componentes se están utilizando, utilice una variable total_utilizados (que,
obviamente, deberá ser menor de 100 en todo momento)
Implemente algoritmos para realizar las siguientes tareas:
a) Comprobar si el vector es un palíndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} sería
un palíndromo, pero {'a','c','b','a'} no lo sería. Si la secuencia tiene un
número impar de componentes, la que ocupa la posición central es descartada,
por lo que {'a','b','j','b','a'} sería un palíndromo.
b) Invertir el vector. Si éste contenía, por ejemplo, los caracteres
{'m','u','n','d','o'}, después de llamar al método se quedará con
{'o','d','n','u','m'}.
c) Contar el número de mayúsculas que contiene.
*/

#include <iostream>

using namespace std;

bool Palindromo(char vector[], int utilizados){								//Funcion que devuelve si el vector es palindromo o no

	bool palindromo=true;
	int i;
	
	for(i=0;i<utilizados && palindromo;i++,utilizados--)
		if(vector[i]!=vector[utilizados-1])
			palindromo=false; 

return palindromo;
}

char *Invertir(char vector[], int utilizados){								//Funcion que invierte el vector y nos devuelve el vector invertido

	char aux;
	int i;
	
	for(i=0;i<utilizados;i++,utilizados--){
		aux=vector[i];
		vector[i]=vector[utilizados-1];
		vector[utilizados-1]=aux;
	}

return vector;
}

int Mayusculas(char vector[],int utilizados){						//Funcion que nos devuelve el numero de mayusculas que hay en el vector

	int mayusculas=0,i;
	
	for(i=0;i<utilizados;i++){
		if(vector[i]>='A' && vector[i]<='Z')
			mayusculas++;
	}

return mayusculas;
}

int main(){
	
	const int TAMANIO=100;												//Creamos la constante de tamaño del vector
	int total_utilizados=0,i,mayusculas;							//Creamos las demas variables de control y de entrada
	bool palindromo=true;
	char caracteres[TAMANIO],caracter;

	cout << "Introduce la primera letra (# para salir): ";							//Introducimos los valores
	caracter=cin.get();
	
	while(caracter!='#' && total_utilizados<TAMANIO){
		
		caracteres[total_utilizados]=caracter;								//Añadimos al vector el valor introducido por el usuario
		total_utilizados++;														//Sumamos uno al total utilizados
		
		/* SI INTRODUCIMOS LOS DATOS POR TECLADO DESCOMENTAR LA SIGUIENTE LINEA:*/
		if(caracter=='\n')
			total_utilizados--;
		
		cout << "Introduce otra letra (# para salir): ";				//Seguimos añadiendo hasta que el usuario pare
		caracter=cin.get();
	}
	
	palindromo=Palindromo(caracteres,total_utilizados);				//Obtenemos si el vector es palindromo o no
	mayusculas=Mayusculas(caracteres,total_utilizados);				//Obtenemos el numero de mayusulas que tiene el vector
	
	if(palindromo)																	//Mostramos si es palindromo
		cout << "\nEste vector SI es palindromo.";
	else
		cout << "\nEste vector NO es palindromo.";
	
	cout << "\n\nEl vector COMPLETO es:\n";					//Mostramos el vector normal
	cout << caracteres[0];								
	for(i=1;i<total_utilizados;i++){
		cout << ", " << caracteres[i];
	}
		
	Invertir(caracteres,total_utilizados);									//Invertimos el vector
	
	cout << "\n\nEl vector completo INVERTIDO es:\n";					//Mostramos el vector invertido
	cout << caracteres[0];								
	for(i=1;i<total_utilizados;i++){
		cout << ", " << caracteres[i];
	}
		
	cout << "\n\nEl numero de mayusculas en el vector es:\n" << mayusculas << "\n\n";			//Mostramos el numero de mayusculas
	
system("pause");
}
