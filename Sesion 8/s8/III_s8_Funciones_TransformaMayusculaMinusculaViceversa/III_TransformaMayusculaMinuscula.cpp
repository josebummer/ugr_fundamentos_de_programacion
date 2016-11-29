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
	Se pide implementar la función CambiaMayMin, a la que se le pase como parámetro un char y haga lo siguiente:
		 si el argumento es una letra en mayúscula, devuelve su correspondiente letra en minúscula,
		 si el argumento es una letra en minúscula, devuelve su correspondiente letra en	mayúscula,
		 si el argumento no es ni una letra mayúscula, ni una letra mayúscula, devuelve el carácter pasado como argumento.
	
	Observad que la constante de amplitud
		const int DIFERENCIA_MAY_MIN = 'a'-'A';
	habría que declararla como constante local en ambas funciones. 
	Para no repetir este código, ¿qué podemos hacer?
		Primera solución:
			Declarar la constante como un dato GLOBAL.
			Al ser constante no se pueden producir efectos laterales (ver transparencias de teoría)
 
		Segunda solución:
			Declarar una función que devuelva dicho valor.
			
		Ambas aproximaciones serían correctas.
*/

#include <iostream>
using namespace std;


/*
   Tenemos que usar la diferencia entre mayúsculas y minúsculas (32)
   en distintos sitios del programa.
   Tenemos dos alternativas:
   
   - O bien usamos una constante global:
         const int DIFERENCIA_MAY_MIN = 'a'-'A'; 
         
   - O bien usamos una función:
         int DiferenciaEntreMayusculas_y_Minusculas(){
	        return 'a'-'A';
         }    
   
   Ambas soluciones son correctas.
   En este ejemplo usaremos una constante ya que es un valor universal que
   seguramente no cambiará nunca (la tabla ASCII mantendrá siempre los órdenes
   de las letras en las posibles versiones futuras)
   
   En otros ejercicios, usaremos una función, sobre todo en aquellos casos 
   en los que se prevea que pueda cambiar el valor 
   (porcentaje de retención, salario base, etc)
*/


enum class TipoLetra {mayuscula, minuscula, otro_caracter};
     

TipoLetra Capitalizacion (char caracter){
	TipoLetra tipo_de_letra;
	
   if (caracter >= 'A' && caracter <= 'Z')
      tipo_de_letra = TipoLetra::mayuscula;
   else if (caracter >= 'a' && caracter <= 'z')
      tipo_de_letra = TipoLetra::minuscula;
   else
      tipo_de_letra = TipoLetra::otro_caracter;
   
   return tipo_de_letra;
}


int main(){
   char letra;
   TipoLetra tipo_letra;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra;
   
	tipo_letra = Capitalizacion(letra);
	
	if (tipo_letra == TipoLetra::mayuscula)
		cout << letra << " es mayúscula";
	else if (tipo_letra == TipoLetra::minuscula)
		cout << letra << " es minúscula";
	else
		cout << letra << " no es ni mayúscula ni minúscula";

   cout << "\n\n";   
   system("pause");
}



/////////////////////////////////////////////////////////////////////////
// Primera versión

/*
char Convierte_a_Mayuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == TipoLetra::minuscula)
		caracter_convertido = caracter - DIFERENCIA_MAY_MIN;
	else
		caracter_convertido = caracter;

	// cout << caracter_convertido;  <-- SUSPENSO !!!
	
	return caracter_convertido;
}

char Convierte_a_Minuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == TipoLetra::mayuscula)
		caracter_convertido = caracter + DIFERENCIA_MAY_MIN;
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char CambiaMayMin (char caracter){           
	char caracter_convertido;
	TipoLetra capitalizacion;
	
	capitalizacion = Capitalizacion(caracter);
	
	if (capitalizacion == TipoLetra::minuscula)
		caracter_convertido = Convierte_a_Mayuscula(caracter);  
	else if (capitalizacion == TipoLetra::mayuscula)
		caracter_convertido = Convierte_a_Minuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;

}

*/


/////////////////////////////////////////////////////////////////////////

/*
   Capitalizacion -> if (caracter >= 'A' && caracter <= 'Z')
   CambiaMayMin   -> Capitalizacion 
                  -> Convierte_a_Mayuscula  -> Capitalizacion
                  
	Dentro de CambiaMayMin se comprueba if (Capitalizacion(caracter) == minuscula)
	Luego llama a la función Convierte_a_Mayuscula(caracter) y ésta vuelve
	a comprobar lo mismo.
	Esto supone una recarga computacional que, seguramente será inapreciable
	en las aplicaciones que realicemos, pero podría ser importante si
	se llamase a CambiaMayMin dentro de un bucle (por ejemplo, para cambiar
	las letras en un texto muy grande)
	
	Para evitarlo, nos preguntamos si hubiese sido mejor implementar
	la función CambiaMayMin como sigue:
	*/
	
	
	char CambiaMayMinINCORRECTA (char caracter){           
		char caracter_convertido;
		TipoLetra capitalizacion;
		
		capitalizacion = Capitalizacion(caracter);
	
		if (capitalizacion == TipoLetra::minuscula)
			caracter_convertido = caracter + DIFERENCIA_MAY_MIN; 
		else if (capitalizacion == TipoLetra::mayuscula)
			caracter_convertido = caracter - DIFERENCIA_MAY_MIN;
		else
			caracter_convertido = caracter;

		return caracter_convertido;
	}

	
/*
	La respuesta es que no.
	
	Si lo hiciésemos, tendríamos duplicado en varias funciones 
	el código que realiza la transformación en mayúscula (restarle DIFERENCIA_MAY_MIN) 
	o en minúscula (sumarle DIFERENCIA_MAY_MIN)	
	De hecho, hemos introducido una errata a propósito en el código
	anterior ya que había que restar (sumar) cuando hemos puesto sumar (restar)	
	
	Si nos quisiéramos evitar la doble comprobación if (Capitalizacion(caracter) == minuscula)
	bastaría con definir una función más (ToMayuscula) que realizase la transformación
	de una forma "no segura" y llamarla donde fuese necesario.
*/

////////////////////////////////////////////////////////////////////
// Segunda versión

/*
	ToMayuscula            -> - 32 (sin comprobar nada)
	ToMinuscula            -> + 32 (sin comprobar nada)
   Capitalizacion         -> devuelve un enumerado dependiendo
	                          del valor del carácter
	Convierte_a_Mayuscula  -> Capitalizacion
	                       -> ToMayuscula
	Convierte_a_Minuscula  -> Capitalizacion
	                       -> ToMinuscula	                       
	CambiaMayMin           -> Capitalizacion
	                       -> ToMayuscula 
*/


char ToMinuscula (char caracter){                
	return caracter + DIFERENCIA_MAY_MIN;        // Único sitio en el que se hace esta tarea
}

char ToMayuscula (char caracter){             
	return caracter - DIFERENCIA_MAY_MIN;        // Único sitio en el que se hace esta tarea
}

char Convierte_a_Mayuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == TipoLetra::minuscula)
		caracter_convertido = ToMayuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char Convierte_a_Minuscula (char caracter){             
	char caracter_convertido;

	if (Capitalizacion(caracter) == TipoLetra::mayuscula)
		caracter_convertido = ToMinuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}

char CambiaMayMin (char caracter){           
	char caracter_convertido;
	TipoLetra capitalizacion;
	
	capitalizacion = Capitalizacion(caracter);
	
	if (capitalizacion == TipoLetra::minuscula)
		caracter_convertido = ToMayuscula(caracter);  
	else if (capitalizacion == TipoLetra::mayuscula)
		caracter_convertido = ToMinuscula(caracter);
	else
		caracter_convertido = caracter;

	return caracter_convertido;
}
	

/*

int main(){
   char letra, convertida;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra;
   
	convertida = CambiaMayMin (letra);

   cout << "\nEl carácter " << letra  << " una vez convertido es: " << convertida;

   cout << "\n\n";   
   system("pause");
}
*/
