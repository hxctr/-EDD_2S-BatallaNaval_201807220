#include <iostream>
#include <string>
#include <vector>
#include "sha256.h"
using namespace std;

class ItemNode
{
private:
public:
    int id;
    // string categoria;
    // int precio;
    // string nombre;
    // string src;
    ItemNode *next;

    ItemNode(int id
    // , string categoria, int precio, string nombre, string src)
    )
    {
        this->id = id;
        // this->categoria = categoria;
        // this->precio = precio;
        // this->nombre = nombre;
        // this->src = src;
        this->next = nullptr;
    }

    int getId()
    {
        return this->id;
    }

    // string getNombre()
    // {
    //     return this->nombre;
    // }

    // int getPrecio()
    // {
    //     return this->precio;
    // }
};

class ItemsList
{
private:
public:
    ItemNode *start;

    ItemsList()
    {
        this->start = nullptr;
    }

    void insertInfo(int id
    // , string categoria, int precio, string nombre, string src
    )
    {
        ItemNode *node = new ItemNode(id
        // , categoria, precio, nombre, src
        );
        if (this->start == nullptr)
        {
            this->start = node;
        }
        else
        {
            ItemNode *temp = this->start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void printlk()
    {
        ItemNode *temp = this->start;
        while (temp != nullptr)
        {
            // cout << to_string(temp->id) + ", " + temp->categoria + ", " + to_string(temp->precio) + ", " + temp->nombre + ", " + temp->src << endl;
            cout << temp->id<< endl;
            temp = temp->next;
        }
    }

    ItemNode *get_start() const
    {
        return start;
    }
};

class UsersNode
{
private:
public:
    int id;
    string nick;
    string password;
    int monedas;
    int edad;
    ItemsList linked_list;
    UsersNode *next;

    UsersNode(int id, string nick, string password, int monedas, int edad, ItemsList linked_list)
    {
        this->id = id;
        this->nick = nick;
        this->password = password;
        this->monedas = monedas;
        this->edad = edad;
        this->linked_list = linked_list;
        this->next = nullptr;
    }

    void setLinkedList(ItemsList newlist){
        this->linked_list = newlist;
    }

    void setId(int id){
        this->id = id;
    }

    void setNick(string nick){
        this->nick = nick;
    }

    void setPassword(string password){
        this->password = password;
    }

    void setMonedas(int monedas){
        this->monedas = monedas;
    }

    int getMonedas(){
        return this->monedas;
    }

    void setEdad(int edad){
        this->edad = edad;
    }


};

class UsersList
{
private:
public:
    UsersNode *start;
    UsersList()
    {
        this->start = nullptr;
    }

    void insert(int id, string nick, string password, int monedas, int edad, ItemsList linked_list)
    {
        UsersNode *node = new UsersNode(id, nick, password, monedas, edad, linked_list);
        if (this->start == nullptr)
        {
            this->start = node;
        }
        else
        {
            UsersNode *temp = this->start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void _print(){
        UsersNode *temp = this->start;
        while (temp != nullptr)
        {
            cout << "Nick: " + temp->nick + ", Id: " + to_string(temp->id) + "\n";
            temp = temp->next;
        }
        
    }

    void setNewLinkedList(string nick, ItemsList newlist){
        UsersNode *temp = this->start;
        while (temp != nullptr)
        {
            if (temp->nick == nick)
            {
                temp->setLinkedList(newlist);
            }
            temp = temp->next;
        }
        
    }

    vector<int> sendIdsToPY(){
        UsersNode *temp = this->start;
        vector<int> idvec;

        while (temp != nullptr)
        {
            idvec.push_back(temp->id);
            temp = temp->next;
        }
        return idvec;
    }

    vector<string> sendNicksToPY(){
        UsersNode *temp = this->start;
        vector<string> nickvec;

        while (temp != nullptr)
        {
            nickvec.push_back(temp->nick);
            temp = temp->next;
        }
        return nickvec;
    }

    vector<string> sendPasswordsToPY(){
        UsersNode *temp = this->start;
        vector<string> passvec;

        while (temp != nullptr)
        {
            passvec.push_back(SHA256::cifrar(temp->password));
            temp = temp->next;
        }
        return passvec;
    }

    vector<int> sendAgesToPY(){
        UsersNode *temp = this->start;
        vector<int> agevec;

        while (temp != nullptr)
        {
            agevec.push_back(temp->edad);
            temp = temp->next;
        }
        return agevec;
    }

    void bubblesortDown()
    {
        if (this->start != nullptr)
        {
            UsersNode *curr = nullptr, *new_start = nullptr, *move_start = nullptr, *prev = nullptr;

            while (this->start != nullptr)
            {
                prev = nullptr;
                curr = this->start;
                move_start = this->start;
                while (curr != nullptr)
                {
                    if (curr->next != nullptr && curr->next->edad < move_start->edad)
                    {
                        move_start = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_start == this->start)
                {
                    this->start = this->start->next;
                }
                if (prev != nullptr)
                {
                    prev->next = move_start->next;
                }
                move_start->next = new_start;
                new_start = move_start;
            }
            this->start = new_start;
        }
        else
        {
            cout << "empty list";
        }
    }

    void bubblesortUp()
    {
        if (this->start != nullptr)
        {
            UsersNode *curr = nullptr, *new_start = nullptr, *move_start = nullptr, *prev = nullptr;

            while (this->start != nullptr)
            {
                prev = nullptr;
                curr = this->start;
                move_start = this->start;
                while (curr != nullptr)
                {
                    if (curr->next != nullptr && curr->next->edad > move_start->edad)
                    {
                        move_start = curr->next;
                        prev = curr;
                    }
                    curr = curr->next;
                }
                if (move_start == this->start)
                {
                    this->start = this->start->next;
                }
                if (prev != nullptr)
                {
                    prev->next = move_start->next;
                }
                move_start->next = new_start;
                new_start = move_start;
            }
            this->start = new_start;
        }
        else
        {
            cout << "empty list";
        }
    }

    void getLk(int id)
    {
        UsersNode *temp = this->start;
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                cout << "Nick: " + temp->nick + ", Id: " + to_string(temp->id) + "\n";

                for (ItemNode *p = temp->linked_list.get_start(); p != nullptr; p = p->next)
                {
                    // cout << "- " << to_string(p->getId()) + ", " + p->getNombre() + ", " + to_string(p->getPrecio()) << endl;
                    cout << p->getId()<< endl;
                }
            }
            temp = temp->next;
        }
    }

    vector<int> getLkByName(string nick)
    {
        UsersNode *temp = this->start;
        vector<int> secondId;

        while (temp != nullptr)
        {
            if (temp->nick == nick)
            {
                for (ItemNode *p = temp->linked_list.get_start(); p != nullptr; p = p->next)
                {
                    secondId.push_back(p->getId());
                }
            }
            temp = temp->next;
        }
        return secondId;
    }

    int logUser(string nick, string password)
    {
        /*
        If this funcion returns a 1 it means it is admin user, so
        swap interface to admin, if it is 2, it mean it is in 
        user, so change GUI to user interface, else, if it is 0
        it means it didn´t find user, so then show a dialog message
        */
        UsersNode *tmp = this->start;

        if (nick == "ADMIN" && password == "123")
        {
            return 1;
        }
        else
        {
            while (tmp != nullptr)
            {
                if (tmp->nick == nick && tmp->password == password)
                {
                    return 2;
                }
                tmp = tmp->next;
            }
            
        }

        return 0;
    }

    bool setNewData(string nick_to_search, string nick, string password, int edad){//I can pull nick from the user text fiel in GUI
    //if return true, then it means data get changed, but if not, it will return false, it means data doesn´t change because user doesn´t exist
        UsersNode *temp = this->start;
        while (temp != nullptr)
        {
            if (temp->nick == nick_to_search)
            {
                temp->setNick(nick);
                temp->setPassword(password);
                temp->setEdad(edad);
                return true;

            }
            temp = temp->next;
        }
        return false;
    }

    void deleteUser(int id){
        UsersNode *temp = this->start;
        UsersNode* prev = nullptr;

        if (temp!=nullptr && temp->id == id)
        {
            this->start = temp->next;
            delete temp;
            return;
        }else
        {
            while (temp != nullptr && temp->id!= id)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr)
            {
                return;
            }
            prev->next = temp->next;
            delete temp;     
        } 
    }
};