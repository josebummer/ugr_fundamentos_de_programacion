///////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
////////////////////////////////////////////////////////////////////////////


/*
Escribir un programa que lea dos n�meros enteros, escriba en pantalla el men� que
se muestra a continuaci�n, lea la opci�n seleccionada y muestre el resultado de la
operaci�n indicada.
----------------
I. Introducir n�meros
S. Suma
P. Producto
M. M�ximo
R. SaliR
----------------
Introduzca opci�n:
Observe que se permite realizar distintas operaciones (opciones S,P,M) con los mis-
mos valores num�ricos (los introducidos en la opci�n I)
*/

#include <iostream>
#include <cctype>
using namespace std;

enum class Opciones {introducir, suma, producto, maximo, salir};

int main(){
   double dato1, dato2, resultado;
   char opcion_caracter;
   const string TEXTO_OPCIONES = 
      "\nI. Introducir n�meros \nS. Suma \nP. Producto\nM. M�ximo\nR. SaliR\n\nIntroduzca la opci�n elegida: ";
   const string TEXTO_INTRO_VALORES = "\nIntroduzca dos valores enteros\n";
   const string TEXTO_RESULTADO = "\nResultado de la operaci�n: ";
   const string TEXTO_DATOS_NO_INTRODUCIDOS = "\nPrimero debe introducir datos\n";
   const string TEXTO_OPCION_INCORRECTA = "\nLa opci�n elegida es incorrecta\n";
   
   Opciones opcion;
   // Es importante controlar que la primera vez no permita realizar operaciones
   // ya que todav�a no hay valores introducidos. Lo controlamos con un bool.
   
   bool datos_introducidos, opcion_es_correcta;

   datos_introducidos = false;
   
   do{
      cout << TEXTO_OPCIONES;
      
      do{
         opcion_es_correcta = true;
         cin >> opcion_caracter;
         opcion_caracter = toupper(opcion_caracter);
         
         if (opcion_caracter == 'I')
            opcion = Opciones::introducir;
         else if (opcion_caracter == 'S')
            opcion = Opciones::suma;
         else if (opcion_caracter == 'P')
            opcion = Opciones::producto;
         else if (opcion_caracter == 'M')
            opcion = Opciones::maximo;
         else if (opcion_caracter == 'R')
            opcion = Opciones::salir;    
         else{
            cout << TEXTO_OPCION_INCORRECTA;     
            opcion_es_correcta = false;       
         }
      }while (!opcion_es_correcta);
   
      if (opcion != Opciones::salir){
         if (opcion == Opciones::introducir){
            cout << TEXTO_INTRO_VALORES;
            cin >> dato1;
            cin >> dato2;    
            datos_introducidos = true;
         }
         else{
            if (datos_introducidos){
               if (opcion == Opciones::suma)
                  resultado = dato1 + dato2;
               else if (opcion == Opciones::producto)
                  resultado = dato1 * dato2;
               else if (opcion == Opciones::maximo){
                  if (dato1 > dato2)
                     resultado = dato1;
                  else
                     resultado = dato2;
               }
               
               cout << TEXTO_RESULTADO << resultado << "\n\n";
            }
            else
               cout << TEXTO_DATOS_NO_INTRODUCIDOS;
         }  
      }
   }while(opcion != Opciones::salir);   
   
   cout << "\n\n";   
}
