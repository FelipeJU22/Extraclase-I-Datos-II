#include <iostream>
using namespace std;

/**
 * Clase utilizada para la reservación de datos enteros
 */
class Nodo
{
public:
    int dato;
    Nodo *siguiente;
    Nodo(){
        dato = 0;
        siguiente = nullptr;
    }
    /**
     * Método constructor para nodos enteros
     * @param dato
     */
    Nodo(int dato)
    {
        this->dato = dato;
        this->siguiente = NULL;
    }
    /**
     * Método constructor para nodos y puntero hacia el siguiente nodo
     * @param dato
     * @param signodo
     */
    Nodo(int dato, Nodo *signodo)
    {
        this->dato = dato;
        this->siguiente = signodo;
    }
    /**
     * setear del dato entero
     * @param x
     */
    void setDato(int x);
    /**
     * Setear el siguiente valor
     * @param x
     */
    void setSiguiente(Nodo* x);
    friend class Collector;
};
void Nodo::setDato(int x){
    dato = x;
}
void Nodo::setSiguiente(Nodo* x){
    siguiente = x;
}



//-----------------------------------------------------------------------------
/**
 * Clase collector, encargada de recolectar punteros de los datos eliminados
 */
class Collector {
public:
    Nodo *head;

    /**
     * Insertar al inicio de collector
     * @param puntero
     */
    void InsertarInicioC(Nodo *puntero) {
        if (head == nullptr) {
            head = puntero;
            //head->setDato(0);
            head->siguiente = nullptr;
        } else {
            puntero->setSiguiente(head);
            head = puntero;
            head->setDato(0);
        }
    }
    /**
     * Mostrar collector
     */
    void Mostrar() {
        cout << "Se elimina ----> " << head <<endl;
        if (head == nullptr)
            cout << "No hay elementos en collector";
        else {
            cout<< "Collector:   ";
            for (Nodo *temp = head; temp != nullptr; temp = temp->siguiente) {
                cout << temp << " / ";
            }
            cout << endl;
            cout << endl;
        }
    }
    /**
     * Función para verificar si hay algo en collector
     * @return
     */
    bool HayEspacios() {
        if (this->head == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    /**
     * Función para eliminar de collector
     * @return
     */
    Nodo *EliminarDeColl() {
        if (this->head->siguiente == nullptr) {
            Nodo *tmp = head;
            head = nullptr;

            return tmp;
        } else {
            Nodo *tmp = head;
            head = head->siguiente;
            return tmp;
        }
    };
};


//-----------------------------------------------------------------------------
/**
 * Clase lista, para almacenar nodos con valores enteros
 */
class Lista {
public:
    Nodo *cabeza;
    int tamaño;
    Collector *botadero;
    /**
     * Atributos de la lista simple enlazada
     */
    Lista() {
        cabeza = nullptr;
        tamaño = 0;
        botadero = new Collector();
    }
    /**
     * Función para insertar al final de la lista
     * @param data
     */
    void InsertarFinal(int data) {
        if (botadero->HayEspacios() != false) {
            Nodo *newPtr = botadero->EliminarDeColl();
            if (cabeza == nullptr) {
                cabeza = newPtr;
                cabeza->setDato(data);
                cabeza->setSiguiente(nullptr);
                tamaño++;
            } else {
                Nodo *temp = cabeza;
                while (temp->siguiente != nullptr) {
                    temp = temp->siguiente;
                }
                temp->setSiguiente(newPtr);
                newPtr->setSiguiente(nullptr);
                newPtr->setDato(data);
                tamaño++;
            }
        } else {
            Nodo *newPtr = new Nodo(data);
            if (cabeza == nullptr) {
                cabeza = newPtr;
                tamaño++;
            } else {
                Nodo *temp = cabeza;
                while (temp->siguiente != nullptr) {
                    temp = temp->siguiente;
                }
                temp->setSiguiente(newPtr);
                tamaño++;
            }
        }
    }
    /**
     * Función para insertar al inicio de la lista enlazada
     * @param data
     */
    void InsertarInicio(int data) {

        if (botadero->HayEspacios() != false) {
            Nodo *newPtr = botadero->EliminarDeColl();

            if (cabeza == nullptr) {
                cabeza = newPtr;
                cabeza->setDato(data);
                cabeza->setSiguiente(nullptr);
                tamaño++;

            } else {
                newPtr->setSiguiente(cabeza);
                cabeza = newPtr;
                cabeza->setDato(data);
                tamaño++;

            }
        } else {
            if (cabeza == nullptr) {
                Nodo *newPtr = new Nodo(data);
                cabeza = newPtr;
                tamaño++;
            } else {
                Nodo *newPtr = new Nodo(data, cabeza);
                cabeza = newPtr;
                tamaño++;
            }
        }

    }
    /**
     * Función para eliminar dato de la lista enlazada
     * @param data
     */
    void EliminarDato(int data) {
        if (data == cabeza->dato) {
            Nodo *temp = cabeza;
            cabeza = cabeza->siguiente;
            botadero->InsertarInicioC(temp);
            botadero->Mostrar();
            tamaño--;


        } else {
            Nodo *buscador = cabeza;
            Nodo *prev;
            while (buscador->dato != data) {
                prev = buscador;
                buscador = buscador->siguiente;
            }

            prev->siguiente = buscador->siguiente; // prev->nextPtr = prev->nextPtr->nextPtr;
            botadero->InsertarInicioC(buscador);
            botadero->Mostrar();
            tamaño--;
        }

    }
    /**
     * Función para mostrar la lista enlazada actual
     */
    void MostrarLista() {
        Nodo *temp;
        if (cabeza == nullptr) {
            cout << "No hay elementos en al lista " << endl;
        } else {
            temp = cabeza;
            cout << "Lista :   " << endl;
            while (temp) {
                cout <<  temp->dato << " -> " <<temp << endl;
                temp = temp->siguiente;
            }
            cout << endl;
        }
    }
};

//-----------------------------------------------------------------------------

/**
 * Función main
 * @return
 */
int main(){
    Lista *l = new Lista();
    Collector *C = new Collector();
    l->InsertarInicio(1);
    l->InsertarFinal(2);
    l->InsertarInicio(3);
    l->InsertarFinal(4);
    l->InsertarFinal(5);

    l->MostrarLista();


    l->EliminarDato(4);
    l->MostrarLista();

    l->EliminarDato(5);
    l->MostrarLista();


    l->InsertarInicio(70);
    l->MostrarLista();
    l->EliminarDato(1);
    l->EliminarDato(3);

    l->InsertarFinal(48);
    l->MostrarLista();
}