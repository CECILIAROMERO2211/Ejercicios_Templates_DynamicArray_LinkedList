// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include <iostream> // Permite usar cout, endl, etc.
using namespace std; // Simplifica el uso del espacio de nombres estándar

// Template de función que imprime los elementos de un arreglo de cualquier tipo
template <typename T> // Declara que la función será genérica (puede usar cualquier tipo de dato)
void PrintArray(T* array, int size)
{
    cout << "elementos del arreglo: "; // Muestra mensaje inicial
    for (int i = 0; i < size; i++)     // Recorre todos los elementos del arreglo
        cout << array[i] << " ";       // Imprime el elemento actual seguido de un espacio
    cout << endl;                      // Salto de línea al final
}

// Función que demuestra el uso del template PrintArray con diferentes tipos de datos
void DemostracionTemplatePrintArray()
{
    int arr1[] = {1, 2, 3, 4, 5};              // Arreglo de enteros
    double arr2[] = {1.1, 2.2, 3.3};           // Arreglo de números decimales
    string arr3[] = {"uno", "dos", "tres"};    // Arreglo de cadenas (strings)

    // Llamadas a la función template con diferentes tipos
    PrintArray(arr1, 5); // Imprime el arreglo de enteros
    PrintArray(arr2, 3); // Imprime el arreglo de flotantes
    PrintArray(arr3, 3); // Imprime el arreglo de cadenas
}
