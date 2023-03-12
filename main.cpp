#include <iostream>
using namespace std;

class Nodo
{
public:
    int dato;
    Nodo *siguiente;
    Nodo(){
        dato = 0;
        siguiente = nullptr;
    }
    Nodo(int dato)
    {
        this->dato = dato;
        this->siguiente = NULL;
    }
    Nodo(int dato, Nodo *signodo)
    {
        this->dato = dato;
        this->siguiente = signodo;
    }

    void setDato(int x);
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

class Collector {
public:
    Nodo *head;

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
        }
    }

    bool HayEspacios() {
        if (this->head == nullptr) {
            return false;
        } else {
            return true;
        }
    }

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

class Lista {
public:
    Nodo *cabeza;
    int tamaño;
    Collector *botadero;

    Lista() {
        cabeza = nullptr;
        tamaño = 0;
        botadero = new Collector();
    }

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
