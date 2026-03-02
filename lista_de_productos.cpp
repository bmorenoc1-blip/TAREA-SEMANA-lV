#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};
struct Nodo {
    Producto dato;
    Nodo* siguiente;
};

int main() {
    cout << "========================================" << endl;
    cout << "Estudiante: [Brandon Moreno ]" << endl;
    cout << "Sistema de Gestión de Productos (FERRETERIA)" << endl;
    cout << "========================================\n" << endl;

    Nodo* cabeza = nullptr;
    Nodo* ultimo = nullptr; 

    for (int i = 0; i < 4; i++) {
      
        Nodo* nuevoNodo = new Nodo();
        
        cout << "Producto #" << i + 1 << endl;
        cout << "Ingrese código: ";
        cin >> nuevoNodo->dato.codigo;
        cin.ignore(); 
        cout << "Ingrese nombre: ";
        getline(cin, nuevoNodo->dato.nombre);
        cout << "Ingrese precio: ";
        cin >> nuevoNodo->dato.precio;

        nuevoNodo->siguiente = nullptr;

        if (cabeza == nullptr) {
            cabeza = nuevoNodo; 
            ultimo = nuevoNodo;
        } else {
            ultimo->siguiente = nuevoNodo; 
            ultimo = nuevoNodo;            
        }
        cout << "----------------------------------------" << endl;
    }

    cout << "\nLISTADO DE PRODUCTOS:" << endl;
    cout << "----------------------------------------" << endl;
    
    Nodo* aux = cabeza; // 
    double totalAcumulado = 0;

    while (aux != nullptr) {
        cout << "ID: " << aux->dato.codigo 
             << " | Nombre: " << aux->dato.nombre 
             << " | Precio: $" << aux->dato.precio << endl;
        
        totalAcumulado += aux->dato.precio;
        aux = aux->siguiente; 
    }

    cout << "----------------------------------------" << endl;
    cout << "TOTAL ACUMULADO: $" << totalAcumulado << endl;
    cout << "----------------------------------------" << endl;

    cout << "\nLiberando memoria..." << endl;
    while (cabeza != nullptr) {
        Nodo* temporal = cabeza;    
        cabeza = cabeza->siguiente; 
        delete temporal;            
    }
    cout << "Memoria liberada exitosamente. Programa finalizado." << endl;
    return 0;
}