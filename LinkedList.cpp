// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "LinkedList.h"
#include <iostream>
using namespace std;

void DemostracionLinkedList()
{
    LinkedList<string> myLinkedList;
    myLinkedList.PushFront("Inicio");
    myLinkedList.PushFront("Primero");
    myLinkedList.Print();
    myLinkedList.PopFront();
    myLinkedList.Print();
    myLinkedList.Append("Juan");
    myLinkedList.Append("Pedro");
    myLinkedList.Append("Luis");
    myLinkedList.Append("Maria");
    myLinkedList.InsertAfterValue("Juan", "Pepe");
    cout << myLinkedList.Front() << " es el nodo hasta el frente de la lista" << endl;
    cout << myLinkedList.Back() << " es el nodo hasta el final de la lista" << endl;
    myLinkedList.BorrarNodoPorValor("Juan");
    myLinkedList.BorrarNodoPorValor("Luis");
    myLinkedList.BorrarNodoPorValor("Maria");
    myLinkedList.BorrarNodoPorValor("Pepe");
    myLinkedList.BorrarNodoPorValor("Pedro");
    myLinkedList.Front();
    myLinkedList.Back();
    myLinkedList.LiberarMemoria();
}
