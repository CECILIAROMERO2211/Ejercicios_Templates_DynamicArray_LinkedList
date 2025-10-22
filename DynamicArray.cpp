// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include "DynamicArray.h" // Incluye el archivo de encabezado con la definición de la clase DynamicArray
#include <iostream>       // Permite usar cout, endl, etc.
using namespace std;      // Simplifica el uso del espacio de nombres estándar

// Constructor: inicializa el arreglo con una capacidad dada o vacía
DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity; // Guarda el valor de capacidad
    count = 0;                 // Inicialmente el arreglo está vacío

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    copyCounter = 0;           // Si la opción está activa, inicializa el contador de copias
#endif

    if (capacity > 0)          // Si la capacidad es mayor que 0
        elements = new int[capacity]; // Se reserva memoria dinámica
    else
        elements = nullptr;    // Si no, el puntero se deja vacío
}

// Destructor: libera la memoria ocupada por el arreglo dinámico
DynamicArray::~DynamicArray()
{
    if (elements != nullptr)   // Si hay memoria reservada
    {
        delete[] elements;     // Libera el bloque de memoria
        elements = nullptr;    // Evita punteros colgantes
    }
}

// Agrega un nuevo valor al final del arreglo
void DynamicArray::Append(const int value)
{
    // Si no hay espacio suficiente, se redimensiona el arreglo
    if (count >= capacity)
    {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2; // Duplica o inicia en 1
        if (newCapacity > maxCapacity) // Evita sobrepasar el límite máximo
        {
            cout << "advertencia: se alcanzó la capacidad máxima" << endl;
            return;
        }

        // Se crea un nuevo arreglo con mayor capacidad
        int* newArray = new int[newCapacity];
        for (int i = 0; i < count; i++) // Copia todos los elementos anteriores
        {
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter++; // Aumenta el contador de copias
#endif
            newArray[i] = elements[i];
        }

        delete[] elements; // Libera el arreglo viejo
        elements = newArray; // Reemplaza con el nuevo
        capacity = newCapacity; // Actualiza la capacidad
    }

    elements[count] = value; // Agrega el nuevo elemento
    count++; // Aumenta el contador de elementos
}

// Inserta un valor después de otro existente
bool DynamicArray::InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar)
{
    for (int i = 0; i < count; i++) // Recorre el arreglo
    {
        if (elements[i] == valorAEncontrar) // Si encuentra el valor buscado
        {
            if (count >= capacity) // Si está lleno
            {
                Append(valorAInsertar); // Llama a Append para expandir y agregar
                return true;
            }

            // Desplaza los elementos hacia la derecha
            for (int j = count; j > i + 1; j--)
                elements[j] = elements[j - 1];

            elements[i + 1] = valorAInsertar; // Inserta el nuevo valor
            count++; // Aumenta el total
            return true;
        }
    }
    cout << "advertencia: no existe el valor " << valorAEncontrar << endl;
    return false; // Si no lo encuentra
}

// Devuelve el elemento en un índice específico
int DynamicArray::ObtenerElemento(const size_t indice) const
{
    if (indice >= count) // Si está fuera de rango
    {
        cout << "error: índice fuera de rango" << endl;
        return -1; // Retorna error
    }
    return elements[indice]; // Devuelve el elemento
}

// Asigna un nuevo valor a un índice
void DynamicArray::AsignarElemento(const size_t indice, const int valor)
{
    if (indice >= count) // Verifica que exista
    {
        cout << "error: índice fuera de rango" << endl;
        return;
    }
    elements[indice] = valor; // Cambia el valor
}

// Busca un valor dentro del arreglo
int DynamicArray::BuscarElemento(const int valor) const
{
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == valor)
            return i; // Devuelve la posición
    }
    return -1; // Si no se encuentra
}

// Elimina el último elemento y devuelve su valor
int DynamicArray::QuitarUltimoElemento()
{
    if (count == 0) // Si el arreglo está vacío
    {
        cout << "advertencia: arreglo vacío" << endl;
        return -1;
    }
    count--; // Reduce el contador
    return elements[count]; // Devuelve el elemento eliminado
}

// Devuelve cuántos elementos tiene actualmente
int DynamicArray::GetCount() const
{
    return count; // Retorna el número total de elementos
}

// Imprime todos los elementos del arreglo
void DynamicArray::Print() const
{
    cout << "elementos del arreglo: ";
    for (int i = 0; i < count; i++) // Recorre cada elemento
        cout << elements[i] << " "; // Lo imprime separado por espacios
    cout << endl;
}

// Sobrecarga del operador [] para acceder como un arreglo normal
int& DynamicArray::operator[](int index)
{
    if (index < 0 || index >= count) // Verifica límites válidos
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1); // Detiene el programa en caso de error
    }
    return elements[index]; // Devuelve referencia al valor
}

// Versión constante del operador []
const int& DynamicArray::operator[](int index) const
{
    if (index < 0 || index >= count)
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1);
    }
    return elements[index];
}

// Agrega un valor al final del arreglo (igual que Append)
void DynamicArray::push_back(int value)
{
    Append(value); // Reutiliza la función Append
}

// Elimina el último valor del arreglo
void DynamicArray::pop_back()
{
    if (count > 0) // Si hay elementos
        count--;   // Reduce el total
    else
        cout << "advertencia: arreglo vacío" << endl;
}

// Ajusta la capacidad al número exacto de elementos
void DynamicArray::shrink_to_fit()
{
    // Si la capacidad es mayor al número real de elementos, se ajusta
    if (capacity > count)
    {
        int* newArray = new int[count]; // Crea un arreglo exacto del tamaño actual
        for (int i = 0; i < count; i++)
            newArray[i] = elements[i]; // Copia los datos existentes

        delete[] elements; // Libera la memoria anterior
        elements = newArray; // Asigna el nuevo arreglo ajustado
        capacity = count; // Actualiza la capacidad

        cout << "shrink_to_fit(): capacidad ajustada al tamaño real (" << capacity << ")" << endl;
    }
    else
    {
        cout << "shrink_to_fit(): no se requiere ajuste" << endl;
    }
}

// Demostración del uso del DynamicArray
void DemostracionDynamicArray()
{
    DynamicArray myArray; // Crea un objeto de tipo DynamicArray

    myArray.Append(10); // Agrega valores de prueba
    myArray.Append(20);
    myArray.Append(30);

    cout << "elementos iniciales: ";
    myArray.Print(); // Muestra los elementos

    myArray.push_back(40); // Agrega un nuevo valor al final
    myArray.Print();

    myArray.pop_back(); // Elimina el último valor
    myArray.Print();

    cout << "primer elemento con operador []: " << myArray[0] << endl; // Muestra acceso con operador []
    myArray.shrink_to_fit(); // Ajusta la capacidad al tamaño real
}

// Fuentes consultadas:
// CodeBeauty. (2021, 17 de julio). Dynamic Arrays in C++ (how they work, resize, and manage memory). [Video]. YouTube. 
// https://www.youtube.com/watch?v=PocJ5jXv8No
// Contenido: Minuto 04:10 a 07:45. Explica cómo redimensionar arreglos dinámicos y gestionar memoria con new[] y delete[],
// lo cual fue aplicado en la función shrink_to_fit() para optimizar el uso de memoria dinámica.
//
// Geek’s Lesson. (2020, 8 de mayo). Use push_back and pop_back with vectors in C++. [Video]. YouTube. 
// https://www.youtube.com/watch?v=opAnlfre-Kw
// Contenido: Minuto 01:00 a 03:20. Muestra el funcionamiento de las funciones push_back() y pop_back() 
// en los vectores del STL, las cuales fueron replicadas manualmente dentro de esta clase.
