/*
 Calcular el número de segundos que hay entre dos instantes del mismo día.
Cada instante se caracteriza por la hora (entre 0 y 23), minuto (entre 0 y 59) y segundo
(entre 0 y 59).
El programa leerá la hora, minuto y segundo del instante inicial, y la hora, minuto y
segundo del instante final (supondremos que los valores introducidos son correctos) y
mostrará el número de segundos entre ambos instantes.
*/

#include <iostream>  

using namespace std; 

int main(){                   
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;   
   int hora_inicial, minuto_inicial, segundo_inicial;
   int hora_final, minuto_final, segundo_final;
   int segundos_iniciales, segundos_finales;
   int segundos_diferencia;
   
   cout << "Introduzca la hora, minuto y segundo inicial ";
   cin >> hora_inicial;
   cin >> minuto_inicial;
   cin >> segundo_inicial;
   
   cout << "Introduzca la hora, minuto y segundo final ";
   cin >> hora_final;
   cin >> minuto_final;
   cin >> segundo_final;
   
   segundos_iniciales = hora_inicial * MINUTOS_POR_HORA * SEGUNDOS_POR_MINUTO +
                        minuto_inicial * SEGUNDOS_POR_MINUTO +
                        segundo_inicial;
   
   segundos_iniciales = SEGUNDOS_POR_MINUTO * (hora_inicial * MINUTOS_POR_HORA   +
                                               minuto_inicial) +
                        segundo_inicial;
                        
   segundos_finales   = SEGUNDOS_POR_MINUTO * (hora_final * MINUTOS_POR_HORA   +
                                               minuto_final) +
                        segundo_final;                     
   
   segundos_diferencia = segundos_finales - segundos_iniciales;
   
   cout << "\nNúmero total de segundos de diferencia: " << segundos_diferencia;
                     
}



