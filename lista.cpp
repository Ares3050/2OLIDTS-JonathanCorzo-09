#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para agregar elementos a la lista
void agregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo; // Creando el apuntador hacia el nuevo nodo
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    }
    else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

// Función para borrar la lista y liberar memoria
void borrarLista(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* siguiente = cabeza->siguiente;
        cout << "Elemento borrado: " << cabeza->dato << endl;
        delete cabeza;
        cabeza = siguiente;
    }
}

int main() {
    Nodo* cabeza = nullptr; // Declaramos un puntero de memoria nulo
    int tamanolista;

    cout << "Ingrese la cantidad de elementos que desea agregar a la lista: ";
    cin >> tamanolista;

    if (tamanolista <= 0) {
        cout << "Cantidad de elementos no válida" << endl;
        return 1;
    }

    for (int i = 0; i < tamanolista; i++) {
        int valor;
        cout << "Ingrese dato " << i + 1 << ": ";
        cin >> valor;
        // Invocamos nuestra función de agregar Nodo
        agregarNodo(cabeza, valor);
    }

    cout << "Imprimiendo lista de números: " << endl;
    imprimirLista(cabeza);

    cout << "Eliminando la lista..." << endl;
    borrarLista(cabeza);

    return 0;
}