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
Escriba una función en C++ LeeOpcion2Alternativas que imprima en pantalla
un mensaje, lea una opción como un carácter y sólo permita aceptar los caracteres
'S' o 'N' (mayúscula o minúscula). ¿Qué debería devolver la función? ¿El carácter
leído o un bool?. Aplique esta función en la solución del ejercicio 13 (Renta bruta y
neta) de la
*/
/*
Medidas contra la crisis.

Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
según el criterio que se indica posteriormente e imprima su renta neta final.
• La renta bruta es la cantidad de dinero íntegra que el trabajador gana.
• La retención fiscal es el tanto por ciento que el gobierno se queda.
• La renta neta es la cantidad que le queda al trabajador después de quitarle el
porcentaje de retención fiscal, es decir:
   Renta_neta = Renta_bruta - Renta_bruta * Retención final / 100

Los datos a leer son:
• Si la persona es un trabajador autónomo o no
• Si es pensionista o no
• Estado civil
• Renta bruta (total de ingresos obtenidos)
• Retención inicial a aplicar.
La retención inicial se va a modificar ahora atendiendo al siguiente criterio:
• Se baja 3 puntos la retención fiscal a los autónomos, es decir, si la retención
inicial era de un 15%, por ejemplo, la retención final a aplicar será de un 12%
(por lo que la renta neta final será mayor)
• Para los no autónomos:
   – Se sube un punto la retención fiscal a todos los pensionistas, es decir, si la
   retención inicial era de un 13%, por ejemplo, la retención final a aplicar será
   de un 14% (por lo que la renta neta final será menor)
   – Al resto de trabajadores (no autónomo y no pensionista) se le aplica a todos
   una primera subida lineal de dos puntos en la retención inicial.
   Una vez hecha esta subida, se le aplica (sobre el resultado anterior) las si-
   guientes subidas adicionales, dependiendo de su estado civil y niveles de
   ingresos:
      ? Se sube otros dos puntos la retención fiscal si la renta bruta es menor de
      20.000 euros
      ? Se sube otros 2.5 puntos la retención fiscal a los casados con renta bruta
      superior a 20.000 euros
      ? Se sube otros tres puntos la retención fiscal a los solteros con renta bruta
      superior a 20.000 euros
Una vez calculada la retención final, habrá que aplicarla sobre la renta bruta para así
obtener la renta final del trabajador.
*/


#include <iostream>
#include <cctype>
using namespace std;

bool Opcion_es_si (string mensaje){
   char opcion;
   	
	do{
		cout << "\n" << mensaje << " (s/n) ";		
		cin >> opcion;
		opcion = toupper(opcion);		
	}while (opcion != 'S' && opcion != 'N');
	
	return opcion == 'S';    
}

/*
   Dentro de la función anterior deberíamos usar un bool para no repetir 
   !=, == 'S' 
   Podemos mejorar la función sin tocar el main, siempre que no cambie
   la cabecera de ésta. :-)
*/

int main(){
	const int LIMITE_SALARIO_BAJO = 20000;
   const int ACTUALIZACION_RETENCION_POR_PENSIONISTA = + 1;        
   const int ACTUALIZACION_RETENCION_POR_AUTONOMO    = - 3;
   const int ACTUALIZACION_RETENCION_POR_RENTA_BAJA  = + 6;
   const int ACTUALIZACION_RETENCION_POR_SALARIO_NORMAL_SOLTERO = + 1;
   const int ACTUALIZACION_RETENCION_POR_SALARIO_NORMAL_CASADO  = + 8;
   const int ACTUALIZACION_RETENCION_INCREMENTO_LINEAL          = + 2;	
   
   double renta_bruta, renta_neta, retencion, retencion_final, actualizacion_retencion;
	bool es_autonomo, es_soltero, es_pensionista; 
   
   
 	///////////////////////////////////////////////////////////////////////////////////
 	//  Entradas de datos
   
	cout << "\nRenta Bruta/Neta\n";
	
	es_autonomo    = Opcion_es_si ("Indique si la persona es un trabajador autónomo o no");	
	es_pensionista = Opcion_es_si ("Indique si la persona es pensionista o no");
	es_soltero     = Opcion_es_si ("Indique si la persona está soltera o no");
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////
	// Todo lo que viene a continuación no cambia con respecto al ejercicio de la relación II
   ////////////////////////////////////////////////////////////////////////////////////


	
	
	cout << "\nIndique la Renta Bruta: ";		
	cin >> renta_bruta;
	cout << "\nIndique la Retención a aplicar (en %): ";		
	cin >> retencion;
	
	///////////////////////////////////////////////////////////////////////////////////
	// Cómputos
	
	/*
	Algoritmo:
	
	  En la variable actualizacion_retencion vamos a ir acumulando las distintas
	  actualizaciones dependiendo de si es autónomo, pensionista, etc.
	    
	  Actualizamos la retención final a partir de la retención inicial y del
	  valor calculado anteriormente actualizacion_retencion
	   
     Calculamos la renta neta en función de la renta bruta y la retención final
	*/

	if (es_autonomo)
		actualizacion_retencion = ACTUALIZACION_RETENCION_POR_AUTONOMO;
	else if (es_pensionista)
		actualizacion_retencion = ACTUALIZACION_RETENCION_POR_PENSIONISTA;
	else{
      actualizacion_retencion = ACTUALIZACION_RETENCION_INCREMENTO_LINEAL;

      if (renta_bruta < LIMITE_SALARIO_BAJO)
         actualizacion_retencion = actualizacion_retencion + 
                                   ACTUALIZACION_RETENCION_POR_RENTA_BAJA;
      else if (es_soltero)
         actualizacion_retencion = actualizacion_retencion + 
                                   ACTUALIZACION_RETENCION_POR_SALARIO_NORMAL_SOLTERO;
      else
         actualizacion_retencion = actualizacion_retencion + 
                                   ACTUALIZACION_RETENCION_POR_SALARIO_NORMAL_CASADO;
   }

	retencion_final = retencion + actualizacion_retencion;
	renta_neta = renta_bruta * (1 - retencion_final/100.0);

	///////////////////////////////////////////////////////////////////////////////////
	// Salida de resultados
	
	cout << "\nPorcentaje final de retención a aplicar = " << retencion_final;
	cout << "\nRenta final = " << renta_neta;
   cout << "\n\n";
	system("pause");
}

