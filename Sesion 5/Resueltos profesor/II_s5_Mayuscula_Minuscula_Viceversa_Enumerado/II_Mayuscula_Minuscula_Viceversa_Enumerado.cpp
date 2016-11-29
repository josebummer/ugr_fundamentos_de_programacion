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
   Pasar un car�cter de may�scula a min�scula y viceversa (usando un enumerado)
*/

#include <iostream>
using namespace std;

enum class TipoLetra {mayuscula, minuscula, otro_caracter};
   
int main(){
   const int DISTANCIA_MAY_MIN = 'a'-'A';        
   char letra_convertida, letra_original;
   TipoLetra tipo_de_letra;
  
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra_original;
 
   if (letra_original >= 'A' && letra_original <= 'Z')
      tipo_de_letra = TipoLetra::mayuscula;
   else if (letra_original >= 'a' && letra_original <= 'z')
      tipo_de_letra = TipoLetra::minuscula;
   else
      tipo_de_letra = TipoLetra::otro_caracter;

	if (tipo_de_letra == TipoLetra::mayuscula)
      letra_convertida = letra_original + DISTANCIA_MAY_MIN;    
	else if (tipo_de_letra == TipoLetra::minuscula)
		letra_convertida = letra_original - DISTANCIA_MAY_MIN;
	else
		letra_convertida = letra_original; 

   cout << "\nEl car�cter " << letra_original  
		  << " una vez convertido es: " << letra_convertida;     

   cout << "\n\n";   
}
