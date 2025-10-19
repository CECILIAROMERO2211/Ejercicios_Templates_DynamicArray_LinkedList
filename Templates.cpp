// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#include <iostream>
using namespace std;

template <typename T>
void PrintArray(T* array, int size)
{
    cout << "elementos del arreglo: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void DemostracionTemplatePrintArray()
{
    int arr1[] = {1, 2, 3, 4, 5};
    double arr2[] = {1.1, 2.2, 3.3};
    string arr3[] = {"uno", "dos", "tres"};
    PrintArray(arr1, 5);
    PrintArray(arr2, 3);
    PrintArray(arr3, 3);
}
