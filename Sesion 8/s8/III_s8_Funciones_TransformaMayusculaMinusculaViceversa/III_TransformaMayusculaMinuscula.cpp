////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////


/*
	Se pide implementar la funci�n CambiaMayMin, a la que se le pase como par�metro un char y haga lo siguiente:
		 si el argumento es una letra en may�scula, devuelve su correspondiente letra en min�scula,
		 si el argumento es una letra en min�scula, devuelve su correspondiente letra en	may�scula,
		 si el argumento no es ni una letra may�scula, ni una letra may�scula, devuelve el car�cter pasado como argumento.
	
	Observad que la constante de amplitud
		const int DIFERENCIA_MAY_MIN = 'a'-'A';
	habr�a que declararla como constante local en ambas funciones. 
	Para no repetir este c�digo, �qu� podemos hacer?
		Primera soluci�n:
			Declarar la constante como un dato GLOBAL.
			Al ser constante no se pueden producir efectos laterales (ver transparencias de teor�a)
 
		Segunda soluci�n:
			Declarar una funci�n que devuelva dicho valor.
			
		Ambas aproximaciones ser�an correctas.
*/

#include <iostream>
using namespace std;


/*
   Tenemos que usar la diferencia entre may�sculas y min�sculas (32)
   en distintos sitios del programa.
   Tenemos dos alternativas:
   
   - O bien usamos una constante global:
         const int DIFERENCIA_MAY_MIN = 'a'-'A'; 
         
   - O bien usamos una funci�n:
         int DiferenciaEntreMayusculas_y_Minusculas(){
	        return 'a'-'A';
         }    
   
   Ambas soluciones son correctas.
   En este ejemplo usaremos una constante ya que es un valor universal que
   seguramente no cambiar� nunca (la tabla ASCII mantendr� siempre los �rdenes
   de las letras en las posibles versiones futuras)
   
   En otros ejercicios, usaremos una funci�n, sobre todo en aquellos casos 
   en los que se prevea que pueda cambiar el valor 
   (porcentaje de retenci�n, salario base, etc)
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
		cout << letra << " es may�scula";
	else if (tipo_letra == TipoLetra::minuscula)
		cout << letra << " es min�scula";
	else
		cout << letra << " no es ni may�scula ni min�scula";

   cout << "\n\n";   
   system("pause");
}



/////////////////////////////////////////////////////////////////////////
// Primera versi�n

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
	Luego llama a la funci�n Convierte_a_Mayuscula(caracter) y �sta vuelve
	a comprobar lo mismo.
	Esto supone una recarga computacional que, seguramente ser� inapreciable
	en las aplicaciones que realicemos, pero podr�a ser importante si
	se llamase a CambiaMayMin dentro de un bucle (por ejemplo, para cambiar
	las letras en un texto muy grande)
	
	Para evitarlo, nos preguntamos si hubiese sido mejor implementar
	la funci�n CambiaMayMin como sigue:
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
	
	Si lo hici�semos, tendr�amos duplicado en varias funciones 
	el c�digo que realiza la transformaci�n en may�scula (restarle DIFERENCIA_MAY_MIN) 
	o en min�scula (sumarle DIFERENCIA_MAY_MIN)	
	De hecho, hemos introducido una errata a prop�sito en el c�digo
	anterior ya que hab�a que restar (sumar) cuando hemos puesto sumar (restar)	
	
	Si nos quisi�ramos evitar la doble comprobaci�n if (Capitalizacion(caracter) == minuscula)
	bastar�a con definir una funci�n m�s (ToMayuscula) que realizase la transformaci�n
	de una forma "no segura" y llamarla donde fuese necesario.
*/

////////////////////////////////////////////////////////////////////
// Segunda versi�n

/*
	ToMayuscula            -> - 32 (sin comprobar nada)
	ToMinuscula            -> + 32 (sin comprobar nada)
   Capitalizacion         -> devuelve un enumerado dependiendo
	                          del valor del car�cter
	Convierte_a_Mayuscula  -> Capitalizacion
	                       -> ToMayuscula
	Convierte_a_Minuscula  -> Capitalizacion
	                       -> ToMinuscula	                       
	CambiaMayMin           -> Capitalizacion
	                       -> ToMayuscula 
*/


char ToMinuscula (char caracter){                
	return caracter + DIFERENCIA_MAY_MIN;        // �nico sitio en el que se hace esta tarea
}

char ToMayuscula (char caracter){             
	return caracter - DIFERENCIA_MAY_MIN;        // �nico sitio en el que se hace esta tarea
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

   cout << "\nEl car�cter " << letra  << " una vez convertido es: " << convertida;

   cout << "\n\n";   
   system("pause");
}
*/
