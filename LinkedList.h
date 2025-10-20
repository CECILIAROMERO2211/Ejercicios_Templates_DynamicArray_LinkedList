// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#pragma once // Evita que este archivo se incluya más de una vez durante la compilación
#include <iostream> // Permite usar cout, endl, etc.
using namespace std; // Facilita el uso de elementos de la biblioteca estándar

// Declaramos una clase genérica (template) que puede almacenar cualquier tipo de dato
template <typename T>
class LinkedList
{
public: // Sección pública: métodos accesibles desde fuera de la clase

    // Constructor: inicializa la lista vacía
    LinkedList()
    {
        count = 0; // Número de nodos empieza en 0
        first = nullptr; // No hay nodos todavía, por lo tanto el puntero apunta a null
    }

    // Destructor automático: se ejecuta cuando el objeto deja de existir
    // Sirve para liberar memoria sin necesidad de llamar manualmente a LiberarMemoria()
    ~LinkedList()
    {
        LiberarMemoria(); // Llama a la función que libera todos los nodos
    }

    // Inserta un elemento al final de la lista (igual que Append)
    void PushBack(const T value)
    {
        Append(value); // Llama internamente a Append para agregar al final
    }

    // Agrega un nuevo nodo al final de la lista
    void Append(const T value)
    {
        if (first == nullptr) // Si la lista está vacía
        {
            first = new Node(value); // Crea el primer nodo con el valor dado
            count++; // Aumenta el contador de elementos
            return; // Termina la función
        }

        // Si ya hay elementos, recorre hasta el último nodo
        Node* nodoActual = first;
        while (nodoActual->next != nullptr)
            nodoActual = nodoActual->next;

        // Crea un nuevo nodo y lo enlaza al final
        Node* nuevoNodo = new Node(value);
        nodoActual->next = nuevoNodo;
        count++; // Aumenta el total de nodos
    }

    // Inserta un nodo después de otro que tenga un valor específico
    bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
    {
        Node* nodoActual = first; // Empieza desde el primer nodo
        while (nodoActual != nullptr) // Recorre toda la lista
        {
            if (nodoActual->data == valorAEncontrar) // Si el nodo actual tiene el valor buscado
            {
                Node* newNode = new Node(valorAInsertar); // Crea un nuevo nodo
                newNode->next = nodoActual->next; // El nuevo nodo apunta al siguiente del actual
                nodoActual->next = newNode; // Y el nodo actual apunta al nuevo
                count++; // Aumenta el contador
                return true; // Inserción exitosa
            }
            nodoActual = nodoActual->next; // Avanza al siguiente nodo
        }

        // Si no se encontró el valor, muestra advertencia
        cout << "Advertencia: no existe el valor " << valorAEncontrar << endl;
        return false; // Inserción fallida
    }

    // Elimina un nodo que contenga el valor indicado
    bool BorrarNodoPorValor(const T valorDelNodoABorrar)
    {
        if (count == 0) // Si la lista está vacía
        {
            cout << "Advertencia: lista vacía." << endl;
            return false; // No se puede borrar nada
        }

        Node* nodoActual = first; // Empezamos desde el inicio

        // Si el primer nodo tiene el valor buscado
        if (nodoActual->data == valorDelNodoABorrar)
        {
            first = nodoActual->next; // El primer nodo ahora será el siguiente
            delete nodoActual; // Liberamos la memoria del nodo borrado
            count--; // Reducimos el contador
            return true; // Éxito
        }

        // Recorre los nodos buscando el valor
        while (nodoActual->next != nullptr)
        {
            if (nodoActual->next->data == valorDelNodoABorrar) // Si el siguiente nodo tiene el valor
            {
                Node* nodoABorrar = nodoActual->next; // Guardamos referencia del nodo a eliminar
                nodoActual->next = nodoActual->next->next; // Saltamos ese nodo en la lista
                delete nodoABorrar; // Liberamos la memoria del nodo eliminado
                count--; // Reducimos el contador
                return true; // Nodo eliminado correctamente
            }
            nodoActual = nodoActual->next; // Avanza al siguiente nodo
        }

        // Si no se encontró el valor, mostramos advertencia
        cout << "Advertencia: no existe el valor " << valorDelNodoABorrar << endl;
        return false; // No se borró nada
    }

    // Devuelve el valor que está al frente (primer nodo)
    T Front()
    {
        if (first != nullptr) // Si hay al menos un nodo
            return first->data; // Devuelve el valor del primer nodo

        cout << "Advertencia: Front lista vacía." << endl;
        return T{}; // Devuelve valor vacío (según el tipo)
    }

    // Devuelve el valor del último nodo de la lista
    T Back()
    {
        if (count == 0) // Si la lista está vacía
        {
            cout << "Advertencia: Back lista vacía." << endl;
            return T{}; // Devuelve valor vacío
        }

        Node* nodoActual = first; // Comienza en el primer nodo
        while (nodoActual->next != nullptr) // Avanza hasta el último
            nodoActual = nodoActual->next;

        return nodoActual->data; // Devuelve el valor del último nodo
    }

    // Inserta un elemento al principio de la lista
    void PushFront(const T value)
    {
        Node* nuevoNodo = new Node(value); // Crea un nuevo nodo con el valor dado
        nuevoNodo->next = first; // Hace que el nuevo nodo apunte al primero actual
        first = nuevoNodo; // El nuevo nodo se convierte en el primero
        count++; // Aumenta el total de elementos
    }

    // Elimina el primer nodo de la lista
    void PopFront()
    {
        if (first == nullptr) // Si la lista está vacía
        {
            cout << "Advertencia: PopFront lista vacía." << endl;
            return; // No hay nada que eliminar
        }

        Node* nodoABorrar = first; // Guardamos el primer nodo
        first = first->next; // Avanzamos el inicio al siguiente nodo
        delete nodoABorrar; // Liberamos la memoria del nodo borrado
        count--; // Disminuye el total de nodos
    }

    // Imprime todos los valores de la lista
    void Print()
    {
        cout << "Imprimiendo lista: ";
        Node* actual = first; // Comienza desde el primer nodo
        while (actual != nullptr) // Mientras haya nodos
        {
            cout << actual->data << " "; // Imprime el valor actual
            actual = actual->next; // Avanza al siguiente
        }
        cout << endl; // Salto de línea al final
    }

    // Libera toda la memoria usada por la lista
    void LiberarMemoria()
    {
        Node* actual = first; // Comienza desde el primer nodo
        while (actual != nullptr) // Mientras haya nodos
        {
            Node* temp = actual; // Guarda el nodo actual en una variable temporal
            actual = actual->next; // Avanza al siguiente nodo
            delete temp; // Libera el nodo actual
        }
        first = nullptr; // Vuelve el puntero inicial a vacío
        count = 0; // Reinicia el contador
    }

private: // Sección privada: solo accesible desde dentro de la clase

    // Clase interna Node: representa cada elemento de la lista
    class Node
    {
    public:
        Node(T _data) // Constructor del nodo
        {
            data = _data; // Guarda el dato dentro del nodo
            next = nullptr; // Inicialmente no apunta a nadie
        }

        T data; // Valor almacenado dentro del nodo
        Node* next; // Puntero al siguiente nodo
    };

    Node* first; // Apunta al primer nodo de la lista
    int count; // Lleva el conteo de cuántos nodos hay
};

// Declaración de la función externa para demostrar la lista enlazada
void DemostracionLinkedList();
