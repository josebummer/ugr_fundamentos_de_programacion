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
A�ada los m�todos EsPalindromo , Invierte y NumeroMayusculas a la clase
SecuenciaCaracteres que implementen las tareas descritas en el ejercicio 1 de
esta relaci�n de problemas.
Incluya un programa principal de prueba similar al del ejercicio 1.
*/

/*
A�ada el m�todo IntercambiaComponentes para intercambiar dos componentes
de la secuencia. Por ejemplo, si la secuencia contiene {'h','o','l','a'} , des-
pu�s de intercambiar las componentes 1 y 3, se quedar�a con {'h','a','l','o'} .
�Qu� deber�a hacer este m�todo si los �ndices no son correctos?
Modifique la implementaci�n del m�todo Invierte del ejercicio 4, para que lo haga
llamando a IntercambiaComponentes .
Imprima las componentes de la secuencia desde el main , antes y despu�s
de llamar a dicho m�todo. Para ello, use el m�todo ToString() de la clase
SecuenciaCaracteres 
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class  SecuenciaCaracteres{
private:
   static const int TAMANIO  =  50;
   char vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentesDirectamente (int izda, int dcha){
      char intermedia;

      intermedia = vector_privado[izda];
      vector_privado[izda] = vector_privado[dcha];
      vector_privado[dcha] = intermedia;
   }
public:
   SecuenciaCaracteres()
      :total_utilizados(0)        // O bien en la misma declaraci�n del dato miembro:  int  total_utilizados = 0;
   {    
   }
   
   int TotalUtilizados(){
      return  total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void Aniade(char  nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }
   
   char Elemento(int  indice){
      return  vector_privado[indice];
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Modifica (int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }

   string ToString(){
      string cadena;

      for (int i=0; i < total_utilizados; i++)
         cadena = cadena + vector_privado[i];

      return cadena;
   }
   
   int NumeroMayusculas(){
      int numero_mayusculas = 0;
      
      for (int i = 0; i < total_utilizados; i++){
         if (isupper(vector_privado[i]))
            numero_mayusculas++;  
      }
      
      return numero_mayusculas;
   }

   bool EsPalindromo(){
      bool es_palindromo;
      int izda, dcha;

      es_palindromo = true;
      izda = 0;
      dcha = total_utilizados - 1;

      while (izda < dcha && es_palindromo){
         if (vector_privado[izda] != vector_privado[dcha])
            es_palindromo = false;
         else{
            izda++;
            dcha--;
         }
      }

      return es_palindromo;
   }
   
   
   void IntercambiaComponentes (int izda, int dcha){
      if (izda >= 0  &&  izda < dcha  &&  dcha < total_utilizados)
         IntercambiaComponentesDirectamente (izda, dcha);
   }

   void Invierte(){
      /*
      Primera versi�n:

         while (izda < dcha){
            IntercambiaComponentes(izda, dcha);
            izda++;
            dcha--;
         }
         
         Hay una peque�a ineficiencia ya que dentro de IntercambiaComponentes
         se realiza la comprobaci�n de que las componentes izda y dcha
         est�n en el rango correcto, algo que ya estaba garantizado
         en el bucle while (izda < dcha)
         
         Para resolverlo, se puede declarar un m�todo PRIVADO
            IntercambiaComponentesDirectamente
         que no realice la comprobaci�n de la precondici�n y que
         sea el que se llame desde los m�todos p�blicos que necesiten
         intercambiar componentes.
         
         Hay que resaltar que la comprobaci�n de una condici�n simple como
            if (izda >= 0  &&  izda < dcha  &&  dcha < total_utilizados)
         no va a afectar de una forma perceptible la eficiencia del programa,
         a�n cuando estuviese en un bucle (como en el caso while (izda < dcha))
         Lo importante de este ejercicio es la idea de declarar un m�todo privado
         para aquellos casos en los que la comprobaci�n de la precondici�n
         requiriese c�mputos m�s complejos.
      */
      
      int izda, dcha;

      izda = 0;
      dcha = total_utilizados - 1;

      while (izda < dcha){
         IntercambiaComponentesDirectamente(izda, dcha);
         izda++;
         dcha--;
      }
   }
};


int main(){
   /*
      Importante:
      
      El terminador no forma parte de la cadena de caracteres.
      Es un car�cter que se usa para terminar la entrada de datos
      y podr�a ser distinto a #
      Por lo tanto, no es un dato miembro de la clase SecuenciaCaracteres
      Lo declaramos como constante dentro del main
   */
   /*
      La variable total_introducidos nos sirve para controlar que 
      no introduzcamos m�s de un n�mero determinado de valores.
      Pero una vez tengamos los datos dentro de la cadena de caracteres,
      usaremos el m�todo TotalUtilizados() para saber cu�ntos caracteres
      hay en dicha cadena.
   */
   
   const char TERMINADOR = '#';    
   SecuenciaCaracteres secuencia;
   int total_introducidos;
   int capacidad_secuencia;
   char caracter;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   
   total_introducidos = 0;
   caracter = cin.get();
   capacidad_secuencia = secuencia.Capacidad();
   
   while (caracter != TERMINADOR && total_introducidos < capacidad_secuencia){
      secuencia.Aniade(caracter);
      total_introducidos++;
      caracter = cin.get();
   }

   //////////////////////////////////////////////////////////////////
   // N�mero de may�sculas:
   
   int numero_mayusculas;
   
   numero_mayusculas = secuencia.NumeroMayusculas();

   cout << "\n\nHay un total de " << numero_mayusculas << " may�sculas";
   
   
   //////////////////////////////////////////////////////////////////
   // Pal�ndromo:

   bool es_palindromo;
   
   es_palindromo = secuencia.EsPalindromo();

   if (es_palindromo)
      cout << "\nEs un pal�ndromo";
   else
      cout <<"\nNo es un pal�ndromo";
  
  
   //////////////////////////////////////////////////////////////////
   // Invierte:   
   
   secuencia.Invierte();
   

   cout << "\nComponentes del vector despu�s de invertirlo: < ";
   
   // Para imprimir las componentes:
   // O bien lo hacemos componente a componente:
   //
   // int longitud_secuencia;
   //
   // longitud_secuencia = secuencia.TotalUtilizados();
   // for (int i = 0; i < longitud_secuencia; i++)
   //     cout  << secuencia.Elemento(i) << " ";
   //
   // O bien directamente con el m�todo ToString()
   
   cout << secuencia.ToString();
}
