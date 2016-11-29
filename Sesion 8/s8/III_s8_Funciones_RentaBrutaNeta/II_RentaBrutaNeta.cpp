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
Escriba una funci�n en C++ LeeOpcion2Alternativas que imprima en pantalla
un mensaje, lea una opci�n como un car�cter y s�lo permita aceptar los caracteres
'S' o 'N' (may�scula o min�scula). �Qu� deber�a devolver la funci�n? �El car�cter
le�do o un bool?. Aplique esta funci�n en la soluci�n del ejercicio 13 (Renta bruta y
neta) de la
*/
/*
Medidas contra la crisis.

Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
seg�n el criterio que se indica posteriormente e imprima su renta neta final.
� La renta bruta es la cantidad de dinero �ntegra que el trabajador gana.
� La retenci�n fiscal es el tanto por ciento que el gobierno se queda.
� La renta neta es la cantidad que le queda al trabajador despu�s de quitarle el
porcentaje de retenci�n fiscal, es decir:
   Renta_neta = Renta_bruta - Renta_bruta * Retenci�n final / 100

Los datos a leer son:
� Si la persona es un trabajador aut�nomo o no
� Si es pensionista o no
� Estado civil
� Renta bruta (total de ingresos obtenidos)
� Retenci�n inicial a aplicar.
La retenci�n inicial se va a modificar ahora atendiendo al siguiente criterio:
� Se baja 3 puntos la retenci�n fiscal a los aut�nomos, es decir, si la retenci�n
inicial era de un 15%, por ejemplo, la retenci�n final a aplicar ser� de un 12%
(por lo que la renta neta final ser� mayor)
� Para los no aut�nomos:
   � Se sube un punto la retenci�n fiscal a todos los pensionistas, es decir, si la
   retenci�n inicial era de un 13%, por ejemplo, la retenci�n final a aplicar ser�
   de un 14% (por lo que la renta neta final ser� menor)
   � Al resto de trabajadores (no aut�nomo y no pensionista) se le aplica a todos
   una primera subida lineal de dos puntos en la retenci�n inicial.
   Una vez hecha esta subida, se le aplica (sobre el resultado anterior) las si-
   guientes subidas adicionales, dependiendo de su estado civil y niveles de
   ingresos:
      ? Se sube otros dos puntos la retenci�n fiscal si la renta bruta es menor de
      20.000 euros
      ? Se sube otros 2.5 puntos la retenci�n fiscal a los casados con renta bruta
      superior a 20.000 euros
      ? Se sube otros tres puntos la retenci�n fiscal a los solteros con renta bruta
      superior a 20.000 euros
Una vez calculada la retenci�n final, habr� que aplicarla sobre la renta bruta para as�
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
   Dentro de la funci�n anterior deber�amos usar un bool para no repetir 
   !=, == 'S' 
   Podemos mejorar la funci�n sin tocar el main, siempre que no cambie
   la cabecera de �sta. :-)
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
	
	es_autonomo    = Opcion_es_si ("Indique si la persona es un trabajador aut�nomo o no");	
	es_pensionista = Opcion_es_si ("Indique si la persona es pensionista o no");
	es_soltero     = Opcion_es_si ("Indique si la persona est� soltera o no");
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////
	// Todo lo que viene a continuaci�n no cambia con respecto al ejercicio de la relaci�n II
   ////////////////////////////////////////////////////////////////////////////////////


	
	
	cout << "\nIndique la Renta Bruta: ";		
	cin >> renta_bruta;
	cout << "\nIndique la Retenci�n a aplicar (en %): ";		
	cin >> retencion;
	
	///////////////////////////////////////////////////////////////////////////////////
	// C�mputos
	
	/*
	Algoritmo:
	
	  En la variable actualizacion_retencion vamos a ir acumulando las distintas
	  actualizaciones dependiendo de si es aut�nomo, pensionista, etc.
	    
	  Actualizamos la retenci�n final a partir de la retenci�n inicial y del
	  valor calculado anteriormente actualizacion_retencion
	   
     Calculamos la renta neta en funci�n de la renta bruta y la retenci�n final
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
	
	cout << "\nPorcentaje final de retenci�n a aplicar = " << retencion_final;
	cout << "\nRenta final = " << renta_neta;
   cout << "\n\n";
	system("pause");
}

