////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con tres
números, el identificador de la sucursal (1,2 ó 3), el código del producto (1, 2 ó 3) y
el número de unidades vendidas. Diseñar un programa que lea desde el teclado una
serie de registros compuestos por sucursal, producto, unidades y diga cuál
es la sucursal que más productos ha vendido. La serie de datos termina cuando la
sucursal introducida vale -1. Por ejemplo, con la serie de datos
2 a 20
1 b 10
1 b 4
3 c 40
1 a 1
2 b 15
1 a 1
1 c 2
2 b 6
-1
Se puede ver que la sucursal que más productos ha vendido es la número 2 con
41 unidades totales. La salida del programa deberá seguir exactamente el siguiente
formato:

SUCURSAL: 2
VENTAS: 41

Para comprobar que el programa funciona correctamente, cread un fichero de texto y
re-dirigid la entrada a dicho fichero.
*/


#include <iostream> 
#include <string>  
using namespace std;   
    
int main(){  	
	const int TERMINADOR = -1;  
	const int ID_1 = 1; 
	const int ID_2 = 2; 
	const int ID_3 = 3; 
   int identif_sucursal,  identif_sucursal_max_ventas, unidades_vendidas;
   char cod_producto;
   int num_ventas_1, num_ventas_2, num_ventas_3, num_max_ventas;

   cout << "\nSe procede a leer datos del fichero ... \n";;
   
   num_max_ventas = 0;
	num_ventas_1 = 0;
	num_ventas_2 = 0;
	num_ventas_3 = 0;
   
   /* 
   Algoritmo (Sucursal con mayor número de ventas):
      
      Mientras que la sucursal sea distinto a TERMINADOR
         Leer datos de la sucursal
         Actualizar número de unidades vendidas de la sucursal que se haya introducido
         Si identif_sucursal es distinto de 1,2,3, se pasa al siguiente
		
		Calcular el Máximo
		
		Nota: En caso de empate, el algoritmo devuelve la primera en el orden ID_1, ID_2, ID_3
   */

   cin >> identif_sucursal;  
     
   while (identif_sucursal != TERMINADOR){              
      cin >> cod_producto;
      cin >> unidades_vendidas;
      
      if (identif_sucursal == ID_1)
         num_ventas_1 = num_ventas_1 + unidades_vendidas;
      else if (identif_sucursal == ID_2)
         num_ventas_2 = num_ventas_2 + unidades_vendidas;
      else if (identif_sucursal == ID_3)
         num_ventas_3 = num_ventas_3 + unidades_vendidas;
          
      cin >> identif_sucursal;   
   }

	num_max_ventas = num_ventas_1;
	identif_sucursal_max_ventas = ID_1;

   if (num_ventas_2 > num_max_ventas){
      num_max_ventas = num_ventas_2;  
      identif_sucursal_max_ventas = ID_2;
   }       

   if (num_ventas_3 > num_max_ventas){
      num_max_ventas = num_ventas_3;  
      identif_sucursal_max_ventas = ID_3;
   }    
  
   cout << "\nSucursal ganadora: " << identif_sucursal_max_ventas;
   cout << "\nVentas realizadas: " << num_max_ventas;
   
   /*
   Si deseamos dar un mensaje específico en el caso de que el fichero esté vacío,
   podríamos usar un bool es_fichero_vacio y asignarle
      es_fichero_vacio = identif_sucursal == TERMINADOR;
   antes de entrar al bucle de lectura de datos.
   Justo antes de la salida de resultados en pantalla, observaríamos
   el valor de la variable para imprimir el mensaje adecuado.
   */
   
   cout << "\n\n";
   system("pause");
}
