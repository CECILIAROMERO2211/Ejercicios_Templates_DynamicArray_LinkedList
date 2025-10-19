// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#pragma once                 // evita que el archivo se incluya más de una vez al compilar
#include <iostream>          // biblioteca estándar para usar cout y endl
using namespace std;         // evita escribir std:: antes de cout o string

// clase plantilla (template) para que la lista pueda usar cualquier tipo de dato (int, string, etc.)
template <typename T>
class LinkedList
{
public:                      // seccion pública: funciones accesibles desde fuera de la clase

    // constructor: inicializa la lista vacía
    LinkedList()
    {
        count = 0;           // al inicio la lista no tiene elementos
        first = nullptr;     // el primer nodo apunta a nada (lista vacía)
    }

    // agrega un elemento al final de la lista (alias de Append)
    void PushBack(const T value)
    {
        Append(value);       // simplemente llama a la función Append
    }

    // agrega un elemento al final de la lista
    void Append(const T value)
    {
        if (first == nullptr)            // si la lista está vacía
        {
            first = new Node(value);     // crea un nuevo nodo y lo asigna como primero
            count++;                     // aumenta el contador de elementos
            return;                      // termina la función
        }

        Node* nodoActual = first;        // comienza desde el primer nodo
        while (nodoActual->next != nullptr) // recorre hasta llegar al último nodo
            nodoActual = nodoActual->next;

        Node* nuevoNodo = new Node(value); // crea un nuevo nodo con el valor dado
        nodoActual->next = nuevoNodo;      // enlaza el nuevo nodo al final
        count++;                           // incrementa la cantidad de elementos
    }

    // inserta un nodo nuevo después de un valor específico
    bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
    {
        Node* nodoActual = first;          // inicia desde el primer nodo
        while (nodoActual != nullptr)      // recorre la lista
        {
            if (nodoActual->data == valorAEncontrar) // si encuentra el valor buscado
            {
                Node* newNode = new Node(valorAInsertar); // crea un nuevo nodo con el valor a insertar
                newNode->next = nodoActual->next;         // conecta el nuevo nodo al siguiente del actual
                nodoActual->next = newNode;               // conecta el nodo actual con el nuevo
                count++;                                  // aumenta el contador
                return true;                              // devuelve true porque se insertó con éxito
            }
            nodoActual = nodoActual->next;                // pasa al siguiente nodo
        }
        cout << "Advertencia: no existe el valor " << valorAEncontrar << endl; // si no lo encuentra, avisa
        return false;                                     // devuelve false si no se insertó nada
    }

    // elimina un nodo que tenga un valor específico
    bool BorrarNodoPorValor(const T valorDelNodoABorrar)
    {
        if (count == 0)                                   // si la lista está vacía
        {
            cout << "Advertencia: lista vacía." << endl;
            return false;                                 // no hay nada que borrar
        }

        Node* nodoActual = first;                         // empieza desde el primer nodo
        if (nodoActual->data == valorDelNodoABorrar)      // si el primer nodo es el que se va a borrar
        {
            first = nodoActual->next;                     // el segundo nodo pasa a ser el primero
            delete nodoActual;                            // se libera el nodo eliminado
            count--;                                      // se reduce el contador
            return true;                                  // operación exitosa
        }

        // si el nodo a borrar no es el primero
        while (nodoActual->next != nullptr)               // recorre toda la lista
        {
            if (nodoActual->next->data == valorDelNodoABorrar) // si el siguiente nodo tiene el valor a borrar
            {
                Node* nodoABorrar = nodoActual->next;          // guarda la dirección del nodo a borrar
                nodoActual->next = nodoActual->next->next;     // salta el nodo borrado
                delete nodoABorrar;                            // libera la memoria del nodo
                count--;                                       // disminuye el contador
                return true;                                   // regresa true porque se borró con éxito
            }
            nodoActual = nodoActual->next;                     // avanza al siguiente nodo
        }

        cout << "Advertencia: no existe el valor " << valorDelNodoABorrar << endl; // si no lo encuentra
        return false;                                         // no se borró nada
    }

    // devuelve el valor del primer nodo de la lista
    T Front()
    {
        if (first != nullptr)            // si la lista no está vacía
            return first->data;          // devuelve el dato del primer nodo
        cout << "Advertencia: Front lista vacía." << endl;
        return T{};                      // devuelve un valor vacío del tipo genérico
    }

    // devuelve el valor del último nodo
    T Back()
    {
        if (count == 0)                  // si la lista está vacía
        {
            cout << "Advertencia: Back lista vacía." << endl;
            return T{};                  // devuelve un valor vacío
        }

        Node* nodoActual = first;        // empieza desde el primer nodo
        while (nodoActual->next != nullptr) // recorre hasta el último nodo
            nodoActual = nodoActual->next;
        return nodoActual->data;         // devuelve el valor del último nodo
    }

    // obtiene un valor por su índice (posición)
    T GetByIndex(const size_t indice) const
    {
        if (indice >= count)             // si el índice es mayor al tamaño de la lista
        {
            cout << "Error: índice inválido." << endl;
            return T{};                  // devuelve un valor vacío
        }

        Node* nodoActual = first;        // comienza desde el primer nodo
        for (int i = 0; i < indice; i++) // avanza hasta el índice indicado
            nodoActual = nodoActual->next;
        return nodoActual->data;         // devuelve el dato del nodo en esa posición
    }

    // inserta un nuevo nodo al principio de la lista
    void PushFront(const T value)
    {
        Node* nuevoNodo = new Node(value); // crea un nuevo nodo con el valor dado

        if (first == nullptr)              // si la lista está vacía
            nuevoNodo->next = nullptr;     // su siguiente apunta a nada
        else
            nuevoNodo->next = first;       // si no, lo conecta al nodo que antes era primero

        first = nuevoNodo;                 // el nuevo nodo se vuelve el primer nodo
        count++;                           // aumenta el número de elementos
    }

    // elimina el nodo que está al principio de la lista
    void PopFront()
    {
        if (first == nullptr)              // si la lista está vacía
        {
            cout << "Advertencia: PopFront lista vacía." << endl;
            return;                        // no hay nada que borrar
        }

        Node* nodoABorrar = first;         // guarda el nodo que se va a eliminar
        first = first->next;               // el segundo nodo pasa a ser el primero
        delete nodoABorrar;                // libera la memoria del nodo eliminado
        count--;                           // disminuye el contador de elementos
    }

    // imprime todos los elementos de la lista en consola
    void Print()
    {
        cout << "Imprimiendo lista: ";     // texto informativo
        Node* actual = first;              // comienza desde el primer nodo
        while (actual != nullptr)          // recorre la lista completa
        {
            cout << actual->data << " ";   // imprime el valor del nodo actual
            actual = actual->next;         // avanza al siguiente nodo
        }
        cout << endl;                      // salto de línea al final
    }

    // libera toda la memoria de los nodos (elimina toda la lista)
    void LiberarMemoria()
    {
        Node* actual = first;              // empieza desde el primer nodo
        while (actual != nullptr)          // mientras existan nodos
        {
            Node* temp = actual;           // guarda el nodo actual
            actual = actual->next;         // avanza al siguiente nodo
            delete temp;                   // libera el nodo guardado
        }
        first = nullptr;                   // el puntero al primer nodo se vacía
        count = 0;                         // contador vuelve a cero
        cout << "Memoria liberada correctamente." << endl; // mensaje de confirmación
    }

private:                                   // sección privada, no accesible desde fuera
    // clase interna que representa cada nodo individual de la lista
    class Node
    {
    public:
        Node(T _data)                      // constructor del nodo
        {
            data = _data;                  // guarda el valor del nodo
            next = nullptr;                // apunta a nada inicialmente
        }
        T data;                            // almacena el dato dentro del nodo
        Node* next;                        // puntero al siguiente nodo
    };

    Node* first;                           // puntero que apunta al primer nodo de la lista
    int count;                             // cantidad total de nodos en la lista
};

// declaración de la función de demostración para probar la lista
void DemostracionLinkedList();
