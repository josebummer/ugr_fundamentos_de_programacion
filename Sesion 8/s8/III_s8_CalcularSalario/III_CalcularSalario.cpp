..................................................................................................................................................................................................................................................................................................................................................................................................................////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////
/*
A un trabajador le pagan seg�n sus horas trabajadas y la tarifa est� a un valor por
hora. Si la cantidad de horas trabajadas es mayor de 40 horas, la tarifa por hora se
incrementa en un 50% para las horas extras (las que haya por encima de 40). Construir
una funci�n que dado el n�mero total de horas trabajadas y el precio por hora,
devuelva el salario del trabajador.
*/

#include <iostream>
using namespace std;

/*
   El n�mero de horas base para considerar que son horas extraordinarias y
   el porcentaje de aumento son valores que no nos indican si se van 
   a usar en otros sitios del programa.
   Tenemos por tanto las siguientes opciones:
   - Declararlos como constantes locales a la funci�n que calcula el Salario
   - Si tenemos la previsi�n de que  puedan usarse en otros sitios:
      = Declararlos como constantes globales 
      = Declarar sendas funciones que devuelvan su valor
*/
      
double Salario_vs_1 (double horas_trabajadas, double salario_por_hora){
   double salario;     
   const double BASE_HORAS_EXTRA = 40;
   const double PORCENTAJE_AUMENTO_HORAS_EXTRA = 50;
   
   if (horas_trabajadas > BASE_HORAS_EXTRA){
      salario = (horas_trabajadas - BASE_HORAS_EXTRA) *  salario_por_hora;
      salario = salario + salario * PORCENTAJE_AUMENTO_HORAS_EXTRA / 100.0;
      salario = salario + BASE_HORAS_EXTRA * salario_por_hora;               
   }
   else
      salario = horas_trabajadas * salario_por_hora;
   
   return salario;   
}

/////////////////////////////////////////////////////////////////////////////

/*
   Segunda versi�n. 
   
   Con funciones por separado para obtener los valores BaseHorasExtra
   y PorcentajeAumentoHorasExtra. Tambi�n podr�an haber sido constantes globales.
*/
   

double AplicaPorcentaje (double cantidad, int porcentaje){
   return cantidad + cantidad * porcentaje / 100.0;
}

int BaseHorasExtra(){   // Tambi�n podr�a haberse usado una constante global
   return 40;
}

int PorcentajeAumentoHorasExtra(){   // Tambi�n podr�a haberse usado una constante global
   return 50;
}

double Salario (double horas_trabajadas, double salario_por_hora){
   double salario;     
   
   if (horas_trabajadas > BaseHorasExtra()){
      salario = BaseHorasExtra() * salario_por_hora +
                AplicaPorcentaje( (horas_trabajadas - BaseHorasExtra()) * salario_por_hora , 
                                   PorcentajeAumentoHorasExtra());                
   }
   else
      salario = horas_trabajadas * salario_por_hora;
   
   return salario;   
}

int main(){
   double horas_de_trabajo, a_pagar_por_hora, salario_final;
   
   cout << "C�mputo del salario en funci�n de las horas trabajadas.";
   cout << "\n\nIntroduzca n�mero de horas trabajas: ";
   cin >> horas_de_trabajo;
   cout << "\nIntroduzca el salario por hora: ";
   cin >> a_pagar_por_hora;
   
   salario_final = Salario_vs_1 (horas_de_trabajo, a_pagar_por_hora);
   
   cout << "\n\nSalario Final: " << salario_final;
}
