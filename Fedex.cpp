#include <iostream>
#include <fstream>
using namespace std;

struct Quirales
{
    int id;
    string name;
    float weight;

    Quirales *sig;
    Quirales *ant;
};

class Lucky_Clover
{
private:
    Quirales *head; // pInicio
    Quirales *tail; // pFinal

public:
    Lucky_Clover();
    void InsertarInicio(void);
    void InsertarFinal(void);
    void MostrarInicio(void);
    void MostrarFinal(void);
    void BuscarporId(void);
    void EliminarporId(void);
    void ModificarporId(void);
    void ArchivoEnvios(void);
    void CargarEnvios(void);
    void MenuAcciones(void);
};

Lucky_Clover::Lucky_Clover()
{
    head = nullptr;
    tail = nullptr;
    CargarEnvios();
    // limpiamos ambas listas
}

void Lucky_Clover::InsertarInicio(void)
{
    Quirales *nuevo = new Quirales;
    int id;
    string name;
    float weight;

    cout << "Digite el id para la orden: ";
    cin >> id;
    cout << "Dijite el nombre: ";
    getline(cin >> ws, name);
    cout << "Digite el peso del paquete: ";
    cin >> weight;

    (*nuevo).id = id;
    (*nuevo).name = name;
    (*nuevo).weight = weight;
    (*nuevo).ant = nullptr;

    if (head == nullptr)
    { // validos si nuestro primer valor es nulo
        (*nuevo).sig = nullptr;
        head = tail = nuevo; // como no hay valor inicializamos el primero y el ultimo con el mismo valor
    }
    else
    {
        (*nuevo).sig = head;
        head->ant = nuevo;
        head = nuevo;
    }
}

void Lucky_Clover::InsertarFinal(void)
{
    Quirales *nuevo = new Quirales;
    int id;
    string name;
    float weight;

    cout << "Digite el id para la orden: ";
    cin >> id;
    cout << "Dijite el nombre: ";
    getline(cin >> ws, name);
    cout << "Digite el peso del paquete: ";
    cin >> weight;

    (*nuevo).id = id;
    (*nuevo).name = name;
    (*nuevo).weight = weight;
    (*nuevo).sig = nullptr;

    if (head == nullptr)
    { // validos si nuestro primer valor es nulo
        (*nuevo).ant = nullptr;
        head = tail = nuevo; // como no hay valor inicializamos el primero y el ultimo con el mismo valor
    }
    else
    {
        (*nuevo).ant = tail;
        head->sig = nuevo;
        tail = nuevo;
    }
}

void Lucky_Clover::MostrarInicio(void)
{
    if (head != nullptr)
    {
        Quirales *Rito = head;

        while (Rito != nullptr)
        {

            cout << "id para la orden: " << Rito->id << endl;
            cout << "Nombre: " << Rito->name << endl;
            cout << "Peso del paquete: " << Rito->weight << endl;
            cout << "---------------------" << endl;
            Rito = Rito->sig;
        }
    }
    else
    {
        cout << "Aun no hay paquetes en la lista " << endl;
        return;
    }
}

void Lucky_Clover::MostrarFinal(void)
{
    if (tail != nullptr)
    {
        Quirales *Rito = tail;

        while (Rito != nullptr)
        {
            cout << "id para la orden: " << Rito->id << endl;
            cout << "Nombre: " << Rito->name << endl;
            cout << "Peso del paquete: " << Rito->weight << endl;
            cout << "---------------------"<< endl;
            Rito = Rito->ant;
        }
    }
    else
    {
        cout << "Aun no hay paquetes en la lista " << endl;
    }
}

void Lucky_Clover::BuscarporId(void)
{
    if (head == nullptr)
    {
        cout << "La lista esta vacia.";
        return;
    }

    int idBuscar;
    cout << "Digite el id a buscar: ";
    cin >> idBuscar;

    Quirales *aux = head;

    while (aux != nullptr)
    {
        if (aux->id == idBuscar)
        {
            cout << "Paquete encontrado: "<< endl;
            cout << "Id: " << aux->id << endl;
            cout << "Nombre: " << aux->name << endl;
            cout << "Peso: " << aux->weight << endl;
            return;
        }

        aux = aux->sig;
    }

    cout << "No se encontro el paquete."<< endl;
}

void Lucky_Clover::EliminarporId(void)
{
    if (head == nullptr)
    {
        cout << "Lista vacia.";
        return;
    }

    int idEliminar;
    cout << "Digite el id a eliminar: ";
    cin >> idEliminar;

    Quirales *aux = head;

    while (aux != nullptr)
    {

        if (aux->id == idEliminar)
        {

            if (head == tail)
            {
                head = tail = nullptr;
            }
            else if (aux == head)
            {
                head = head->sig;
                head->ant = nullptr;
            }
            else if (aux == tail)
            {
                tail = tail->ant;
                tail->sig = nullptr;
            }
            else
            {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }

            delete aux;
            cout << "Paquete eliminado."<< endl;
            return;
        }

        aux = aux->sig;
    }

    cout << "No se encontro el paquete."<< endl;
}

void Lucky_Clover::ModificarporId(void)
{
    if(head== nullptr){
        cout << "No hay paquetes que se puedan editar " << endl;
        return;
    } else {
        
    int idEdit;
    cout << "Digite el id del paquete a editar: ";
    cin >> idEdit;

    Quirales *Search = head;
    while (Search != nullptr)
    {

        if (Search->id == idEdit)
        {
            cout << "Nuevo nombre: ";
            getline(cin >> ws, Search->name);
            cout << "Nuevo peso: ";
            cin >> Search->weight;

            cout << "Se ha modificado la informacion del paquete. " << endl;

        }
        Search = Search->sig;
    }
    }
    cout << "id Invalido" << endl;
}

void Lucky_Clover::ArchivoEnvios(void)
{
    ofstream archivo("PaquetesenCola.txt");

    Quirales *a1 = head;
    while (a1 != nullptr)
    {
        archivo << a1->id << " "
                << a1->name << " "
                << a1->weight << endl;
        a1 = a1->sig;
    }
    archivo.close();
}

void Lucky_Clover::CargarEnvios(void)
{
    ifstream archivo("PaquetesenCola.txt");

    int id;
    string name;
    float weight;

    while (archivo >> id >> name >> weight)
    {
        Quirales *Cargar = new Quirales;

        Cargar->id = id;
        Cargar->name = name;
        Cargar->weight = weight;
        Cargar->sig = nullptr;
        Cargar->ant = nullptr;

        if (head == nullptr)
        {
            head = tail = Cargar;
        }
        else
        {
            tail->sig = Cargar;
            Cargar->ant = tail;
            tail = Cargar;
        }
    }
    archivo.close();
}

void Lucky_Clover::MenuAcciones(void)
{

    cout << endl;
    cout << "Las opciones del menu son: " << endl;

    int option;

    do
    {
        cout << "1. Insertar paquete al inicio.  " << endl
             << "2. Insertar paquete al final. " << endl
             << "3. Mostrar Adelante " << endl
             << "4. Mostrar Atras " << endl
             << "5. Buscar paquete por id " << endl
             << "6. Eliminar paquete por id " << endl
             << "7. Editar paquete por id" << endl
             << "8. Salir" << endl;
        cin >> option;

        switch (option)
        {

        case 1:
            InsertarInicio();
            break;
        case 2:
            InsertarFinal();
            break;
        case 3:
            MostrarInicio();
            break;
        case 4:
            MostrarFinal();
            break;
        case 5:
            BuscarporId();
            break;
        case 6:
            EliminarporId();
            break;
        case 7:
            ModificarporId();
            break;
        case 8:
            ArchivoEnvios();
            cout << "Saliendo....";
            break;
        }

    } while (option != 8);
}

int main()
{

    Lucky_Clover HyrulePost;
    HyrulePost.MenuAcciones();

    cout << endl;
    return 0;
}