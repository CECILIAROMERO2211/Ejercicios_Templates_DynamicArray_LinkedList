// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#pragma once                   // evita que este archivo se incluya más de una vez al compilar
#include <iostream>            // permite usar cout, endl y otras funciones de entrada/salida
using namespace std;           // para no tener que escribir std:: en cada línea

#define COUNT_DYNAMIC_ARRAY_COPIES 1 // define una constante que activa el conteo de copias (1 = activo)

// definición de la clase DynamicArray
class DynamicArray
{
public:                        // todo lo que va aquí puede ser usado fuera de la clase

    static const int maxCapacity = 1024; // capacidad máxima del arreglo para evitar desbordamientos

    DynamicArray(int capacity = 0);      // constructor: crea el arreglo dinámico con cierta capacidad
    ~DynamicArray();                     // destructor: libera la memoria usada por el arreglo

    void Append(const int value);        // agrega un elemento al final del arreglo
    bool InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar); // inserta un valor después de otro
    int ObtenerElemento(const size_t indice) const;   // devuelve el elemento en un índice específico
    void AsignarElemento(const size_t indice, const int valor); // cambia el valor en cierta posición
    int BuscarElemento(const int valor) const;        // busca un valor dentro del arreglo
    int QuitarUltimoElemento();                       // quita el último elemento del arreglo
    int GetCount() const;                             // devuelve cuántos elementos hay guardados
    void Print() const;                               // imprime todos los elementos
    int& operator[](int index);                       // sobrecarga del operador [] para acceder a elementos
    const int& operator[](int index) const;           // versión constante del operador []

    void push_back(int value);                        // agrega un elemento al final (como en std::vector)
    void pop_back();                                  // elimina el último elemento sin devolverlo
    void shrink_to_fit();                             // ajusta la capacidad al tamaño actual

private:                       // las siguientes variables solo se pueden usar dentro de la clase
    int* elements;              // puntero que guarda la dirección del arreglo dinámico
    int count;                  // cantidad actual de elementos en el arreglo
    int capacity;               // capacidad total del arreglo (espacio reservado)

#if COUNT_DYNAMIC_ARRAY_COPIES != 0 // si el conteo de copias está activo
    int copyCounter;             // variable que cuenta cuántas copias se hacen al redimensionar
#endif
};

// declaración de una función externa que muestra cómo funciona la clase
void DemostracionDynamicArray();
