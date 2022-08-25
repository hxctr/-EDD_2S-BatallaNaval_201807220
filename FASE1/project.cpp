#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "tabulate.hpp"
#include "sha256.h"
using namespace std;
#define null 0
#include <cstdlib>
using namespace tabulate;

// cola
class NodoC
{
public:
    int x;
    int y;
    NodoC *sigC, *antC;

    NodoC(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->sigC = null;
        this->antC = null;
    }

    int getX()
    {
        return this->x;
    }

    int getY()
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

    void printcola()
    {
        NodoC *current = this->cabeza, *next = current->sigC;
        while (next != null)
        {
            current = next;
            next = current->sigC;
        }
        cout << "\tTablero:" << endl;
        cout << "\t\tAncho: ";
        cout << current->x;
        cout << "\n\t\tAlto: ";
        cout << current->y << endl;

        cout << "\tMovimientos:" << endl;
        if (this->cabeza == null)
        {
            cout << "Lista vacia";
        }
        NodoC *aux = this->cabeza;
        while (aux != null)
        {

            if (aux->sigC == null)
            {
                break;
            }
            else
            {
                cout << "(" + to_string(aux->x) + ", " + to_string(aux->y) + ")"
                     << "->";
            }

            aux = aux->sigC;
        }
    }

    void enqueue(int x, int y)
    {
        NodoC *newqueue = new NodoC(x, y);

        if (this->cabeza == null)
        {
            this->cabeza = newqueue;
        }
        else
        {
            newqueue->sigC = this->cabeza;
            this->cabeza = newqueue;
        }
    }

    void graficarCola()
    {
        NodoC *nuevo = this->cabeza;
        int cont = 0;
        string cadena = "";

        cadena += "digraph G { \n";
        cadena += "rankdir=LR\n";

        while (nuevo != null)
        {

            cadena += string("Node") + string(to_string(cont)) + string("[label=\"") + string(to_string(nuevo->getX())) + string("\n") + string(to_string(nuevo->getY())) + string("\" shape=box];\n");
            if (nuevo != this->cabeza)
            {
                cadena += string("Node") + string(to_string(cont - 1)) + string(" -> ") + string("Node") + string(to_string(cont)) + string(";\n");
            }
            nuevo = nuevo->sigC;
            cont += 1;
        }

        cadena += "}";
        // cout << cadena;
        ofstream colaDot;
        colaDot.open("./cola.dot");
        colaDot << cadena;
        colaDot.close();
        system("dot.exe -Tpng ./cola.dot -o ./cola.png");

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
    int id, precio;
    string categoria;
    nodo *siguiente, *anterior;

    nodo(int espacio, int id, string categoria, string nombre, int precio)
    {
        this->espacio = espacio;
        this->name = nombre;
        this->id = id;
        this->precio = precio;
        this->categoria = categoria;
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

    int buscarItem(int id)
    {
        nodo *tmp = this->raiz;
        while (tmp != nullptr)
        {
            if (tmp->id == id)
            {
                return tmp->precio;
            }
            tmp = tmp->siguiente;
        }
        return 0;
    }

    void add(int id, string categoria_, string nombre, int precio)
    {
        nodo *nuevo = new nodo(correlativo, id, categoria_, nombre, precio);
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

    void print()
    {
        Table articulos;
        articulos.add_row({"Id", "nombre", "categoria", "precio"});

        nodo *aux = this->raiz;
        while (aux != nullptr)
        {
            articulos.add_row({to_string(aux->id), aux->name, aux->categoria, to_string(aux->precio)});
            // printf("Id : %d, Articulo: %s\n", aux->id, aux->name.c_str());
            aux = aux->siguiente;
        }

        articulos.column(0).format().font_align(FontAlign::center);
        articulos.column(1).format().font_align(FontAlign::center);
        articulos.column(2).format().font_align(FontAlign::center);
        articulos.column(3).format().font_align(FontAlign::center);

        // for (size_t i = 0; i < 4; ++i)
        // {
        //     articulos[0][i].format().font_color(Color::cyan).font_align(FontAlign::center).font_style({FontStyle::bold});
        // }
        cout << "Tienda" << endl;
        cout << articulos;
    }
};

//--
class ItemNode
{
public:
    string nombre;
    int id, precio;
    string categoria;
    ItemNode *next;
    ItemNode(int id, string categoria, string nombre, int precio)
    {
        this->id = id;
        this->categoria = categoria;
        this->nombre = nombre;
        this->precio = precio;
        this->next = null;
    }
};

class Items
{
private:
    ItemNode *head;
    ItemNode *tail;
    int size;

public:
    Items()
    {
        this->head = null;
        this->tail = null;
    }

    void bubblesort()
    {
        if (this->head != null)
        {
            ItemNode *curr = null, *new_head = null, *move_head = null, *prev = null;

            while (this->head != null)
            {
                prev = null;
                curr = this->head;
                move_head = this->head;
                while (curr != null)
                {
                    if (curr->next != null && curr->next->precio < move_head->precio)
                    {
                        move_head = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_head == this->head)
                {
                    this->head = this->head->next;
                }
                if (prev != null)
                {
                    prev->next = move_head->next;
                }
                move_head->next = new_head;
                new_head = move_head;
            }
            this->head = new_head;
        }
        else
        {
            cout << "empty list";
        }
    }

    void bubblesortUp()
    {
        if (this->head != null)
        {
            ItemNode *curr = null, *new_head = null, *move_head = null, *prev = null;

            while (this->head != null)
            {
                prev = null;
                curr = this->head;
                move_head = this->head;
                while (curr != null)
                {
                    if (curr->next != null && curr->next->precio > move_head->precio)
                    {
                        move_head = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_head == this->head)
                {
                    this->head = this->head->next;
                }
                if (prev != null)
                {
                    prev->next = move_head->next;
                }
                move_head->next = new_head;
                new_head = move_head;
            }
            this->head = new_head;
        }
        else
        {
            cout << "empty list";
        }
    }

    void insert(int id, string categoria, string nombre, int precio)
    {
        ItemNode *nodenew = new ItemNode(id, categoria, nombre, precio);
        nodenew->next = null;
        if (this->head == null)
        {
            this->head = nodenew;
        }
        else
        {
            ItemNode *auxi = this->head;
            while (auxi->next != null)
            {
                auxi = auxi->next;
            }
            auxi->next = nodenew;
        }
    }

    void print()
    {

        Table artis;
        artis.add_row({"Id", "Nombre", "Categoria", "Precio"});
        if (this->head == null)
        {
            cout << "Lista vacia";
        }

        ItemNode *auxi = this->head;

        while (auxi != null)
        {
            artis.add_row({to_string(auxi->id), auxi->nombre, auxi->categoria, to_string(auxi->precio)});
            // cout << auxi->id << ", " << auxi->nombre << ", " << auxi->categoria << ", " << auxi->precio << endl;
            auxi = auxi->next;
        }
        cout << artis;
    }
};
//--
//**
class Unode
{
public:
    string nick;
    string password;
    int monedas;
    int edad;

    Unode *next;
    Unode(string nick, string password, int monedas, int edad)
    {
         this->nick = nick;
        this->password = password;
        this->monedas = monedas;
        this->edad = edad;
        this->next = null;
    }
};

class Ulist
{
private:
    Unode *head;
    Unode *tail;
    int size;

public:
    Ulist()
    {
        this->head = null;
        this->tail = null;
    }

    void bubblesort()
    {
        if (this->head != null)
        {
            Unode *curr = null, *new_head = null, *move_head = null, *prev = null;

            while (this->head != null)
            {
                prev = null;
                curr = this->head;
                move_head = this->head;
                while (curr != null)
                {
                    if (curr->next != null && curr->next->edad < move_head->edad)
                    {
                        move_head = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_head == this->head)
                {
                    this->head = this->head->next;
                }
                if (prev != null)
                {
                    prev->next = move_head->next;
                }
                move_head->next = new_head;
                new_head = move_head;
            }
            this->head = new_head;
        }
        else
        {
            cout << "empty list";
        }
    }

    void bubblesortUp()
    {
        if (this->head != null)
        {
            Unode *curr = null, *new_head = null, *move_head = null, *prev = null;

            while (this->head != null)
            {
                prev = null;
                curr = this->head;
                move_head = this->head;
                while (curr != null)
                {
                    if (curr->next != null && curr->next->edad > move_head->edad)
                    {
                        move_head = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_head == this->head)
                {
                    this->head = this->head->next;
                }
                if (prev != null)
                {
                    prev->next = move_head->next;
                }
                move_head->next = new_head;
                new_head = move_head;
            }
            this->head = new_head;
        }
        else
        {
            cout << "empty list";
        }
    }

    void insert(string nick, string password, int monedas, int edad)
    {
        Unode *nodenew = new Unode(nick, password, monedas, edad);
        nodenew->next = null;
        if (this->head == null)
        {
            this->head = nodenew;
        }
        else
        {
            Unode *auxi = this->head;
            while (auxi->next != null)
            {
                auxi = auxi->next;
            }
            auxi->next = nodenew;
        }
    }

    void print()
    {

        Table artis;
        artis.add_row({"Nick", "Contrasenia", "Monedas", "Edad"});
        if (this->head == null)
        {
            cout << "Lista vacia";
        }

        Unode *auxi = this->head;

        while (auxi != null)
        {
            artis.add_row({auxi->nick, SHA256::cifrar(auxi->password), to_string(auxi->monedas), to_string(auxi->edad)});
            // cout << auxi->id << ", " << auxi->nombre << ", " << auxi->categoria << ", " << auxi->precio << endl;
            auxi = auxi->next;
        }
        cout << artis;
    }
};
//**
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

    void add(string categoria, int id, string categoria_, string articulo, int precio)
    {
        if (this->raiz == nullptr)
        {
            this->raiz = this->ultimo = new nodoL(categoria);
            this->raiz->lst->add(id, categoria, articulo, precio);
            return;
        }
        else
        {

            if (this->search(categoria) == false)
            {
                nodoL *nuevo = new nodoL(categoria);
                nuevo->lst->add(id, categoria, articulo, precio);
                this->ultimo->siguiente = nuevo;
                nuevo->anterior = this->ultimo;
                this->ultimo = nuevo;
                return;
            }
            else
            {
                nodoL *temp = this->get(categoria);
                temp->lst->add(id, categoria, articulo, precio);
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
        system("dot.exe -Tpng ./lista_articulos.dot -o ./lista_articulos.png");
    }

    void print()
    {
        nodoL *aux = this->raiz;
        // while (aux != nullptr)
        // {
        //     aux->lst->print();
        //     aux = aux->siguiente;
        // }
        aux->lst->print();
    }
};

// Circular doble
class Node
{
public:
    string nick;
    string password;
    int monedas;
    int edad;

    Node *next;
    Node *prev;
    Node(string nick, string password, int monedas, int edad)
    {
        this->nick = nick;
        this->password = password;
        this->monedas = monedas;
        this->edad = edad;

        this->next = null;
        this->prev = null;
    }

    void setNick(string nick)
    {
        // cout << "si cambio el nick";
        this->nick = nick;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    void setEdad(int edad)
    {
        this->edad = edad;
    }

    void setMonedas(int monedas)
    {
        this->monedas = this->monedas - monedas;
        cout << endl
             << "Tokens actuales: " << to_string(this->monedas);
    }

    void setMonedasForMove(int monedas)
    {
        this->monedas = this->monedas + monedas;
        cout << endl
             << "Tokens actuales: " << to_string(this->monedas);
    }

    int getMonedas()
    {
        return this->monedas;
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

    // void removeAccount(const string& nick)
    // {

    //     Node *start = this->first;

    //     while ((start != nullptr) && (start->nick != nick))
    //     {
    //         start = start->next;
    //     }

    //     if (start == nullptr)
    //     {
    //         return;
    //     }

    //     Node *prev = start->prev;
    //     Node *next = start->next;

    //     if (prev != nullptr)
    //     {
    //         prev->next = next;
    //     }
    //     else
    //     {
    //         first = next;
    //     }

    //     if (next != nullptr)
    //     {
    //         next->prev = prev;
    //     }
    //     else
    //     {
    //         last = prev;
    //     }
    //     delete start;
    // }

    void bubblesort()
    {
        if (this->first != null)
        {
            Node *curr = null, *new_head = null, *move_head = null, *prev = null;

            while (this->first != null)
            {
                prev = null;
                curr = this->first;
                move_head = this->first;
                while (curr != null)
                {
                    if (curr->next != null && curr->next->edad < move_head->edad)
                    {
                        move_head = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_head == this->first)
                {
                    this->first = this->first->next;
                }
                if (prev != null)
                {
                    prev->next = move_head->next;
                }
                move_head->next = new_head;
                new_head = move_head;
            }
            this->first = new_head;
        }
        else
        {
            cout << "lista vacia";
        }
    }

    void removerCuenta(string nick_)
    {
        Node *aux = this->first;

        do
        {

            if (aux->nick == nick_)
            {
                if (this->first == this->last)
                {
                    this->first = null;
                    this->last = null;
                }
                else
                {
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;

                    aux->next = null;
                    aux->prev = null;

                    delete aux;
                    break;
                }
            }
            else
            {
                aux = aux->next;
            }

        } while (aux != this->first);
    }

    void sorte()
    {
        Node *t, *s;
        int v, i;
        if (this->first == this->last && this->first == null)
        {
            cout << "The List is empty" << endl;
            return;
        }
        s = this->first;
        for (i = 0; i < this->size; i++)
        {
            t = s->next;
            while (t != this->first)
            {
                if (s->edad > t->edad)
                {
                    v = s->edad;
                    s->edad = t->edad;
                    t->edad = v;
                }
                t = t->next;
            }
            s = s->next;
        }
    }

    int printMonedas(string nick)
    {
        bool found = false;
        Node *current;
        current = this->first;

        if (current == null)
        {
            return 0;
        }
        else
        {
            do
            {
                if (current->nick == nick)
                {
                    found = current->monedas;
                }
                else
                {
                    current = current->next;
                }

            } while (!found && current != this->first);
            return found;
        }
    }

    bool setNewTokens(string nick, int monedas)
    {
        bool found = false;
        Node *current;
        current = this->first;

        if (current == null)
        {
            return false;
        }
        else
        {
            do
            {
                if (current->nick == nick)
                {
                    // cout << "si cambio monedas";
                    current->setMonedas(monedas);
                    found = true;
                }
                else
                {
                    current = current->next;
                    // cout << "no encuentra nada";
                }

            } while (!found && current != this->first);
            return found;
        }
    }

    bool setNewTokensForMove(string nick, int monedas)
    {
        bool found = false;
        Node *current;
        current = this->first;

        if (current == null)
        {
            return false;
        }
        else
        {
            do
            {
                if (current->nick == nick)
                {
                    cout << endl
                         << "Se ha agregado +1 token para el usuario " + nick;
                    current->setMonedasForMove(monedas);
                    found = true;
                }
                else
                {
                    current = current->next;
                }

            } while (!found && current != this->first);
            return found;
        }
    }

    bool setNewData(string nick2, string nick_, string password_, int edad_)
    {
        bool found = false;
        Node *current;
        current = this->first;

        if (current == null)
        {
            return false;
        }
        else
        {
            do
            {
                if (current->nick == nick2)
                {
                    // cout << "si passa aqui";
                    current->setNick(nick_);
                    current->setEdad(edad_);
                    current->setPassword(password_);
                    found = true;
                }
                else
                {
                    current = current->next;
                }

            } while (!found && current != this->first);
            return found;
        }

        // bool found = false;
        // Node *current;
        // current = this->first;

        // if (current == null)
        // {
        //     cout<<"lista vacia";
        // }
        // else
        // {
        //     do
        //     {
        //         if (current->nick == nick_)
        //         {
        //             cout<<"si passa aqui";
        //             current->setNick(nick_);
        //             current->setEdad(edad_);
        //             current->setPassword(password_);
        //             found = true;
        //         }
        //         else
        //         {
        //             current = current->next;
        //             cout<<"no lo encuentra";
        //         }

        //     } while (!found && current != this->first);

        // }
    }

    // bool searchUser(string nick_, string password_)
    // {
    //     Node *tmpCL = this->first;

    //     while (tmpCL)
    //     {
    //         if ((tmpCL->nick == nick_) && (tmpCL->password == password_))
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //         tmpCL = tmpCL->next;
    //     }

    //     return 0;
    // }

    bool searchUser(string nick_, string password_)
    {
        bool found = false;
        Node *current;
        current = this->first;

        if (current == null)
        {
            return false;
        }
        else
        {
            do
            {
                if (current->nick == nick_ && current->password == password_)
                {
                    found = true;
                }
                else
                {
                    current = current->next;
                }

            } while (!found && current != this->first);
            return found;
        }
    }

    void append(string nick, string password, int monedas, int edad)
    {

        Node *node = new Node(nick, password, monedas, edad);

        if (this->last == null)
        {
            this->first = node;
            this->last = node;
            this->first->next = this->last;
            this->last->prev = this->first;
        }
        else
        {
            this->last->next = node;
            node->prev = this->last;
            node->next = this->first;
            this->last = node;
            this->first->prev = this->last;
        }
        size++;
    }

    void display()
    {

        Node *aux;
        aux = this->first;

        SHA256 sha256;

        Table usuarios;

        usuarios.add_row({"Usuario", "Contrasenia", "Monedas", "Edad"});
        while (aux != null)
        {
            // cout<<aux->nick<<", "<<aux->password<<", "<<aux->monedas<<", "<<aux->edad<<endl;
            usuarios.add_row({aux->nick, SHA256::cifrar(aux->password), to_string(aux->monedas), to_string(aux->edad)});

            aux = aux->next;
            if (aux == this->first)
            {
                break;
                /* code */
            }

            /* code */
        }
        cout << usuarios;
    }

    void usersDot()
    {
        Node *temp = this->first;
        int contador1 = 0;

        string codigoDot = "digraph G{\n";
        codigoDot += "label=\"Usuarios\"\n";
        codigoDot += "node [shape=box]\n";
        codigoDot += "nodesep=1;\n";
        codigoDot += "node [fillcolor =\"#EEEEEEE\"]\n";


        while (temp != null)
        {

            codigoDot += string(temp->nick) + string("_nodo_") + string(to_string(contador1)) + string(" [label=\"") + string(temp->nick) + string("\n ") + string(temp->password) + string("\n ") + string(to_string(temp->monedas)) + string("\n ") + string(to_string(temp->edad)) + string("\"]\n");

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

        // cout << codigoDot;

        ofstream usuarios;
        usuarios.open("./lista_usuarios.dot");
        usuarios << codigoDot;
        usuarios.close();
        system("dot.exe -Tpng ./lista_usuarios.dot -o ./lista_usuarios.png");
    }
};

// lista de pilas
class NodoPila
{
public:
    int indice;
    string name;
    NodoPila *siguiente, *anterior;
    NodoPila(int indice, string nombre)
    {
        this->indice = indice;
        this->name = nombre;
        this->siguiente = this->anterior = nullptr;
    }
};

class Pila
{
public:
    NodoPila *raiz, *ultimo;
    int correlativo;

    Pila()
    {
        this->raiz = this->ultimo = nullptr;
        this->correlativo = 1;
    }

    void add(string nombre)
    {
        NodoPila *nuevo = new NodoPila(correlativo, nombre);
        correlativo++;

        if (this->raiz == null)
        {
            this->raiz = nuevo;
        }
        else
        {
            nuevo->siguiente = this->raiz;
            this->raiz = nuevo;
        }
    }
};

class NodoLista
{
public:
    string nombre;
    Pila *stack;
    NodoLista *siguiente, *anterior;

    NodoLista(string nombre)
    {
        this->nombre = nombre;
        this->stack = new Pila();
        this->siguiente = this->anterior = nullptr;
    }
};

class ListaDePilas
{
private:
    NodoLista *raiz, *ultimo;

public:
    ListaDePilas()
    {
        this->raiz = this->ultimo = nullptr;
    }

    bool search(string name)
    {
        NodoLista *aux = this->raiz;
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

    void add(string hed, string stack)
    {
        if (this->raiz == nullptr)
        {
            this->raiz = this->ultimo = new NodoLista(hed);
            this->raiz->stack->add(stack);
            return;
        }
        else
        {
            if (this->search(hed) == false)
            {
                NodoLista *nuevo = new NodoLista(hed);
                nuevo->stack->add(stack);
                this->ultimo->siguiente = nuevo;
                nuevo->anterior = this->ultimo;
                this->ultimo = nuevo;
                return;
            }
            else
            {
                NodoLista *temp = this->get(hed);
                temp->stack->add(stack);
                return;
            }
        }
    }

    NodoLista *get(string name)
    {
        NodoLista *aux = this->raiz;
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
        file.open("./lista_pilas.dot");
        file << "digraph{\n";
        NodoLista *vertical = raiz;
        int contador = 0;
        while (vertical != nullptr)
        {
            file << "\"" << vertical->nombre.c_str() << "\"[shape=box,rankdir=UD, style =\"filled\"; label=\"" << vertical->nombre.c_str() << "\";pos=\"0,-" << to_string(contador) << "!\""
                 << "]\n";
            NodoPila *horizontal = vertical->stack->raiz;
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
            NodoPila *horizontal = vertical->stack->raiz;
            if (horizontal != nullptr)
            {
                file << "\"" << vertical->nombre.c_str() << "\"->\"" << horizontal->name.c_str() << "\"\n";
                while (horizontal != nullptr)
                {
                    if (horizontal == vertical->stack->raiz)
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

        NodoLista *aux = this->raiz;
        string texts = "";
        while (aux != nullptr)
        {
            texts += string("\"") + aux->nombre.c_str() + string("\";");

            aux = aux->siguiente;
        }
        file << "{rank = same;" << texts.c_str() << "}";

        file << "\n}\n";
        file.close();
        system("dot.exe -Tpng ./lista_pilas.dot -o ./lista_pilas.png");
    }
};
// fin lista de pilas

// objetos
LinkedList dcll;
lista_listas ldl;
Cola cola;
lista ld;
Items it;
ListaDePilas ldp;
Ulist lo;

void signUpUser()
{
    string nick;
    string password;
    int monedas;
    int edad;

    cout << "Ingrese su nick: ";
    cin >> nick;
    cout << endl
         << "Digite su contraseña: ";
    cin >> password;
    cout << endl
         << "Ingrese la cantidad de monedas: ";
    cin >> monedas;
    cout << endl
         << "Ingrese su edad: ";
    cin >> edad;
    dcll.append(nick, password, monedas, edad);
}

// void editInfo(string nick, string nick_, string password_, string edad_)
// {
//     dcll.setNewData(nick, nick_, password_, edad_);
// }

void buyItem(string nick)
{

    ld.print();

    int id = 0;
    string yesNo;

    cout << endl
         << "Ingrese el Id del item a comprar: ";
    cin >> id;

    int ret = ld.buscarItem(id);

    if (ret != 0)
    {
        // cout << "si existe dicho item";
        cout << ret;
        dcll.setNewTokens(nick, ret);
    }
    else
    {
        // cout << "No se encontro";
    }

    // cout<<"Digite "

    // bool response = dcll.searchUser(nick, password);
}

int contador = 0;

void agregarMovimientos(string nick)
{
    string salir = "";

    string nombre = " ";
    cout << endl
         << "Ingrese el nombre de la pila" << endl;
    cin >> nombre;

    string coordenadas;
    while (salir != "stop")
    {

        if (coordenadas != "stop")
        {
            cout << "Ingrese las coordenadas de movimientos separadas por coma y sin espacios:                                           Digite \"stop\" para parar" << endl;
            cin >> coordenadas;
            if (coordenadas == "stop")
            {
                break;
            }
            else
            {
                contador++;
                ldp.add(nombre, to_string(contador) + ".- " + coordenadas);
            }
        }
        else
        {
            salir = "stop";
        }
    }

    dcll.setNewTokensForMove(nick, 1);
}

void signIn()
{

    string nick = "", nick_ = "";
    string password = "", password_ = "";
    int edad_;
    string yesNo;

    cout << "Ingrese su nick: ";
    cin >> nick;
    cout << "Ingrese su contraseña: ";
    cin >> password;

    bool response = dcll.searchUser(nick, password);

    if (response)
    {
        string option = " ";
        char res;
        int tokens = dcll.printMonedas(nick);

        while (option != "f")
        {

            cout << endl
                 << "> SESION INICIADA COMO " + string(nick) << endl;
            cout << "  [a] Editar informacion"
                 << "\n  [b] Eliminar cuenta"
                 << "\n  [c] Ver el tutorial"
                 << "\n  [d] Ver articulos de la tienda"
                 << "\n  [e] Realizar movimientos"
                 << "\n  [f] Salir al menu principal\n";
            cin >> res;

            switch (res)
            {
            case 'a':
                cout << "Ingrese su nick: ";
                cin >> nick_;
                cout << "Digite su contraseña: ";
                cin >> password_;
                cout << "Ingrese su edad: ";
                cin >> edad_;
                dcll.setNewData(nick, nick_, password_, edad_);
                cout << "*DATOS CAMBIADOS CORRECTAMENTE*\n*VUELVA A INICIAR SESION*";
                option = "f";
                break;
            case 'b':

                // dcll.removeAccount(nick);
                dcll.removerCuenta(nick);
                cout << "*CUENTA ELIMINADA CORRECTAMENTE*\n*VUELVA A INICIAR SESION*";
                option = "f";

                break;
            case 'c':
                cout << "Tutorial" << endl;
                cola.printcola();

                break;
            case 'd':
                // cout << "Tokens: " + to_string(tokens) << endl;
                buyItem(nick);
                // ld.print();
                break;
            case 'e':
                cout << "Realizar movimientos" << endl;
                agregarMovimientos(nick);
                break;
            case 'f':
                option = "f";
                break;
            default:
                cout << "La opcion ingresada no existe" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Credenciales incorrectas";
    }
}

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
        lo.insert(usuario["nick"], usuario["password"], usuario["monedas"], usuario["edad"]);
        // cout << usuario["nick"]<<", "<< usuario["password"]<<", "<<usuario["monedas"]<<", "<<usuario["edad"]<<endl;
    }

    for (auto articulo : json["articulos"])
    {
        ldl.add(articulo["categoria"], articulo["id"], articulo["categoria"], articulo["nombre"], articulo["precio"]);
        // cout << articulo["id"] << ", " << articulo["categoria"] << ", " << articulo["precio"] << ", " << articulo["nombre"] << articulo["src"] << endl;
        ld.add(articulo["id"], articulo["categoria"], articulo["nombre"], articulo["precio"]);
        it.insert(articulo["id"], articulo["categoria"], articulo["nombre"], articulo["precio"]);
    }

    // cargardatos a cola
    cola.enqueue(json["tutorial"]["ancho"], json["tutorial"]["alto"]);

    for (auto coordenadas : json["tutorial"]["movimientos"])
    {
        cola.enqueue(coordenadas["x"], coordenadas["y"]);
    }
}

int main(int argc, char const *argv[])
{
    // LinkedList list;
    // list.append("hector", "465465", 15, "21");
    // list.display();

    int option = 0;

    while (option != 5)
    {

        cout << endl
             << "> ESCOJA UNA OPCION:" << endl;
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
            signUpUser();
            break;
        case 3:
            cout << "> Login" << endl;
            signIn();
            break;
        case 4:
            cout << "> Reportes" << endl;

            ldl.graficar(); // dot lista de listas
            dcll.usersDot();     // dot usuarios
            cola.graficarCola(); // dot cola
            ldp.graficar();      // dot lista de pilas
            cout <<endl<< "*Listado de usuarios ordenados descendente por edad*" << endl;
            lo.bubblesort();
            lo.print();
            cout <<endl<< "*Listado de usuarios ordenados ascendente por edad*" << endl;
            lo.bubblesortUp();
            lo.print();
            cout << endl
                 << "*Listado de articulos ordenados por precio descendente*" << endl;
            it.bubblesort();
            it.print();
            cout << endl
                 << "*Listado de articulos ordenados por precio descendente*" << endl;
            it.bubblesortUp();
            it.print();
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