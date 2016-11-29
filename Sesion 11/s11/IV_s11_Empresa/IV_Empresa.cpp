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
 Recupere la soluci�n del ejercicio 28 (ventas de empresa) de la relaci�n de problemas
III. Resuelva el problema pedido (calcular la sucursal con mayor n�mero de ventas)
pero ahora considere que no conoce a priori el n�mero de sucursales que hay, aunque
sabe que los c�digos de �stas siempre son n�meros entre 1 y 100 y que en total no
hay m�s de 100 sucursales. Por lo tanto, tendr� que a�adir como dato miembro de
la clase, un vector con un tama�o m�ximo de 100. Cree un programa principal de
prueba.
*/

/*
Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con tres
n�meros, el identificador de la sucursal (1,2 � 3), el c�digo del producto (1, 2 � 3) y
el n�mero de unidades vendidas. Dise�ar un programa que lea desde el teclado una
serie de registros compuestos por sucursal, producto, unidades y diga cu�l
es la sucursal que m�s productos ha vendido. La serie de datos termina cuando la
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
Se puede ver que la sucursal que m�s productos ha vendido es la n�mero 2 con
41 unidades totales. La salida del programa deber� seguir exactamente el siguiente
formato:

SUCURSAL: 2
VENTAS: 41

Para comprobar que el programa funciona correctamente, cread un fichero de texto y
re-dirigid la entrada a dicho fichero.
*/


#include <iostream> 
#include <string>  
using namespace std;   

/*
VentasSucursales
   - const int NUMERO_SUCURSALES = 100
   - int num_ventas[NUMERO_SUCURSALES]
   + VentasSucursales()
   + void Actualiza(int identif_sucursal, int unidades_vendidas)
   + int IDSucursalGanadora()
   + int NumeroVentas(int id_sucursal)
*/   
   
class VentasSucursales{
private:
   static const int NUMERO_SUCURSALES = 100;
   static const int VACIO = -1;
   int num_ventas[NUMERO_SUCURSALES];   
public:
   VentasSucursales(){
      for (int i=0; i<NUMERO_SUCURSALES; i++)
         num_ventas[i] = VACIO;
   }   
   
   /*
   Normalmente empezaremos a llenar el vector desde la componente 0.
   Pero en este ejercicio, como queremos que los m�todos devuelvan 
   identificadores de sucursales (o pasarlas como par�metros) y �stos
   son a partir de 1, para no tener que estar haciendo la conversi�n
   -/+ 1, empezaremos a rellenar desde la componente 1, de forma que
   establecemos una correspondencia directa:
      �ndice en el vector <--> identificador de sucursal
   */
   
   void Actualiza(int identif_sucursal, int unidades_vendidas){
      if (unidades_vendidas > 0){         
         if (1 <= identif_sucursal && identif_sucursal <= 100)
            num_ventas[identif_sucursal] = num_ventas[identif_sucursal] 
                                           + unidades_vendidas ;
      }
   }
   
   int IDSucursalGanadora(){
      int identif_sucursal_max_ventas;
      int primera_no_vacia;
      
      primera_no_vacia = 0;
      
      while (num_ventas[primera_no_vacia] != VACIO 
             && 
             primera_no_vacia < NUMERO_SUCURSALES){
             
         primera_no_vacia++;      
      }
      
      identif_sucursal_max_ventas = primera_no_vacia;
      
      for (int i=primera_no_vacia + 1; i < NUMERO_SUCURSALES; i++){
         if (num_ventas[i] != VACIO 
             &&
             num_ventas[i] > num_ventas[identif_sucursal_max_ventas])
             
            identif_sucursal_max_ventas = i;
      }
   
      return identif_sucursal_max_ventas;   
      
      // Nota: No ser�a necesario comprobar num_ventas[i] != VACIO
      // ya que el valor vac�o es -1 que ser� siempre menor que cualquier venta
      // En cualquier caso, lo dejamos para que quede m�s claro.
   }
   
   int NumeroVentas(int id_sucursal){
      if (1 <= id_sucursal && id_sucursal <= NUMERO_SUCURSALES)
         return num_ventas[id_sucursal];
      else    
         return VACIO; 
   }
};


/*
   Observad que el main es exactamente el mismo que el de la Relaci�n
   de Problemas III. Lo �nico que cambia es la creaci�n del objeto ya que
   ahora no le pasamos los tres identificadores en el constructor,
   ya que pueden ser m�s de tres y pueden ser cualesquiera (lo �nico que
   se sabe es que son n�meros entre 1 y 100)
*/

int main(){
   const int TERMINADOR = -1;   
   int identif_sucursal,  ID_sucursal_ganadora, unidades_vendidas;
   char cod_producto; 
   int  ventas_sucursal_ganadora;
   string mensaje_entrada;
   bool fichero_vacio;
   
   VentasSucursales ventas;
   
   mensaje_entrada = "\nSe procede a leer datos del fichero ... \n";
   cout << mensaje_entrada;
 
   ID_sucursal_ganadora = TERMINADOR;   // Por si no se introduce ninguna sucursal v�lida   
   cin >> identif_sucursal;  
   fichero_vacio = identif_sucursal  == TERMINADOR;
   
   if (!fichero_vacio){
      while (identif_sucursal != TERMINADOR){              
         cin >> cod_producto;
         cin >> unidades_vendidas;
         
         ventas.Actualiza(identif_sucursal, unidades_vendidas); 

         cin >> identif_sucursal;      
      }
      
      ID_sucursal_ganadora = ventas.IDSucursalGanadora();
      ventas_sucursal_ganadora = ventas.NumeroVentas(ID_sucursal_ganadora);            
   }   
   
   if (fichero_vacio)
      cout << "\nEl fichero estaba vac�o";
   else{
      cout << "\nSucursal ganadora: " << ID_sucursal_ganadora;
      cout << "\nVentas realizadas: " << ventas_sucursal_ganadora;
   }
   
   cout << "\n\n";
   
   // 2 a 20   1 b 10   1 b 4 3 c 40   1 a 1 2 b 15   25 a 14  1 a 1    1 c 2    2 b 6    7 v 15      -1
}
