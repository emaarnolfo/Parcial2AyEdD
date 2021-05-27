#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Colas.cpp"

using namespace std;

template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};

template <class T> class arbol {
private:
    nodo<T>* raiz, * q;
    void ArbolBusq(T x, nodo<T>*& nuevo);
    void rid(nodo<T>* aux);
    void ird(nodo<T>* aux);
    void idr(nodo<T>* aux);
    void show(nodo<T>* aux, int n);
    void mostrarHojas(nodo<T>* aux);
    bool esta(T n, nodo<T>* aux);
    T men(nodo<T>* aux);
    T may(nodo<T>* aux);
    //void borrar()

public:
    arbol() { raiz = NULL; };
    ~arbol() {};
    void CreaArbolBus(T x);
    void RID() { rid(raiz); }
    void IRD() { ird(raiz); }
    void IDR() { idr(raiz); }
    void VerArbol() { show(raiz, 0); }
    void MostrarHojas() { mostrarHojas(raiz); }
    bool Esta(T x) { return esta(x, raiz); }
    T Menor() { return men(raiz); }
    T Mayor() { return may(raiz); }
    //void Borrar(T x) { borrar(x, raiz); }
};


template <class T> void arbol<T>::CreaArbolBus(T x){
    ArbolBusq(x, raiz);
}

template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo){
    if (nuevo == NULL) {
        nuevo = new nodo<T>;
        nuevo->info = x; nuevo->der = nuevo->izq = NULL;
    }
    if (x > nuevo->info) ArbolBusq(x, nuevo->der);
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq);
}

template <class T> void arbol<T>::ird(nodo<T>* aux){
    if (aux != NULL) {
        ird(aux->izq);
        cout << "\n" << aux->info;
        ird(aux->der);
    }
}

template <class T> void arbol<T>::rid(nodo<T>* aux){
    if (aux != NULL) {
        cout << "\n" << aux->info;
        rid(aux->izq);
        rid(aux->der);
    }
}

template <class T> void arbol<T>::idr(nodo<T>* aux){
    if (aux != NULL) {
        idr(aux->izq);
        idr(aux->der);
        cout << "\n" << aux->info;
    }
}

template <class T> void arbol<T>::show(nodo<T>* aux, int n){
    int i;
    if (aux != NULL) {                      //OjO este es un recorrido dri
        show(aux->der, n + 1);
        for (i = 1; i <= n; i++) cout << "     ";
        cout << aux->info << "\n";
        show(aux->izq, n + 1);
    }
}


//-------------------------------------------------------
int main(int argc, char* argv[])
{
    Cola<string>* palabras = new Cola<string>();
    arbol<string> arb;

    string x;
    ifstream inFile;

    inFile.open("texto.txt");
    while(inFile >> x){
        palabras->encolar(x);
    }
    inFile.close();

    palabras->impre();

    while(!palabras->colavacia()){
        cout<<"while" <<endl;
        arb.CreaArbolBus(palabras->tope());
        palabras->desencolar();
    }

    arb.VerArbol();

    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}