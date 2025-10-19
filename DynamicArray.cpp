// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity;
    count = 0;

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    copyCounter = 0;
#endif

    if (capacity > 0)
        elements = new int[capacity];
    else
        elements = nullptr;
}

DynamicArray::~DynamicArray()
{
    if (elements != nullptr)
    {
        delete[] elements;
        elements = nullptr;
    }
}

void DynamicArray::Append(const int value)
{
    if (count >= capacity)
    {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        if (newCapacity > maxCapacity)
        {
            cout << "advertencia: se alcanzó la capacidad máxima" << endl;
            return;
        }

        int* newArray = new int[newCapacity];
        for (int i = 0; i < count; i++)
        {
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;
#endif
            newArray[i] = elements[i];
        }
        delete[] elements;
        elements = newArray;
        capacity = newCapacity;
    }
    elements[count] = value;
    count++;
}

bool DynamicArray::InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar)
{
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == valorAEncontrar)
        {
            if (count >= capacity)
            {
                Append(valorAInsertar);
                return true;
            }
            for (int j = count; j > i + 1; j--)
                elements[j] = elements[j - 1];
            elements[i + 1] = valorAInsertar;
            count++;
            return true;
        }
    }
    cout << "advertencia: no existe el valor " << valorAEncontrar << endl;
    return false;
}

int DynamicArray::ObtenerElemento(const size_t indice) const
{
    if (indice >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        return -1;
    }
    return elements[indice];
}

void DynamicArray::AsignarElemento(const size_t indice, const int valor)
{
    if (indice >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        return;
    }
    elements[indice] = valor;
}

int DynamicArray::BuscarElemento(const int valor) const
{
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == valor)
            return i;
    }
    return -1;
}

int DynamicArray::QuitarUltimoElemento()
{
    if (count == 0)
    {
        cout << "advertencia: arreglo vacío" << endl;
        return -1;
    }
    count--;
    return elements[count];
}

int DynamicArray::GetCount() const
{
    return count;
}

void DynamicArray::Print() const
{
    cout << "elementos del arreglo: ";
    for (int i = 0; i < count; i++)
        cout << elements[i] << " ";
    cout << endl;
}

int& DynamicArray::operator[](int index)
{
    if (index < 0 || index >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1);
    }
    return elements[index];
}

const int& DynamicArray::operator[](int index) const
{
    if (index < 0 || index >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1);
    }
    return elements[index];
}

void DynamicArray::push_back(int value)
{
    Append(value);
}

void DynamicArray::pop_back()
{
    if (count > 0)
        count--;
    else
        cout << "advertencia: arreglo vacío" << endl;
}

void DynamicArray::shrink_to_fit()
{
}

void DemostracionDynamicArray()
{
    DynamicArray myArray;
    myArray.Append(10);
    myArray.Append(20);
    myArray.Append(30);

    cout << "elementos iniciales: ";
    myArray.Print();

    myArray.push_back(40);
    myArray.Print();

    myArray.pop_back();
    myArray.Print();

    cout << "primer elemento con operador []: " << myArray[0] << endl;
    myArray.shrink_to_fit();
}

// Fuentes de información:
// Cplusplus.com. (n.d.). exit – C++ Reference. Recuperado de https://cplusplus.com/reference/cstdlib/exit/
// Deitel, P. J., & Deitel, H. M. (2016). C++ Cómo programar (10ª edición). Pearson Educación.
