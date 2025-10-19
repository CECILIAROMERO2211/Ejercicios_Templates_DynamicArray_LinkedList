// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
using namespace std;

template <typename T>
void PrintArray(T* array, int size);
void DemostracionTemplatePrintArray();

int main()
{
    cout << "===== demostracion de dynamic array =====" << endl;
    DemostracionDynamicArray();
    cout << endl << "===== demostracion de linked list =====" << endl;
    DemostracionLinkedList();
    cout << endl << "===== demostracion de printarray (template) =====" << endl;
    DemostracionTemplatePrintArray();
    cout << endl << "presiona cualquier tecla para salir..." << endl;
    system("pause");
    return 0;
}
