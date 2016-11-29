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
   Subir el sueldo un 5% a los jubilados con ingresos inferiores a 300 euros
*/

#include <iostream>
using namespace std;

int main(){
	/*
	Si es aplicable la subida el programa mostrar� lo siguiente:
	  Salario Final: 3400 
	Si no es aplicable la subida el programa mostrar� lo siguiente:
	  No es aplicable la subida
	  Salario Final: 3000 
	*/

	/*
	if (edad > 65 && ingresos < 300)
		ingresos = ingresos * 1.05;
	else
		cout << "\nNo es aplicable la subida";

	cout << "\nSalario Final: " << ingresos;
	*/

	/*
	El problema en el anterior c�digo es que realizamos los c�mputos en el mismo bloque
	en el que realizamos la salida de datos por pantalla:

   Para resolverlo, usaremos variables l�gicas a las que se le asignar� un
   valor en el bloque de c�mputos. Posteriormente, en el bloque de salida de resultados,
   se observar� el valor asignado para actuar seg�n sea dicho valor.

   Adem�s, en vez de usar literales, usamos mejor datos constantes
   ya que facilitan la lectura del c�digo y la futura actualizaci�n.
   */

   const double IV_SUBIDA = 1.05;   // IV: �ndice de Variaci�n
   const int LIMITE_INGRESOS_BAJOS = 300;
   const int EDAD_JUBILACION = 65;
   
	int edad;
	double ingresos, ingresos_finales;
	bool es_jubilado, tiene_ingresos_bajos, es_aplicable_subida;
	
	cout << "\nIntroduce la edad de la persona: ";
	cin >> edad;
	cout << "\nIntroduce los ingresos: ";
	cin >> ingresos;
	
	// C�MPUTOS:

	es_jubilado 			= edad > EDAD_JUBILACION;
	tiene_ingresos_bajos = ingresos < LIMITE_INGRESOS_BAJOS;
	es_aplicable_subida 	= es_jubilado && tiene_ingresos_bajos;

	if (es_aplicable_subida)
		ingresos_finales = ingresos * IV_SUBIDA;
	else
		ingresos_finales = ingresos;

	// SALIDA RESULTADOS:

	if (! es_aplicable_subida)
		cout << "\nNo es aplicable la subida";

	cout << "\nSalario Final: " << ingresos_finales;

   /*
   En la sentencia

   if (es_aplicable_subida)
		ingresos = ingresos * INDICE_VARIACION_SUBIDA;

   no hay que incluir ning�n else ya que si no es aplicable la subida,
   no hay que modificar la variable ingresos y se queda con el valor que
   tuviese asignado previamente.
   */

	/*
	En el anterior c�digo usamos dos estructuras equivalentes:
		if (es_aplicable_subida)
      ......
		if (! es_aplicable_subida)
	pero logramos independizar los c�mputos de la salida de datos,
	lo cual es muy importante.
	*/

	cout << "\n\n";
	system("pause");
}
