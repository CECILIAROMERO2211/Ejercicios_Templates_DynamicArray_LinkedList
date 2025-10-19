// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include <iostream>          // biblioteca necesaria para usar cout y endl
using namespace std;         // permite usar cout sin escribir std::cout

// función plantilla (template) que permite imprimir arreglos de cualquier tipo de dato
template <typename T>        // se usa <typename T> para hacer la función genérica
void PrintArray(T* array, int size) // recibe un puntero al arreglo y su tamaño
{
    cout << "elementos del arreglo: "; // imprime un texto inicial antes de los valores
    for (int i = 0; i < size; i++)     // ciclo que recorre todos los elementos del arreglo
        cout << array[i] << " ";       // imprime el valor actual seguido de un espacio
    cout << endl;                      // salto de línea al final
}

// función que demuestra el uso del template PrintArray con distintos tipos de datos
void DemostracionTemplatePrintArray()
{
    int arr1[] = {1, 2, 3, 4, 5};                // arreglo de enteros
    double arr2[] = {1.1, 2.2, 3.3};             // arreglo de números decimales (double)
    string arr3[] = {"uno", "dos", "tres"};      // arreglo de cadenas de texto (string)

    PrintArray(arr1, 5);                         // imprime el arreglo de enteros
    PrintArray(arr2, 3);                         // imprime el arreglo de decimales
    PrintArray(arr3, 3);                         // imprime el arreglo de strings
}
