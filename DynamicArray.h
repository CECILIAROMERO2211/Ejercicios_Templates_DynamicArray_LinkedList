// Autores: Cecilia Romero Granados y Alexis Jeshua Arrona
// Práctica: Templates, DynamicArray y LinkedList
// Profesor: Adrián González
// Universidad Cuauhtémoc Querétaro

#pragma once
#include <iostream>
using namespace std;

#define COUNT_DYNAMIC_ARRAY_COPIES 1

class DynamicArray
{
public:
    static const int maxCapacity = 1024;
    DynamicArray(int capacity = 0);
    ~DynamicArray();
    void Append(const int value);
    bool InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar);
    int ObtenerElemento(const size_t indice) const;
    void AsignarElemento(const size_t indice, const int valor);
    int BuscarElemento(const int valor) const;
    int QuitarUltimoElemento();
    int GetCount() const;
    void Print() const;
    int& operator[](int index);
    const int& operator[](int index) const;
    void push_back(int value);
    void pop_back();
    void shrink_to_fit();

private:
    int* elements;
    int count;
    int capacity;
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter;
#endif
};

void DemostracionDynamicArray();
