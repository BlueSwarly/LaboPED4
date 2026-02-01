#include <iostream>
#include <fstream>
using namespace std;

struct Quirales{
    int id;
    string name;
    float weight;

    Quirales *sig;
    Quirales *ant;
};

class Lucky_Clover{
    private:
    Quirales *head; //pInicio
    Quirales *tail; //pFinal

    public:
    Lucky_Clover();
    void InsertarInicio(void);
    void InsertarFinal(void);
    void MostrarInicio(void);
    void MostrarFinal(void);
    void BuscarporId(void);
    void EliminarporId(void);
    void ModificarporId(void);
    void ArchivoLista(void);
    void MenuAcciones(void);

};

Lucky_Clover::Lucky_Clover(){
    head = nullptr;
    tail = nullptr; 
    //limpiamos ambas listas
}

void Lucky_Clover::InsertarInicio(void){
    Quirales *nuevo = new Quirales;
    int id;
    string name;
    float weight;

    cout << "Digite el id para la orden: ";
    cin >> id; 
    cout <<"Dijite el nombre: ";
    getline(cin >> ws, name);
    cout << "Digite el peso del paquete: ";
    cin >> weight;

    (*nuevo).id = id;
    (*nuevo).name = name;
    (*nuevo).weight = weight;
    (*nuevo).ant = nullptr;

    if(head == nullptr){ //validos si nuestro primer valor es nulo
        (*nuevo).sig = nullptr;
        head = tail = nuevo; //como no hay valor inicializamos el primero y el ultimo con el mismo valor 
    } else {
        (*nuevo).sig = head;
        head->ant = nuevo;
        head = nuevo;
    }
 
}

void Lucky_Clover::InsertarFinal(void){
    Quirales *nuevo = new Quirales;
    int id;
    string name;
    float weight;

    cout << "Digite el id para la orden: ";
    cin >> id; 
    cout <<"Dijite el nombre: ";
    getline(cin >> ws, name);
    cout << "Digite el peso del paquete: ";
    cin >> weight;

    (*nuevo).id = id;
    (*nuevo).name = name;
    (*nuevo).weight = weight;
    (*nuevo).sig = nullptr;

    if(head == nullptr){ //validos si nuestro primer valor es nulo
        (*nuevo).ant = nullptr;
        head = tail = nuevo; //como no hay valor inicializamos el primero y el ultimo con el mismo valor 
    } else {
        (*nuevo).ant = tail;
        head->sig = nuevo;
        tail = nuevo;
    }
 
}