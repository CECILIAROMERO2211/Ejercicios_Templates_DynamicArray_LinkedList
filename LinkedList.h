// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
        count = 0;
        first = nullptr;
    }

    void PushBack(const T value)
    {
        Append(value);
    }

    void Append(const T value)
    {
        if (first == nullptr)
        {
            first = new Node(value);
            count++;
            return;
        }

        Node* nodoActual = first;
        while (nodoActual->next != nullptr)
            nodoActual = nodoActual->next;

        Node* nuevoNodo = new Node(value);
        nodoActual->next = nuevoNodo;
        count++;
    }

    bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
    {
        Node* nodoActual = first;
        while (nodoActual != nullptr)
        {
            if (nodoActual->data == valorAEncontrar)
            {
                Node* newNode = new Node(valorAInsertar);
                newNode->next = nodoActual->next;
                nodoActual->next = newNode;
                count++;
                return true;
            }
            nodoActual = nodoActual->next;
        }
        cout << "Advertencia: no existe el valor " << valorAEncontrar << endl;
        return false;
    }

    bool BorrarNodoPorValor(const T valorDelNodoABorrar)
    {
        if (count == 0)
        {
            cout << "Advertencia: lista vacía." << endl;
            return false;
        }

        Node* nodoActual = first;
        if (nodoActual->data == valorDelNodoABorrar)
        {
            first = nodoActual->next;
            delete nodoActual;
            count--;
            return true;
        }

        while (nodoActual->next != nullptr)
        {
            if (nodoActual->next->data == valorDelNodoABorrar)
            {
                Node* nodoABorrar = nodoActual->next;
                nodoActual->next = nodoActual->next->next;
                delete nodoABorrar;
                count--;
                return true;
            }
            nodoActual = nodoActual->next;
        }

        cout << "Advertencia: no existe el valor " << valorDelNodoABorrar << endl;
        return false;
    }

    T Front()
    {
        if (first != nullptr)
            return first->data;
        cout << "Advertencia: Front lista vacía." << endl;
        return T{};
    }

    T Back()
    {
        if (count == 0)
        {
            cout << "Advertencia: Back lista vacía." << endl;
            return T{};
        }

        Node* nodoActual = first;
        while (nodoActual->next != nullptr)
            nodoActual = nodoActual->next;
        return nodoActual->data;
    }

    T GetByIndex(const size_t indice) const
    {
        if (indice >= count)
        {
            cout << "Error: índice inválido." << endl;
            return T{};
        }

        Node* nodoActual = first;
        for (int i = 0; i < indice; i++)
            nodoActual = nodoActual->next;
        return nodoActual->data;
    }

    void PushFront(const T value)
    {
        Node* nuevoNodo = new Node(value);

        if (first == nullptr)
            nuevoNodo->next = nullptr;
        else
            nuevoNodo->next = first;

        first = nuevoNodo;
        count++;
    }

    void PopFront()
    {
        if (first == nullptr)
        {
            cout << "Advertencia: PopFront lista vacía." << endl;
            return;
        }

        Node* nodoABorrar = first;
        first = first->next;
        delete nodoABorrar;
        count--;
    }

    void Print()
    {
        cout << "Imprimiendo lista: ";
        Node* actual = first;
        while (actual != nullptr)
        {
            cout << actual->data << " ";
            actual = actual->next;
        }
        cout << endl;
    }

    void LiberarMemoria()
    {
        Node* actual = first;
        while (actual != nullptr)
        {
            Node* temp = actual;
            actual = actual->next;
            delete temp;
        }
        first = nullptr;
        count = 0;
        cout << "Memoria liberada correctamente." << endl;
    }

private:
    class Node
    {
    public:
        Node(T _data)
        {
            data = _data;
            next = nullptr;
        }
        T data;
        Node* next;
    };

    Node* first;
    int count;
};

void DemostracionLinkedList();
