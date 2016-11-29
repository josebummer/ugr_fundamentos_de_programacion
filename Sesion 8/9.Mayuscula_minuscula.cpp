/*Recuperad la solución del ejercicio 15 de la Relación de Problemas II (pasar de mayúscula
a minúscula y viceversa usando un enumerado) Para que el tipo de dato enumerado
sea accesible desde dentro de las funciones, debemos ponerlo antes de definir
éstas, es decir, en un ámbito global a todo el fichero. Se pide definir las siguientes
funciones y cread un programa principal de ejemplo que las llame:*/

#include <iostream>

using namespace std;

enum class TipoLetra {mayuscula, minuscula, otro_caracter};
const int AMPLITUD = 'a'-'A';

/*a)Capitalizacion nos dice si un carácter pasado como parámetro es una minúscula,
mayúscula u otro carácter. A dicho parámetro, llamadlo una_letra. La
función devuelve un dato de tipo enumerado.*/

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

/*Convierte_a_Mayuscula comprueba si un carácter pasado como parámetro
es minúscula (para ello, debe llamar a la función Capitalizacion), en cuyo
caso lo transforma a mayúscula. Si el carácter no es minúscula debe dejar la
letra igual. A dicho parámetro, llamadlo caracter.
Esta función hace lo mismo que la función tolower de la biblioteca cctype.
Observad que el parámetro una_letra de la función Capitalizacion
podría llamarse igual que el parámetro caracter de la función
Convierte_a_Mayuscula. Esto es porque están en ámbitos distintos y
para el compilador son dos variables distintas. Haced el cambio y comprobarlo.*/

char Convierte_a_Mayuscula(char caracter){
	
	//const int AMPLITUD = 'a'-'A'; 
	
	if(Capitalizacion(caracter)==TipoLetra::minuscula)
		caracter-=AMPLITUD; 

return caracter;
}

/*Convierte_a_Minuscula análoga a la anterior pero convirtiendo a minúscula.
Observad que la constante de amplitud
const int AMPLITUD = 'a'-'A';
es necesaria declararla como constante local en ambas funciones. Para no repetir
este código, ¿qué podemos hacer? Implemente la solución adoptada.*/

char Convierte_a_Minuscula(char caracter){

	//const int AMPLITUD = 'a'-'A';
	
	if(Capitalizacion(caracter)==TipoLetra::mayuscula)
		caracter+=AMPLITUD;

return caracter;
}

/*CambiaMayusculaMinuscula, a la que se le pase como parámetro un char
y haga lo siguiente:
 si el argumento es una letra en mayúscula, devuelve su correspondiente letra
en minúscula,
 si el argumento es una letra en minúscula, devuelve su correspondiente letra
en mayúscula,
 si el argumento no es ni una letra mayúscula, ni una letra minuscula, devuelve
el carácter pasado como argumento.*/

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
