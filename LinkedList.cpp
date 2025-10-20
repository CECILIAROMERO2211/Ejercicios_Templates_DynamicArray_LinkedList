// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "LinkedList.h" // Incluye la definición de la clase LinkedList
#include <iostream>     // Permite usar cout para imprimir mensajes
using namespace std;    // Simplifica el uso del espacio de nombres estándar

// Función que demuestra el uso de todas las operaciones de la lista enlazada
void DemostracionLinkedList()
{
    LinkedList<string> myLinkedList; // Crea una lista enlazada que almacenará cadenas (strings)

    // Prueba de inserción al frente de la lista
    myLinkedList.PushFront("Inicio");  // Inserta un nodo con el valor "Inicio" al principio
    myLinkedList.PushFront("Primero"); // Inserta otro nodo al frente, ahora este es el nuevo primero
    myLinkedList.Print();              // Imprime la lista actual (Primero → Inicio)

    // Prueba de eliminación del primer nodo
    myLinkedList.PopFront();           // Elimina el nodo del frente (Primero)
    myLinkedList.Print();              // Imprime la lista después de eliminar el primero (Inicio)

    // Pruebas de inserción al final de la lista
    myLinkedList.Append("Juan");       // Inserta "Juan" al final de la lista
    myLinkedList.Append("Pedro");      // Inserta "Pedro" al final
    myLinkedList.Append("Luis");       // Inserta "Luis" al final
    myLinkedList.Append("Maria");      // Inserta "Maria" al final
    // En este punto, la lista contiene: Inicio → Juan → Pedro → Luis → Maria

    // Inserta un nuevo valor después de uno existente
    myLinkedList.InsertAfterValue("Juan", "Pepe"); // Inserta "Pepe" después de "Juan"

    // Prueba de funciones Front() y Back()
    cout << myLinkedList.Front() << " es el nodo hasta el frente de la lista" << endl; // Muestra el primer nodo
    cout << myLinkedList.Back() << " es el nodo hasta el final de la lista" << endl;   // Muestra el último nodo

    // Prueba de eliminación de varios nodos por su valor
    myLinkedList.BorrarNodoPorValor("Juan");  // Elimina el nodo que contiene "Juan"
    myLinkedList.BorrarNodoPorValor("Luis");  // Elimina "Luis"
    myLinkedList.BorrarNodoPorValor("Maria"); // Elimina "Maria"
    myLinkedList.BorrarNodoPorValor("Pepe");  // Elimina "Pepe"
    myLinkedList.BorrarNodoPorValor("Pedro"); // Elimina "Pedro"
    // En este punto, la lista solo debería contener "Inicio"

    // Pruebas adicionales de los métodos Front() y Back() con lista reducida
    myLinkedList.Front(); // Devuelve el primer elemento actual (Inicio)
    myLinkedList.Back();  // Devuelve el último elemento actual (Inicio)

    // No se llama a LiberarMemoria() manualmente porque el destructor la libera automáticamente
    // cuando el objeto myLinkedList termina su tiempo de vida (al salir de la función)
}
