///////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

/*
Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
est�n ordenados (da igual si es de forma ascendente o descendente) o no lo est�n
*/

#include <iostream>
using namespace std;


int main(){
   int a, b, c;  // Jam�s usaremos nombres tan cortos. Este programa, por su sencillez, es una excepci�n.
   bool ordenados_creciente, ordenados_decreciente, ordenados;
   
   cout << "\nIntroduzca tres enteros:\n";
   cin >> a;  
   cin >> b;
   cin >> c;
   
   ordenados_creciente =   a <= b && b <= c;
   ordenados_decreciente = a >= b && b >= c;
   ordenados = ordenados_creciente ||  ordenados_decreciente;
   
   if (ordenados)
      cout << "\nHas introducido los valores de forma ordenada";   
   else
      cout << "\nNo has introducido los valores de forma ordenada";   
   
   cout << "\n\n";
   system("pause");
}
