// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "LinkedList.h"   // se incluye el encabezado donde está la plantilla de la lista enlazada
#include <iostream>       // permite usar cout y endl para imprimir en consola
using namespace std;      // evita escribir std:: en cada instrucción

// función que demuestra cómo funcionan las operaciones de la lista enlazada
void DemostracionLinkedList()
{
    LinkedList<string> myLinkedList;   // se crea una lista enlazada de tipo string

    myLinkedList.PushFront("Inicio");  // inserta "Inicio" al principio de la lista
    myLinkedList.PushFront("Primero"); // inserta "Primero" al inicio (ahora será el nuevo frente)

    myLinkedList.Print();              // imprime la lista actual: debería mostrar "Primero Inicio"

    myLinkedList.PopFront();           // elimina el primer nodo ("Primero")
    myLinkedList.Print();              // imprime de nuevo para ver la lista actual

    myLinkedList.Append("Juan");       // agrega "Juan" al final de la lista
    myLinkedList.Append("Pedro");      // agrega "Pedro" al final
    myLinkedList.Append("Luis");       // agrega "Luis" al final
    myLinkedList.Append("Maria");      // agrega "Maria" al final

    myLinkedList.InsertAfterValue("Juan", "Pepe"); // inserta "Pepe" después de "Juan"

    // muestra cuál es el primer elemento de la lista
    cout << myLinkedList.Front() << " es el nodo hasta el frente de la lista" << endl;

    // muestra cuál es el último elemento de la lista
    cout << myLinkedList.Back() << " es el nodo hasta el final de la lista" << endl;

    // elimina los nodos con los valores indicados uno por uno
    myLinkedList.BorrarNodoPorValor("Juan");   // borra el nodo con valor "Juan"
    myLinkedList.BorrarNodoPorValor("Luis");   // borra "Luis"
    myLinkedList.BorrarNodoPorValor("Maria");  // borra "Maria"
    myLinkedList.BorrarNodoPorValor("Pepe");   // borra "Pepe"
    myLinkedList.BorrarNodoPorValor("Pedro");  // borra "Pedro"

    myLinkedList.Front();                      // intenta acceder al primer nodo 
    myLinkedList.Back();                       // intenta acceder al último nodo

    myLinkedList.LiberarMemoria();             // libera la memoria de los nodos restantes (si hubiera)
}
