#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Nodo{
    string dato;
    Nodo *siguiente;
};
bool leerCola(Nodo *&frente,string dato);
bool colaVacia(Nodo *frente);
void insertarCola(Nodo *&frente,Nodo *&fin,Nodo *&pila);
void crearPila(Nodo *&pila,string caracter);
string sacarPila(Nodo *&pila);
void suprimirCola(Nodo *&frente,Nodo *&fin,string &cedula);
void mostrarCola(Nodo *&frente);
int main()
{
    Nodo *pila=NULL;
    Nodo *frente=NULL;
    Nodo *fin=NULL;
    string ced;
    cout << "Bienvenido al Banco el Tesoro!" << endl;
    cout << "--------------------------------------------------------"<< endl;
    while(1){
    cout << "\nPresione 'A' para ingresar una cedula" << endl;
    cout << "Presione '1' para llamar a la cola virtual de la taquilla 1" << endl;
    cout << "Presione '2' para llamar a la cola virtual de la taquilla 2" << endl;
    cout << "Presione '3' para llamar a la cola virtual de la taquilla 3" << endl;
    cout << "Presione 'F' para finalizar el programa\n" << endl;
    char opcion;
    cin>>opcion;
    opcion=toupper(opcion);
    switch(opcion){
    case 'A':
        {
            insertarCola(frente,fin,pila);
            break;
        }
    case '1':
        if(frente!=NULL){
            suprimirCola(frente,fin,ced);
            cout<<"Se elimino correctamente"<<endl;
            mostrarCola(frente);
        }else{
            cout<<"No existen mas personas en la cola virtual"<<endl;
        }
        break;
    break;
    case '2':
        if(frente!=NULL){
            suprimirCola(frente,fin,ced);
            cout<<"Se elimino correctamente"<<endl;
            mostrarCola(frente);
        }else{
            cout<<"No existen mas personas en la cola virtual"<<endl;
        }
        break;
    case '3':
        if(frente!=NULL){
            suprimirCola(frente,fin,ced);
            cout<<"Se elimino correctamente"<<endl;
            mostrarCola(frente);
        }else{
            cout<<"No existen mas personas en la cola virtual"<<endl;
        }
        break;
    case 'F':
    return 0;
    break;
    default:
        cout<<"No es ninguna opcion"<<endl;
        return 0;
    }
    }
    return 0;
}
void insertarCola(Nodo *&frente,Nodo *&fin,Nodo *&pila){
    string cedula,caracter;
    int cont=3;
    int caracteres=0;
    cout << "\nIngrese la cedula: ";
    getline(cin>>ws,cedula);
    int pos=cedula.length();
    string codigo = cedula.substr(pos-cont,3);
    while(1){
    if(leerCola(frente,codigo)){
    Nodo *nuevo_nodo =new Nodo();
    nuevo_nodo->dato=codigo;
    nuevo_nodo->siguiente=NULL;
    if(colaVacia(frente)){
        frente =nuevo_nodo;
    }
    else{
        fin->siguiente=nuevo_nodo;
    }
    fin=nuevo_nodo;
    mostrarCola(frente);
    break;
    }else{
        cont++;
        if(pos-cont==-1){
            while(caracteres<pos){
                caracter=cedula.substr(caracteres,1);
                crearPila(pila,caracter);
                caracteres++;
            }
        cedula="";
        cedula+=sacarPila(pila);
        cont=3;
        codigo=cedula.substr(pos-cont,3);
        }else{
        codigo = cedula.substr(pos-cont,3);
        }
    }
    }

}


void crearPila(Nodo *&pila,string caracter){
    Nodo *nuevo_nodo =new Nodo();
    nuevo_nodo->dato=caracter;
    nuevo_nodo->siguiente=pila;
    pila=nuevo_nodo;
}
bool colaVacia(Nodo *frente){
    return(frente==NULL)?true:false;
}


bool leerCola(Nodo *&frente,string dato){
    Nodo *aux=frente;
    while(frente!=NULL){
        if(frente->dato==dato){
            frente=aux;
            return false;
            break;
        }else{
        frente=frente->siguiente;
        }}
    frente=aux;
    return true;
}
string sacarPila(Nodo *&pila){
    string cedula="";
    while(pila!=NULL){
        cedula+=pila->dato;
        pila=pila->siguiente;
    }
    return cedula;
}

void suprimirCola(Nodo *&frente,Nodo *&fin,string &cedula){
    cedula=frente->dato;
    Nodo *aux=frente;
    if(frente==fin){
        frente=NULL;
        fin=NULL;
    }else{
        frente=aux->siguiente;
    }
    delete aux;
}
void mostrarCola(Nodo *&frente){
    Nodo *aux=frente;
    cout<<"\nLa cola contiente los siguientes elementos\n"<<endl;
    while(frente!=NULL){
        cout<<frente->dato<<endl;
        frente=frente->siguiente;
    }
    frente=aux;
}
