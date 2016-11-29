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
En el ejercicio 28 se ped�a presentar un men� de operaciones al usuario. Resolved
este ejercicio definiendo una funci�n para leer la opci�n del usuario y definiendo otra
para calcular el m�ximo de dos n�meros.
*/

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

Opciones LeeOpcionUsuario (){
   Opciones opcion;
   char opcion_caracter;
   const string TEXTO_OPCIONES = 
      "\nI. Introducir n�meros \nS. Suma \nP. Producto\nM. M�ximo\nR. SaliR\n\nIntroduzca la opci�n elegida: ";
   const string TEXTO_OPCION_INCORRECTA = "\nLa opci�n elegida es incorrecta\n";
   bool opcion_es_correcta;
   
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
   
   return opcion;
}

double Max(double un_valor, double otro_valor){  
	double max;

	if (un_valor >= otro_valor)
		max = un_valor;
	else
		max = otro_valor;

	return max;
}



int main(){
   const string TEXTO_INTRO_VALORES = "\nIntroduzca dos valores enteros\n";
   const string TEXTO_RESULTADO = "\nResultado de la operaci�n: ";
   const string TEXTO_DATOS_NO_INTRODUCIDOS = "\nPrimero debe introducir datos\n";
   double dato1, dato2, resultado;
   
   Opciones opcion_usuario;
   
   // Es importante controlar que la primera vez no permita realizar operaciones
   // ya que todav�a no hay valores introducidos. Lo controlamos con un bool.
   
   bool datos_introducidos;

   datos_introducidos = false;
   
   do{      
      opcion_usuario = LeeOpcionUsuario();
   
      if (opcion_usuario != Opciones::salir){
         if (opcion_usuario == Opciones::introducir){
            cout << TEXTO_INTRO_VALORES;
            cin >> dato1;
            cin >> dato2;    
            datos_introducidos = true;
         }
         else{
            if (datos_introducidos){
               if (opcion_usuario == Opciones::suma)
                  resultado = dato1 + dato2;
               else if (opcion_usuario == Opciones::producto)
                  resultado = dato1 * dato2;
               else if (opcion_usuario == Opciones::maximo){
                  resultado = Max(dato1, dato2);
               }
               
               cout << TEXTO_RESULTADO << resultado << "\n\n";
            }
            else
               cout << TEXTO_DATOS_NO_INTRODUCIDOS;
         }  
      }
   }while(opcion_usuario != Opciones::salir);   
   
   cout << "\n\n";   
}
