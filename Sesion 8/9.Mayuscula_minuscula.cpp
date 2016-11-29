/*Recuperad la soluci�n del ejercicio 15 de la Relaci�n de Problemas II (pasar de may�scula
a min�scula y viceversa usando un enumerado) Para que el tipo de dato enumerado
sea accesible desde dentro de las funciones, debemos ponerlo antes de definir
�stas, es decir, en un �mbito global a todo el fichero. Se pide definir las siguientes
funciones y cread un programa principal de ejemplo que las llame:*/

#include <iostream>

using namespace std;

enum class TipoLetra {mayuscula, minuscula, otro_caracter};
const int AMPLITUD = 'a'-'A';

/*a)Capitalizacion nos dice si un car�cter pasado como par�metro es una min�scula,
may�scula u otro car�cter. A dicho par�metro, llamadlo una_letra. La
funci�n devuelve un dato de tipo enumerado.*/

TipoLetra Capitalizacion(char una_letra){

	TipoLetra tipo_letra;
	
	if(una_letra>='A' && una_letra <='Z')
		tipo_letra=TipoLetra::mayuscula;
	else if(una_letra>='a' && una_letra<='z')
		tipo_letra=TipoLetra::minuscula;
	else
		tipo_letra=TipoLetra::otro_caracter;
		
return tipo_letra;
}

/*Convierte_a_Mayuscula comprueba si un car�cter pasado como par�metro
es min�scula (para ello, debe llamar a la funci�n Capitalizacion), en cuyo
caso lo transforma a may�scula. Si el car�cter no es min�scula debe dejar la
letra igual. A dicho par�metro, llamadlo caracter.
Esta funci�n hace lo mismo que la funci�n tolower de la biblioteca cctype.
Observad que el par�metro una_letra de la funci�n Capitalizacion
podr�a llamarse igual que el par�metro caracter de la funci�n
Convierte_a_Mayuscula. Esto es porque est�n en �mbitos distintos y
para el compilador son dos variables distintas. Haced el cambio y comprobarlo.*/

char Convierte_a_Mayuscula(char caracter){
	
	//const int AMPLITUD = 'a'-'A'; 
	
	if(Capitalizacion(caracter)==TipoLetra::minuscula)
		caracter-=AMPLITUD; 

return caracter;
}

/*Convierte_a_Minuscula an�loga a la anterior pero convirtiendo a min�scula.
Observad que la constante de amplitud
const int AMPLITUD = 'a'-'A';
es necesaria declararla como constante local en ambas funciones. Para no repetir
este c�digo, �qu� podemos hacer? Implemente la soluci�n adoptada.*/

char Convierte_a_Minuscula(char caracter){

	//const int AMPLITUD = 'a'-'A';
	
	if(Capitalizacion(caracter)==TipoLetra::mayuscula)
		caracter+=AMPLITUD;

return caracter;
}

/*CambiaMayusculaMinuscula, a la que se le pase como par�metro un char
y haga lo siguiente:
 si el argumento es una letra en may�scula, devuelve su correspondiente letra
en min�scula,
 si el argumento es una letra en min�scula, devuelve su correspondiente letra
en may�scula,
 si el argumento no es ni una letra may�scula, ni una letra minuscula, devuelve
el car�cter pasado como argumento.*/

char CambiaMayusculaMinuscula(char caracter){

	if(Capitalizacion(caracter)==TipoLetra::minuscula)
		caracter=Convierte_a_Mayuscula(caracter);
	else if(Capitalizacion(caracter)==TipoLetra::mayuscula)
		caracter=Convierte_a_Minuscula(caracter);
	
return caracter;
}

int main(){

	char caracter;
	
	cout << "Introduce el caracter: ";
	cin >> caracter;
	
	caracter=CambiaMayusculaMinuscula(caracter);
	
	cout << "\n" << caracter << "\n\n";
	
system("pause");
}
