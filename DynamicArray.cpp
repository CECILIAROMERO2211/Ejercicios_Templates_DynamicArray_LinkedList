// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "DynamicArray.h" // se incluye el encabezado con la clase DynamicArray
#include <iostream>       // se usa para imprimir mensajes en consola
using namespace std;

// constructor: inicializa el arreglo con la capacidad dada
DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity; // se guarda la capacidad indicada al crear el objeto
    count = 0;                 // inicialmente el arreglo está vacío

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    copyCounter = 0;           // si la opción está activa, inicializa el contador de copias
#endif

    if (capacity > 0)          // si la capacidad es mayor que 0
        elements = new int[capacity]; // se reserva memoria para esa cantidad de enteros
    else
        elements = nullptr;    // si no, se deja el puntero vacío
}

// destructor: libera la memoria ocupada por el arreglo dinámico
DynamicArray::~DynamicArray()
{
    if (elements != nullptr)   // verifica que el puntero no esté vacío
    {
        delete[] elements;     // libera la memoria dinámica asignada
        elements = nullptr;    // evita punteros colgantes
    }
}

// función que agrega un nuevo valor al final del arreglo
void DynamicArray::Append(const int value)
{
    if (count >= capacity)     // si ya no hay espacio suficiente
    {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2; // duplica la capacidad o la inicia en 1
        if (newCapacity > maxCapacity) // evita que la capacidad supere el máximo permitido
        {
            cout << "advertencia: se alcanzó la capacidad máxima" << endl;
            return;            // termina la función sin agregar
        }

        int* newArray = new int[newCapacity]; // crea un nuevo arreglo temporal con la nueva capacidad

        // copia todos los elementos del arreglo viejo al nuevo
        for (int i = 0; i < count; i++)
        {
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;     // cuenta cada copia si el contador está activado
#endif
            newArray[i] = elements[i]; // copia el valor del elemento actual
        }

        delete[] elements;     // libera el arreglo anterior
        elements = newArray;   // cambia el puntero al nuevo arreglo
        capacity = newCapacity; // actualiza la nueva capacidad
    }

    elements[count] = value;   // agrega el nuevo valor al final del arreglo
    count++;                   // aumenta el número de elementos almacenados
}

// función que inserta un valor después de otro específico
bool DynamicArray::InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar)
{
    for (int i = 0; i < count; i++) // recorre todos los elementos del arreglo
