#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"

//DEFINICIONES
#define DIM 60

//ESTRUCTURAS
typedef struct
{
    int legajo;
    char nombreYApellido[DIM];
    int edad;
    int anio;
} Alumno;

//PROTOTIPADO
//AUX
void mostrarMenuTP7();
//Ejercicio 1
void ejercicioNro1();
void cargarArchivoInt();
//Ejercicio 2
void ejercicioNro2();
void mostrarArchivoInt();
//Ejercicio 3
void ejercicioNro3(char []);
int validosArchivoInt(char []);
//Ejercicio 4
void ejercicioNro4(char []);
void cargarArchivoAlumnos(char []);
Alumno cargarAlumno();
int comprobarLegajo(int );
int comprobarEdad(int );
int comprobarAnio(int );
void generarArchivoAlumnos(char []);
Alumno generarAlumno();
void generarNombre();
//Ejercicio 5
void ejercicioNro5(char []);
void mostrarArchivoAlumnos(char []);
void mostrarAlumno(Alumno );
int validosArchivo(char []);
//Ejercicio 7
void legajoDeArchivoAPila(char [], Pila * );

//MAIN
int main()
{
    menu();
}

//FUNCIONES
//MENU
void menu()
{
    //Declaraciones
    srand(time(NULL));
    //Ejercicio 1
    char continuar = 's';
    int nroEjercicio = 0;
    char nombreArchivoInt[] = {"integers.bin"};
    //Ejercicio 4
    char nombreArchivoAlumnos[] = {"alumnos.bin"};
    //Ejercicio 7
    Pila pilaLegajos;
    inicpila(&pilaLegajos);

    //Funciones
    while( continuar == 's' || continuar == 'S' )
    {
        mostrarMenuTP7();
        printf("\nIngrese el numero de ejercicio que desea ejecutar ( 0 para salir ): ");
        fflush(stdin);
        scanf("%i", &nroEjercicio);
        switch( nroEjercicio )
        {
        case 1:
            ejercicioNro1(nombreArchivoInt);
            break;
        case 2:
            ejercicioNro2(nombreArchivoInt);
            break;
        case 3:
            ejercicioNro3(nombreArchivoInt);
            break;
        case 4:
            ejercicioNro4(nombreArchivoAlumnos);
            break;
        case 5:
            ejercicioNro5(nombreArchivoAlumnos);
            break;
        case 6:
            ejercicioNro4(nombreArchivoAlumnos);
            break;
        case 7:
            ejercicioNro7(nombreArchivoAlumnos, &pilaLegajos);
            break;
        case 15:
            ejercicioNro15(nombreArchivoAlumnos, &pilaLegajos);
            break;
        case 0:
            continuar = -1;
            break;
        default:
            printf("\nEl ejercicio ingresado no es valido.");
            break;
        }
        if( continuar != -1 )
        {
            printf("\nDesea continuar en el menu? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
    }
    printf("\n\nSaliendo del programa...\n");
}

//AUX
void mostrarMenuTP7()
{
    printf("\n\nTrabajo Practico Nro 7: Archivos");
    printf("\n\nUtilizando datos primitivos (int, char, float, etc), elija un tipo de dato y realice las siguientes funciones:");
    printf("\n\n1. Hacer una función que agregue un elemento al final de un archivo.");
    printf("\n\n2. Hacer una función que muestre por pantalla el contenido de un archivo.");
    printf("\n\n3. Hacer una función que retorne la cantidad de registros que contiene un archivo.");
    printf("\n\nUtilizando la estructura: ");
    printf("\n| typedef struct {");
    printf("\n|   int legajo;");
    printf("\n|   char nombreYapellido [30];");
    printf("\n|   int edad;");
    printf("\n|   int anio;");
    printf("\n| } StAlumno;");
    printf("\n\n4. Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está");
    printf("\ncreado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función");
    printf("\n\n5. Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.");
    printf("\n\n6. Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se");
    printf("\npiden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.");
    printf("\n\n7. Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.");
    printf("\n\n8. Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que ");
    printf("\nse envía por parámetro.");
    printf("\n\n9. Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico");
    printf("\n(por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar");
    printf("\n\n10. Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.");
    printf("\n\n11. Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.");
    printf("\n\n12. Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo. Asimismo, realice");
    printf("\notra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.");
    printf("\n\n13. Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función");
    printf("\npara uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.");
    printf("\n\n14. Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que muestre el contenido de un registro, cuyo");
    printf("\nnúmero (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo.");
    printf("\n\n15. Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos. La misma debe permitir");
    printf("\nmodificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo.");
    printf("\n\n16. Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo. No se puede usar otro archivo auxiliar ni");
    printf("\nun arreglo auxiliar. Debe trabajar sobre el archivo. Puede utilizar variables de tipo alumno auxiliares.");
    printf("\n\n17. Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder");
    printf("\nejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.\n");
}

//Ejercicio 1
void ejercicioNro1(char nombreArchivoInt[])
{
    cargarArchivoInt(nombreArchivoInt);
}

void cargarArchivoInt(char nombreArchivoInt[])
{
    char continuar = 's';
    int bufferInt;
    FILE *archivoInt = fopen(nombreArchivoInt, "ab");
    if( archivoInt == NULL )
    {
        printf("\nEl archivo no existe.");
    }
    else
    {
        while( continuar == 's' || continuar == 'S' )
        {
            printf("\nIngrese un integer para agregar al archivo: ");
            fflush(stdin);
            scanf("%i", &bufferInt);

            fwrite(&bufferInt, sizeof(int), 1, archivoInt);

            printf("\nDesea seguir agregando elementos al archivo? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
        fclose(archivoInt);
    }
}

//Ejercicio 2
void ejercicioNro2(char nombreArchivoInt[])
{
    mostrarArchivoInt(nombreArchivoInt);
}

void mostrarArchivoInt(char nombreArchivoInt[])
{
    int bufferInt;
    FILE *archivoInt = fopen(nombreArchivoInt, "rb");
    if( archivoInt == NULL )
    {
        printf("\nEl archivo no existe.");
    }
    else
    {
        while( !feof(archivoInt) )
        {
            fread(&bufferInt, sizeof(int), 1, archivoInt);
            if( !feof(archivoInt) )
            {
                printf("\n|%i| ", bufferInt);
            }
        }
        fclose(archivoInt);
    }
}

//Ejercicio 3
void ejercicioNro3(char nombreArchivoInt[])
{
    int validosInt = validosArchivoInt(nombreArchivoInt);
    printf("\nCantidad de validos en archivo Int: %i", validosInt);
}

int validosArchivoInt(char nombreArchivoInt[])
{
    int validos = 0;
    FILE *archivoInt = fopen(nombreArchivoInt, "rb");
    if( archivoInt == NULL )
    {
        printf("\nEl archivo no existe.");
    }
    else
    {
        fseek(archivoInt, sizeof(int), SEEK_END);
        validos = (int)ftell(archivoInt) / sizeof(int);
    }
    return validos;
}

//Ejercicio 4, 6
void ejercicioNro4(char nombreArchivoAlumnos[])
{
    //cargarArchivoAlumnos(nombreArchivoAlumnos);
    generarArchivoAlumnos(nombreArchivoAlumnos);
}

void cargarArchivoAlumnos(char nombreArchivoAlumnos[])
{
    char continuar = 's';
    Alumno bufferAlumno;
    FILE *archivoAlumnos = fopen(nombreArchivoAlumnos, "ab"); //si el archivoAlumnos no existe se crea
    if( archivoAlumnos == NULL )
    {
        printf("\nEl archivo no existe.");
    }
    else
    {
        while( continuar == 's' )
        {
            bufferAlumno = cargarAlumno();

            fwrite(&bufferAlumno, sizeof(Alumno), 1, archivoAlumnos);
            mostrarAlumno(bufferAlumno);

            printf("\nDesea agregar otro alumno al archivo Alumnos? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
        fclose(archivoAlumnos);
    }
}

Alumno cargarAlumno()
{
    Alumno alumnoACargar;
    printf("\n-----------------------------------");
    printf("\nIngrese el numero de legajo del alumno: ");
    fflush(stdin);
    scanf("%i", &alumnoACargar.legajo);
    while( comprobarLegajo(alumnoACargar.legajo) == 0 )
    {
        printf("\nNumero de legajo ingresado no valido, por favor ingrese un numero entre 0 y 9999.");
        printf("\nIngrese el numero de legajo del alumno: ");
        fflush(stdin);
        scanf("%i", &alumnoACargar.legajo);
    }
    printf("\nIngrese el nombre del alumno: ");
    fflush(stdin);
    gets(alumnoACargar.nombreYApellido);
    printf("\nIngrese la edad del alumno: ");
    fflush(stdin);
    scanf("%i", &alumnoACargar.edad);
    while( comprobarEdad(alumnoACargar.edad) == 0 )
    {
        printf("\nEdad del alumno no valido, por favor ingrese un numero entre 0 y 130.");
        printf("\nIngrese la edad del alumno: ");
        fflush(stdin);
        scanf("%i", &alumnoACargar.edad);
    }
    printf("\nIngrese el anio de igreso del alumno: ");
    fflush(stdin);
    scanf("%i", &alumnoACargar.anio);
    while( comprobarAnio(alumnoACargar.anio) == 0 )
    {
        printf("\nAnio de ingreso no valido, por favor ingresa un anio entre 1990 y 2023.");
        printf("\nIngrese la edad del alumno: ");
        fflush(stdin);
        scanf("%i", &alumnoACargar.anio);
    }
    return alumnoACargar;
}

int comprobarLegajo(int legajo)
{
    int comprobado = 0;
    if( legajo >= 0 && legajo <= 9999 ) comprobado == 1;
    return comprobado;
}

int comprobarEdad(int edad)
{
    int comprobado = 0;
    if( edad >= 0 && edad <= 130 ) comprobado == 1;
    return comprobado;
}

int comprobarAnio(int Anio)
{
    int comprobado = 0;
    if( Anio >= 1990 && Anio <= 2023 ) comprobado == 1;
    return comprobado;
}

void generarArchivoAlumnos(char nombreArchivoAlumnos[])
{
    char continuar = 's';
    Alumno bufferAlumno;
    FILE *archivoAlumnos = fopen(nombreArchivoAlumnos, "ab"); //si el archivoAlumnos no existe se crea
    if( archivoAlumnos == NULL )
    {
        printf("\nEl archivo no existe.");
    }
    else
    {
        while( continuar == 's' )
        {
            bufferAlumno = generarAlumno();
            fwrite(&bufferAlumno, sizeof(Alumno), 1, archivoAlumnos);
            mostrarAlumno(bufferAlumno);
            printf("\nDesea agregar otro alumno al archivo Alumnos? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
        fclose(archivoAlumnos);
    }
}

Alumno generarAlumno()
{
    Alumno alumnoAGenerar;
    alumnoAGenerar.legajo = rand()%9999;
    generarNombre(alumnoAGenerar.nombreYApellido);
    alumnoAGenerar.edad = rand()%40+17;
    alumnoAGenerar.anio = rand()%32+1990;
    return alumnoAGenerar;
}

void generarNombre(char nombreRandom[])
{
    int i = 0, nroLetras = 12, espacioRandom = 0;
    while( i < nroLetras )
    {
        espacioRandom = rand()%8; //1 en 8 de ser un espacio
        if( espacioRandom == 1 )
        {
            nombreRandom[i] = 32;
        }
        else
        {
            nombreRandom[i] = rand()%25+97;
        }
        i++;
    }
    nombreRandom[i] = '\0';
}

//Ejercicio 5
void ejercicioNro5(char nombreArchivoAlumnos[])
{
    mostrarArchivoAlumnos(nombreArchivoAlumnos);
}

void mostrarArchivoAlumnos(char nombreArchivoAlumnos[])
{
    Alumno alumnoBuffer;
    FILE *archivoAlumnos = fopen(nombreArchivoAlumnos, "rb");
    if( archivoAlumnos != NULL )
    {
        while( !feof(archivoAlumnos) )
        {
            fread(&alumnoBuffer, sizeof(Alumno), 1, archivoAlumnos);
            if( !feof(archivoAlumnos) )
            {
                mostrarAlumno(alumnoBuffer);
            }
        }
        fclose(archivoAlumnos);
    }
}

void mostrarAlumno(Alumno alumnoAMostrar)
{
    printf("\n-----------------------------------");
    printf("\nAlumno");
    printf("\nNumero de legajo: %i", alumnoAMostrar.legajo);
    printf("\nNombre: %s", alumnoAMostrar.nombreYApellido);
    printf("\nEdad: %i", alumnoAMostrar.edad);
    printf("\nAnio: %i", alumnoAMostrar.anio);
    printf("\n-----------------------------------");
}

int validosArchivo(char nombreArchivoAlumnos[])
{
    int validos;
    FILE *bufferArchivo = fopen(nombreArchivoAlumnos, "rb");
    if( bufferArchivo != NULL )
    {
        fseek(bufferArchivo, 0, SEEK_END);
        validos = ftell(bufferArchivo) / sizeof(Alumno);
        fclose(bufferArchivo);
    }
    return validos;
}

//Ejercicio 7
void ejercicioNro7(char nombreArchivoAlumnos[], Pila *pilaLegajos)
{
    legajoDeArchivoAPila(nombreArchivoAlumnos, pilaLegajos);
    mostrar(pilaLegajos);
}

void legajoDeArchivoAPila(char nombreArchivoAlumnos[], Pila *pilaLegajos)
{
    Alumno bufferAlumno;
    FILE *bufferArchivo = fopen(nombreArchivoAlumnos, "rb");
    if( bufferArchivo != NULL )
    {
        while( !feof(bufferArchivo) )
        {
            fread(&bufferAlumno, sizeof(Alumno), 1, bufferArchivo);
            if( !feof(bufferArchivo) && bufferAlumno.edad > 17 )
            {
                printf("\nbufferAlumno.legajo: %i", bufferAlumno.legajo); //debug
                apilar(pilaLegajos, bufferAlumno.legajo);
            }
        }
        fclose(bufferArchivo);
    }
}

int cantidadAlumnosMayoresQue(char nombreArchivoAlumnos[], int edad)
{
    int validosMayoresDeEdad = 0;
    Alumno bufferAlumno;
    FILE *bufferArchivoAlumnos = fopen(nombreArchivoAlumnos, "rb");
    if( bufferArchivoAlumnos == NULL )
    {
        printf("\nEl archivo no existe.");
    }
    else
    {
        while( !feof(bufferArchivoAlumnos) )
        {
            fread(&bufferAlumno, sizeof(Alumno), 1, bufferArchivoAlumnos);
            while( !feof(bufferArchivoAlumnos) && bufferAlumno.edad > edad ) validosMayoresDeEdad++;
        }
        fclose(bufferArchivoAlumnos);
    }
    printf("\nvalidosMayoresDeEdad: %i", validosMayoresDeEdad);
    return validosMayoresDeEdad;
}

//Ejercicio 15
void ejercicioNro15(char nombreArchivoAlumnos[])
{
    char continuar = 's';
    int opcionMenu = 0;
    while( continuar == 's' || continuar == 'S' )
    {
        mostrarMenuArchivo();
        printf("\nIngrese la opcion que desea realizar ( 0 para salir ): ");
        fflush(stdin);
        scanf("%c", &opcionMenu);
        switch( opcionMenu )
        {
        case 1:
            opcion1(nombreArchivoAlumnos);
            break;
        case 2:
            //opcion2(nombreArchivoAlumnos);
            break;
        case 3:
            //opcion3(nombreArchivoAlumnos);
            break;
        case 4:
            //opcion4(nombreArchivoAlumnos);
            break;
        default:
            printf("\nLa opcion ingresada no es valida.");
            break;
        }
        printf("\nDesea continuar en este menu? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
}

void mostrarMenuArchivo()
{
    printf("\n\nOperaciones: ");
    printf("\n1. Mostrar un Alumno.");
    printf("\n2. Editar un Alumno.");
    printf("\n2. Agregar un Alumno.");
    printf("\n3. Borrar un Alumno.");
}

void opcion1(char nombreArchivoAlumnos[])
{
    char continuar = 's';
    int opcionMenu = 0;
    while( continuar == 's' || continuar == 'S' )
    {
        mostrarMenuOpcion1();
        printf("\nIngrese la forma en la que desea buscar el alumno:");
        fflush(stdin);
        scanf("%c", &opcionMenu);
        switch( opcionMenu )
        {
        case 1:
            buscarAlumnoXLegajo(nombreArchivoInt);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("\nLa opcion ingresada no es valida.");
            break;
        }
        printf("\nDesea continuar en este menu? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
}

void mostrarMenuOpcion1()
{
    printf("\n\nBuscar alumno por: ");
    printf("\n1. Legajo.");
    printf("\n2. Nombre y Apellido.");
    printf("\n2. Edad.");
    printf("\n3. Anio.");
}
