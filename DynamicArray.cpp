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
    {
        if (elements[i] == valorAEncontrar) // si encuentra el valor buscado
        {
            if (count >= capacity) // si el arreglo está lleno
            {
                Append(valorAInsertar); // llama a Append para redimensionar y agregar
                return true;            // regresa true porque se insertó
            }

            // recorre todos los elementos una posición hacia la derecha
            for (int j = count; j > i + 1; j--)
                elements[j] = elements[j - 1];

            elements[i + 1] = valorAInsertar; // coloca el nuevo valor después del encontrado
            count++;                          // aumenta el número de elementos
            return true;                      // termina indicando que se logró insertar
        }
    }
    cout << "advertencia: no existe el valor " << valorAEncontrar << endl; // si no lo encuentra, avisa
    return false;                    // regresa falso porque no se insertó nada
}

// función que devuelve el elemento en un índice específico
int DynamicArray::ObtenerElemento(const size_t indice) const
{
    if (indice >= count)            // si el índice es mayor que el número de elementos
    {
        cout << "error: índice fuera de rango" << endl;
        return -1;                  // devuelve -1 como indicador de error
    }
    return elements[indice];        // devuelve el valor del elemento en esa posición
}

// función que asigna un nuevo valor en un índice determinado
void DynamicArray::AsignarElemento(const size_t indice, const int valor)
{
    if (indice >= count)            // valida que el índice exista
    {
        cout << "error: índice fuera de rango" << endl;
        return;                     // si no, termina sin cambiar nada
    }
    elements[indice] = valor;       // reemplaza el valor del elemento por el nuevo
}

// busca un valor dentro del arreglo y devuelve su posición
int DynamicArray::BuscarElemento(const int valor) const
{
    for (int i = 0; i < count; i++) // recorre todos los elementos
    {
        if (elements[i] == valor)   // si el valor coincide
            return i;               // devuelve el índice donde lo encontró
    }
    return -1;                      // devuelve -1 si no se encuentra
}

// elimina el último elemento del arreglo
int DynamicArray::QuitarUltimoElemento()
{
    if (count == 0)                 // si no hay elementos
    {
        cout << "advertencia: arreglo vacío" << endl;
        return -1;                  // devuelve -1 indicando error
    }

    count--;                        // reduce el conteo de elementos
    return elements[count];         // devuelve el valor eliminado
}

// devuelve cuántos elementos tiene actualmente el arreglo
int DynamicArray::GetCount() const
{
    return count;                   // regresa la variable count
}

// imprime todos los elementos guardados en el arreglo
void DynamicArray::Print() const
{
    cout << "elementos del arreglo: ";
    for (int i = 0; i < count; i++) // recorre el arreglo
        cout << elements[i] << " "; // imprime cada elemento separado por un espacio
    cout << endl;                   // salto de línea al final
}

// sobrecarga del operador [] para acceder a elementos como si fuera un array normal
int& DynamicArray::operator[](int index)
{
    if (index < 0 || index >= count) // valida que el índice sea correcto
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1);                     // termina el programa si el índice no es válido
    }
    return elements[index];          // devuelve una referencia al elemento
}

// versión constante del operador [] (para objetos constantes)
const int& DynamicArray::operator[](int index) const
{
    if (index < 0 || index >= count) // valida el rango del índice
    {
        cout << "error: índice fuera de rango" << endl;
        exit(1);                     // detiene el programa si hay error
    }
    return elements[index];          // devuelve una referencia constante al elemento
}

// función que agrega un valor al final, igual que Append
void DynamicArray::push_back(int value)
{
    Append(value);                   // llama a Append internamente
}

// elimina el último elemento del arreglo sin devolverlo
void DynamicArray::pop_back()
{
    if (count > 0)                   // si hay elementos
        count--;                     // simplemente reduce el contador
    else
        cout << "advertencia: arreglo vacío" << endl; // avisa si no hay nada que borrar
}

// ajusta la capacidad al número exacto de elementos
void DynamicArray::shrink_to_fit()
{
    // no hace nada porque solo se pide dejarla declarada
}

// función de demostración que prueba todas las funciones anteriores
void DemostracionDynamicArray()
{
    DynamicArray myArray;             // crea un objeto de tipo DynamicArray

    myArray.Append(10);               // agrega 10 al arreglo
    myArray.Append(20);               // agrega 20
    myArray.Append(30);               // agrega 30

    cout << "elementos iniciales: ";
    myArray.Print();                  // muestra los primeros elementos

    myArray.push_back(40);            // agrega un nuevo elemento al final
    myArray.Print();                  // imprime de nuevo

    myArray.pop_back();               // elimina el último elemento
    myArray.Print();                  // muestra los que quedan

    cout << "primer elemento con operador []: " << myArray[0] << endl; // accede al primer valor con el operador []
    myArray.shrink_to_fit();          // llamada vacía como parte del ejercicio
}

// Fuentes de información:
// Cplusplus.com. (n.d.). exit – C++ Reference. Recuperado de https://cplusplus.com/reference/cstdlib/exit/
// Deitel, P. J., & Deitel, H. M. (2016). C++ Cómo programar (10ª edición). Pearson Educación.
