/*LIBRERIAS A USAR: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
  NOMBRES : VICENTE ROA & BENJAMIN QUEZADA  |
  FECHA   :   26/11/2022                    |
  RUT     :  21.287.775-1 & 21.158.853-5    |
  Profesor:  Irene Zuccar                   |

*/
/*--------------------------------------------------------------------*/
/*
    VARIABLES GLOBLAES

Usaramos distintas variables globales para poder usarla en diferentes
funciones para poder realizar las traducciones difernetes.

*/

FILE *archivo;      //Donde se almacena el archivo
char linea[4000];   //Guaradara lo que contenga el archivo
char arch[30];      //Almacenara el nombre del archivo de la opcion 1
char arch2[30];     //Almacenera el nombre del archivo de la opcion 2
int i;              //Variable como contador
int i = 0;          //Incializa en 0

struct nodo{
    char info;
    struct nodo *izq;
    struct nodo *der;
/*
    NODO:

    Creamos un nodo que contenga 3 campos:
    info : almacenara la informacion del nodo
    izq: Nodo Hijo izquerdo
    der : Nodo Hijo Derecho

*/
};
typedef struct nodo tNodo;
typedef tNodo *AB; //Nombramos nuestro tipo de dato como AB



AB creaNodo(char valor)
{
   AB aux;

   aux = (AB)malloc(sizeof(tNodo)); //Generamos un espacio en la memoria para crear los nodos
   if (aux != NULL)
   {
      aux->info = valor; //dejaremos nuestro info igual a lo que contenga valor
      aux->izq = NULL;   //El nodo hijo izquerdo iniciara como nulo
      aux->der = NULL;   // El nodo hijo derecho iniciara como nulo
   }
   else                  //Condicion en caso de que no se pueda generar el nodo
   {
       printf("\nNo hay memoria suficiente para crear el nodo.");
       exit(1);
   }
   return aux;
}
AB creaAB()
{
    /*

    Generamos arbol completo que nos serviara para acceder y ir traduciendo los distintos archivos
    (español a morse & morse a español)

    Creamos los nodos necesarios tanto para los hijos izquerdos y derecho con diferentes letras , numeros , puntos y guiones

    */
    AB T;
    T = creaNodo('#');
    T->izq = creaNodo('E');
    T->der = creaNodo('T');
    T->izq->izq = creaNodo('I');
    T->izq->der = creaNodo('A');
    T->der->izq = creaNodo('N');
    T->der->der = creaNodo('M');
    T->izq->izq->izq = creaNodo('S');
    T->izq->izq->der = creaNodo('U');
    T->izq->der->izq = creaNodo('R');
    T->izq->der->der = creaNodo('W');
    T->der->izq->izq = creaNodo('D');
    T->der->izq->der = creaNodo('K');
    T->der->der->izq = creaNodo('G');
    T->der->der->der = creaNodo('O');
    T->izq->izq->izq->izq = creaNodo('H');
    T->izq->izq->izq->der = creaNodo('V');
    T->izq->izq->der->izq = creaNodo('F');
    T->izq->izq->der->der = creaNodo('#');
    T->izq->der->izq->izq = creaNodo('L');
    T->izq->der->izq->der = creaNodo('#');
    T->izq->der->der->izq = creaNodo('P');
    T->izq->der->der->der = creaNodo('J');
    T->der->izq->izq->izq = creaNodo('B');
    T->der->izq->izq->der = creaNodo('X');
    T->der->izq->der->izq = creaNodo('C');
    T->der->izq->der->der = creaNodo('Y');
    T->der->der->izq->izq = creaNodo('Z');
    T->der->der->izq->der = creaNodo('Q');
    T->der->der->der->izq = creaNodo('#');
    T->der->der->der->der = creaNodo('#');
    T->izq->izq->izq->izq->izq = creaNodo('5');
    T->izq->izq->izq->izq->der = creaNodo('4');
    T->izq->izq->izq->der->der = creaNodo('3');
    T->izq->izq->der->der->izq = creaNodo('#');
    T->izq->izq->der->der->der = creaNodo('2');
    T->izq->der->izq->izq->izq = creaNodo('&');
    T->izq->der->izq->izq->der = creaNodo('#');
    T->izq->der->izq->der->izq = creaNodo('+');
    T->izq->der->der->izq->der = creaNodo('#');
    T->izq->der->der->der->der = creaNodo('1');
    T->der->izq->izq->izq->izq = creaNodo('6');
    T->der->izq->izq->izq->der = creaNodo('=');
    T->der->izq->izq->der->izq = creaNodo('/');
    T->der->izq->der->izq->der = creaNodo('#');
    T->der->izq->der->der->izq = creaNodo('(');
    T->der->der->izq->izq->izq = creaNodo('7');
    T->der->der->izq->izq->der = creaNodo('#');
    T->der->der->izq->der->der = creaNodo(165);// ر
    T->der->der->der->izq->izq = creaNodo('8');
    T->der->der->der->der->izq = creaNodo('9');
    T->der->der->der->der->der = creaNodo('0');
    T->izq->izq->der->der->izq->izq = creaNodo('?');
    T->izq->izq->der->der->izq->der = creaNodo('_');
    T->izq->der->izq->izq->der->izq = creaNodo('"');
    T->izq->der->izq->der->izq->der = creaNodo('.');
    T->izq->der->der->izq->der->izq = creaNodo('@');
    T->izq->der->der->der->der->izq = creaNodo(39); // '
    T->der->izq->izq->izq->izq->der = creaNodo('-');
    T->der->izq->der->izq->der->izq = creaNodo(';');
    T->der->izq->der->izq->der->der = creaNodo('!');
    T->der->izq->der->der->izq->der = creaNodo(')');
    T->der->der->izq->izq->der->der = creaNodo(',');
    T->der->der->der->izq->izq->izq = creaNodo(':');

    return T;
}

void menu()
{
    /*
    MENU:

    Generamos nuestra funcion menu que contendra lo que se mostrara a la pantalla
    al usuario.
    De este menu el usuario podra observar las distintas opciones que tiene para
    elegir.

    */
  printf("\n1. Lenguaje natural a codigo morse.\n");
  printf("2. Codigo morse a lenguaje natural.\n");
  printf("3. salir.\n");
  printf("Ingresa una opcion: ");
}


void leeArchivo(char nombre[30])    //  Esta funcion lo que nos permite es leer el archivo.
{
  archivo = fopen(nombre, "a+");    //  Esta opcion nos permite abrir el archivo, leerlo y cambiar lo que lleva dentro.
  if (archivo == NULL)              //  Esta condicional nos permite saber que si no existe un archivo de texto no se pueda iniciar y se cierre el programa.
  {
    printf("ERROR: El archivo no se pudo encontrar\n Intente de nuevo");
    exit(1);
  }else
  {
    printf("Codificacion realizada con exito\n");   //  Si se cumple esto, significa que el texto funciona .
  }
  fgets(linea, 4000, archivo);                      //  Esto nos permite añadir lo que queremos al archivo.
}

bool buscaElemento(AB A, char dato)
{
  /*
  Explicacion:
   Esta funcion nos sera util para poder comprobar si hay datos
   en los nodos correspondientes.
  */

  if (A == NULL)
    return false;       //  Si se cumple esto retornará un "false".
  if (A->info == dato)
    return true;        //  Si se cumple esto retornará un "true".
  return buscaElemento(A->izq, dato) || buscaElemento(A->der, dato); //Retorna la funcion buscaElemento por la izquierda y por la derecha en "dato".
}

void morseAespanol(AB T, char linea[4000])      //  Funcion que lee de morse a Español.
{
  if (linea[i] == ' ') {                        //  Si la linea en la posicion i es un espacio vacio (" "), entonces se colocara la informacion de T dentro del archivo.
    fprintf(archivo, "%c", T->info);
    i++;                                        // Contador de 1 en 1 (1+1).
    return;
  }
  if (linea[i] == '.') {                        //  Si la linea en la posicion i es un espacio con punto ("."), entonces se retornara la funcion recursiva.
    i++;                                        //  Contador de 1 en 1 (1+1).
    return morseAespanol(T->izq, linea);
  }
  if (linea[i] == '-') {                        //  Si la linea en la posicion i es un espacio con guion ("-"), entonces se retornara la funcion recursiva que es un AB.
    i++;                                        //  Contador de 1 en 1 (1+1).
    return morseAespanol(T->der, linea);
  }
}

void espanolAmorse(AB T, char letra)            //  Funcion que lee de Español a Morse.
{
  if (T->info == letra) {                       //  Si la informacion dentro del nodo es un caracter, entonces se colocara un espacio vacio dentro del archivo.
    fprintf(archivo, " ");
    return;
  }
  if (buscaElemento(T->izq, letra) == true) {   //  Si la informacion dentro del nodo izquierdo es true, entonces se colocara un punto dentro del archivo.
    fprintf(archivo, ".");
    return espanolAmorse(T->izq, letra);        //  Se retorna la funcion para el subarbol izquierdo.
  }
  if (buscaElemento(T->der, letra) == true) {   //  Si la informacion dentro del nodo derecho es true, entonces se colocara un guion dentro del archivo.
    fprintf(archivo, "-");
    return espanolAmorse(T->der, letra);        //  Se retorna la funcion para el subarbol derecho.
  }
}

void FraseNM(char frase[4000]) {
  AB T = NULL;                  //Iniciamos nuestro arbol T en nulo.
  T = creaAB();                 //Nuestro arbol T genera los nodos.
  fprintf(archivo, "\n");       //Escribe en el archivo dejando un espacio para la traduccion.
  while (i < strlen(frase))     // Recorrera lo que contenga frase.
  {
    espanolAmorse(T, frase[i]); // Traducira string por string usando nuestra funcion español a morse.
    if (frase[i] == ' ')
    {
      fprintf(archivo, " ");    //Escribira en el archivo un espacio.
    }
    i++;                        //Nuestra variable i que ira sumando en el proceso de traduccion.
  }
}

void FraseMN(char frase[40000])
{
  AB T = NULL;                  //Iniciamos nuestro arbol T en nulo.
  T = creaAB();                 //Nuestro arbol T genera los nodos.
  fprintf(archivo, "\n");       //Escribe en el arhcivo dejando un espacio para la traduccion.
  while (i < strlen(frase)) {   //Recorrera lo que contenga frase.
    morseAespanol(T, frase);    //Traduciendo string por string de morse a español.
    if (frase[i] == ' ') {
      fprintf(archivo, " ");    //Escribira un espacio en el archivo.
      i++;                      //Sumara 1 en la variable I para el proceso de traduccion.
    }
  }
}

void Condicionales(int op) {    //Funcion que contendra las condicionales del menu.

  if (op == 1) {                                 //Si la opcion que elige el usuario es 1.
    printf("\nIngrese el nombre del archivo: "); //Imprimira por pantalla para ingresar el archivo.
    gets(arch);                                  //Obtenemos lo que ingrese el usuario y la guardamos en la variable arch.
    leeArchivo(arch);                            //Pasamos como paramatero principal el nombre del archivo ingresado para que pueda ser leído.
    FraseNM(linea);                              //Usamos nuestra funcion que recorrera y ingresara la traduccion en el archivo.
    fclose(archivo);                             //Cerreamos nuestro arhcivo para que pueda traducirse.
    system("pause");                             //Pausamos el programa.
  }
  if (op == 2) {                                 //Si la opcion que elige el usuario es 2.
    printf("\nIngrese el nombre del archivo: "); //Imprime "Ingrese el nombre del archivo".
    gets(arch2);                                 //Se guardara lo que colocamos en arch2.
    leeArchivo(arch2);                          //Lee el archivo de arch2.
    FraseMN(linea);                              //Se lee la funcion FraseMN.
    fclose(archivo);                             //Se cierra el archivo.
    system("pause");                             //Se pausa el sistema.
  }
  system("cls");                                 //Limpia la pantalla.

  if (op == 3) {                                 //Si la opcion que elige el usuario es 3.
    exit(1);                                     //Se cierra el programa.
  }
}

int main()
{

  int usuario;                  //Creamos nuestra variable usuario.
  while (usuario != 3) {        //Mientras el usuario ponga un numero distinto a 3.
    menu();                     //Se ejecuta el menu.
    scanf("%d", &usuario);      //Se escanea y escribimos en usuario.
    fflush(stdin);              //Se limpia el caracter vacio.
    Condicionales(usuario);     //Se ejecuta la funcion Condicionales en "usuario".
  }

  printf("\n");
  printf("\n\n");
  return 0;
}


//FIN DEL PROGRAMA.
