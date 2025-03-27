class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None

# Función para agregar un nodo al final de la lista
def agrega_nodo(cabeza, valor):
    nuevo_nodo = Nodo(valor)

    if cabeza is None:  # Si la lista está vacía
        cabeza = nuevo_nodo
    else:
        actual = cabeza
        while actual.siguiente is not None:  # Avanzamos en la lista
            actual = actual.siguiente
        actual.siguiente = nuevo_nodo
    
    return cabeza

# Función para imprimir la lista
def imprimir_lista(cabeza):
    actual = cabeza
    while actual is not None:
        print(actual.dato, end=" -> ")
        actual = actual.siguiente
    print("None")

# Función para borrar la lista
def borrar_lista(cabeza):
    while cabeza is not None:
        siguiente = cabeza.siguiente
        print(f"Elemento {cabeza.dato} borrado")
        cabeza = siguiente

# Función principal
if __name__ == "__main__":
    cabeza = None  # Inicializamos la cabeza de la lista como None

    tamaño_lista = int(input("Ingrese la cantidad de elementos que desea agregar a la lista: "))

    for i in range(tamaño_lista):
        valor = int(input(f"Ingrese dato {i+1}: "))
        cabeza = agrega_nodo(cabeza, valor)

    print("\nImprimiendo lista de números:")
    imprimir_lista(cabeza)

    borrar_lista(cabeza)

    print("\nImprimiendo lista de números después de borrar:")
    imprimir_lista(cabeza)

