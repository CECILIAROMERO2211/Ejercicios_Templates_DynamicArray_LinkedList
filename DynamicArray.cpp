// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "DynamicArray.h" // Incluye el archivo de encabezado con la definición de la clase
#include <iostream>       // Permite usar cout, endl, etc.
using namespace std;      // Evita tener que escribir std:: en cada línea

// Constructor: inicializa el arreglo con una capacidad dada o vacía
DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity; // Guarda el valor de capacidad
    count = 0;                 // Inicializa el número de elementos en cero

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    copyCounter = 0;           // Inicializa el contador de copias si está activado
#endif

    // Si la capacidad es mayor que cero, reserva memoria dinámica
    if (capacity > 0)
        elements = new int[capacity];
    else
        elements = nullptr;    // Si no, deja el puntero vacío
}

// Destructor: libera la memoria cuando el objeto deja de existir
DynamicArray::~DynamicArray()
{
    if (elements != nullptr)   // Verifica que haya memoria reservada
    {
        delete[] elements;     // Libera el bloque de memoria
        elements = nullptr;    // Evita que el puntero quede colgando
    }
}

// Agrega un nuevo elemento al final del arreglo
void DynamicArray::Append(const int value)
{
    // Si el número de elementos alcanza la capacidad, hay que redimensionar
    if (count >= capacity)
    {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2; // Duplica la capacidad o inicia con 1

        // Si la nueva capacidad sobrepasa el máximo permitido, se detiene
        if (newCapacity > maxCapacity)
        {
            cout << "advertencia: se alcanzó la capacidad máxima" << endl;
            return;
        }

        // Crea un nuevo arreglo temporal con la nueva capacidad
        int* newArray = new int[newCapacity];

        // Copia los elementos del arreglo viejo al nuevo
        for (int i = 0; i < count; i++)
        {
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++;     // Aumenta el contador de copias por cada elemento copiado
#endif
            newArray[i] = elements[i]; // Copia cada elemento
        }

        delete[] elements;     // Libera la memoria anterior
        elements = newArray;   // Cambia el puntero al nuevo arreglo
        capacity = newCapacity; // Actualiza la capacidad total
    }

    // Inserta el nuevo valor en la siguiente posición disponible
    elements[count] = value;
    count++; // Aumenta el número de elementos almacenados
}

// Inserta un nuevo valor después de un valor específico
bool DynamicArray::InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar)
{
    // Recorre el arreglo para encontrar el valor indicado
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == valorAEncontrar) // Si encuentra el valor buscado
        {
            if (count >= capacity) // Si el arreglo está lleno
            {
                Append(valorAInsertar); // Usa Append para agregar al final
                return true;
            }

            // Recorre los elementos hacia la derecha para hacer espacio
            for (int j = count; j > i + 1; j--)
                elements[j] = elements[j - 1];

            // Inserta el nuevo valor justo después del encontrado
            elements[i + 1] = valorAInsertar;
            count++; // Aumenta el número total de elementos
            return true;
        }
    }

    // Si el valor no se encontró, muestra advertencia
    cout << "advertencia: no existe el valor " << valorAEncontrar << endl;
    return false; // Devuelve falso si no se hizo la inserción
}

// Devuelve el elemento que se encuentra en un índice específico
int DynamicArray::ObtenerElemento(const size_t indice) const
{
    // Si el índice es inválido, muestra error
    if (indice >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        return -1; // Retorna -1 como valor de error
    }
    return elements[indice]; // Devuelve el elemento correspondiente
}

// Cambia el valor en una posición específica del arreglo
void DynamicArray::AsignarElemento(const size_t indice, const int valor)
{
    // Verifica que el índice sea válido
    if (indice >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        return; // Termina la función sin hacer nada
    }

    elements[indice] = valor; // Asigna el nuevo valor al índice indicado
}

// Busca un valor dentro del arreglo y devuelve su posición
int DynamicArray::BuscarElemento(const int valor) const
{
    // Recorre todos los elementos para buscar coincidencia
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == valor) // Si encuentra el valor
            return i;             // Devuelve su posición
    }
    return -1; // Si no lo encuentra, devuelve -1
}

// Elimina el último elemento del arreglo
int DynamicArray::QuitarUltimoElemento()
{
    if (count == 0) // Si el arreglo está vacío
    {
        cout << "advertencia: arreglo vacío" << endl;
        return -1; // No hay nada que eliminar
    }

    count--; // Disminuye el conteo de elementos
    return elements[count]; // Devuelve el valor eliminado
}

// Devuelve el número actual de elementos en el arreglo
int DynamicArray::GetCount() const
{
    return count; // Retorna el valor de la variable count
}

// Imprime todos los elementos almacenados
void DynamicArray::Print() const
{
    cout << "elementos del arreglo: "; // Texto previo
    for (int i = 0; i < count; i++)    // Recorre cada elemento
        cout << elements[i] << " ";    // Imprime cada valor con un espacio
    cout << endl;                      // Salto de línea al final
}

// Sobrecarga del operador [] para acceder a los elementos directamente
int& DynamicArray::operator[](int index)
{
    // Verifica que el índice sea válido
    if (index < 0 || index >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1); // Termina el programa si el índice es inválido
    }
    return elements[index]; // Devuelve referencia al elemento
}

// Versión constante del operador [], para arreglos de solo lectura
const int& DynamicArray::operator[](int index) const
{
    if (index < 0 || index >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1); // Termina el programa si hay error
    }
    return elements[index]; // Devuelve referencia constante
}

// Agrega un valor al final del arreglo (igual que Append)
void DynamicArray::push_back(int value)
{
    Append(value); // Llama internamente a Append
}

// Elimina el último elemento del arreglo sin devolverlo
void DynamicArray::pop_back()
{
    if (count > 0) // Si hay elementos
        count--;   // Reduce el contador en uno
    else
        cout << "advertencia: arreglo vacío" << endl; // Si no hay nada que borrar
}

// Ajusta la capacidad del arreglo al número exacto de elementos
void DynamicArray::shrink_to_fit()
{
    // Esta función se deja vacía como parte de la práctica
}

// Función de demostración: muestra cómo usar DynamicArray
void DemostracionDynamicArray()
{
    DynamicArray myArray; // Crea un objeto DynamicArray vacío

    myArray.Append(10); // Agrega el número 10
    myArray.Append(20); // Agrega el número 20
    myArray.Append(30); // Agrega el número 30

    cout << "elementos iniciales: ";
    myArray.Print(); // Imprime los valores actuales

    myArray.push_back(40); // Agrega un nuevo valor al final
    myArray.Print();       // Muestra el arreglo actualizado

    myArray.pop_back(); // Elimina el último elemento
    myArray.Print();    // Vuelve a mostrar el arreglo

    // Accede al primer elemento con el operador []
    cout << "primer elemento con operador []: " << myArray[0] << endl;

    myArray.shrink_to_fit(); // Llama a la función vacía (solo demostración)
}
