// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include <iostream>        // Permite usar cout, endl, etc.
#include "DynamicArray.h"  // Incluye la clase DynamicArray
#include "LinkedList.h"    // Incluye la clase LinkedList
using namespace std;       // Simplifica el uso del espacio de nombres estándar

// Declaración anticipada del template y función de demostración
template <typename T>
void PrintArray(T* array, int size); // Prototipo de la función genérica para imprimir arreglos
void DemostracionTemplatePrintArray(); // Prototipo de la función que prueba el template

// Función principal del programa
int main()
{
    // Primera demostración: DynamicArray
    cout << "===== demostracion de dynamic array =====" << endl; // Título
    DemostracionDynamicArray(); // Llama a la función que prueba todas las funciones del arreglo dinámico

    // Segunda demostración: LinkedList
    cout << endl << "===== demostracion de linked list =====" << endl; // Separador visual
    DemostracionLinkedList(); // Llama a la función que prueba todas las funciones de la lista enlazada

    // Tercera demostración: Template PrintArray
    cout << endl << "===== demostracion de printarray (template) =====" << endl; // Otro separador
    DemostracionTemplatePrintArray(); // Llama a la función que demuestra el template

    // Espera de cierre (dependiendo del sistema operativo)
#ifdef _WIN32
    system("pause"); // En Windows, pausa la consola hasta que se presione una tecla
#else
    cout << "Presiona Enter para salir..." << endl; // En Mac o Linux muestra mensaje
    cin.get(); // Espera que el usuario presione Enter
#endif

    return 0; // Indica que el programa terminó correctamente
}
