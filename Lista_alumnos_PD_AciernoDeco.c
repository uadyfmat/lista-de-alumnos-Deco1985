//Librerias para C, primera version solo para C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Librerias para C++:
#include <iostream>
#include <iomanip>
#include <string>
*/

        /*Estructura de datos para el alumno(dado por el profesor):               
            - Nombre Completo (cadena),  
            - Creditos Aprobados(int),
            - Semestre equivalente (int).*/

typedef struct Alumno {//Posible Struct
	char *NombreCompleto;
	int *CreditosAprob;
	int *SemestreEquiv;
	struct Alumno *siguiente;
} Nodo, *NodoPtr;

        /*Prototipos de las funciones(dado por el profesor):
            *Alumno crearAlumno(*char, int, int);
            void imprimirAlumno();
            *Nodo crearNodo(*Alumno);
            int insertarNodoOrdenadoCreditos(*nodo);
            void imprimirLista(); */

//Prototipos
Alumno crearNodo(char *NombreCompleto, int *CreditosAprob, int *SemestreEquiv);
void imprimirLista(Alumno inicio);
void liberarMemoria(Alumno *inicio);

int main()
{
    Alumno inicio = NULL; //Se inicializa el puntero o cabecera "inicio"   
//crear 5 instancias de estructuras Alumno
//crear la lista con las 5 instancias de Alumno
//insertar de forma ordenada de acuerdo al número de créditos (descendente)
//imprimir la lista

liberarMemoria(&inicio);
}

//Primera versión Nodo
Alumno crearNodo(char *NombreCompleto, int *CreditosAprob, int *SemestreEquiv) {
	Alumno nuevoNodo = (Alumno)malloc(sizeof(Nodo));
	
	nuevoNodo->NombreCompleto = strdup(NombreCompleto);
	nuevoNodo->CreditosAprob = strdup(CreditosAprob);
	nuevoNodo->SemestreEquiv = strdup(SemestreEquiv);
	
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

void imprimirLista(Alumno inicio) {
	Alumno actual = inicio;
	while (actual != NULL) {
		printf("Nombre completo: %s\n", actual->NombreCompleto);
		printf("Creditos aprobados: %s\n", actual->CreditosAprob);
		printf("Semestre equivalente: %s\n", actual->SemestreEquiv);
		printf("----------------------\n");
		actual = actual->siguiente;
	}
}

void liberarMemoria(Alumno *inicio) {
    while (*inicio != NULL) {
        Alumno temp = *inicio;
        *inicio = (*inicio)->siguiente;
        free(temp->NombreCompleto);
        free(temp->creditosAprob);
        free(temp->SemestreEquiv);
        free(temp);
    }
}
/*El Principio de Responsabilidad Única 
    dice que una clase debe hacer una cosa y, 
    por lo tanto, debe tener una sola razón para cambiar. */