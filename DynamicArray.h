// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#pragma once // Evita que el archivo se incluya más de una vez al compilar
#include <iostream> // Permite usar cout, endl, etc.
using namespace std; // Simplifica el uso del espacio de nombres std

#define COUNT_DYNAMIC_ARRAY_COPIES 1 // Activa el conteo de copias dentro del arreglo dinámico

// Se define la clase DynamicArray
class DynamicArray
{
public: // Sección pública: accesible desde fuera de la clase
    static const int maxCapacity = 1024; // Capacidad máxima permitida para el arreglo

    DynamicArray(int capacity = 0); // Constructor que permite definir capacidad inicial
    ~DynamicArray(); // Destructor que libera memoria al destruir el objeto

    // Constructor de copia: crea un nuevo arreglo copiando otro existente
    DynamicArray(const DynamicArray& other)
    {
        count = other.count; // Copia el número de elementos
        capacity = other.capacity; // Copia la capacidad total

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
        copyCounter = other.copyCounter; // Copia también el contador de copias si está activo
#endif

        // Si hay capacidad, reserva memoria para el nuevo arreglo
        if (capacity > 0)
        {
            elements = new int[capacity]; // Crea espacio para todos los elementos
            for (int i = 0; i < count; i++) // Copia los elementos uno por uno
                elements[i] = other.elements[i];
        }
        else
            elements = nullptr; // Si no hay capacidad, deja el puntero vacío
    }

    // Operador de asignación: permite igualar un DynamicArray a otro (a = b)
    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other) // Evita la autoasignación
        {
            delete[] elements; // Libera la memoria existente para evitar fugas
            count = other.count; // Copia el número de elementos
            capacity = other.capacity; // Copia la capacidad

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
            copyCounter = other.copyCounter; // Copia el contador de copias
#endif

            // Reserva nueva memoria y copia los datos
            if (capacity > 0)
            {
                elements = new int[capacity]; // Crea nuevo arreglo con la capacidad copiada
                for (int i = 0; i < count; i++)
                    elements[i] = other.elements[i]; // Copia cada elemento
            }
            else
                elements = nullptr; // Si no hay capacidad, deja el puntero vacío
        }
        return *this; // Devuelve el propio objeto actualizado
    }

    void Append(const int value); // Agrega un nuevo valor al final del arreglo
    bool InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar); // Inserta un valor después de otro existente
    int ObtenerElemento(const size_t indice) const; // Devuelve un elemento en un índice específico
    void AsignarElemento(const size_t indice, const int valor); // Asigna un nuevo valor a una posición
    int BuscarElemento(const int valor) const; // Busca un valor y devuelve su índice
    int QuitarUltimoElemento(); // Elimina el último elemento y lo devuelve
    int GetCount() const; // Devuelve el número de elementos actuales
    void Print() const; // Imprime todos los elementos del arreglo
    int& operator[](int index); // Sobrecarga del operador [] (permite acceder a elementos)
    const int& operator[](int index) const; // Versión constante del operador []
    void push_back(int value); // Agrega un elemento al final (como en std::vector)
    void pop_back(); // Elimina el último elemento
    void shrink_to_fit(); // Ajusta la capacidad al tamaño real (solo declarada)

private: // Sección privada: solo accesible dentro de la clase
    int* elements; // Puntero al bloque de memoria donde se guardan los enteros
    int count; // Número actual de elementos
    int capacity; // Tamaño total del arreglo reservado

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter; // Cuenta cuántas copias se hicieron (opcional)
#endif
};

// Declaración de la función de demostración
void DemostracionDynamicArray();
