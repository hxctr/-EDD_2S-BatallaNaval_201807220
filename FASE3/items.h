#include <iostream>
#include <string>
#define NOT_FOUND -1
#include <vector>
using namespace std;

class NodoArticulo
{
public:
    string nombre;
    int id, precio;
    string categoria;
    string src_img;
    NodoArticulo *next;
    NodoArticulo(int id, string categoria, string nombre, int precio, string src_img)
    {
        this->id = id;
        this->categoria = categoria;
        this->nombre = nombre;
        this->precio = precio;
        this->src_img = src_img;
        this->next = nullptr;
    }
};

class ListaArticulos
{
private:
    NodoArticulo *head;
    NodoArticulo *tail;
    int size;

public:
    ListaArticulos()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert(int id, string categoria, string nombre, int precio, string src_img)
    {
        NodoArticulo *nodenew = new NodoArticulo(id, categoria, nombre, precio, src_img);
        nodenew->next = nullptr;
        if (this->head == nullptr)
        {
            this->head = nodenew;
        }
        else
        {
            NodoArticulo *auxi = this->head;
            while (auxi->next != nullptr)
            {
                auxi = auxi->next;
            }
            auxi->next = nodenew;
        }
    }

    string returnNameById(int id){
        NodoArticulo *auxi = this->head;
        while (auxi != nullptr)
        {
            if (auxi->id == id)
            {
                return auxi->nombre;
            }
            auxi = auxi->next;
        }
        return "NOT_FOUND";
    }

    int returnPriceById(int id){
        NodoArticulo *auxi = this->head;
        while (auxi != nullptr)
        {
            if (auxi->id == id)
            {
                return auxi->precio;
            }
            auxi = auxi->next;
        }
        return NOT_FOUND;
    }

    vector<int> sendIdsToPY(){
        NodoArticulo *temp = this->head;
        vector<int> idvec;

        while (temp != nullptr)
        {
            idvec.push_back(temp->id);
            temp = temp->next;
        }
        return idvec;
    }

    vector<string> sendCategoriaToPY(){
        NodoArticulo *temp = this->head;
        vector<string> categoriavec;

        while (temp != nullptr)
        {
            categoriavec.push_back(temp->categoria);
            temp = temp->next;
        }
        return categoriavec;
    }

    vector<int> sendPrecioToPY(){
        NodoArticulo *temp = this->head;
        vector<int> preciovec;

        while (temp != nullptr)
        {
            preciovec.push_back(temp->precio);
            temp = temp->next;
        }
        return preciovec;
    }

    vector<string> sendNombreToPY(){
        NodoArticulo *temp = this->head;
        vector<string> nombrevec;

        while (temp != nullptr)
        {
            nombrevec.push_back(temp->nombre);
            temp = temp->next;
        }
        return nombrevec;
    }

     vector<string> sendSRCToPY(){
        NodoArticulo *temp = this->head;
        vector<string> srcvec;

        while (temp != nullptr)
        {
            srcvec.push_back(temp->src_img);
            temp = temp->next;
        }
        return srcvec;
    }

    void _print()
    {

        if (this->head == nullptr)
        {
            cout << "Lista vacia";
        }

        NodoArticulo *auxi = this->head;

        while (auxi != nullptr)
        {

            cout << auxi->id << ", " << auxi->nombre << ", " << auxi->categoria << ", " << auxi->precio << endl;
            auxi = auxi->next;
        }
    }

    void deleteList(NodoArticulo *head)
    {
        NodoArticulo *prev = head;

        while (head)
        {
            this->head = head->next;
            delete (prev);
            prev = this->head;
        }
    }
};