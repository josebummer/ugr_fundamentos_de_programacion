/*Queremos modificar el ejercicio 7 para leer un car�cter letra_original desde teclado
y hacer lo siguiente:
			Si es una letra may�scula, almacenaremos en la variable letra_convertida
			la correspondiente letra min�scula.
			
			Si es una letra min�scula, almacenaremos en la variable letra_convertida
			la correspondiente letra may�scula.
			
			Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en la variable
			letra_convertida
			
El programa debe imprimir en pantalla el valor de letra_convertida e indicar si la
letra introducida era una min�scula, may�scula o no era una car�cter alfab�tico.*/

#include <iostream>

using namespace std;

int main () {

	char letra_original, letra_convertida;
	
	cout << "Intruce una caracter: ";
	cin >> letra_original;
	
	if (letra_original > 'A' && letra_original < 'Z')
		letra_convertida = letra_original + 32;
	else if (letra_original > 'a' && letra_original < 'z')
		letra_convertida = letra_original - 32;
	else
		letra_convertida = letra_original;
		
	cout << "\nEl caracter/letra convertida es: " << letra_convertida << "\n\n";

	system("pause");

}


