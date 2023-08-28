#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
    char *NombreCompleto;
    int CreditosAprob;
    int SemestreEquiv;
    struct Alumno *siguiente;
} Alumno, *AlumnoPtr;

typedef struct Nodo {
    Alumno alumno;
    struct Nodo *siguiente_Nodo;
} Nodo, *NodoPtr;

AlumnoPtr crearAlumno(char*, int, int);
NodoPtr crearNodo(AlumnoPtr);
void insertarOrdenado(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr);
void imprimirAlumno(AlumnoPtr alumno);
void liberarMemoria(NodoPtr);

int main() {
    NodoPtr lista = NULL;
   
    AlumnoPtr alumno1 = crearAlumno("Deco Acierno Hernandez", 44, 3);
    AlumnoPtr alumno2 = crearAlumno("Maria de todos los Angeles Zapata Basto", 38, 2);
    AlumnoPtr alumno3 = crearAlumno("Venustiano Quintal Trejo", 150, 6);
    AlumnoPtr alumno4 = crearAlumno("Angel Barrueta Arceo", 110, 4);
    AlumnoPtr alumno5 = crearAlumno("Christofer Salazar de la Torre", 80, 8);
    
    insertarOrdenado(&lista, crearNodo(alumno1));
    insertarOrdenado(&lista, crearNodo(alumno2));
    insertarOrdenado(&lista, crearNodo(alumno3));
    insertarOrdenado(&lista, crearNodo(alumno4));
    insertarOrdenado(&lista, crearNodo(alumno5));
    
    imprimirLista(lista);
    
    imprimirAlumno(alumno1);
    
    liberarMemoria(lista);
}
AlumnoPtr crearAlumno(char* nombre, int creditos, int semestre) {
    AlumnoPtr nuevoAlumno = (AlumnoPtr)malloc(sizeof(Alumno));//Reservamos memoria dinamica 
    if (nuevoAlumno != NULL) {
        nuevoAlumno->NombreCompleto = strdup(nombre); //strdup Duplica la cadena de caracteres
        nuevoAlumno->CreditosAprob = creditos;
        nuevoAlumno->SemestreEquiv = semestre;
        nuevoAlumno->siguiente = NULL;
        printf("Se ha creado una Estructura Alumno en la direccion de memoria: %p\n", nuevoAlumno);
    }
    return nuevoAlumno;
}
NodoPtr crearNodo(AlumnoPtr alumno) {
    NodoPtr nuevoNodo = (NodoPtr)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->alumno = *alumno;
        nuevoNodo->siguiente_Nodo = NULL;
        printf("Se ha creado un Nodo en la estructura Alumno en: %p\n", nuevoNodo);
    }
    return nuevoNodo;
}
void insertarOrdenado(NodoPtr* lista, NodoPtr nodo) {
    if (*lista == NULL || (*lista)->alumno.CreditosAprob <= nodo->alumno.CreditosAprob) {//Verifica si el puntero de lista es nulo o si el nodo a insertar tiene mayor creditos
        nodo->siguiente_Nodo = *lista;//Conecta al nodo con la cabecera
        *lista = nodo;
    } else { //En caso contrario, se busca su posicion 
        NodoPtr actual = *lista; 
        while (actual->siguiente_Nodo != NULL && actual->siguiente_Nodo->alumno.CreditosAprob > nodo->alumno.CreditosAprob) {//mientras que no sean mayores al actual 
            actual = actual->siguiente_Nodo;
        }
        nodo->siguiente_Nodo = actual->siguiente_Nodo;
        actual->siguiente_Nodo = nodo;
    }
}
void imprimirLista(NodoPtr lista) {
    printf("\nLista de Alumnos:\n");
    NodoPtr actual = lista;
    while (actual != NULL) {
        printf("Nombre: %s\n", actual->alumno.NombreCompleto);
        printf("Creditos: %d\n", actual->alumno.CreditosAprob);
        printf("Semestre: %d\n", actual->alumno.SemestreEquiv);
        printf("-----------------\n");
        actual = actual->siguiente_Nodo;
    }
}
void imprimirAlumno(AlumnoPtr alumno) {//Imprimir solo un alumno
    printf("\nAlumno individual:\n");
    printf("Nombre: %s\n", alumno->NombreCompleto);
    printf("Creditos: %d\n", alumno->CreditosAprob);
    printf("Semestre: %d\n", alumno->SemestreEquiv);
    printf("-----------------\n");
}
void liberarMemoria(NodoPtr lista) {
    NodoPtr actual = lista;
    while (actual != NULL) {
        NodoPtr siguiente = actual->siguiente_Nodo;
        printf("Memoria liberada exitosamente en: %p\n", actual);
        free(actual->alumno.NombreCompleto);//Se libera memoria dinamica solo del nombre
        free(actual); //Los primitivos tipo int se liberan junto al Nodo
        actual = siguiente;
    }
}