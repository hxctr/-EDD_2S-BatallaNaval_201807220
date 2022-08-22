#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
using namespace std;
#define null 0
#include <cstdlib>

// cola
class NodoC
{
public:
    string x;
    string y;
    NodoC *sigC, *antC;

    NodoC(string x, string y)
    {
        this->x = x;
        this->y = y;
        this->sigC = null;
        this->antC = null;
    }

    string getX()
    {
        return this->x;
    }

    string getY()
    {
        return this->y;
    }
};

class Cola
{
private:
    NodoC *cabeza;

public:
    Cola()
    {
        this->cabeza = null;
    }

     void enqueue(string x, string y)
    {
        NodoC *newqueue = new NodoC(x, y);

        if (this->cabeza == null)
        {
            this->cabeza = newqueue;
        }else{
            newqueue->sigC = this->cabeza;
            this->cabeza = newqueue;
        }
    }

    void graficarCola(){
        NodoC* nuevo = this->cabeza;
        int cont = 0;
        string cadena = "";

        cadena +=  "digraph G { \n";
        cadena +=  "rankdir=LR\n";


         while(nuevo != null){

            cadena += string("Node") +string(to_string(cont))+string("[label=\"")+string(nuevo->getX())+string("\n")+string(nuevo->getY())+string("\" shape=box];\n");
            if (nuevo != this->cabeza) {
                cadena += string("Node")+string(to_string(cont-1))+string(" -> ")+string("Node")+string(to_string(cont))+string(";\n");
            }
            nuevo = nuevo->sigC;
            cont+=1;
        }

        cadena += "}";
        cout<<cadena;
        ofstream colaDot;
        colaDot.open("./cola.dot");
        colaDot << cadena;
        colaDot.close();

        // ofstream file;
        // file.open("./cola.dot");
        // file << "digraph G { \n";
        // file << "rankdir=LR\n";

        // while(nuevo != null){
        //     file << "Node"<<cont<<"[label=\""<<nuevo->getX()<<"\n"<<nuevo->getY()<<;
        //     if (nuevo != this->cabeza) {
        //         file << 'Node'<<cont-1<<' -> '<<'Node'+cont<<';\n';
        //     }
        //     nuevo = nuevo->sigC;
        //     cont+=1;
        // }
        // file << '}';
        // file.close();

    }
};

// lista de listas
class nodo
{
public:
    int espacio;
    string name;
    nodo *siguiente, *anterior;

    nodo(int espacio, string nombre)
    {
        this->espacio = espacio;
        this->name = nombre;
        this->siguiente = this->anterior = nullptr;
    }
};

class lista
{
public:
    nodo *raiz, *ultimo;
    int correlativo;
    lista()
    {
        this->raiz = this->ultimo = nullptr;
        this->correlativo = 1;
    }

    void add(string nombre)
    {
        nodo *nuevo = new nodo(correlativo, nombre);
        correlativo++;
        if (this->raiz == nullptr)
        {
            this->raiz = this->ultimo = nuevo;
            return;
        }
        else
        {
            this->ultimo->siguiente = nuevo;
            nuevo->anterior = this->ultimo;
            ultimo = nuevo;
            return;
        }
    }
};

class nodoL
{
public:
    string nombre;
    lista *lst;
    nodoL *siguiente, *anterior;

    nodoL(string nombre)
    {
        this->nombre = nombre;
        this->lst = new lista();
        this->siguiente = this->anterior = nullptr;
    }
};

class lista_listas
{
private:
    nodoL *raiz, *ultimo;

public:
    lista_listas()
    {
        this->raiz = this->ultimo = nullptr;
    }

    bool search(string name)
    {
        nodoL *aux = this->raiz;
        while (aux != nullptr)
        {
            if (aux->nombre.compare(name) == 0)
            {
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }

    void add(string categoria, string articulo)
    {
        if (this->raiz == nullptr)
        {
            this->raiz = this->ultimo = new nodoL(categoria);
            this->raiz->lst->add(articulo);
            return;
        }
        else
        {

            if (this->search(categoria) == false)
            {
                nodoL *nuevo = new nodoL(categoria);
                nuevo->lst->add(articulo);
                this->ultimo->siguiente = nuevo;
                nuevo->anterior = this->ultimo;
                this->ultimo = nuevo;
                return;
            }
            else
            {
                nodoL *temp = this->get(categoria);
                temp->lst->add(articulo);
                return;
            }
        }
    }

    nodoL *get(string name)
    {
        nodoL *aux = this->raiz;
        while (aux != nullptr)
        {
            if (aux->nombre.compare(name) == 0)
            {
                return aux;
            }
            aux = aux->siguiente;
        }
        return nullptr;
    }
    void graficar()
    {
        ofstream file;
        file.open("./lista_articulos.dot");
        file << "digraph{\n";
        nodoL *vertical = raiz;
        int contador = 0;
        while (vertical != nullptr)
        {
            file << "\"" << vertical->nombre.c_str() << "\"[shape=box,rankdir=UD, style =\"filled\"; label=\"" << vertical->nombre.c_str() << "\";pos=\"0,-" << to_string(contador) << "!\""
                 << "]\n";
            nodo *horizontal = vertical->lst->raiz;
            int contador2 = 0;
            while (horizontal != nullptr)
            {
                file << "\"" << horizontal->name.c_str() << "\"[shape=box,rankdir=LR ,style =\"filled\"; label=\"" << horizontal->name.c_str() << "\";pos=\"" << to_string(contador2) << ",-" << to_string(contador) << "!\""
                     << "]\n";
                contador2++;
                horizontal = horizontal->siguiente;
            }
            contador++;
            vertical = vertical->siguiente;
        }

        vertical = raiz;
        while (vertical != nullptr)
        {
            if (vertical == raiz)
            {
                file << "\"" << vertical->nombre.c_str() << "\"";
            }
            else
            {
                file << "->\"" << vertical->nombre.c_str() << "\"";
            }
            vertical = vertical->siguiente;
        }
        file << "\n";
        vertical = raiz;
        while (vertical != nullptr)
        {
            nodo *horizontal = vertical->lst->raiz;
            if (horizontal != nullptr)
            {
                file << "\"" << vertical->nombre.c_str() << "\"->\"" << horizontal->name.c_str() << "\"\n";
                while (horizontal != nullptr)
                {
                    if (horizontal == vertical->lst->raiz)
                    {
                        file << "\"" << horizontal->name.c_str() << "\"";
                    }
                    else
                    {
                        file << "->\"" << horizontal->name.c_str() << "\"";
                    }
                    horizontal = horizontal->siguiente;
                }
            }
            file << "\n";
            vertical = vertical->siguiente;
        }

        nodoL *aux = this->raiz;
        string texts = "";
        while (aux != nullptr)
        {
            texts += string("\"") + aux->nombre.c_str() + string("\";");

            aux = aux->siguiente;
        }
        file << "{rank = same;" << texts.c_str() << "}";

        file << "\n}\n";
        file.close();
        system("dot -Tpng ./lista_articulos.dot -o ./lista_articulos.png");
    }
};

// Circular doble
class Node
{
public:
    string nick;
    string password;
    float monedas;
    string edad;

    Node *next;
    Node *prev;
    Node(string nick, string password, float monedas, string edad)
    {
        this->nick = nick;
        this->password = password;
        this->monedas = monedas;
        this->edad = edad;

        this->next = null;
        this->prev = null;
    }
};

class LinkedList
{
private:
    Node *first;
    Node *last;
    int size;

public:
    LinkedList()
    {
        this->first = null;
        this->last = null;
        size = 0;
    }
    int getSize()
    {
        return size;
    }

    void append(string nick, string password, string monedas, string edad)
    {

        float temp = ::atof(monedas.c_str());
        Node *node = new Node(nick, password, temp, edad);

        if (this->first == null)
        {
            this->first = node;
            this->first->next = node;
            this->first->prev = node;
            this->last = node;
        }
        else
        {
            this->last->next = node;
            node->next = this->first;
            node->prev = this->last;
            this->last = node;
            this->first->prev = this->last;
        }
        size++;
    }
    void display()
    {
        cout << "Hola desde aquiiiii" << endl;
        Node *aux;
        aux = this->first;

        while (aux != null)
        {
            cout << aux->nick << endl;
            cout << aux->monedas << endl;
            aux = aux->next;
            if (aux == this->first)
            {
                break;
                /* code */
            }

            /* code */
        }
    }

    void usersDot()
    {
        Node *temp = this->first;
        int contador1 = 0;

        string codigoDot = "digraph G{\n";
        codigoDot += "label=\"Clientes\"\n";
        codigoDot += "node [shape=box]\n";
        codigoDot += "nodesep=1;\n";
        codigoDot += "node [fillcolor =\"#EEEEEEE\"]\n";
        codigoDot += "node [color = \"#4EA06D\"]\n";
        codigoDot += "edge [color = \"#00FF00\"];\n";

        while (temp != null)
        {

            codigoDot += string(temp->nick) + string("_nodo_") + string(to_string(contador1)) + string(" [label=\"") + string(temp->nick) + string("\n ") + string(temp->password) + string("\n ") + string(to_string(temp->monedas)) + string("\n ") + string(temp->edad) + string("\"]\n");

            contador1 = contador1 + 1;
            temp = temp->next;
            if (temp == this->first)
            {
                break;
            }
        }

        contador1 = 0;
        int contador2 = contador1 + 1;
        temp = this->first;
        while (temp != null)
        {
            if (temp->next != null)
            {

                codigoDot += string(temp->nick) + string("_nodo_") + string(to_string(contador1)) + string("->") + string(temp->next->nick) + string("_nodo_") + string(to_string(contador2)) + string("\n ");

                contador1 = contador1 + 1;
                contador2 = contador2 + 1;
                temp = temp->next;
                if (temp == this->last)
                {
                    break;
                }
            }
        }

        int contadorUltimo = contador1;
        contador2 = contador1 - 1;
        temp = this->last;
        while (temp != null)
        {
            if (temp->prev != null)
            {

                codigoDot += string(temp->nick) + string("_nodo_") + string(to_string(contador1)) + string("->") + string(temp->prev->nick) + string("_nodo_") + string(to_string(contador2)) + string("\n ");
                contador1 = contador1 - 1;
                contador2 = contador2 - 1;
                temp = temp->prev;
                if (temp == this->first)
                {
                    break;
                }
            }
        }

        temp = this->first;
        Node *temp2 = this->last;

        codigoDot += string(temp->nick) + string("_nodo_") + string("0") + string("->") + string(temp2->nick) + string("_nodo_") + string(to_string(contadorUltimo)) + string("\n ");

        codigoDot += string(temp2->nick) + string("_nodo_") + string(to_string(contadorUltimo)) + string("->") + string(temp->nick) + string("_nodo_") + string("0") + string("\n ");

        codigoDot += "rankdir=LR;\n}";

        cout << codigoDot;
    }
};

// objetos
LinkedList dcll;
lista_listas ldl;
Cola cola;

void loadFile()
{
    string pathFile;
    cout << "Escriba el nombre/ruta del archivo .json" << endl;
    cin >> pathFile;

    ifstream fJson(pathFile);
    stringstream buffer;
    buffer << fJson.rdbuf();
    auto json = nlohmann::json::parse(buffer.str());

    // cout << "\nUsers " << json["usuarios"] << "\n";

    for (auto usuario : json["usuarios"])
    {
        dcll.append(usuario["nick"], usuario["password"], usuario["monedas"], usuario["edad"]);
        // cout << usuario["nick"]<<", "<< usuario["password"]<<", "<<usuario["monedas"]<<", "<<usuario["edad"]<<endl;
    }

    for (auto articulo : json["articulos"])
    {
        ldl.add(articulo["categoria"], articulo["nombre"]);
        // cout << articulo["id"] << ", " << articulo["categoria"] << ", " << articulo["precio"] << ", " << articulo["nombre"] << articulo["src"] << endl;
    }

    //cargardatos a cola
    cola.enqueue(json["tutorial"]["ancho"], json["tutorial"]["alto"]);

    for (auto coordenadas : json["tutorial"]["movimientos"])
    {
        cola.enqueue(coordenadas["x"], coordenadas["y"]);
    }

    ldl.graficar();
    dcll.display();
    dcll.usersDot();
    cola.graficarCola();
}

int main(int argc, char const *argv[])
{
    // LinkedList list;
    // list.append("hector", "465465", 15, "21");
    // list.display();

    int option = 0;

    while (option != 5)
    {

        cout << "> ESCOJA UNA OPCION:" << endl;
        cout << "  [1] Carga masiva"
             << "\n  [2] Registrar usuario"
             << "\n  [3] Login"
             << "\n  [4] Reportes"
             << "\n  [5] Salir\n";
        cin >> option;
        switch (option)
        {
        case 1:
            loadFile();
            break;
        case 2:
            cout << "> Registrar" << endl;
            break;
        case 3:
            cout << "> Login" << endl;
            break;
        case 4:
            cout << "> Reportes" << endl;
            break;
        case 5:
            option = 5;
            break;
        default:
            cout << "La opcion ingresada no existe" << endl;
            break;
        }
    }

    system("PAUSE");
    return 0;
}