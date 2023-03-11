#include <iostream>
using namespace std;

class Nodo
{
public:
    int dato;
    Nodo *puntero;
    Nodo *siguiente;
    Nodo(){

    }
    Nodo(int dato)
    {
        this->dato = dato;
        this->siguiente = NULL;
        this->puntero = NULL;
    }
    Nodo(int dato, Nodo *signodo)
    {
        this->dato = dato;
        this->siguiente = signodo;
        this->puntero = NULL;
    }
    Nodo(Nodo *puntero){
        this->dato = 0;
        this->siguiente = NULL;
        this->puntero = puntero;
    }
    Nodo(Nodo *puntero, Nodo *signodo){
        this->dato = 0;
        this->siguiente = signodo;
        this->puntero = puntero;
    }

};

//////////////////////////

class Collector {
public:
    Nodo *head;

    /**bool ListaVacia() {
        cout << " entro a lista ";
        cout << " AAAAAAAAAAAAAAA ";
        return head == nullptr;
    }*/


    void InsertarInicio(int puntero) {
        cout <<puntero<<endl;
        cout << "entro a insertar" << endl;
        if (this->head == NULL) {
            cout << "entro al if" << endl;
            this->head = new Nodo(puntero);
        } else {
            cout << "entro al else" << endl;
            this->head = new Nodo(puntero, head);
        }
    }


    void Mostrar() {
        Nodo *aux;
        if (head == NULL)
            cout << "No hay elementos AQUI";
        else {
            aux = head;
            while (aux) {
                cout << aux->puntero << "-> ";
                aux = aux->siguiente;
            }
            cout << endl;
        }
    }
};



//////////////////////////






class Lista {
Collector* botadero;
private:
    void agregarRecursivo(Nodo *n, int dato) {
        if (n->siguiente == NULL) {
            n->siguiente = new Nodo(dato);
        } else {
            this->agregarRecursivo(n->siguiente, dato);
        }
    }
    void agregarInicioRecursivo(Nodo *n, int dato) {
        if (n->siguiente == NULL) {
            this->cabeza = new Nodo(dato);
        } else {
            this->cabeza = new Nodo(dato, this->cabeza);
        }
    }
    void imprimirRecursivo(Nodo *n) {
        if (n != NULL) {
            int *datoPtr;
            datoPtr = &n->dato;
            cout << n->dato << std::endl;
            cout << datoPtr << std::endl;
            this->imprimirRecursivo(n->siguiente);
        }
    }

    void eliminarRecursivo(Nodo *n, int dato) {
        if (n == NULL) {
            return;
        }
        if (n->dato == dato && n == this->cabeza) {
            Nodo *temporal = this->cabeza;

            cout << temporal<< endl;
            if (this->cabeza->siguiente != NULL) {
                this->cabeza = this->cabeza->siguiente;
                //cout << "ENTRO LINEA 57";
                //botadero->agregarC(temporal);
                delete temporal;
            } else {
                //cout << "ENTRO LINEA 61";
                this->cabeza = NULL;
            }
            return;
        }
        if (n->siguiente != NULL && n->siguiente->dato == dato) {
            Nodo *temporal = n->siguiente;
            Nodo *temp = temporal;
            cout << temporal << endl;
            if (n->siguiente != NULL) {
                //cout << "ENTRO LINEA 69" << endl;
                n->siguiente = n->siguiente->siguiente;
            }
            botadero->InsertarInicio(5);
            delete temporal;
        } else {
            //cout << "ENTRO LINEA 74"<< endl;
            this->eliminarRecursivo(n->siguiente, dato);
        }
    }

    bool existeRecursivo(Nodo *n, int dato) {
        if (n == NULL) {
            return false;
        }
        if (n->dato == dato) {
            return true;
        }
        return this->existeRecursivo(n->siguiente, dato);
    }

public:
    Nodo *cabeza;
    Nodo *aux;

    void eliminar(int dato) {

        this->eliminarRecursivo(this->cabeza, dato);
    }

    void agregar(int dato) {
        cout << "cabeza de la lista simple:  "<< cabeza <<endl;
        if (this->cabeza == NULL) {

            this->cabeza = new Nodo(dato);
        } else {
            this->agregarRecursivo(this->cabeza, dato);
        }
    }

    void agregarI(int dato)
    {
        agregarInicioRecursivo( this->cabeza, dato);
    }
    void imprimir()
    {
        //cout << "Imprimiendo " << endl;
        //this->imprimirRecursivo(this->cabeza);
        if( this->cabeza == NULL)
            cout << "No hay elementos AQUI";
        else{
            aux = this->cabeza;
            int *datoPtr;
            while(aux){
                datoPtr = &aux ->dato;
                cout << aux->dato << "-> ";
                //cout << datoPtr << "-> " << endl;
                aux = aux->siguiente;
            }
            cout << endl;
        }
    }
    bool existe(int dato)
    {
        return this->existeRecursivo(this->cabeza, dato);
    }
};




/////////////////////////////////








int main()
{
    Lista *l = new Lista();
    Collector *C = new Collector();
    //C->getHead();
    Nodo *N = new Nodo(N);
    Nodo *M = new Nodo(M, N);
    l->agregar(1);
    l->imprimir();
    l->agregar(2);
    l->imprimir();
    l->agregarI(3);
    l->imprimir();
    l->agregar(4);
    l->agregar(5);
    l->imprimir();

    l->eliminar(4);
    l->imprimir();
    //l->eliminar(1);
    //l->agregar(3);
    //l->eliminar(1);
    //l->eliminar(2);
    //l->eliminar(3);
    //l->eliminar(4);
    //l->eliminar(5);

    //C->agregarC(M);
    C->Mostrar();

    int pepe = 5;
    int *PepePtr = &pepe;
    C->InsertarInicio(*PepePtr);


}
