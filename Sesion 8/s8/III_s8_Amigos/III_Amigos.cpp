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
Dos n�meros amigos son dos n�meros naturales a y b,
tales que la suma de los divisores propios de a m�s uno es igual a b, y viceversa. 
Un ejemplo de n�meros amigos es el par de naturales (220; 284), ya que:

 Los divisores propios de 220 son 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110, que suman
283, y 283 + 1 = 284.

 Los divisores propios de 284 son 2, 4, 71 y 142, que suman 219, y 219 + 1 = 220.
Realice un programa que implemente estas dos tareas:

   a) En primer lugar debe leer dos n�meros naturales e indicar si son o no amigos.
   b) A continuaci�n leer� otro n�mero natural, n, e informar� si existe alg�n n�mero
   amigo de n en el intervalo centrado en n y de radio 3.

Utilice las funciones que estime oportuno
*/

#include <iostream>
#include <cmath>
using namespace std;

bool SonAmigos_REPITIENDO_CODIGO (int uno, int otro){
   int tope_uno = uno/2, suma_uno = 0;
   int tope_otro = otro/2, suma_otro = 0;
   
   for (int divisor = 2; divisor <= tope_uno; divisor++)
      if (uno % divisor == 0)
         suma_uno = suma_uno + divisor;
         
   for (int divisor = 2; divisor <= tope_otro; divisor++)
      if (otro % divisor == 0)
         suma_otro = suma_otro + divisor; 
   
   return (suma_uno + 1 == otro && suma_otro + 1 == uno);
}

/*
   Debemos aislar el c�mputo de la suma de los divisores en una funci�n.
   Para ser coherentes, o bien definimos la funci�n
      SumaDivisoresPropios(int n)  (excluyendo 1 y n)
   o bien definimos la funci�n
      SumaDivisoresImpropios(int n)  (incluyendo 1 y n)
   Nos decantamos por la primera.
*/

int SumaDivisoresPropios (int n){
   int tope = n/2, suma = 0;
   
   for (int divisor = 2; divisor <= tope; divisor++)
      if (n % divisor == 0)
         suma = suma + divisor;
   
   return suma;
}

bool SonAmigos (int uno, int otro){
   return ( (SumaDivisoresPropios(uno) + 1 == otro) 
         && (SumaDivisoresPropios(otro) + 1 == uno) );
}

/*
   Aunque nos piden buscar amigos en un intervalo de amplitud 3,
   lo l�gico es que definamos una funci�n que trabaje con
   cualquier amplitud y que en el main, la llamemos pas�ndole
   como par�metro el 3.
*/


bool TieneAmigoAlrededor(int n, int amplitud){
   bool hay_un_amigo;   
   int amigo_candidato, tope;
         
   hay_un_amigo = false;
   amigo_candidato = n - amplitud;
   tope = n + amplitud;
   
   do{
      hay_un_amigo = SonAmigos(n, amigo_candidato);
      amigo_candidato ++;
   }while (!hay_un_amigo && amigo_candidato <= tope);
   
   return hay_un_amigo;
}


int main(){
   int un_valor, otro_valor, tercer_valor;
   int amplitud;
   bool tiene_amigo_cerca, son_amigos;
      
   cout << "N�meros amigos\n";   
   cout << "\nIntroduzca dos enteros: ";
   cin >> un_valor;
   cin >> otro_valor; 
   cout << "\nIntroduzca otro entero: ";
   cin >> tercer_valor;
   
   amplitud = 3;                                   // <- Mejor si la leemos de teclado 
   son_amigos = SonAmigos(un_valor, otro_valor);
   tiene_amigo_cerca = TieneAmigoAlrededor(tercer_valor, amplitud);
   
   ////////////////////////////////////////////////////////////////
   
   cout << "\nLos n�meros " << un_valor << " y " << otro_valor << " ";
   
   if (son_amigos)
      cout << "son amigos";
   else
      cout << "no son amigos";
   
   // ----------------------------------------------------------------
   
   cout << "\n\nEl n�mero " << tercer_valor;
          
   if (!tiene_amigo_cerca)
      cout << " no";
   
   cout << " tiene un amigo cerca (amplitud = " << amplitud << ")";
}
