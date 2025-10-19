// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include <iostream>          // se incluye para poder usar cout y endl
#include "DynamicArray.h"    // incluye el encabezado de la clase DynamicArray
#include "LinkedList.h"      // incluye el encabezado de la clase LinkedList
using namespace std;         // permite usar cout sin escribir std::cout

// declaración de la función plantilla que imprime arreglos de cualquier tipo
template <typename T>
void PrintArray(T* array, int size);

// declaración de la función de demostración de templates
void DemostracionTemplatePrintArray();

// función principal donde inicia el programa
int main()
{
    // muestra un título para la sección del arreglo dinámico
    cout << "===== demostracion de dynamic array =====" << endl;

    // llama a la función que demuestra las operaciones del DynamicArray
    DemostracionDynamicArray();

    // separa visualmente las demostraciones con una línea vacía
    cout << endl << "===== demostracion de linked list =====" << endl;

    // llama a la función que demuestra cómo funciona la lista enlazada
    DemostracionLinkedList();

    // imprime otro título para la parte de las funciones template
    cout << endl << "===== demostracion de printarray (template) =====" << endl;

    // llama a la función que muestra cómo se imprimen arreglos genéricos con templates
    DemostracionTemplatePrintArray();

    // mensaje final antes de terminar el programa
    cout << endl << "presiona cualquier tecla para salir..." << endl;

    system("pause"); // pausa la ejecución hasta que el usuario presione una tecla (solo en Windows)
    
    return 0;        // devuelve 0 indicando que el programa terminó correctamente
}
