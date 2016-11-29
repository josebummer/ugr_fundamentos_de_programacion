///////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

/*
Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están
*/

#include <iostream>
using namespace std;


int main(){
   int a, b, c;  // Jamás usaremos nombres tan cortos. Este programa, por su sencillez, es una excepción.
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
