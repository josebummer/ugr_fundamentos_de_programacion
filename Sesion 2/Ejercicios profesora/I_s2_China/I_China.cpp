/*
 De http://countrymeters.info se obtienen los siguientes datos estimados 
 sobre la población de China:
• nace una persona cada 1.87 segundos
• muere una persona cada 3.27 segundos
• emigra una personada cada 71.9 segundos
Escriba un programa que muestre la población dentro de 2 años, considerando que la
población actual es de 1.375.570.814 personas. Los datos de entrada son el número
de años y la población de partida
*/

#include <iostream>  

using namespace std; 

int main(){                   
   // No es necesario poner 1.0 en las divisiones de las constantes,
   // ya que el otro argumento es real y por tanto la división es real
   // En cualquier caso es una buena costumbre, por lo que pondremos 1.0
   
   const double NACIMIENTOS_POR_SEGUNDO   = 1.0/1.87;   
   const double MUERTES_POR_SEGUNDO       = 1.0/3.27;
   const double EMIGRACIONES_POR_SEGUNDO  = 1.0/71.9;
   const int NUMERO_DIAS_ANIO          = 365;
   const int NUMERO_SEGUNDOS_DIA       = 24 * 60 * 60;
   
   double poblacion_actual, poblacion_futura;
   double segundos_transcurridos, numero_anios;
   
   cout << "Cálculo de la población futura.";
   cout << "\nIntroduzca la población actual: "
   cin >> poblacion_actual;
   cout << "\nIntroduzca el número de años a transcurrir: "
   cin >> numero_anios;
   
   /*
   poblacion_actual = 1375570814;  
   numero_anios = 2;
   */
   
   segundos_transcurridos = numero_anios * NUMERO_DIAS_ANIO * NUMERO_SEGUNDOS_DIA;
   
   poblacion_futura = poblacion_actual + 
                      segundos_transcurridos * (NACIMIENTOS_POR_SEGUNDO -
                                                MUERTES_POR_SEGUNDO -
                                                EMIGRACIONES_POR_SEGUNDO);
   cout << fixed;                                             
   cout << "\nPoblación futura de China: " << poblacion_futura;
   
   /*
   NOTA:
      En una aplicación real, lo lógico es que los datos de nacimiento por segundo, 
      muertes, etc, no sean constantes sino variables que se lean desde un dispositivo externo.
   */
}
